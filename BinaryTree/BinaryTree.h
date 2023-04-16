#include <bits/stdc++.h>
using namespace std;

struct node{
    int value;
    node* right;
    node* left;
    node(): value(0), right(nullptr), left(nullptr){}
    node(int x): value(x), right(nullptr), left(nullptr){}
};

class BinTree{
    private:
        node* root;
        int height;
        void _Preorder (node*);
        void _Inorder (node*);
        void _Postorder (node*);
    public: 
        BinTree(): root(nullptr), height(-1){}
        void CreateRoot(int);
        void InsertNode(int, int, int, char);
        int LevelNode(int);
        int TreeHeight();
        void PrintBT();
        int PositionNode(int);
        void ReplaceNode(int, int);
        node* FindNode(int);
        void DeleteNode(int);
        node* DeepestNode();
        void ClearTree ();
        void AdjustHeight ();
        void Preorder ();
        void Inorder ();
        void Postorder ();
};

void BinTree::CreateRoot(int value)
{
    root=new node(value);
    height=0;
}

void BinTree::InsertNode(int value, int level, int PositionNode, char side)
{
    //check the values doesnt repeat in the tree
    node* aux=FindNode(value);
    if(aux!=nullptr)
        return ;
    //make sure side has valid values
    if(side=='l' or side=='r')
        bool flag=1;
    else
    {
        cout<<"\nInvalid value for side, the only values for side are 'r' for right and 'l' for left\n";
        return ;
    }
    //make sure id that Position node can exist
    if(PositionNode>(pow(2,level)-1))
    {
        cout<<"\nUnexistent position of node\n";
        return ;
    }
    //make sure the level exist
    if(level>height)
    {
        cout<<"\nInvalid level\n";
        return ;
    }
    if(height==-1)
    {
        cout<<"\nEmpty tree, you must create a root first\n";
        return ;
    }
    int i=0, cont=0;
    queue <node*> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        i++;
        aux=nodes.front();
        nodes.pop();
        if(cont==level) //we are in the correct level
        {
            if((i-1)==PositionNode) //if we found the father node
            {
                if(aux==nullptr) //if he father doesnt exist
                {
                    cout<<"The father doesnt exist";
                    return;
                }
                if(side=='l')
                {
                    if(aux->left==nullptr)
                    {
                        aux->left=new node (value);
                        height=max(height, level+1);
                        return ;
                    }
                    cout<<"\nThat place has already a node";
                    return ;
                }
                if(aux->right==nullptr)
                    {
                        aux->right=new node (value);
                        height=max(height, level+1);
                        return ;
                    }
                    cout<<"\nThat place has already a node";
                    return ;
            }
        }
        if(i==pow(2, cont)) //new level
        {
            i=0;
            cont++;
        }
        nodes.push(aux->left);
        nodes.push(aux->right);
    }
}

int BinTree::TreeHeight()
{
    return height;
}

int BinTree::LevelNode(int val)
{
    if(!root)
    {
        cout<<"Empty tree";
            return INT_MIN;
    }
    int i, cont, numbernulls;
    i=cont=numbernulls=0;
    queue <node*> bfs;
    node *aux;
    bfs.push(root);
    while(!bfs.empty())
    {
        i++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            if(aux->value==val)
                return cont;
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
        {
            cout<<"Inexisten node";
                return INT_MIN;
        }
        if(i==pow(2, cont))
        {
            numbernulls=0;
            i=0;
            cont++;
        }
    }
    return INT_MIN;
}

void BinTree::PrintBT ()
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

void BinTree::Preorder (){
    _Preorder(root);
}
void BinTree::Inorder (){
    _Inorder(root);
}
void BinTree::Postorder (){
    _Postorder(root);
}

void BinTree::_Preorder(node* root)
{
    if(root!=nullptr)
    {
        cout<<root->value<<" ";
        _Preorder(root->left);
        _Preorder(root->right);
    }
}

void BinTree::_Inorder (node* root)
{
    if(root!=nullptr)
    {
        _Inorder(root->left);
        cout<<root->value<<" ";
        _Inorder(root->right);
    }
}

void BinTree::_Postorder (node* root)
{
    if(root!=nullptr)
    {
        _Postorder(root->left);
        _Postorder(root->right);
        cout<<root->value<<" ";
    }
}

