#include "stdafx.h"
#include "MyString.cpp"

void TestFunc(const CMyString &param)
{
    cout<<param.GetString()<<endl;
}

int main()
{
    CMyString strData;
    strData.SetString("Hello");
    TestFunc(strData);

    return 0;
}