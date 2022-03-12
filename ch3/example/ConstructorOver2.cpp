#include <iostream>

using namespace std;

class CMyPoint
{
    int m_x = 0;
    int m_y = 0;

public:
    CMyPoint(int x)
    {
        cout<<"CMyPoint(int x)"<<endl;

        if(x>100) x=100;

        m_x = 100;
    }

    CMyPoint(int x, int y) : CMyPoint(x)
    {
        cout<<"CMyPoint(int, int)"<<endl;

        if(y>200) y = 200;

        m_y = 200;
    }

    void Print()
    {
        cout << "X:" << m_x << endl;
        cout << "Y:" << m_y << endl;
    }
};

int main()
{
    CMyPoint ptBegin(110);
    ptBegin.Print();

    CMyPoint ptEnd(50, 250);
    ptEnd.Print();
    
    return 0;
}