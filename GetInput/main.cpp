#include <iostream>
#include <stdio.h>
#include <windows.h>
#define N 7
using namespace std;

int main()
{

    int i,m;
	char mat[N][N]={ "######",
					 "#    #",
					 "#    #",
					 "#    #",
					 "#    #",
					 "######",};
    mat[1][1]='@';
    printf("\n");

    while(1)
    {
	        system("cls");
	
	        for(i=0;i<N;i++)
	        {
	            printf("\t");
	            for(m=0;m<N;m++)
	            {
	                printf(" %c ",mat[i][m]);
	
	            }
	            printf("\n");
	        }
	        for(i=0;i<N;i++)
	        {
	            for(m=0;m<N;m++)
	            {
	                    if(mat[i][m]=='@')
	                    {
	                        if(GetAsyncKeyState(VK_UP)!=' ')
	                        {
	                        	mat[i][m]=' ';
	                            mat[--i][m]='@';
	
	                        }
	                        if(GetAsyncKeyState(VK_DOWN)!=0)
	                        {
	                            mat[i][m]=0;
	                            mat[++i][m]=1;
	
	                        }
	                        if(GetAsyncKeyState(VK_LEFT)!=0)
						    {
						        mat[i][m]=0;
	                            mat[i][--m]=1;
						    }
						    if(GetAsyncKeyState(VK_RIGHT)!=0)
						    {
						        mat[i][m]=0;
	                            mat[i][++m]=1;
						    }
	                    }
	            }
	        }
	
	    Sleep(100);
	}
	/*
	while(1)
	{
	
	
	    if(GetAsyncKeyState(VK_UP)!=0)
	    {
	        printf("su\n");
	    }
	    if(GetAsyncKeyState(VK_DOWN)!=0)
	    {
	        printf("giu\n");
	    }
	    if(GetAsyncKeyState(VK_LEFT)!=0)
	    {
	        printf("sinistra\n");
	    }
	    if(GetAsyncKeyState(VK_RIGHT)!=0)
	    {
	        printf("destra\n");
	    }
	
	    getchar();
	
	}
*/

    getchar();


    return 0;
}
