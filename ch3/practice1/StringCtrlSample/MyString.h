#pragma

class CMyString
{
    const char* m_pszData;
    int m_nLength;
public:
    CMyString();
    ~CMyString();
    int SetString(const char* pszParam);
    const char* GetString();
    void Release();
};