/*
 * DP_RCC.h
 *
 *  Created on: Apr 26, 2020
 *      Author: Garmoosh
 *
 */

#ifndef DP_INC_DP_RCC_H_
#define DP_INC_DP_RCC_H_
#include <GHeader.h>



#define HSE_TIMEOUT 10
#define HSI_TIMEOUT 10
#define PLL_TIMEOUT 10
#define LSE_TIMEOUT 10
#define LSI_TIMEOUT 10

#define HSE_ENABLE() osc_enable( &RCC->CR , RCC_CR_HSERDY_Pos , RCC_CR_HSEON_Pos , HSE_TIMEOUT )
#define HSE_BYPASS_ENABLE() ( RCC->CR|= (  RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk ))
#define HSI_ENABLE() osc_enable( &RCC->CR , RCC_CR_HSIRDY_Pos , RCC_CR_HSION_Pos , HSI_TIMEOUT )
#define PLL_ENABLE() osc_enable( &RCC->CR , RCC_CR_PLLRDY_Pos , RCC_CR_PLLON_Pos , PLL_TIMEOUT )
#define LSE_ENABLE() osc_enable( &RCC->BDCR , RCC_BDCR_LSERDY_Pos , RCC_BDCR_LSEON_Pos , LSE_TIMEOUT )
#define LSE_BYPASS_ENABLE() ( RCC->BDCR|= (  RCC_BDCR_LSEON_Msk | RCC_BDCR_LSEBYP_Msk ))
#define LSI_ENABLE() osc_enable( &RCC->CSR , RCC_CSR_LSIRDY_Pos , RCC_CSR_LSION_Pos , LSI_TIMEOUT )

#define HSE_DISABLE() osc_disable( &RCC->CR , RCC_CR_HSERDY_Pos , RCC_CR_HSEON_Pos , HSE_TIMEOUT )
#define HSE_BYPASS_DISABLE() ( RCC->CR&= ~( RCC_CR_HSEON_Msk | RCC_CR_HSEBYP_Msk ) )
#define HSI_DISABLE() osc_disable( &RCC->CR , RCC_CR_HSIRDY_Pos , RCC_CR_HSION_Pos , HSI_TIMEOUT )
#define PLL_DISABLE() osc_disable( &RCC->CR , RCC_CR_PLLRDY_Pos , RCC_CR_PLLON_Pos , PLL_TIMEOUT )
#define LSE_DISABLE() osc_disable( &RCC->BDCR , RCC_BDCR_LSERDY_Pos , RCC_BDCR_LSEON_Pos , LSE_TIMEOUT )
#define LSE_BYPASS_DISABLE() ( RCC->BDCR&= ~( RCC_BDCR_LSEON_Msk | RCC_BDCR_LSEBYP_Msk ) )
#define LSI_DISABLE() osc_disable( &RCC->CSR , RCC_CSR_LSIRDY_Pos , RCC_CSR_LSION_Pos , LSI_TIMEOUT )

#define GET_MCLKS_S() ( (RCC->CFGR & (RCC_CFGR_SWS_Msk) ) >> RCC_CFGR_SWS_Pos )
#define GET_AHB_DIV(ARG) (( ARG == AHBPre::AHBPRE_DIV1 ) ? (1UL) : ( ARG == AHBPre::AHBPRE_DIV2 ) ? (2UL):(ARG == AHBPre::AHBPRE_DIV4) ?(4UL):(ARG == AHBPre::AHBPRE_DIV8) ?(8UL):(ARG == AHBPre::AHBPRE_DIV16)?(16UL):(ARG == AHBPre::AHBPRE_DIV64)?(64UL):(ARG == AHBPre::AHBPRE_DIV128)?(128UL):(ARG == AHBPre::AHBPRE_DIV256)?(256UL):(512UL))
#define GET_APB_DIV(ARG) (( ARG == APBPre::APBPRE_DIV1 ) ? (1UL) : ( ARG == APBPre::APBPRE_DIV2 ) ? (2UL):( ARG == APBPre::APBPRE_DIV4)?(4UL):( ARG == APBPre::APBPRE_DIV8 )?(8UL):(16UL) )
#define GET_ADC_DIV(ARG) (( ARG == ADCPre::ADCPRE_DIV2 ) ? (2UL) : ( ARG == ADCPre::ADCPRE_DIV4 ) ? (4UL):( ARG == ADCPre::ADCPRE_DIV6 )?(6UL):(8UL))

