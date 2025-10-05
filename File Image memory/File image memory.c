/* �� ��������� File image memory ������� ��� ������� ��� ������� ��� ��� ������
 Eikones ��� ������� ��� �� ������ ��������� ������ �����������. �� ������ ����
 ������� ��� ������ ������������ ��� �� �������� ������������ �� ��������. ������
 ������� �������� ��������� ���� ��� ��� ������� ����� �������� ������ ����, � ���
 ����� ������� ��� ����� ��� ������� 2 ����� � ��� ��� ������� ���� �� ������ ���
 ������. ������� �� ������ �� ������������ � ���������� �� ��������� �� ��� �������.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genlib.h"
#include "simpio.h"
#include <stdbool.h>
#define SIZE 16
int readFile(FILE *f, char element[SIZE][SIZE])
{
    int i = 0;
    int total = 0;
    while(fgets(element[i], SIZE, f))
	{
        if (element[i][0] != 'A')
        {
            if (element[i][strlen(element[i])-1] == '\n')
                element[i][strlen(element[i])-1] = '\0';
        }
        i++;
    }
    total = i;
    for(i = 0; i < total; i++)
    {
        printf("%s\n", element[i]);
    }
    printf("\n");
    return total;
}
int main(void)
{
    FILE *a, *b;
    string filename_a, filename_b;
    int totala, totalb;
    char elementa[SIZE][SIZE], elementb[SIZE][SIZE];
    printf("Select the first image: ");
    filename_a = GetLine();
    a = fopen(filename_a, "r");
    if (a == NULL)
    {
        printf("File not exists\n");
        return 0;
    }
    totala = readFile(a, elementa);
    printf("Select the second image: ");
    filename_b = GetLine();
    b = fopen(filename_b, "r");
    if (b == NULL)
    {
        printf("File not exists\n");
        return 0;
    }
    totalb = readFile(b, elementb);
    if(!strcmp(filename_b, filename_a))
    {
        printf("You cannot select the same image but the similar.\n");
        return 0;
    }
    else
    {
        bool flag = false;
        printf("\n");
        for (int i = 0; i < totala; i++)
        {
            for (int j = 0; j < totalb; j++)
            {
                if(!strcmp(elementa[i], elementb[j]) == 1)
                    flag = true;
            }
        }
        if (flag == true)
            printf("The images is matching\n");
        else
            printf("The images cannot matching\n");
    }
    fclose(a);
    fclose(b);
}
