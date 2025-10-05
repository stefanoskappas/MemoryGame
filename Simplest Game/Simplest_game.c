/* Το πρόγραμμα Simplest image memory δέχεται την επιλογή δύο εικόνων από τον φάκελο
 * Eikones και ελέγχει εάν η μία εικόνα ταιριάζει με την άλλη εικόνα. Αν ταιριάζουν
 * στέλνει ένα μύνημα επιβεβαίωσης. Αλλιώς στέλνει μηνύματα σφάλματος όπως ότι δεν
 * ταιριάζουν οι εικόνες μεταξυ τους, ή ότι επέλεξες την ίδια εικόνα 2 φορές ή ότι
 * δεν υπάρχει αυτή η εικόνα που ψάχνεις.
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