#define IS_MCLKS( ARG )   ( ARG == MCLKS_PLLHSI \
						  || ARG == MCLKS_PLLHSE_BYPASS \
						  || ARG == MCLKS_PLLHSE \
						  || ARG == MCLKS_HSI \
						  || ARG ==	MCLKS_HSE \
						  || ARG ==	MCLKS_HSE_BYPASS )



#define IS_MCO( ARG ) ( ARG == MCO_NOCLK      \
						|| ARG == MCO_SYSCLK  \
						|| ARG == MCO_HSICLK  \
						|| ARG == MCO_HSECLK  \
						|| ARG == MCO_PLLCLK  )


#define IS_USBPRE( ARG )  ( ARG == USB_DIV1P5 \
						  || ARG == USB_NODIV )



#define IS_AHBPRE( ARG )  (  ARG == AHBPRE_DIV1 \
						  || ARG == AHBPRE_DIV2 \
						  || ARG == AHBPRE_DIV4 \
						  || ARG == AHBPRE_DIV8 \
						  || ARG ==	AHBPRE_DIV16 \
						  || ARG ==	AHBPRE_DIV64 \
						  || ARG ==	AHBPRE_DIV128 \
						  || ARG ==	AHBPRE_DIV256 \
						  || ARG ==	AHBPRE_DIV512 )


#define IS_APBPRE( ARG )  (  ARG == APBPRE_DIV1 \
						  || ARG == APBPRE_DIV2 \
						  || ARG == APBPRE_DIV4 \
						  || ARG == APBPRE_DIV8 \
						  || ARG ==	APBPRE_DIV16 )


#define IS_PLLMUL( ARG )  (  ARG == PLL_MUL_X2  \
						  || ARG == PLL_MUL_X3  \
						  || ARG == PLL_MUL_X4  \
						  || ARG == PLL_MUL_X5  \
						  || ARG ==	PLL_MUL_X6  \
						  || ARG ==	PLL_MUL_X7  \
						  || ARG ==	PLL_MUL_X8  \
						  || ARG ==	PLL_MUL_X9  \
						  || ARG ==	PLL_MUL_X10 \
						  || ARG ==	PLL_MUL_X11 \
						  || ARG ==	PLL_MUL_X12 \
						  || ARG ==	PLL_MUL_X13 \
						  || ARG ==	PLL_MUL_X14 \
						  || ARG ==	PLL_MUL_X15 \
						  || ARG ==	PLL_MUL_X16 )


#define IS_ADCPRE( ARG )  (  ARG == ADCPRE_DIV2 \
						  || ARG == ADCPRE_DIV4 \
						  || ARG == ADCPRE_DIV8 \
						  || ARG == ADCPRE_DIV16 )


#define IS_HSEDIV( ARG )  ( ARG == HSE_DIV1 \
							|| ARG == HSE_DIV2)


#define IS_CSSEN( ARG )    ( ARG == CSS_ENABLE \
							 || ARG == CSS_DISABLE )

#define IS_PLLSRC( ARG )   ( ARG == MPLL_SRC_HSE \
							 || ARG == MPLL_SRC_HSI )


#define IS_OSCBYPASS( ARG ) ( ARG == SEL_OSC \
							  || ARG == SEL_EXTCLK )

#define IS_RTCSEL( ARG )  (  ARG == RTC_NO_CLOCK \
						  || ARG == RTC_LSI \
						  || ARG == RTC_LSE \
						  || ARG == RTC_HSE_DIV128 )





enum class  Mclks {

	MCLKS_PLLHSI,
	MCLKS_PLLHSE_BYPASS,
	MCLKS_PLLHSE,
	MCLKS_HSI,
	MCLKS_HSE,
	MCLKS_HSE_BYPASS,

};



enum class Mco {

