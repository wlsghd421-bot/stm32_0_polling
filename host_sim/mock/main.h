#ifndef MOCK_MAIN_H
#define MOCK_MAIN_H
#include <stdint.h>
typedef enum { GPIO_PIN_RESET = 0, GPIO_PIN_SET = 1 } GPIO_PinState;
typedef struct { int id; } GPIO_TypeDef;
extern GPIO_TypeDef MOCK_GPIOA, MOCK_GPIOC;
#define LED_ece2_GPIO_Port (&MOCK_GPIOA)
#define LED_ece2_Pin 0x0020
#define BUTTON_ece2_GPIO_Port (&MOCK_GPIOC)
#define BUTTON_ece2_Pin 0x2000
#define GPIO_IN_PULLUP_ece2_Pin 0x0001
#define GPIO_IN_PULLDOWN_ece2_Pin 0x0002
typedef struct { void *Instance; } TIM_HandleTypeDef;
typedef struct { void *Instance; } UART_HandleTypeDef;
#define TIM6 ((void *)6)
#define USART2 ((void *)2)
#define USART3 ((void *)3)
#define TIM_CHANNEL_1 0U
uint32_t HAL_GetTick(void);
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *p, uint16_t pin);
void HAL_GPIO_TogglePin(GPIO_TypeDef *p, uint16_t pin);
int HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *h);
int HAL_TIM_PWM_Start(TIM_HandleTypeDef *h, uint32_t ch);
void mock_set_compare(TIM_HandleTypeDef *h, uint32_t ch, uint32_t v);
#define __HAL_TIM_SET_COMPARE(h, ch, v) mock_set_compare((h), (ch), (v))
extern TIM_HandleTypeDef htim3, htim6;
extern UART_HandleTypeDef huart2, huart3;
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim);
#endif
