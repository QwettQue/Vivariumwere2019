
/*******************
    Marco Spagnuolo
    4IC
    acquanest
*******************/



#include <iostream>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#define VUOTO 0
#define NAVE 1
#define C 5                 //costante che indica numero righe e colonne
#define N 5                 // costante indica numero navi

using namespace std;
void interfaccia(void);     //interfaccia principale
void regole(void);          //ascii art di regole

int main()
{
    int whil=0;
    int gioca=0;
    int turno=0;
    int var=0;                          // del while
    int w=N;                            //variabile del primo while inizializzata=a N
    int x=0;                            // variabile del secondo while
    int y=0;                            // variabile per la scelta avversario: utente o cpu
    int i,j;                            //variabili di incremento
    int rr,cr;                          //righe e colonne random
    char nomeg1[15],nomeg2[] = "CPU";
    int campogiocatore[C][C]={};        // proprio campo
    int campogiocatore2[C][C]={};       // campo giocatore avversario
    srand(time(NULL));
    system("COLOR 0B");



    //Assegnazione di navi
    while(w>0)//Griglia giocatore
    {
        rr=rand()%C;//righe randomizzate nel campo del giocatore
        cr=rand()%C;//colonne randomizzate nel campo del giocatore

        if(campogiocatore[rr][cr]==VUOTO)
        {
            campogiocatore[rr][cr]=NAVE;
            w--;
        }
    }

    w=N;

    while(w>0)//Griglia cpu
    {
        rr=rand()%C;
        cr=rand()%C;

        if(campogiocatore2[rr][cr]==VUOTO)
        {
            campogiocatore2[rr][cr]=NAVE;
            w--;
        }
    }
    //Assegnazione di navi



    while(x!=3)
    {

        interfaccia();
        printf("Digita:\n");
        printf("1 per visualizzare le regole del gioco\n");
        printf("2 per iniziare una partita\n");;
        printf("3 per uscire dal programma\n");
        fflush(stdin);
        scanf("%d",& x);

        if(x==1)
        {
            regole();//asci art
            system("PAUSE");
            system("cls");
        }

        else if(x==2)
        {


            printf("\n\n\n");
            printf("Inserisci il tuo nome\n");
            cin>>nomeg1;
            system("cls");
            int riga, colonna, navi_colpite_g1 = 0, navi_colpite_g2 = 0;

/*
            for(i=0;i<C;i++)
            {
                for(j=0;j<C;j++)
                {
                    printf(" %d ",campogiocatore[i][j]);
                }
                printf("\n");
            }
            printf("\n");
            for(i=0;i<C;i++)
            {
                for(j=0;j<C;j++)
                {
                    printf(" %d ",campogiocatore2[i][j]);
                }
                printf("\n");
            }

            getchar();
            getchar();
*/
            while(gioca == 0)//Esce dal while solo quando l utente inserisce -1 e quando un giocatore vince
            {
                system("cls");
                printf("\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Legenda modifiche proprio campo\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ~ -> X == nave affondata\n");

                //////////////////////////////////////////////////////////////
                //Stampa campo giocatore
                printf("\t    0  1  2  3  4\n");
                for(i=0; i<C; i++)//Ciclo da aggiornare
                {
                    printf("\t");

                    for (j=0; j<C; j++)
                    {
                        if(j==0)
                        {
                            printf(" %d ",i);
                        }

                        if (campogiocatore[i][j]==NAVE || campogiocatore[i][j]==VUOTO)
                        {
                            printf("[~]");
                        }

                        else if(campogiocatore[i][j]==3)
                        {
                            printf("[0]");
                        }
                        else if(campogiocatore[i][j]==2)
                        {
                            printf("[X]");
                        }


                    }

                    if (i==4)
                    {
                        printf("\t\t Griglia di %s", nomeg1);
                    }
                    printf("\n");
                }
                //Stampa campo giocatore
                //////////////////////////////////////////////////////////////

                printf("\n\n\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Legenda modifiche campo cpu\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ~ == mare\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ~ -> 0 == cella vuota gia' colpita\n");
                printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t ~ -> X == nave affondata\n");

                //////////////////////////////////////////////////////////////
                //Stampa campo cpu
                printf("\t    0  1  2  3  4\n");
                for(i=0; i<C; i++)
                {
                    printf("\t");

                    for (j=0; j<C; j++)//Ciclo da aggiornare
                    {


                        if(j==0)
                        {
                            printf(" %d ",i);
                        }

                        if (campogiocatore2[i][j]==NAVE || campogiocatore2[i][j]==VUOTO)
                        {
                            printf("[~]");
                        }

                        else if(campogiocatore2[i][j]==3)
                        {
                            printf("[O]");
                        }

                        else if(campogiocatore2[i][j]==2)
                        {
                            PlaySound(TEXT("gun.wav"), NULL, SND_SYNC);
                            printf("[X]");

                        }

                    }

                    if (i==4)
                    {
                        printf("\t\t Griglia della %s", nomeg2);
                    }
                    printf("\n");

                }
                //Stampa campo cpu
                //////////////////////////////////////////////////////////////

                printf("\n");


                if(turno == 0)//Turno giocatore
                {   fflush(stdin);
                    printf("Gioca: %s\n", nomeg1);
                    printf("Inserisci coordinate (Inserisci -1 per terminare): \n");
                    printf("Inserire riga\t\t");
                    fflush(stdin);
                    scanf("%d", &riga);
                    printf("Inserire colonna\t");
                    fflush(stdin);
                    scanf("%d", &colonna);
                    fflush(stdin);

                    if(riga == -1 || colonna == -1)//uscita dal ciclo
                    {
                        gioca++;
                        system ("cls");
                    }
                    else
                    {
                        if(campogiocatore2[riga][colonna] == VUOTO)
                        {
                            printf("Acqua!\n");
                            campogiocatore2[riga][colonna]= 3;//contatore cella colpita
                        }

                        else if(campogiocatore2[riga][colonna] == NAVE)
                        {
                            printf("Colpito e affondato!\n");
                            campogiocatore2[riga][colonna]= 2;//contatore cella colpita
                            navi_colpite_g2++;//Contatore nave colpita
                        }

                        else if(campogiocatore2[riga][colonna] == 2 || campogiocatore2[riga][colonna] == 3)
                        {
                            printf("Hai gia' attaccato questa cella! Salti il turno.\n");
                        }

                    }
                    if(navi_colpite_g2 == N)//Uscita dal ciclo
                    {
                        printf("\nHa vinto %s\n", nomeg1);
                        getchar();
                        gioca++;
                    }

                    fflush(stdin);
                    printf("Premere un tasto per continuare");
                    getchar();
                    turno = 1;
                    fflush(stdin);

                }//turno dell if



                else if(turno == 1)//Turno cpu
                {
                    srand(time(NULL));
                    while(whil!=0)//non generare stesse coordinate
                    {
                        riga=rand()%C;
                        colonna=rand()%C;

                        if(campogiocatore[riga][colonna]==0|| campogiocatore[riga][colonna]==1)
                        {
                            whil--;
                        }
                    }
                    whil=1;

                    printf("Gioca: %s\n", nomeg2);

                    printf("%s attacca [%d][%d]", nomeg2, riga, colonna);

                    if(campogiocatore[riga][colonna] == VUOTO)
                    {
                        printf("Acqua!\n");
                        campogiocatore[riga][colonna] = 3;
                    }
                    else if(campogiocatore[riga][colonna] == NAVE)
                    {
                        printf("Colpito e affondato!\n");
                        campogiocatore[riga][colonna] = 2;
                        navi_colpite_g1++;//Contatore nave colpita
                    }
                    else
                    {
                        printf("Hai gia' attaccato questa cella! Salti il turno.\n");
                    }

                    if(navi_colpite_g1 == N)//Uscita dal ciclo
                    {
                        printf("\nHa vinto %s\n", nomeg2);
                        getchar();
                        gioca++;
                    }
                    fflush(stdin);
                    printf("Premere un tasto per continuare");
                    getchar();
                    turno = 0;
                    fflush(stdin);

                }//fine dell else if

            }//fine del while
        }




        else if(x==3)
        {
            printf("Sei uscito...\n");
            system("PAUSE");
        }

        else if(x==10)
        {
            system("scherzo.txt");
            x=x/0;//fai crashare il programa
        }

        else
        {
            printf("Inserire un numero compreso tra 1 e 3\n");
            x=0;
            fflush(stdin);
            system("PAUSE");
            system ("cls");
        }
    }



    return 0;
}





    void interfaccia (void)
    {
        printf("\t\t\t\t\t\t\t                                            _                   \n");
        printf("\t\t\t\t\t\t\t                                           | |                  \n");
        printf("\t\t\t\t\t\t\t   __ _  __ _ _   _  __ _   _ __   ___  ___| |_                 \n");
        printf("\t\t\t\t\t\t\t  / _` |/ _` | | | |/ _` | | '_ \\ / _ \\/ __| __|                \n");
        printf("\t\t\t\t\t\t\t ( (_| | (_| | |_| | (_| | | | | |  __/\\__ \\ |_                 \n");
        printf("\t\t\t\t\t\t\t  \\__,_|\\__, |\\__,_|\\__,_| |_| |_|\\___||___/\\__|                \n");
        printf("\t\t\t\t\t\t\t           | |                                                  \n");
        printf("\t\t\t\t\t\t\t           |_|                                                  \n\n\n\n\n");

        printf("                __/___                         |    |    |                                                    |----.___\n");
        printf("          _____/______|                       )_)  )_)  )_)                                                          |----.___',\n");
        printf("  _______/_____\\_______\\_____              )___))___))___)\\                                        ._________________|_______________.\n");
        printf("  \\              O O O       |             )____)____)_____)\\\\                                     |####|    |####|    |####|   |####|\n");
        printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~        _____|____|____|____\\\\\__                                 |####|    |####|    |####|    |####|       .\n");
        printf("                                ---------\\                   /---------                              |####|    |####|    |####|    |####|     /|_____.\n");
        printf("                                    ~~~~~ ~~~~~~~~~~~~~~~~~~~~~                           __          |####|    |####|    |####|    |####|   |  o  ..|\n");
        printf("                                       ~~~~~      ~~~~~     ~~~~    ~~~                 (  '.         '####|    '####|    '####|    '####|   '.  .vvv'\n");
        printf("                                                                                         '@ |          |####.    |####.    |####.    |####|    ||\n");
        printf("                                                                                          | |          '####.    '####.    '####.    '####.    ||\n");
        printf("                                 o ooo                                                   /  |         /####.    /####.    /####.    /####.     |'.\n");
        printf("                                   o oo                                                 |    |       '####/    '####/    '####/    '####/      |  |\n");
        printf("                                    o o      |   #)                                     |     |  .  /####|____/####|____/####|____/####|      |    |\n");
        printf("                                     oo     _|_|_#_                                     |      |//   .#'#. .*'*. .#'#. .*'*. .#'#. .*'*.     |      |\n");
        printf("                                       o   | U505  |                                     |     //-...#'#'#-*'*'*-#'#'#-*'*'*-#'#'#-*'*'*-...'        |\n");
        printf("  __                    ___________________|       |_________________                     |   //     '#'#' '*'*' '#'#' '*'*' '#'#' '*'*'             |\n");
        printf(" |   -_______-----------                                             \\                     './/                                                     .'\n");
        printf(">|    _____                                                   --->     )                   _//'._                    VIKINGS                      _.'\n");
        printf(" |__ -     ---------_________________________________________________ /                   /__/   '----------------------------------------------'\n\n\n\n");

    }
