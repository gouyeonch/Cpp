#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString()
    : m_pszData(nullptr), m_nLength(0)
{

}

CMyString::~CMyString()
{
    Release();
}

int CMyString::SetString(const char* pszParam)
{  

    //문자열 길이 측정하고 m_nLength에 저장
    this->m_nLength = strlen(pszParam);

    //메모리 동적할당 하고, 문자열 저장
    this->m_pszData = new char[this->m_nLength + 1];
    this->m_pszData = pszParam;

    return 0;
}

const char* CMyString::GetString()
{
    return this->m_pszData;
}

void CMyString::Release()
{
    if(m_pszData != NULL)
        delete[] m_pszData;

    m_pszData = nullptr;
    m_nLength = 0;
}