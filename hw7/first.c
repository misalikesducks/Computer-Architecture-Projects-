#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <math.h> 

typedef struct Node{
    int data; 
    struct Node* next; 
    char name[11];
}Node; 

typedef struct commands{
    char gate[20]; 
    char in1[11];
    char in2[11];
    char out[11];
    struct commands* next; 
}commands;

void insert(Node **front, Node* newNode);
void printList(Node* n);
void not(Node** front, char *input1, char *output);
Node* add (Node **curr, int n);
void and(Node **front, char *input1, char *input2, char *output);
void insertCommands(commands **front, commands *newLine);
void or(Node **front, char *input1, char *input2, char *output);
void nand(Node **front, char *input1, char *input2, char *output);
void nor(Node **front, char *input1, char *input2, char *output);
void xor(Node **front, char *input1, char *input2, char *output);

int main(int argc, char* argv[1])
{
    FILE *file = fopen(argv[1], "r");

    int numVars; 
    fscanf(file, "INPUTVAR %d", &numVars);
    Node *row = NULL; 
  
    for(int i = 0; i < numVars; i++)
    {
        Node *newNode = (Node*) malloc(sizeof(Node));
        fscanf(file, "%s", newNode->name);
        //printf("%s: ", newNode->name);
        newNode -> next = NULL; 
        newNode -> data = 0; 
        insert(&row, newNode); 
       // printList(row); 
        
    }
    int numOuts; 
    
    fscanf(file, "\nOUTPUTVAR %d", &numOuts);
    for(int i = 0; i < numOuts; i++)
    {
        Node *newNode2 = (Node*)malloc(sizeof(Node));
        fscanf(file, "%s", newNode2 ->name);
        newNode2 -> next = NULL;
        newNode2 -> data = 0; 
        insert(&row, newNode2);
        
    }
    char command[20]; 
    int binary = 0; 
    char input1[20];
    char input2[20];
    char output[20]; 
    char line[100]; 
    commands *stuff = NULL; 
    while(fscanf(file, "%s", &command[0]) != EOF)
    {
        if(strcmp(command, "NOT") == 0)
        {
            fscanf(file, "%s %s", &input1[0], &output[0]); 
            commands *newLine = (commands*) malloc(sizeof(commands)); 
            newLine ->next = NULL; 
            strcpy(newLine -> gate, command); 
            strcpy(newLine->out, output); 
            strcpy(newLine->in1, input1); 
            strcpy(newLine->in2, "");
            insertCommands(&stuff, newLine);
            //printf("Command: %s, in1: %s, out: %s\n", newLine ->gate,newLine->in1, newLine->out);
        }
        else
        {
            fscanf(file, "%s %s %s", &input1[0], &input2[0], &output[0]); 
            
            commands *newLine = (commands*) malloc(sizeof(commands)); 
            newLine ->next = NULL; 
            strcpy(newLine -> gate, command); 
            strcpy(newLine->out, output); 
            strcpy(newLine->in1, input1); 
            strcpy(newLine ->in2, input2);
            insertCommands(&stuff, newLine);
            //printf("Command: %s, in1: %s, in2: %s out: %s\n", newLine ->gate,newLine->in1, newLine->in2, newLine->out);
        }
    }
    fclose(file); 
    for(int i = 0; i < pow(2, numVars); i++)
    {
        //printList(row);
        Node *print = row; 
        for(int i = 0; i < numVars; i++)
        {
            printf("%d ", print->data); 
            print = print -> next; 
        }
        for(commands *cPtr = stuff; cPtr != NULL; cPtr = cPtr->next)
        {
            //printf("Command: %s, in1: %s, in2: %s out: %s\n", cPtr ->gate,cPtr->in1, cPtr->in2, cPtr->out);
            //printf("before: ");
            //printList(row); 
            Node *temps = row; 
            int exist = 0; 
            while(temps != NULL)
            {
                if(strcmp(temps->name, cPtr->out)== 0)
                {
                    exist = 1; 
                    break; 
                }
                temps = temps->next; 
            }
            if(exist == 0)
            {
                Node* spicy = (Node*) malloc(sizeof(Node));
                strcpy(spicy->name, cPtr->out);
                spicy -> data = 0; 
                spicy -> next = NULL; 
                insert(&row, spicy);
            }
            if(strcmp(cPtr->gate, "NOT") == 0)
            {
                not(&row, cPtr->in1, cPtr->out);
                //
            }
            else if(strcmp(cPtr->gate, "AND") == 0) and(&row, cPtr->in1, cPtr -> in2, cPtr->out);
            else if(strcmp(cPtr->gate, "OR") == 0) or(&row, cPtr->in1, cPtr -> in2, cPtr->out);
            else if(strcmp(cPtr->gate, "NAND") == 0) nand(&row, cPtr->in1, cPtr -> in2, cPtr->out);
            else if(strcmp(cPtr->gate, "NOR") == 0) nor(&row, cPtr->in1, cPtr -> in2, cPtr->out);
            else if(strcmp(cPtr->gate, "XOR") == 0) xor(&row, cPtr->in1, cPtr -> in2, cPtr->out);
        
        }
        Node *curr = NULL; 
        //printList(row);

        //updating the values 
        
       // printf("\nJbfdjsdhbgjkdshg : %d\n", binary);
        binary++; 
        
        if(binary < pow(2, numVars))
        {
            
            int ind = 0; 
            int hate = binary; 
            while(hate > 0)
            {
                curr = add(&curr, hate%2);
                hate = hate / 2;
                ind++;
            }
            //printList(curr);
            while(ind < numVars)
            {
                //printf("hello");
                curr = add(&curr, 0); 
                ind++; 
            }
            // printf("\nthis is curr: \n");
            // printList(curr);
        }
        
        Node *chang = row; 
        Node *curr2;  
        
       // printList(curr);
        while((curr2 = curr) != NULL)
        {
            chang->data = curr->data; 
            //printf("hi %s: %d", chang->name, chang->data);
            curr = curr ->next; 
           // printf("hello");
            chang = chang ->next;
            free(curr2);
        }   
          
        Node *no = row; 
        
        for(int i = 0; i < numVars; i++)
        {
            no = no->next; 
        }
        for(int i = 0; i < numOuts; i++)
        {
            printf("%d ", no->data);
            no = no->next; 
        }
        for(int i = 0; i < numOuts; i++)
        {
            chang -> data = 0; 
            chang = chang->next; 
        }

        printf("\n");
        
    }
    commands *death; 
    while((death = stuff) != NULL)
    {
        stuff = stuff->next; 
        free(death);
    }
    Node *hi; 
    while((hi = row) != NULL)
    {
        row = row->next; 
        free(hi);
    }
}
void nor(Node **front, char *input1, char *input2, char *output)
{
    Node *ptr = *front; 
    Node *input = NULL; 
    Node *out = NULL; 
    Node *in2 = NULL; 
    while(ptr != NULL)
    {
        if(strcmp(input1, ptr->name) == 0)
        {
            input = ptr; 
        }
        if(strcmp(output, ptr->name) == 0)
        {
            out = ptr; 
        }
        if(strcmp(input2, ptr->name) == 0)
        {
            in2 = ptr; 
        }
        ptr = ptr->next;

    }
    out->data = !(input->data || in2 -> data);
    //printf("%d", out->data);
    return; 
}
void xor(Node **front, char *input1, char *input2, char *output)
{
    Node *ptr = *front; 
    Node *input = NULL; 
    Node *out = NULL; 
    Node *in2 = NULL; 
    while(ptr != NULL)
    {
        if(strcmp(input1, ptr->name) == 0)
        {
            input = ptr; 
        }
        if(strcmp(output, ptr->name) == 0)
        {
            out = ptr; 
        }
        if(strcmp(input2, ptr->name) == 0)
        {
            in2 = ptr; 
        }
        ptr = ptr->next;

    }
    out->data = (input->data ^ in2 -> data);
    //printf("%d", out->data);
    return; 
}
void nand(Node **front, char *input1, char *input2, char *output)
{
    Node *ptr = *front; 
    Node *input = NULL; 
    Node *out = NULL; 
    Node *in2 = NULL; 
    while(ptr != NULL)
    {
        if(strcmp(input1, ptr->name) == 0)
        {
            input = ptr; 
        }
        if(strcmp(output, ptr->name) == 0)
        {
            out = ptr; 
        }
        if(strcmp(input2, ptr->name) == 0)
        {
            in2 = ptr; 
        }
        ptr = ptr->next;

    }
    out->data = !(input->data && in2 -> data);
    //printf("%d", out->data);
    return; 
}
void or(Node **front, char *input1, char *input2, char *output)
{
    Node *ptr = *front; 
    Node *input = NULL; 
    Node *out = NULL; 
    Node *in2 = NULL; 
    while(ptr != NULL)
    {
        if(strcmp(input1, ptr->name) == 0)
        {
            input = ptr; 
        }
        if(strcmp(output, ptr->name) == 0)
        {
            out = ptr; 
        }
        if(strcmp(input2, ptr->name) == 0)
        {
            in2 = ptr; 
        }
        ptr = ptr->next;

    }
    out->data = (input->data || in2 -> data);
    //printf("%d", out->data);
    return; 
}
void and(Node **front, char *input1, char *input2, char *output)
{
    //printf("Hello");
    Node *ptr = *front; 
    Node *input = NULL; 
    Node *out = NULL; 
    Node *in2 = NULL; 
    while(ptr != NULL)
    {
        if(strcmp(input1, ptr->name) == 0)
        {
            input = ptr; 
        }
        if(strcmp(output, ptr->name) == 0)
        {
            out = ptr; 
        }
        if(strcmp(input2, ptr->name) == 0)
        {
            in2 = ptr; 
        }
        ptr = ptr->next;

    }
    out->data = (input->data && in2 -> data);
    //printf("\nthis is a thing %d\n", out->data);
    return; 
}
Node* add(Node **curr, int n)
{
    Node *temp; 
    temp = (Node *) malloc(sizeof(Node));
    temp -> data = n; 
    temp -> next = *curr; 
    return temp; 
}
void not(Node** front, char *input1, char *output)
{
    //printf("hello");
    Node *ptr = *front; 
    Node *input = NULL; 
    Node *out = NULL; 
    while(ptr != NULL)
    {
        if(strcmp(input1, ptr->name) == 0)
        {
            input = ptr; 
        }
        if(strcmp(output, ptr->name) == 0)
        {
            out = ptr; 
        }
        ptr = ptr->next;
    }
    out->data = !input->data; 
    //printf("%d", out->data);
    return; 
}
void insertCommands(commands **front, commands *newLine) //inserting into the linkedlist of commands 
{
    commands *current = *front;  

    if(*front == NULL)
    {
        *front = newLine; 
        return; 
    }
    else
    {
        //current = *front; 
        while(current ->next != NULL)
        {
            current = current -> next; 
        }
        
        current -> next = newLine; 
        return; 
    }
}
void insert(Node **front, Node* newNode) //inserting into the LinkedList of binary 
{
    Node *current = *front;  

    if(*front == NULL)
    {
        *front = newNode; 
        return; 
    }
    else
    {
        //current = *front; 
        while(current ->next != NULL)
        {
            current = current -> next; 
        }
        
        current -> next = newNode; 
        return; 
    }
}
void printList(Node* n) //method for testing 
{
	while( n != NULL)
    {
        printf("%s: %d ", n ->name, n->data); 
        n = n -> next; 
    }
}
