#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main()
{
	system("chcp 1251"); // ��������� � �������
	system("cls"); // �������� �������, ����� ������ ������� "Active code page: 1251"
	
	int i, j, N;
	char mode; // ����� ������: "+", "-" ��� "*"
	double **matrix1, **matrix2, **result;
	
	printf("������� ����������� ��� ���� ���������� ������: ");
	scanf("%i", &N);
	
	// �������� ������ ��� �������, �������� ��������� �����������
	
	matrix1 = (double**)malloc(N * sizeof(double*));
	matrix2 = (double**)malloc(N * sizeof(double*));
	result = (double**)malloc(N * sizeof(double*));
	
	for(i = 0; i < N; i++)
	{
		matrix1[i] = (double*)malloc(N * sizeof(double));
		matrix2[i] = (double*)malloc(N * sizeof(double));
		result[i] = (double*)malloc(N * sizeof(double));
	}
	
	// ������ � ������� �������� ��������� ������
	
	printf("������� �������� ��������� ������ �������: ");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%lf", &matrix1[i][j]);
		}
	}
	printf("������� �������� ��������� ������ �������: ");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			scanf("%lf", &matrix2[i][j]);
		}
	}
	
	// ������������ �������� ������
	
	printf("\n������ �������: \n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%lf ", matrix1[i][j]);
		}
		puts("");
	}
	printf("\n������ �������: \n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%lf ", matrix2[i][j]);
		}
		puts("");
	}
	printf("\n");
	
	printf("������� ��������, ������� ���������� ���������� ��� ����� ��������� (\"+\", \"-\" ��� \"*\"): ");
	scanf(" %c", &mode);
	
	if(mode == '+')
	{
		result = sum(N, matrix1, matrix2);
	}
	else if(mode == '-')
	{
		result = difference(N, matrix1, matrix2);
	}
	else if(mode == '*')
	{
		result = multiplication(N, matrix1, matrix2);
	}
	
	printf("\n������������ �������:\n");
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < N; j++)
		{
			printf("%lf ", result[i][j]);
		}
		puts("");
	}
	
	return 0;
}
