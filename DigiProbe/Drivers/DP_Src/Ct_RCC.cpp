/*
 * Ct_RCC.cpp
 *
 *  Created on: May 2, 2020
 *      Author: Garmoosh
 */


#include <Ct_RCC.h>



const static RCC_Fill_Struct HSI_Default_Struct = {

	HSE_Val      : 0UL  ,
	LSE_Val      : 0UL ,
	Main_Clk_Src : Mclks::MCLKS_PLLHSI ,
	PLL_Src      : MPLLSrc::MPLL_SRC_HSI ,
	HSE_Bypass   : OscBypass::SEL_OSC ,
	PLL_Mul      : PLLMul::PLL_MUL_X9 ,
	HSE_Div      : HSEDiv::HSE_DIV1 ,
	CSS_En       : CSSEn::CSS_ENABLE ,
	AHB_Scaler   : AHBPre::AHBPRE_DIV1 ,
	APB1_Scaler  : APBPre::APBPRE_DIV2 ,
	APB2_Scaler  : APBPre::APBPRE_DIV1 ,
	Main_Clk_Out : Mco::MCO_NOCLK ,
	USB_Pre      : USBPre::USB_DIV1P5 ,
	ADC_Pre      : ADCPre::ADCPRE_DIV2,
	RTC_Sel      : RTCSel::RTC_LSI ,
	LSE_Bypass   : OscBypass::SEL_OSC ,


};





