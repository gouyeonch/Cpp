#include "stdafx.h"
#include "MyString.h"

CMyString::CMyString()
    : m_pszData(nullptr), m_nLength(0)
{

}

CMyString::CMyString(const CMyString &rhs)
    : m_pszData(NULL), m_nLength(0)
{
    this->SetString(rhs.GetString());
}

CMyString& CMyString::operator=(const CMyString &rhs)
{
    if(this != &rhs) this->SetString(rhs.GetString());

    return *this;
}

CMyString::~CMyString()
{
    Release();
}

int CMyString::SetString(const char* pszParam)
{  
    Release();
    
    if(pszParam == NULL) return 0;

    //문자열 길이 측정하고 m_nLength에 저장
    this->m_nLength = strlen(pszParam);
    if(m_nLength == 0) return 0;

    //메모리 동적할당 하고, 문자열 저장
    this->m_pszData = new char[this->m_nLength + 1];
    strcpy(m_pszData, pszParam);

    return 0;
}

const char* CMyString::GetString() const
{
    return this->m_pszData;
}

void CMyString::Release()
{
    if(m_pszData != NULL) delete[] m_pszData;

    m_pszData = nullptr;
    m_nLength = 0;
}