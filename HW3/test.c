#include "memory.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    char character;
    int data;
    char code[100];
    struct node *leftChild, *rightChild;
};

struct node huffman[100];
struct node *root;

void getInput();
void CreateNode(char character, int data);
void Huffman();
void output();

void sortOfFrequency(struct node a[], int array_size);
void sortOfAscii(struct node a[], int array_size);
void findNodes(struct node *ro, char target);

char input[100], result[100], tmp_char[100];
int bucket[26] = {0}, tmp[100];
int find_flag = 0, mincost = 0, h_ind = 0, code_i = 0, total_char = 0, tmp_i = 0,
    total_node = 0;

char array0[2];
char array1[2];

int main() {
    root = (struct node *)malloc(sizeof(struct node));
    getInput();
    Huffman();
    output();
    return 0;
}

void getInput()
{
    int i = 0;
    char tmp;

    while (1)
    {
        scanf("%c", &tmp);
        if (tmp == '\n')
            break;
        input[i++] = tmp;
        bucket[tmp - 'a'] = bucket[tmp - 'a'] + 1;
    }
    total_char = i;
    for (int i = 0; i < 26; i++)
    {
        if (bucket[i] > 0)
        {
            CreateNode((i + 'a'), bucket[i]);
            total_node++;
        }
    }
}

void CreateNode(char a, int data)
{
    struct node *tmpNode = (struct node *)malloc(sizeof(struct node));
    tmpNode->character = a;
    tmpNode->data = data;
    tmpNode->leftChild = NULL;
    tmpNode->rightChild = NULL;

    huffman[h_ind++] = *tmpNode;
}

void Huffman() {
    int step = 0;
  
    while (1) {
        printf("===== step: %d =====\n", step+1);
        printf("total_node: %d\n",total_node);
        sortOfFrequency(huffman, h_ind);
        sortOfAscii(huffman, h_ind);

        struct node *parent = (struct node *)malloc(sizeof(struct node));
        if (total_node >= 2) {
            parent->leftChild = &huffman[0];
            parent->rightChild = &huffman[1];
            parent->data = huffman[0].data + huffman[1].data;
            parent->character = '~';
            // printf("h_ind: %d\n",h_ind);
            huffman[h_ind] = *parent;
            h_ind++;
            
            // printf("h_ind: %d\n",h_ind);
            for (int i = 2; i < h_ind; i++)
                huffman[i - 2] = huffman[i];
            h_ind -= 2;
            if (h_ind <= 3)
            {
                h_ind = 0;
                root = parent;
                break;
            }
        } else if(total_node == 1){
            parent->leftChild = &huffman[0];
            parent->rightChild = NULL;
            parent->data = huffman[0].data;
            parent->character = huffman[0].character;
        }
        step++;
    }
}

void output()
{
    printf("> \n");
    printf("> %d\n", mincost);
}

void sortOfFrequency(struct node a[], int array_size)
{
    int i, j, temp_i;
    char temp_char;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j)
        {
            if (a[j].data > a[j + 1].data)
            {
                temp_i = a[j + 1].data;
                temp_char = a[j + 1].character;
                a[j + 1].data = a[j].data;
                a[j + 1].character = a[j].character;
                a[j].data = temp_i;
                a[j].character = temp_char;
            }
        }
    }
}
void sortOfAscii(struct node a[], int array_size)
{
    int i, j, temp_i;
    char temp_char;
    for (i = 0; i < (array_size - 1); ++i)
    {
        for (j = 0; j < array_size - 1 - i; ++j)
        {
            if (a[j].data == a[j + 1].data)
            {
                if (a[j].character >= a[j + 1].character)
                {
                    temp_i = a[j + 1].data;
                    temp_char = a[j + 1].character;
                    a[j + 1].data = a[j].data;
                    a[j + 1].character = a[j].character;
                    a[j].data = temp_i;
                    a[j].character = temp_char;
                }
            }
        }
    }
}
void findNodes(struct node *ro, char target)
{
    array0[0] = '0';
    array0[1] = '\0';

    array1[0] = '1';
    array1[1] = '\0';
    
    if (ro->character == target)
    {

        printf("> %s\n", tmp_char);
    }
    else
    {

        if (ro->leftChild)
        {
            // printf("left\n");
            strcat(tmp_char, array0);
            findNodes(ro->leftChild, target);
        }

        if (ro->rightChild)
        {
            // printf("right\n");
            strcat(tmp_char, array1);
            findNodes(ro->rightChild, target);
        }
    }
    
}
