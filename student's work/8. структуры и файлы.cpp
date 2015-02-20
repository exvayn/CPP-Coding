/*
2.	Сведения об экзамене содержат следующие данные: 
дисциплину (программирование, алгебра, история, геометрия), 
дату сдачи экзамена (год, месяц, день), 
сведения о студенте (факультет, курс, группа, номер в журнале) 
и экзаменационную оценку. 

Задан набор сведений об экзаменах, сданных студентами за последние два года; 
в них факультет и предмет кодируются первыми буквами названия. 
Определить количество неуспевающих по программированию на экономическом  
факультете среди студентов первого курса, сдававших экзамены зимой 2012 года, 
вывести на экран их группу и номер в журнале.

Факультеты:
Экономический
Машиносторительный
Юридический
Технический
Пищевой

*/
#include <stdio.h>
//#include <locale.h>
#include <windows.h>
#include <iostream>

	FILE *f;
	struct data {
		int d; //день
		int m; //месяц
		int y; //год
	};
	struct student {
		char fac; //факультет (1 символ)
		int kurs; //курс
		int group; //группа
		int num; //номер в журнале
	};

	struct exam {
		char disc; //дисциплина (1 символ)
		struct data date; //дата (из записиси дата)
		struct student stud; //студент (из записи студент)
		int rating; //оценка
	};
	struct exam record[1000];

// функции
int menu(void);
int qqq(void); //read
int www(void); //add
int eee(void); //new
int rrr(void); //info
int lobby(void);

int buf=0;

