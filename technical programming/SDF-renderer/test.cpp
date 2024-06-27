#include <Windows.h>
#include <conio.h>
#include <math.h>
#include <stdio.h>

LPCSTR                     shading = ".,-~:;=!*#$@";
DWORD                      _       = 1;
HANDLE                     conOut  = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE                     conIn   = GetStdHandle(STD_INPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
float                      lightVector[3] = {25.0f, 25.0f, 25.0f};
/*
#define INPUT_SIZE 64
INPUT_RECORD* inputBuffer[INPUT_SIZE];
*/

void draw(LPCSTR character, short x, short y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    WriteConsoleOutputCharacterA(conOut, character, 1, coordinates, &_);
};

float magnitude(float vector[])
{
    return sqrtf(vector[0] * vector[0] + vector[1] * vector[1] + vector[2] * vector[2]);
};

float normalizedDotProduct(float vector1[], float vector2[])
{
    return (vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2]) /
           (magnitude(vector1) * magnitude(vector2));
};

void drawCircle(float radius, float stretchX, float stretchY, float offsetX, float offsetY)
{
    for (int x = 1; x <= 2 * radius * stretchX; x++)
    {
        for (int y = 1; y <= 2 * radius * stretchY; y++)
        {
            float X =
                x - radius * stretchX; // The displacement of x by relation of the center of the circle's x coordinate
            float Y = y - radius * stretchY;
            if ((X * X / stretchX + Y * Y / stretchY) <= radius * radius)
            {
                draw("X", (x + offsetX), (y + offsetY));
            };
        };
    };
};

void drawLitSphere(float radius, float stretchX, float stretchY, float offsetX, float offsetY, float lightVector[])
{
    for (int x = 1; x <= 2 * radius * stretchX; x++)
    {
        for (int y = 1; y <= 2 * radius * stretchY; y++)
        {
            float X =
                x - radius * stretchX; // The displacement of x by relation of the center of the circle's x coordinate
            float Y             = y - radius * stretchY;
            float Z             = sqrtf(radius * radius - X * X - Y * Y);
            float vector[3]     = {X, Y, Z};
            int   lightingLevel = roundf(9.0f * normalizedDotProduct(vector, lightVector));
            if (lightingLevel >= 0)
            {
                draw(&shading[lightingLevel], x + offsetX, y + offsetY);
            };
        };
    };
};

int main()
{
    SetConsoleMode(conIn, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    BOOL         pressedKey = FALSE;
    int          INPUT_SIZE = 1;
    INPUT_RECORD inputBuffer;
    while (!pressedKey)
    {
        ReadConsoleInput(conIn, &inputBuffer, INPUT_SIZE, &_);
        if (inputBuffer.EventType == KEY_EVENT)
        {
            float lightMagnitude = magnitude(lightVector);
            float tempX          = lightVector[0];
            float tempY          = lightVector[1];
            WORD  input          = inputBuffer.Event.KeyEvent.wVirtualKeyCode;
            if (input == VK_LEFT)
            {
                lightVector[0] += -lightVector[2] / lightMagnitude;
                lightVector[2] += tempX / lightMagnitude;
            }
            else if (input == VK_RIGHT)
            {
                lightVector[0] += lightVector[2] / lightMagnitude;
                lightVector[2] += -tempX / lightMagnitude;
            }
            else if (input == VK_UP)
            {
                lightVector[1] += -lightVector[2] / lightMagnitude;
                lightVector[2] += tempY / lightMagnitude;
            }
            else if (input == VK_DOWN)
            {
                lightVector[1] += lightVector[2] / lightMagnitude;
                lightVector[2] += -tempY / lightMagnitude;
            }
            else if (input == 0x57)
            { // W key
                lightVector[0] *= 1.05f;
                lightVector[1] *= 1.05f;
                lightVector[2] *= 1.05f;
            }
            else if (input == 0x53)
            { // S key
                lightVector[0] *= 0.95f;
                lightVector[1] *= 0.95f;
                lightVector[2] *= 0.95f;
            }
            else if (input == VK_ESCAPE)
            {
                pressedKey = TRUE;
            };
            drawLitSphere(30.0, 1, 1, 10, 10, lightVector);
        };
    };
    return 0;
};