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
        if(('/'==line[i]) || ('*'==line[i]) || ('+'==line[i]) || ('-'==line[i] && !isdigit(line[i+1])))
        {
            operators++;
        }
        if( isdigit( line[i] ) && (line[i+1]==' ' || line[i+1]=='\n'))
        {
            numbers++;
        }
    }

    if((operators<1) || numbers-1!=operators)
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
            if(line[position[i]+2]!='-')
            {
                printf("Incorect input data!\n");
                exit(0);
            }
        }

        int jj;
        int kk;

        if(line[position[i]-3]!=' ' && isdigit(line[position[i]-3]))
        {
            char c[10] = " ";
            char c2[10] = " ";
            int k = 0;
            while((line[position[i]-2-k]!=' ') && isdigit(line[position[i]-2-k]))
            {
                c[k] = line[position[i]-2-k];
                k++;
            }
            if(line[position[i]-2-k]=='-')
            {
                c[k] = '-';
                k++;
            }

            c[k] = '\0';

            int j = 0;
            for(int i=strlen(c)-1;i>=0;i--)
            {
                c2[j] = c[i];
                j++;
            }
            c2[j] = '\0';

            jj = atoi(&c2);
            kk = atoi(&line[position[i]+2]);
        }
        else if(line[position[i]+3]!=' ' && isdigit(line[position[i]+3]))
        {
            char c[10] = " ";
            int k = 0;
            while((line[position[i]+2+k]!=' ') && (isdigit(line[position[i]+2+k]) || line[position[i]+2+k]=='-') )
            {
                c[k] = line[position[i]+2+k];
                k++;
            }
            c[k] = '\0';
            jj = atoi(&line[position[i]-2]);
            kk = atoi(&c);
        }
        else
        {
            jj = atoi(&line[position[i]-2]);
            kk = atoi(&line[position[i]+2]);
        }

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


            if(('+'==line[i]) || ('-'==line[i] && !(isdigit(line[i+1]))) ||  ('*'==line[i]) || ('/'==line[i]))
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

