#include <iostream>
#include <unistd.h>

/**
 *
 * Description:
 *          Program demonstrate the tower of hanoi puzzle game,
 *          with machine solver and an interactive mode.
 *
 * Original Author:    H.T.Phong
 * Created:   Jan 9, 2024
 *
 **/

#define MAX_SIZE 10
#define GAME_MODE true
#define DEBUG_MODE false

void drawDisk(int size, int maxSize)
{
    for (int i = 0; i < maxSize - size; i++)
    {
        std::cout << ' ';
    }
    std::cout << (size > 0 ? '[' : ' ');
    for (int i = 0; i < size; i++)
    {
        std::cout << '=';
    }
    std::cout << '|';
    for (int i = 0; i < size; i++)
    {
        std::cout << '=';
    }
    std::cout << (size > 0 ? ']' : ' ');
    for (int i = 0; i < maxSize - size; i++)
    {
        std::cout << ' ';
    }
}

void drawBase(int spacing, char label1, char label2, char label3, char filler)
{
    for (int i = 0; i < spacing + 1; i++)
    {
        std::cout << filler;
    }
    std::cout << label1;
    for (int i = 0; i < spacing * 2 + 3; i++)
    {
        std::cout << filler;
    }
    std::cout << label2;
    for (int i = 0; i < spacing * 2 + 3; i++)
    {
        std::cout << filler;
    }
    std::cout << label3;
    for (int i = 0; i < spacing + 1; i++)
    {
        std::cout << filler;
    }
}

void drawPos(int posData[3][MAX_SIZE], int disks)
{
#if !(DEBUG_MODE)
    system("cls");
#endif
    for (int col = disks - 1; col > -1; col--)
    {
        for (int row = 0; row < 3; row++)
        {
            drawDisk(posData[row][col], disks);
            std::cout << ' ';
        }
        std::cout << '\n';
    }
    drawBase(disks, 'A', 'B', 'C', '.');
    std::cout << '\n';
#if !(GAME_MODE)
    usleep(125000);
#endif
}

void moveDisk(int posData[3][MAX_SIZE], int disks, int from, int to)
{
#if !(GAME_MODE)
    int disk = 0;
    for (int i = 0; i < disks; i++)
    {
        if (posData[from][i] == 0)
        {
            posData[from][i]     = posData[from][i - 1];
            posData[from][i - 1] = 0;
            std::cout << '\n';
            drawPos(posData, disks);
        }
    }
    disk                     = posData[from][disks - 1];
    posData[from][disks - 1] = 0;
    std::cout << '\n';
    drawPos(posData, disks);
    posData[to][disks - 1] = disk;
    std::cout << '\n';
    drawPos(posData, disks);
    for (int i = disks - 1; i > -1; i--)
    {
        if (posData[to][i] == 0)
        {
            posData[to][i]     = posData[to][i + 1];
            posData[to][i + 1] = 0;
            std::cout << '\n';
            drawPos(posData, disks);
        }
    }
#else
    int i = disks - 1;
    for (; i > -1; i--)
    {
        if (posData[from][i] != 0)
            break;
    }
    int j = 0;
    for (; j < disks; j++)
    {
        if (posData[to][j] == 0)
            break;
    }
    posData[to][j]   = posData[from][i];
    posData[from][i] = 0;
#endif
}

bool validateMove(int posData[3][MAX_SIZE], int disks, int from, int to)
{
    if (from > 2 || from < 0)
        return false;
    if (to > 2 || to < 0)
        return false;
    int i = disks - 1;
    for (; i > 0; i--)
    {
        if (posData[from][i] != 0)
            break;
    }
    int j = disks - 1;
    for (; j > 0; j--)
    {
        if (posData[to][j] != 0)
            break;
    }
    // std::cout << posData[from][i] << " and " << posData[to][j] << '\n';
    if (posData[to][j] == 0)
        return true;
    if (posData[to][j] > posData[from][i])
        return true;
    else
        return false;
}

/*A is start, C is destination*/
void TowerOfHanoi(int posData[3][MAX_SIZE], int disks, int n, int A = 0, int B = 1, int C = 2)
{
    if (n > 0)
    {
        TowerOfHanoi(posData, disks, n - 1, A, C, B);
        moveDisk(posData, disks, A, C);
        TowerOfHanoi(posData, disks, n - 1, B, A, C);
    }
}

bool areYouWinningSon(int posData[3][MAX_SIZE], int disks)
{
    return (posData[0][0] == 0 && posData[1][0] == 0);
}

int main()
{
    int disks;
    do
    {
        std::cout << "Enter disks amount: ";
        std::cin >> disks;
    } while (disks < 1 || disks > MAX_SIZE);

    int posData[3][MAX_SIZE] = {};
    for (int i = 0; i < disks; i++)
        posData[0][i] = disks - i;

#if GAME_MODE
    while (!areYouWinningSon(posData, disks))
    {
        drawPos(posData, disks);
        std::cout << "[Goal]: move all disk from A to C.\n"
                  << "[Rules]: bigger disk cant be on smaller one.\n";
        char pegFrom;
        char pegTo;
        std::cout << "Choose a peg to move: ";
        std::cin >> pegFrom;
        std::cout << "Choose a peg to place: ";
        std::cin >> pegTo;
        if (validateMove(posData, disks, pegFrom - 'A', pegTo - 'A'))
        {
            moveDisk(posData, disks, pegFrom - 'A', pegTo - 'A');
        }
    }
    drawPos(posData, disks);
    std::cout << "        You did it !\n";
    std::cout << "      _______________\n     |@@@@|     |####|\n     |@@@@|     |####|\n     |@@@@|     |####|\n     "
                 "\\@@@@|     |####/\n      \\@@@|     |###/\n       `@@|_____|##'\n            (O)\n         "
                 ".-'''''-.\n       .'  * * *  `.\n      :  *       *  :\n     : ~ T O W E R ~ :\n     : ~    O F    ~ "
                 ":\n     : ~ H A N O I ~ :\n      :  *       *  :\n       `.  * * *  .'\n         `-.....-'\n";
    std::cout << "\n          -Credit-\n"
              << "   Programmer: H.T.Phong\n"
              << "Game Inventor: Edouard Lucas\n"
              << "    Medal art: joan g stark\n";
    std::cin.ignore();
#else
    drawPos(posData, disks);
    std::cin.ignore();
    std::cout << "Press enter to start...";
    std::cin.get();
    TowerOfHanoi(posData, disks, disks);
#endif
    std::cin.get();
    return 0;
}