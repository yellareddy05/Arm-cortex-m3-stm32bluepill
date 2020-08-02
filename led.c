#include "stm32f10x.h"
#include "HAL_GPIO.h"

#define delay for(int i=0; i<5000000; ++i)

void GPIO_Init(void);

//int count = 0;
//uint8_t string[20]= "Hello world";

int main()
{
	GPIO_Init();
	while(1)
	{
		//++count;
		//--count;
		GPIOC->ODR ^= GPIO_PIN_13;
		delay;
		
	}
	
}
void GPIO_Init()
{
	//enable the clock for port c
	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	//Configure GPIOC pin13 into output push pull mode
	
	GPIOC->CRH |= GPIO_CRH_MODE13; // port c pin 13 in output mode 50Mhz
	GPIOC->CRH &= ~(GPIO_CRH_CNF13);
}
