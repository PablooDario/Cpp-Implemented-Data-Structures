#include "MaxHeap.h"

int main()
{
    //Create the Heap
    MaxHeap myHeap;

    //Push elements
    myHeap.Push(6);
    myHeap.Push(4);
    myHeap.Push(8);
    myHeap.Push(2);
    
    //See the Top
    cout<<"\nThe Top is: "<<myHeap.Top()<<endl;

    //Push more elements
    myHeap.Push(7);
    myHeap.Push(10);
    myHeap.Push(1);
    myHeap.Push(15);
    myHeap.Push(3);

    //See the new Top and size
    cout<<"\nThe New Top is: "<<myHeap.Top();
    cout<<"\nThe Size is: "<<myHeap.Size()<<endl;

    //Delete elements
    myHeap.Pop();
    myHeap.Pop();
    myHeap.Pop();

    //See the Top and size
    cout<<"\nThe New Top is: "<<myHeap.Top();
    cout<<"\nThe New Size is: "<<myHeap.Size()<<endl;

    //Print the Heap in tree form
    myHeap.Print();
    
    //Clear the Heap and see the size
    myHeap.Clear();
    cout<<"\n\nThe New Size is: "<<myHeap.Size();
    return 0;
}