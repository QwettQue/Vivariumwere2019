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

            if(m2<N-1)//Ordinamento tipo bubble sort, m2<N-1 perchè deve fermarsi al penultimo ciclo del fot m2
            {

                m2=m+1;//Con questo indichiamo una posizione successiva ad m
                temp=mat[i][m];
                mat[i][m]=mat[i][m2];
                mat[i][m2]=temp;

            }

            else// Spostiamo i valori a fine colonna, a inizio colonna
            {
                temp=mat[i][m2];
                mat[i][m2]=mat[i][m2-(N-1)];
                mat[i][m2-(N-1)]=temp;
                m2=0;
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
