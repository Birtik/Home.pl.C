#include <main.h>
#include <string.h>

double *wynik;

int main()
{
    int num;
    char term;

    scanf("%d", &num);

    if(num<1)
    {
        printf("Incorrect input data!");
        exit(0);
    }
    wynik = (double*) malloc (sizeof(double)*num);

    for(int i=0;i<=num;i++)
    {
        explore(i);
    }

    showResults(num);

    return 0;
}
