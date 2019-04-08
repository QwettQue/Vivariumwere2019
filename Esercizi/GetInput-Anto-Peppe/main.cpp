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
/*
    int mat[N][N]={};
    mat[1][1]=1;*/

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
=======
        system("cls");

        for(i=0;i<N;i++)
        {
            printf("\t");
            for(m=0;m<N;m++)
            {
                printf(" %d ",mat[i][m]);

            }
            printf("\n");
        }
        for(i=0;i<N;i++)
        {
            for(m=0;m<N;m++)
            {
                    if(mat[i][m]!=0)
                    {
                        if(GetAsyncKeyState(VK_UP)!=0)
                        {
                            int i2=(i-1);
                            if(mat[i2][m]==0)
                            {
                                mat[i][m]=0;
                                i--;
                                mat[i2][m]=1;
                            }
/*
                        	mat[i][m]=0;
                            mat[--i][m]=1;
*//*

                        }
                        if(GetAsyncKeyState(VK_DOWN)!=0)
                        {
                            int i2=(i+1);
                            if(mat[i2][m]==0)
                            {
                                mat[i][m]=0;
                                i++;
                                mat[i2][m]=1;
                            }
                            //mat[i][m]=0;
                            //mat[++i][m]=1;

                        }
                        if(GetAsyncKeyState(VK_LEFT)!=0)
					    {

                            int m2=(m-1);
                            if(mat[i][m2]==0)
                            {
                                mat[i][m]=0;
                                m--;
                                mat[i][m2]=1;
                            }

					        //mat[i][m]=0;
                            //mat[i][--m]=1;
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
>>>>>>> b8df7fb7e3b77a60bffa878b7fc3be956f3724ef
*/

    getchar();


    return 0;
}
