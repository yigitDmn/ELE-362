/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "circular_buffer.h"
#include "dwt_delay.h"
#include "Nokia_5110.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum
{
    STATE_HEADER,
    STATE_LENGTH1,
    STATE_LENGTH2,
    STATE_ID,
    STATE_DATA,
    STATE_FINISH,
    STATE_CHECKSUM,
    STATE_DONE,
    STATE_ERROR
} State;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define BUFFER_SIZE 64
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
UART_HandleTypeDef huart3;

/* USER CODE BEGIN PV */
volatile uint8_t temp;

uint8_t bufferArray[BUFFER_SIZE];
volatile CircularBuffer circularBuffer;

State currentState = STATE_HEADER;

volatile uint8_t length1;
volatile uint8_t length2;
volatile uint16_t lengthOfData;

volatile uint8_t i;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART3_UART_Init(void);

void stateMachine(CircularBuffer *ptr, uint8_t byte);
_Bool checkSum(CircularBuffer *ptr);
void processPackage(CircularBuffer *ptr);
void toggleLEDs(CircularBuffer *ptr);
void printToGLCD(CircularBuffer *ptr, uint8_t item);
void arithmeticCommandTransmit(CircularBuffer *ptr, uint8_t item);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */


void recieveHandler(uint8_t);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	arrangeCircularBuffer(&circularBuffer, &bufferArray, BUFFER_SIZE);
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART3_UART_Init();
  /* USER CODE BEGIN 2 */
	DWT_Init();
	NOKIA_Init();
  /* USER CODE END 2 */
	HAL_UART_Receive_IT(&huart3,&temp,1);

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
		
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief USART3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART3_UART_Init(void)
{

  /* USER CODE BEGIN USART3_Init 0 */

  /* USER CODE END USART3_Init 0 */

  /* USER CODE BEGIN USART3_Init 1 */

  /* USER CODE END USART3_Init 1 */
  huart3.Instance = USART3;
  huart3.Init.BaudRate = 115200;
  huart3.Init.WordLength = UART_WORDLENGTH_8B;
  huart3.Init.StopBits = UART_STOPBITS_1;
  huart3.Init.Parity = UART_PARITY_NONE;
  huart3.Init.Mode = UART_MODE_TX_RX;
  huart3.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart3.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart3) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART3_Init 2 */

  /* USER CODE END USART3_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pins : PC0 PC1 PC2 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA4 PA5 PA7 PA8
                           PA13 PA14 PA15 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_7|GPIO_PIN_8
                          |GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
	if(huart->Instance == USART3){
		recieveHandler(temp);
		
		HAL_UART_Receive_IT(&huart3, &temp, 1);
	}
}

void recieveHandler(uint8_t byte){
	NOKIA_Out(3,4,"Interrupt");
	
	pushItemToBuff(&circularBuffer, byte);
	
	stateMachine(&circularBuffer, byte);
}

void stateMachine(CircularBuffer *ptr, uint8_t byte){
	switch (currentState){
		case STATE_HEADER:
			if (byte != 0xAB){
				deleteFromHead(ptr);
      }
      else if (byte == 0xAB){
				currentState = STATE_LENGTH1;
      }
      break;

		case STATE_LENGTH1:
			length1 = byte;
			currentState = STATE_LENGTH2;
      break;

		case STATE_LENGTH2:
      length2 = byte;
      lengthOfData = (length1 << 8) | length2;
      currentState = STATE_ID;
      break;

		case STATE_ID:
      currentState = STATE_DATA;
      break;

		case STATE_DATA:
      if ((getCount(ptr) - getHead(ptr) - 4) == lengthOfData){
				currentState = STATE_FINISH;
      }
      break;

		case STATE_FINISH:
      if (byte == 0xBA){
				currentState = STATE_CHECKSUM;
      }
      else if (byte != 0xBA){
				currentState = STATE_ERROR;
      }
      break;

		case STATE_CHECKSUM:
      if (checkSum(ptr)){
				currentState = STATE_DONE;
				processPackage(ptr);
			}
      else{
				currentState = STATE_ERROR;
      }
      break;

		case STATE_DONE:
			//printPackageStatus(ptr);
			currentState = STATE_HEADER;
      break;

		case STATE_ERROR:
      //printPackageStatus(ptr);
      currentState = STATE_HEADER;
      break;
	}
}

_Bool checkSum(CircularBuffer *ptr){
	uint16_t checkSumTotal;
	uint8_t *item;
  uint8_t index;

  for (index = 0; index < lengthOfData + 3; index++){
		pickItemFromBuff(ptr, item, index + 3);

    if (index + 3 != lengthOfData + 4){
			checkSumTotal += *item;
    }
	}
	return ((((checkSumTotal >> 8) + checkSumTotal) & 0xFF) == 0xFF);
}

void processPackage(CircularBuffer *ptr){
	uint8_t item;

  pickItemFromBuff(ptr, &item, 3);
    
	if (item == 0x01){
		toggleLEDs(ptr);
	}
  else if (item == 0x02){
		printToGLCD(ptr, item);
  }
  else if (item == 0x03 || item == 0x04 || item == 0x05 || item == 0x06){
		arithmeticCommandTransmit(ptr, item);
  }
  else{
		for (i = 0; i < lengthOfData; i++){
			pickItemFromBuff(ptr, &item, i + 4);
		}
	}
}

void toggleLEDs(CircularBuffer *ptr){
	uint8_t dataLEDs;
  uint8_t durationLEDs;

  pickItemFromBuff(ptr, &dataLEDs, 4);
  pickItemFromBuff(ptr, &durationLEDs, 5);

	// Pinlerin Numalar D�zenlenecek
	
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_0, (dataLEDs & 0x01) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, (dataLEDs & 0x02) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, (dataLEDs & 0x04) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, (dataLEDs & 0x08) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, (dataLEDs & 0x10) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, (dataLEDs & 0x20) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, (dataLEDs & 0x40) ? GPIO_PIN_SET : GPIO_PIN_RESET);
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7, (dataLEDs & 0x80) ? GPIO_PIN_SET : GPIO_PIN_RESET);

  HAL_Delay(durationLEDs * 1000); // dwt_delay de olur.
}

void printToGLCD(CircularBuffer *ptr, uint8_t item){
	uint8_t row;
  uint8_t column;

  pickItemFromBuff(ptr, &item, 4);

  if (lengthOfData == 1 && item == 0xFF){
    NOKIA_Clear();
  }
  else{
		pickItemFromBuff(ptr, &row, 4);
        
		pickItemFromBuff(ptr, &column, 5);
    
		for (i = 0; i < lengthOfData; i++){
			pickItemFromBuff(ptr, &item, i + 4);
      NOKIA_Out(row, column, (char*)item); // Bu satiri editlenecek
		}
	}
}

void arithmeticCommandTransmit(CircularBuffer *ptr, uint8_t item){
	uint8_t id = item;
  float result;
  char resultChar[32];

  pickItemFromBuff(ptr, &item, 4);
  result = (float)item;

  for (i = 0; i < lengthOfData - 1; i++){
		pickItemFromBuff(ptr, &item, i + 5);
    if (id == 0x03){
			result += (float)item;
    }
		else if (id == 0x04){
			result -= (float)item;
		}
    else if (id == 0x05){
			result *= (float)item;
		}
    else if (id == 0x06){
			result /= (float)item;
		}
	}
	sprintf(resultChar, "%.2f", result);
	HAL_UART_Transmit(&huart3, (uint8_t *)resultChar , 32, 1);
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
