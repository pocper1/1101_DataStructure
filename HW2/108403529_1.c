#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct listNode
{
  int data;
  struct listNode *next;
};
typedef struct listNode Node;
Node *CreateNode();
Node *InsertNode(int *, int);
void Traversing(Node *, int);
void Reverse(Node *);

int main()
{
  Node *first = NULL; // create linked list
  int arr[100] = {0};
  int size = 0, target;

  while (scanf("%d", &arr[size]) != EOF)
  {
    size++;
  }

  first = InsertNode(arr, size);
  target = round(size/2+0.5);

  Traversing(first, target);

  // reverse the linked list
  Reverse(first);
  
  return 0;
}

Node *CreateNode() {
  Node *ptr = NULL;
  ptr = (Node *)malloc(sizeof(Node));
  return ptr;
}

Node *InsertNode(int *arr, int len)
{
 
  Node *first, *current, *previous;
  for (int i = 0; i < len; i++)
  {
    current = CreateNode();
    current->data = arr[i];
    if (i == 0)
    {
      first = current;
    }
    else
    {
      previous->next = current;
    }
    current->next = NULL;
    previous = current;
  }
  return first;
}

void Traversing(Node *arr,int target)
{
  Node *node = arr;
  int count = 0;

  if (arr == NULL)
  {
    printf("List of Node is empty\n");
  } else {
    printf(">");
    while (node != NULL) {
      if (count < target-1) {
        node = node->next;
        count++;
      } else {
        printf(" %d", node->data);
        node = node->next;
        count++;
      }
    }
    printf("\n");
  }
}

void Reverse(Node *arr)
{
  Node *previous=0, *current=arr, *preceding=arr->next, *first;
  
  if (arr == NULL)
    printf("List of Node is empty\n");

  while (preceding != 0) {
    current->next = previous; // current node->next 轉向前面
    previous = current;       // previous 往後移
    current = preceding;
    preceding = preceding->next;
  }
  current->next = previous;
  first = current;
  printf(">");

  while (first != NULL)
  {
    printf(" %d", first->data);
    first = first->next;
  }
  printf("\n");
}