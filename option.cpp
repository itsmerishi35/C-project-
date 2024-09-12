#include <raylib.h>
#include <iostream>
#include "menu.h"
#include "option.h"
#include "ping.h"

int option()
{
    int selectedOption = 0;
    const int numOptions = 2;

    const char *options[numOptions] = {"SinglePlayer", "Multiplayer"};

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(LIGHTGRAY);

        // Draw each option
        for (int i = 0; i < numOptions; i++)
        {
            Color color = (i == selectedOption) ? RED : BLACK; // Highlight selected option
            DrawText(options[i], GetScreenWidth() / 2 - MeasureText(options[i], 20) / 2, GetScreenHeight() / 2 + 40 * i - 10, 20, color);
        }

        // Handle input
        if (IsKeyPressed(KEY_DOWN))
        {
            selectedOption = (selectedOption + 1) % numOptions;
        }
        else if (IsKeyPressed(KEY_UP))
        {
            selectedOption = (selectedOption - 1 + numOptions) % numOptions;
        }


        // Handle Enter key
        if (IsKeyPressed(KEY_SPACE))
        {
            if (selectedOption == 0)
            {
                ping(false);
            }
            else if (selectedOption == 1)
            {
                ping(true);
            }
        }

        EndDrawing();
    }

    return 0;
}
