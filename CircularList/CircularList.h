#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node(): value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
};

class  CList{
    private:
        Node *first;
    public:
        CList () : first(nullptr) {}
        void Push_back(int);
        void Push_front(int);
        void Insert(int, int);
        bool Empty ();
        void Print_Circular_list();
        Node* Find(int);
        void Erase (int);
        void Pop_back();
        void Pop_front();
        int Front();
        int Back();
        void Clear ();
};

void  CList::Push_back(int x)
{   
    Node *newnode= new Node(x);
    if(!first)
    {
        first=newnode;
        newnode->next= first;
    }
    else
    {
        Node *aux= first;
        while(aux->next!= first)
            aux=aux->next;
        aux->next=newnode;
        newnode->next= first;
    }
}

void CList::Push_front(int x)
{
    Node *newnode = new Node(x);
    if(!first)
    {
        first=newnode;  
        first->next= first;      
    }
    else
    {
        Node *aux = first;
        while(aux->next!=first)
            aux=aux->next;
        newnode->next= first;
        first=newnode;
        aux->next=newnode;
    }
}

void CList::Insert(int x, int Pos)
{
    int cont=2;
    Node *newnode=new Node(x);
    if(Pos==0)
    {
        Push_front(x);  
        return ;      
    }
    if(!first)
    {
        cout<<"Could not link node in position "<<Pos<<endl;
        return ;
    }
    if(Pos==1)
    {
        newnode->next= first->next;
        first->next=newnode;
        return ;
    }
    Node *aux= first->next;
    while(cont<Pos and aux!= first)
    {
        aux=aux->next;
        cont++;
    }
    if(aux==first)
        cout<<"Could not link node in position "<<Pos<<endl;
    else if(aux->next==first)
    {
        aux->next=newnode;      
        newnode->next=first;      
    }
    else
    {
        newnode->next=aux->next;
        aux->next=newnode;
    } 
}

bool CList::Empty ()
{
    if(first)
        return false;
    return true;
}

void CList::Print_Circular_list()
{
    Node *aux;
    aux=first;
    if(!aux)
    {
        cout<<"The circular list is empty"<<endl;
        return ;
    }
    while(aux->next!=first)
    {
        cout<<aux->value<<", ";
        aux=aux->next;
    }
    cout<<aux->value;
}

Node* CList::Find(int target)
{
    if(Empty())
        return nullptr;
    Node *aux = first;
    while(aux->next!=first)
    {
        if(aux->value==target)
            return aux;
        aux=aux->next;
    }   
    return nullptr;
}

void CList::Pop_back()
{
    if(Empty())
        return ;
    if(first->next== first)
    {
        first->next=nullptr;
        delete( first);
        first=nullptr;
        return ;
    }
    Node *aux=first, *aux2;
    aux2=aux;
    while(aux2->next!=first)
    {
        aux=aux2;
        aux2=aux2->next;
    }
    aux->next=first;
    aux2->next=nullptr;
    delete(aux2);
}

void CList::Pop_front()
{
    if(Empty())
        return;
    Node *aux=first;
    if( first->next==first)
    {
        first=nullptr;
        aux->next=nullptr;
        delete(aux);
        return ;
    }
    Node *aux2;
    aux2=aux;
    while(aux2->next!=first)
        aux2=aux2->next;
    first= first->next;
    aux->next=nullptr;
    aux2->next= first;
    delete(aux);    
}

void CList::Erase (int x)
{
    if(!first)
        return; 
    Node *aux, *aux2;
    aux=first;
    aux2=first->next;
    if(first->value==x)
    {
        Pop_front( );
        return;
    }
    while(aux2!=first)
    {
        if(aux2->value==x)
        {
            aux->next=aux2->next;
            aux2->next=nullptr;
            delete(aux2);
            return;
        }
        aux=aux2;
        aux2=aux2->next;
    }
}

int CList::Front() 
{
    if(!first)
        return INT_MIN;
    return (first->value);
}

int CList::Back()
{
    if(!first)
        return INT_MIN;
    Node* aux=first;
    while(aux->next!= first)
        aux=aux->next;
    return aux->value;
}

void CList::Clear ()
{
    while(first)
        Pop_front( );
}