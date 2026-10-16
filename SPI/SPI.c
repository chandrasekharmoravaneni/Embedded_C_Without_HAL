/*
 * SPI.c
 *
 *  Created on: 12 Oct 2026
 *      Author: chandrasekharmoravaneni
 */
#include "SPI.h"



uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint32_t Flagname){

	if(pSPIx->SR & Flagname)
	{
		return FLAG_SET;
	}


	return FLAG_RESET;

}

void SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t ENorDI){
	if(ENorDI == ENABLE)
		{
			if(pSPIx == SPI1)
			{
				SPI1_PCLK_EN();
			}
			else if(pSPIx == SPI4)
			{
				SPI4_PCLK_EN();
			}
			else if(pSPIx == SPI2)
			{
				SPI2_PCLK_EN();
			}
			else if(pSPIx == SPI3)
			{
				SPI3_PCLK_EN();
			}

		}
		else
		{
			if(pSPIx == SPI1)
			{
				SPI1_PCLK_DI();
			}
			else if(pSPIx == SPI4)
			{
				SPI4_PCLK_DI();
			}
			else if(pSPIx == SPI2)
			{
				SPI2_PCLK_DI();
			}
			else if(pSPIx == SPI3)
			{
				SPI3_PCLK_DI();
			}
		}

}
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
	SPI_PCLK_Control(pSPIHandle ->pSPIx,ENABLE);
	//Config SPI_CR1 Register

	uint32_t temp_reg = 0;

	// Device Mode
	temp_reg = pSPIHandle ->SPIConfig.SPI_DeviceMode << SPI_CR1_MSTR;
	// Config BUS_CONFIG
	if(pSPIHandle ->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_FULLDUPLEX)
	{
		//BIDI MODE should be cleared
		temp_reg &= ~(1U << SPI_CR1_BIDIMODE);

	}
	else if(pSPIHandle ->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_HALFDUPLEX)
	{
		// BIDI MODE should be set
		temp_reg |= (1U << SPI_CR1_BIDIMODE);
	}
	else if(pSPIHandle ->SPIConfig.SPI_BusConfig == SPI_BUS_CONFIG_SIMPLEX_RXONLY)
	{
		// BIDI MODE should be cleared
		temp_reg &= ~(1U << SPI_CR1_BIDIMODE);
		//RXONLY bit set
		temp_reg |=(1U << SPI_CR1_RXONLY);
	}

	// SPI_ Serial clock speed
	temp_reg |= pSPIHandle ->SPIConfig.SPI_SclkSpeed << SPI_CR1_BR;
	// SPI DFF
	temp_reg |= pSPIHandle ->SPIConfig.SPI_DFF << SPI_CR1_DFF;
	//CPOL
	temp_reg |= pSPIHandle ->SPIConfig.SPI_CPOL << SPI_CR1_CPOL;
	//CPHA
	temp_reg |= pSPIHandle ->SPIConfig.SPI_CPHA << SPI_CR1_CPHA;

	pSPIHandle ->pSPIx ->CR1 = temp_reg;


}

// Blocking call function

void SPI_SendData(SPI_RegDef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len){

	while(Len > 0)
	{
		// Wait  until TXE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET);


		// CHECK DFF BIT in CR1
		if((pSPIx ->CR1 & (1 << SPI_CR1_DFF)))
		{
			//16 bit DFF
			//load the data in to the DR
			pSPIx ->DR = *((uint16_t*)pTxBuffer);
			Len--; /* 2 bits thats why 2 times decrease*/
			Len--;
			(uint16_t*)pTxBuffer++;
		}
		else
		{
			// 8bit DFF
			pSPIx ->DR = *pTxBuffer;
			Len--;
			pTxBuffer++;
		}
	}

}
void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t ENorDI){
	if(ENorDI == ENABLE)
	{
		pSPIx ->CR1 |= (1 << SPI_CR1_SPE);
	}
	else
	{
		pSPIx ->CR1 &= ~(1 << SPI_CR1_SPE);
	}

}
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t ENorDI){
	if(ENorDI == ENABLE)
	{
		pSPIx ->CR1 |= (1 << SPI_CR1_SSI);
	}
	else
	{
		pSPIx ->CR1 &= ~(1 << SPI_CR1_SSI);
	}

}
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len){
	while(Len > 0)
	{
		// Wait  until TXE is set
		while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG) == FLAG_RESET);


		// CHECK DFF BIT in CR1
		if((pSPIx ->CR1 & (1 << SPI_CR1_DFF)))
		{
			//16 bit DFF
			//load the data from DR to RxBuffer
			*((uint16_t*)pRxBuffer) = pSPIx ->DR;
			Len--; /* 2 bits thats why 2 times decrease*/
			Len--;
			(uint16_t*)pRxBuffer++;
		}
		else
		{
			// 8bit DFF
			*pRxBuffer = pSPIx ->DR ;
			Len--;
			pRxBuffer++;
		}
	}

}
