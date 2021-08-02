#include <stdio.h>
#include <stdlib.h>

/*
Author: Usman Yousef
Date: 07/27/2021
Description: This is my first, primitive version of TicTacToe
Corrected function signatures, replaced 2D array with a 1D array, and corrected logic error in OTurn()
Looking to make final correction to proper displaying of the grid which seems "lagged" in output...
*/

int Check4Winner(int* pArray);
void XTurn(int* pArray);
void OTurn(int* pArray);
void InitializeGrid(int* pArray);
void DisplayGrid(int* pArray);
void DisplayResult(int win, int turnCount);

int main()
{
    //declarations
    int array [9];
    int turnCount = 0;
    int win = 0;

    InitializeGrid(array);

    while(win == 0 && turnCount < 9)
    {
        DisplayGrid(array);
        XTurn(array);
        ++turnCount;
        win = Check4Winner(array);

        if(win == 1)
        {
            break;
        }

        DisplayGrid(array);
        OTurn(array);
        ++turnCount;
        win = Check4Winner(array);
    }

    DisplayGrid(array);
    DisplayResult(win, turnCount);
    return 0;
}
//================================================================================================================================================================================================================
void XTurn (int* pArray)
{
    int num = 0;

    while(num < 2 || num > 10)
    {
        printf("\nPlease select a valid number...\n");
        scanf("%d \n", &num);
    }

    for(int x = 0; x < 9; x++)
    {
        if (num == pArray[x])
        {
            pArray[x] = 1;
        }
    }
}
//================================================================================================================================================================================================================
void OTurn (int* pArray)
{
    int num = 0;

    while(num < 2 || num > 10)
    {
        printf("\nPlease select a valid number...\n");
        scanf("%d \n", &num);
    }
    for(int x = 0; x < 9; x++)
    {
        if (num == pArray[x])
        {
            pArray[x] = 0;
        }
    }
}
//================================================================================================================================================================================================================
int Check4Winner(int* pArray)
{
    //O's winning conditions
    if(pArray[0] && pArray[1] && pArray[2] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[3] && pArray[4] && pArray[5] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[6] && pArray[7] && pArray[8] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[0] && pArray[3] && pArray[6] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[1] && pArray[4] && pArray[7] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[2] && pArray[5] && pArray[8] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[0] && pArray[4] && pArray[8] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }
    else if(pArray[6] && pArray[4] && pArray[2] == 0)
    {
        //printf("O WINS!!!\n");
        return 1;
    }

    //X's winning conditions
    if(pArray[0] && pArray[1] && pArray[2] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[3] && pArray[4] && pArray[5] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[6] && pArray[7] && pArray[8] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[0] && pArray[3] && pArray[6] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[1] && pArray[4] && pArray[7] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[2] && pArray[5] && pArray[8] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[0] && pArray[4] && pArray[8] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    else if(pArray[6] && pArray[4] && pArray[2] == 1)
    {
        //printf("X WINS!!!\n");
        return 1;
    }
    return 0;
}
//================================================================================================================================================================================================================
void DisplayGrid(int* pArray)
{
    int lineLimit = 0;
    for(int x = 0; x < 9; x++)
    {
        printf("%d  ", pArray[x]);
        lineLimit++;
        if(lineLimit == 3)
        {
            printf("\n");
            lineLimit = 0;
        }
    }
}
//================================================================================================================================================================================================================
void InitializeGrid(int* pArray)
{
    int i = 2;

    for(int x = 0; x < 9; x++)
    {
        pArray[x] = i;
        i++;
    }
}
//================================================================================================================================================================================================================
void DisplayResult(int win, int turnCount)
{
    if(turnCount % 2 == 0 && win == 1)
    {
        printf("O WINS!!!");
    }
    else if (turnCount % 2 != 0 && win == 1)
    {
        printf("X WINS!!!");
    }
    else
    {
        printf("Draw!");
    }
}
