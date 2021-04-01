#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	system("chcp 1251"); // Кириллица в консоли
	system("cls"); // Очистить консоль, чтобы убрать надпись "Active code page: 1251"
	
	FILE *in, *out; // Указатели на будущие файлы ввода и вывода
	char first[32], last[32]; // Имя и фамилия, которые будут прочитаны из файла
	int query; int date; // Дата, введёная с консоли, и дата, которая будет прочитана из файла
	
	printf("Людей, родившихся позднее какого года Вы хотите найти? ");
	scanf("%i", &query);
	
	// Открываем файл вывода на "запись с удалением старого содержимого"
	out = fopen("output.txt", "w")
	
	// Переоткрываем файл вывода на "добавление в конце" с помощью freopen (файл будет автоматически
	// закрыт и открыт заново с новым режимом)
	out = freopen("output.txt", "a");
	
	// Пока не закончатся переданные в main() файлы
	while(--argc)
	{
		// Открываем очередной файл на чтение
		in = fopen(argv[argc], "r");
		
		// Проверяем, удалось ли (не вернулось ли NULL)
		if(in == NULL)
		{
			printf("Не удалось прочитать файл: %s\n", argv[argc]);
			exit(0);
		}
		
		// Успех! Сообщаем о нём
		printf("Обрабатывается файл: %s\n", argv[argc]);
		
		// Читаем и сохраняем по два слова и одному числу за раз (то есть по одной строке), 
		// пока они не закончатся в этом файле (пока fscanf не вернёт EOF)
		while(fscanf(in, "%s%s%i", first, last, &date) != EOF)
		{
			// Сравнием дату, введёную с консоли, с датой, которую мы только что прочитали
			if(date > query)
			{
				// То что нужно! Сохраняем строчку в файл
				fprintf(out, "%s %s %i\n", first, last, date);
			}
		}
		
		// Больше строчек нет, закрываем этот файл
		fclose(in);
	}
	
	// Больше файлов нет, закрываем файл вывода
	fclose(out);
	
	return 0;
}
