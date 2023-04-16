#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int value;
    Node *prev, *next;
    Node () : value(0), prev(nullptr), next(nullptr) {}
    Node (int x) : value(x), prev(nullptr), next(nullptr) {}
};

class DList
{
    private:
        Node *head, *tail;
    public:
        DList () : head(nullptr), tail(nullptr) {}
        void Push_back(int);
        void Push_front(int);
        void Insert(int, int);
        bool Empty ();
        void Print_list();
        void Print_reverse_list();
        Node* Find(int);
        void Erase (int);
        void Pop_back();
        void Pop_front();
        int Front();
        int Back();
        void Clear ();
};

bool DList::Empty ()
{
    if(head and tail)
        return false;
    return true;
}

void DList::Push_back(int x)
{   
    Node *newnode= new Node(x);
    if(!head and !tail)
    {
        head=newnode;
        tail=newnode;
    }
    else
    {
        tail->next=newnode;
        newnode->prev=  tail;
        tail=newnode;
    }
}

void DList::Push_front(int x)
{
    Node *newnode = new Node(x);
    if(!head and !tail)
    {
        head=newnode;
        tail=newnode;        
    }
    else
    {
        newnode->next=  head;
        head->prev=newnode;
        head=newnode;
    }
}

void DList::Insert(int x, int Pos)
{
    int cont=1;
    Node *newnode=new Node(x);
    if(Pos==0)
    Push_front(x);
    else
    {
        Node *aux = head;
        while(cont<Pos and aux)
        {
            aux=aux->next;
            cont++;
        }
        if(!aux)
            cout<<"Could not link node in position "<<Pos<<endl;
        else if(!aux->next)
            Push_back(x);
        else
        {
            newnode->next=aux->next;
            newnode->prev=aux;
            aux->next->prev=newnode;
            aux->next=newnode;
        } 
    }
}

void DList::Print_list()
{
    Node *aux;
    aux=head;
    if(!aux)
        cout<<"The Double List is Empty"<<endl;
    while(aux)
    {
        cout<<aux->value;
        aux=aux->next;
        if(aux)
            cout<<", ";
    }
}

void DList::Print_reverse_list ()
{
    Node* aux;
    aux = tail;
    if(!aux)
        cout<<"The Double List is Empty"<<endl;
    while(aux)
    {
        cout<<aux->value;
        aux=aux->prev;
        if(aux)
            cout<<", ";
    }
}

Node* DList::Find(int target)
{
    if(Empty( ))
        return nullptr;
    Node *aux=head;
    Node *aux2=tail;
    while(aux->next and aux2->prev)
    {
        if(aux->value==target)
            return aux;
        if(aux2->value==target)
            return aux2;
        aux=aux->next;
        aux2=aux2->prev;
    }   
    return nullptr;
}

void DList::Pop_back()
{
    if(Empty( ))
        return ;
    if(!tail->prev)
    {
        delete(tail);
        head=nullptr;
        tail=nullptr;
        return ;
    }
    Node *aux=tail;
      tail = tail->prev;
      tail->next=nullptr;
    aux->prev=nullptr;
    delete(aux);
}

void DList::Pop_front()
{
    if(Empty())
        return ;
    if(!head->next)
    {
        delete(head);
        head=nullptr;
        tail=nullptr;
        return ;
    }
    Node *aux=head;
    head=head->next;
    head->prev=nullptr;
    aux->next=nullptr;
    delete(aux);    
}

void DList::Erase (int x)
{
    if(!head and !tail)
        return; 
    Node *aux=head, *aux2;
    aux2=aux;
    if(head->value==x and head==tail)
    {
        head=nullptr;
        tail=nullptr;
        delete(aux);
        return;
    }
    if(head->value==x)
    {
        head=aux->next;
        aux->next=nullptr;
        head->prev=nullptr;
        delete (aux);
        return ;
    }
    if(tail->value==x)
    {
        aux=  tail;
        tail=aux->prev;
        tail->next=nullptr;
        aux->prev=nullptr;
        delete (aux);
        return ;
    }
    while(aux2)
    {
        if(aux2->value==x)
        {
            aux->next=aux2->next;
            aux2->next->prev=aux;
            aux2->next=nullptr;
            aux2->prev=nullptr;
            delete(aux2);
            return;
        }
        aux=aux2;
        aux2=aux2->next;
    }
}

int DList::Front() 
{
    if(!head)
        return INT_MIN;
    return head->value;
}

int DList::Back()
{
    if(!tail)
        return INT_MIN;
    return tail->value;
}

void DList::Clear()
{
    while(head and tail)
        Pop_front(  );
}