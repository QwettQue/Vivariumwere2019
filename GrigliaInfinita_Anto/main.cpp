#include <iostream>
#define N 5
using namespace std;

int main()
{
    int mat[N][N]={};
    int i,m;

    for(i=0;i<N;i++)
    {
       m=1;

       mat[i][m]=1;
    }

    while(1)
    {

	int n;
        for(i=0;i<N;i++)
        {
            for(m=0;m<N;m++)
            {


            if(mat[i][m]==1)
            {
            	
                if(m==0)
                {
                	mat[i][m]=0;
                	n=m+4;
                	mat[i][n]=1;
				}
				else
				{
					mat[i][m]=0;
					n=m-1;
	                mat[i][n]=1;
				}
				
            }

            }



        }
		 for(i=0;i<N;i++)
        {
            for(m=0;m<N;m++)
            {
            	
            printf(" %d ",mat[i][m]);
            }
            printf("\n");


        }
        getchar();

    }










    return 0;
}
