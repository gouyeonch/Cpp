#include "stdafx.h"
#include "MyString.cpp"

int main()
{
    CMyString strData;
    strData.SetString("Hello");
    cout<<strData.GetString()<<endl;

    return 0;
}