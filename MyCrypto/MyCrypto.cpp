#include "pch.h"
#include "MyCrypto.h" 
#include "SHA256.h"   
#include <cstring>
#include <string>


const std::string ADMIN_ID = "admin";
// "admin12"의 해시값
const std::string ADMIN_PW_HASH = "114663ab194edcb3f61d409883ce4ae6c3c2f9854194095a5385011d15becbef";

//외부 input 해시 생성
static std::string InternalGenerateHash(const char* input)
{
    try {
        SHA256 sha;
        sha.update(input);
        uint8_t* digest = sha.digest();
        std::string hstr = SHA256::toString(digest);
        delete[] digest;
        return hstr;
    }
    catch (...) {
        return "";
    }
}

// ID와 PW를 받아서 true/false 리턴
extern "C" __declspec(dllexport) bool CheckLogin(const char* id, const char* pw)
{
    if (id == nullptr || pw == nullptr) return false;

    // 아이디 검사
    if (ADMIN_ID != id) {
        return false;
    }

    // 비밀번호 해싱
    std::string inputHash = InternalGenerateHash(pw);

    // 해시값 비교
    if (inputHash == ADMIN_PW_HASH) {
        return true;
    }

    //비밀번호 실제 입력된 값(디버그용)
    //else {
    //    MessageBoxA(NULL, inputHash.c_str(), "DLL 디버그 (값 비교)", MB_OK);
    //}

    return false;
}