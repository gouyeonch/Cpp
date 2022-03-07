#include <iostream>

using namespace std;

int main()
{
    char *str = new char[12];

    cin>>str;
    cout<<str<<endl;

    delete[] str;

    return 0;
}