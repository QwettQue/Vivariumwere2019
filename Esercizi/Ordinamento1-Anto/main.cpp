#include <iostream>
#include <stdio.h>
#include <windows.h>
#define N 5

//Programma che mi ha fatto esercitare nello spostare il primo valore di mat[0][0] all ultima cella mat[N][N]

using namespace std;

int main()
{

    int mat[N][N]={};

    mat[0][0]=1;

    for(int i=0;i<N;i++)
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
            if(m2<N-1)
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
