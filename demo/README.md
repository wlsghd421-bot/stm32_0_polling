# STM32_0 실험 시연 자료 (2026-10-12)

보드: NUCLEO-G474RE, 환경: STM32CubeIDE for VS Code

| 파일 | 내용 |
|---|---|
| `task1_vscode_serial.jpg` | 과제 1 실행 중 VS Code 화면. 위쪽은 `polling_routine()`의 버튼 처리 코드(65행에 중단점), 아래쪽은 Serial Monitor(COM5, 9600 baud)의 `Hello, World!` 출력 |
| `task2_external_led.jpg` | 과제 2. PB0에 저항과 적색 LED를 연결해 LED가 켜진 순간 |
| `task1_interval.MOV` | 과제 1 영상: 버튼으로 점멸 간격이 1→2→4→8→1초로 바뀌는 동작 (아래 "영상" 참고) |
| `task2_external_led.MOV` | 과제 2 영상: 외부 LED 점멸과 버튼 동작 |

## 영상
영상은 용량(약 40 MB) 때문에 별도 파일로 이 폴더에 추가했다. 원본은 Google Drive에도 있다.

- 과제 1 폴더: https://drive.google.com/drive/folders/1o4reZISh4F2I-nM__OpyyHjFJqpka5r2
- 과제 2 폴더: https://drive.google.com/drive/folders/18YbQjAYOEPnQItyq24ZAqajCXkeIzX1z

## 참고
- 과제 1 사진 속 코드는 `interval_ms`를 2배씩 올리는 형태이며, 제출한 `submission/task1_interval.c`(표 `interval_ms[4]`와 `idx` 사용)와 구현 방식이 다르다. 두 코드의 동작 순서(1→2→4→8→1초)는 같다.
