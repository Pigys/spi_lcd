#include <stddef.h>
#include "stm32l1xx.h"
#include <math.h>
#include "spi.h"
#include "ssd1306.h"
#include "ili9163.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "spi_lcd.h"

char last = 'a';

char get_adc_char(){
	if (adc_value >1800 && adc_value < 2200){
		last = 'w';
		return 'w';
	}
	else if(adc_value >850 && adc_value < 1200){
		last = 'd';
		return 'd';
	}
	else if(adc_value >50 && adc_value < 400){
		last = 'a';
		return 'a';
	}
	else if(adc_value >2400 && adc_value < 2800){
		last = 's';
		return 's';
	}
	return last;
}

void draw_hadik(){
	//H
	lcdCircle(5+DM1,20,2,31);
	lcdCircle(5+DM1,24,2,31);
	lcdCircle(5+DM1,28,2,31);
	lcdCircle(5+DM1,32,2,31);
	lcdCircle(5+DM1,36,2,31);
	lcdCircle(5+DM1,40,2,31);
	lcdCircle(5+DM1,44,2,31);
	lcdCircle(9+DM1,32,2,31);
	lcdCircle(11+DM1,32,2,31);
	lcdCircle(13+DM1,32,2,31);
	lcdCircle(17+DM1,20,2,31);
	lcdCircle(17+DM1,24,2,31);
	lcdCircle(17+DM1,28,2,31);
	lcdCircle(17+DM1,32,2,31);
	lcdCircle(17+DM1,36,2,31);
	lcdCircle(17+DM1,40,2,31);
	lcdCircle(17+DM1,44,2,31);

	//A
	lcdCircle(25+DM1,44,2,31);
	lcdCircle(25+DM1,40,2,31);
	lcdCircle(25+DM1,36,2,31);
	lcdCircle(25+DM1,32,2,31);
	lcdCircle(29+DM1,32,2,31);
	lcdCircle(25+DM1,28,2,31);
	lcdCircle(25+DM1,24,2,31);
	lcdCircle(25+DM1,20,2,31);
	lcdCircle(29+DM1,20,2,31);
	lcdCircle(31+DM1,20,2,31);
	lcdCircle(35+DM1,20,2,31);
	lcdCircle(35+DM1,44,2,31);
	lcdCircle(35+DM1,40,2,31);
	lcdCircle(35+DM1,36,2,31);
	lcdCircle(35+DM1,32,2,31);
	lcdCircle(35+DM1,28,2,31);
	lcdCircle(35+DM1,24,2,31);

	//D
	lcdCircle(43+DM1,44,2,31);
	lcdCircle(43+DM1,40,2,31);
	lcdCircle(43+DM1,36,2,31);
	lcdCircle(43+DM1,32,2,31);
	lcdCircle(43+DM1,28,2,31);
	lcdCircle(43+DM1,24,2,31);
	lcdCircle(43+DM1,20,2,31);
	lcdCircle(47+DM1,20,2,31);
	lcdCircle(51+DM1,24,2,31);
	lcdCircle(47+DM1,44,2,31);
	lcdCircle(51+DM1,40,2,31);
	lcdCircle(55+DM1,36,2,31);
	lcdCircle(55+DM1,32,2,31);
	lcdCircle(55+DM1,28,2,31);

	//I
	lcdCircle(63+DM1,44,2,31);
	lcdCircle(63+DM1,40,2,31);
	lcdCircle(63+DM1,36,2,31);
	lcdCircle(63+DM1,32,2,31);
	lcdCircle(63+DM1,28,2,31);
	lcdCircle(63+DM1,24,2,31);
	lcdCircle(63+DM1,20,2,31);

	//K
	lcdCircle(71+DM1,44,2,31);
	lcdCircle(71+DM1,40,2,31);
	lcdCircle(71+DM1,36,2,31);
	lcdCircle(71+DM1,32,2,31);
	lcdCircle(71+DM1,28,2,31);
	lcdCircle(71+DM1,24,2,31);
	lcdCircle(71+DM1,20,2,31);

	lcdCircle(75+DM1,32,2,31);

	lcdCircle(79+DM1,36,2,31);
	lcdCircle(83+DM1,40,2,31);
	lcdCircle(87+DM1,44,2,31);

	lcdCircle(87+DM1,20,2,31);
	lcdCircle(83+DM1,24,2,31);
	lcdCircle(79+DM1,28,2,31);


	 lcdPutS("Pre hranie",40,70,0xFFFF, 0);
	 lcdPutS("Stlac modry button  ",10,80,0xFFFF, 0);

}

