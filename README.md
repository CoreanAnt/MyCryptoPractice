# MyCrypto Practice Project

MFC와 C++ DLL을 활용한 로그인 및 SHA256 암호화 연습 프로젝트입니다.

## 구조
- **MyCrypto (DLL)**: SHA256 알고리즘을 이용해 비밀번호 검증을 수행하는 라이브러리
- **LoginApp (MFC)**: 사용자 입력을 받아 DLL 함수를 호출하는 UI 프로그램

## 실행 방법
이 프로젝트는 DLL이 분리되어 있으므로 실행 시 DLL 파일이 필요합니다.

1. 솔루션을 빌드합니다 (Build Solution).
2. LoginApp.exe와 MyCrypto.dll 두 파일을 동일 디렉토리에 위치시킵니다.
3. `LoginApp.exe`를 실행합니다.

## 테스트 계정
- **ID**: admin
- **PW**: admin12
