
#include "main.h"


int main(void)
{
	//Enable PORT C
	RCC->APB2ENR |= ( 1 << RCC_APB2ENR_IOPCEN_Pos );

	//MAKE PIN 13 AN OUTPUT

	GPIOC->CRH |= ( 1 << GPIO_CRH_MODE13_Pos ) ;


  while (1)
  {
	  //SET PIN
	  GPIOC->ODR |= ( 1 << 13 );
	  for( int i = 0 ; i < 100000 ;i++);
	  //clear PIN
	  GPIOC->ODR &= ~ ( 1 << 13 );
	  for( int i = 0 ; i < 100000 ;i++);
  }

}

