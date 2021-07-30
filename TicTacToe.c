#include <stdio.h>
#include <stdlib.h>

/*
Author: Usman Yousef
Date: 07/27/2021
Description: This is my first, primitive version of Tic-Tac-Toe
*/

void Check4Winner();
void XTurn();
void OTurn();
void InitializeGrid();
void DisplayGrid();
void TestFunc();

int main()
{
    //declarations
    int array [3][3];
    int turnCount = 1;

    //printf("%d \n", array);
    //printf("%d \n", *array);
    InitializeGrid(array);
    DisplayGrid(array);

    while(turnCount < 10)
    {
        XTurn(array);
        turnCount++;
        DisplayGrid(array);
        Check4Winner(&turnCount, array);

        OTurn(array);
        turnCount++;
        DisplayGrid(array);
        Check4Winner(&turnCount, array);
    }
    return 0;
}
//================================================================================================================================================================================================================
void XTurn (int** pArray[])
{
    int num = 0;

    while(num < 2 || num > 10)
    {
        printf("\nPlease select a valid number...\n");
        scanf("%d \n", &num);
    }
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            if (num == pArray[x][y])
            {
                pArray[x][y] = 1;
            }
        }
    }
}
//================================================================================================================================================================================================================
void OTurn (int** pArray[])
{
    int num = 0;

    while(num < 2 || num > 10)
    {
        printf("\nPlease select a valid number...\n");
        scanf("%d \n", &num);
    }
    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            if (num == pArray[x][y])
            {
                pArray[x][y] = 0;
            }
        }
    }
}
//================================================================================================================================================================================================================
void Check4Winner(int turnCount, int** pArray[])
{
    int checkWin = 0;
    //O's winning conditions
    if(pArray[0][0] && pArray[0][1] && pArray[0][2] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][0] && pArray[1][0] && pArray[2][0] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[2][0] && pArray[2][1] && pArray[2][2] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][1] && pArray[1][1] && pArray[2][1] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][1] && pArray[1][1] && pArray[2][1] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][2] && pArray[1][2] && pArray[2][2] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[2][0] && pArray[1][1] && pArray[0][2] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][0] && pArray[1][1] && pArray[2][2] == 0)
    {
        printf("O WINS!!!");
        checkWin++;
        return 0;
    }

    //X's winning conditions
    if(pArray[0][0] && pArray[0][1] && pArray[0][2] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][0] && pArray[1][0] && pArray[2][0] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[2][0] && pArray[2][1] && pArray[2][2] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][1] && pArray[1][1] && pArray[2][1] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][1] && pArray[1][1] && pArray[2][1] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][2] && pArray[1][2] && pArray[2][2] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[2][0] && pArray[1][1] && pArray[0][2] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }
    else if(pArray[0][0] && pArray[1][1] && pArray[2][2] == 1)
    {
        printf("X WINS!!!");
        checkWin++;
        return 0;
    }

    if (checkWin == 0 && turnCount == 9)
    {
        printf("DRAW!!!");
        return 0;
    }
}
//================================================================================================================================================================================================================
void DisplayGrid(int** pArray[])
{
    for(int x = 0; x < 3; x++)
    {
        printf("\n");
        for(int y = 0; y < 3; y++)
        {
            printf("%d  ", pArray[x][y]);
        }
    }
}
//================================================================================================================================================================================================================
void InitializeGrid(int** pArray[])
{
    int i = 2;

    for(int x = 0; x < 3; x++)
    {
        for(int y = 0; y < 3; y++)
        {
            pArray[x][y] = i;
            i++;
        }
    }
}
//================================================================================================================================================================================================================
