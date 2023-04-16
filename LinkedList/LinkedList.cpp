#include "LinkedList.h"

int main(){
    List  Liinked;
    Node* Finder;

    //Print an empty list
    cout<<endl;
    Liinked.Print_list( );

    //Insert 9 elements by the 3 differents forms
    Liinked.Push_back(20);
    Liinked.Push_front(0);
    Liinked.Insert(10, 1); //Value, Position
    Liinked.Insert(5, 1);
    Liinked.Insert(15, 3);
    Liinked.Push_back(30);
    Liinked.Push_front(-10);
    Liinked.Push_back(40);
    Liinked.Push_front(-20);

    //Print the new list
    cout<<"\n\nNew List --> ";
    Liinked.Print_list();
    cout<<endl;

    //Find an element and erase it from the list
    Finder=Liinked.Find(10);
    if(Finder)
        cout<<"The Element: "<<Finder->value<<" Was Found"<<endl;
    Liinked.Erase(Finder->value);

    //Erase the element in the front and in the back and then print the list
    Liinked.Pop_back( );
    Liinked.Pop_front( );
    cout<<endl<<"New List --> ";
    Liinked.Print_list( );
    cout<<endl;

    //See the front and back
    cout<<endl<<"The element in the front is: "<<Liinked.Front( )<<endl;
    cout<<"The element in the back is: "<<Liinked.Back( )<<endl;

    //Clear List
    Liinked.Clear( );
    cout<<endl;
    Liinked.Print_list( ); 
    return 0;
}