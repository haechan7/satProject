# Function Graph Visualizer

SDL2 기반 C++ 그래프 시각화 프로그램

---

## 1. 개요

이 프로그램은 사용자가 입력한 수학적 함수를 2D 그래프 형태로 시각화합니다.  
현재 지원되는 함수는 다음과 같습니다:

- 다항함수 (Polynomial)
- 절대값 포함 다항함수 (Absolute Polynomial)
- 삼각함수 (sin, cos, tan)

---

## 2. 주요 특징

| 기능 | 설명 |
|------|------|
| 사용자 입력 기반 그래프 생성 | 계수 입력을 통해 다양한 형태의 실수 함수 출력 |
| SDL2 기반 렌더링 | 축, 눈금, 좌표 기반 스케일링 포함 |
| 확장 가능한 구조 | Function 클래스 + Factory 패턴으로 기능 확장 가능 |

---

## 3. 프로그램 구조

```text
src/
├── main.cpp
├── renderer.* // 화면 그리기 및 이벤트 처리
├── mymath.* // 수학 유틸
├── function.* // 함수 인터페이스
├── functionfactory.* // 객체 생성
├── polynomialfunction.*
├── abspolynomialfunction.*
├── sinfunction.*
├── cosfunction.*
└── tanfunction.*
```

---

## 4. 설치 및 실행 방법

### SDL2 설치 (Windows / Visual Studio)

1. SDL2 Development Libraries 다운로드
2. 다음 라이브러리를 프로젝트에 추가:

SDL2.lib
SDL2main.lib

3. `SDL2.dll`을 실행 파일 `.exe` 위치에 복사

---

### 실행

프로젝트를 빌드 후 콘솔 입력을 따라 함수 계수를 입력합니다.

예시:

함수 선택 → 1
계수 입력 → 1 2 1 -9999 // y = x^2 + 2x + 1

## 5. License

본 프로젝트는 MIT License 하에 자유롭게 사용, 수정, 배포가 가능합니다.

---

## 6. 제작자

| 이름 | 역할 |
|------|------|
| 이해찬 | 개발 및 설계 |
| 공승환 | 개발 및 설계 |