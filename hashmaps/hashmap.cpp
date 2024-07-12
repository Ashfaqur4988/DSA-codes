#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> m;

    // insertion
    pair<string, int> p = make_pair("hello", 1);
    m.insert(p);

    pair<string, int> p2("name", 3);
    m.insert(p2);

    m["my"] = 2;

    // search
    cout << m["hello"] << endl;
    // cout << m["name"] << endl;
    cout << m["my"] << endl;

    cout << m.at("name") << endl;

    cout << m.size() << endl;

    // count
    cout << m.count("name") << endl;

    // erase
    m.erase("name");

    cout << m.size() << endl;

    // traversing using iterator
    unordered_map<string, int>::iterator it = m.begin();

    while (it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++;
    }
    return 0;
}