#include <stdlib.h>

double **sum(int N, double **matrix1, double **matrix2)
{
	int i, j;
	
	// �������� ������ ��� ��������� ������� ��� �������� ������
	
	double **result = (double**)malloc(N * sizeof(double*));
	for(i = 0; i < N; i++)
		result[i] = (double*)malloc(N * sizeof(double));
		
	// ������� ����� ��������� ���� ������ � ���������� ����������
	// �� ��������� �������
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	
	return result;
}

double **difference(int N, double **matrix1, double **matrix2)
{
	int i, j;
	
	// �������� ������ ��� ��������� ������� ��� �������� ������
	
	double **result = (double**)malloc(N * sizeof(double*));
	for(i = 0; i < N; i++)
		result[i] = (double*)malloc(N * sizeof(double));
		
	// ������� �������� ��������� ���� ������ � ���������� ����������
	// �� ��������� �������
	
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			result[i][j] = matrix1[i][j] - matrix2[i][j];
		}
	}
	
	return result;
}

double **multiplication(int N, double **matrix1, double **matrix2)
{
	int i, j, k;
	
	// �������� ������ ��� ��������� ������� ��� �������� ������
	
	double **result = (double**)malloc(N * sizeof(double*));
	for(i = 0; i < N; i++)
		result[i] = (double*)malloc(N * sizeof(double));
		
	// ������� ������������ ��������� ���� ������ � ���������� ����������
	// �� ��������� �������
	
	for(i = 0; i < N; i++)
	    for(j = 0; j < N; j++)
	    {
	        result[i][j] = 0;
	        for(k = 0; k < N; k++)
	            result[i][j] += matrix1[i][k] * matrix2[k][j];
    }
	
	return result;
}
