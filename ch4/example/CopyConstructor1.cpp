#include <iostream>

using namespace std;

class CMyData
{
    int m_nData = 0;
public:
    CMyData() {cout<<"CMyData()"<<endl;}

    CMyData(const CMyData &rhs)
    {
        this->m_nData = rhs.m_nData;
        cout<<"CMyData(const CMyData &)"<<endl;
    }

    int GetData(void) const {return m_nData;}
    void SetData(int nParam) {m_nData = nParam;}
};

int main()
{
    CMyData a;
    a.SetData(10);

    CMyData b(a);
    cout << b.GetData() << endl;

    return 0;
}