#include <bits/stdc++.h>
using namespace std; 

class Heap
{
    protected:
        int position =-1;
        vector <int> heapArray;
    private:
        void _InsHeapify(int);
        void _DelHeapify(int);
    public:
        void Push(int);
        void Pop ();
        int Top ();
        int Size ();
        bool Empty ();
        void Clear ();
        void Print ();
};
typedef Heap MinHeap;

void Heap::Push(int value)
{
    heapArray.push_back(value);
    position++;
    if(position!=0)
        _InsHeapify(position);
}

void Heap::_InsHeapify(int i)
{
    int fatherPos=floor((i-1)/2);
    if(heapArray[i] < heapArray[fatherPos])
    {
        swap(heapArray[i],heapArray[fatherPos]);
        if(fatherPos!=0)
            _InsHeapify(fatherPos);
    }
}

void Heap::Pop()
{
    if(position==-1)
        return ;
    heapArray[0]=heapArray[position];
    position--;
    heapArray.pop_back();
    if(position==-1)
        return;
    _DelHeapify(0);
}

void Heap::_DelHeapify(int i)
{
    int lchild=(i*2)+1;
    int rchild=(i*2)+2;
    if(rchild<=position)
    {
        //si son menores los 2 hijos
        if( heapArray[lchild] < heapArray[i] && heapArray[rchild] < heapArray[i])
        {
            int pos = heapArray[lchild] < heapArray [rchild] ? lchild : rchild;
            swap(heapArray[pos], heapArray[i]);
            _DelHeapify(pos);
        }
        //si es menor hijo izquierdo
        else if(heapArray[lchild] < heapArray[i])
        {
            swap(heapArray[lchild], heapArray[i]);
            _DelHeapify(lchild);
        }
        //si es menor hijo derecho
        else if(heapArray[rchild] < heapArray[i])
        {
            swap(heapArray[rchild], heapArray[i]);
            _DelHeapify(rchild);
        }
    }
    else if(lchild<=position)
    {
       if(heapArray[lchild] < heapArray[i])
            swap(heapArray[lchild], heapArray[i]);
    }
}

int Heap::Top()
{
    return heapArray[0];
}

int Heap::Size()
{
    return position+1;
}

bool Heap::Empty()
{
    return position==-1 ? true : false;
}

void Heap::Clear()
{
    position=-1;
    heapArray.clear();
}

void Heap::Print()
{
    if(position==-1)
    {
        cout<<"Empty Tree";
        return ;
    }
    int i, j, cont;
    i=cont=0;
    j=-1;
    cout<<"\nLevel 0 ---> ";
    for(auto element:heapArray)
    {
        i++; j++;
        cout<<element;
        if(i==pow(2, cont))
        {
            i=0;
            cout<<"\nLevel "<<cont+1<<" ---> ";
            cont++;
        }
        else if(j==position)
            cout<<", end";
        else
            cout<<", ";
    }
}