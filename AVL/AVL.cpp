#include "AVL.h"

int main()
{
    //Create the AVL tree
    AVLTree Forest;
    Forest.CreateRoot(0);

    //Insert nodes
    Forest.Insert(1);
    Forest.Insert(2);
    Forest.Insert(3);
    Forest.Insert(4);
    Forest.Insert(5);
    Forest.Insert(6);
    Forest.Insert(7);
    Forest.Insert(8);
    Forest.Insert(9);
    Forest.Insert(10);
    Forest.Insert(11);
    Forest.Insert(12);

    //Print the tree
    Forest.PrintBT();

    //Print in Preorder, Inorder and Postorder
    cout<<"\n\nPreorder -----> ";
    Forest.Preorder();
    cout<<"\nInorder -----> ";
    Forest.Inorder();
    cout<<"\nPostorder -----> ";
    Forest.Postorder();

    //Delete some nodes and then print it
    Forest.Delete(9);
    Forest.Delete(6);
    Forest.Delete(7);
    cout<<"\n\n--------New Tree---------";
    Forest.PrintBT();

    //Search Elements
    node *aux=Forest.Find(5);
    if(aux!=nullptr)
        cout<<"\n\nThe node "<<aux->value<<" is in the tree";
    else
        cout<<"\n\nThe node 5 isnt in the tree";

    aux=Forest.Find(18);
    if(aux!=nullptr)
        cout<<"\n\nThe node "<<aux->value<<" is in the tree";
    else
        cout<<"\nThe node 18 isnt in the tree";

    //Get the maximun and minimun nodes of the tree
    aux=Forest.Max();
    cout<<"\n\nThe Maximun value in the tree is ----> "<<aux->value;
    aux=Forest.Min();
    cout<<"\nThe Minimun value in the tree is ----> "<<aux->value;

    //Clear the tree and then print it
    Forest.ClearTree ();
    cout<<endl<<"\n--------Final Tree---------\n";
    Forest.PrintBT();
    return 0;
}