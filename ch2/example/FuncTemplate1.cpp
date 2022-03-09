#include <iostream>

using namespace std;

template <typename T>
T TestFunc(T a)
{
    cout<<"매개변수 a: "<< a << endl;

    return a;
}

int main()
{
    cout<<TestFunc(3)<<"int\t"<<endl;
    cout<<TestFunc(3.3)<<"double\t"<<endl;
    cout<<TestFunc('A')<<"char\t"<<endl;
    cout<<TestFunc("TestString")<<"char*\t"<<endl;

    return 0;
}