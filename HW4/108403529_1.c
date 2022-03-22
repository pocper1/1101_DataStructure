#include <stdio.h>
#include <stdlib.h>

void hasVisited(char **grid, int i, int j, int gridSize, int *gridColSize);
int numbersOfIsland(char **grid, int gridSize, int *gridColSize);

int main()
{
    int arr_size1 = 0, arr_size2 = 0, result;

    scanf("%d %d", &arr_size1, &arr_size2);

    char arr[arr_size1][arr_size2];
    int gridSize[arr_size1];

    int tmp=0;
    char **ptr_arr = (char **)malloc(arr_size1 * sizeof(char *));
    char *row = (char *)malloc(arr_size1 * sizeof(char));
    for (int i = 0; i < arr_size1; i++)
    {
        for (int j = 0; j < arr_size2; j++)
        {
          scanf("%d", &tmp);
          arr[i][j] = tmp + '0';
        //   printf("test: %c %d\n",arr[i][j], tmp);
        }
        // *row = arr[i];
    }
    for (int i = 0; i < arr_size1; i++) {
      row = arr[i];
    //   printf("row: %s\n", row);
      ptr_arr[i] = row;
      gridSize[i] = arr_size2;
    }

    result = numbersOfIsland(ptr_arr, arr_size1, gridSize);
    printf("> %d\n", result);
    return 0;
}
void hasVisited(char **grid, int i, int j, int gridSize, int *gridColSize)
{
    if (i < 0 || j < 0 || i >= gridSize)
    {
        //當i 或者j 小於邊界，或者i 大於邊界
        return;
    }
    if (j >= gridColSize[i])
    {
        // 當j > 邊界
        return;
    }
    if (grid[i][j] == '0')
    {
        // 如果遇到0(water)或者訪問過的land
        return;
    }
    grid[i][j] = '0'; //將訪問過的地方設為0

    //              (i,j-1)
    //                 |
    //  (i-1,j)<-   (i  ,j)   ->(i+1,j)
    //                 |
    //              (i,j+1)
    hasVisited(grid, i - 1, j, gridSize, gridColSize);
    hasVisited(grid, i + 1, j, gridSize, gridColSize);
    hasVisited(grid, i, j - 1, gridSize, gridColSize);
    hasVisited(grid, i, j + 1, gridSize, gridColSize);
}

int numbersOfIsland(char **grid, int gridSize, int *gridColSize)
{
    int i, j;
    int res = 0;

    for (i = 0; i < gridSize; i++) // 尋找初始2D array 之row
    {
        for (j = 0; j < gridColSize[i]; j++) // 尋找初始2D array col
        {
            if (grid[i][j] == '1') // 如果是1 就代表land
            {
                hasVisited(grid, i, j, gridSize, gridColSize); // 向上 向下 向左 向右 確認還有沒有陸地
                res++;
            }
        }
    }
    return res;
}