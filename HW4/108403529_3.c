#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 101

typedef struct edge
{
    int source;
    int dest;
    int weight;
} edge;

typedef struct edgeList
{
    edge data[MAX];
    int count;
} edgeList;

int tmp[MAX][3], edges[MAX][MAX], total_edges, total_lines, parent[MAX];
edgeList t_list;
edgeList final_list;

void input();
void K_algo();
void print_result();
void sort_by_weight();
void update_parent(int parent[], int edge1, int edge2);
int main()
{
    input();
    return 0;
}

void input()
{
    //input data to tmp array
    scanf("%d", &total_edges);
    scanf("%d", &total_lines);
    for (int i = 0; i < total_lines; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &tmp[i][j]);
        }
    }

    // input data to edges array
    for (int i = 0; i < total_edges; i++)
    {
        edges[i][i] = 0;
        for (int j = 0; j < total_edges; j++)
        {
            for (int k = 0; k < total_lines; k++)
            {
                if (tmp[k][0] == i && tmp[k][1] == j)
                {
                    edges[i][j] = tmp[k][2];
                    edges[j][i] = tmp[k][2];
                }
            }
        }
    }

    // put data into t_list
    t_list.count = 0;
    for (int i = 0; i < total_lines; i++)
    {
        t_list.data[t_list.count].source = tmp[i][0];
        t_list.data[t_list.count].dest = tmp[i][1];
        t_list.data[t_list.count].weight = tmp[i][2];
        t_list.count++;
    }
    sort_by_weight(); // to choose the minimum edge of weight
    K_algo();         //implement the kurskal algorithm
    print_result();   //print the final result
}

void K_algo()
{
    // implement K_algo;
    int edge1, edge2;

    for (int i = 0; i < t_list.count; i++)
    {
        parent[i] = i;
    }

    final_list.count = 0;
    for (int i = 0; i < t_list.count; i++)
    {

        edge1 = parent[t_list.data[i].source];
        edge2 = parent[t_list.data[i].dest];
        // printf("i:%d edge1: %d edge2: %d\n",i,edge1,edge2);
        if (edge1 != edge2)
        {
            final_list.data[final_list.count] = t_list.data[i];
            final_list.count++;
            update_parent(parent, edge1, edge2);
        }
    }
}

void update_parent(int parent[], int e1, int e2) {
  printf("e1:%d e2:%d\n",e1,e2);
    for (int i = 0; i < t_list.count; i++)
    {
      if (parent[i] == e2)
        // printf("parent[%d]:%d\n",i,parent[i]);
            parent[i] = e1;
    }
}
void print_result()
{
    // print the total result
    int total_cost = 0;
    for (int i = 0; i < final_list.count; i++)
    {
        total_cost += final_list.data[i].weight;
    }

    if (final_list.count != total_edges - 1)
    {
        printf("> NO connected\n");
    }
    else
    {
        printf("> %d\n", total_cost);
    }

    for (int i = 0; i < total_edges; i++)
    {
        for (int j = 0; j < total_edges; j++)
        {
            if (j != total_edges - 1)
                printf("%d ", edges[i][j]);
            else
                printf("%d", edges[i][j]);
        }
        printf("\n");
    }
}

void sort_by_weight()
{
    edge tmp;
    for (int i = 1; i < t_list.count; i++)
    {
        for (int j = 0; j < t_list.count - 1; j++)
        {
            if (t_list.data[j].weight > t_list.data[j + 1].weight)
            {
                tmp = t_list.data[j];
                t_list.data[j] = t_list.data[j + 1];
                t_list.data[j + 1] = tmp;
            }
        }
    }
}
/*
STEPS
1. sort all edges in non-decending order of wt.
2.  i) pick the smallest edge
2.  ii) check if adding the edge comes cycle.
2.  iii)   if cycle is not formed->include edge
            else->exclude
3.  repeat setp-2 unless (v-1)  edges are included
*/

/*
3 3
0 1 3
0 2 3
1 2 4

> 6
0 3 3
3 0 4
3 4 0
*/

/*
5 4
0 1 7
0 2 6
1 2 8
3 4 5

> NO connected
0 7 6 0 0
7 0 8 0 0
6 8 0 0 0
0 0 0 0 5
0 0 0 5 0
*/