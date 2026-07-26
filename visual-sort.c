#include "raylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 900
#define HEIGHT 600

#define NUMBARS 25

int bars[NUMBARS];

int sort_i = 0;
int sort_j = 0;
bool sorted = false;


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


// Swap two elements given indexes and an array
void Swap(int i, int j, int arr[]){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


// Randomly shuffle the bars array using a generated index 
void ShuffleBars(){
	srand(time(NULL)); // seed the number generator using current times

	for(int i = NUMBARS - 1; i > 0; i--){
		int random_num = rand() % (i + 1); // generating random number between 0 and i
		
		// randomly swap
		Swap(i, random_num, bars); 
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


// Perform a single step of the bubble sort algorithm
void BubbleSortStep(){
	if(sorted)
		return;

	// if current element is bigger than the next, bubble it up 
	if(bars[sort_j] > bars[sort_j + 1]){
		Swap(sort_j, sort_j + 1, bars);
	}	
	sort_j++;

	// check if sort_j is still within bounds of bars array
	if(sort_j >= NUMBARS - sort_i - 1){
		sort_j = 0;
		sort_i++;	

		// check if sorting is still necessary
		if(sort_i >= NUMBARS - 1){ // entire array has been checked and sorted 
			sorted = true;
		}
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
	BubbleSortStep();
	
        BeginDrawing();

	ClearBackground(BLACK);

	DrawBars();

        EndDrawing();
    }

    CloseWindow();        // Close window and OpenGL context
    return 0;
}
