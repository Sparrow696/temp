#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

int createIdentity(double** matrix_, int size_)
{
	double** identityMatrix = malloc(size_ * sizeof(double*));
	if (!identityMatrix)
	{
		free(identityMatrix);
		return 0;
	}
	for (size_t i = 0; i < size_; i++)
	{
		identityMatrix[i] = malloc(size_ * sizeof(double));
		if (!identityMatrix[i])
		{
			return 0;
		}
	}
	char k;
	for (int i = 0; i < size_; i++)
	{
		for (int j = 0; j < size_; j++)
		{
			scanf_s("%lf", &matrix_[i][j]);
			if (i == j)
			{
				identityMatrix[i][j] = 1;
			}
			else
			{
				identityMatrix[i][j] = 0;
			}
		}
	}
}

int inverseMatrix(double** matrix_, double** identity_, int size_)
{
	int k, j, i;
	for (k = 0; k < size_; k++)
	{
		double scalar = matrix_[k][k];
		for (j = 0; j < size_; j++)
		{
			matrix_[k][j] /= scalar;
			identity_[k][j] /= scalar;
		}
		for (i = 0; i < size_; i++)
		{
			if (i != k) {
				double temp = matrix_[i][k];
				for (j = 0; j < size_; j++)
				{
					matrix_[i][j] -= temp * matrix_[k][j];
					identity_[i][j] -= temp * identity_[k][j];
				}
			}
		}
	}
	return 0;
}
void printMatrix(double** matrix_, int size_)
{
	for (int i = 0; i < size_; i++)
	{
		printf("\n");
		for (int j = 0; j < size_; j++)
		{
			printf("%lf ", matrix_[i][j]);
		}
	}
}