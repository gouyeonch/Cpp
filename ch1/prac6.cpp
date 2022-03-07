#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int aList[6] = {10,100, 20,30,40,50};

    for(auto &n : aList)
        cout<<n<<' ';
    cout<<endl;

    sort(aList, aList+6);

    for(auto &n : aList)
        cout<<n<<' ';
    cout<<endl;
}