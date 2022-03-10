#include <iostream>

using namespace std;

namespace TEST
{
    int g_nData = 100;

    void TestFunc(void)
    {
        cout<<"TEST::TestFunc()"<<endl;
    }
}

int main()
{
    TEST::TestFunc();
    cout<<TEST::g_nData<<endl;
    
    return 0;
}