#ifndef CHESS_H
# define CHESS_H
#include <stdio.h>

typedef struct piece
{
	char	name_piece;
	char	color_piece;
} 			piece;

typedef struct square
{
	piece	piece_square;
	char	coordinates[3];
}			square;

#endif