/*
 * DP_RCC.cpp
 *
 *  Created on: Apr 26, 2020
 *      Author: Garmoosh
 */


#include <DP_RCC.h>








void  RCC_Fill (  const RCC_Fill_Struct& Fill_Struct ) {



	uint32_t temp ;


	temp = RCC->CFGR ;

	temp &= ~ ( RCC_CFGR_ADCPRE_Msk  | RCC_CFGR_USBPRE_Msk | RCC_CFGR_HPRE_Msk |
				RCC_CFGR_PPRE1_Msk   | RCC_CFGR_PPRE2_Msk  | RCC_CFGR_PLLMULL_Msk |
				RCC_CFGR_MCO_Msk     | RCC_CFGR_PLLXTPRE_Msk | RCC_CFGR_PLLSRC_Msk ) ;

	temp |= ( ( static_cast<uint32_t>(Fill_Struct.ADC_Pre)  << RCC_CFGR_ADCPRE_Pos     ) |
				  ( static_cast<uint32_t>(Fill_Struct.USB_Pre)  << RCC_CFGR_USBPRE_Pos     ) |
				  ( static_cast<uint32_t>(Fill_Struct.AHB_Scaler) << RCC_CFGR_HPRE_Pos     ) |
				  ( static_cast<uint32_t>(Fill_Struct.APB1_Scaler) << RCC_CFGR_PPRE1_Pos   ) |
				  ( static_cast<uint32_t>(Fill_Struct.APB2_Scaler) << RCC_CFGR_PPRE2_Pos   ) |
				  ( static_cast<uint32_t>(Fill_Struct.PLL_Mul) << RCC_CFGR_PLLMULL_Pos     ) |
				  ( static_cast<uint32_t>(Fill_Struct.Main_Clk_Out) << RCC_CFGR_MCO_Pos    ) |
				  ( static_cast<uint32_t>(Fill_Struct.HSE_Div) << RCC_CFGR_PLLXTPRE_Pos    ) |
				  ( static_cast<uint32_t>(Fill_Struct.PLL_Src) << RCC_CFGR_PLLSRC_Pos      ) );


	RCC->CFGR = temp ;

	temp = RCC->CR ;
	temp &= ~ ( RCC_CR_CSSON_Msk | RCC_CR_HSEBYP_Msk );
	temp |=(( static_cast<uint32_t>(Fill_Struct.CSS_En) << RCC_CR_CSSON_Pos ) |
			( static_cast<uint32_t>(Fill_Struct.HSE_Bypass) << RCC_CR_HSEBYP_Pos) ) ;
	RCC->CR = temp ;



	temp = RCC->BDCR ;


	temp &= ~ ( RCC_BDCR_RTCSEL_Msk | RCC_BDCR_LSEBYP_Msk ) ;


	temp|= ( ( static_cast<uint32_t>(Fill_Struct.RTC_Sel) << RCC_BDCR_RTCSEL_Pos ) |
			 ( static_cast<uint32_t>(Fill_Struct.LSE_Bypass) << RCC_BDCR_LSEBYP_Pos ) ) ;

	RCC->BDCR = temp ;


}




bool osc_enable ( volatile uint32_t* reg , uint32_t rdyfpos , uint32_t onpos, uint32_t timeout ){


	if ( *(reg) & ( 1 << rdyfpos ) && *(reg) & ( 1 << onpos )){
		return true ;
	}

	uint32_t bias = ( UINT_LEAST32_MAX - systick.getCount() ) <= timeout ? timeout : 0 ;
	uint32_t timer_s =  systick.getCount() + bias  ;

	(*reg)|= ( 1 << onpos ) ;

	while ( ( (systick.getCount() + bias ) - timer_s ) < timeout ){

		if ( *(reg) & ( 1 << rdyfpos ) ){
			return true ;
		}

	}

	return false ;
}


bool osc_disable ( volatile uint32_t* reg , uint32_t rdyfpos , uint32_t onpos , uint32_t timeout )
{

	if ( !( *(reg) & ( 1 << onpos )) ){
		return true ;
	}

	uint32_t bias = ( UINT_LEAST32_MAX - systick.getCount() ) <= timeout ? timeout : 0 ;
	uint32_t timer_s =  systick.getCount() + bias  ;

	(*reg)&= ~( 1 << onpos ) ;

	while ( ( (systick.getCount() + bias ) - timer_s ) < timeout ){

		if ( !(*(reg) & ( 1 << rdyfpos ) ) ){
			return true ;
		}

	}

	return false ;

}