void Delays()
{
	int c = 1, d = 1;

	   for ( c = 1 ; c <= 500 ; c++ )
	       for ( d = 1 ; d <= 500 ; d++ )
	       {}


}

void Delays1()
{
	int c = 1, d = 1;

	   for ( c = 1 ; c <= 1500 ; c++ )
	       for ( d = 1 ; d <= 1500 ; d++ )
	       {}


}
void initWorld(char map[SIZE_OF_WORLD][SIZE_OF_WORLD]) {
/*
Funkcia initWorld memsetne celu maticu na medzery, nasledne ju preiteruje a nastavi
okraje matice na X, teda spravime si ohradu
*/
    int row, col;

    memset(map, ' ',NUMBER_OF_ELEMENTS);

    for (row=0; row < SIZE_OF_WORLD; row++) {
        for(col = 0; col < SIZE_OF_WORLD; col++) {
            if(col == 0 || col == SIZE_OF_WORLD-1) {
                map[row][col] = 'X';
            }
            if(row == 0 || row == SIZE_OF_WORLD-1){
                map[row][col] = 'X';
            }
        }
    }
}

void printWorld(char map[SIZE_OF_WORLD][SIZE_OF_WORLD]) {
/*
Vyprinti aktualny stav matice
*/

    int row, col;

    for (row=0; row < SIZE_OF_WORLD; row++) {
        for(col = 0; col < SIZE_OF_WORLD; col++) {
             //printf("%c", map[row][col]);
        	lcdPutCh(map[row][col], col*DM, row*DM, 31, 0);

        }

        //printf("\n");
    }

}


void spawnFood(char map[SIZE_OF_WORLD][SIZE_OF_WORLD]) {
/*
Vygeneruje nahodnu poziciu v ramci matice a da tam jedlo. Funkcia generuje jedlo,
pokial sa nespawne do neobsadenej pozicie (kontroluje,ci sa nespawne do hada alebo steny)
*/
    //srand(time(NULL));
    int x,y;

    do {
        x = rand() % SIZE_OF_WORLD;
        y = rand() % SIZE_OF_WORLD;
    } while (map[x][y] != ' ');

    map[x][y] = '@';
}

void spawnRock(char map[SIZE_OF_WORLD][SIZE_OF_WORLD]) {

    //srand(time(NULL));
    int x,y;

    do {
        x = rand() % SIZE_OF_WORLD;
        y = rand() % SIZE_OF_WORLD;
    } while (map[x][y] != ' ');

    map[x][y] = 'X';
}

