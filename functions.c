#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

double *wynik;

void checkValid(char line[])
{
    int numbers = 0,operators = 0;
    int length = strlen(line) - 1;

    for(int i=0;i<length;i++)
    {
        if(('/'==line[i]) || ('*'==line[i]) || ('+'==line[i]) || ('-'==line[i]))
        {
            operators++;
        }
        if( isdigit( line[i] ) )
        {
            numbers++;
        }
    }
    if((numbers-1!=operators))
    {
        printf("Incorect input data!\n");
        exit(0);
    }
}

void calculate(char *operations,int *position,char line[],int result)
{
    double suma = 0;

    for(int i=0;i<strlen(operations);i++)
    {
        if(!(isdigit(line[position[i]-2])) || !(isdigit(line[position[i]+2])) )
        {
            printf("Incorect input data!\n");
            exit(0);
        }

        int jj = atoi(&line[position[i]-2]);
        int kk = atoi(&line[position[i]+2]);
        double j = (double) jj;
        double k = (double) kk;

        if('+'==operations[i])
        {
            if(suma==0) suma = j + k;
            else
            {
                if(position[i-1]!=NULL && position[i-1]>position[i])
                {
                    suma += j;
                }
                else if(position[i-1]!=NULL && position[i-1]<position[i])
                {
                    suma += k;
                }
            }
        }
        else if('-'==operations[i])
        {
            if(suma==0)  suma = j - k;
            else
            {
                if(position[i-1]!=NULL && position[i-1]>position[i])
                {
                    suma -= j;
                }
                else if(position[i-1]!=NULL && position[i-1]<position[i])
                {
                    suma -= k;
                }
            }
        }
        else if('*'==operations[i])
        {
            if(suma==0) suma = j * k;
            else
            {
                if(position[i-1]!=NULL && position[i-1]>position[i])
                {
                    suma *= j;
                }
                else if(position[i-1]!=NULL && position[i-1]<position[i])
                {
                    suma *= k;
                }
            }
        }
        else if('/'==operations[i])
        {
            if(suma==0) suma = j / k;
            else
            {
                if(position[i-1]!=NULL && position[i-1]>position[i])
                {
                    suma /= j;
                }
                else if(position[i-1]!=NULL && position[i-1]<position[i])
                {
                    suma /= k;
                }
            }
        }
        else
        {
            printf("INVALID OPERATION!!!");
        }
    }

    wynik[result] = suma;
}

void orderOperation(char *operations,int *position){
    int j = 0;
    for(int i=0;i<strlen(operations);i++)
    {
        if(('/'==operations[i]) || ('*'==operations[i]) && i!=0)
        {
            int temp = position[i];
            position[i] = position[j];
            position[j] = temp;

            char temp2 = operations[i];
            operations[i] = operations[j];
            operations[j] = temp2;
            j++;
        }
    }
}

void explore(int *positions_of_oper, char *operations,int result)
{
    char line[50]=" ";
    char operation[10];
    positions_of_oper = (int*) malloc (sizeof(int)*10);
    for(int i=0;i<10;i++)
    {
        positions_of_oper[i] = 0;
    }

    static int i = 0;
    fgets(line, sizeof line, stdin);

    if(i!=0)
    {
        checkValid(line);

        int j = 0;
        for(int i=0;i<strlen(line);i++){

            char t[1];
            t[0] = line[i];

            if(('+'==t[0]) || ('-'==t[0]) ||  ('*'==t[0]) || ('/'==t[0]))
            {
                operation[j] = line[i];
                positions_of_oper[j] = i;
                j++;
            }
        }
        operation[j] = '\0';

        operations = (char*) malloc ((strlen(operation))*sizeof(char));

        int k;
        for(k=0;k<strlen(operation);k++)
        {
            operations[k] = operation[k];
        }
        operations[k] = '\0';

        orderOperation(operations,positions_of_oper);

        calculate(operations,positions_of_oper,line,result);

        free(positions_of_oper);
        free(operations);
    }
    else i++;
}

void showResults(int line)
{
    for(int i=1;i<=line;i++)
    {
        wynik[i] = floor(wynik[i]*100)/100;
        int truncated = (int)wynik[i];

        if(wynik[i] == truncated)
        {
            printf("%d\n",truncated);
        }
        else
        {
            printf("%.1f\n",wynik[i]);
        }
    }
    free(wynik);
}

