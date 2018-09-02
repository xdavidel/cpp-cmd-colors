#include <Windows.h>
#include <stdio.h>

#define COLORED_TEXT "This is what the color looks like"
#define DEFAULT_CMD_COLOR 7

int main(int argc, char **argv)
{
    HANDLE hConsole;
    size_t colorNumber;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (argc > 1)
    {
        int colorNumber = atoi(argv[1]);
        if (colorNumber < 255 && colorNumber > 0)
        {
            SetConsoleTextAttribute(hConsole, colorNumber);
            printf("%3d  %s\n", colorNumber, COLORED_TEXT);

            SetConsoleTextAttribute(hConsole, DEFAULT_CMD_COLOR);
            return 0;
        }
    }

    // you can loop k higher to see more color choices
    for (colorNumber = 1; colorNumber < 255; colorNumber++)
    {
        SetConsoleTextAttribute(hConsole, colorNumber);
        printf("%3d  %s\n", colorNumber, COLORED_TEXT);
    }

    SetConsoleTextAttribute(hConsole, DEFAULT_CMD_COLOR);

    return 0;
}