#include <iostream>

using namespace std;
#define L 4
int main()
{
    int i,j;
    char tabella[L][L]={{'x','x','o','x'},{'x','x','o','x'},{'x','x','o','x'},{'x','x','o','x'}};
    for (i = 0;i < L;i++)
    {
        for (j = 0;j < L;j++)
        {
            cout << tabella[i][j];
        }
        cout << endl;
    }
    getchar();
    for (i = 0;i < L;i++)
    {
        for (j = 0;j < L;j++)
        {
            if (tabella[i][++j]=='o')
            {
                tabella[i][j]='o';
                tabella[i][++j]='x';

            }
            cout << tabella[i][j];
        }
        cout << endl;
    }

    return 0;
}
