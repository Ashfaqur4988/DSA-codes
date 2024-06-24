#include <iostream>
#include <queue>
#include <list>
using namespace std;
int Time = 0;

class Animal
{
public:
    int time;
    string name;
    string type;
};

class Dogs : public Animal
{
public:
    Dogs(string name)
    {
        type = "dog";
        this->name = name;
    }
};

class Cats : public Animal
{
public:
    Cats(string name)
    {
        type = "cat";
        this->name = name;
    }
};

class AnimalQueue
{
public:
    queue<Dogs> dogs;
    queue<Cats> cats;

    void enqueue(Dogs d)
    {
        d.time = Time++;
        dogs.push(d);
    }

    void enqueue(Cats c)
    {
        c.time = Time++;
        cats.push(c);
    }

    Dogs dequeueDog()
    {
        Dogs d = dogs.front();
        dogs.pop();
        return d;
    }

    Cats dequeueCat()
    {
        Cats c = cats.front();
        cats.pop();
        return c;
    }

    Animal dequeueAny()
    {

        Dogs d = dogs.front();
        Cats c = cats.front();

        return (d.time < c.time ? (Animal)dequeueDog() : (Animal)dequeueCat());
    }
};

int main()
{

    AnimalQueue s;
    Dogs d1("Tommy"), d2("Buster"), d3("Oscar"), d4("Daisy");
    Cats c1("Ginger"), c2("Lily"), c3("Lucy"), c4("Silky");
    s.enqueue(d1);                         // Tommy
    s.enqueue(c1);                         // Ginger
    s.enqueue(d2);                         // Buster
    s.enqueue(c2);                         // Lily
    s.enqueue(c3);                         // Lucy
    s.enqueue(d3);                         // Oscar
    s.enqueue(d4);                         // Daisy
    s.enqueue(c4);                         // Silky
    cout << (s.dequeueAny()).name << "\n"; // Tommy
    cout << (s.dequeueDog()).name << "\n"; // Buster
    cout << (s.dequeueAny()).name << "\n"; // Ginger
    cout << (s.dequeueAny()).name << "\n"; // Lily
    cout << (s.dequeueDog()).name << "\n"; // Oscar
    cout << (s.dequeueAny()).name << "\n"; // Lucy
    cout << (s.dequeueCat()).name << "\n"; // Silky
    cout << (s.dequeueAny()).name << "\n"; // Daisy
    return 0;
}