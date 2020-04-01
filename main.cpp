#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>

int first_player_move(int [3][3]);
int second_player_move(int [3][3],int choice);
int check_result(int [3][3]);
int display(int [3][3]);

int main()
{
    int i,j,r=0,a[3][3],count=0,choice;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            a[i][j] = ' ';
        }
    }
    printf("...............................................BOARD WILL LOOK LIKE THIS................................................\n\n");
    display(a);
    printf("\n\n*****************************************************INSTRUCTIONS*******************************************************\n");
    printf("-> ENTER NUMBERS FOR PLACING MARKS (O/X)\n-> EACH PLAYER WILL ENTER (1/2/3/4/5/6/7/8/9) FOR THEIR RESPECTIVE MARKS ALTERNATIVELY\n\n");
    printf("************************************************************************************************************************\n\n\n\t\t\t\t\t\t");

    printf("player vs computer\n\t\t\t\t\t\t");
    printf("player vs player");
    scanf("%d",&choice);
    system("cls");

    switch(choice)
    {
    case 1:
        do
        {
            first_player_move(a);
            if((a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O') || (a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O') || (a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O') || (a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O') || (a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O') || (a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O') || (a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O') || (a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O'))
                goto check1;
            second_player_move(a,choice);
            check1:
            r = check_result(a);
            count++;
            if(count == 4)
                goto end;
        }while(r!=1 && r!=2);
        break;
    case 2:
        do
        {
            first_player_move(a);
            if((a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O') || (a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O') || (a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O') || (a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O') || (a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O') || (a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O') || (a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O') || (a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O'))
                goto check;
            second_player_move(a,choice);
            check:
            r = check_result(a);
            count++;
            if(count == 4)
                goto end;
        }while(r!=1 && r!=2);
        break;
    default:
        printf("Enter valid choice");
    }

    end:
        system("cls");
        display(a);
    if(r == 1)
       printf("\n\n\n\t\t\t\t\t\tPlayer 1 is winner!!!!!!!!\n\n\n\n");
    else if(r == 2)
       printf("\n\n\n\t\t\t\t\t\tPlayer 2 is winner!!!!!!!!\n\n\n\n");
    else if(r == 0)
        printf("\n\n\t\t\t\t\t\tDRAW\n");

    return 0;
}

/**********************************************************************************
                            MOVES(1st player/2nd player)
 *********************************************************************************/
int first_player_move(int x[3][3])
{
    int i,j,m=0,n=0,ip;
    P1:
        system("cls");
        display(x);
    printf("\nEnter position (O):");
    scanf("%d",&ip);
    if(ip==1)
    {
        m=0;
        n=0;
    }
    else if(ip==2)
    {
        m=0;
        n=1;
    }
    else if(ip==3)
    {
        m=0;
        n=2;
    }
    else if(ip==4)
    {
        m=1;
        n=0;
    }
    else if(ip==5)
    {
        m=1;
        n=1;
    }
    else if(ip==6)
    {
        m=1;
        n=2;
    }
    else if(ip==7)
    {
        m=2;
        n=0;
    }
    else if(ip==8)
    {
        m=2;
        n=1;
    }
    else if(ip==9)
    {
        m=2;
        n=2;
    }
    if(x[m][n]==' ')
    {
        x[m][n]='O';
    }
    else if(x[m][n]=='O' || x[m][n]=='X')
    {
        printf("\n\n-----------------------------------------------------INVALID MOVE-------------------------------------------------------\n\t\t\t\t\t\t      TRY AGAIN\n");
        goto P1;
    }
    display(x);
}

int second_player_move(int y[3][3],int choice)
{
    int i,j,r,m=0,n=0,ip;
    P1:
        system("cls");
        display(y);
    if(choice==1)
    {
        Sleep(1000);
        again:
        srand(time(0));
        ip = rand() % 9;
    }
    else{
        printf("\nEnter position (X):");
        scanf("%d",&ip);
    }

    if(ip==1)
    {
        m=0;
        n=0;
    }
    else if(ip==2)
    {
        m=0;
        n=1;
    }
    else if(ip==3)
    {
        m=0;
        n=2;
    }
    else if(ip==4)
    {
        m=1;
        n=0;
    }
    else if(ip==5)
    {
        m=1;
        n=1;
    }
    else if(ip==6)
    {
        m=1;
        n=2;
    }
    else if(ip==7)
    {
        m=2;
        n=0;
    }
    else if(ip==8)
    {
        m=2;
        n=1;
    }
    else if(ip==9)
    {
        m=2;
        n=2;
    }
    if(y[m][n]==' ')
    {
        y[m][n]='X';
    }
    else if(y[m][n]=='O' || y[m][n]=='X')
    {
        if(choice==1)
            goto again;
        else
        {
            printf("\n\n-----------------------------------------------------INVALID MOVE-------------------------------------------------------\n\t\t\t\t\t\t      TRY AGAIN\n");
            goto P1;
        }
    }
    system("cls");
    display(y);
}


/**********************************************************************************
                         CHECK FOR WIN(PLAYER 1/2)/DRAW
 *********************************************************************************/
