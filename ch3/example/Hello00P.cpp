#include <iostream>

using namespace std;

class USERDATA
{
public:
    int nAge;
    char szName[32];

    void Print(void)
    {
        cout<<nAge<<", "<<szName<<endl;
    }
};

int main()
{
    USERDATA user = {24 , "구연"};

    user.Print();

    return 0;
}