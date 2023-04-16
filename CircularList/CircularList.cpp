#include "CircularList.h"

int main ()
{
    CList Circle;
    Node *aux;

    //erase elements when the list is empty and the print it
    Circle.Pop_back( );
    Circle.Pop_front( );
    Circle.Erase(8);
    cout<<endl;
    Circle.Print_Circular_list( );
    cout<<endl;

    //Insert elements in the list  
    Circle.Insert(3, 0);
    Circle.Push_front(2);
    Circle.Push_back(4);
    Circle.Insert(8, 1);
    Circle.Insert(15, 6);
    Circle.Push_back(5);
    Circle.Push_back(11);
    Circle.Push_front(1);
    Circle.Push_front(5);

    //Print the list
    cout<<"The list is --> ";
    Circle.Print_Circular_list( );

    //Erase elements by the 3 forms and print the list
    Circle.Pop_back( );
    Circle.Pop_front( );
    Circle.Erase(8);
    cout<<endl<<"\nThe new list is --> ";
    Circle.Print_Circular_list( );

    //Check if the list is empty
    if(Circle.Empty( ))
        cout<<endl<<"\nThe list is empty";
    else    
        cout<<endl<<"\nThe list isnt empty";

    //Check if an element is in the list
    int x=5;
    aux=Circle.Find(x);
    if(aux!=nullptr)
        cout<<"\nThe element: "<<aux->value<<"is in the list";
    else
        cout<<"\nThe element: "<<x<<" isnt in the list";

    //Check the back and front
    cout<<endl;
    cout<<"The Front of the list is: "<<Circle.Front()<<endl;
    cout<<"The Back of the list is: "<<Circle.Back()<<endl;

    //Clear the list
    Circle.Clear( );
    cout<<endl;
    Circle.Print_Circular_list( );

    return 0;
}