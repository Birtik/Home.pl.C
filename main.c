#include <main.h>

double *wynik;

int main()
{
    int c;
    int *positions_of_oper;
    char *operations;
    scanf("%d",&c);

    wynik = (double*) malloc (sizeof(double)*c);

    for(int i=0;i<=c;i++)
    {
        explore(positions_of_oper,operations,i);
    }
    showResults(c);

    return 0;
}