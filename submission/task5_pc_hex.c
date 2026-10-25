#include <stdio.h>
#include "main.h"
void polling_routine(void);

/* 과제 5: PC에서 받은 문자 한 개와 그 바이트 값을 16진수로 출력합니다. */
void polling_routine(void)
{
    int ch = getchar();                 /* 입력이 올 때까지 기다림 */
    if (ch != EOF)
    {
        printf("받은 문자: %c, 값: 0x%02X\r\n", ch, ch);
    }
}