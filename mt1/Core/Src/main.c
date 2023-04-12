#include <stm32f407xx.h>
#define duration  30
//int count; //buna gerek yokmus CNT zaten timer icin countermis

int main(){
	RCC->APB1ENR=RCC_APB1ENR_TIM2EN_Pos;
	RCC->APB1ENR|=RCC_APB1ENR_TIM2EN;
	TIM2->CR1|=TIM_CR1_CEN; // timer icin enable olan bir tek bunu gordum counte'n alakasi var mi bilmiyorum
	TIM2->CR1=&~TIM_CR1_CEN; //dogru mask'in o oldugunu dusunup stop icin bitwise ile and'ledim
    TIM2->PSC= 1680;
    TIM2->ARR=65536-1;
	RCC->AHB1ENR|=RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER|=GPIO_MODER_MODE15_0;
	GPIOD->ODR^=GPIO_ODR_ODR_15; //toggle the bit

	while(1)// devamli olsun diye
	{
		if((TIM2->CNT)=duration){

			TIM2->CNT=1;


			GPIOD->ODR^=GPIO_ODR_ODR_15;
		}
	}//while


}//main
