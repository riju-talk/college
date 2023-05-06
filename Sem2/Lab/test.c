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

void sort(directory *head)
{
    directory *temp;
    char *value;
    temp = head;
    directory *iterator;
    directory *box;
    while (temp != NULL)
    {
        iterator = temp->next;
        value = temp->name;
        box = temp;
        while (iterator != NULL)
        {
            if (strcmp(iterator->name, value) < 0)
            {
                value = iterator->name;
                box = iterator;
            }
            iterator = iterator->next;
        }
        char *tempname = temp->name;
        temp->name = box->name;
        box->name = tempname;
        temp = temp->next;
    }
}

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
            g = (char *)malloc(100 * sizeof(char));
            scanf("%s", g);
            g = (char *)realloc(g, strlen(g) + 1);

            if (strcmp(g, "ls") == 0)
            {
                if (master_temp->child == NULL)
                {
                    printf("\n");
                }
                else
                {
                    directory *cpy;
                    directory* temp;
                    cpy=master_temp->child;
                    /*
                    temp = master_temp->child->next;
                    cpy = (directory *)malloc(sizeof(directory));
                    directory *new_temp;
                    cpy->name = master_temp->child->name;
                    new_temp = cpy;
                    while (temp != NULL)
                    {
                        directory *node;
                        node = (directory *)malloc(sizeof(directory));
                        node->name = temp->name;
                        node->next = NULL;
                        new_temp->next = node;
                        new_temp = new_temp->next;
                        temp = temp->next;
                    }*/
                    sort(cpy);
                    temp=cpy;
                    while(temp!=NULL){
                        printf("%s ",temp->name);
                        temp=temp->next;
                    }
                    printf("\n");
                }
            }
            else if (strcmp(g, "pwd") == 0)
            {
                directory *tempdirectory;
                directory *temp2;
                tempdirectory = NULL;
                directory *temp;
                temp = master_temp;
                while (temp != NULL)
                {
                    temp2 = temp;
                    temp2->next = tempdirectory;
                    tempdirectory = temp2;
                    temp = temp->parent;
                }
                while (tempdirectory->next != NULL)
                {
                    printf("%s/", tempdirectory->name);
                    tempdirectory = tempdirectory->next;
                }
                printf("%s", tempdirectory->name);
                printf("\n");
            }
        }
        if (n == 2)
        {
            char *g;
            char *h;
            g = (char *)malloc(100 * sizeof(char));
            h = (char *)malloc(100 * sizeof(char));
            scanf("%s %s", g, h);
            g = (char *)realloc(g, strlen(g) + 1);
            h = (char *)realloc(h, strlen(h) + 1);
            if (strcmp(g, "cd") == 0)
            {
                if (strcmp(h, "..") == 0)
                {
                    if (master_temp->parent == NULL)
                    {
                        printf("-1\n");
                    }
                    else
                    {
                        master_temp = master_temp->parent;
                    }
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
                        directory* n_temp;
                        n_temp=temp;
                        while (n_temp != NULL)
                        {
                            if (strcmp(n_temp->name, h) == 0)
                            {
                                break;
                            }
                            n_temp = n_temp->next;
                        }
                        if (n_temp == NULL)
                        {
                            printf("-1\n");

                        }
                        else{
                            master_temp=n_temp;
                        }
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

                directory *temp, *temp1;
                temp1 = master_temp->child;
                if (temp1 == NULL)
                {
                    master_temp->child = temp2;
                }
                else
                {
                    while (temp1 != NULL)
                    {
                        if (strcmp(temp1->name, h) == 0)
                        {
                            printf("-1\n");
                            break;
                        }
                        temp = temp1;
                        temp1 = temp1->next;
                    }
                    if (temp1 == NULL)
                    {
                        temp->next = temp2;
                    }
                }
            }
        }
        if (n == 3)
        {
            char *entry1;
            char *entry2;
            char *entry3;
            entry1 = (char *)malloc(100 * sizeof(char));
            entry2 = (char *)malloc(100 * sizeof(char));
            entry3 = (char *)malloc(100 * sizeof(char));
            scanf("%s %s %s", entry1, entry2, entry3);
            entry1 = (char *)realloc(entry1, 100 * sizeof(char));
            entry2 = (char *)realloc(entry2, 100 * sizeof(char));
            entry3 = (char *)realloc(entry3, 100 * sizeof(char));
            if (master_temp->child == NULL)
            {
                printf("-1\n");
            }
            else
            {
                int flag = 0;
                if (strcmp(master_temp->child->name, entry3) == 0)
                {
                    directory *temp2;
                    directory *temp1;
                    temp2 = master_temp->child;
                    temp1 = temp2->next;
                    master_temp->child = temp1;
                    flag = 1;
                }
                else
                {
                    directory *temp2;
                    directory *temp1;
                    temp2 = master_temp->child;
                    while (temp2->next != NULL)
                    {
                        temp1 = temp2;
                        temp2 = temp2->next;
                        if (strcmp(temp2->name, entry3) == 0)
                        {
                            directory *temp3;
                            temp3 = temp2->next;
                            temp1->next = temp3;
                            flag = 1;
                        }
                    }
                    if (strcmp(temp2->name, entry3) == 0 && temp1 != NULL)
                    {
                        directory *temp3;
                        temp3 = temp2->next;
                        temp1->next = temp3;
                        flag = 1;
                    }
                }
                if (flag == 0)
                {
                    printf("-1\n");
                }
            }
        }
        q--;
    }
    return 0;
}