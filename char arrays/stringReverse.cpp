#include <iostream>
using namespace std;

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        swap(name[s++], name[e--]);
    }
}

int main()
{
    char name[20];
    cout << "enter name " << endl;
    cin >> name;
    cout << "name is " << name << endl;
    int n = getLength(name);
    cout << "length is " << n << endl;
    reverse(name, n);
    cout << "reverse is " << name << endl;

    return 0;
}