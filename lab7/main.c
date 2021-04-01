#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct person
{
	char *first;
	char *last;
	int date;
} PERSON;

PERSON **persons;
PERSON **sorted;
int stored = 0;

int main(int argc, char *argv[])
{
	system("chcp 1251"); // ��������� � �������
	system("cls"); // �������� �������, ����� ������ ������� "Active code page: 1251"
	
	int i, j, N;
	
	// ��� ���������� ���� �������� �������� �������������� ���
	// �����, ������� � ���� �������� ��������, �������� �� ����������
	// (��� ���������) �� ������ ���� �����
	char first[32];
	char last[32];
	int date;
	
	printf("������� ���������� �����, ������� �� ������ ��������: ");
	scanf("%i", &N);
	
	// ������� ������ ��� ���������� ������ �������� ���� PERSON
	persons = (PERSON**)malloc(N * sizeof(PERSON*));
	
	// ����� ��������� ��� ������������ �� �����, ����� �� �����������
	printf("������� <���> <�������> <��� ��������> ��� �������� c ID\n");
	
	// ���� ����������� �� ��� ���, ���� � �� ��������� ���������
	// � ���� ����� (���������� ����� � N)
	for(i = 0; i < N; i++)
	{
		// ������������ ����� �������� �������� � �������
		printf("%i: ", i);
		
		// ������ ���, ������� � ��� �������� � ������� � ���������� � �����
		scanf("%s%s%i", first, last, &date);
		
		// ������� ������ ��� ������� ������� ������� PERSON
		persons[i] = (PERSON*)malloc(sizeof(PERSON));
		
		// ������� ������ ��� ��� �������� ��������
		persons[stored]->first = (char*)malloc(strlen(first) * sizeof(char));
		
		// ������� ��� �� ������ � ��������������� ����� � ���������
		strcpy(persons[stored]->first, first);
		
		// ������� ������ ��� ������� �������� ��������
		persons[stored]->last = (char*)malloc(strlen(last) * sizeof(char));
		
		// ������� ������� �� ������ � ��������������� ����� � ���������
		strcpy(persons[stored]->last, last);
		
		// ��� int �� ��������� ����������� ����� � ������ �������� � 4 �����,
		// ���� � ������� ������ ��� �������� ������������� ����
		persons[stored]->date = date;
		
		// ����������� ������� ���������� � ������� ����� �� ��������
		stored++;
	}
	
	// ������� ������ persons � ������ sorted
	memcpy(&sorted, &persons, sizeof(persons));
	
	// ����������� ������ ������������� ������� persons, �� ��� ������ �� �����,
	// ��� ��� ��� ����� ������� � ������� sorted
	free(persons);
	for(i = 0; i < N; i++)
		free(persons[i]);

	// �������� ��������� ������ sorted �� ���� �������� (�� �������� � ��������)
	for(i = 0; i < N - 1; i++)
	{
		for(j = 0; j < N - 1 - i; j++)
		{
			// ���� ������� ������� "������" ���������� � ������ �������
			// ��������� ���� ��������
			if(sorted[j]->date < sorted[j + 1]->date)
			{
				// ������ ������� ����� ���� �������� ���������
				strcpy(first, sorted[j + 1]->first);
				strcpy(sorted[j + 1]->first, sorted[j]->first);
				strcpy(sorted[j]->first, first);
				
				// ������ ������� ������� ���� �������� ���������
				strcpy(last, sorted[j + 1]->last);
				strcpy(sorted[j + 1]->last, sorted[j]->last);
				strcpy(sorted[j]->last, last);
				
				// ������ ������� ���� �������� ���� �������� ���������
				date = sorted[j + 1]->date;
				sorted[j + 1]->date = sorted[j]->date;
				sorted[j]->date = date;
			}
		}
	}
	
	// ������ �� ������� ��������������� ������ ����� sorted
	printf("����� ��������������� ������ ����� (�� �������� � ��������): \n");
	for(i = 0; i < N; i++)
		printf("%i: %s %s %i\n", i, sorted[i]->first, sorted[i]->last, sorted[i]->date);

	// ����������� ������ ������������� ������� sorted, ������ � �� ��� ������ �� �����
	free(sorted);
	for(i = 0; i < N; i++)
		free(sorted[i]);
	
	return 0;
}
