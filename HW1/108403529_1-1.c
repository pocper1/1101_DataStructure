#include <stdio.h>
#include <stdlib.h>
#define len 100
int main()
{
	int row = 0, col = 0, total = 0;

	scanf("%d %d", &row, &col);

	if ((row > len && row < 0) || (col > len && col < 0))
	{
		printf("Input matrix has wrong size. Please input again.\n");
		exit(0);
	}

	int arr[row][col];
	int trans[col][row];
	int input[len * len];
	int count = 0, count_input = 0, tmp_row = 0, tmp_col = 0, row_num = 0;
	int check = 1;
	char tm;

	for (int i = 0; i < len * len; i++)
	{
		input[i] = 0;
	}
	while (scanf("%d%c", &input[count], &tm) != EOF)
	{
		if (tm == '\n')
		{
			if (tmp_col + 1 != col)
			{
				check = 0;
			}
			tmp_row++;
			tmp_col = 0;
			row_num++;
		}
		else
		{
			tmp_col++;
		}
		count++;
	}
	if (row_num + 1 != row)
	{
		check = 0;
	}
	if (scanf("%d%c", &input[count], &tm) == EOF && check == 0)
	{

		printf("Input matrix has wrong size. Please input again.\n");
		exit(0);
	}
	else
	{

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				arr[i][j] = input[count_input];

				if (input[count_input] != 0)
				{
					total++;
				}
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
		printf("%d%s%d%s%d %s", row, " ", col, " ", total, "\n");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (arr[i][j] != 0)
				{
					printf("%d%s%d%s%d%s", i, " ", j, " ", arr[i][j], "\n");
				}
			}
		}
		// print transpose matrix
		printf("Transpose of the sparse matrix:\n");
		printf("%d %d %d %s", row, col, total, "\n");
		for (int i = 0; i < col; i++)
		{
			for (int j = 0; j < row; j++)
			{
				if (trans[i][j] != 0)
				{
					printf("%d%s%d%s%d%s", i, " ", j, " ", trans[i][j], "\n");
				}
			}
		}
	}
	return 0;
}

/*

15 0 0 22 0
0 0 3 0 0
0 0 0 -6 0
0 0 0 0 7
91 0 0 0 0

15 0 0 22 0 -15 100
0 11 3 0 0 0
0 0 0 -6 0 0
0 0 0 0 0 0
91 0 0 0 0 0
0 0 28 0 0 0
1 0 0 0 0 0
*/