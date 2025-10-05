/* �� ��������� Simplest image memory ������� ��� ������� ��� ������� ��� ��� ������
 * Eikones ��� ������� ��� � ��� ������ ��������� �� ��� ���� ������. �� ����������
 * ������� ��� ������ ������������. ������ ������� �������� ��������� ���� ��� ���
 * ���������� �� ������� ������ ����, � ��� �������� ��� ���� ������ 2 ����� � ���
 * ��� ������� ���� � ������ ��� �������.
*/
#include <stdio.h>
#include <stdlib.h>
#include "genlib.h"
#include "simpio.h"
int main(void)
{
    FILE *a, *b;
    string filename_a, filename_b;
    printf("Select the first image: ");
    filename_a = GetLine();
    a = fopen(filename_a, "r");
    if (a == NULL)
    {
        printf("File not exists\n");
        return 0;
    }
    printf("Select the second image: ");
    filename_b = GetLine();
    b = fopen(filename_b, "r");
    if (b == NULL)
    {
        printf("File not exists\n");
        return 0;
    }
    if(!strcmp(filename_b, filename_a))
    {
        printf("You cannot select the same image but the similar.\n");
        return 0;
    }
    else if (!strcmp(filename_a,"Eikones/a.png") && !strcmp(filename_b,"Eikones/c.png") ||
             !strcmp(filename_a,"Eikones/c.png") && !strcmp(filename_b,"Eikones/a.png") ||
             !strcmp(filename_a,"Eikones/b.png") && !strcmp(filename_b,"Eikones/d.png") ||
             !strcmp(filename_a,"Eikones/d.png") && !strcmp(filename_b,"Eikones/b.png"))
        printf("The images is matching.\n");
    else
        printf("The images cannot matching.\n");
    fclose(a);
    fclose(b);
}
