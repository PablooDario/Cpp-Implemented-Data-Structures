//This tree doesnt accept repeated values

//In a normal Binary Tree you have to insert the values manually because the computer doesn´t know where to put the node; so you have to pass the value of the new node, 
//the level of the node father, the Position of that node in that level and if you want to insert a lef or right child

//To insert values in a Binary Tree, first you have to create the root

#include "BinaryTree.h"
using namespace std;

int main()
{
    //Create a new tree and Print it
    cout<<endl;
    BinTree BTree;
    BTree.PrintBT();

    //Create a root 
    BTree.CreateRoot(0);

    //Insert nodes
    BTree.InsertNode(1, 0, 0, 'l');
    BTree.InsertNode(2, 0, 0, 'r');
    BTree.InsertNode(4, 1, 0, 'l');
    BTree.InsertNode(5, 1, 1, 'r');

    //Print the tree
    cout<<endl<<endl;
    cout<<"--------New Tree--------";
    BTree.PrintBT();

    //Obtaining the level and position of a node (the position of a node is the position in the level, not in all the tree) 
    cout<<"\n\nThe level of the node 2 is: "<<BTree.LevelNode(2)<<" and its position in that level is " <<BTree.PositionNode(2);

    //Replace and Insert nodes with existing values in the tree (wont happen nothing)
    BTree.ReplaceNode(1, 2); 
    BTree.InsertNode(4, 1, 0, 'r');

    //Delete a node, replace a node and Insert more nodes
    BTree.DeleteNode(4);
    BTree.InsertNode(3, 1, 0, 'l');
    BTree.InsertNode(4, BTree.LevelNode(1), BTree.PositionNode(1), 'r');
    BTree.ReplaceNode(5, 6);
    BTree.InsertNode(5, BTree.LevelNode(2), BTree.PositionNode(2), 'l');
    BTree.InsertNode(7, BTree.LevelNode(3), BTree.PositionNode(3), 'l');
    BTree.InsertNode(8, BTree.LevelNode(6), BTree.PositionNode(6), 'r');

    //Print the new tree
    cout<<"\n\n--------New Tree--------";
    BTree.PrintBT();

    //Traverse de tree
    cout<<"\n\nPreorder------> ";
    BTree.Preorder();
    cout<<"\nInorder-------> ";
    BTree.Inorder();
    cout<<"\nPostorder-----> ";
    BTree.Postorder();

    //get the deepest node
    node *aux=BTree.DeepestNode();
    if(aux)
        cout<<"\n\nThe deepest node is "<<aux->value;

    //Find a node
    aux=BTree.FindNode(5);
    if(aux==nullptr)
        cout<<"\nThe node 5 doesnt exist in the tree";
    else
        cout<<"\nThe node "<<aux->value<<" is in the tree\n";

    //Clear the tree and print it
    BTree.ClearTree();
    cout<<"\n-----------Final Tree---------\n";
    BTree.PrintBT();
    cout<<"\nHeight of the tree "<<BTree.TreeHeight()<<endl; 
    return 0;
}