//cpp에서 auto 예약어는 자료형을 알아서 자동으로 결전되어 초기값에 맞춘다
#include <iostream>

using namespace std;

void outputFunc(auto element){
    cout<<sizeof(element)<<endl;
}

int main(){

    int a;
    char b;
    double c;

    outputFunc(a);
    outputFunc(b);
    outputFunc(c);
}