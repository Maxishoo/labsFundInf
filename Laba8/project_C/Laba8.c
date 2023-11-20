#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}
void print_matrix(int matrix[8][8], int n)
{
	printf("\nResult:\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%d\t", matrix[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	const int n;
	scanf("%d", &n);
	int matrix[8][8];
	int max_on_line;
	int smesh = 0;
	for (int i = 0; i < n; i++)
	{
		max_on_line = -1e9+7;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &matrix[i][j]);
			max_on_line = max(max_on_line, matrix[i][j]);
		}
		matrix[i][smesh] = max_on_line;
		smesh++;
	}
	print_matrix(matrix, n);
}