/*
 * DP_SYSTICK.h
 *
 *  Created on: May 16, 2020
 *      Author: Garmoosh
 */


#ifndef DP_INC_DP_SYSTICK_H_
#define DP_INC_DP_SYSTICK_H_

#include <GHeader.h>


class Ct_SYSTICK
{

private :

	uint32_t Freq   ;
	uint32_t* countptr  ;
public:

	explicit Ct_SYSTICK(  uint32_t* ptr ) ;
	inline uint32_t getCount( void ) { return *(countptr) ; }
	inline uint32_t getFreq( void )  { return Freq  ; }
	int32_t Update( uint32_t Freq , uint32_t sysFreq ) ;
	void delay ( uint32_t t_ms ) ;

};



extern Ct_SYSTICK systick ;






#endif /* DP_INC_DP_SYSTICK_H_ */
