#include "BST.h"

int main()
{
    //Create the binary tree
    BinarySearchTree Forest;
    Forest.CreateRoot(35);

    //Insert nodes
    Forest.Insert(30);
    Forest.Insert(50);
    Forest.Insert(22);
    Forest.Insert(32);
    Forest.Insert(47);
    Forest.Insert(58);
    Forest.Insert(31);
    Forest.Insert(10);
    Forest.Insert(27);
    Forest.Insert(48);
    Forest.Insert(55);
    Forest.Insert(60);

    //Print the left and right sides of the tree
    Forest.PrintBT();
    cout<<endl<<endl;
    Forest.PrintLeft();
    cout<<endl<<endl;
    Forest.PrintRight();

    //Print in Preorder, Inorder and Postorder
    cout<<"\n\nPreorder -----> ";
    Forest.Preorder();
    cout<<"\nInorder -----> ";
    Forest.Inorder();
    cout<<"\nPostorder -----> ";
    Forest.Postorder();

    //Delete some nodes and then print it
    Forest.Delete(35);
    Forest.Delete(27);
    Forest.Delete(32);
    cout<<"\n\n--------New Tree---------";
    Forest.PrintBT();

    //Search Elements
    node *aux=Forest.Find(55);
    if(aux!=nullptr)
        cout<<"\n\nThe node "<<aux->value<<" is in the tree";
    else
        cout<<"\n\nThe node 55 isnt in the tree";

    aux=Forest.Find(26);
    if(aux!=nullptr)
        cout<<"\n\nThe node "<<aux->value<<" is in the tree";
    else
        cout<<"\nThe node 26 isnt in the tree";

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