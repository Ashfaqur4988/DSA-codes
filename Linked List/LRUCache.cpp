#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
    class Node
    {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;

        Node(int key, int val)
        {
            this->key = key;
            this->val = val;
        }
    };

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int capacity;
    unordered_map<int, Node *> m;

    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node *newNode)
    {
        Node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    void deleteNode(Node *delNode)
    {
        Node *delPrev = delNode->prev;
        Node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        // if exist, finding in map
        if (m.find(key) != m.end())
        {
            // create the node
            Node *resNode = m[key];
            // take the val of the node to return
            int res = resNode->val;
            // remove from hashmap
            m.erase(key);
            // delete node from the DLL
            deleteNode(resNode);
            // insert it at the beginning, next to head
            addNode(resNode);
            // re assign the new node to the hashmap
            m[key] = head->next;
            // return
            return res;
        }
        // if donot exist
        return -1;
    }

    void put(int key, int val)
    {
        // if exist find in map
        if (m.find(key) != m.end())
        {
            // new node to store the searched node
            Node *existingNode = m[key];
            // erase from hashmap
            m.erase(key);
            // delete the node;
            deleteNode(existingNode);
        }
        // if capacity full?
        if (m.size() == capacity)
        {
            // erase from hashmap
            m.erase(tail->prev->key);
            // delete the LRU node,nearest to tail
            deleteNode(tail->prev);
        }
        // add the new node to the DLL
        addNode(new Node(key, val));
        // insert in the hashmap
        m[key] = head->next;
    }
};

int main()
{

    return 0;
}