#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node() : value(0), next(nullptr){}
    Node(int x) : value(x), next(nullptr){}
};

class Stack 
{
    private:
        Node *top;
        int size;
    public:
        Stack() : size(0), top(nullptr) {}
        void Push (int);
        void Pop ();
        int Top ();
        bool Empty ();
        int Size ();
        void clear ();
        void Print_stack();
};

void Stack::Push (int x)
{
    Node *newnode = new Node(x);
    newnode->next=top;
    top=newnode;
    size++;
}

void Stack::Pop ()
{
    if(size==0)
        return ;
    Node *aux=top;
    top=aux->next;
    aux->next=nullptr;
    delete(aux);
    size--;
}

int Stack::Top ()
{
    if(!top)
        return INT_MIN;
    return top->value;
}

bool Stack::Empty ()
{
    if(size==0)
        return true;
    return false;
}

int Stack::Size ()
{
    return size;
}

void Stack::clear ()
{
    while(size>0)
        Pop();
}

void Stack::Print_stack()
{
    if(Empty())
    {
        cout<<"The stack is empty"<<endl;
        return ;
    }
    Node* aux=top;
    while(aux)
    {
        cout<<aux->value;
        aux=aux->next;
        if(aux)
            cout<<", ";
    }
}