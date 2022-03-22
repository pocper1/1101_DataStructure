#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int length;
void input();
void primMST(int graph[length][length]);
int selectMinVertex(int key[], bool setMST[]);

int main()
{
    input();
    return 0;
}

void input()
{
    scanf("%d", &length);
    // printf("length: %d\n", length);
    int graph[length][length];
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    primMST(graph);
}

void primMST(int graph[length][length])
{
    int parent[length]; //存parent node
    int key[length];
    bool setMST[length];
    int total_cost = 0;
    bool checkConntected = false;
    int counter = 0;
    for (int i = 0; i < length; i++)
    {
        key[i] = INT_MAX; //設為無限大
        setMST[i] = false;
    }

    for (int i = 0; i < length; i++)
    {
        parent[i] = -2;// let all parent set -2 to check is all the node is connected
    }

    key[0] = 0;     //make key 0 for the source vertex
    parent[0] = -1; // first node is the root of MST

    for (int count = 0; count < length - 1; count++)
    {
        int u = selectMinVertex(key, setMST);
        setMST[u] = true;

        for (int vi = 0; vi < length; vi++)
        {
            if (graph[u][vi] && setMST[vi] == false && graph[u][vi] < key[vi])
            {
                parent[vi] = u;
                key[vi] = graph[u][vi];
            }
        }
    }
    // printf("result\n");
    for (int i = 0; i < length; i++)
    {
        if (parent[i] == -2)
        {
            checkConntected = true;
        }
    }
    if (checkConntected == false)
    {
        for (int i = 1; i < length; i++)
        {
            total_cost += graph[i][parent[i]];
        }
        printf("> %d\n", total_cost);
    } else {
      printf("> NO connected\n");
    }
}

int selectMinVertex(int key[], bool setMST[])
{
    int min = INT_MAX, min_index;
    for (int vertex = 0; vertex < length; vertex++)
    {
        if (setMST[vertex] == false && key[vertex] < min)
        {
            min = key[vertex];
            min_index = vertex;
        }
    }
    return min_index;
}

/*
STEPS
begin. all node weights are infinite except source
begin-1 .select source first

while(){
    1. select node with min-weight(start at source)     ->use key(int)
    2. include selected node in setmst                  ->use setMST array(bool)
    3. relax/compute all adjacent edges                 ->use parent array(int)
}
*/

/*
1) create a set mstSET
mstSET = {}
Source: 0
vertex  0       1       2       3       4       5       6       7       8
key     0       inf     inf     inf     inf     inf     inf     inf     inf

2) Assign a key value to all vertices in the input graph.

3)
while mstSET doesn't include all vertices{
    a)pick a vertex u which is not there in mstSET and has minimum key value
    b) include u to mstSET
    c) update key value of all adjacent vertices of u
    //一開始0 是最小的所以被選上為u
    //selectMST->選擇臨近的點

    //選擇不在mstSET裡面的點且最小的
}
while(){
    1. select node with min-weight(start at source)     ->use key(int)
    2. include selected node in setmst                  ->use setMST array(bool)
    3. relax/compute all adjacent edges                 ->use parent array(int)
}
*/

/*
4
0 4 9 21
4 0 8 17
9 8 0 16
21 17 16 0

> 28
*/
/*
4
0 5 0 0
5 0 6 0
0 6 0 0
0 0 0 0

> NO connected
*/