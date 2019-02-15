// пока копипиздинг у Коли

/*1.Программа. Дан текстовый файл. Написать функцию поиска самого
 короткого слова в строке (строки читать из данного файла. Найденное
 слово записать в новый файл. Имена обоих файлов задаются в командной строке*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>



void ShortestWord(char * file1, char * file2)
{
    unsigned long  min=1000;
    unsigned long  len=1000;
    char * str=NULL;
    char * string[len];
    

    FILE * OpFile;
    OpFile=fopen(file1,"r");
    
    if (OpFile==NULL)
    {
        perror ("Error: can not read file");
        exit (EXIT_FAILURE);
    }
    
    getline(&str,&len,OpFile);
    
    for(char *p=strtok(str," "); p; p = strtok(NULL, " "))
    {
        if(strlen(p)<min)
        {
            min = strlen(p);
            strcpy(string,p);
        }
    }
    
    fclose(OpFile);
    
    OpFile = fopen(file2, "w");
    
    if (OpFile==NULL)
    {
        perror ("Error: can not read file");
        exit (EXIT_FAILURE);
    }
    
    fputs(string, OpFile);
    fclose(OpFile);
    
}

int main(int arg, char * argv[])
{
    ShortestWord(argv[1], argv[2]);
    return 0;
}
