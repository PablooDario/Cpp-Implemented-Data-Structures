#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr){}
};

class Queue
{
    private:
        int size;
        Node *front;
        Node *back;
    public:
        Queue() : size(0), front(nullptr), back(nullptr) {}
        void Push (int x);
        void Pop ();
        int Front ();
        int Back ();
        int Size ();
        bool Empty ();
        void PrintQueue ();
        void Clear ();

};

void Queue::Push (int x)
{
    Node *newnode =new Node(x);
    if(size==0)
    {
        front=newnode;
        back=newnode;
        size++;
        return ;
    }
    back->next=newnode;
    back=back->next;
    size++;
}

void Queue::Pop ()
{
    if(size==0)
        return;
    Node *aux=front;
    if(size==1)
    {
        delete(aux);
        back=nullptr;
        front=nullptr;
        size--;
        return ;
    }
    front=aux->next;
    aux->next=nullptr;
    delete(aux);
    size--;
}

int Queue::Front ()
{
    if(size==0)
        return INT_MIN;
    return front->value;
}

int Queue::Back ()
{
    if(size==0)
        return INT_MIN;
    return back->value;
}

int Queue::Size ()
{
    return size;
}

bool Queue::Empty ()
{
    if(size==0)
        return true;
    return false;
}

void Queue::PrintQueue ()
{
    if(size==0)
    {
        cout<<"Empty Queue"<<endl;
        return;
    }
    Node *aux=front;
    while(aux)
    {
        cout<<aux->value;
        aux=aux->next;
        if(aux)
            cout<<", ";
    }
}

void Queue::Clear()
{
    while(size>0)
        Pop();
}