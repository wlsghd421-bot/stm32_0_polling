#include <stdio.h>
#include <stdlib.h>
#include "main.h"
GPIO_TypeDef MOCK_GPIOA, MOCK_GPIOC;
TIM_HandleTypeDef htim3 = {(void *)3}, htim6 = {(void *)6};
UART_HandleTypeDef huart2 = {(void *)2}, huart3 = {(void *)3};
static uint32_t g_ms; static int g_btn; static int g_led; static int tim6_on;
static uint32_t g_cmp = 0; static int pwm_on = 0; static int mode;
uint32_t HAL_GetTick(void) { return g_ms; }
GPIO_PinState HAL_GPIO_ReadPin(GPIO_TypeDef *p, uint16_t pin) { return g_btn ? GPIO_PIN_SET : GPIO_PIN_RESET; }
void HAL_GPIO_TogglePin(GPIO_TypeDef *p, uint16_t pin) { g_led ^= 1; printf("t=%6u ms  PA5 -> %d\n", g_ms, g_led); }
int HAL_TIM_Base_Start_IT(TIM_HandleTypeDef *h) { tim6_on = 1; return 0; }
int HAL_TIM_PWM_Start(TIM_HandleTypeDef *h, uint32_t ch) { pwm_on = 1; return 0; }
void mock_set_compare(TIM_HandleTypeDef *h, uint32_t ch, uint32_t v) { g_cmp = v; printf("t=%6u ms  CCR1 = %u (%u%%)\n", g_ms, v, v / 10); }
void ece2_474_init(void); void polling_routine(void);
/* 입력: 0 = 2550/7050/12050/21050에 100 ms 눌림(누를 때·뗄 때 EXTI 호출), 1 = 2550에 5초 누름,
   2 = 2550에 누르는 순간 6 ms 떨림, 3 = 과제4용 1000/2000/3000/4000에 눌림 */
int main(int argc, char **argv) {
    mode = argc > 1 ? atoi(argv[1]) : 0;
    ece2_474_init();
    uint32_t end = (mode == 3) ? 5200 : 25000;
    for (g_ms = 1; g_ms <= end; g_ms++) {
        int press = 0, release = 0;
        if (mode == 0) { uint32_t p[4] = {2550, 7050, 12050, 21050}; for (int i = 0; i < 4; i++) { if (g_ms == p[i]) press = 1; if (g_ms == p[i] + 100) release = 1; } }
        if (mode == 1) { if (g_ms == 2550) press = 1; if (g_ms == 7550) release = 1; }
        if (mode == 2) { if (g_ms == 2550 || g_ms == 2553 || g_ms == 2556 || g_ms == 2559) press = 1; if (g_ms == 2552 || g_ms == 2555 || g_ms == 2558) release = 1; if (g_ms == 2650) release = 1; }
        if (mode == 3) { uint32_t p[4] = {1000, 2000, 3000, 4000}; for (int i = 0; i < 4; i++) { if (g_ms == p[i]) press = 1; if (g_ms == p[i] + 100) release = 1; } }
        if (g_ms % 100 == 0 && tim6_on) HAL_TIM_PeriodElapsedCallback(&htim6);
        if (press) { g_btn = 1; HAL_GPIO_EXTI_Callback(BUTTON_ece2_Pin); }
        if (release) { g_btn = 0; HAL_GPIO_EXTI_Callback(BUTTON_ece2_Pin); }
        polling_routine();
    }
    return 0;
}
