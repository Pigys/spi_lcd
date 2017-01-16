/*
 * spi_lcd.h
 *
 *  Created on: Jan 15, 2017
 *      Author: Andrej
 */

#ifndef SPI_LCD_H_
#define SPI_LCD_H_
#include <stddef.h>
#include "stm32l1xx.h"
#include <math.h>
#include "spi.h"
#include "ssd1306.h"
#include "ili9163.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "adc.h"


#define SIZE_OF_WORLD 13
#define NUMBER_OF_ELEMENTS SIZE_OF_WORLD * SIZE_OF_WORLD
#define SIZE_OF_SNAKE 15
#define DM 10 //DISPLAY MULTIPLIER
#define DM1 15
char last;

typedef struct{
    int x;
    int y;
    int isUsed;
}Snake;

void draw_hadik();
void Delays();
void Delays1();
void initWorld(char[SIZE_OF_WORLD][SIZE_OF_WORLD]);
void printWorld(char[SIZE_OF_WORLD][SIZE_OF_WORLD]);
void spawnFood(char[SIZE_OF_WORLD][SIZE_OF_WORLD]);
void spawnRock(char[SIZE_OF_WORLD][SIZE_OF_WORLD]);
void initSnake(char[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake[SIZE_OF_WORLD]);
void moveSnake(char[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake[SIZE_OF_WORLD]);
void growthSnake(char[SIZE_OF_WORLD][SIZE_OF_WORLD],Snake[SIZE_OF_WORLD],int*);
void clearMapFromSnake(char[SIZE_OF_WORLD][SIZE_OF_WORLD]);
void addSnakeToMap(char[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake[SIZE_OF_WORLD]);
int collision(char[SIZE_OF_WORLD][SIZE_OF_WORLD],Snake[SIZE_OF_WORLD],int,int, int*);
int move(char, char[SIZE_OF_WORLD][SIZE_OF_WORLD],Snake[SIZE_OF_WORLD], int*);
char get_adc_char();
void buttoninit();
void init_game();

#endif /* SPI_LCD_H_ */
