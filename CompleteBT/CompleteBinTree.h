#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* right;
    node* left;
    node(): value(0), right(nullptr), left(nullptr){}
    node(int x): value(x), right(nullptr), left(nullptr){}
};

class CompleteBT
{
    private:
        node* root;
        void _PreOrder(node*);
        void _InOrder(node*);
        void _PostOrder(node*);
    public:
        void CreateRoot(int);
        void PushBT (int);
        void PrintBT ();
        void PrintLeft ();
        void PrintRight ();
        void PrintLevel(int);
        node* FindNode(int);
        node* DeepestNode();
        void DeleteDeepest ();
        void DeleteNode (int);
        void PreOrder();
        void InOrder();
        void PostOrder();
        void Clear();
};


void CompleteBT::CreateRoot(int x){
    root = new node(x);
}

void CompleteBT::PushBT(int x)
{
    if(!root)
    {
        root=new node(x);
        return ;
    }
    int i=0;
    node *aux;
    vector <node*> nodes;    
    nodes.push_back(root);
    while(i<nodes.size())
    {
        aux=nodes[i];
        if(aux==nullptr)
        {
            auto z=(i-1);
            aux=nodes[floor(z/2)];
            if(z%2==0)
                aux->left=new node(x);
            else
                aux->right=new node(x);
            return ;
        }
        nodes.push_back(aux->left);
        nodes.push_back(aux->right);
        i++;
    }
}

void CompleteBT::PrintBT ()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    node* aux;
    int i=0, cont=0;
    queue <node*> nodes;
    nodes.push(root);
    cout<<"\nLevel 0 ---> ";
    while(!nodes.empty())
    {
        i++;
        aux=nodes.front();
        nodes.pop();
        if(aux==nullptr)
        {
            cout<<"end";
            return ;
        }
        cout<<aux->value;
        if(i==pow(2, cont))
        {
            cout<<"\nLevel "<<cont+1<<" ---> ";
            i=0;
            cont++;
        }
        else
            cout<<", ";
        nodes.push(aux->left);
        nodes.push(aux->right);
    }
}

void CompleteBT::PrintLeft ()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    cout<<"------- Left side of the root -------\n";
    node *aux;
    int i=0, cont=0;
    queue <node*> nodes;
    cout<<"\n Root   ---> "<<root->value;
    nodes.push(root->left);
    cout<<"\nLevel 1 ---> ";
    while(!nodes.empty())
    {
        i++;
        aux=nodes.front();
        nodes.pop();
        if(aux==nullptr)
        {
            cout<<"end";
            return ;
        }
        cout<<aux->value;
        if(i==pow(2, cont))
        {
            cout<<"\nLevel "<<cont+2<<" ---> ";
            i=0;
            cont++;
        }
        else
            cout<<", ";
        nodes.push(aux->left);
        nodes.push(aux->right);
    }
}

void CompleteBT::PrintLevel(int l)
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    node *aux;
    int i=0, cont=0;
    queue <node*> nodes;
    if(l<0)
    {
        cout<<"Invalid Level";
        return ;
    }
    if(l==0)
    {
        cout<<"Level 0 --->"<<root->value;
        return ;
    }
    nodes.push(root);
    aux=nodes.front();
    while(aux)
    {
        i++;
        aux=nodes.front();
        nodes.pop();
        if(aux==nullptr)
        {
            cout<<"Invalid Level";
            return ;
        }
        //cout<<aux->value;
        if(i==pow(2, l))
        {
            cout<<"\nLevel "<<l<<" ---> ";
            for(i=0; i<pow(2, l); i++)
            {
                cout<<aux->value;
                if(i!=pow(2,l)-1)
                    cout<<", ";
                aux=nodes.front();
                nodes.pop();
            }
            return ;
        }
        nodes.push(aux->left);
        nodes.push(aux->right);
    }
}

