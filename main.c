#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "system.h"
#include "alt_types.h"
#include "altera_up_avalon_video_pixel_buffer_dma.h"
#include "altera_avalon_pio_regs.h"
#include "COLOR_08.h"
#include "letters.h"



void Delay_Loading () {int d = 0; for (d = 0; d <  5000000; d++);}
void Delay_Long    () {int d = 0; for (d = 0; d <   500000; d++);}
void Delay_Medium  () {int d = 0; for (d = 0; d <   150000; d++);}
void Delay_Short   () {int d = 0; for (d = 0; d <     5000; d++);}

void draw(int dd[24][16], int color, int x_offset, int y_offset){

	alt_up_pixel_buffer_dma_dev* hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

	int vertical, horizontal;

	for (vertical=0; vertical<24; vertical++){

		for (horizontal=0; horizontal<16; horizontal++)
			{
				if (dd[vertical][horizontal] > 0)
					{
						alt_up_pixel_buffer_dma_draw (hPB, color, horizontal+x_offset*16, vertical+y_offset*24);
					}
			}
	}
}
void draw1(int dd_bb[24][16], int color, int x_offset, int y_offset){
	alt_up_pixel_buffer_dma_dev* hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

	int vert;
	int hori;

	for (vert=0; vert<24; vert++){

		for (hori=0; hori<16; hori++)
			{
				if (dd_bb[vert][hori] <= 0)
					{
						alt_up_pixel_buffer_dma_draw (hPB, color, hori+x_offset*16, vert+y_offset*24);
					}
			}
	}
}

