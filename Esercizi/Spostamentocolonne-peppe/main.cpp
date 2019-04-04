#include <iostream>
#include <stdio.h>
#include <windows.h>
#define N 5

//Programma che mi ha fatto esercitare nello spostare gli utltimi valori di colonne ai primi posti

using namespace std;

int main()
{

    int mat[N][N]={};

    for(int i=0;i<N;i++)
    {
        mat[i][0]=1;
    }

    for(int i=0;i<N;i++)//stampa griglia iniziale
    {
        for(int m=0;m<N;m++)
        {
            printf(" %d ",mat[i][m]);
        }
        printf("\n");
    }


    int temp,m2=0;
    for(int i=0;i<N;i++)
    {
        for(int m=0;m<N;m++)
        {
            for(int x=0;x<N;x++)
            {

                if(m==N-1)// Spostiamo i valori a fine colonna, a inizio colonna
                {
                    temp=mat[x][m];
                    mat[x][m]=mat[x][m-(N-1)];
                    mat[x][m-(N-1)]=temp;
                    m2=0;
                }

                    m2=m+1;//Con questo indichiamo una posizione successiva ad m
                    temp=mat[x][m];
                    mat[x][m]=mat[x][m2];
                    mat[x][m2]=temp;

                printf("\n");
                printf("\n");
                for(int i=0;i<N;i++)
                {
                    for(int m=0;m<N;m++)
                    {
                        printf(" %d ",mat[i][m]);
                    }
                    printf("\n");
                }
                getchar();


            }


        }
    }



    printf("\n");
    for(int i=0;i<N;i++)
    {
        for(int m=0;m<N;m++)
        {
            printf(" %d ",mat[i][m]);
        }
        printf("\n");
    }
    getchar();



    getchar();

    return 0;
}













 /*           if(m2<N-1)
            {
                m2=m+1;
                temp=mat[i][m];
                mat[i][m]=mat[i][m2];
                mat[i][m2]=temp;
            }
            else
            {
                temp=mat[i][m2];
                mat[i][m2]=mat[i+1][0];
                mat[i+1][0]=temp;
                m2=0;

            }*/
