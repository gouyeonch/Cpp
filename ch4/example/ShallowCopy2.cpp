#include <iostream>

using namespace std;

class CMyData
{
    int *m_pnData = nullptr;
public:
    CMyData(int nParam)
    {
        m_pnData = new int;
        *m_pnData = nParam;
    }

    CMyData(const CMyData &rhs)
    {
        cout<<"CMyData(const CMyData &)"<<endl;

        m_pnData = new int;
        *m_pnData = *rhs.m_pnData;
    }

    ~CMyData() {delete m_pnData;}

    CMyData& operator=(const CMyData &rhs)
    {
        *m_pnData = *rhs.m_pnData;
        return *this;
    }

    int GetData()
    {
        if(m_pnData != NULL) return *m_pnData;

        return 0;
    }
};

int main()
{   
    CMyData a(10);
    CMyData b(20);

    a=b;
    cout<<a.GetData()<<endl;

    return 0;
}