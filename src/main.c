/**
*****************************************************************************
**
**  File        : main.c
**
**  Abstract    : main function.
**
**  Functions   : main
**
**  Environment : Atollic TrueSTUDIO/STM32
**                STMicroelectronics STM32Lxx Standard Peripherals Library
**
**  Distribution: The file is distributed “as is,” without any warranty
**                of any kind.
**
**  (c)Copyright Atollic AB.
**  You may use this file as-is or modify it according to the needs of your
**  project. This file may only be built (assembled or compiled and linked)
**  using the Atollic TrueSTUDIO(R) product. The use of this file together
**  with other tools than Atollic TrueSTUDIO(R) is not permitted.
**
*****************************************************************************
*/

/* Includes */
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
#include "spi_lcd.h"




/*
Struktura Snake reprezentuje jednu cast hada, finalny had je pole tychto struktur.
Ci je dany prvok pola uz realny had alebo je to este nenaplnena struktura, ktora
sa naplni az ked had zozerie jedlo, rozhoduje premenna isUsed. Teda, ak ma had uz
tri gulicky, prve tri struktury maju isUsed 1
*/









int main(void)
{

 init_game();

  while (1){

  }

  return 0;
}

