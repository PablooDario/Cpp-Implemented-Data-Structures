#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int value;
    Node *next;
    Node() : value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr){}
};

class Deque
{
    private:
        Node *front;
        Node *back;
    public:
        Deque() : front(nullptr), back(nullptr) {}
        void Push_back (int);
        void Push_front (int);
        void Pop_back ();
        void Pop_front ();
        int Front ();
        int Back ();
        bool Empty ();
        void PrintDeque ();
        void Clear ();

};

void Deque::Push_front(int x)
{
    Node *newnode = new Node(x);
    if(!back and !front)
    {
        front=newnode;
        back=newnode;
        return ;
    }
    newnode->next=front;
    front=newnode;
}

void Deque::Push_back (int x)
{
    Node *newnode =new Node(x);
    if(!back and !front)
    {
        front=newnode;
        back=newnode;
        return ;
    }
    back->next=newnode;
    back=back->next;
}

void Deque::Pop_front ()
{
    if(!front)
        return;
    Node *aux=front;
    if(front==back)
    {
        delete(aux);
        back=nullptr;
        front=nullptr;
        return ;
    }
    front=aux->next;
    aux->next=nullptr;
    delete(aux);
}

void Deque::Pop_back ()
{
    if(!back)
        return ;
    Node *aux=front;
    if(front==back)
    {
        delete(aux);
        back=nullptr;
        front=nullptr;
        return ;
    }
    while(aux->next!=back)
        aux=aux->next;
    aux->next=nullptr;
    delete(back);
    back=aux;
}

int Deque::Front ()
{
    if(!front)
        return INT_MIN;
    return front->value;
}

int Deque::Back ()
{
    if(!back)
        return INT_MIN;
    return back->value;
}

bool Deque::Empty ()
{
    if(!front and !back)
        return true;
    return false;
}

void Deque::PrintDeque ()
{
    if(!back and !front)
    {
        cout<<"Empty Deque"<<endl;
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

void Deque::Clear()
{
    while(front)
        Pop_front();
}