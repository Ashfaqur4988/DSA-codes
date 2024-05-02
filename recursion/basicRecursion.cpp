#include <iostream>
using namespace std;
int count = 1;
void func1()
{

    cout << count << endl;
    count++;

    if (count >= 4)
    {
        return;
    }
    func1();
}
int main()
{
    func1();
    return 0;
}