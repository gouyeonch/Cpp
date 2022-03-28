#include <iostream>

using namespace std;

class CMyData
{
    int m_nData;

public:
    CMyData(int nParam) : m_nData(nParam) {};
    void PrintData()
    {
        cout<< m_nData<<endl;

        cout<<CMyData::m_nData<<endl;

        cout<<this->m_nData<<endl;

        cout<<this->CMyData::m_nData<<endl;
    }
};

int main()
{
    CMyData a(5), b(10);

    a.PrintData();
    b.PrintData();

    return 0;
}