const static RCC_Fill_Struct Blue_Pill_Struct = {

	HSE_Val      : 8000000UL  ,
	LSE_Val      : 32768000UL ,
	Main_Clk_Src : Mclks::MCLKS_PLLHSE ,
	PLL_Src      : MPLLSrc::MPLL_SRC_HSE ,
	HSE_Bypass   : OscBypass::SEL_OSC ,
	PLL_Mul      : PLLMul::PLL_MUL_X9 ,
	HSE_Div      : HSEDiv::HSE_DIV1 ,
	CSS_En       : CSSEn::CSS_ENABLE ,
	AHB_Scaler   : AHBPre::AHBPRE_DIV1 ,
	APB1_Scaler  : APBPre::APBPRE_DIV2 ,
	APB2_Scaler  : APBPre::APBPRE_DIV1 ,
	Main_Clk_Out : Mco::MCO_NOCLK ,
	USB_Pre      : USBPre::USB_DIV1P5 ,
	ADC_Pre      : ADCPre::ADCPRE_DIV2,
	RTC_Sel      : RTCSel::RTC_LSE ,
	LSE_Bypass   : OscBypass::SEL_EXTCLK ,


};


 Ct_RCC::Ct_RCC ( uint32_t Config )
{




 if ( Config == BLUEPILL_CONFIG ){

	/* Fill as HSE */

	 Ct_Fill_Struct.HSE_Val = Blue_Pill_Struct.HSE_Val ;
	 Ct_Fill_Struct.LSE_Val = Blue_Pill_Struct.LSE_Val ;
	 Ct_Fill_Struct.Main_Clk_Src = Blue_Pill_Struct.Main_Clk_Src ;
	 Ct_Fill_Struct.PLL_Src = Blue_Pill_Struct.PLL_Src ;
	 Ct_Fill_Struct.HSE_Bypass = Blue_Pill_Struct.HSE_Bypass ;
	 Ct_Fill_Struct.PLL_Mul = Blue_Pill_Struct.PLL_Mul ;
	 Ct_Fill_Struct.HSE_Div = Blue_Pill_Struct.HSE_Div ;
	 Ct_Fill_Struct.CSS_En = Blue_Pill_Struct.CSS_En ;
	 Ct_Fill_Struct.AHB_Scaler = Blue_Pill_Struct.AHB_Scaler ;
	 Ct_Fill_Struct.APB1_Scaler = Blue_Pill_Struct.APB1_Scaler ;
	 Ct_Fill_Struct.APB2_Scaler = Blue_Pill_Struct.APB2_Scaler ;
	 Ct_Fill_Struct.Main_Clk_Out = Blue_Pill_Struct.Main_Clk_Out ;
	 Ct_Fill_Struct.USB_Pre = Blue_Pill_Struct.USB_Pre ;
	 Ct_Fill_Struct.ADC_Pre = Blue_Pill_Struct.ADC_Pre ;
	 Ct_Fill_Struct.RTC_Sel = Blue_Pill_Struct.RTC_Sel ;
	 Ct_Fill_Struct.LSE_Bypass = Blue_Pill_Struct.LSE_Bypass ;



}
 else
 {

	 	/* Fill as HSI*/

	 Ct_Fill_Struct.HSE_Val = HSI_Default_Struct.HSE_Val ;
	 Ct_Fill_Struct.LSE_Val = HSI_Default_Struct.LSE_Val ;
	 Ct_Fill_Struct.Main_Clk_Src = HSI_Default_Struct.Main_Clk_Src ;
	 Ct_Fill_Struct.PLL_Src = HSI_Default_Struct.PLL_Src ;
	 Ct_Fill_Struct.HSE_Bypass = HSI_Default_Struct.HSE_Bypass ;
	 Ct_Fill_Struct.PLL_Mul = HSI_Default_Struct.PLL_Mul ;
	 Ct_Fill_Struct.HSE_Div = HSI_Default_Struct.HSE_Div ;
	 Ct_Fill_Struct.CSS_En = HSI_Default_Struct.CSS_En ;
	 Ct_Fill_Struct.AHB_Scaler = HSI_Default_Struct.AHB_Scaler ;
	 Ct_Fill_Struct.APB1_Scaler = HSI_Default_Struct.APB1_Scaler ;
	 Ct_Fill_Struct.APB2_Scaler = HSI_Default_Struct.APB2_Scaler ;
	 Ct_Fill_Struct.Main_Clk_Out = HSI_Default_Struct.Main_Clk_Out ;
	 Ct_Fill_Struct.USB_Pre = HSI_Default_Struct.USB_Pre ;
	 Ct_Fill_Struct.ADC_Pre = HSI_Default_Struct.ADC_Pre ;
	 Ct_Fill_Struct.RTC_Sel = HSI_Default_Struct.RTC_Sel ;
	 Ct_Fill_Struct.LSE_Bypass = HSI_Default_Struct.LSE_Bypass ;


	 }

}







 Ct_RCC::Ct_RCC ( const RCC_Fill_Struct& fill_struct )
 {
	 Fill( fill_struct );

 }


 void Ct_RCC::Fill (const RCC_Fill_Struct& fill_struct )
 {


	 Ct_Fill_Struct.HSE_Val = fill_struct.HSE_Val ;
	 Ct_Fill_Struct.LSE_Val = fill_struct.LSE_Val ;
	 Ct_Fill_Struct.Main_Clk_Src = fill_struct.Main_Clk_Src ;
	 Ct_Fill_Struct.PLL_Src = fill_struct.PLL_Src ;
	 Ct_Fill_Struct.HSE_Bypass = fill_struct.HSE_Bypass ;
	 Ct_Fill_Struct.PLL_Mul = fill_struct.PLL_Mul ;
	 Ct_Fill_Struct.HSE_Div = fill_struct.HSE_Div ;
	 Ct_Fill_Struct.CSS_En = fill_struct.CSS_En ;
	 Ct_Fill_Struct.AHB_Scaler = fill_struct.AHB_Scaler ;
	 Ct_Fill_Struct.APB1_Scaler = fill_struct.APB1_Scaler ;
	 Ct_Fill_Struct.APB2_Scaler = fill_struct.APB2_Scaler ;
	 Ct_Fill_Struct.Main_Clk_Out = fill_struct.Main_Clk_Out ;
	 Ct_Fill_Struct.USB_Pre = fill_struct.USB_Pre ;
	 Ct_Fill_Struct.ADC_Pre = fill_struct.ADC_Pre ;
	 Ct_Fill_Struct.RTC_Sel = fill_struct.RTC_Sel ;
	 Ct_Fill_Struct.LSE_Bypass = fill_struct.LSE_Bypass ;








 }








 int32_t Ct_RCC :: Update ( void )
 {

	uint32_t pllsr      = 0 ;
	uint32_t AHB_Val    = 0 ;
	uint32_t APB1_Val   = 0 ;
	uint32_t APB2_Val   = 0 ;
	uint32_t PLL_Input  = 0 ;
	uint32_t PLL_Output = 0 ;
	uint32_t hsesr = 0 ;
	uint32_t hsisr = 0 ;
	uint32_t rtc = 0 ;
	/* Switch to known HSI */
	if ( GET_MCLKS_S() != 0UL )
	{
		/*Switch to a stable Source (HSI) */
		RCC->CFGR &= ~( RCC_CFGR_SW_Msk ) ;

		systick.Update( systick.getFreq() , this->HSI_clk  ) ;

		/*Switch OFF PLL and HSE , To enable later code to be able to configure PLL */
		if ( !PLL_DISABLE() )
		{
			return TIMEOUT_FAIL ;
		}
		if ( !HSE_DISABLE() )
		{
			return TIMEOUT_FAIL ;
		}

	}

	/*Configure New Clock */

	if ( this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_HSE ||
		 this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_HSE_BYPASS ||
		 this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSE ||
		 this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSE_BYPASS ){

		/* Use PLL */
		if ( this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSE || this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSE_BYPASS )
		{
			pllsr = 1 ;

		}
		else{

			hsesr = 1 ;

		}

		/* Check HSE Boundaries */
		if ( ( this->Ct_Fill_Struct.HSE_Val > 16000000UL && (this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_HSE || this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSE) )||
			 ( this->Ct_Fill_Struct.HSE_Val > 25000000UL && (this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_HSE_BYPASS || this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSE_BYPASS)) )
		{
			return ASSERT_FAIL ;

		}

		/* Check PLL Boundaries */

		PLL_Input = this->Ct_Fill_Struct.HSE_Val /( static_cast<uint32_t>(this->Ct_Fill_Struct.HSE_Div ) + 1 ) ;
		PLL_Output = PLL_Input * (static_cast<uint32_t>(this->Ct_Fill_Struct.PLL_Mul)+2UL) ;

		if ( pllsr && ( PLL_Output > 72000000UL ) ){
			return ASSERT_FAIL ;
		}

		/* Check Bus Clock Boundaries */


		if ( pllsr )
		{
			AHB_Val = PLL_Output / GET_AHB_DIV(this->Ct_Fill_Struct.AHB_Scaler) ;
			APB1_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB1_Scaler) ;
			APB2_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB2_Scaler) ;
		}
		else{

			AHB_Val = PLL_Input / GET_AHB_DIV(this->Ct_Fill_Struct.AHB_Scaler) ;
			APB1_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB1_Scaler) ;
			APB2_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB2_Scaler) ;

		}

		if ( AHB_Val > 72000000UL || APB1_Val > 36000000UL || APB2_Val > 72000000UL )
		{
			return ASSERT_FAIL ;
		}

		if ( this->Ct_Fill_Struct.HSE_Bypass == OscBypass::SEL_OSC ){
		/* Turn on HSE */
		if ( !HSE_ENABLE() ) {

			return TIMEOUT_FAIL ;

		}

	}
		else{

			HSE_BYPASS_ENABLE();
		}


	 }
	else if ( this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_HSI ||
			  this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSI ){

		/* Use PLL */
		if ( this->Ct_Fill_Struct.Main_Clk_Src == Mclks::MCLKS_PLLHSI ){
			pllsr = 1 ;
		}
		else{
			hsisr = 1 ;
		}

		/* Check PLL Boundaries */

		PLL_Input = this->HSI_clk ;
		PLL_Output = PLL_Input * (static_cast<uint32_t>(this->Ct_Fill_Struct.PLL_Mul)+2UL) ;

		if ( pllsr && ( PLL_Output > 72000000UL ) ){
			return ASSERT_FAIL ;
		}

		/* Check Bus Clock Boundaries */


		if ( pllsr )
		{
			AHB_Val = PLL_Output / GET_AHB_DIV(this->Ct_Fill_Struct.AHB_Scaler) ;
			APB1_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB1_Scaler) ;
			APB2_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB2_Scaler) ;
		}
		else{

			AHB_Val = PLL_Input / GET_AHB_DIV(this->Ct_Fill_Struct.AHB_Scaler) ;
			APB1_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB1_Scaler) ;
			APB2_Val= AHB_Val / GET_APB_DIV(this->Ct_Fill_Struct.APB2_Scaler) ;

		}

		if ( AHB_Val > 72000000UL || APB1_Val > 36000000UL || APB2_Val > 72000000UL )
		{
			return ASSERT_FAIL ;
		}

		/* Turn on HSI */
		if ( !HSI_ENABLE() ) {

			return TIMEOUT_FAIL ;

		}



	}


	/* Update RTC Source */

	if ( this->Ct_Fill_Struct.RTC_Sel == RTCSel::RTC_LSI ){

		if ( !LSI_ENABLE() )
		{
			return TIMEOUT_FAIL ;
		}

		rtc = this->LSI_clk ;


	}
	else if ( this->Ct_Fill_Struct.RTC_Sel == RTCSel::RTC_LSE ){

			if ( this->Ct_Fill_Struct.LSE_Bypass == OscBypass::SEL_OSC )
			{
				if ( !LSE_ENABLE() )
				{
					return TIMEOUT_FAIL ;
				}

			}
			else{

					LSE_BYPASS_ENABLE();

			}

		rtc = this->Ct_Fill_Struct.LSE_Val ;

	}
	else if (this->Ct_Fill_Struct.RTC_Sel == RTCSel::RTC_HSE_DIV128 )
	{

		if ( this->Ct_Fill_Struct.HSE_Bypass == OscBypass::SEL_OSC ){
		if ( !HSE_ENABLE() )
		{
			return TIMEOUT_FAIL ;
		}
		}
		else{
			HSE_BYPASS_ENABLE();
		}

		rtc = this->Ct_Fill_Struct.HSE_Val /128UL ;

	}
	else{

		rtc = 0 ;


	}

	/* Fill Scalers , and Values */

	RCC_Fill( this->Ct_Fill_Struct ) ;

	/* Turn on PLL */

	if ( pllsr && !PLL_ENABLE() ){

		return TIMEOUT_FAIL ;
	}

	uint32_t sysclk = pllsr ? PLL_Output : PLL_Input ;

	/* Set Flash wait states */
	uint32_t ws = 0 ;
	uint32_t preb = 0 ;
	if ( sysclk <= 24000000UL ){
		ws = 0 ;
	}
	else if ( sysclk <= 48000000UL ){
		ws = 1 ;
	}
	else{
		ws = 2 ;
	}

	if ( this->Ct_Fill_Struct.AHB_Scaler != AHBPre::AHBPRE_DIV1 ){
		preb = 1 ;
	}

	uint32_t temp ;

	temp = FLASH->ACR ;

	temp&= ~ ( FLASH_ACR_LATENCY_Msk | FLASH_ACR_PRFTBE_Msk ) ;

	temp|= ( ws << FLASH_ACR_LATENCY_Pos | preb << FLASH_ACR_PRFTBE_Pos ) ;

	FLASH->ACR = temp ;

	temp = RCC->CFGR ;

	temp &= ~ ( RCC_CFGR_SW_Msk ) ;
	if ( pllsr )
	{
		temp|= ( 2 << RCC_CFGR_SW_Pos ) ;
	}
	else if ( hsesr )
	{
		temp |= ( 1 << RCC_CFGR_SW_Pos ) ;
	}

	RCC->CFGR = temp ;
	/* Update SYSTICK Base */

	systick.Update( systick.getFreq() , sysclk ) ;


	/* Update Clock Values */

	this->SYS_clk  = sysclk   ;
	this->H_clk    = AHB_Val  ;
	this->AHB_clk  = AHB_Val  ;
	this->APB1_clk = APB1_Val ;
	this->APB2_clk = APB2_Val ;
	this->RTC_clk  = rtc ;
	this->PLL_clk  = PLL_Output ;
