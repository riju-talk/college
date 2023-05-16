#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

typedef struct queue
{
    tree **arr;
    int head;
    int tail;
    int size;
} queue;

tree *create(int data)
{
    tree *yes;
    yes = (tree *)malloc(sizeof(tree));
    yes->data = data;
    yes->left = NULL;
    yes->right = NULL;
    return yes;
}

queue *create_q(int size)
{
    queue *yes;
    yes = (queue *)malloc(sizeof(queue));
    yes->head = 0;
    yes->tail = 0;
    yes->size = size;
    yes->arr = (tree **)malloc(size * sizeof(tree *));
}

int is_full(queue *q)
{
    if ((q->head + 1) % q->size == q->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_emp(queue *q)
{
    if (q->head == q->tail)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void enque(queue *list, tree *d)
{
    if (is_full(list) || d == NULL)
    {
        return;
    }
    else
    {
        list->arr[list->head] = d;
        list->head = (list->head + 1) % list->size;
    }
}

tree *deque(queue *list)
{
    tree *temp;
    if (!is_emp(list))
    {
        temp = list->arr[list->tail];
        list->tail = (list->tail + 1) % list->size;
        return temp;
    }
    else
    {
        return NULL;
    }
}

tree *create_tree(int *data, int n)
{
    tree *n_root;
    queue *elts = create_q(n), queue, *emp = create_q(n);
}

void travel(tree *root)
{
    if (root != NULL)
    {
        travel(root->left);
        travel(root->right);
        printf("%d ", root->data);
    }
    else
    {
        return;
    }
}

void level_o_traversal(tree *root, int k)
{
    queue *ls;
    ls = create_q(k);
    enque(ls, root);
    while (!is_emp(ls))
    {
        tree *temp;
        temp = deque(ls);
        printf("%d ", temp->data);
        enque(ls, temp->left);
        enque(ls, temp->right);
    }
    return;
}

tree *input_level(int *arr, int n)
{
    queue *ls;
    ls = create_q(n);
    tree *l, *r, *root, *temp;
    root = create(arr[0]);
    enque(ls, root);
    int i = 1;
    while (i < n)
    {
        temp = deque(ls);
        if (i < n && arr[i] != -1)
        {
            temp->left = create(arr[i]);
        }
        else if (i < n && arr[i] == -1)
        {
            temp->left = NULL;
        }

        if (i + 1 < n && arr[i + 1] != -1)
        {
            temp->right = create(arr[i + 1]);
        }
        else if (i + 1 < n && arr[i + 1] == -1)
        {
            temp->right = NULL;
        }
        enque(ls, temp->left);
        enque(ls, temp->right);
        i += 2;
    }
    return root;
}
int main()
{
    tree *root;
    int arr[] = {1, 2, 3, -1, 5, 6, 7, 8, -1, 10};
    root = input_level(arr, 10);
    level_o_traversal(root, 10);
    printf("\n");
    travel(root);
    return 0;
}