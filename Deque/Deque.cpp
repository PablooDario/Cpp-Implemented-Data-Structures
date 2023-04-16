#include "Deque.h"

int main()
{
    Deque Deck;

    //Pop elements when the deque is empty and the print it
    Deck.Pop_back();
    Deck.Pop_front();
    cout<<endl;
    Deck.PrintDeque();

    //Insert elements
    Deck.Push_front(3);
    Deck.Push_back(4);
    Deck.Push_front(2);
    Deck.Push_back(5);
    Deck.Push_back(6);
    Deck.Push_front(1);
    Deck.Push_front(0);
    Deck.Push_back(7);
    Deck.Push_back(8);
    Deck.Push_front(2);
    Deck.Push_back(3);
    Deck.Push_front(10);
    Deck.Push_back(9);

    //Print the Deque
    cout<<"\nThe deque is --> ";
    Deck.PrintDeque();

    //Pop some elements and print the deque
    Deck.Pop_back();
    Deck.Pop_front();
    Deck.Pop_front();
    Deck.Pop_back();
    cout<<"\n\nThe new deque is --> ";
    Deck.PrintDeque();

    //See the elements at the back and front
        cout<<"\nThe element at the front is: "<<Deck.Front();
        cout<<"\nThe element at the back is: "<<Deck.Back();

    //Clear the deque
    cout<<"\n\nThe deque was cleared succesfully"<<endl;
    Deck.Clear();
    Deck.PrintDeque();
    return 0;
}