#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct person
{
	char *first;
	char *last;
	int year;
	int sex;
	double height;
} PERSON;

PERSON **persons;
PERSON *buffer;
int lines = 0;

// ������ ������� ��� �������� ������� �������� ���� PERSON
void swap(j)
{
	buffer = persons[j];
	persons[j] = persons[j + 1]; 
	persons[j + 1] = buffer;
}

void by_first()
{
	int i, j;
	for(i = 0; i < lines - 1; i++)
		for(j = 0; j < lines - i - 1; j++)
			if(strcmp(persons[j]->first, persons[j + 1]->first) == 1)
				swap(j);
}

void by_last()
{
	int i, j;
	for(i = 0; i < lines - 1; i++)
		for(j = 0; j < lines - i - 1; j++)
			if(strcmp(persons[j]->last, persons[j + 1]->last) == 1)
				swap(j);
}

void by_year()
{
	int i, j;
	for(i = 0; i < lines - 1; i++)
		for(j = 0; j < lines - i - 1; j++)
			if(persons[j]->year > persons[j + 1]->year)
				swap(j);
}

void by_sex()
{
	int i, j;
	for(i = 0; i < lines - 1; i++)
		for(j = 0; j < lines - i - 1; j++)
			if(persons[j]->sex > persons[j + 1]->sex)
				swap(j);
}

void by_height()
{
	int i, j;
	for(i = 0; i < lines - 1; i++)
		for(j = 0; j < lines - i - 1; j++)
			if(persons[j]->height > persons[j + 1]->height)
				swap(j);
}

int main(int argc, char **argv)
{
	
	system("chcp 1251"); // ��������� � �������
	system("cls"); // �������� �������, ����� ������ ������� "Active code page: 1251"
	
	FILE *in, *out;
	
	char query[6];
	
	int i;
	
	char first[32];   //
	char last[32];    //
	int year;         // �����
	int sex;          //
	double height;    //
	
	out = fopen("output.txt", "w");
	while(--argc)
	{
		in = fopen(argv[argc], "r");
		if(in == NULL)
		{
			printf("�� ������� ��������� ����: %s\n", argv[argc]);
			exit(0);
		}
		
		printf("�������������� ����: %s\n", argv[argc]);
		while(fscanf(in, "%*[^\n]%*c") != EOF)
			lines++;
			
		// ��������� � ��������� ���� ������, ����� ����������� �������� ���������
		// �� ������ �����. ������ fscanf(in, "%*[^\n]%*c") ������� ��� � ����� �����
		fclose(in);
		in = fopen(argv[argc], "r");		
		
		persons = (PERSON**)malloc(lines * sizeof(PERSON*));
		for(i = 0; i < lines; i++)
		{
			persons[i] = (PERSON*)malloc(sizeof(PERSON));
			
			fscanf(in, "%s%s%i%i%lf", first, last, &year, &sex, &height);
			
			persons[i]->first = (char*)malloc(strlen(first) * sizeof(char));
			strcpy(persons[i]->first, first);
			
			persons[i]->last = (char*)malloc(strlen(last) * sizeof(char));
			strcpy(persons[i]->last, last);
			
			persons[i]->year = year;
			persons[i]->sex = sex;
			persons[i]->height = height;
		}
		
		// ����� ��������� ����������
		printf("������� �������� ���������� ��� ��������\n<�> �� �����\n<�> �� �������\n<�> �� ���� ��������\n<�> �� ����\n<�> �� �����:\n > ");
		scanf("%s", query);
		for(i = 0; i < strlen(query); i++)
		{
			switch(query[i])
			{
				case '�': printf("���������� �� �����\n"); by_first(); break;
				case '�': printf("���������� �� �������\n"); by_last(); break;
				case '�': printf("���������� �� ���� ��������\n"); by_year(); break;
				case '�': printf("���������� �� ����\n"); by_sex(); break;
				case '�': printf("���������� �� �����\n"); by_height(); break;
			}
		}
		
		// ���������� ������� � ����
		for(i = 0; i < lines; i++)
			fprintf(out, "%s %s %i %i %lf\n", persons[i]->first, persons[i]->last, persons[i]->year, persons[i]->sex, persons[i]->height);
	}
	getch();
	return 0;
}
