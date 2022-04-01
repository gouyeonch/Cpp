#include <iostream>

using namespace std;

class CMyData
{
    int m_nData;
public:
    CMyData() : m_nData(0){};

    int GetData(void) {return m_nData;}
    void SetData(int nParam){m_nData=nParam;}

    void SetData(double nParam) = delete;
};

int main()
{
    CMyData a;

    a.SetData(10);
    cout<<a.GetData()<<endl;

    CMyData b;

    b.SetData(5.5);
    cout<<b.GetData()<<endl;

    return 0;
}