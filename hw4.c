

#include "pch.h"
#include "train.h"
#include "workers.h"

int main(int argc, char *argv[])
{
	int a;
	scanf_s("%d", &a);
	char b;
	scanf_s("%c", &b);
	unsigned int timestamp;
	scanf_s("%d", &timestamp);

	doShit(argv[1], a, b, timestamp);

	return 0;
}


// train.h

#ifndef train_h
#define train_h

#include <stdio.h>

struct time
{
	int hours;
	int minutes;
};

struct train 
{
	int nomber;
	struct time artime;
	struct time deptime;
	char station[30];


};

#endif



//  workers.h

#ifndef workers_h
#define workers_h
#define l 100
#include <stdio.h>
struct pt
{
	char name[l];
	char surname[l];
	char middlename[l];
	char job[l];
	unsigned int timestamp;
	int money;


};
void doShit(char filename[200], int a, char b, int timestamp);

#endif /* workers_h */



//  workers.cpp

#include "workers.h"
#include <stdlib.h>

void doShit(char filename[200], int a, char b, int timestamp)
{

	char tmp[12];
	FILE * fp, *fp1, *fp2, *fp3;
	char str[999];
	struct pt ptr[3];
	if ((fp = fopen(filename, "rb")) == NULL)
	{
		perror("невозможно открыть файл");
		exit(1);
	}
	if ((fp1 = fopen("text1.txt", "w")) == NULL)
	{
		perror("невозможно открыть файл");
		exit(1);
	}
	if ((fp2 = fopen("text2.txt", "w")) == NULL)
	{
		perror("невозможно открыть файл");
		exit(1);
	}
	if ((fp3 = fopen("text3.txt", "w")) == NULL)
	{
		perror("невозможно открыть файл");
		exit(1);
	}
	for (int i = 0; i < 3; i++)
	{
		fgets(ptr[i].name, sizeof(ptr[i].name), fp);
		fgets(ptr[i].surname, sizeof(ptr[i].surname), fp);
		fgets(ptr[i].middlename, sizeof(ptr[i].middlename), fp);
		fgets(ptr[i].job, sizeof(ptr[i].job), fp);
		fgets(str, sizeof(str), fp);
		ptr[i].money = atoi(str);
		fgets(str, sizeof(str), fp);
		ptr[i].timestamp = atoi(str);
		if (ptr[i].money > a)
		{
			fputs(ptr[i].name, fp1);
			fputs(ptr[i].surname, fp1);
			fputs(ptr[i].middlename, fp1);
			fputs(ptr[i].job, fp1);
			sprintf(tmp, "%d", ptr[i].money);
			fputs(tmp, fp1);
			sprintf(tmp, "%d", ptr[i].timestamp);
			fputs(tmp, fp1);
		}
		if (ptr[i].name[0] == b)
		{
			fputs(ptr[i].name, fp2);
			fputs(ptr[i].surname, fp2);
			fputs(ptr[i].middlename, fp2);
			fputs(ptr[i].job, fp2);
			sprintf(tmp, "%d", ptr[i].money);
			fputs(tmp, fp2);
			sprintf(tmp, "%d", ptr[i].timestamp);
			fputs(tmp, fp2);
		}
		if (ptr[i].timestamp > timestamp)
		{
			fputs(ptr[i].name, fp3);
			fputs(ptr[i].surname, fp3);
			fputs(ptr[i].middlename, fp3);
			fputs(ptr[i].job, fp3);
			sprintf(tmp, "%d", ptr[i].money);
			fputs(tmp, fp3);
			sprintf(tmp, "%d", ptr[i].timestamp);
			fputs(tmp, fp3);
		}
	}
	fclose(fp);
	fclose(fp1);
}
