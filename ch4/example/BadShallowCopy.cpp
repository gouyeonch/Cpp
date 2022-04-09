#include <iostream>

using namespace std;

int main()
{
    int *pa, *pb;

    pa = new int;
    *pa = 10;

    pb = new int;
    pb = pa;

    cout << *pa << endl;
    cout << *pb << endl;

    delete pa;
    delete pb;

    return 0;
}