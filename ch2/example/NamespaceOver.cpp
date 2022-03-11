#include <iostream>

using namespace std;

void TestFunc(void) {cout<<"::TestFunc()"<<endl;}

namespace TEST
{
    void TestFunc(void)
    {
        cout<<"TEST::TestFunc()"<<endl;
    }
}

namespace MYDATA
{
    void TestFunc(void)
    {
        cout<<"MYDATA::TestFunc()"<<endl;
    }
}

int main()
{
    TestFunc();
    ::TestFunc();
    TEST::TestFunc();
    MYDATA::TestFunc();
    
    return 0;
}