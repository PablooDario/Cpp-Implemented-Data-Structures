#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    int height = 1;
    node* right;
    node* left;
    node(): value(0), right(nullptr), left(nullptr){}
    node(int x): value(x), right(nullptr), left(nullptr){}
};

class AVL{
    protected:
        node* root;
    private:
        node* _Insert(node*&,int);
        node* _Delete(node*&, int);
        node* _Find(node*, int);
        void _Preorder (node*);
        void _Inorder (node*);
        void _Postorder (node*);
        node* _Max(node*);
        node* _Min(node*);
        void _UpdateHeight(node*);
        int _GetHeight(node*);
        node* _Rotation (node*);
        int _Balance(node*);
        node* _RightRotation(node*);
        node* _LeftRotation(node*);
    public:
        void CreateRoot(int);
        void Insert(int);
        void Delete(int);

        void PrintBT ();
        void Preorder ();
        void Inorder ();
        void Postorder ();

        node* Find(int);
        node* Max();
        node* Min();
        bool Empty();
        void ClearTree();
};
typedef AVL AVLTree;

void AVL::CreateRoot(int x)
{
    root=new node(x);
}

void AVL::Insert(int value)
{
    if(root==nullptr)
    {
        root=new node(value);
        return ;
    }
    root=_Insert(root, value);
}

node* AVL::_Insert(node*& root, int value)
{
    if(root==nullptr)
        return new node(value);
    if(value<root->value)
        root->left=_Insert(root->left, value);        
    else if(value>root->value)
        root->right=_Insert(root->right, value);
    else
        return root;
    _UpdateHeight (root);
    return _Rotation(root);
}

void AVL::_UpdateHeight(node* root)
{
    int hl, hr;
    hl=_GetHeight(root->left);
    hr=_GetHeight(root->right);
    root->height=(max(hl+1,hr+1));
}

int AVL::_GetHeight(node* root)
{
    return root != nullptr ? root->height : 0 ;
}

node* AVL::_Rotation(node* root)
{
    int balance = _Balance(root); 
    if(balance > 1)
    {
        if(_Balance(root->left)<0)
            root->left=_LeftRotation(root->left);
        return _RightRotation(root);
    }
    if(balance < -1)
    {
        if(_Balance(root->right)>0)
            root->right=_RightRotation(root->right);
        return _LeftRotation(root);
    }
    return root;
}

node* AVL::_RightRotation(node* root)
{
    node* left=root->left;
    node* aux=left->right;
    left->right=root;
    root->left=aux;
    _UpdateHeight(root);
    _UpdateHeight(left);
    return left;
}

node* AVL::_LeftRotation(node* root)
{
    node* right=root->right;
    node* aux=right->left;
    right->left=root;
    root->right=aux;
    _UpdateHeight(root);
    _UpdateHeight(right);
    return right;
}

int AVL::_Balance(node* root)
{
    return root!=nullptr ? (_GetHeight(root->left)- _GetHeight(root->right)) : 0;
}

void AVL::Delete(int value)
{
    root=_Delete(root, value);
}

node* AVL::_Delete(node*& root, int value)
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
    _UpdateHeight (root);
    return _Rotation(root);
}

void AVL::PrintBT ()
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

node* AVL::Find(int value)
{
    return _Find(root, value);
}

node* AVL::_Find(node*root, int value)
{
    if(root==nullptr)
        return nullptr;
    if(value<root->value)
        return _Find(root->left, value);
    else if(value>root->value)
        return _Find(root->right, value);
    return root;
}

void AVL::Preorder (){
    _Preorder(root);
}

void AVL::_Preorder (node* root)
{
    if(root!=nullptr)
    {
        cout<<root->value<<" ";
        _Preorder(root->left);
        _Preorder(root->right);
    }
}

void AVL::Inorder (){
    _Inorder(root);
}

void AVL::_Inorder (node* root)
{
    if(root!=nullptr)
    {
        _Inorder(root->left);
        cout<<root->value<<" ";
        _Inorder(root->right);
    }
}

void AVL::Postorder (){
    _Postorder(root);
}

void AVL::_Postorder (node* root)
{
    if(root!=nullptr)
    {
        _Postorder(root->left);
        _Postorder(root->right);
        cout<<root->value<<" ";
    }
}

node* AVL::Max()
{
    return _Max(root);
}

node* AVL::_Max(node* root)
{
    if (Empty())
        return nullptr;
    if(root->right==nullptr)
        return root;
    return _Max(root->right);
}

node* AVL::Min()
{
    return _Min(root);
}

node* AVL::_Min(node* root)
{
    if (Empty())
        return nullptr;
    if(root->left==nullptr)
        return root;
    return _Min(root->left);
}

bool AVL::Empty()
{
    if (root==nullptr)
        return true;
    return false;
}

void AVL::ClearTree ()
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