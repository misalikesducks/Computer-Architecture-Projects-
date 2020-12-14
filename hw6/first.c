#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node{
    int valid; // valid bit 
    int tag; 
    int lastUsed; 

}node;


int main(int argc, char* argv[])
{

    double cache = atoi(argv[1]);
    double block = atoi(argv[4]); 
    FILE *file = fopen(argv[5], "r");
    if(ceil(log2(cache))!=floor(log2(cache)))
    {
        printf("error\n");
        return 0;
    }
    if(ceil(log2(block))!=floor(log2(block)))
    {
        printf("error\n");
        return 0;
    }
    if(argc != 6)
    {
        printf("error\n");
		return 0;
    }
    char associative[100] = {0};
    strcpy(associative, argv[2]);
    char replacement[100] ={0};
    strcpy(replacement, argv[3]);
    if(strcmp(replacement, "lru")!=0 && strcmp(replacement, "fifo")!=0)
    {
        printf("error\n");
        return 0;
    }

    int set; //set bits 
    int n = 0; 
    
    int cacheType; 
 
    //finding bits and stuff 
    if(strncmp(associative, "assoc:", 6) == 0)
    {
        if(associative[6] >= '0' && associative[6] <= '9')
        {
            n = atoi(strchr(associative, ':') + 1);
            set = (int)(log(cache/block/n)/log(2)+.5);
            cacheType = 0; 
        }
        else 
        {
            printf("error\n");
            return 0; 
        }
    }
    else if(strcmp(associative, "assoc") == 0)
    {
        n = cache/block; 
        set = 0; 
        cacheType = 1; 
        
    }
    else if(strcmp(associative, "direct") == 0)
    {
        n = 1; 
        set = (int)(log(cache/block)/log(2)+.5);
        cacheType = 0; 
    }
    else
    {
        printf("error\n");
        return 0;
    }
    
    if(ceil(log2(n))!=floor(log2(n)))
    {
        printf("error\n");
        return 0;
    }
    
    int total = 0; 
    
    for(int i = 0; i < set; i++)
    {
        total += pow(2, i); 
    }

    int blockOff = (int) (log(block)/log(2) + .5); 
    //int tagBits = (48 - set - blockOff); 
  //  printf("%d\t%d\t%d",set,tagBits,blockOff);
    
    //declare array 
    node** array;   
    if(cacheType == 1)
    {
        array = malloc(sizeof(node*)); 
        array[0] = malloc(sizeof(node) * n);
        for(int i = 0; i < n; i++)
        {
            array[0][i].valid = 0; 
            array[0][i].tag = 0; 
            array[0][i].lastUsed = 0; 
        }
    }
    else
    {
        array = malloc(sizeof(node*) * (total + 1));
        for(int i = 0; i < total + 1; i++)
        {
            array[i] = malloc(sizeof(node) * n);
            for(int j = 0; j < n; j++)
            {
                array[i][j].valid = 0; 
                array[i][j].tag = 0; 
                array[i][j].lastUsed = 0; 
            }
        }
    }


    //read in file 
    char numbers[50] = {0};
    char type; 
    int address, tag; 
    int setIndex; 

    int hit = 0, miss = 0, read = 0, write = 0; 
    
    if(!file)
    {
        printf("error\n");
		return 0;  
    }
    while(fscanf(file,"%s %c %x", &numbers[0],&type,&address) != EOF)
    {
        if(numbers[0] == '#')
        {
            break; 
        } 

        tag = address >> (set + blockOff);
        setIndex = ((address >> blockOff) & total);  // set index 
        int lru = 0; 
        if(strcmp(replacement, "lru") == 0)
        {
            lru = 1; 
        }

        int hitted = 0; 
        int coldHit = 0; 
        int max = 0; 

        for(int i = 0; i < n; i++)
        {
            if(array[setIndex][i].valid == 1 && array[setIndex][i].tag == tag)
            {
                hit++; 
                hitted = 1; 
                if(lru == 1)
                {
                    //lru 
                    for(int j = 0; j < n; j++)
                    {
                        if(array[setIndex][j].lastUsed > max)
                        {
                            max = array[setIndex][j].lastUsed; 
                        }
                    }
                    array[setIndex][i].lastUsed = max + 1; 
                }
            }
        }
        int min = __INT_MAX__;  
        int temp = 0; 
        max = 0; 
        if(hitted == 0)
        {
            miss++; 
            for(int i = 0; i < n; i++)
            {

                if(array[setIndex][i].valid == 0)
                {
                    array[setIndex][i].valid = 1; 
                    array[setIndex][i].tag = tag; 
                    coldHit = 1; 
                    temp = i; 
                    break;  
                }
            }
            int last; 
            if(coldHit == 0)
            {
                for(int i = 0; i < n; i++)
                {
                    last = array[setIndex][i].lastUsed;
                    if(last < min)
                    {
                        min = last; 
                        temp = i; 
                    }
                }
                array[setIndex][temp].tag = tag; 
            }
            for(int i = 0; i < n; i++)
            {
                last = array[setIndex][i].lastUsed;
                if(last > max)
                {
                    max = last; 
                }
            }
            array[setIndex][temp].lastUsed = max + 1; 

        }
        if(type == 'R')
        {
            if(hitted == 0)
            {
                read++;
            }
        }
        else
        {
            write++; 
            if(hitted == 0)
            {
                read++; 
            }
        }
    }
    printf("Memory reads: %d\nMemory writes: %d\nCache hits: %d\nCache misses: %d\n", read, write, hit, miss); 

    fclose(file); 

    for(int i = 0; i < total + 1; i++)
    {
        free(array[i]);
    }
    free(array); 
    
}