	MCO_NOCLK  = 0B000 ,
	MCO_SYSCLK = 0B100 ,
	MCO_HSICLK = 0B101 ,
	MCO_HSECLK = 0B110 ,
	MCO_PLLCLK = 0B111 ,

};


enum class USBPre {

	USB_DIV1P5 = 0 ,
	USB_NODIV  = 1 ,
};



enum class  AHBPre {

		AHBPRE_DIV1   = 0B0111 ,
		AHBPRE_DIV2   = 0B1000 ,
		AHBPRE_DIV4   = 0B1001 ,
		AHBPRE_DIV8   = 0B1010 ,
		AHBPRE_DIV16  = 0B1011 ,
		AHBPRE_DIV64  = 0B1100 ,
		AHBPRE_DIV128 = 0B1101 ,
		AHBPRE_DIV256 = 0B1110 ,
		AHBPRE_DIV512 = 0B1111 ,

};



enum class  PLLMul {

	PLL_MUL_X2  = 0B0000 ,
	PLL_MUL_X3  = 0B0001 ,
	PLL_MUL_X4  = 0B0010 ,
	PLL_MUL_X5  = 0B0011 ,
	PLL_MUL_X6  = 0B0100 ,
	PLL_MUL_X7  = 0B0101 ,
	PLL_MUL_X8  = 0B0110 ,
	PLL_MUL_X9  = 0B0111 ,
	PLL_MUL_X10 = 0B1000 ,
	PLL_MUL_X11 = 0B1001 ,
	PLL_MUL_X12 = 0B1010 ,
	PLL_MUL_X13 = 0B1011 ,
	PLL_MUL_X14 = 0B1100 ,
	PLL_MUL_X15 = 0B1101 ,
	PLL_MUL_X16 = 0B1110 ,


};




enum class  APBPre {

		APBPRE_DIV1  = 0B000 ,
		APBPRE_DIV2  = 0B100 ,
		APBPRE_DIV4  = 0B101 ,
		APBPRE_DIV8  = 0B110 ,
		APBPRE_DIV16 = 0B111 ,


};




enum class  ADCPre {


	ADCPRE_DIV2 = 0B00 ,
	ADCPRE_DIV4 = 0B01 ,
	ADCPRE_DIV6 = 0B10 ,
	ADCPRE_DIV8 = 0B11 ,

};



enum class  HSEDiv {

	HSE_DIV1 =  0 ,
	HSE_DIV2 =  1 ,
};




enum class CSSEn {

	CSS_ENABLE  = 1 ,
	CSS_DISABLE = 0 ,
};





enum class  MPLLSrc {

	MPLL_SRC_HSE = 1 ,
	MPLL_SRC_HSI = 0 ,

};

enum class  OscBypass {

	SEL_OSC    = 0  ,
	SEL_EXTCLK = 1  ,

};



enum class RTCSel {

	RTC_NO_CLOCK   = 0B00 ,
	RTC_LSE        = 0B01 ,
	RTC_LSI        = 0B10 ,
	RTC_HSE_DIV128 = 0B11 ,
};




struct RCC_Fill_Struct {

	uint32_t  HSE_Val    ;
	uint32_t  LSE_Val    ;
	Mclks   Main_Clk_Src ;
	MPLLSrc PLL_Src      ;
	OscBypass HSE_Bypass ;
	PLLMul  PLL_Mul      ;
	HSEDiv  HSE_Div      ;
	CSSEn   CSS_En       ;
	AHBPre  AHB_Scaler   ;
	APBPre  APB1_Scaler  ;
	APBPre  APB2_Scaler  ;
	Mco     Main_Clk_Out ;
	USBPre  USB_Pre      ;
	ADCPre  ADC_Pre      ;
	RTCSel  RTC_Sel      ;
	OscBypass LSE_Bypass ;

};






bool osc_enable ( volatile uint32_t* reg , uint32_t rdyfpos , uint32_t onpos, uint32_t timeout );
bool osc_disable (volatile  uint32_t* reg , uint32_t rdyfpos , uint32_t onpos, uint32_t timeout );
void  RCC_Fill (  const RCC_Fill_Struct& Fill_Struct );

















#endif /* DP_INC_DP_RCC_H_ */
