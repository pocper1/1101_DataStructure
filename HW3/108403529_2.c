#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
};

struct node *root = NULL;

void getInput();
void Preorder(struct node *ptr);
void Postorder(struct node *ptr);
void output();
void CreateNode();

char input[100];
int pre[100], post[100];
int input_i = 0, preorder_i = 0, postorder_i = 0;

int main()
{
    getInput();

    output();
    return 0;
}

void CreateNode(int data)
{
    struct node *tmpNode = (struct node *)malloc(sizeof(struct node));
    struct node *current;
    struct node *parent;

    tmpNode->data = data;
    tmpNode->leftChild = NULL;
    tmpNode->rightChild = NULL;

    if (root == NULL)
    {
        root = tmpNode;
    }
    else
    {
        current = root;
        parent = NULL;

        while (1)
        {
            parent = current;
            if (data < parent->data)
            {
                current = current->leftChild;

                if (current == NULL)
                {
                    parent->leftChild = tmpNode;
                    return;
                }
            }
            else
            {
                current = current->rightChild;
                if (current == NULL)
                {
                    parent->rightChild = tmpNode;
                    return;
                }
            }
        }
    }
}

void getInput()
{
    int nums, tmp;
    scanf("%d", &nums);
    for (int i = 0; i < nums; i++)
    {
      scanf("%d", &tmp);
        CreateNode(tmp);
    }

    Preorder(root);
    Postorder(root);
}

void Preorder(struct node *ro)
{
    if (ro != NULL)
    {
        pre[preorder_i] = ro->data;
        preorder_i += 1;
        Preorder(ro->leftChild);
        Preorder(ro->rightChild);
    }
}

void Postorder(struct node *ro)
{
    if (ro != NULL)
    {
        Postorder(ro->leftChild);
        Postorder(ro->rightChild);
        post[postorder_i] = ro->data;
        postorder_i += 1;
    }
}
void output()
{
    printf("> Preorder:");
    for (int i = 0; i < preorder_i; i++)
    {
        printf(" %d", pre[i]);
    }
    printf("\n> Postorder:");
    for (int j = 0; j < postorder_i; j++)
    {
        printf(" %d", post[j]);
    }
}