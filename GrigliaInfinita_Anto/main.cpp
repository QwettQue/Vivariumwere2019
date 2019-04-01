#include <iostream>
#define N 5
using namespace std;

int main()
{
    int mat[N][N]={};
    int i,m;

    for(i=0;i<N;i++)
    {
       m=0;

       mat[m][i]=1;
    }



        for(i=0;i<N;i++)
        {

            for(m=0;m<N;m++)
            {
                if(mat[i][m]==1)
                {
                    int i2=(i-1);
                    if(mat[i2][m]==1)
                    {
                        mat[i][m]=0;
                        i-=1;
                        mat[i2][m]=1;
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





    return 0;
}
