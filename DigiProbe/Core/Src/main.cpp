
#include "main.h"
#include <stdint.h>
#include <DP_USB.h>

int main(void)
{
	Ct_RCC sysctl( BLUEPILL_CONFIG ) ;

	if ( sysctl.Update() != 1 )
	{
		while(1)
		{
			//BREAK;
		}
	}
	sysctl.enableUSB();
	sysctl.enableGPIOC();

	EP_Config_S my_ep ;
	my_ep.EP_Addr = 0x12 ;
	my_ep.EP_BT = EP_bufftype_E::EP_SINGLE_BUFF ;
	my_ep.EP_RX0_BSize = 32 ;
	my_ep.EP_TX0_BSize = 24 ;
	my_ep.EP_BT = EP_bufftype_E::EP_SINGLE_BUFF ;
	my_ep.EP_Type= EP_type_E::EP_TYPE_INT ;
	my_ep.EP_Dir = EP_dir_E::EP_DIR_BID ;
	my_ep.EP_Num = 2 ;
	my_ep.EP_Reg = nullptr ;

	if ( my_ep.allocate() == -1 ){
		while(1);
	}

	uint8_t tx_array[13] = { 1 , 2, 3 , 4, 5 , 6 ,7 ,8 ,9 ,10 , 11 , 12 , 13 };

	my_ep.writeTXBuff(tx_array, 13);

	uint8_t value ;

	for ( int i = 0 ; i < 13 ; i++ ){
		value = pma.read_b( my_ep.EP_TX0_Ptr + i );
	}







	systick.Update( 4000 , sysctl.getSYSCLK() );

	//OUTPUT
	GPIOC->CRH = ( 1 << GPIO_CRH_MODE13_Pos );




  while (1)
  {

	  GPIOC->ODR |= ( 1 << 13 );
	  systick.delay(5000);
	  GPIOC->ODR &= ~( 1 << 13 );
	  systick.delay(5000);


  }



}
