#include <cmath>
#include <iostream>
#include <windows.h>

enum
{
    BLACK       = 0,
    DARKBLUE    = FOREGROUND_BLUE,
    DARKGREEN   = FOREGROUND_GREEN,
    DARKCYAN    = FOREGROUND_GREEN | FOREGROUND_BLUE,
    DARKRED     = FOREGROUND_RED,
    DARKMAGENTA = FOREGROUND_RED | FOREGROUND_BLUE,
    DARKYELLOW  = FOREGROUND_RED | FOREGROUND_GREEN,
    DARKGRAY    = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    GRAY        = FOREGROUND_INTENSITY,
    BLUE        = FOREGROUND_INTENSITY | FOREGROUND_BLUE,
    GREEN       = FOREGROUND_INTENSITY | FOREGROUND_GREEN,
    CYAN        = FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE,
    RED         = FOREGROUND_INTENSITY | FOREGROUND_RED,
    MAGENTA     = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_BLUE,
    YELLOW      = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN,
    WHITE       = FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
};

DWORD  _      = 1;
HANDLE conOut = GetStdHandle(STD_OUTPUT_HANDLE);
char   str[]  = {(char)176, (char)177, (char)178, (char)219, '\0'};
LPCSTR lpcstr = str;

void draw(LPCSTR character, short x, short y, WORD color = WHITE)
{
    COORD coordinates;
    coordinates.X  = x;
    coordinates.Y  = y;
    WORD attribute = color;
    WriteConsoleOutputAttribute(conOut, &attribute, 1, coordinates, &_);
    WriteConsoleOutputCharacterA(conOut, character, 1, coordinates, &_);
}

void drawPixel(int x, int y, float gradient)
{
    int charpos;
    if (gradient >= 0.75)
    {
        charpos = 0;
    }
    else if (gradient >= 0.5)
    {
        charpos = 1;
    }
    else if (gradient >= 0.25)
    {
        charpos = 2;
    }
    else
    {
        charpos = 3;
    }
    draw(&lpcstr[charpos], x, y);
}

// Bresenham's algorithm
void plotLine(int x0, int y0, int x1, int y1, WORD color = WHITE)
{
    int dx    = std::abs(x1 - x0);
    int sx    = x0 < x1 ? 1 : -1;
    int dy    = -std::abs(y1 - y0);
    int sy    = y0 < y1 ? 1 : -1;
    int error = dx + dy;

    while (true)
    {
        draw(&lpcstr[3], x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * error;
        if (e2 >= dy)
        {
            if (x0 == x1)
                break;
            error = error + dy;
            x0    = x0 + sx;
        }
        if (e2 <= dx)
        {
            if (y0 == y1)
                break;
            error = error + dx;
            y0    = y0 + sy;
        }
    }
}

void plotAALine(int x0, int y0, int x1, int y1)
{
    int steep = std::abs(y1 - y0) > std::abs(x1 - x0);
    if (steep)
    {
        std::swap(x0, y0);
        std::swap(x1, y1);
    }
    if (x0 > x1)
    {
        std::swap(x0, x1);
        std::swap(y0, y1);
    }
    float dx       = x1 - x0;
    float dy       = y1 - y0;
    float gradient = dy / dx;
    if (dx == 0.0)
        gradient = 1;
    int   xpxl1      = x0;
    int   xpxl2      = x1;
    float intersectY = y0;
    if (steep)
    {
        int x;
        for (x = xpxl1; x <= xpxl2; x++)
        {
            // pixel coverage is determined by fractional
            // part of y co-ordinate
            float gradient1 = intersectY - (int)intersectY;
            float gradient2 = 1 - gradient1;
            drawPixel((int)intersectY, x, gradient2);
            drawPixel((int)intersectY - 1, x, gradient1);
            intersectY += gradient;
        }
    }
    else
    {
        int x;
        for (x = xpxl1; x <= xpxl2; x++)
        {
            // pixel coverage is determined by fractional
            // part of y co-ordinate
            float gradient1 = intersectY - (int)intersectY;
            float gradient2 = 1 - gradient1;
            drawPixel(x, (int)intersectY, gradient2);
            drawPixel(x, (int)intersectY - 1, gradient1);
            intersectY += gradient;
        }
    }
}

void drawSquare(int x, int y, int a, WORD color = WHITE)
{
    plotLine(x, y, x + a, y, color);
    plotLine(x + a, y, x + a, y + a, color);
    plotLine(x + a, y + a, x, y + a, color);
    plotLine(x, y + a, x, y, color);
}

void drawTriangle(int x0, int y0, int x1, int y1, int x2, int y2, WORD color = WHITE)
{
    plotLine(x0, y0, x1, y1, color);
    plotLine(x1, y1, x2, y2, color);
    plotLine(x2, y2, x0, y0, color);
}

void sierpinski(int n, int x0, int y0, int x1, int y1, int x2, int y2, WORD color = WHITE)
{
    if (n == 0)
    {
        return drawTriangle(x0, y0, x1, y1, x2, y2, color);
    }
    else
    {
        sierpinski(n - 1, x0, y0, (x0 + x1) / 2, (y0 + y1) / 2, (x0 + x2) / 2, (y0 + y2) / 2, color);
        sierpinski(n - 1, x1, y1, (x1 + x0) / 2, (y1 + y0) / 2, (x1 + x2) / 2, (y1 + y2) / 2, color);
        sierpinski(n - 1, x2, y2, (x2 + x1) / 2, (y2 + y1) / 2, (x2 + x0) / 2, (y2 + y0) / 2, color);
    }
}

void minkowski(int n, int x, int y, int a, WORD color = WHITE)
{
    if (n == 0)
    {
        return drawSquare(x, y, a, color);
    }
    else
    {
        minkowski(n - 1, x, y, a / 3, color);
        minkowski(n - 1, x + 2 * a / 3, y, a / 3, color);
        minkowski(n - 1, x, y + 2 * a / 3, a / 3, color);
        minkowski(n - 1, x + 2 * a / 3, y + 2 * a / 3, a / 3, color);
        minkowski(n - 1, x + a / 3, y + a / 3, a / 3, color);
    }
}

int main()
{
    {
        system("cls");
        CONSOLE_FONT_INFOEX cfi;
        cfi.cbSize       = sizeof(cfi);
        cfi.nFont        = 0;
        cfi.dwFontSize.X = 1;
        cfi.dwFontSize.Y = 1;
        cfi.FontFamily   = FF_DONTCARE;
        cfi.FontWeight   = FW_NORMAL;
        std::wcscpy(cfi.FaceName, L"MS Gothic");
        SetCurrentConsoleFontEx(conOut, FALSE, &cfi);

        COORD coordinates;
        coordinates.X = 5000;
        coordinates.Y = 5000;
        SetConsoleScreenBufferSize(conOut, coordinates);
    }

    // for (int i = 0; i < 16; i++)
    // {
    //     double angle = (3.14 / 8) * i;
    //     plotLine(50, 50, 50 + 40 * cos(angle), 50 + 40 * sin(angle));
    // }

    minkowski(3, 100, 100, 100, RED);

    // sierpinski(4, 150, 50, 250, 200, 50, 200, YELLOW);

    std::cin.get();
    return 0;
}