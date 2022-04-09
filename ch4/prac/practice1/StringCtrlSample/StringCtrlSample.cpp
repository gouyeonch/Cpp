#include "stdafx.h"
#include "MyString.cpp"

void TestFunc(const CMyString &param)
{
    cout<<param.GetString()<<endl;
}

int main()
{
    CMyString strData, strTest;
    strData.SetString("Hello");
    strTest.SetString("World");

    CMyString strNewData(strData);
    cout <<strNewData.GetString()<<endl;

    strNewData = strTest;
    cout<<strNewData.GetString()<<endl;

    TestFunc(strData);

    return 0;
}