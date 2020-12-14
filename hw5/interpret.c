#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    FILE *file = fopen(argv[1], "r");
    char line[100];
    char arguments[100][100]; 
    int index = 0; 
    for(int i = 0; i < 100; i++)
    {
        strcpy(arguments[i], "");
    }
    while(fgets(line, 100, file))
    {
        strcpy(arguments[index], line);
        index++; 
    }
    int n = sizeof(arguments) / sizeof(arguments[0]); 
    
    fclose(file); 

    //char instuct[10];
    int ax, bx, cx, dx = 0; 
    int x, y; 
    char reg; 
    for(int i = 0; i < n; i++)
    {
       
        if(arguments[i][0] == 'r')
        {
            //read 
            reg = arguments[i][5]; 
            switch(reg)
            {
                case 'a':
                    scanf("%d", &ax);
                    break; 
                case 'b':
                    scanf("%d", &bx);
                    break; 
                case 'c':
                    scanf("%d", &cx);
                    break; 
                case 'd':
                    scanf("%d", &dx);
                    
            }
            //printf("%d\t%d\t%d\t%d\t", ax, bx, cx, dx);
            continue; 
        }
        else if(arguments[i][0] == 'p')
        {
            //print
            int count = 0; 
            int index = 6; 
            reg = arguments[i][6];
            switch(reg)
            {
                case 'a':
                    printf("%d", ax);
                    break; 
                case 'b':
                    printf("%d", bx);
                    break; 
                case 'c':
                    printf("%d", cx);
                    break; 
                case 'd':
                    printf("%d", dx);
                    break; 
                default: 
                    
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++;
                        
                    }
                    int current = 6;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    x = atoi(num); 
                    memset(&(num[0]), 0, count);
                    printf("%d", x); 
                    
            }

        }
        else if(arguments[i][0] == 'a')
        {
            //add
            int count = 0; 
            int index = 4; 
            reg = arguments[i][4];
            //printf("%c", reg); 
            //cx = 2; 
            switch(reg)
            {
                case 'a':
                    x = ax; 
                    count = 2; 
                    break; 
                case 'b':
                    x = bx;
                    count = 2; 
                    break; 
                case 'c':
                    x = cx; 
                    count = 2; 
                    break; 
                case 'd':
                    x = dx; 
                    count = 2; 
                    break; 
                default: 
                    //printf("hello");
                    count = 0; 
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++;
                        
                    }
                    int current = 4;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    x = atoi(num); 
                    memset(&(num[0]), 0, count);
                    //printf("%d", x);       
            }
            //printf("this is x: %d", x);
            index = 4 + count + 1; 
            reg = arguments[i][index];
            switch(reg)
            {
                case 'a':
                    ax += x; 
                    break; 
                case 'b':
                    bx += x; 
                    break; 
                case 'c':
                    cx += x;  
                    break; 
                case 'd':
                    dx += x;
            }
            //printf("%d\t%d\t%d\t%d\t", ax, bx, cx, dx);
            continue; 
        }
        else if(arguments[i][0] == 's')
        {
            //subtract
            
            int count = 0; 
            int index = 4; 
            reg = arguments[i][4];
            
            switch(reg)
            {
                case 'a':
                    x = ax; 
                    count = 2; 
                    break; 
                case 'b':
                    x = bx;
                    count = 2; 
                    break; 
                case 'c':
                    x = cx; 
                    count = 2; 
                    break; 
                case 'd':
                    x = dx; 
                    count = 2; 
                    break; 
                default: 
                    //printf("hello");
                    count = 0; 
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++;
                        
                    }
                    int current = 4;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    x = atoi(num);
                    memset(&(num[0]), 0, count); 
                    //printf("%d", x);       
            }
            //printf("%d\t%d\t%d\t%d\t", ax, bx, cx, dx);
            index = 4 + count + 1; 
            reg = arguments[i][index];
            switch(reg)
            {
                case 'a':
                    ax -= x; 
                    break; 
                case 'b':
                    bx -= x; 
                    break; 
                case 'c':
                    cx -= x;  
                    break; 
                case 'd':
                    dx -= x;
            }
        }
        else if(arguments[i][0] == 'd')
        {
            int count = 0; 
            int index = 4; 
            reg = arguments[i][4];
            //printf("%c", reg); 
            //cx = 2; 
            switch(reg)
            {
                case 'a':
                    x = ax; 
                    count = 2; 
                    break; 
                case 'b':
                    x = bx;
                    count = 2; 
                    break; 
                case 'c':
                    x = cx; 
                    count = 2; 
                    break; 
                case 'd':
                    x = dx; 
                    count = 2; 
                    break; 
                default: 
                    //printf("hello");
                    count = 0; 
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++;
                        
                    }
                    int current = 4;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    x = atoi(num); 
                    memset(&(num[0]), 0, count);
                    //printf("%d", x);       
            }
            //printf("this is x: %d", x);
            index = 4 + count + 1; 
            reg = arguments[i][index];
            switch(reg)
            {
                case 'a':
                    ax = x/ax; 
                    break; 
                case 'b':
                    bx = x/bx; 
                    break; 
                case 'c':
                    cx=x/cx;  
                    break; 
                case 'd':
                    dx = x/dx;
            }
        }
        else if(arguments[i][0] == 'm')
        {
            if(arguments[i][1] == 'o')
            {
                //move 
                int count = 0; 
                int index = 4; 
                reg = arguments[i][4];
                switch(reg)
                {
                    case 'a':
                        x = ax; 
                        count = 2; 
                        break; 
                    case 'b':
                        x = bx;
                        count = 2; 
                        break; 
                    case 'c':
                        x = cx; 
                        count = 2; 
                        break; 
                    case 'd':
                        x = dx; 
                        count = 2; 
                        break; 
                    default: 
                        //printf("hello");
                        count = 0; 
                        while(arguments[i][index] != '\040')
                        {
                            count++; 
                            index++;
                            
                        }
                        int current = 4;  
                        char num[count];
                        for(int j = 0; j < count; j++)
                        {
                            num[j] = arguments[i][current];
                            current++; 
                        }
                        x = atoi(num); 
                        memset(&(num[0]), 0, count);
                               
                }
                index = 4 + count + 1; 
                reg = arguments[i][index];
               
                switch(reg)
                {
                    case 'a':
                        ax = x; 
                        break; 
                    case 'b':
                        bx = x; 
                        break; 
                    case 'c':
                        cx = x;  
                        break; 
                    case 'd':
                        dx = x;
                }
                

            }
            else if(arguments[i][1] == 'u')
            {
                int count = 0; 
                int index = 4; 
                reg = arguments[i][4];
                //printf("herlelelel %c", reg); 
                //cx = 2; 
                switch(reg)
                {
                    case 'a':
                        x = ax; 
                        count = 2; 
                        break; 
                    case 'b':
                        x = bx;
                        count = 2; 
                        break; 
                    case 'c':
                        x = cx; 
                        count = 2; 
                        break; 
                    case 'd':
                        x = dx; 
                        count = 2; 
                        break; 
                    default: 
                        //printf("hello");
                        count = 0; 
                        while(arguments[i][index] != '\040')
                        {
                            count++; 
                            index++;
                            
                        }
                        int current = 4;  
                        char num[count];
                        for(int j = 0; j < count; j++)
                        {
                            num[j] = arguments[i][current];
                            current++; 
                        }
                        x = atoi(num); 
                        memset(&(num[0]), 0, count); 
                        //("this is X in mul: %d\n", x);       
                }
                //printf("this is x: %d", x);
                index = 4 + count + 1; 
                reg = arguments[i][index];
                switch(reg)
                {
                    case 'a':
                        ax *= x; 
                        break; 
                    case 'b':
                        bx *= x; 
                        break; 
                    case 'c':
                        cx *= x;  
                        break; 
                    case 'd':
                        dx *= x;

                }
            }
                
        }
        else if(arguments[i][0] == 'j')
        {
            
            if(arguments[i][1] == 'm')
            {
                //jmp reg = arguments[i][4]; 
                int count = 0;  
                int index = 4; 
                while(arguments[i][index] != '\040')
                {
                    count++; 
                    index++; 
                }
                int current = 4;  
                char num[count];
                for(int j = 0; j < count; j++)
                {
                    num[j] = arguments[i][current];
                    current++; 
                }
                x = atoi(num);
                memset(&(num[0]), 0, count);
                //printf("This is x: %d \n",x);
                i = x - 1; 
                //printf("this is i %d", i);
                //puts(arguments[i]);
            }
            else if(arguments[i][1] == 'e')
            {
                //je
                int count = 0; 
                int index = 3; 
                reg = arguments[i][3];
                //printf("Hello");
                while(arguments[i][index] != '\040')
                {
                    count++; 
                    index++; 
                }
                int current = 3;  
                char num[count];
                for(int j = 0; j < count; j++)
                {
                    num[j] = arguments[i][current];
                    current++; 
                }
                int l = atoi(num);
                memset(&(num[0]), 0, count);
                //printf("This is L: %d \n",l);
                int jump = l - 1; 
                index = 3 + count + 1; 
                reg = arguments[i][index]; 
                switch(reg)
                {
                    case 'a':
                        x = ax; 
                        count = 2; 
                        break; 
                    case 'b':
                        x = bx;
                        count = 2; 
                        break; 
                    case 'c':
                        x = cx; 
                        count = 2; 
                        break; 
                    case 'd':
                        x = dx; 
                        count = 2; 
                        break; 
                    default: 
                        //printf("hello");
                        count = 0; 
                        int counter = index; 
                        while(arguments[i][counter] != '\040')
                        {
                            count++;                                                                
                            counter++;
                        }
                        int current = index; 
                        char num2[count];
                        for(int j = 0; j < count; j++)
                        {
                            num2[j] = arguments[i][current];
                            current++; 
                        }
                        x = atoi(num2); 
                        memset(&(num2[0]), 0, count);
                        //printf("This is X: %d", x);       
                }
                index += count + 1; 
                reg = arguments[i][index];
                switch(reg)
                {
                    case 'a':
                        if(ax == x)
                        {
                            i = jump; 
                        } 
                        break; 
                    case 'b':
                        if(bx == x)
                        {
                            i = jump; 
                        }
                        break; 
                    case 'c':
                        if(cx == x)
                        {
                            i = jump; 
                        }  
                        break; 
                    case 'd':
                        if(dx == x)
                        {
                            i = jump; 
                        }
                        break; 
                    default: 
                        count = 0; 
                        int counter = index; 
                        while(arguments[i][counter] != '\040')
                        {
                            count++;                                                                
                            counter++;
                        }
                        int current = index; 
                        char num2[count];
                        for(int j = 0; j < count; j++)
                        {
                            num2[j] = arguments[i][current];
                            current++; 
                        }
                        y = atoi(num2);
                        memset(&(num2[0]), 0, count);
                        num2[0] = 0; 
                        if(x == y)
                        {
                            i = jump; 
                        }

                }

            }
            else if(arguments[i][1] == 'n')
            {
                //jne
                int count = 0; 
                int index = 4; 
                reg = arguments[i][4];
                //printf("Hello JNENENENNENENENE");
                while(arguments[i][index] != '\040')
                {
                    count++; 
                    index++; 
                }
                int current = 4;  
                char num[count];
                for(int j = 0; j < count; j++)
                {
                    num[j] = arguments[i][current];
                    current++; 
                }
                int l = atoi(num);
                memset(&(num[0]), 0, count);
                //printf("This is L: %d \n",l);
                int jump = l - 1; 
                index = 4 + count + 1; 
                reg = arguments[i][index]; 
                switch(reg)
                {
                    case 'a':
                        x = ax; 
                        count = 2; 
                        break; 
                    case 'b':
                        x = bx;
                        count = 2; 
                        break; 
                    case 'c':
                        x = cx; 
                        count = 2; 
                        break; 
                    case 'd':
                        x = dx; 
                        count = 2; 
                        break; 
                    default: 
                        //printf("hello");
                        count = 0; 
                        int counter = index; 
                        while(arguments[i][counter] != '\040')
                        {
                            count++;                                                                
                            counter++;
                        }
                        int current = index; 
                        char num2[count];
                        for(int j = 0; j < count; j++)
                        {
                            num2[j] = arguments[i][current];
                            current++; 
                        }
                        x = atoi(num2); 
                        memset(&(num2[0]), 0, count);
                        //printf("This is X: %d", x);       
                }
                index += count + 1; 
                reg = arguments[i][index];
                switch(reg)
                {
                    case 'a':
                        if(ax != x)
                        {
                            i = jump; 
                        } 
                        break; 
                    case 'b':
                        if(bx != x)
                        {
                            i = jump; 
                        }
                        break; 
                    case 'c':
                        if(cx != x)
                        {
                            i = jump; 
                        }  
                        break; 
                    case 'd':
                        if(dx != x)
                        {
                            i = jump; 
                        }
                        break; 
                    default: 
                        count = 0; 
                        int counter = index; 
                        while(arguments[i][counter] != '\040')
                        {
                            count++;                                                                
                            counter++;
                        }
                        int current = index; 
                        char num2[count];
                        for(int j = 0; j < count; j++)
                        {
                            num2[j] = arguments[i][current];
                            current++; 
                        }
                        y = atoi(num2);
                        memset(&(num2[0]), 0, count); 
                        if(x != y)
                        {
                            i = jump; 
                        }

                }
            }
            else if(arguments[i][1] == 'g')
            {
                if(arguments[i][2] == 'e')
                {
                    //jge
                    
                    int count = 0; 
                    int index = 4; 
                    reg = arguments[i][4];
                    //printf("Hello");
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++; 
                    }
                    int current = 4;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    int l = atoi(num);
                    memset(&(num[0]), 0, count);
                   // printf("\nThis is L: %d \n",l);
                    int jump = l - 1; 
                    index = 4 + count + 1; 
                    reg = arguments[i][index]; 
                    switch(reg)
                    {
                        case 'a':
                            x = ax; 
                            count = 2; 
                            break; 
                        case 'b':
                            x = bx;
                            count = 2; 
                            break; 
                        case 'c':
                            x = cx; 
                            count = 2; 
                            break; 
                        case 'd':
                            x = dx; 
                            count = 2; 
                            break; 
                        default: 
                            //printf("hello");
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            x = atoi(num2); 
                            memset(&(num2[0]), 0, count); 
                            //printf("This is X: %d", x);       
                    }
                    index += count + 1; 
                    reg = arguments[i][index];
                    switch(reg)
                    {
                        case 'a':
                            if(ax <= x)
                            {
                                i = jump; 
                            } 
                            break; 
                        case 'b':
                            if(bx <= x)
                            {
                                i = jump; 
                            }
                            break; 
                        case 'c':
                            if(cx <= x)
                            {
                                i = jump; 
                            }  
                            break; 
                        case 'd':
                            if(dx <= x)
                            {
                                i = jump; 
                            }
                            break; 
                        default: 
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            y = atoi(num2);
                            memset(&(num2[0]), 0, count); 
                            if(x >= y)
                            {
                                i = jump; 
                            }

                    }
                }
                else
                {
                    //jg
                    int count = 0; 
                    int index = 3; 
                    reg = arguments[i][3];
                    //printf("Hello");
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++; 
                    }
                    int current = 3;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    int l = atoi(num);
                    memset(&(num[0]), 0, count);
                    //printf("This is L: %d \n",l);
                    int jump = l - 1; 
                    index = 3 + count + 1; 
                    reg = arguments[i][index]; 
                    switch(reg)
                    {
                        case 'a':
                            x = ax; 
                            count = 2; 
                            break; 
                        case 'b':
                            x = bx;
                            count = 2; 
                            break; 
                        case 'c':
                            x = cx; 
                            count = 2; 
                            
                            break; 
                        case 'd':
                            x = dx; 
                            
                            count = 2; 
                            break; 
                        default: 
                            //printf("hello");
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            x = atoi(num2); 
                            memset(&(num2[0]), 0, count);
                            //printf("This is X: %d", x);       
                    }
                    index += count + 1; 
                    reg = arguments[i][index];
                    switch(reg)
                    {
                        case 'a':
                            if(ax < x)
                            {
                                i = jump; 
                            } 
                            break; 
                        case 'b':
                            if(bx < x)
                            {
                                i = jump; 
                            }
                            break; 
                        case 'c':
                            if(cx < x)
                            {
                                i = jump; 
                            }  
                            break; 
                        case 'd':
                            if(dx < x)
                            {
                                i = jump; 
                            }
                            break; 
                        default: 
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            y = atoi(num2);
                            
                            memset(&(num2[0]), 0, count);
                            if(x > y)
                            {
                                i = jump; 
                            }

                    }
                }
                
            }
            else if(arguments[i][1] == 'l')
            {
                if(arguments[i][2] == 'e')
                {
                    //jle
                    //printf("hello jle ");
                    int count = 0; 
                    int index = 4; 
                    reg = arguments[i][4];
                    //printf("Hello");
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++; 
                    }
                    int current = 4;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    int l = atoi(num);
                    memset(&(num[0]), 0, count);
                    //printf("This is L: %d \n",l);
                    int jump = l - 1; 
                    index = 4 + count + 1; 
                    reg = arguments[i][index]; 
                    switch(reg)
                    {
                        case 'a':
                            x = ax; 
                            count = 2; 
                            break; 
                        case 'b':
                            x = bx;
                            count = 2; 
                            break; 
                        case 'c':
                            x = cx; 
                            count = 2; 
                            break; 
                        case 'd':
                            x = dx; 
                            count = 2; 
                            break; 
                        default: 
                            //printf("hello");
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            x = atoi(num2); 
                            memset(&(num2[0]), 0, count);
                            //printf("This is X: %d", x);       
                    }
                    index += count + 1; 
                    reg = arguments[i][index];
                    switch(reg)
                    {
                        case 'a':
                            if(ax >= x)
                            {
                                i = jump; 
                            } 
                            break; 
                        case 'b':
                            if(bx >= x)
                            {
                                i = jump; 
                            }
                            break; 
                        case 'c':
                            if(cx >= x)
                            {
                                i = jump; 
                            }  
                            break; 
                        case 'd':
                            if(dx >= x)
                            {
                                i = jump; 
                            }
                            break; 
                        default: 
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            y = atoi(num2);
                            memset(&(num2[0]), 0, count);
                            if(x <= y)
                            {
                                i = jump; 
                            }

                    }
                }
                else
                {
                     //jl 
                     int count = 0; 
                    int index = 3; 
                    reg = arguments[i][3];
                    //printf("Hello");
                    while(arguments[i][index] != '\040')
                    {
                        count++; 
                        index++; 
                    }
                    int current = 3;  
                    char num[count];
                    for(int j = 0; j < count; j++)
                    {
                        num[j] = arguments[i][current];
                        current++; 
                    }
                    int l = atoi(num);
                    memset(&(num[0]), 0, count);
                    //printf("This is L: %d \n",l);
                    int jump = l - 1; 
                    index = 3 + count + 1; 
                    reg = arguments[i][index]; 
                    switch(reg)
                    {
                        case 'a':
                            x = ax; 
                            count = 2; 
                            break; 
                        case 'b':
                            x = bx;
                            count = 2; 
                            break; 
                        case 'c':
                            x = cx; 
                            count = 2; 
                            break; 
                        case 'd':
                            x = dx; 
                            count = 2; 
                            break; 
                        default: 
                            //printf("hello");
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            x = atoi(num2); 
                            memset(&(num2[0]), 0, count); 
                            //printf("This is X: %d", x);       
                    }
                    index += count + 1; 
                    reg = arguments[i][index];
                    switch(reg)
                    {
                        case 'a':
                            if(ax > x)
                            {
                                i = jump; 
                            } 
                            break; 
                        case 'b':
                            if(bx > x)
                            {
                                i = jump; 
                            }
                            break; 
                        case 'c':
                            if(cx > x)
                            {
                                i = jump; 
                            }  
                            break; 
                        case 'd':
                            if(dx > x)
                            {
                                i = jump; 
                            }
                            break; 
                        default: 
                            count = 0; 
                            int counter = index; 
                            while(arguments[i][counter] != '\040')
                            {
                                count++;                                                                
                                counter++;
                            }
                            int current = index; 
                            char num2[count];
                            for(int j = 0; j < count; j++)
                            {
                                num2[j] = arguments[i][current];
                                current++; 
                            }
                            y = atoi(num2);
                            memset(&(num2[0]), 0, count);
                            if(x < y)
                            {
                                i = jump; 
                            }
                    }
                }
            }
        }
        
    }   
}
