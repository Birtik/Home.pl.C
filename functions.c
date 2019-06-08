#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

double *wynik;

void checkValid(char line[]){
    int numbers = 0,operators = 0;
    int length = strlen(line) - 1;

    for(int i=0;i<length;i++)
    {
        if(('/'==line[i]) || ('*'==line[i]) || ('+'==line[i]) || ('-'==line[i] && !isdigit(line[i+1])))
        {
            operators++;
        }
        if( isdigit( line[i] ) && (line[i+1]==' ' || line[i+1]=='\n' ))
        {
            numbers++;
        }

        if(isalpha(line[i]))
        {
            printf("Incorect input data!\n");
            exit(0);
        }
    }
    if((operators<1) || numbers-1!=operators)
    {
        printf("Incorect input data!\n");
        exit(0);
    }
}



void calculate(char line[],int result){

    int i;
    for(i = 0;i<=strlen(line);i++){
        double leftValue = 0;
        double rightValue= 0;

        bool leftFloat = false;
        bool rightFloat = false;

        double suma = 0;
        int k = 0;
        char l[10] = " ";
        char r[10] = " ";

        int lB = 0;
        int rB = 0;

        if((line[i]=='/' || line[i]=='*' || line[i]=='+' || line[i]=='-') && (line[i-1]==' ') && (line[i+1]==' ') )
        {
            if(!(isdigit(line[i-2])) || !(isdigit(line[i+2])) ){
                if(line[i+2]!='-')
                {
                    printf("Incorect input data\n");
                    exit(0);
                }
            }
            bool isProrityD = false;
            bool isProrityM = false;

            if(line[i]!='/')
            {
                for(int ii = i;ii<=strlen(line);ii++){
                    if(line[ii]=='/') isProrityD = true;
                }

                for(int ii = i;ii<=strlen(line);ii++){
                    if(line[ii]=='*') isProrityM = true;
                }
            }
            else
            {
                isProrityD = true;
            }

            if((isProrityD && line[i]=='/') || ( isProrityD==false && isProrityM && line[i]=='*') || (isProrityD==false && isProrityM==false) )
            {
                 while(line[i-2-k]!=' ' && i-2-k >=0)
                {
                    if(line[i-2-k]!='.' && line[i-2-k]!='-' && !(isdigit(line[i-2-k])) )
                    {
                        printf("Incorect input data!\n");
                        exit(0);
                    }
                    l[k] = line[i-2-k];

                    if(line[i-2-k]=='.')
                    {
                        leftFloat = true;
                    }
                    k++;

                    if(line[i-2-k]=='-')
                    {

                        l[k] = '-';
                        k++;
                        break;
                    }
                }

                lB = i-2-k;
                l[k] = '\0';

                if(strlen(l)>1)
                {
                    char g[10];
                    int u;
                    for(u=0;u<strlen(l);u++)
                    {
                        g[u] = l[strlen(l)-1-u];
                    }

                    g[u] = '\0';

                    if(g[u-1]=='.')
                    {
                        printf("Incorect input data!\n");
                        exit(0);
                    }

                    if(leftFloat) leftValue = atof(&g);
                    else leftValue = atoi(&g);
            }
            else
            {
                if(l[k-1]=='.')
                {
                    printf("Incorect input data!\n");
                    exit(0);
                }
                if(leftFloat) leftValue = atof(&l);
                else leftValue = atoi(&l);
            }

            k = 0;
            int dd = 0;
            while(line[i+2+k]!=' ' && line[i+2+k]!='\n')
            {
                if(line[i+2+k]!='.' && line[i+2+k]!='-' && !(isdigit(line[i+2+k])) )
                {
                    printf("Incorect input data!\n");
                    exit(0);
                }

                r[k] = line[i+2+k];

                if(line[i+2+k]=='.')
                {
                    rightFloat = true;
                    dd++;
                }
                k++;
            }

            if(dd>1)
            {
                printf("Incorect input data!\n");
                exit(0);
            }

            rB = i+2+k;
            r[k] = '\0';


            if(r[k-1]=='.')
            {
                printf("Incorect input data!\n");
                exit(0);
            }

            if(rightFloat) rightValue = atof(&r);
            else rightValue = atoi(&r);

            if(line[i]=='*') suma = leftValue * rightValue;
            else if(line[i]=='/') suma = leftValue / rightValue;
            else if(line[i]=='+') suma = leftValue + rightValue;
            else if(line[i]=='-') suma = leftValue - rightValue;


            if(rightValue==0 && line[i]=='/')
            {
                printf("We don't divide by zero :) !\n");
                exit(0);
            }

            char sum[20];
            sprintf(sum, "%.2f", suma);
            int d;
            for(d=0;d<strlen(sum);d++);
            sum[d] = '\0';

            char tabx[50];
            int x;
            for(x=0;x<=lB;x++)
            {
                tabx[x] = line[x];
            }
            tabx[x] = '\0';
            strcat( tabx, &sum );

            char taby[50];
            int ii = 0;
            int y;
            for(y=rB;y<strlen(line);y++,ii++)
            {
                taby[ii] = line[y];
            }

            taby[ii] = '\0';
            strcat( tabx, &taby );

            int l;
            for(l=0;l<strlen(tabx);l++)
            {
                line[l] = tabx[l];
            }
            line[l] = '\0';
            i = 0;

            isProrityD = false;
        }
        }
    }
    wynik[result] = atof(line);
}

void explore(int result)
{
    char line[50] = " ";

    static int i = 0;
    fgets(line, sizeof line, stdin);

    if(i!=0)
    {
        checkValid(line);
        calculate(line,result-1);
    }
    else i++;
}

void showResults(int line)
{
    for(int i=0;i<line;i++)
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

