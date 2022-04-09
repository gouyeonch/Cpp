#include <iostream>

using namespace std;

class Test
{
    int* mem;
public:
    Test(int a) : mem(&a) {}; 
    void setmem(int s)
    {
        *mem = s;
    }
    int GetMem()
    {
        return *mem;
    }
};

int main()
{
    Test a(10);
    Test b(a);

    cout<<a.GetMem()<<endl;
    b.setmem(99);
    cout<<a.GetMem()<<endl;

    return 0;
}