#if defined( RCC_APB1ENR_USBEN_Msk)
	this->USB_clk  = (PLL_Output * 2UL) / ( (this->Ct_Fill_Struct.USB_Pre == USBPre::USB_DIV1P5) ? (3UL) : (2UL) ) ;
#endif
#if defined( RCC_APB2ENR_ADC1EN_Msk)
	this->ADC1_clk = APB2_Val / GET_ADC_DIV( this->Ct_Fill_Struct.ADC_Pre ) ;
#endif
#if defined( RCC_AHBENR_SDIOEN_Msk )
	this->SDIO_clk = this->H_clk  ;
	this->SDIO_AHB_clk = this->H_clk /2 ;
#endif
#if defined( RCC_APB1ENR_I2C1EN_Msk )
	this->I2C1_clk = this->APB1_clk ;
#endif
#if defined( RCC_APB1ENR_I2S2EN_Msk )
	this->I2S2_clk = sysclk ;
#endif
#if defined ( RCC_APB1ENR_I2S3EN_Msk )
	this->I2S3_clk = sysclk ;
#endif
#if defined ( RCC_AHBENR_FLITFEN_Msk)
	this->FLITF_clk= this->HSI_clk ;
#endif
#if defined ( RCC_APB1ENR_TIM2EN_Msk )
	this->TIM2_clk = (this->Ct_Fill_Struct.APB1_Scaler == APBPre::APBPRE_DIV1 ) ? ( this->APB1_clk ) : ( 2UL * this->APB1_clk ) ;
#endif
#if defined( RCC_APB2ENR_TIM1EN_Msk )
	this->TIM1_clk = (this->Ct_Fill_Struct.APB2_Scaler == APBPre::APBPRE_DIV1 ) ? ( this->APB2_clk ) : ( 2UL * this->APB2_clk ) ;
#endif

	this->MCO_clk = ((this->Ct_Fill_Struct.Main_Clk_Out == Mco::MCO_HSECLK )?(this->Ct_Fill_Struct.HSE_Val):
					(this->Ct_Fill_Struct.Main_Clk_Out == Mco::MCO_HSICLK )?(this->HSI_clk):
					(this->Ct_Fill_Struct.Main_Clk_Out == Mco::MCO_SYSCLK )?(this->SYS_clk):
					(this->Ct_Fill_Struct.Main_Clk_Out == Mco::MCO_PLLCLK )?((this->PLL_clk)/2UL):
					(0UL));


	 return 1 ;



 }


