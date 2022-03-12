#include <iostream>

using namespace std;

class CTest
{
    public:
    CTest(void) = default;
    int m_nData = 5;
};

int main()
{
    CTest a;
    cout<<a.m_nData<<endl;

    return 0;
}