#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 900
#define HEIGHT 600

#define NUMBARS 10

int bars[NUMBARS];

// Initialize bars array with values
void CreateBars(){
	for(int i = 0; i < NUMBARS; i++){
		bars[i] = i + 1;
		//printf("bars[%i] = %i\n", i, bars[i]);
	}	
}

// Scale the bars properly and draw them to the screen evenly distributed in the screen
void DrawBars(){
	for(int i = 0; i < NUMBARS; i++){
		int bar_height_scaled = bars[i]*HEIGHT*0.75/NUMBARS;	
		int bar_width_scaled = WIDTH/NUMBARS - 5; 
		int x = ((float) i/NUMBARS)*WIDTH;
		int y = HEIGHT*0.8 - bar_height_scaled;

		DrawRectangle(x, y, bar_width_scaled, bar_height_scaled, WHITE);
	}
}


int main(void)
{

    InitWindow(WIDTH, HEIGHT, "Visual Sort");

    SetTargetFPS(30);               

    CreateBars();		    	 

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

	DrawBars();

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}
