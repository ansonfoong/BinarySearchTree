#include "tree.c"
#include <string.h>
#include <stdio.h>

char * copyString(char * str)
{
    char * copy = malloc(strlen(str)+1);
    strcpy(copy, str);
    return copy;
}

char *  removeNewline(char * str)
{
    int i = 0;
    while(str[i] != 0)
    {
        if(str[i] == '\n')
            str[i] = '\0';
        i++;
    }
    return str;
}
int main(void)
{
    NODE * ROOT = NULL;
    printf("%s\n%s\n", "This is a Binary Search Tree Written in C.", "------------------------------------------");
    
    char * command = malloc(100);
    int flag = 1;
    while(flag)
    {
        printf("Command: ");
        fgets(command, 100, stdin);
        char * copy = copyString(command);
        char * token = removeNewline(strtok(copy, " "));
        if(strcmp(token, "ins") == 0)
        {
            int data = atoi(strtok(NULL, " "));
            insertTree(&ROOT, data);
            printf("Inserted %d", data);
        }
        else if(strcmp(token, "del") == 0)
        {
            int data = atoi(strtok(NULL, " "));
            if(searchTree(&ROOT, data) != NULL)
                deleteNode(&ROOT, data);
        }
        else if(strcmp(token, "in") == 0) printInorder(&ROOT);
        else if(strcmp(token, "pre") == 0) printPreorder(&ROOT);
        else if(strcmp(token, "post") == 0) printPostorder(&ROOT);
        else if(strcmp(token, "full") == 0)
        {
            if(isFull(&ROOT))
                printf("Tree is full!");
            else
                printf("Tree is not full");
        }
        else if(strcmp(token, "complete") == 0)
        {
            
        }
        printf("\n");
    }
    return 0;
}