int check_result(int a[3][3])
{
    int i,j;
       for(i=0; i<3; i++)
       {
           for(j=0; j<3; j++)
           {
                if(a[i][j]!=' ')
                {
                    if(a[0][0]=='O' || a[0][0]=='X')
                    {
                         if(a[0][0]==a[0][1] && a[0][1]==a[0][2])
                         {
                            if(a[0][0]=='O')
                                return 1;
                            else if(a[0][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[0][0]==a[1][0] && a[1][0]==a[2][0])
                         {
                            if(a[0][0]=='O')
                                return 1;
                            else if(a[0][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[0][0]==a[1][1] && a[1][1]==a[2][2])
                         {
                            if(a[0][0]=='O')
                                return 1;
                            else if(a[0][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[0][1]=='O' || a[0][1]=='X')
                    {
                         if(a[0][1]==a[0][0] && a[0][0]==a[0][2])
                         {
                            if(a[0][1]=='O')
                                return 1;
                            else if(a[0][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[0][1]==a[1][1] && a[1][1]==a[2][1])
                         {
                            if(a[0][1]=='O')
                                return 1;
                            else if(a[0][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[0][2]=='O' || a[0][2]=='X')
                    {
                         if(a[0][2]==a[0][1] && a[0][1]==a[0][0])
                         {
                            if(a[0][2]=='O')
                                return 1;
                            else if(a[0][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[0][2]==a[1][1] && a[1][1]==a[2][0])
                         {
                            if(a[0][2]=='O')
                                return 1;
                            else if(a[0][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[0][2]==a[1][2] && a[1][2]==a[2][2])
                         {
                            if(a[0][2]=='O')
                                return 1;
                            else if(a[0][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[1][0]=='O' || a[1][0]=='X')
                    {
                         if(a[1][0]==a[1][1] && a[1][1]==a[1][2])
                         {
                            if(a[1][0]=='O')
                                return 1;
                            else if(a[1][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[1][0]==a[0][0] && a[0][0]==a[2][0])
                         {
                            if(a[1][0]=='O')
                                return 1;
                            else if(a[1][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[1][1]=='O' || a[1][1]=='X')
                    {
                         if(a[1][1]==a[1][0] && a[1][0]==a[2][0])
                         {
                            if(a[1][1]=='O')
                                return 1;
                            else if(a[1][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[1][1]==a[0][1] && a[0][1]==a[2][1])
                         {
                            if(a[1][1]=='O')
                                return 1;
                            else if(a[1][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[1][1]==a[0][2] && a[0][2]==a[2][0])
                         {
                            if(a[1][1]=='O')
                                return 1;
                            else if(a[1][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[1][1]==a[0][0] && a[0][0]==a[2][2])
                         {
                            if(a[1][1]=='O')
                                return 1;
                            else if(a[1][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[1][2]=='O' || a[1][2]=='X')
                    {
                         if(a[1][2]==a[0][2] && a[0][2]==a[2][2])
                         {
                            if(a[1][2]=='O')
                                return 1;
                            else if(a[1][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[1][2]==a[1][1] && a[1][1]==a[1][0])
                         {
                            if(a[1][2]=='O')
                                return 1;
                            else if(a[1][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[2][0]=='O' || a[2][0]=='X')
                    {
                         if(a[2][0]==a[0][0] && a[0][0]==a[1][0])
                         {
                            if(a[2][0]=='O')
                                return 1;
                            else if(a[2][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[2][0]==a[2][1] && a[2][1]==a[2][2])
                         {
                            if(a[2][0]=='O')
                                return 1;
                            else if(a[2][0]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[2][1]=='O' || a[2][1]=='X')
                    {
                         if(a[2][1]==a[1][1] && a[1][1]==a[0][1])
                         {
                            if(a[2][1]=='O')
                                return 1;
                            else if(a[2][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[2][1]==a[2][0] && a[2][0]==a[2][2])
                         {
                            if(a[2][1]=='O')
                                return 1;
                            else if(a[2][1]=='X')
                                return 2;
                            else
                                return 0;
                         }
                    }
                    if(a[2][2]=='O' || a[2][2]=='X')
                    {
                         if(a[2][2]==a[2][1] && a[2][1]==a[2][0])
                         {
                            if(a[2][2]=='O')
                                return 1;
                            else if(a[2][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else if(a[2][2]==a[1][2] && a[1][2]==a[0][2])
                         {
                            if(a[2][2]=='O')
                                return 1;
                            else if(a[2][2]=='X')
                                return 2;
                            else
                                return 0;
                         }
                         else
                            return 0;
                    }
                }
           }
       }
}

/**********************************************************************************
               FUNCTION TO DRAW BOARD OF TIC TAC TOE WITH PLAYERS MARK
 *********************************************************************************/
int display(int p[3][3])
{
    printf("\n");
    int i,j;
    for(i=0; i<3; i++)
    {
        printf("     \t\t     ");
        for(j=0; j<3; j++)
        {
            printf("    \t  ");
            printf("%c\t",p[i][j]);
            if(j!=2)
                printf("     |     ");
        }
        if(i!=2)
            printf("\n\n\t\t\t     ---------------------------------------------------------\n\n");
    }
    printf("\n");
}
