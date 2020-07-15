// tic tac toe for 3ds :)!
// see ttt.c for actual tic tac toe implementation. main is only for the 3ds stuff
#include <citro2d.h>
#include "ttt.c"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240 // board is 240x240
#define SIDEBAR SCREEN_WIDTH-SCREEN_HEIGHT

static C2D_TextBuf staticTextBuf;
static C2D_Text txt_scores;

static int cpu_score;
static int p_score

static bool game

static void drawBoard(const u32 gridColor, const u32 barColor){
	// Draw the grid-lines on the right 
	 for (int row = 1; row < ROWS; row++) {
	    C2D_DrawRectangle(SIDEBAR, CELL_SIZE * row - GRID_WIDTH_HALF, 0,
		  SCREEN_HEIGHT-1, GRID_WIDTH, gridColor, gridColor, gridColor,gridColor);
	 }
	 for (int col = 1; col < COLS; ++col) {
		C2D_DrawRectangle(SIDEBAR+CELL_SIZE * col - GRID_WIDTH_HALF, 0, 0,
		  GRID_WIDTH, SCREEN_WIDTH-1, gridColor,gridColor,gridColor,gridColor);
	 }

	// Draw the sidebar on the left
	C2D_DrawRectSolid(0, 0, 0, SIDEBAR, SCREEN_HEIGHT, barColor);
}

static void drawSideText(void){
	C2D_DrawText(&txt_scores, 0, 8.0f, 8.0f, 0.0f, 0.5f, 0.5f);

}

int main(int argc, char* argv[]){
	// initialize graphics
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_TOP, NULL);
	
	printf("\x1b[16;20Hwelcome to tic tac toe...");
	printf("\x1b[1;0HTouch Screen position:");
	printf("\x1b[30;16Hpress START to exit.");

	// Create graphics screen on the bottom
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	// Create colors
	u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	//u32 clrRed   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
	u32 clrBlue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);

	// Create text buffer
	staticTextBuf = C2D_TextBufNew(128);
	C2D_TextParse(&txt_scores, staticTextBuf, "Thinking...");
	C2D_TextOptimize(&txt_scores);
	
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// Detect user input
		u32 kDown = hidKeysDown();
		if(kDown & KEY_START) break; //break and return to hbmenu
		

		// touch postion for DEBUGGING
		touchPosition touch;

		//Read the touch screen coordinates
		hidTouchRead(&touch);

		//Print the touch screen coordinates
		printf("\x1b[2;0H%03d; %03d", touch.px, touch.py);

		// Render the screen
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		{
			C2D_TargetClear(bottom, clrBlue);
			C2D_SceneBegin(bottom);

			drawBoard(clrWhite, clrGreen);
			drawSideText();
		}	

		C3D_FrameEnd(0);

	}

	// Deinitialize libraries
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
