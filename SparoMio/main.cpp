#include <iostream>
#include <curses.h>
#include <unistd.h>
using namespace std;
//void add_colpo();
int scur=0;

struct shot
{
    int x=0;
    int y=29;
    int avanti=1;
};



int main()
{
    struct shot c;
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    int in,righe,colonne;
    getmaxyx(stdscr, righe, colonne);

    int f;

    while(1)
    {


        for (int i=0; i < scur; ++i)
        {

            mvprintw(c.y,c.x,"!");

        }

        refresh();

        for(int i=0;i<50;i++)
        {
            in=getch();

            if(in==' ')
            {
                scur=1;
                //mvprintw(righe-1,10,"ciao");
                f=1;
                //add_colpo();
            }

        }

        if(f==1)
        {
            mvprintw(righe-1,10,"ciao");

            for(int i=0;i<scur;i++)
            {
                if(c.avanti==1)
                    c.y-=1;
            }




            for (int i=0; i < scur; ++i)
            {

                mvprintw(c.y,c.x,"!");
            refresh();

            sleep(2);
            }



        }
    }

    endwin();

    return 0;
}/*
void add_colpo()
{
    struct shot c;
    scur++;
    c.x=0;
    c.y=29;
    c.avanti=1;
    mvprintw(29,10,"ciao");

}*/