void CompleteBT::PrintRight ()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    cout<<"------- Right side of the root -------\n";
    node *aux;
    int i=0, cont=0;
    queue <node*> nodes;
    cout<<"\n Root   ---> "<<root->value;
    nodes.push(root->right);
    cout<<"\nLevel 1 ---> ";
    while(!nodes.empty())
    {
        i++;
        aux=nodes.front();
        nodes.pop();
        if(aux==nullptr)
        {
            cout<<"end";
            return ;
        }
        cout<<aux->value;
        if(i==pow(2, cont))
        {
            cout<<"\nLevel "<<cont+2<<" ---> ";
            i=0;
            cont++;
        }
        else
            cout<<", ";
        nodes.push(aux->left);
        nodes.push(aux->right);
    }
}

node* CompleteBT::FindNode(int target)
{
    if(!root)
        return nullptr;
    queue <node*> nodes;
    node* aux;
    nodes.push(root);
    while(!nodes.empty())
    {
        aux=nodes.front();
        nodes.pop();
        if(aux==nullptr)
            return nullptr;
        if(aux->value==target)
            return aux;
        nodes.push(aux->left);
        nodes.push(aux->right);
    }
    return nullptr;
}

node* CompleteBT::DeepestNode()
{
    node* aux;
    if(!root)
        return nullptr;
    queue <node*> qnodes;
    qnodes.push(root);
    while(!qnodes.empty())  
    {
        aux=qnodes.front();
        qnodes.pop();
        if(aux->left!=nullptr)
            qnodes.push(aux->left); 
        if(aux->right!=nullptr)
            qnodes.push(aux->right); 
    }
    return aux;
}

void CompleteBT::DeleteDeepest ()
{
    node* aux;
    if(!root->left && !root->right)
    {
        aux=root;
        root=nullptr;
        delete(aux);
        return ;
    }
    int i=-1;
    queue <node*> qnodes;
    vector <node*> nodes;
    qnodes.push(root);
    nodes.push_back(root);
    while(!qnodes.empty())  
    {
        aux=qnodes.front();
        qnodes.pop();
        if(aux->left!=nullptr)
        {
            qnodes.push(aux->left); 
            nodes.push_back(aux->left);           
        }
        if(aux->right!=nullptr)
        {
            qnodes.push(aux->right);   
            nodes.push_back(aux->right);         
        }
        i++;
    }
    node *aux2=nodes[floor((i-1)/2)];
    if(i%2==0)
    {
        aux2->right=nullptr;
        delete(aux);
        return ;
    }
    aux2->left=nullptr;
    delete(aux);
    return ;
} 

void CompleteBT::DeleteNode(int x)
{
    if(root==nullptr)
    {
        cout<<"Empty tree";
        return ;
    }
    node *aux=FindNode(x);
    if(aux==nullptr)
    {
        cout<<"\n\nInexistent node";        
        return; 
    }
    auto last=DeepestNode();
    if(aux!=last)
        aux->value=last->value;
    DeleteDeepest();
}

void CompleteBT::PreOrder()
{
    _PreOrder(root);
}

void CompleteBT::_PreOrder(node* root)
{
    if(root==nullptr)
        return ;
    cout<<root->value<<" ";
    _PreOrder(root->left);
    _PreOrder(root->right);
}

void CompleteBT::InOrder()
{
    _InOrder(root);
}

void CompleteBT::_InOrder(node* root)
{
    if(!root->left)
    {
        cout<<root->value<<" ";
        return ;
    }
    _InOrder(root->left);
    cout<<root->value<<" ";
    _InOrder(root->right);
}

void CompleteBT::PostOrder()
{
    _PostOrder(root);
}

void CompleteBT::_PostOrder(node* root)
{
    if(!root->left)
    {
        cout<<root->value<<" ";
        return ;
    }
    _PostOrder(root->left);
    _PostOrder(root->right);
    cout<<root->value<<" ";
}

void CompleteBT::Clear()
{
    while(root)
        DeleteDeepest();
}