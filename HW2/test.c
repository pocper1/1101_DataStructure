#include <stdio.h>
#include <stdlib.h>

//must have 4 functions-> CreateNode,InsertNode,Traversing,Reverse

//design linked list node
typedef struct ListNode
{
    int data;   //the value the node stores (data)
    struct ListNode *next;  //the node the current node points to (address)   //how the nodes link
} *listPointer;

listPointer CreateNode(int value);
void InsertNode(int value, listPointer listPtr);
void Traversing(listPointer listPtr, listPointer first);
listPointer Reverse(listPointer lead);

int main() {
    listPointer iPtr;
    iPtr = malloc(sizeof(listPointer));

    int n, iCount=0;  //iCount計算node數量
    char iC;    //iC為'\n'或' '
    scanf("%d", &n);
    iPtr = CreateNode(n);
    iCount++;

    while(scanf("%d", &n) !=EOF)
    {
        InsertNode(n, iPtr);
        iCount++;
    }
    
    //find middle node
/*  listPointer fast = iPtr;
    listPointer slow = iPtr;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }   */

    listPointer middle = iPtr;
    for(int i=0; i<iCount/2; i++)
    {
        middle = middle->next;
    }

    Traversing(iPtr, middle);
    printf("\n");

    iPtr = Reverse(iPtr);
    Traversing(iPtr, iPtr);

    return 0;
}

listPointer CreateNode(int value)
{
    listPointer cNode;
    cNode = malloc(sizeof(listPointer));

    cNode->data = value;
    cNode->next = NULL;

    return cNode;
}

void InsertNode(int value, listPointer listPtr)
{
    while(listPtr->next != NULL)
    {
        listPtr = listPtr->next;
    }
    listPtr->next = CreateNode(value);
}

void Traversing(listPointer listPtr, listPointer first)
{
    printf(">");

    if(listPtr == NULL) //if linked list is empty
    {
        printf("List is empty!");
    }
    else
    {
        while(first != NULL)
        {
            printf(" %d", first->data);
            first = first->next;
        }

/*      for(; first; first = first->next)
        {
            printf(" %d", first->data);  //data of current node
        }   */
    }
}

listPointer Reverse(listPointer lead)
{
/*  listPointer prevNode, curNode;
    prevNode = malloc(sizeof(listPointer));
    curNode = malloc(sizeof(listPointer));

    prevNode = lead;
    curNode = lead->next;
    lead = lead->next;

    prevNode->next = NULL; // Make first node as last node

    while(lead != NULL)
    {
        lead = lead->next;
        curNode->next = prevNode;

        prevNode = curNode;
        curNode = lead;
    }

    lead = prevNode; // Make last node as head
*/
    listPointer prevNode = NULL, curNode = lead;
    while(lead != NULL)
    {
        lead = curNode->next;
        curNode->next = prevNode;

        prevNode = curNode;
        curNode = lead;
    }

    return prevNode;
}
