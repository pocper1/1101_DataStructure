#include <stdio.h>
#include <stdlib.h>
#define len 100
int main()
{
    int row = 0, col = 0, total = 0;

    scanf("%d %d", &row, &col);
    //如果輸入col or row 有問題
    if (row > len || row <= 0 || col > len || col <= 0)
    {
        printf("Input matrix has wrong size. Please input again.\n");
        exit(0);
        return 0;
    }

    int arr[row][col];
    int trans[col][row];
    int input[len * len];
    int count = 0, count_input = 0, flag = 1, tmp_row = 0, tmp_col = 0, row_num = 0;
    char im;
    // init input
    for (int i = 0; i < len * len; i++)
    {
        input[i] = 0;
    }
    // scnaf util EOF
    while (scanf("%d%c", &input[count], &im) != EOF)
    {
        if (im == '\n')
        {
            if (tmp_col + 1 != col) //如果有一行的col != 前面輸的col
                flag = 0;

            tmp_row++;
            tmp_col = 0;
            row_num++;
        }
        else
            tmp_col++;
        count++;
    }
    // if row * col != count->it means error input
    if (row_num + 1 != row)
        flag = 0;

    if (scanf("%d%c", &input[count], &im) == EOF && flag == 0)
    {

        printf("Input matrix has wrong size. Please input again.\n");
        exit(0);
        return 0;
    }

    // let input array put into arr array
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            arr[i][j] = input[count_input];
            // when numbers != 0->total += 1
            if (input[count_input] != 0)
                total++;

            count_input++;
        }
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
    printf("%d %d %d\n", row, col, total);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (arr[i][j] != 0)
                printf("%d %d %d\n", i, j, arr[i][j]);
        }
    }

    // print transpose matrix
    printf("Transpose of the sparse matrix:\n");
    printf("%d %d %d\n", col, row, total);
    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (trans[i][j] != 0)
                printf("%d %d %d\n", i, j, trans[i][j]);
        }
    }
    return 0;
}
