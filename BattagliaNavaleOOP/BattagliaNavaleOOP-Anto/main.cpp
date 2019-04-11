#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define N 5
using namespace std;

class Nave
{
    public:
    int y=2,x=3;
    int colpito=0;
    Nave()
    {

    }
    ~Nave();

};
Nave::~Nave()
{
    colpito=1;
}

int main()
{
    Nave n;

    int mat[N][N]={};
    int y,x;

    mat[n.y][n.x]=1;

    while(1)
    {

        for(int i=0;i<N;i++)
        {
            for(int m=0;m<N;m++)
            {
                if(mat[i][m]==mat[n.y][n.x])
                {
                    if(n.colpito==0)
                    {
                        printf("[ ]");
                    }
                    else
                    {
                        printf("[X]");
                    }
                }
                else if(mat[i][m]==2)
                {
                    printf("[o]");
                }
                else
                {
                    printf("[ ]");
                }
            }
            printf("\n");

        }

        printf("Inserisci coordinate");
        scanf("%d%d",&y,&x);

        if(mat[y][x]==mat[n.y][n.x])
        {
            //n.colpito=1;
            n.~Nave();
        }
        else
        {
            mat[y][x]=2;
        }
    }


    return 0;
}
