/*
 * SPI.h
 *
 *  Created on: 12 Oct 2026
 *      Author: chandrasekharmoravaneni
 */

#ifndef SPI_H_
#define SPI_H_

#include "GPIO.h"

/* SPI Base address */
#define SPI1_BASE_ADDR 				(APB2_BASE_ADDR + 0x3000U)
#define SPI4_BASE_ADDR				(APB2_BASE_ADDR + 0x3100U)
#define SPI2_BASE_ADDR				(APB1_BASE_ADDR + 0x3800U)
#define SPI3_BASE_ADDR				(APB1_BASE_ADDR + 0x3C00U)

/* SPI Ports */
#define SPI1							(SPI_RegDef_t*)(SPI1_BASE_ADDR)
#define SPI4							(SPI_RegDef_t*)(SPI4_BASE_ADDR)
#define SPI2							(SPI_RegDef_t*)(SPI2_BASE_ADDR)
#define SPI3							(SPI_RegDef_t*)(SPI3_BASE_ADDR)

/* Clock enable for SPI*/

#define SPI1_PCLK_EN()    			(RCC -> APB2ENR |= (1U << 12))
#define SPI4_PCLK_EN()				(RCC -> APB2ENR |= (1U << 13))
#define SPI2_PCLK_EN()				(RCC -> APB1ENR |= (1U << 14))
#define SPI3_PCLK_EN()				(RCC -> APB1ENR |= (1U << 15))

/* Clock disable for SPI*/
#define SPI1_PCLK_DI()    			(RCC -> APB2ENR &= ~(1U << 12))
#define SPI4_PCLK_DI()				(RCC -> APB2ENR &= ~(1U << 13))
#define SPI2_PCLK_DI()				(RCC -> APB1ENR &= ~(1U << 14))
#define SPI3_PCLK_DI()				(RCC -> APB1ENR &= ~(1U << 15))

/* Reset for SPI*/
#define SPI1_REG_RESET()     do { (RCC -> APB2RSTR |= (1U<<12));  (RCC -> APB2RSTR &= ~(1U<<12)); } while(0)
#define SPI4_REG_RESET()     do { (RCC -> APB2RSTR |= (1U<<13));  (RCC -> APB2RSTR &= ~(1U<<13)); } while(0)
#define SPI2_REG_RESET()     do { (RCC -> APB1RSTR |= (1U<<14));  (RCC -> APB1RSTR &= ~(1U<<14)); } while(0)
#define SPI3_REG_RESET()     do { (RCC -> APB1RSTR |= (1U<<15));  (RCC -> APB1RSTR &= ~(1U<<15)); } while(0)



/* SPI DeviceMode*/

#define MASTER_MODE				1
#define SLAVE_MODE 				0

/* SPI BusConfig*/

#define SPI_BUS_CONFIG_FULLDUPLEX				1
#define SPI_BUS_CONFIG_HALFDUPLEX				2
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY			3


/*SPI sclk speed*/
#define SPI_SCLK_SPEED_DIV2				0
#define SPI_SCLK_SPEED_DIV4				1
#define SPI_SCLK_SPEED_DIV8				2
#define SPI_SCLK_SPEED_DIV16			3
#define SPI_SCLK_SPEED_DIV32			4
#define SPI_SCLK_SPEED_DIV64			5
#define SPI_SCLK_SPEED_DIV128			6
#define SPI_SCLK_SPEED_DIV256			7

/* SPI DFF*/
#define SPI_DFF_8BITS			0
#define SPI_DFF_16BITS			1

/*SPI CPHA*/
#define SPI_CHPA_HIGH			1
#define SPI_CHPA_LOW			0

/*SPI CPOL*/

#define SPI_CPOL_HIGH		1
#define SPI_CPOL_LOW		0

/*SPI SSM*/
#define SPI_SSM_EN			1
#define SPI_SSM_DI			0   // by default Software management is active

#define SPI_TXE_FLAG   (1U << SPI_SR_TXE)
#define SPI_RNXE_FLAG   (1U << SPI_SR_RXNE)
#define SPI_BUSY_FLAG   (1U << SPI_SR_BSY)

/*SPI BIT POSITION MACROS FOR CR1*/

#define SPI_CR1_CPHA			0
#define SPI_CR1_CPOL			1
#define SPI_CR1_MSTR			2
#define SPI_CR1_BR				3
#define SPI_CR1_SPE				6
#define SPI_CR1_LSBFIRST		7
#define SPI_CR1_SSI				8
#define SPI_CR1_SSM				9
#define SPI_CR1_RXONLY			10
#define SPI_CR1_DFF				11
#define SPI_CR1_CRCNEXT			12
#define SPI_CR1_CRCEN			13
#define SPI_CR1_BIDIOE			14
#define SPI_CR1_BIDIMODE		15

/*SPI BIT POSITION MACROS FOR CR2*/
#define SPI_CR2_RXDMAEN			0
#define SPI_CR2_TXDMAEN			1
#define SPI_CR2_SSOE			2
#define SPI_CR2_FRF				4
#define SPI_CR2_ERRIE			5
#define SPI_CR2_RXNEIE 			6
#define SPI_CR2_TXEIE			7
/*SPI BIT POSITION MACROS FOR SR*/
#define SPI_SR_RXNE				0
#define SPI_SR_TXE				1
#define SPI_SR_CHSIDE			2
#define SPI_SR_UDR				3
#define SPI_SR_CRCERR			4
#define SPI_SR_MODF				5
#define SPI_SR_OVR				6
#define SPI_SR_BSY				7
#define SPI_SR_FRE				8

typedef struct
{
	__vo uint32_t CR1;
	__vo uint32_t CR2;
	__vo uint32_t SR;
	__vo uint32_t DR;
	__vo uint32_t CRCPR;
	__vo uint32_t RXCRCR;
	__vo uint32_t TXCRCR;
	__vo uint32_t I2SCFGR;
	__vo uint32_t I2SPR;

}SPI_RegDef_t;

/*Configuration structure  for SPIx peripheral*/

typedef struct{
	uint8_t SPI_DeviceMode;
	uint8_t SPI_BusConfig;
	uint8_t SPI_SclkSpeed;
	uint8_t SPI_DFF;
	uint8_t SPI_CPHA;
	uint8_t SPI_CPOL;
	uint8_t SPI_SSM;


}SPI_Config_t;

/*SPIx Handle structure*/

typedef struct{
	SPI_RegDef_t *pSPIx;  // this holds the base address of the spi(x: 0,1,2,3,4) peripheral
	SPI_Config_t SPIConfig;

}SPI_Handle_t;



void SPI_PCLK_Control(SPI_RegDef_t *pSPIx, uint8_t ENorDI);
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/* Data send and receive*/

void SPI_SendData(SPI_RegDef_t *pSPIx,uint8_t *pTxBuffer, uint32_t Len);
void SPI_ReceiveData(SPI_RegDef_t *pSPIx, uint8_t *pRxBuffer, uint32_t Len);

void SPI_PeripheralControl(SPI_RegDef_t *pSPIx, uint8_t ENorDI);
void SPI_SSIConfig(SPI_RegDef_t *pSPIx, uint8_t ENorDI);

#endif /* SPI_SPI_H_ */
