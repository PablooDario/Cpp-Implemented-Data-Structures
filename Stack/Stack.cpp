#include "Stack.h"

int main()
{
    Stack st1;
    int aux;

    //Pop an element when the stack is empty and then print it
    cout<<endl;
    st1.Pop();
    st1.Print_stack();
    cout<<"The size is: "<<st1.Size()<<endl;

    //Insert values in the stack
    st1.Push(5);
    st1.Push(4);
    st1.Push(3);
    st1.Push(2);
    st1.Push(1);
    st1.Push(0);

    //Print the stack
    cout<<endl<<"The stack is --> ";
    st1.Print_stack();

    //Look what element is at the top
    cout<<"\nThe value at the top is: "<<st1.Top()<<endl;

    //Print the size
    cout<<"The size is: "<<st1.Size()<<endl;

    //Pop 2 elements and print the new stack
    st1.Pop();
    st1.Pop();
    cout<<"\nThe new stack is --> ";
    st1.Print_stack();

    //Clear the stack
    st1.clear();
    cout<<"\n\nThe stack was cleared\n";
    st1.Print_stack();
    
    return 0;
}