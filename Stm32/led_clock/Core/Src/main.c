/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void encender(int tiempo);
void apagar(int tiempo);
int inicial(int tiempo[]);
int  run(int tiempo[]);
int set(int tiempo[]);
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	int tiempo[] = {7,30,0};
	int state = 1;
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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */
 
 

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  switch (state) {
	  		case 1:
	  			state = inicial(tiempo);
	  			break;
	  		case 2:
	  			state = run(tiempo);
	  			break;
	  		case 3:
	  			state = set(tiempo);
	  			break;
	  		default:
	  			break;
	  }
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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
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
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, led_9_Pin|led_10_Pin|led_11_Pin|led_6_Pin 
                          |led_7_Pin|led_8_Pin|buzzer_Pin|opc_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, led_12_Pin|led_1_Pin|led_2_Pin|led_3_Pin 
                          |led_4_Pin|led_5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : puls_Pin */
  GPIO_InitStruct.Pin = puls_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(puls_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : led_9_Pin led_10_Pin led_11_Pin led_6_Pin 
                           led_7_Pin led_8_Pin buzzer_Pin opc_1_Pin */
  GPIO_InitStruct.Pin = led_9_Pin|led_10_Pin|led_11_Pin|led_6_Pin 
                          |led_7_Pin|led_8_Pin|buzzer_Pin|opc_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : led_12_Pin led_1_Pin led_2_Pin led_3_Pin 
                           led_4_Pin led_5_Pin */
  GPIO_InitStruct.Pin = led_12_Pin|led_1_Pin|led_2_Pin|led_3_Pin 
                          |led_4_Pin|led_5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
int inicial(int tiempo[]){
	 int button;
	 int time = 0;
	 int estado = 1;
	 //for para las horas
	for (int i = tiempo[0];  i < 12; ++ i) {
		//for para los minutos
		for (int j = tiempo[1]; j < 60; ++j) {
			//for para los segundos
			for (int k = tiempo[2]; k < 60; ++k) {
				tiempo[2] = tiempo [2] + 1;//sumar un segundo
				if(tiempo[2] == 59){//evaluar si ya paso un minuto
					tiempo[1]= tiempo[1] + 1;//sumar un minuto
					tiempo[2] = 0;//reset segundos
				}
				HAL_Delay(500);//delay 1 segundo
				button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//leer boton
				while (button == GPIO_PIN_SET){//mientras este presionado
					button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//leer botton
					time = time +1 ;//tiempo para reconocer estado
					HAL_Delay(1000);// delay un segundo
				}
				if(time >= 5){//para ir a set (5 seg)
					estado = 3;//estado set
				}else if (time > 0 && time < 5){
					estado = 2;//estado run
				}
				if(estado != 1){
					break;//si se tiene un estado se rompe for de segundos
				}
			}
			if(tiempo[1] == 59){//se evalua que se cumplan los minutos
				tiempo[0]= tiempo[0] + 1;//se suma una hora
				tiempo[1] = 0;//reset min
			}
			if(estado != 0){
				break;//si se tiene un estado se rompe for de minutos
			}
		}
		if(tiempo[0] == 11){//se evalua si se cumplen las horas
			tiempo[0] = 0;//reset horas
		}
		if(estado != 0){
			break;//si se tiene un estado se rompe for de horas
		}
	}
	return estado;
}
void encender(int tiempo){
	switch (tiempo) {//switch para cambiar estado de los leds
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_SET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_SET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_SET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_SET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
			break;
		case 10:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
			break;
		case 11:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
			break;
		default:
			break;
	}
}
void apagar(int tiempo){
	switch (tiempo) {//switch para cambiar estado de los leds
		case 0:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
			break;
		case 1:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
			break;
		case 2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_15, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, GPIO_PIN_RESET);
			break;
		case 8:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
			break;
		case 10:
			HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
			break;
		case 11:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}
int run(int tiempo[]){//estado run
	int estado = 2;//se define el estado actual
	encender(tiempo[0]);//se enciende led de las horas
	for (int i = 0; i < 5; ++i) {//ciclo de parpadeo minutos
		encender(tiempo[1] / 5);//encendido
		HAL_Delay(300);//espera
		apagar(tiempo[1] / 5);//apagado
		HAL_Delay(300);//espera
	}
	apagar(tiempo[0]);//apagar hora
	estado = 1;//estado principal
	return estado;//retorno
}

int set(int tiempo[]){
	int estado = 3;//estado
	int button;//pulso
	int time = 0;//tiempo en seg
	int time2 = 0;
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);//pitido on
	HAL_Delay(300);//espera 300 ms
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);//pitido off
	HAL_Delay(300);//esperar 300 ms
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);//pitido on
	HAL_Delay(300);//esperar 300ms
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);//pitido off
	encender(tiempo[0]);//encender las horas
	do{
		button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//leer boton
		while (button == GPIO_PIN_SET){//mientras este presionado
			button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//seguir leyendo boton
			time = time + 1;//sumar al tiempo
			HAL_Delay(1000);//esperar un segundo
		}
		if(time >= 5){//si el pulso es mayo a 5 seg
			apagar(tiempo[0]);// apagar horas
			encender(tiempo[1] / 5); // encender min
			//for para horas
			for (int i = tiempo[0];  i < 12; ++ i) {
					//for para los minutos
					for (int j = tiempo[1]; j < 60; ++j) {
						//for para los segundos
						for (int k = tiempo[2]; k < 60; ++k) {
							button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//leer boton
							while (button == GPIO_PIN_SET){//mientras este presionado
								button = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12);//seguir leyendo boton
								time2 = time2 + 1;//sumer tiempo
								HAL_Delay(1000);//esperar un seg
							}
							if(time2 > 0 && time2 < 5){//si el pulso es menor a 5
								apagar(tiempo[1] / 5);//apagar min
								if(tiempo[1] == 60){
									tiempo[1] = 0;
								}else if(tiempo[1] < 60){
									tiempo[1] = tiempo[1] + 5;//sumar 5 min
								}
								encender(tiempo[1] / 5);//encender min
								HAL_Delay(2000);
								apagar(tiempo[1] / 5);//apagar min
								time2 = 0;
							}else if (time2 >= 5){//si el pulso es mayor a 5
								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_SET);//pitido on
								HAL_Delay(2000);//esperar 2 seg
								HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, GPIO_PIN_RESET);//pitido off
								estado = 1;//estado en principal
								apagar(tiempo[1]/5);//apagar horas
								break;//romper for seg
							}
							HAL_Delay(1000);//esperar un segundo
						}
						if(estado == 1){//si cambio el estado
							break;//romper min
						}
					}
					if(estado == 1){//si cambio el estado
							break;//romper horas
					}
			}
		}else if(time > 0 && time < 5){//si el pulso es menor a 5
			apagar(tiempo[0]);//apagar horas
			if (tiempo[0]== 11){
				tiempo[0] = 0;//se reinicia la hora
			}else if(tiempo[0]<11){
				tiempo[0] = tiempo[0] + 1;//sumar 1 hora
			}
			encender(tiempo[0]);//encender horas
			time = 0;
		}
	}while(estado == 3);
	return estado;//retornar estado
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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
