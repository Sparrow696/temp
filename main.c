#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	unsigned int size;
	printf("Write matrix size: ");
	scanf_s("%d", &size);
	double** matrix = malloc(size * sizeof(double*));
	if (!matrix)
	{
		return 0;
	}
	for (size_t i = 0; i < size; i++)
	{
		matrix[i] = malloc(size * sizeof(double));
		if (!matrix[i])
		{
			free(matrix);
			return 0;
		}
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			scanf_s("%lf", &matrix[i][j]);
		}
	}
	//inverseMatrix();
	return 0;