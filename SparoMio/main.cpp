#include <iostream>
#include <curses.h>
#include <unistd.h>
#include <assert.h>
using namespace std;


int spari=0;


struct shot
{
    int x;
    int y;
    int avanti;
};

int main()
{

    initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
    curs_set(0);
    keypad(stdscr, TRUE);

    int in,righe,colonne;
    extern int spari;
    int maxspari=5;
    getmaxyx(stdscr, righe, colonne);



    struct shot* sparo;
    sparo=(struct shot*) malloc(maxspari * sizeof(struct shot));
    assert(sparo!=NULL);



    while(1)
    {

        mvprintw(1,14,"Premere spazio per sparare");
        for(int i=0;i<10000;i++)
        {
            in=getch();
            //usleep(10);
            if(in==' ')
            {
                spari+=1;

                sparo[spari-1].x=0;
                sparo[spari-1].y=29;
                sparo[spari-1].avanti=1;

                if(spari==maxspari)
                {
                    maxspari=maxspari+maxspari;
                    sparo=(struct shot*) realloc(sparo, maxspari * sizeof(struct shot));
                    assert(sparo!=NULL);
                }
            }

        }


            for(int i=0;i<spari;i++)
            {
                if(sparo[i].avanti==1)
                    sparo[i].y-=1;
            }




            clear();
            mvprintw(1,14,"Premere spazio per sparare");
            mvprintw(28,30,"spari %d",spari);
            mvprintw(29,30,"maxspari %d",maxspari);
            for (int i=0; i < spari; ++i)
            {

                mvprintw(sparo[i].y,sparo[i].x,"!");

            }

            refresh();




    }

    endwin();
    free(sparo);

    return 0;
}

