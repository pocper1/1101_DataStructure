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

void getInput();
void CreateNode(char character, int data);
void Huffman();
void output();

void sortOfFrequency(struct node a[], int array_size);
void sortOfAscii(struct node a[], int array_size);
void findNodes(struct node *ro, char target);

char input[100], result[100], codes[100];
int bucket[26] = {0}, tmp[100];
int mincost, h_ind = 0, level = 1, current = 1, code_i = 0, input_i = 0, tmp_i = 0,
             total_node = 0;
struct node *root;
char tmp_char[100];

char array0[2];
char array1[2];

int main()
{
    memset(tmp_char, '\0', sizeof(tmp_char));

    getInput();
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
    input_i = i;
    for (int i = 0; i < 26; i++)
    {
        if (bucket[i] > 0)
        {
            CreateNode((i + 'a'), bucket[i]);
            total_node++;
            // printf("which one:%c frequency: %d\n", i + 'a', bucket[i]);
        }
    }
    Huffman();
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

void Huffman()
{
    int total_node = h_ind, step = 0;
    root = (struct node *)malloc(sizeof(struct node));

    while (1)
    {
        // printf("===== step: %d =====\n", step + 1);
        // printf("h_inde: %d\n", h_ind);
        // for (int i = 0; i < h_ind; i++) {
        //   printf("begin Data[%d]: %c %d\n",i,huffman[i].character,huffman[i].data);
        // }
        sortOfFrequency(huffman, h_ind);
        // for (int i = 0; i < h_ind; i++) {
        //   printf("before Data[%d]: %c %d\n",i,huffman[i].character,huffman[i].data);
        // }
        sortOfAscii(huffman, h_ind);
        // for (int i = 0; i < h_ind; i++) {
        //   printf("after data[%d]: %c %d\n",i,huffman[i].character,huffman[i].data);
        // }
        struct node *parent = (struct node *)malloc(sizeof(struct node));

        parent->leftChild = &huffman[0];
        parent->rightChild = &huffman[1];

        parent->data = huffman[0].data + huffman[1].data;
        parent->character = '~';

        huffman[h_ind] = *parent;
        h_ind++;

        if (h_ind <= 3)
        {
            h_ind = 0;
            root = parent;
            break;
        }
        else
        {
            for (int i = 2; i < h_ind; i++)
                huffman[i - 2] = huffman[i];
            h_ind -= 2;
        }

        for (int i = 0; i < h_ind; i++)
        {
            printf("mdfk data[%d]: %c %d\n", i, huffman[i].character, huffman[i].data);
        }
        printf("huffman[0]->Data: %c %d\n", huffman[0].character, huffman[0].data);
        printf("huffman[1]->Data: %c %d\n", huffman[1].character, huffman[1].data);

        step++;
    }
    // printf("end of sort\n");
}

void output()
{
    for (int i = 0; i < input_i; i++)
    {
        printf("\nindex: %d want to find: %c \n", i, input[i]);
        findNodes(root, input[i]);
    }

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
// 第七個側資
// 左右順序要對
// 第八個側資
// 測資很長
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
// int find_flag = 0;

void findNodes(struct node *ro, char target)
{
    printf("in function want to find: %c\n", target);
    array0[1] = '\0';
    array1[1] = '\0';

    array0[0] = '0';
    array1[0] = '1';

    if (ro != NULL)
    {
        printf("character: %c target: %c\n", ro->character, target);
        if (ro->character == target)
        {

            printf("> %s\n", tmp_char);
        } 
         
        if (ro->leftChild != NULL)
        {
            printf("left\n");
            strcat(tmp_char, array0);
            findNodes(ro->leftChild, target);
            
            
        }

         if (ro->rightChild != NULL)
        {
            printf("right\n");
            strcat(tmp_char, array1);
            findNodes(ro->rightChild, target);
        }
        
    }
}