void regole (void)
{
    system("cls");
    printf("  _____                  _                                                       _\n");
    printf(" |  __ \\                | |                                                     | |\n");
    printf(" | |__)|___   __ _  ___ | | ___         __ _  __ _ _   _  __ _   _ __   ___  ___| |_\n");
    printf(" |  _  / _ \\ / _` |/ _ \\| |/ _ \\       / _` |/ _` | | | |/ _` | | '_ \\ / _ \\/ __| __|\n");
    printf(" | | \\ \\  __/ (_| | (_) | |  __/      ( (_| | (_| | |_| | (_| | | | | |  __/\\__ \\ |_\n");
    printf(" |_|  \\_\\___|\\__, |\\___/|_|\\___|       \\__,_|\\__, |\\__,_|\\__,_| |_| |_|\\___||___/\\__|\n");
    printf("              __/ |                             | |\n");
    printf("             |___/                              |_|\n");

    printf("\n");
    printf("[-] Questo programma emula una battaglia tra player e cpu in stile <battaglia navale> \n\n");
    printf("[-] Il programma e' formato da 2 griglie che rappresentano i rispettivi campi di gioco\n\n");
    printf("[-] A loro volta le griglie sono formate da 9 righe e 9 colonne\n\n");
    printf("[-] In ogni griglia ci sono 27 navi ovvero un terzo del numero delle celle totali\n\n");
    printf("[-] Sara' possible sparare un colpo per turno \n\n");
    printf("[-] Inserendo coordinate gia' digitate precedentemente il turno sara' perso! :)\n\n");
    printf("                                 h elp                                      \n");
    printf("                                   h el                                         \n");
    printf("                                    h l      |   #)                             \n");
    printf("                                     he     _|_|_#_                             \n");
    printf("                                       h   | help  |                            \n");
    printf("  __                    ___________________|       |_________________           \n");
    printf(" |   -_______-----------                                               \\         \n");
    printf(">|    _____                     U505_HELP_MODE             help--->     )        \n");
    printf(" |__ -     ---------_________________________________________________ /         \n\n\n\n");
}
