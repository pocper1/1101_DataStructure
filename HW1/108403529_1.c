#include <stdio.h>
#include <stdlib.h>

int main()
{
  int row, col, tmp, total = 0,i=0;
  char test_arr[100][100];
  char line[10000];
  scanf("%d", &row);
  scanf("%d", &col);
  if (row > 100 | row<0 | col> 100 | col < 0)
  {
    printf("1Input matrix has wrong size. Please input again.\n");
  } else {
    
    char arr[row][col];
    char trans[col][row];

    // input martrix
    while (scanf("%s",test_arr[i]) != EOF) {
      getchar();
      i++;
    }
    for (int j = 0; j < 100; j++) {
      printf("%s ", test_arr[j]);
      
    }

    if (i != row * col) {
      printf("Input matrix has wrong size. Please input again.\n");
    } else {
      int count = 0;
      
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < col; j++) {

          arr[row][col] = test_arr[count][0];
          count++;
        }
      }
      
      printf("\n");
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < col; j++) {

          printf("%s ", arr[row][col]);
        }
        printf("\n");
      }

      // transpose a matrix
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < col; j++)
        {
          trans[j][i] = arr[i][j];
        }
      }
      // print normal martix
      printf("Sparse matrix by triplet form:\n");
      printf("%d %s %d %s %d %s", row, " ", col, " ", total, "\n");
      for (int i = 0; i < row; i++)
      {
        for (int j = 0; j < col; j++)
        {
          if (arr[i][j] != 0)
          {
            printf("%d %s %d %s %d %s", i, " ", j, " ", arr[i][j], "\n");
          }
        }
      }

      // print transpose matrix
      printf("Transpose of the sparse matrix:\n");
      printf("%d %s %d %s %d %s", row, " ", col, " ", total, "\n");
      for (int i = 0; i < col; i++)
      {
        for (int j = 0; j < row; j++)
        {
          if (trans[i][j] != 0)
          {
            printf("%d %s %d %s %d %s", i, " ", j, " ", trans[i][j], "\n");
          }
        }
      }
    }
    return 0;
  }
}