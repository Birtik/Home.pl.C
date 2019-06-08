#include <main.h>
#include <string.h>

double *wynik;

int main()
{
    int c;
    scanf("%d",&c);

    if(c<1)
    {
        printf("Incorrect input data!");
        exit(0);
    }
    wynik = (double*) malloc (sizeof(double)*c);

    for(int i=0;i<=c;i++)
    {
        explore(i);
    }
    showResults(c);

    return 0;
}
