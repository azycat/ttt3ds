#define CELL_SIZE 80 
#define ROWS 3
#define COLS 3
#define GRID_WIDTH 6 
#define GRID_WIDTH_HALF GRID_WIDTH/2

// enumerations for the game state
typedef enum{
	PLAYING,
	TIE,
	X_WIN,
	O_WIN
}gamestate_t;

// enumerations for the marks that each cell in the grid can have
typedef enum{
	EMPTY,
	X_,
	O_,
}mark_t;

// structure type that contains all the data of the board
typedef struct{
	gamestate_t** data;
	unsigned int size;
}board_t;

// allocates space for a new board
static board_t* board_create(unsigned int size);

// frees all memory associated with b
void board_destroy(board_t* b);

// sets every cell on the board to EMPTY
void board_clear(board_t* b);

// sets a mark for a cell at (x, y) 
void board_set(board_t* b, unsigned int x, unsigned int y, mark_t mark);

// if index is valid, return the mark at the cell (x, y)
mark_t board_get(board_t* b, unsigned int x, unsigned int y);


