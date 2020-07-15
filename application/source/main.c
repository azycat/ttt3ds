// tic tac toe for 3ds :)!
#include <citro2d.h>
#include <3ds.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define BOT_WIDTH 320
#define BOT_HEIGHT 240

#define LINE_WIDTH 3
#define PADDING 50

struct board{
	int **data;
	int size;	
};

int main(int argc, char **argv){
	// initialize libraries
	gfxInitDefault();
	C3D_Init(C3D_DEFAULT_CMDBUF_SIZE);
	C2D_Init(C2D_DEFAULT_MAX_OBJECTS);
	C2D_Prepare();
	consoleInit(GFX_TOP, NULL);
	
	printf("\x1b[16;20Hwelcome to tic tac toe...");

	printf("\x1b[30;16Hpress START to exit.");

	// Create graphics screen on the bottom
	C3D_RenderTarget* bottom = C2D_CreateScreenTarget(GFX_BOTTOM, GFX_LEFT);

	// Create colors
	u32 clrWhite = C2D_Color32(0xFF, 0xFF, 0xFF, 0xFF);
	u32 clrClear = C2D_Color32(0xFF, 0xD8, 0xB0, 0x68);
	//u32 clrGreen = C2D_Color32(0x00, 0xFF, 0x00, 0xFF);
	//u32 clrRed   = C2D_Color32(0xFF, 0x00, 0x00, 0xFF);
	//u32 clrBlue  = C2D_Color32(0x00, 0x00, 0xFF, 0xFF);
	
	// Main loop
	while (aptMainLoop())
	{
		hidScanInput();

		// Detect user input
		u32 kDown = hidKeysDown();
		if(kDown & KEY_START) break; //break and return to hbmenu

		// Render the screen
		C3D_FrameBegin(C3D_FRAME_SYNCDRAW);
		C2D_TargetClear(bottom, clrClear);
		C2D_SceneBegin(bottom);

		// Draw vertical lines for board
		C2D_DrawLine(BOT_WIDTH/4, PADDING,clrWhite, BOT_WIDTH/4, BOT_HEIGHT-PADDING, clrWhite, LINE_WIDTH, 0);
		C2D_DrawLine(BOT_WIDTH*(3/4), PADDING, clrWhite, BOT_WIDTH*(3/4), BOT_HEIGHT-PADDING, clrWhite, LINE_WIDTH, 0);

		// Draw horizontal lines for board
		// /
		C2D_DrawLine(PADDING, BOT_HEIGHT/4,clrWhite, BOT_WIDTH-PADDING, BOT_HEIGHT/4, clrWhite, LINE_WIDTH, 0);
		C2D_DrawLine(PADDING, BOT_HEIGHT*(3/4), clrWhite, BOT_WIDTH-PADDING, BOT_HEIGHT*(3/4), clrWhite, LINE_WIDTH, 0);


		C3D_FrameEnd(0);

	}

	// Deinitialize libraries
	C2D_Fini();
	C3D_Fini();
	gfxExit();
	return 0;
}
