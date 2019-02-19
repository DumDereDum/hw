/*1.Программа. Дан текстовый файл. Написать функцию поиска самого
 короткого слова в строке (строки читать из данного файла. Найденное
 слово записать в новый файл. Имена обоих файлов задаются в командной строке*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


void ShortesWord(char file1[], char file2[])
{
    unsigned long min=1000;
    unsigned long len=1000;
    
    char * string[len];
    char * str=NULL;
    
    FILE * file;
    
    file = fopen(file1, "r");
    
    if (file==NULL)
    {
        perror ("Error: can not read file");
        exit (EXIT_FAILURE);
    }
    
    getline(&str, &len, file);
    
    for(char *word=strtok(str," "); word; word= strtok(NULL, " "))
    {
        if(srtlen(word)< min)
        {
            min = strlen(word);
            strcpy(string,word);
        }
    }
    
    fclose(file);
    
    file = fopen(file2, "w");
    
    if (file==NULL)
    {
        perror ("Error: can not read file");
        exit (EXIT_FAILURE);
    }
    
    fputs(string,file);
    fclose(file);
    
}


int main()
{
    char file1[]="test1";
    char file2[]="test2";
    ShortestWord(file1,file2);
    
    return 0;
}

