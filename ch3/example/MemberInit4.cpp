#include <iostream>

using namespace std;

class CTest
{
public:
    CTest()
    {
        m_nData = 10;
    }

    int m_nData;

    void PrintData(void);
};

void CTest::PrintData(void)
{
    cout<<"CTest 생성자 함수"<<endl;
    cout<<m_nData<<endl;
}

int main()
{
    cout<<"main함수 시작"<<endl;

    CTest t;
    t.PrintData();

    cout<<"main함수 종료"<<endl;

    return 0;
}