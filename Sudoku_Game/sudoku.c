//============================= File Inclusion ================================//
#include<stdio.h>
#include <windows.h>
//========================= Function Declarations =============================//
static int sudoku_cheak_num_exist(int arr[][9],int* row,int* col,int* num);
static int sudoku_cheak_location(int arr[][9],int* row,int* col);
static int sudoku_end_game(int arr[][9],int row,int col);

/*********************** Windows displaying functions **************************/
void gotoxy(int x, int y)
{
    COORD CRD;
    CRD.X=x;
    CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

void setColor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
}
}

extern sudoku[9][9];
int Game_End = 1;   /**** restore game status ****/

int row;   //global row
int col;   //global col
char num;   //number entered

/****************************** flag musk *************************************/
static char flags[9][9]=   {1,1,0,1,1,1,1,1,1,
                            1,1,1,1,1,0,1,1,1,
                            1,1,1,1,0,1,1,1,1,
                            1,1,1,1,1,0,1,1,1,
                            1,0,1,1,1,1,1,1,1,
                            0,1,1,0,1,1,1,1,1,
                            1,1,1,1,1,1,1,1,1,
                            1,1,1,1,1,0,1,1,1,
                            1,0,1,1,1,1,1,1,1};

/************************* sudoku print function ******************************/

void sudoku_print(int arr[][9],int row,int col){
    /*
    int i,j;
    printf("\n\n");
    printf("+ --------- + --------- + --------- +\n");
    for(i=0;i<row;i++){
        if(i==3||i==6){
           printf("+ --------- + --------- + --------- +\n");
        }

        for(j=0;j<col;j++){
            printf("| %c ",arr[i][j]);
        }
        printf("|\n");
    }
    printf("+ --------- + --------- + --------- +\n");
    printf("\n");*/

    int i,j;
    setColor(11);
printf("\n\n");
printf("                                       + --------- + --------- + --------- +\n");
    for(i=0; i<row; i++)
    {
        printf("                                       ");
        for(j=0; j<col; j++)
        {
            if(arr[i][j]==' ')
            {
                setColor(11);
                printf("| %c ",arr[i][j]);
            }
            else
            {
                setColor(11);
                printf("|");
                setColor(6);
                if(flags[i][j]==0){
                  setColor(4);
                }
                printf("%2c ", arr[i][j]);

            }

            if(j==8)
            {
                setColor(11);
                printf("|");
            }
        }
 if(i==0||i==1||i==3||i==4||i==6||i==7)
        {
            printf("\n");
        }
        printf("\n");
        if(i==2||i==5)
        {
            setColor(11);
            printf("                                       + --------- + --------- + --------- +\n");
        }
    }
    setColor(11);
printf("                                       + --------- + --------- + --------- +\n");
}


/******************************** main function ******************************/
void sudoku_game(void){
    sudoku_print(sudoku,9,9);
    /*Enter Number To Add It In The Array*/
    printf("Enter number:\n");
    scanf(" %c",&num);
    printf("\nEnter row then col:\n");
    scanf("%d%d",&row,&col);


    /*Call Function sudoku_cheak_location*/
    int legal = sudoku_cheak_location(sudoku,&row,&col);
    if(legal == 1){
    /*legal location*/
        /*Call Function sudoku_cheak_num_exist*/
        int exist = sudoku_cheak_num_exist(sudoku,&row,&col,&num);
        if(exist == 1){
            /*number not found*/
            sudoku[row][col] = num;
            printf("\n");
            setColor(11);
            printf("============================\n");
            setColor(2);
            printf("number is added successfully\n");
            setColor(11);
            printf("============================\n");
            Game_End = sudoku_end_game(sudoku,9,9);
            if(Game_End == 0){
              sudoku_print(sudoku,9,9);
            }
        }
        else{
            /*number found*/
            printf("\n");
            setColor(11);
            printf("===================================\n");
            setColor(4);
            printf("number is found in this row and col\n");
            setColor(11);
            printf("===================================\n");
        }

    }
    else{
        /*illegal location*/
        printf("\n");
        setColor(11);
        printf("===============================================================\n");
        setColor(4);
        printf("you can not add a number in this location its illigal operation\n");
        setColor(11);
        printf("===============================================================\n");

    }

}
/******************************************************************************/
/*this function return num is exist(-1) or not(1)*/
/******************************************************************************/

 static int sudoku_cheak_num_exist(int arr[][9],int* row,int* col,int* num){
  int i,j;
  int r = *row;
  int c = *col;
  int n = *num;

   //search num in row
   for(j=0;j<9;j++){
    if(arr[r][j]== n){
        return -1;
    }
   }
   //search num in col
   for(i=0;i<9;i++){
    if(arr[i][c]== n){
        return -1;
    }
   }
   return 1;
}


/******************************************************************************/
/*this function return location is legal(1) or illigal(-1)*/
/******************************************************************************/
 static int sudoku_cheak_location(int arr[][9],int* row,int* col){
    int r = *row;
    int c = *col;
    if(flags[r][c]== 0){
       return 1;
    }
    else{
       return -1;
    }
}
/******************************************************************************/
/*if game ended function return 0 if game not ended function return 1*/
/******************************************************************************/
static int sudoku_end_game(int arr[][9],int row,int col){
    int i,j,zero_counter=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(arr[i][j] == ' '){
                zero_counter++ ;
            }
        }
    }
    if(zero_counter == 0){
       return 0;
    }
    else{
        return 1;
    }
}
/******************************************************************************/



