int BinTree::PositionNode(int val)
{
    if(!root)
    {
        cout<<"Empty tree";
            return INT_MIN;
    }
    int i, cont, numbernulls;
    i=cont=numbernulls=0;
    queue <node*> bfs;
    node *aux;
    bfs.push(root);
    while(!bfs.empty())
    {
        i++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            if(aux->value==val)
                return i-1;
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
        {
            cout<<"Inexisten node";
                return INT_MIN;
        }
        if(i==pow(2, cont))
        {
            numbernulls=0;
            i=0;
            cont++;
        }
    }
    return INT_MIN;
}

node* BinTree::FindNode(int val)
{
    if(!root)
    {
        cout<<"Empty tree";
            return nullptr;
    }
    int i, cont, numbernulls;
    i=cont=numbernulls=0;
    queue <node*> bfs;
    node *aux;
    bfs.push(root);
    while(!bfs.empty())
    {
        i++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            if(aux->value==val)
                return aux;
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
            return nullptr;
        if(i==pow(2, cont))
        {
            numbernulls=0;
            i=0;
            cont++;
        }
    }
    return nullptr;
}

void BinTree::ReplaceNode(int oldValue, int newValue)
{
    node* aux=FindNode(newValue);
    if(aux)
        return ;
    aux=FindNode(oldValue);
    if(!aux)
        return;
    aux->value=newValue;
}

void BinTree::AdjustHeight ()
{
    int i, cont, numbernulls;
    i=cont=numbernulls=0;
    queue<node*> bfs;
    node* aux;
    bfs.push(root);
    while(!bfs.empty())
    {
        i++;
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            numbernulls++;
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(numbernulls==pow(2,cont))
        {
            height=min(height, cont-1);
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

node* BinTree::DeepestNode()
{
    if(!root)
    {
        cout<<"Empty Tree";
        return nullptr;
    }
    node* aux, *aux2;
    int i, cont;
    i=cont=0;
    queue <node*> bfs;
    bfs.push(root);
    while(height>=cont)
    {
        i++; 
        aux=bfs.front();
        bfs.pop();
        if(aux==nullptr)
        {
            bfs.push(nullptr);
            bfs.push(nullptr);
        }
        else
        {
            bfs.push(aux->left);
            bfs.push(aux->right);
        }
        if(cont==height)
        {
            if(aux!=nullptr)
                aux2=aux;
        }
        if(i==pow(2, cont))
        {
            i=0;
            cont++;
        }
    }
    return aux2;
}

void BinTree::ClearTree ()
{
    while(root)
    {
        node* aux=DeepestNode();
        DeleteNode(aux->value);
    }
}

void BinTree::DeleteNode(int value)
{
    node* aux2=FindNode(value);
    if(!aux2)
        return ;
    if(aux2->left or aux2->right)
    {
        cout<<"Can't erase that node, it has children";
        return ;
    }
    if(LevelNode(value)==0)
    {
        root=nullptr;
        delete(aux2);
        return ;
    }
    //Obtain the Father data
    char side ='r';
    int numberNode, level;
    level=LevelNode(value)-1;
    numberNode=PositionNode(value);
    if(numberNode%2==0)
        side='l';
    if(numberNode!=0 and numberNode%2==0)
        numberNode++;
    numberNode=floor((numberNode-1)/2);
    node* aux;
    int i=0, cont=0;
    queue <node*> nodes;
    nodes.push(root);
    while(!nodes.empty())
    {
        i++;
        aux=nodes.front();
        nodes.pop();
        if(cont==level) //ya estamos en el nivel
        {
            if((i-1)==numberNode) //si ya es el nodo padre
            {
                if(side=='l')
                {
                    aux->left=nullptr;
                    delete(aux2);
                }
                else
                {
                aux->right=nullptr;
                delete(aux2);
                }
                AdjustHeight();
                return ;
            }
        }
        if(aux==nullptr)
        {
            nodes.push(nullptr);
            nodes.push(nullptr);
        }
        else
        {
        nodes.push(aux->left);
        nodes.push(aux->right);
        }
        if(i==pow(2, cont)) //nuevo nivel
        {
            i=0;
            cont++;
        }
    }
}