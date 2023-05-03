#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct directory
{
    char *name;
    struct directory *next;
    struct directory *parent;
    struct directory *child;
} directory;

int main()
{
    directory *root;
    root = (directory *)malloc(sizeof(directory));
    root->child = NULL;
    root->parent = NULL;
    root->next = NULL;
    root->name = (char *)malloc(5 * sizeof(char));
    root->name = "root";
    int q;
    scanf("%d", &q);
    directory *master_temp;
    master_temp = root;
    while (q > 0)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            char *g;
            g = (char *)malloc(20 * sizeof(char));
            scanf("%s", g);
            g = (char *)realloc(g, strlen(g) + 1);

            if (strcmp(g, "ls") == 0)
            {
                directory *temp;
                temp = master_temp->child;
                while (temp != NULL)
                {
                    printf("%s", temp->name);
                    printf(" ");
                    temp = temp->next;
                }
                printf("\n");
            }
            else if (strcmp(g, "pwd") == 0)
            {
                directory* templist;
                directory* temp2;
                templist=NULL;
                directory *temp;
                temp = master_temp;
                while (temp != NULL)
                {
                    temp2 = temp;
                    temp2->next=templist;
                    templist=temp2;
                    temp = temp->parent;
                }
                while(templist->next!=NULL){
                    printf("%s/", templist->name);
                    templist=templist->next;
                }
                printf("%s",templist->name);
                printf("\n");
            }
        }
        if (n == 2)
        {
            char *g;
            char *h;
            g = (char *)malloc(20 * sizeof(char));
            h = (char *)malloc(20 * sizeof(char));
            scanf("%s %s", g, h);
            g = (char *)realloc(g, strlen(g) + 1);
            h = (char *)realloc(h, strlen(h) + 1);
            if (strcmp(g, "cd") == 0)
            {
                if (strcmp(h, "..") == 0)
                {
                    master_temp = master_temp->parent;
                }
                else
                {
                    directory *temp;
                    temp = master_temp->child;
                    if (temp == NULL)
                    {
                        printf("-1\n");
                    }
                    else
                    {
                        while (temp != NULL)
                        {
                            if (strcmp(temp->name, h) == 0)
                            {
                                break;
                            }
                            temp = temp->next;
                        }
                        if (temp == NULL)
                        {
                            printf("-1\n");
                            break;
                        }
                        master_temp = temp;
                    }
                }
            }
            if (strcmp(g, "mkdir") == 0)
            {
                directory *temp2;
                temp2 = (directory *)malloc(sizeof(directory));
                temp2->name = h;
                temp2->parent = master_temp;
                temp2->next = NULL;
                temp2->child = NULL;
                if (master_temp->child == NULL)
                {
                    master_temp->child = temp2;
                }
                else if(strcmp(master_temp->child->name,h)==0)
                {
                    printf("-1\n");
                }
                else
                {
                    directory *temp1;
                    temp1 = master_temp->child;
                    while (temp1->next != NULL)
                    {
                        if (strcmp(temp1->name, h) == 0 || strcmp(temp1->next->name, h) == 0)
                        {
                            printf("-1");
                            break;
                        }
                        temp1 = temp1->next;
                    }
                    if (temp1->next == NULL)
                    {
                        temp1->next = temp2;
                    }
                }
            }
        }
        if (n == 3)
        {
            char *entry1;
            char *entry2;
            char *entry3;
            entry1 = (char *)malloc(20 * sizeof(char));
            entry2 = (char *)malloc(20 * sizeof(char));
            entry3 = (char *)malloc(20 * sizeof(char));
            scanf("%s %s %s", entry1, entry2, entry3);
            entry1 = (char *)realloc(entry1, 20 * sizeof(char));
            entry2 = (char *)realloc(entry2, 20 * sizeof(char));
            entry3 = (char *)realloc(entry3, 20 * sizeof(char));
            if (master_temp->child == NULL)
            {
                printf("-1\n");
            }
            else
            {
                int flag=0;
                if(strcmp(master_temp->child->name,entry3)==0){
                    directory* temp2;
                    directory* temp1;
                    temp2=master_temp->child;
                    temp1=temp2->next;
                    master_temp->child=temp1;
                    flag=1;
                }
                else{
                    directory* temp2;
                    directory* temp1;
                    temp2=master_temp->child;
                    while(temp2->next!=NULL){
                        temp1=temp2;
                        temp2=temp2->next;
                        if(strcmp(temp2->name,entry3)==0){
                            directory * temp3;
                            temp3=temp2->next;
                            temp1->next=temp3;
                            flag=1;
                        }
                    }
                    if(strcmp(temp2->name,entry3)==0 && temp1!=NULL){
                        directory * temp3;
                        temp3=temp2->next;
                        temp1->next=temp3;
                        flag=1;
                    }
                }
                if(flag==0){
                    printf("-1\n");
                }
            }
        }
        q--;
    }
    return 0;
}