void initSnake(char map[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake snake[SIZE_OF_SNAKE]) {
/*
Funkcia vytvori "hlavu" hada, vsetky ostatne struktury v poli nastavi na nula. Hlavu hada
umiestni do stredu mapy
*/
    int i;

    snake[0].isUsed = 1;
    snake[0].x = (int)floor(SIZE_OF_WORLD/2);
    snake[0].y = (int)floor(SIZE_OF_WORLD/2);
    for(i = 1; i < SIZE_OF_SNAKE; i++) {
        snake[i].isUsed = 0;
    }

    map[snake[0].x][snake[0].y] = 'O';
}

void moveSnake(char map[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake snake[SIZE_OF_SNAKE]) {
/*
Funkcia, ktora hybe hadom, pokial sa hybe v ramci cistej matice (ak pred nim nie je
akakolvek prekazka ci jedlo). Preiterujem sa od hlavy az po chvost a kazdej casti hada
nastavim suradnice tej predchadzajucej,teda kazda cast sa "pohne" tam, kde bola predosla
*/
    int i;
    Snake oldSnake[SIZE_OF_SNAKE];

    for(i = 0; i < SIZE_OF_SNAKE; i++) {
        oldSnake[i] = snake[i];
    }

    for(i = 1; i < SIZE_OF_SNAKE; i++) {
        if(snake[i].isUsed == 1) {
            snake[i] = oldSnake[i-1];
        }
    }
}

void growthSnake(char map[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake snake[SIZE_OF_SNAKE], int* score) {
/*
Funkcia, ktorou sa zvacsuje had. Funguje podobne ako moveSnake, len nepohnem chvostom, len hlavou.
Teda, akoby som pridal jednu gulicku dopredu, na poziciu jedla.
*/
    int i;
    Snake oldSnake[SIZE_OF_SNAKE];

    for(i = 0; i < SIZE_OF_SNAKE; i++) {
        oldSnake[i] = snake[i];
    }

    for(i = 1; i < *score + 1; i++) {
            snake[i] = oldSnake[i-1];
    }
    spawnRock(map);
}

void clearMapFromSnake(char map[SIZE_OF_WORLD][SIZE_OF_WORLD]) {
/*
Funkcia potrebna pri pohybe hada, najskor z matice hada odstranime, potom preratame,kam sa
ma had posunut a nasledne ho tam pridame. V tejto funkcii ho len odstranime
*/
    int row, col;

    for (row=0; row < SIZE_OF_WORLD; row++) {
        for(col = 0; col < SIZE_OF_WORLD; col++) {
            if(map[row][col] == 'O') {
             map[row][col] = ' ';
            }
        }
    }
}

void addSnakeToMap(char map[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake snake[SIZE_OF_SNAKE]) {
/*
Po vyratani novych suradnic pridame hada tam, kde ma byt
*/
    int i;

    for (i = 0; i < SIZE_OF_SNAKE; i++) {
        if(snake[i].isUsed == 1) {
            map[snake[i].x][snake[i].y] = 'O';
        }
    }
}

int collision(char map[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake snake[SIZE_OF_SNAKE],int x, int y, int* score) {
/*
Funkcia deteguje koliziu. Podmienky su zoradene tak, ako predpokladame ich pravdepodobnostny vyskyt a teda
zjednodusujeme zlozitost. Funkcia vracia taku hodnotu,aka udalost nastala, teda 1 ak je mapa volna, 2 ak
sme nieco zjedli a -1 ak sme narazili.
*/
	if(map[x][y] == ' ') {
		return 1;
	}
	if(map[x][y] == '@') {
		return 2;
	}
	if(map[x][y] == 'X' ) {
		return -1;
	}
	/*
	Spodny if zabezpeci, ze ked bude vidiet hada pred sebou,narazi, ten nad nim cekuje,ci nahodou ten
	had pred nim je je koniec chvosta..lebo tam moze ist,nakolko sa ten chost posunie dopredu..preto
	najskor cekujem ci to nieje spicka chvosta,a ak ano vratim jednotku,ze tam mozne ist..az potom
	cekujem ci je to zvysok hada a narazim
	*/
	if (x == snake[*score].x && y == snake[*score].y && (*score !=1)) {
		return 1;
	}
	if (map[x][y] == 'O') {
		return -1;
	}
}

int move(char direction, char map[SIZE_OF_WORLD][SIZE_OF_WORLD], Snake snake[SIZE_OF_SNAKE], int* score) {
    int decision = 0;

    switch(direction) {
        case 'a':    // key up
            decision = collision(map, snake, snake[0].x, snake[0].y - 1, score);
            if (decision < 0) {
                return 1;
            } else if (decision == 1) {
                moveSnake(map,snake);
                snake[0].y--;
            } else if (decision == 2) {
                (*score)++;
                growthSnake(map, snake, score);
                snake[0].y--;
                spawnFood(map);
            }
            break;
        case 'd':    // key down
            decision = collision(map, snake, snake[0].x, snake[0].y + 1, score);
            if (decision < 0) {
                return 1;
            } else if (decision == 1) {
                moveSnake(map,snake);
                snake[0].y++;
            } else if (decision == 2){
                (*score)++;
                growthSnake(map, snake, score);
                snake[0].y++;
                spawnFood(map);
            }
            break;
        case 's':    // key right
            decision = collision(map, snake, snake[0].x + 1, snake[0].y, score);
            if (decision < 0) {
                return 1;
            } else if (decision == 1) {
                moveSnake(map,snake);
                snake[0].x++;
            } else if (decision == 2){
                (*score)++;
                growthSnake(map, snake, score);
                snake[0].x++;
                spawnFood(map);
            }
            break;
        case 'w':    // key left
            decision = collision(map, snake, snake[0].x - 1, snake[0].y, score);
            if (decision < 0) {
                return 1;
            } else if (decision == 1) {
                moveSnake(map,snake);
                snake[0].x--;
            } else if (decision == 2){
                (*score)++;
                growthSnake(map, snake, score);
                snake[0].x--;
                spawnFood(map);
            }
            break;
        case 'o':
            return 1;
            break;
    }

    return 0;
}


void buttoninit(){
	  GPIO_InitTypeDef struktura1;
	 RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
		     struktura1.GPIO_Mode = GPIO_Mode_IN ;
		     struktura1.GPIO_OType = GPIO_OType_PP;
		     struktura1.GPIO_PuPd = GPIO_PuPd_NOPULL;
		     struktura1.GPIO_Pin = GPIO_Pin_13;
		     GPIO_Init(GPIOC, &struktura1);
}

void init_game(){
	  adc_init();
	  initSPI2();
	  initCD_Pin();
	  initCS_Pin();
	  initRES_Pin();
	  buttoninit();

	  lcdInitialise(LCD_ORIENTATION0);
	 lcdClearDisplay(decodeRgbValue(0, 0, 0));
	 draw_hadik();
	  int button = 0;
	  int endFlag = 0;
	  int *score = (int*)malloc(sizeof(int));
	  *score = 0;
	  int isFood = 1;
	  char direction = 0;
	  char map[SIZE_OF_WORLD][SIZE_OF_WORLD];
	  Snake snake[SIZE_OF_SNAKE];
	  Delays1(10);
	  lcdClearDisplay(decodeRgbValue(0, 0, 0));
	  initWorld(map);
	  initSnake(map,snake);
	  spawnFood(map);
	  map[3][6] = '@';
	  char str ;
	  printWorld(map);
	  int pom = 0;
	  char dec, el,temp;



	  do{
		     button = GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13);
		     if(!button) pom = 1 ;
		     if(pom){


	         if(!isFood) {
	             spawnFood(map);
	             isFood = 1;
	         }


	         direction = get_adc_char();



	         /*if(!button)
	        	 direction = 'w';*/


	         endFlag = move(direction, map, snake, score);

	         //system("@cls||clear");
	         clearMapFromSnake(map);
	         addSnakeToMap(map,snake);
	         printWorld(map);

	         //while ( getchar() != '\n' );
	         //fflush(stdin);
	         //direction = 0;
	         Delays(10);



	         if(*score == SIZE_OF_SNAKE -1) {
	        		char hodnota = *score;
	        		dec = hodnota/10;
	        		el = hodnota % 10;
	        		dec += 48;
	        	    el  += 48;
	        	    lcdClearDisplay(decodeRgbValue(0, 0, 0));
	        	    lcdPutS("Vyhral si",40,50,0xFFFF, 0);
	        	    lcdPutS("Tvoje skore :",35,60,0xFFFF,0);
	        	    lcdPutCh(dec,105,60,0xFFFF,0);
	                if(*score >=10){
	        	    lcdPutCh(el,113,60,0xFFFF,0);}
	        	    lcdPutS("Pre hranie odznova ",10,70,0xFFFF, 0);
	        	    lcdPutS("Stlac reset  ",35,80,0xFFFF, 0);
	        	    return 0;
	         }

		     }
	     }while(endFlag != 1);
	  	  	  	  	char hodnota = *score;
	  	         	dec = hodnota/10;
	  	         	temp = hodnota;
	  	         	el = hodnota % 10;

	  	         	dec += 48;
	  	         	el  += 48;
	  	         	temp +=48;
	  	         	lcdClearDisplay(decodeRgbValue(0, 0, 0));
	  	         	lcdPutS("Prehral si",40,50,0xFFFF, 0);
	  	         	lcdPutS("Tvoje skore :",35,60,0xFFFF,0);
	  	         	if(*score < 10){
	  	         	lcdPutCh(temp,105,60,0xFFFF,0);
	  	         	}
	  	         	if(*score >=10){
	  	         	lcdPutCh(dec,105,60,0xFFFF,0);
	  	         	lcdPutCh(el,113,60,0xFFFF,0);
	  	         	}
	  	         	lcdPutS("Pre hranie odznova ",10,70,0xFFFF, 0);
	  	         	lcdPutS("Stlac reset  ",35,80,0xFFFF, 0);

}
