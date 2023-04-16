#include "DoubleList.h"

int main()
{
    DList doubList;
    //Erase elements when the list is empty
    doubList.Erase(2);
    doubList.Pop_back( );
    doubList.Pop_front( );

    //Print the List
    cout<<endl;
    doubList.Print_list( );

    //Insert Elements
    doubList.Push_front(8);
    doubList.Push_back(2);
    doubList.Insert(8, 0);
    doubList.Insert(7, 2);
    doubList.Insert(2, 0);
    doubList.Push_front(0);
    doubList.Push_back(10);

    //Print the List
    cout<<"\nThe list is --> ";
    doubList.Print_list( );
    cout<<endl<<endl;

    //Insert an element in an invalid position 
    doubList.Insert(5, 10);

    //Query of the front and back
    cout<<"The element in the front is: "<<doubList.Front()<<endl;
    cout<<"The element in the back is: "<<doubList.Back()<<endl;

    //Print the element in Reverse
    cout<<"\nThe reverse list is --> ";
    doubList.Print_reverse_list( );
    cout<<endl<<endl;

    //Search an element that is in the list and another that isnt in the list
    Node *f=doubList.Find(8);
    if(f)
        cout<<"The element: "<<f->value<<" is in the list"<<endl;
    Node* b=doubList.Find(95);
    if(b)
        cout<<"The element: "<<b->value<<" is in the list"<<endl;
    else
        cout<<"The element 95 isnt in the list"<<endl;

    //Erase elements
    doubList.Pop_back( );
    doubList.Pop_front( );
    doubList.Erase(50);
    doubList.Erase(7);
    
    //Print the new list
    cout<<"\nThe new list is --> ";
    doubList.Print_list( );
    cout<<endl;

    //Clear the list
    doubList.Clear();
    return 0;
}