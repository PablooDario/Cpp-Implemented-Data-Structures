#include <bits/stdc++.h>
using namespace std;

struct Node{
    int value;
    Node *next;
    Node(): value(0), next(nullptr) {}
    Node(int x) : value(x), next(nullptr) {}
};

class List{
    private:
        Node *head;
    public:
        List () : head(NULL) {}
        void Push_back(int);
        void Push_front(int);
        void Insert(int, int);
        bool Empty ();
        void Print_list();
        Node* Find(int);
        void Erase (int);
        void Pop_back();
        void Pop_front();
        int Front();
        int Back();
        void Clear ();
};

void List::Push_back(int x)
{   
    Node *newnode = new Node(x);
    if(!head)
        head=newnode;
    else
    {
        Node *aux=head;
        while(aux->next!=NULL)
            aux=aux->next;
        aux->next=newnode;
    }
}

void List::Push_front(int x)
{
    Node *newnode = new Node(x);
    if(!head)
        head=newnode;
    else
    {
        newnode->next = head;
        head=newnode;
    }
}

void List::Insert(int x, int Pos)
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
        {
            cout<<"Could not link node in position "<<Pos<<endl;
        }
        else if(!aux->next)
            aux->next=newnode;
        else
        {
            newnode->next=aux->next;
            aux->next=newnode;
        } 
    }
}

bool List::Empty ()
{
    if(head)
        return false;
    return true;
}

void List::Print_list()
{
    Node *aux;
    aux = head;
    if(!aux)
    {
        cout<<"Empty List";
    }
    while(aux)
    {
        cout<<aux->value;
        aux=aux->next;
        if(aux)
            cout<<", ";
    }
}

Node* List::Find(int target)
{
    if(Empty())
        return nullptr;
    Node *aux = head;
    while(aux->next)
    {
        if(aux->value==target)
            return aux;
        aux=aux->next;
    }   
    return nullptr;
}

void List::Erase (int x)
{
    if(!head)
        return; 
    Node *aux = head, *aux2;
    aux2=aux;
    if(head->value==x)
    {
        aux2=aux2->next;
        head=aux2;
        aux->next=nullptr;
        delete(aux);
        return;
    }
    while(aux2)
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

void List::Pop_back()
{
    if(Empty())
        return ;
    if(!head->next)
    {
        delete(  head);
        head=nullptr;
        return ;
    }
    Node *aux=head, *aux2;
    aux2=aux;
    while(aux2->next)
    {
        aux=aux2;
        aux2=aux2->next;
    }
    aux->next=nullptr;
    delete(aux2);
}

void List::Pop_front()
{
    if(Empty())
        return;
    Node *aux = head;
    head = head->next;
    aux->next=nullptr;
    delete(aux);    
}

int List::Front() 
{
    if(!head)
        return INT_MIN;
    return head->value;
}

int List::Back()
{
    if(!head)
        return INT_MIN;
    Node* aux=head;
    while(aux->next)
        aux=aux->next;
    return aux->value;
}

void List::Clear ()
{
    while(head)
        Pop_front();
}