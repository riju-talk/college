#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    int data;
    struct list *next;
} list;



int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    list *head, *temp, *move;
    head = (list *)malloc(sizeof(list));
    temp = (list *)malloc(sizeof(list));
    list *cpy, *temp3;
    cpy = (list* )malloc(sizeof(list));
    head = temp;
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        move = (list *)malloc(sizeof(list));
        move->next = NULL;
        temp->data = k;
        temp->next = move;
        temp = temp->next;
    }
    temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    for (int i = 0; i < q; i++)
    {
        char *s;
        s = (char *)malloc(90 * sizeof(char));
        scanf("%s", s);
        s = (char *)realloc(s, strlen(s) + 1);
        if (strcmp(s, "KthNode") == 0)
        {
            int d;
            scanf("%d", &d);
            temp = head;
            list* temp1;
            int count = 1;
            while (temp != NULL)
            {
                if (count == d)
                {
                    break;
                }
                temp1;
                temp = temp->next;
                count++;
            }
            if (n < d)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n", temp->data);
            }
        }
        if (strcmp(s, "Delete") == 0)
        {
            int d;
            scanf("%d", &d);
            temp = head;
            list* temp1;
            int count = 1;
            while (temp != NULL)
            {
                if (count == d)
                {
                    break;
                }
                temp1=temp;
                temp = temp->next;
                count++;
            }
            if (n < d)
            {
                printf("-1\n");
            }
            else
            {
                list* temp2;
                temp2=temp->next;
                temp1->next = temp2;
                temp = temp->next;
                n--;
            }
        }
        if (strcmp(s, "Add") == 0)
        {
            int d, x;
            scanf("%d %d", &d, &x);
            temp = head;
            list* temp1;
            int count = 1;
            while (temp != NULL)
            {
                if (count == d)
                {
                    break;
                }
                temp1;
                temp = temp->next;
                count++;
            }
            if (n < d)
            {
                printf("-1\n");
            }
            else
            {
                int n_value = temp->data + x;
                temp->data = n_value;
            }
        }
        if (strcmp(s, "Subtract") == 0)
        {
            int d, x;
            scanf("%d %d", &d, &x);
            temp = head;
            list* temp1;
            int count = 1;
            while (temp != NULL)
            {
                if (count == d)
                {
                    break;
                }
                temp1;
                temp = temp->next;
                count++;
            }
            if (n < d)
            {
                printf("-1\n");
            }
            else
            {
                int n_value = temp->data - x;
                temp->data = n_value;
            }
        }
        if (strcmp(s, "Xor") == 0)
        {
            int d, x;
            scanf("%d", &d);
            temp = head;
            list* temp1;
            int count = 1;
            while (temp != NULL)
            {
                if (count == d)
                {
                    break;
                }
                temp1;
                temp = temp->next;
                count++;
            }
            if (n < d)
            {
                printf("-1\n");
            }
            else
            {
                temp = head;
                int l;
                l = q - d;
                count = 1;
                while (temp != NULL)
                {
                    if (count == l)
                    {
                        break;
                    }
                    temp = temp->next;
                    count++;
                }
                int xor_q = 0;
                while (temp != NULL)
                {
                    xor_q = xor_q ^ temp->data;
                    temp = temp->next;
                }
                printf("%d", xor_q);
            }
        }
    }
    return 0;
}