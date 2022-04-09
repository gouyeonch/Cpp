#include <iostream>

using namespace std;

class CMyData
{
    int *m_pnData;
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

    int GetData()
    {
        if(m_pnData != NULL) return *m_pnData;

        return 0;
    }
};

int main()
{
    CMyData a(10);
    CMyData b(a);
    cout<<a.GetData()<<endl;
    cout<<b.GetData()<<endl;

    return 0;
}