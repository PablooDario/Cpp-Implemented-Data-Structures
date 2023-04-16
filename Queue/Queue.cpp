#include "Queue.h"

int main ()
{
    Queue q;
    //See if the queue is empty
    if(q.Empty())
        cout<<"\nThe queue is empty"<<endl;
    else
        cout<<"\nThe queue isnt empty"<<endl;

    //Pop an element when the queue is empty and then print it
    q.Pop();
    q.PrintQueue();    

    //Push 6 elements 
    q.Push(0);
    q.Push(1);
    q.Push(2);
    q.Push(3);
    q.Push(4);
    q.Push(5);

    //Print the Queue
    cout<<endl<<"The list is --> ";
    q.PrintQueue();
    cout<<"\nThe size of the list is: "<<q.Size()<<endl;

    //See the front and the back
    cout<<"\nThe element at the front is: "<<q.Front()<<endl;
    cout<<"The element at the back is: "<<q.Back()<<endl;

    //Pop 3 elements and see the new list
    q.Pop();
    q.Pop();
    q.Pop();
    cout<<"\nThe new list is --> ";
    q.PrintQueue();
    cout<<"\nThe size of the new list is: "<<q.Size()<<endl;

    //See if the Queue is empty
    if(q.Empty())
        cout<<"\nThe queue is empty"<<endl;
    else
        cout<<"The queue isnt empty"<<endl;

    //Clear the queue and see if it cleared correctly
    cout<<"\nThe queue was cleared";
    q.Clear();
    cout<<endl;
    q.PrintQueue();
    return 0;
}