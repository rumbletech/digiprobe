/*
 * DP_SYSTICK.cpp
 *
 *  Created on: May 16, 2020
 *      Author: Garmoosh
 */

#include <DP_SYSTICK.h>



Ct_SYSTICK::Ct_SYSTICK ( uint32_t* ptr )
	:Freq( 1000UL ) , countptr(ptr)
{

	this->Update(Freq, 8000000UL );


}


int32_t Ct_SYSTICK::Update( uint32_t Freq  , uint32_t sysFreq ){

	if ( sysFreq < Freq ){
		return ASSERT_FAIL ;
	}

	this->Freq = Freq ;
	uint32_t ticks = (sysFreq)/Freq ;
	SysTick_Config( ticks );

	return 1 ;


}


void Ct_SYSTICK::delay ( uint32_t t_ms )
{

	uint32_t s_val = this->getCount() ;

	while ( (this->getCount() - s_val) < ((t_ms*this->Freq)/1000) );


}






static uint32_t systick_c  = 0UL ;
Ct_SYSTICK systick( &systick_c ) ;

/* Use C linkage on this function */
#ifdef __cplusplus

extern "C" {

#endif

void SysTick_Handler ( void )
{
	systick_c++ ;
}


#ifdef __cplusplus
}
#endif


