#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ttt.h"

// allocates space for a new board
// if successful, returns a pointer to a new board. otherwise returns a null pointer
static board_t* board_create(unsigned int size){
	board_t board = malloc(sizeof(board_t));
	if (!board)
		return NULL;
	
	unsigned int i = 0;

	board->data = malloc(size*sizeof(mark_t*);
	if (!board->data)
		goto fail;

	for (i; i < size; i++){
		board->data[i] = malloc(size*sizeof(mark_t));
		if(!board->data[i])
			goto fail;

	}

	fail:
	for (unsigned int j; j < i; j++)
		free(board->data[j]);
	free(board->data);
	free(board);

	return NULL;
}

// frees all memory associated with b
void board_destroy(board_t* b);

// sets every cell on the board to EMPTY
void board_clear(board_t* b);

// sets a mark for a cell at (x, y) 
void board_set(board_t* b, unsigned int x, unsigned int y, mark_t mark);

// if index is valid, return the mark at the cell (x, y)
mark_t board_get(board_t* b, unsigned int x, unsigned int y);


