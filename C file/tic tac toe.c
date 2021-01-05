#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
void display(char a[3][3])
{
    fflush(stdin);
    system("CLS");
    printf("\t\t\t\t-------------\n");
    printf("\t\t\t\t| %c | %c | %c |\n",a[0][0],a[0][1],a[0][2]);
    printf("\t\t\t\t-------------\n");
    printf("\t\t\t\t| %c | %c | %c |\n",a[1][0],a[1][1],a[1][2]);
    printf("\t\t\t\t-------------\n");
    printf("\t\t\t\t| %c | %c | %c |\n",a[2][0],a[2][1],a[2][2]);
    printf("\t\t\t\t-------------\n");
    fflush(stdin);
}
int check(char a[][3])
{
    if((a[0][0]==a[0][1] && a[0][1]==a[0][2]) || (a[1][0]==a[1][1] && a[1][1]==a[1][2]) || (a[2][0]==a[2][1] && a[2][1]==a[2][2]) || (a[0][0]==a[1][0] && a[1][0]==a[2][0]) || (a[0][1]==a[1][1] && a[1][1]==a[2][1]) || (a[0][2]==a[1][2] && a[1][2]==a[2][2]) || (a[0][0]==a[1][1] && a[1][1]==a[2][2]) || (a[0][2]==a[1][1] && a[1][1]==a[2][0]))
        return 0;
    else if(a[0][0]=='1' || a[0][1]=='2' || a[0][2]=='3' || a[1][0]=='4' || a[1][1]=='5' || a[1][2]=='6' || a[2][0]=='7' || a[2][1]=='8' || a[2][2]=='9')
        return -1;
    else
        return 1;
}
int position(char a[3][3],int x,char y)
{
    int i,j;
    if(x>=1 && x<=3)
    {
        i=0;
        j=x-1;
    }
    else if(x>=4 && x<=6)
    {
        i=1;
        j=x-4;
    }
    else if(x>=7 && x<=9)
    {
        i=2;
        j=x-7;
    }
    else
    {
        printf("Please enter a valid Index\n");
        getch();
        return 0;
    }
    a[i][j]=y;
    return 1;
}
void input1(char a[3][3],char p1[],char q)
{
    char x,y;
    while(1)
    {
        display(a);
        printf("\n\n%s\nEnter your choice: ",p1);
        scanf("%d",&x);
        y=position(a,x,q);
        if(y==0)
            continue;
        else if(y==1)
            break;
    }
}
void input2(char a[3][3],char p2[],char q)
{
    char x,y;
    while(1)
    {
        display(a);
        printf("\n\n%s\nEnter your choice: ",p2);
        scanf("%d",&x);
        y=position(a,x,q);
        if(y==0)
            continue;
        else if(y==1)
            break;
    }
}
void main()
{
    char p1[15],p2[15],c,a[3][3],x,w,choice;
    int i,j,n;
    while(1)
    {
        n=49;
        system("CLS");
        fflush(stdin);
        for(i=0;i<3;i++)
            for(j=0;j<3;j++)
                a[i][j]=(char)n++;
        printf("\t\t\t\t  WELCOME\n");
        printf("\t\t\t\t     to\n");
        printf("\t\t\t\tTIC TAC TOE\n");
        printf("\n\nEnter Player1 Name: ");
        gets(p1);
        printf("\nEnter Player2 Name: ");
        gets(p2);
        label:
        printf("\n%s: Choose your symbol from 'X' or 'O': ",p1);
        scanf("%c",&c);
        if(c=='x' || c=='X')
        {
            c='X';
            x='O';
        }
        else if(c=='o' || c=='O' || c=='0')
        {
            c='O';
            x='X';
        }
        else
        {
            printf("Please, Enter appropriate symbol\n");
            fflush(stdin);
            goto label;
        }
        while(1)
        {
            input1(a,p1,c);
            w=check(a);
            if(w==0)
            {
                display(a);
                printf("\n%s Wins",p1);
                break;
            }
            else if(w==1)
            {
                display(a);
                printf("\nDRAW");
                break;
            }
            input2(a,p2,x);
            w=check(a);
            if(w==0)
            {
                display(a);
                printf("\n%s Wins",p2);
                break;
            }
            else if(w==1)
            {
                display(a);
                printf("\nDRAW");
                break;
            }
        }
        getch();
        system("CLS");
        printf("\t\tDo you wish to play another round\n\t\tPress any key to CONTINUE\n\t\tIf not, press 'n or 'N' to EXIT\n\t\t");
        scanf("%c",&choice);
        if(choice=='n' || choice=='N')
            break;
    }
    system("CLS");
    printf("\t\tTHANKS FOR PLAYING");
    getch();
}
