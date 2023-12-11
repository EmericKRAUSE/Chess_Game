#include "../includes/chess.h"

void	init_board(square board[8][8])
{
	int	y = 0;
	while (y < 8)
	{
		int	x = 0;
		while (x < 8)
		{
			board[y][x].piece_square.name_piece = ' ';
			char	col = 'a' + x;
			char	row = '8' - y;
			board[y][x].coordinates[0] = col;
			board[y][x].coordinates[1] = row;
			board[y][x].coordinates[2] = '\0';
			x++;
		}
		y++;
	}
}

void	display_board(square board[8][8])
{
	char coordinates_y[8] = {'1', '2', '3', '4', '5', '6', '7', '8'};
	char coordinates_x[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};
	int	y = 0;
	while (y < 8)
	{
		int x = 0;
		printf ("%c ",coordinates_y[7 - y]);
		while (x < 8)
		{
			if ((y - x) % 2 == 0)
				printf ("\033[47m %c \033[0m", board[y][x].piece_square.name_piece);
			else
				printf ("\033[40m %c \033[0m", board[y][x].piece_square.name_piece);
			x++;
		}
		printf("\n");
		y++;
	}
	int x = 0;
	printf ("  ");
	while (x < 8)
	{
		printf (" %c ",coordinates_x[x]);
		x++;
	}
	printf ("\n");
}

void	place_pieces(square board[8][8])
{
	char pieces[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
	int	y = 0;
	int x = 0;

	while(x < 8)
	{
		board[0][x].piece_square.name_piece = pieces[x];
		board[0][x].piece_square.color_piece = 'B';
		x++;
	}
	x = 0;
	while(x < 8)
	{
		board[7][x].piece_square.name_piece = pieces[x];
		board[7][x].piece_square.color_piece = 'W';
		x++;
	}
	x = 0;
	while (x < 8)
	{
		board[1][x].piece_square.name_piece = 'p';
		board[1][x].piece_square.color_piece = 'B';
		x++;
	}
	x = 0;
	while (x < 8)
	{
		board[6][x].piece_square.name_piece = 'p';
		board[6][x].piece_square.color_piece = 'W';
		x++;
	}
}

void	white_move(square board[8][8])
{
	int move;
	printf ("enter a move:");
	scanf("%d", &move);
	if (move == 1)
	{
		board[6][4].piece_square.name_piece = ' ';
		board[4][4].piece_square.name_piece = 'p';
	}
}

int main()
{
	square	board[8][8];
	init_board(board);
	place_pieces(board);
	display_board(board);
	while (1)
	{
		white_move(board);
		display_board(board);
	}

	return (0);
}

