#include <iostream>

using namespace std;

class CTest
{
    int m_nData;
public:
    CTest(int nParam) : m_nData(nParam) {};
    ~CTest() {}

    int GetData() const
    {
        return m_nData;
    }

    int SetData(int nParam) {m_nData = nParam;}
};

int main()
{
    CTest a(10);
    cout<<a.GetData()<<endl;

    return 0;
}