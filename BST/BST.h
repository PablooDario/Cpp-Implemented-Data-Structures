#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* right;
    node* left;
    node(): value(0), right(nullptr), left(nullptr){}
    node(int x): value(x), right(nullptr), left(nullptr){}
};

class BST{
    private:
        node* root;
        void _Insert(node*&,int);
        node* _Delete(node*&, int);
        node* _Find(node*root, int value);
        void _Preorder (node* root);
        void _Inorder (node* root);
        void _Postorder (node* root);
        node* _Max(node*);
        node* _Min(node*);
    public:
        void CreateRoot(int);
        void Insert(int);
        void Delete(int);
        
        void PrintBT ();
        void PrintLeft ();
        void PrintRight ();
        void Preorder ();
        void Inorder ();
        void Postorder ();

        node* Find(int);
        node* Max();
        node* Min();
        bool Empty();
        void ClearTree();
};
typedef BST BinarySearchTree;

void BST::CreateRoot(int x)
{
    root=new node(x);
}

void BST::Insert(int value)
{
    if(root==nullptr)
    {
        root=new node(value);
        return ;
    }
    _Insert(root, value);
}

void BST::_Insert(node*& root, int value)
{
    if(value<root->value)
    {
        if(root->left==nullptr)
            root->left=new node(value);
        else
            _Insert(root->left, value);        
    }
    else if(value>root->value)
    {
        if(root->right==nullptr)
            root->right=new node(value);
        else
            _Insert(root->right, value);
    }
}

void BST::Delete(int value)
{
    root=_Delete(root, value);
}

node* BST::_Delete(node*& root, int value)
{
    if(root==nullptr)
        return nullptr;
    //Buscamos el nodo que queremos borrar
    if(value<root->value)
        root->left=_Delete(root->left, value);
    else if(value>root->value)
        root->right=_Delete(root->right, value);
    //ya encontramos al nodo
    else
    {
        //si tiene 1 solo hijo o es nodo hoja
        if(!root->left and root->right)
        {
            node *aux=root->right;
            delete(root);
            return aux;            
        }
        else if(!root->right and root->left)
        {
            node *aux=root->left;
            delete(root);
            return aux;            
        }
        else if(!root->left and !root->right)
        {
            delete(root);
            return nullptr;
        }
        //if it has 2 children, set that node to the max of its left subtree
        root->value=_Max(root->left)->value;
        //delete the value repeated of the left subtree
        root->left=_Delete(root->left, root->value);
    }
    return root;
}

void BST::PrintBT ()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    node* aux;
    int i, cont, numbernulls, cont2;
    i=cont=cont2=numbernulls=0;
    queue <node*> bfs;
    queue <string> elements;
    bfs.push(root);
    cout<<"\nLevel 0 ---> ";
    while(!bfs.empty())
    {
        i++; cont2++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            elements.push("n");
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            elements.push(to_string(aux->value));
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
        {
            cont2-=pow(2,cont);
            int j;
            j=cont=0;
            for(int i=0; i<cont2; i++)
            { 
                j++;
                cout<<elements.front();
                elements.pop();
                if(j==pow(2, cont) and i!=cont2-1)
                {
                    j=0;
                    cont++;
                    cout<<"\nLevel "<<cont<<" ---> ";
                }
                else if(i!=cont2-1)
                    cout<<", ";
            }
            return ;
        }
        if(i==pow(2, cont))
        {
            numbernulls=0;
            i=0;
            cont++;
        }
    }
}

void BST::PrintLeft ()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    cout<<"------- Left side of the root -------";
    node* aux;
    int i, cont, numbernulls, cont2;
    i=cont=cont2=numbernulls=0;
    queue <node*> bfs;
    queue <string> elements;
    bfs.push(root->left);
    cout<<"\nRoot ---> "<<root->value;
    cout<<"\nLevel 1 ---> ";
    while(!bfs.empty())
    {
        i++; cont2++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            elements.push("n");
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            elements.push(to_string(aux->value));
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
        {
            cont2-=pow(2,cont);
            int j;
            j=cont=0;
            for(int i=0; i<cont2; i++)
            { 
                j++;
                cout<<elements.front();
                elements.pop();
                if(j==pow(2, cont) and i!=cont2-1)
                {
                    j=0;
                    cont++;
                    cout<<"\nLevel "<<cont+1<<" ---> ";
                }
                else if(i!=cont2-1)
                    cout<<", ";
            }
            return ;
        }
        if(i==pow(2, cont))
        {
            numbernulls=0;
            i=0;
            cont++;
        }
    }
}

void BST::PrintRight ()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return ;
    }
    cout<<"------- Right side of the root -------";
    node* aux;
    int i, cont, numbernulls, cont2;
    i=cont=cont2=numbernulls=0;
    queue <node*> bfs;
    queue <string> elements;
    bfs.push(root->right);
    cout<<"\nRoot ---> "<<root->value;
    cout<<"\nLevel 1 ---> ";
    while(!bfs.empty())
    {
        i++; cont2++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            elements.push("n");
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            elements.push(to_string(aux->value));
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
        {
            cont2-=pow(2,cont);
            int j;
            j=cont=0;
            for(int i=0; i<cont2; i++)
            { 
                j++;
                cout<<elements.front();
                elements.pop();
                if(j==pow(2, cont) and i!=cont2-1)
                {
                    j=0;
                    cont++;
                    cout<<"\nLevel "<<cont+1<<" ---> ";
                }
                else if(i!=cont2-1)
                    cout<<", ";
            }
            return ;
        }
        if(i==pow(2, cont))
        {
            numbernulls=0;
            i=0;
            cont++;
        }
    }
}

node* BST::Find(int value)
{
    return _Find(root, value);
}

node* BST::_Find(node*root, int value)
{
    if(root==nullptr)
        return nullptr;
    if(value<root->value)
        return _Find(root->left, value);
    else if(value>root->value)
        return _Find(root->right, value);
    return root;
}

void BST::Preorder (){
    _Preorder(root);
}

void BST::_Preorder (node* root)
{
    if(root!=nullptr)
    {
        cout<<root->value<<" ";
        _Preorder(root->left);
        _Preorder(root->right);
    }
}

void BST::Inorder (){
    _Inorder(root);
}

void BST::_Inorder (node* root)
{
    if(root!=nullptr)
    {
        _Inorder(root->left);
        cout<<root->value<<" ";
        _Inorder(root->right);
    }
}

void BST::Postorder (){
    _Postorder(root);
}

void BST::_Postorder (node* root)
{
    if(root!=nullptr)
    {
        _Postorder(root->left);
        _Postorder(root->right);
        cout<<root->value<<" ";
    }
}

node* BST::Max()
{
    return _Max(root);
}

node* BST::_Max(node* root)
{
    if (Empty())
        return nullptr;
    if(root->right==nullptr)
        return root;
    return _Max(root->right);
}

node* BST::Min()
{
    return _Min(root);
}

node* BST::_Min(node* root)
{
    if (Empty())
        return nullptr;
    if(root->left==nullptr)
        return root;
    return _Min(root->left);
}

bool BST::Empty()
{
    if (root==nullptr)
        return true;
    return false;
}

void BST::ClearTree ()
{
    node *aux;
    queue <node*> bfs;
    stack <int> nums;
    bfs.push(root);
    while(!bfs.empty())
    {
        aux=bfs.front();
        bfs.pop();
        nums.push(aux->value);
        if(aux->left)
            bfs.push(aux->left);
        if(aux->right)
            bfs.push(aux->right);
    }
    while(!nums.empty())
    {
        Delete(nums.top());
        nums.pop();
    }
}