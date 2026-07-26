#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 900
#define HEIGHT 600

#define NUMBARS 25

int bars[NUMBARS];


// Print the bars array to stdout, shows the index and value
void PrintBars(){
	for(int i = 0; i < NUMBARS; i++){
		printf("bars[%i] = %i\n", i, bars[i]);
	}
}


// Initialize bars array with values
void CreateBars(){
	for(int i = 0; i < NUMBARS; i++){
		bars[i] = i + 1;
	}
}


// Randomly shuffle the bars array using a generated index 
void ShuffleBars(){
	srand(time(NULL)); // seed the number generator using current times

	for(int i = NUMBARS - 1; i > 0; i--){
		int random_num = rand() % (i + 1); // generating random number between 0 and i
		
		// randomly swap 
		int temp = bars[i];
		bars[i] = bars[random_num];
		bars[random_num] = temp;
	}
}


// Scale the bars properly and draw them to the screen evenly distributed
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
    ShuffleBars();
    PrintBars(); 

    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();

	DrawBars();

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}