int main (){

	int x, y;

	alt_up_pixel_buffer_dma_dev* hPB = alt_up_pixel_buffer_dma_open_dev (VGA_PIXEL_DMA_NAME);

		if (hPB == NULL){
			printf ("No VGA system in present\n");
			while (1);
		}
		else{
			alt_up_pixel_buffer_dma_clear_screen (hPB, 0);
			alt_up_pixel_buffer_dma_clear_screen (hPB, 1);
    }

	Delay_Long ();

	srand (IORD_ALTERA_AVALON_PIO_DATA (SWITCH_BASE));

	draw(dd_J, COLOR08_BLUE, 0, 0);
	draw(dd_W, COLOR08_BLUE, 1, 0);
	draw(dd_U, COLOR08_BLUE, 2, 0);

	draw(dd_E, COLOR08_WHITE, 4, 0);
	draw(dd_N, COLOR08_WHITE, 5, 0);
	draw(dd_G, COLOR08_WHITE, 6, 0);
	draw(dd_N, COLOR08_WHITE, 7, 0);
	draw(dd_TWO, COLOR08_WHITE, 8, 0);
	draw(dd_ZERO, COLOR08_WHITE, 9, 0);
	draw(dd_EIGHT, COLOR08_WHITE, 10, 0);
	draw(dd_FIVE, COLOR08_WHITE, 11, 0);

	draw(dd_G, COLOR08_GREEN, 13, 0);
	draw(dd_D, COLOR08_GREEN, 14, 0);

	draw(dd_ZERO, COLOR08_GOLD, 16, 0);
	draw(dd_ZERO, COLOR08_GOLD, 17, 0);
	draw(dd_ZERO, COLOR08_GOLD, 18, 0);
	draw(dd_ZERO, COLOR08_GOLD, 19, 0);

	draw(dd_R, COLOR08_MAGENTA , 0, 1);
	draw(dd_E, COLOR08_MAGENTA , 1, 1);
	draw(dd_V, COLOR08_MAGENTA , 2, 1);
	draw(dd_TWO, COLOR08_MAGENTA , 3, 1);
	draw(dd_FOUR, COLOR08_MAGENTA , 4, 1);

	draw(dd_A, COLOR08_RED, 6, 1);
	draw(dd_P, COLOR08_RED, 7, 1);
	draw(dd_P, COLOR08_RED, 8, 1);
	draw(dd_SIX, COLOR08_RED, 9, 1);


	int num;
	int gameboard [8][20]={
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
			{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	};


	for (y=2; y<10; y++){

		for (x=0; x<20; x++)
		{

			num = rand()%10;
			gameboard [y-2][x] =num;


			if (num == 0){

				draw(dd_ZERO, COLOR08_YELLOW, x, y);
			}
			if (num == 1)
			{
				draw(dd_ONE, COLOR08_ORANGE, x, y);
			}
			if (num == 2){

				draw(dd_TWO, COLOR08_MAGENTA, x, y);
			}
			if (num == 3){
				draw(dd_THREE, COLOR08_WHITE, x, y);
			}
			if (num == 4){
				draw(dd_FOUR, COLOR08_GREEN, x, y);
			}
			if (num == 5)
			{
				draw(dd_FIVE, COLOR08_MAROOM, x, y);
			}
			if (num == 6)
			{
				draw(dd_SIX, COLOR08_PALEGREEN, x, y);
			}
			if (num == 7)
			{
				draw(dd_SEVEN, COLOR08_CRIMSON, x, y);
			}
			if (num == 8)
			{
				draw(dd_EIGHT, COLOR08_AQUAMARINE, x, y);
			}
			if (num == 9)
			{
				draw(dd_NINE, COLOR08_GRAY, x, y);
			}
		}
	}

	//finding matches///////////////////////////////////////////////////////////////////

	int count=0;
	int q=10;
	int f;

	for(count=0;count!=q;f++){
		q=count;
		for(x=0;x<18;x++){
			for(y=0;y<8;y++){
				if (gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2])
				{
					draw(dd_box,COLOR08_WHITE,x,y+2);
					draw(dd_box,COLOR08_WHITE,x+1,y+2);
					draw(dd_box,COLOR08_WHITE,x+2,y+2);
					count++;
				}
			}
		}

	for(x=0;x<20;x++){
		for(y=0;y<6;y++){
			if (gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x])
			{
				draw(dd_box,COLOR08_WHITE,x,y+2);
				draw(dd_box,COLOR08_WHITE,x,y+3);
				draw(dd_box,COLOR08_WHITE,x,y+4);
				count++;
			}
		}
	}
	for(x=0;x<18;x++){
		for(y=0;y<6;y++){
			if (gameboard [y][x]==gameboard [y+1][x+1] && gameboard [y+1][x+1]== gameboard [y+2][x+2])
			{
				draw(dd_box,COLOR08_WHITE,x,y+2);
				draw(dd_box,COLOR08_WHITE,x+1,y+3);
				draw(dd_box,COLOR08_WHITE,x+2,y+4);
				count++;
			}
		}
	}
	for(x=2;x<20;x++){
		for(y=0;y<6;y++){
			if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard [y+1][x-1]== gameboard [y+2][x-2])
			{
				draw(dd_box,COLOR08_WHITE,x,y+2);
				draw(dd_box,COLOR08_WHITE,x-1,y+3);
				draw(dd_box,COLOR08_WHITE,x-2,y+4);
				count++;
			}
		}
	}
	Delay_Long ();

	for(x=0;x<18;x++){
		for(y=0;y<8;y++){
			if (gameboard [y][x]==gameboard [y][x+1] && gameboard [y][x+1]== gameboard [y][x+2])
			{
				if(gameboard [y][x]== 0)
				{

					draw(dd_ZERO,COLOR08_BLACK,x,y+2);
					draw1(dd_ZERO,COLOR08_WHITE,x,y+2);
					draw(dd_ZERO,COLOR08_BLACK,x+1,y+2);
					draw1(dd_ZERO,COLOR08_WHITE,x+1,y+2);
					draw(dd_ZERO,COLOR08_BLACK,x+2,y+2);
					draw1(dd_ZERO,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 1)
				{

					draw(dd_ONE,COLOR08_BLACK,x,y+2);
					draw1(dd_ONE,COLOR08_WHITE,x,y+2);
					draw(dd_ONE,COLOR08_BLACK,x+1,y+2);
					draw1(dd_ONE,COLOR08_WHITE,x+1,y+2);
					draw(dd_ONE,COLOR08_BLACK,x+2,y+2);
					draw1(dd_ONE,COLOR08_WHITE,x+2,y+2);
				}
				if(gameboard [y][x]== 2)
				{

					draw(dd_TWO,COLOR08_BLACK,x,y+2);
					draw1(dd_TWO,COLOR08_WHITE,x,y+2);
					draw(dd_TWO,COLOR08_BLACK,x+1,y+2);
					draw1(dd_TWO,COLOR08_WHITE,x+1,y+2);
					draw(dd_TWO,COLOR08_BLACK,x+2,y+2);
					draw1(dd_TWO,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 3)
				{
					draw(dd_THREE,COLOR08_BLACK,x,y+2);
					draw1(dd_THREE,COLOR08_WHITE,x,y+2);
					draw(dd_THREE,COLOR08_BLACK,x+1,y+2);
					draw1(dd_THREE,COLOR08_WHITE,x+1,y+2);
					draw(dd_THREE,COLOR08_BLACK,x+2,y+2);
					draw1(dd_THREE,COLOR08_WHITE,x+2,y+2);
				}
				if(gameboard [y][x]== 4)
				{

					draw(dd_FOUR,COLOR08_BLACK,x,y+2);
					draw1(dd_FOUR,COLOR08_WHITE,x,y+2);
					draw(dd_FOUR,COLOR08_BLACK,x+1,y+2);
					draw1(dd_FOUR,COLOR08_WHITE,x+1,y+2);
					draw(dd_FOUR,COLOR08_BLACK,x+2,y+2);
					draw1(dd_FOUR,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 5)
				{

					draw(dd_FIVE,COLOR08_BLACK,x,y+2);
					draw1(dd_FIVE,COLOR08_WHITE,x,y+2);
					draw(dd_FIVE,COLOR08_BLACK,x+1,y+2);
					draw1(dd_FIVE,COLOR08_WHITE,x+1,y+2);
					draw(dd_FIVE,COLOR08_BLACK,x+2,y+2);
					draw1(dd_FIVE,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 6)
				{

					draw(dd_SIX,COLOR08_BLACK,x,y+2);
					draw1(dd_SIX,COLOR08_WHITE,x,y+2);
					draw(dd_SIX,COLOR08_BLACK,x+1,y+2);
					draw1(dd_SIX,COLOR08_WHITE,x+1,y+2);
					draw(dd_SIX,COLOR08_BLACK,x+2,y+2);
					draw1(dd_SIX,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 7)
				{

					draw(dd_SEVEN,COLOR08_BLACK,x,y+2);
					draw1(dd_SEVEN,COLOR08_WHITE,x,y+2);
					draw(dd_SEVEN,COLOR08_BLACK,x+1,y+2);
					draw1(dd_SEVEN,COLOR08_WHITE,x+1,y+2);
					draw(dd_SEVEN,COLOR08_BLACK,x+2,y+2);
					draw1(dd_SEVEN,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 8)
				{

					draw(dd_EIGHT,COLOR08_BLACK,x,y+2);
					draw1(dd_EIGHT,COLOR08_WHITE,x,y+2);
					draw(dd_EIGHT,COLOR08_BLACK,x+1,y+2);
					draw1(dd_EIGHT,COLOR08_WHITE,x+1,y+2);
					draw(dd_EIGHT,COLOR08_BLACK,x+2,y+2);
					draw1(dd_EIGHT,COLOR08_WHITE,x+2,y+2);

				}
				if(gameboard [y][x]== 9)
				{

					draw(dd_NINE,COLOR08_BLACK,x,y+2);
					draw1(dd_NINE,COLOR08_WHITE,x,y+2);
					draw(dd_NINE,COLOR08_BLACK,x+1,y+2);
					draw1(dd_NINE,COLOR08_WHITE,x+1,y+2);
					draw(dd_NINE,COLOR08_BLACK,x+2,y+2);
					draw1(dd_NINE,COLOR08_WHITE,x+2,y+2);
				}
			}
		}
	}

	for(x=0;x<20;x++){

		for(y=0;y<6;y++){
			if (gameboard [y][x]==gameboard [y+1][x] && gameboard [y+1][x]== gameboard [y+2][x])
			{

				if(gameboard [y][x]== 0)
				{

					draw(dd_ZERO,COLOR08_BLACK,x,y+2);
					draw1(dd_ZERO,COLOR08_WHITE,x,y+2);
					draw(dd_ZERO,COLOR08_BLACK,x,y+3);
					draw1(dd_ZERO,COLOR08_WHITE,x,y+3);
					draw(dd_ZERO,COLOR08_BLACK,x,y+4);
					draw1(dd_ZERO,COLOR08_WHITE,x,y+4);
				}
				if(gameboard [y][x]== 1)
				{

					draw(dd_ONE,COLOR08_BLACK,x,y+2);
					draw1(dd_ONE,COLOR08_WHITE,x,y+2);
					draw(dd_ONE,COLOR08_BLACK,x,y+3);
					draw1(dd_ONE,COLOR08_WHITE,x,y+3);
					draw(dd_ONE,COLOR08_BLACK,x,y+4);
					draw1(dd_ONE,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 2)
				{

					draw(dd_TWO,COLOR08_BLACK,x,y+2);
					draw1(dd_TWO,COLOR08_WHITE,x,y+2);
					draw(dd_TWO,COLOR08_BLACK,x,y+3);
					draw1(dd_TWO,COLOR08_WHITE,x,y+3);
					draw(dd_TWO,COLOR08_BLACK,x,y+4);
					draw1(dd_TWO,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 3)
				{

					draw(dd_THREE,COLOR08_BLACK,x,y+2);
					draw1(dd_THREE,COLOR08_WHITE,x,y+2);
					draw(dd_THREE,COLOR08_BLACK,x,y+3);
					draw1(dd_THREE,COLOR08_WHITE,x,y+3);
					draw(dd_THREE,COLOR08_BLACK,x,y+4);
					draw1(dd_THREE,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 4)
				{

					draw(dd_FOUR,COLOR08_BLACK,x,y+2);
					draw1(dd_FOUR,COLOR08_WHITE,x,y+2);
					draw(dd_FOUR,COLOR08_BLACK,x,y+3);
					draw1(dd_FOUR,COLOR08_WHITE,x,y+3);
					draw(dd_FOUR,COLOR08_BLACK,x,y+4);
					draw1(dd_FOUR,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 5)
				{

					draw(dd_FIVE,COLOR08_BLACK,x,y+2);
					draw1(dd_FIVE,COLOR08_WHITE,x,y+2);
					draw(dd_FIVE,COLOR08_BLACK,x,y+3);
					draw1(dd_FIVE,COLOR08_WHITE,x,y+3);
					draw(dd_FIVE,COLOR08_BLACK,x,y+4);
					draw1(dd_FIVE,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 6)
				{

					draw(dd_SIX,COLOR08_BLACK,x,y+2);
					draw1(dd_SIX,COLOR08_WHITE,x,y+2);
					draw(dd_SIX,COLOR08_BLACK,x,y+3);
					draw1(dd_SIX,COLOR08_WHITE,x,y+3);
					draw(dd_SIX,COLOR08_BLACK,x,y+4);
					draw1(dd_SIX,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 7)
				{

					draw(dd_SEVEN,COLOR08_BLACK,x,y+2);
					draw1(dd_SEVEN,COLOR08_WHITE,x,y+2);
					draw(dd_SEVEN,COLOR08_BLACK,x,y+3);
					draw1(dd_SEVEN,COLOR08_WHITE,x,y+3);
					draw(dd_SEVEN,COLOR08_BLACK,x,y+4);
					draw1(dd_SEVEN,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 8)
				{

					draw(dd_EIGHT,COLOR08_BLACK,x,y+2);
					draw1(dd_EIGHT,COLOR08_WHITE,x,y+2);
					draw(dd_EIGHT,COLOR08_BLACK,x,y+3);
					draw1(dd_EIGHT,COLOR08_WHITE,x,y+3);
					draw(dd_EIGHT,COLOR08_BLACK,x,y+4);
					draw1(dd_EIGHT,COLOR08_WHITE,x,y+4);

				}
				if(gameboard [y][x]== 9)
				{

					draw(dd_NINE,COLOR08_BLACK,x,y+2);
					draw1(dd_NINE,COLOR08_WHITE,x,y+2);
					draw(dd_NINE,COLOR08_BLACK,x,y+3);
					draw1(dd_NINE,COLOR08_WHITE,x,y+3);
					draw(dd_NINE,COLOR08_BLACK,x,y+4);
					draw1(dd_NINE,COLOR08_WHITE,x,y+4);
				}
			}
		}
	}
	for(x=0;x<18;x++){
		for(y=0;y<6;y++){
			if (gameboard [y][x]==gameboard [y+1][x+1] && gameboard [y+1][x+1]== gameboard [y+2][x+2])
				{
					if(gameboard[y][x]==0)
					{
						draw(dd_ZERO,COLOR08_BLACK,x,y+2);
						draw1(dd_ZERO,COLOR08_WHITE,x,y+2);
						draw(dd_ZERO,COLOR08_BLACK,x+1,y+3);
						draw1(dd_ZERO,COLOR08_WHITE,x+1,y+3);
						draw(dd_ZERO,COLOR08_BLACK,x+2,y+4);
						draw1(dd_ZERO,COLOR08_WHITE,x+2,y+4);
					}

					if(gameboard[y][x]==1)
					{
						draw(dd_ONE,COLOR08_BLACK,x,y+2);
						draw1(dd_ONE,COLOR08_WHITE,x,y+2);
						draw(dd_ONE,COLOR08_BLACK,x+1,y+3);
						draw1(dd_ONE,COLOR08_WHITE,x+1,y+3);
						draw(dd_ONE,COLOR08_BLACK,x+2,y+4);
						draw1(dd_ONE,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==2)
					{
						draw(dd_TWO,COLOR08_BLACK,x,y+2);
						draw1(dd_TWO,COLOR08_WHITE,x,y+2);
						draw(dd_TWO,COLOR08_BLACK,x+1,y+3);
						draw1(dd_TWO,COLOR08_WHITE,x+1,y+3);
						draw(dd_TWO,COLOR08_BLACK,x+2,y+4);
						draw1(dd_TWO,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==3)
					{
						draw(dd_THREE,COLOR08_BLACK,x,y+2);
						draw1(dd_THREE,COLOR08_WHITE,x,y+2);
						draw(dd_THREE,COLOR08_BLACK,x+1,y+3);
						draw1(dd_THREE,COLOR08_WHITE,x+1,y+3);
						draw(dd_THREE,COLOR08_BLACK,x+2,y+4);
						draw1(dd_THREE,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==4)
					{
						draw(dd_FOUR,COLOR08_BLACK,x,y+2);
						draw1(dd_FOUR,COLOR08_WHITE,x,y+2);
						draw(dd_FOUR,COLOR08_BLACK,x+1,y+3);
						draw1(dd_FOUR,COLOR08_WHITE,x+1,y+3);
						draw(dd_FOUR,COLOR08_BLACK,x+2,y+4);
						draw1(dd_FOUR,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==5)
					{
						draw(dd_FIVE,COLOR08_BLACK,x,y+2);
						draw1(dd_FIVE,COLOR08_WHITE,x,y+2);
						draw(dd_FIVE,COLOR08_BLACK,x+1,y+3);
						draw1(dd_FIVE,COLOR08_WHITE,x+1,y+3);
						draw(dd_FIVE,COLOR08_BLACK,x+2,y+4);
						draw1(dd_FIVE,COLOR08_WHITE,x+2,y+4);
					}
				if(gameboard[y][x]==6)
					{
						draw(dd_SIX,COLOR08_BLACK,x,y+2);
						draw1(dd_SIX,COLOR08_WHITE,x,y+2);
						draw(dd_SIX,COLOR08_BLACK,x+1,y+3);
						draw1(dd_SIX,COLOR08_WHITE,x+1,y+3);
						draw(dd_SIX,COLOR08_BLACK,x+2,y+4);
						draw1(dd_SIX,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==7)
					{
						draw(dd_SEVEN,COLOR08_BLACK,x,y+2);
						draw1(dd_SEVEN,COLOR08_WHITE,x,y+2);
						draw(dd_SEVEN,COLOR08_BLACK,x+1,y+3);
						draw1(dd_SEVEN,COLOR08_WHITE,x+1,y+3);
						draw(dd_SEVEN,COLOR08_BLACK,x+2,y+4);
						draw1(dd_SEVEN,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==8)
					{
						draw(dd_EIGHT,COLOR08_BLACK,x,y+2);
						draw1(dd_EIGHT,COLOR08_WHITE,x,y+2);
						draw(dd_EIGHT,COLOR08_BLACK,x+1,y+3);
						draw1(dd_EIGHT,COLOR08_WHITE,x+1,y+3);
						draw(dd_EIGHT,COLOR08_BLACK,x+2,y+4);
						draw1(dd_EIGHT,COLOR08_WHITE,x+2,y+4);
					}
					if(gameboard[y][x]==9)
					{
						draw(dd_NINE,COLOR08_BLACK,x,y+2);
						draw1(dd_NINE,COLOR08_WHITE,x,y+2);
						draw(dd_NINE,COLOR08_BLACK,x+1,y+3);
						draw1(dd_NINE,COLOR08_WHITE,x+1,y+3);
						draw(dd_NINE,COLOR08_BLACK,x+2,y+4);
						draw1(dd_NINE,COLOR08_WHITE,x+2,y+4);
						}
				}
			}
		}
	for(x=2;x<20;x++){
		for(y=0;y<6;y++){
			if (gameboard [y][x]==gameboard [y+1][x-1] && gameboard [y+1][x-1]== gameboard [y+2][x-2])
			{
				if(gameboard[y][x]==0)
				{
					draw(dd_ZERO,COLOR08_BLACK,x,y+2);
					draw1(dd_ZERO,COLOR08_WHITE,x,y+2);
					draw(dd_ZERO,COLOR08_BLACK,x-1,y+3);
					draw1(dd_ZERO,COLOR08_WHITE,x-1,y+3);
					draw(dd_ZERO,COLOR08_BLACK,x-2,y+4);
					draw1(dd_ZERO,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==1)
				{
					draw(dd_ONE,COLOR08_BLACK,x,y+2);
					draw1(dd_ONE,COLOR08_WHITE,x,y+2);
					draw(dd_ONE,COLOR08_BLACK,x-1,y+3);
					draw1(dd_ONE,COLOR08_WHITE,x-1,y+3);
					draw(dd_ONE,COLOR08_BLACK,x-2,y+4);
					draw1(dd_ONE,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==2)
				{
					draw(dd_TWO,COLOR08_BLACK,x,y+2);
					draw1(dd_TWO,COLOR08_WHITE,x,y+2);
					draw(dd_TWO,COLOR08_BLACK,x-1,y+3);
					draw1(dd_TWO,COLOR08_WHITE,x-1,y+3);
					draw(dd_TWO,COLOR08_BLACK,x-2,y+4);
					draw1(dd_TWO,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==3)
				{
					draw(dd_THREE,COLOR08_BLACK,x,y+2);
					draw1(dd_THREE,COLOR08_WHITE,x,y+2);
					draw(dd_THREE,COLOR08_BLACK,x-1,y+3);
					draw1(dd_THREE,COLOR08_WHITE,x-1,y+3);
					draw(dd_THREE,COLOR08_BLACK,x-2,y+4);
					draw1(dd_THREE,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==4)
				{
					draw(dd_FOUR,COLOR08_BLACK,x,y+2);
					draw1(dd_FOUR,COLOR08_WHITE,x,y+2);
					draw(dd_FOUR,COLOR08_BLACK,x-1,y+3);
					draw1(dd_FOUR,COLOR08_WHITE,x-1,y+3);
					draw(dd_FOUR,COLOR08_BLACK,x-2,y+4);
					draw1(dd_FOUR,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==5)
				{
					draw(dd_FIVE,COLOR08_BLACK,x,y+2);
					draw1(dd_FIVE,COLOR08_WHITE,x,y+2);
					draw(dd_FIVE,COLOR08_BLACK,x-1,y+3);
					draw1(dd_FIVE,COLOR08_WHITE,x-1,y+3);
					draw(dd_FIVE,COLOR08_BLACK,x-2,y+4);
					draw1(dd_FIVE,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==6)
				{
					draw(dd_SIX,COLOR08_BLACK,x,y+2);
					draw1(dd_SIX,COLOR08_WHITE,x,y+2);
					draw(dd_SIX,COLOR08_BLACK,x-1,y+3);
					draw1(dd_SIX,COLOR08_WHITE,x-1,y+3);
					draw(dd_SIX,COLOR08_BLACK,x-2,y+4);
					draw1(dd_SIX,COLOR08_WHITE,x-2,y+4);
					}
				if(gameboard[y][x]==7)
				{
					draw(dd_SEVEN,COLOR08_BLACK,x,y+2);
					draw1(dd_SEVEN,COLOR08_WHITE,x,y+2);
					draw(dd_SEVEN,COLOR08_BLACK,x-1,y+3);
					draw1(dd_SEVEN,COLOR08_WHITE,x-1,y+3);
					draw(dd_SEVEN,COLOR08_BLACK,x-2,y+4);
					draw1(dd_SEVEN,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==8)
				{
					draw(dd_EIGHT,COLOR08_BLACK,x,y+2);
					draw1(dd_EIGHT,COLOR08_WHITE,x,y+2);
					draw(dd_EIGHT,COLOR08_BLACK,x-1,y+3);
					draw1(dd_EIGHT,COLOR08_WHITE,x-1,y+3);
					draw(dd_EIGHT,COLOR08_BLACK,x-2,y+4);
					draw1(dd_EIGHT,COLOR08_WHITE,x-2,y+4);
				}
				if(gameboard[y][x]==9)
				{
					draw(dd_NINE,COLOR08_BLACK,x,y+2);
					draw1(dd_NINE,COLOR08_WHITE,x,y+2);
					draw(dd_NINE,COLOR08_BLACK,x-1,y+3);
					draw1(dd_NINE,COLOR08_WHITE,x-1,y+3);
					draw(dd_NINE,COLOR08_BLACK,x-2,y+4);
					draw1(dd_NINE,COLOR08_WHITE,x-2,y+4);
				}
			}
		}
	}
	Delay_Long ();

	// calculating score////////////////////////////

	int t,q,w,r;
	if(count>9999){
		count=1;
	}

	t=count%10;
	q=(count/10);
	q=q%10;
	w=(count/100);
	w=w%10;
	r=(count/1000);
	r=r%10;


	if(t==0)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_ZERO,COLOR08_GOLD, 19, 0);
	}
	if(t==1)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_ONE,COLOR08_GOLD, 19, 0);
	}
	if(t==2)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_TWO,COLOR08_GOLD, 19, 0);
	}
	if(t==3)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_THREE,COLOR08_GOLD, 19, 0);
	}
	if(t==4)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_FOUR,COLOR08_GOLD, 19, 0);
	}
	if(t==5)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_FIVE,COLOR08_GOLD, 19, 0);
	}
	if(t==6)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_SIX,COLOR08_GOLD, 19, 0);
	}
	if(t==7)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_SEVEN,COLOR08_GOLD, 19, 0);
	}
	if(t==8)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_EIGHT,COLOR08_GOLD, 19, 0);
	}
	if(t==9)
	{
		draw(dd_fill, COLOR08_BLACK,19,0);
		draw(dd_NINE,COLOR08_GOLD, 19, 0);
	}
	if(q==0)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_ZERO,COLOR08_GOLD, 18, 0);
	}
	if(q==1)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_ONE,COLOR08_GOLD, 18, 0);
	}
	if(q==2)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_TWO,COLOR08_GOLD, 18, 0);
	}
	if(q==3)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_THREE,COLOR08_GOLD, 18, 0);
	}
	if(q==4)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_FOUR,COLOR08_GOLD, 18, 0);
	}
	if(q==5)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_FIVE,COLOR08_GOLD, 18, 0);
	}
	if(q==6)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_SIX,COLOR08_GOLD, 18, 0);
	}
	if(q==7)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_SEVEN,COLOR08_GOLD, 18, 0);
	}
	if(q==8)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_EIGHT,COLOR08_GOLD, 18, 0);
	}
	if(q==9)
	{
		draw(dd_fill, COLOR08_BLACK,18,0);
		draw(dd_NINE,COLOR08_GOLD, 18, 0);
	}
	if(w==0)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_ZERO,COLOR08_GOLD, 17, 0);
	}
	if(w==1)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_ONE,COLOR08_GOLD, 17, 0);
	}
	if(w==2)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_TWO,COLOR08_GOLD, 17, 0);
	}
	if(w==3)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_THREE,COLOR08_GOLD, 17, 0);
	}
	if(w==4)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_FOUR,COLOR08_GOLD, 17, 0);
	}
	if(w==5)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_FIVE,COLOR08_GOLD, 17, 0);
	}
	if(w==6)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_SIX,COLOR08_GOLD, 17, 0);
	}
	if(w==7)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_SEVEN,COLOR08_GOLD, 17, 0);
	}
	if(w==8)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_EIGHT,COLOR08_GOLD, 17, 0);
	}
	if(w==9)
	{
		draw(dd_fill, COLOR08_BLACK,17,0);
		draw(dd_NINE,COLOR08_GOLD, 17, 0);
	}
	if(r==0)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_ZERO,COLOR08_GOLD, 16, 0);
	}
	if(r==1)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_ONE,COLOR08_GOLD, 16, 0);
	}
	if(r==2)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_TWO,COLOR08_GOLD, 16, 0);
	}
	if(r==3)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_THREE,COLOR08_GOLD, 16, 0);
	}
	if(r==4)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_FOUR,COLOR08_GOLD, 16, 0);
	}
	if(r==5)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_FIVE,COLOR08_GOLD, 16, 0);
	}
	if(r==6)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_SIX,COLOR08_GOLD, 16, 0);
	}
	if(r==7)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_SEVEN,COLOR08_GOLD, 16, 0);
	}
	if(r==8)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_EIGHT,COLOR08_GOLD, 16, 0);
	}
	if(r==9)
	{
		draw(dd_fill, COLOR08_BLACK,16,0);
		draw(dd_NINE,COLOR08_GOLD, 16, 0);
	}

	int gameboard_board [8][20]={
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	};
	Delay_Long();
	for(y=0; y<10;y++)
		{
			for(x=0; x<20; x++)
			{
				if(gameboard_board[y][x]<0)
				{

					if (gameboard [y][x] == 0)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_ZERO, COLOR08_PLUM, x, y+2);
					}
					else if (gameboard [y][x] == 1)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_ONE, COLOR08_PALEGREEN, x, y+2);
					}
					else if (gameboard [y][x] == 2)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_TWO, COLOR08_SEAGREEN, x, y+2);
					}
					else if (gameboard [y][x] == 3)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_THREE, COLOR08_PALEGREEN, x, y+2);
					}
					else if (gameboard [y][x] == 4)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_FOUR, COLOR08_TOMATO, x, y+2);
					}
					else if (gameboard [y][x] == 5)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_FIVE, COLOR08_VIOLET, x, y+2);
					}
					else if (gameboard [y][x] == 6)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_SIX, COLOR08_NAVY, x, y+2);
					}
					else if (gameboard [y][x] == 7)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_SEVEN, COLOR08_INC_RED, x, y+2);
					}
					else if (gameboard [y][x] == 8)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_EIGHT, COLOR08_GRAY, x, y+2);
					}
					else if (gameboard [y][x] == 9)
					{
						draw(dd_fill, COLOR08_BLACK, x, y+2);
						draw(dd_NINE, COLOR08_INC_GREEN, x, y+2);
					}

				}
			}
		}

	return 0;
	}
}

