#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <time.h>
#define N 5
using namespace std;

int main()
{
    int mat[N][N]={};
    mat[0][0]=1;



    while(1)
    {
        system("cls");
        for(int y=0;y<N;y++)
        {

            for(int x=0;x<N;x++)
            {

                printf("%d",mat[y][x]);
                if(mat[y][x]==1)
                {
                    if(GetAsyncKeyState(VK_UP)!=0)
                    {
                        int y2=(y-1);
                        if(mat[y2][x]==0)
                        {
                            mat[y][x]=0;
                            y-=1;
                            mat[y2][x]=1;
                        }
                    }

                    if(GetAsyncKeyState(VK_DOWN)!=0)
                    {
                        int y2=(y+1);
                        if(mat[y2][x]==0)
                        {
                            mat[y][x]=0;
                            y+=1;
                            mat[y2][x]=1;
                        }
                    }


                    if(GetAsyncKeyState(VK_LEFT)!=0)
                    {
                        int x2=(x-1);
                        if(mat[y][x2]==0)
                        {
                            mat[y][x]=0;
                            x-=1;
                            mat[y][x2]=1;
                        }
                    }


                    if(GetAsyncKeyState(VK_RIGHT)!=0)
                    {
                        int x2=(x+1);
                        if(mat[y][x2]==0)
                        {
                            mat[y][x]=0;
                            x+=1;
                            mat[y][x2]=1;
                        }
                    }
                }
            }
            printf("\n");
            Sleep(200);

        }
    }






    return 0;
}