void main(void)
{
	//setlocale(0,"RUS");
	SetConsoleCP(1251);// включаем нужные кодировки для потока ввода
	SetConsoleOutputCP(1251); // включаем нужные кодировки для потока вывода
	menu();
}
int menu()
{
	char ch;
	system("cls");
	printf("     <<Меню>>\n"); 
	printf("Просмотр данных - 'q'\n");
	printf("Дополнить данные - 'w' ( Создать новые - 'e' )\n");
	printf("Дополнительные сведения - 'r'\n");
	printf("Выйти - 'x'\n\n");
	printf("Ввод: ");
	if (buf) getchar();
	scanf ( "%c", &ch );
	buf=1;
	if (ch=='q') {  qqq(); return 0;} //просмотр
	if (ch=='w') {  www(); return 0;} //дополнение
	if (ch=='e') {  eee(); return 0;} //новый
	if (ch=='r') {  rrr(); return 0;} //доп свед (по заданию)
	if (ch=='x') { printf("\n"); system("pause"); return 0;} 
	return 0;
}
int lobby()
{
	char ch;
	printf("\n\nВ меню - 'm' | Выйти - 'x'\n\n"); 
	printf("Ввод: ");
	getchar();
	scanf ( "%c", &ch );
	if (ch=='x') {  printf("\n"); system("pause"); return (0);} //выйти
	if (ch=='m') {  system("pause"); menu();  return (0);} //в меню
	return 0;
}
int eee()
{
	int i,j,k,k1,kv;
	if((f=fopen("exvayn.kun", "w"))==NULL) 
	{
		printf("Ошибка при открытии файла.\n");
		lobby();
		return 0;
	}
	
	printf ("Ввод сведений об резальтатах экзаменов:\n");
	printf ("Введите количество вводимых сведений: ");
	scanf("%d",&kv);
	printf ("\n\n");
	for (i=0;i<kv;i++) 
	{	
		printf ("\nСведения номер %d:\n", i+1);
			printf ("   Дисциплина (П,А,И,Г): ");
			getchar();
			scanf ("%c",&record[i].disc);
			printf ("   Дата (dd.mm.yyyy): ");
			scanf ( "%d.%d.%d", &record[i].date.d, &record[i].date.m, &record[i].date.y );
			printf ("   Информация о студенте:\n");
				printf ("      Факультет (Э,М,Ю,Т,П): ");
				getchar();
				scanf ( "%c", &record[i].stud.fac );
				printf ("      Курс (1-5): ");
				scanf ( "%d", &record[i].stud.kurs );
				printf ("      Группа: ");
				scanf ( "%d", &record[i].stud.group );
				printf ("      Номер в журнале: ");
				scanf ( "%d", &record[i].stud.num );
			printf ("   Оценка: ");
			scanf ( "%d", &record[i].rating );
	}

	for(i=0; i<kv; i++)
		if(record[i].disc)
			if(fwrite(&record[i],sizeof(struct exam), 1, f)!=1)  
				printf("Ошибка при записи файла.\n");
	fclose(f);
	printf("Данные введены и сохранены в файл.\n");
	lobby();
	return 0;
}
int qqq(){
	int i,j,kv=-1;
	if((f=fopen("exvayn.kun", "r"))==NULL) 
	{
		printf("Ошибка при открытии файла.\n");
		lobby();
		return 0;
	}
	while(true)
		if(fread(&record[++kv],sizeof(struct exam), 1, f)!=1) 
		{
			if (feof(f)) break;
			printf("Ошибка при чтении файла.\n");
			fclose(f);
			lobby();
			return 0;
		}
    printf ("\n\nСведения об экзаменах:\n");
    for (i=0;i<kv;i++) 
	{

		printf ("\nСведения под номером %d:\n", i+1);
		switch (record[i].disc)
		{
			case 'П': printf ("   Дисциплина: Программирование\n");break;
			case 'А': printf ("   Дисциплина: Алгебра\n");break;
			case 'И': printf ("   Дисциплина: История\n");break;
			case 'Г': printf ("   Дисциплина: Геометрия\n");break;
		}
		printf ("   Дата рождения: %d.%d.%d \n", record[i].date.d, record[i].date.m, record[i].date.y);
		printf ("   Студент:\n");
			switch (record[i].stud.fac)
			{
				case 'Э': printf ("   Факультет: Экономический\n");break;
				case 'М': printf ("   Факультет: Машиносторительный\n");break;
				case 'Ю': printf ("   Факультет: Юридический\n");break;
				case 'Т': printf ("   Факультет: Технический\n");break;
				case 'П': printf ("   Факультет: Пищевой\n");break;
			}
			printf ("      Курс: %d\n", record[i].stud.kurs);
			printf ("      Группа: %d\n", record[i].stud.group);
			printf ("      Номер в журнале: %d\n", record[i].stud.num);
		printf ("   Оценка: %d\n", record[i].rating);
    } 
printf ("\n  Конец файла.  \n");
fclose(f);
system("pause");
lobby();
return 0;
}
int rrr(){
	int i,j,kv=-1,k=0;
	if((f=fopen("exvayn.kun", "r"))==NULL) 
	{
		printf("Ошибка при открытии файла.\n");
		lobby();
		return 0;
	}
	while(true)
		if(fread(&record[++kv],sizeof(struct exam), 1, f)!=1) 
		{
			if (feof(f)) break;
			printf("Ошибка при чтении файла.\n");
			fclose(f);
			lobby();
			return 0;
		}
	printf("\n\nДополнительные сведения:\n\n");
	printf("    Количество неуспевающих по программированию на \n");
	printf("    экономическом факультете среди студентов первого курса,\n");
	printf("    сдававших экзамены зимой 2012 года,\n");
	printf("    вывести на экран их группу и номер в журнале.\n\n");
	for (i=0;i<kv;i++){
		if (record[i].disc=='П' && record[i].rating<3 && record[i].stud.fac=='Э' && record[i].stud.kurs==1 && record[i].date.y==2012 && (record[i].date.m>11 || record[i].date.m<3)){
			printf("%d)Группа: %d\n",++k,record[i].stud.group);
			printf("    Номер в журнале: %d\n\n",record[i].stud.num);
		}	
	}
	printf(" Количество неуспевающих учеников: %d\n\n",k);
	fclose(f);
	system("pause");
	lobby(); 
	return (0);
}
int www(){
	int i,j,k,k1,kv;
	if((f=fopen("exvayn.kun", "a"))==NULL) 
	{
		printf("Ошибка при открытии файла.\n");
		lobby();
		return 0;
	}
	fseek(f, 0, 2);
	printf ("Добавление сведений об резальтатах экзаменов:\n");
	printf ("Введите количество вводимых сведений: ");
	scanf("%d",&kv);
	printf ("\n\n");
	for (i=0;i<kv;i++) 
	{	
		printf ("\nСведения номер %d:\n", i+1);
			printf ("   Дисциплина (П,А,И,Г): ");
			getchar();
			scanf ("%c",&record[i].disc);
			printf ("   Дата (dd.mm.yyyy): ");
			scanf ( "%d.%d.%d", &record[i].date.d, &record[i].date.m, &record[i].date.y );
			printf ("   Информация о студенте:\n");
				printf ("      Факультет (Э,М,Ю,Т,П): ");
				getchar();
				scanf ( "%c", &record[i].stud.fac );
				printf ("      Курс (1-5): ");
				scanf ( "%d", &record[i].stud.kurs );
				printf ("      Группа: ");
				scanf ( "%d", &record[i].stud.group );
				printf ("      Номер в журнале: ");
				scanf ( "%d", &record[i].stud.num );
			printf ("   Оценка: ");
			scanf ( "%d", &record[i].rating );
	}

	for(i=0; i<kv; i++)
		if(record[i].disc)
			if(fwrite(&record[i],sizeof(struct exam), 1, f)!=1)  
				printf("Ошибка при записи файла.\n");
	fclose(f);
	printf("Данные введены и сохранены в файл.\n");
	lobby();
	return 0;
}
