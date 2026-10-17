# STM32_1 · 인터럽트와 PWM (2026-10-19 예비)

- `submission/task3_isr_interval.c` — 과제3: 버튼 인터럽트 + TIM6(100 ms)로 LED 간격 1→2→4→8→1초
- `submission/task4_pwm_duty.c` — 과제4: 버튼으로 PB4(TIM3 CH1) PWM 25→50→75→25 %
- `host_sim/` — 보드 없이 PC에서 ISR 논리를 확인한 하니스(`tb1.c`, 가짜 HAL `mock/`)와 결과 `results/`

## 컴퓨터 시뮬레이션 (gcc)
```
gcc -I host_sim/mock -o t3 host_sim/tb1.c submission/task3_isr_interval.c && ./t3 0
gcc -I host_sim/mock -o t4 host_sim/tb1.c submission/task4_pwm_duty.c && ./t4 3
```
시나리오 0: 정상 누름, 1: 5초 누름, 2: 접점 떨림. 결과는 `host_sim/results/`.
`task3_bad_no_pressed_check.c`는 눌림 상태 확인을 뺀 비교용 코드로, 5초 누름에서 간격이 여러 번 바뀌어 FAIL이 재현된다.
