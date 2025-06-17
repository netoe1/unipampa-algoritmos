#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main(void)
{
    setlocale(LC_ALL, "");
    char file1[30];
    char file2[30];

    puts("\nDigite o nome do primeiro arquivo:");
    setbuf(stdin, NULL);
    fgets(file1, sizeof(file1) - 1, stdin);
    file1[strcspn(file1, "\n")] = '\0';

    puts("\nDigite o nome do segundo arquivo:");
    setbuf(stdin, NULL);
    fgets(file2, sizeof(file2) - 1, stdin);
    file2[strcspn(file2, "\n")] = '\0';

    FILE *FILE_1 = fopen(file1, "r");
    FILE *FILE_2 = fopen(file2, "w");

    char ch = ' ';
    while ((ch = fgetc(FILE_1)) != EOF)
    {
        if (tolower(ch) == 'a' ||
            tolower(ch) == 'e' ||
            tolower(ch) == 'i' ||
            tolower(ch) == 'o' ||
            tolower(ch) == 'u')
        {
            fputc('*', FILE_2);
            continue;
        }
        
        fputc(ch, FILE_2);
    }

    fclose(FILE_1);
    fclose(FILE_2);
    return 0;
}