#pragma once
#include "SHA256.h"

#ifdef MYCRYPTO_EXPORTS
#define MYCRYPTO_API __declspec(dllexport)
//(LoadLibrary와 GetProcAddress를 사용하는 연결방식을 사용할 예정이라 import는 없어도 됨)
//#else
//#define MYCRYPTO_API __declspec(dllimport)
#endif

// C 스타일로 함수를 노출하여 이름 뒤틀림 방지
extern "C" {
    // 입력 문자열을 받아 SHA256 해시된 16진수 문자열로 반환하는 함수
    // outputHex: 결과를 담을 버퍼, maxOutputLen: 버퍼 크기 (최소 65바이트 필요)
    MYCRYPTO_API bool CheckLogin(const char* id, const char* pw);
}