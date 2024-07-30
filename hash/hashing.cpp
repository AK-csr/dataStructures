#include<iostream>

struct Person{
    int key;
    int name;
};

struct Node{
    Node* next;
    Person item;
};

int h(int k, int m)
{
    return k % m;
}

void insert(Person* xPtr, Person** T, int m)
{
    int i = h(xPtr->key, m);
    for (int j = 0; j < m; j++)
    {
        if (T[i] == nullptr)
        {
            T[i] = xPtr;
            return;
        }
        else
        {
            i = (i+1)%m;
        }
    }
}

bool search(int k, Person& x, Node** T, int m)
{
    int i = h(k, m);
    Node*p = T[i];
    while( p != nullptr)
    {
        if (p->item.key == k)
        {
            x = p->item;
            return true;
        }
        p = p->next;
    }
    return false;
}


int main()
{

}