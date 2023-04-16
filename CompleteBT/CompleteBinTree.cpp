#include "CompleteBinTree.h"

int main()
{
    //Create a tree
    CompleteBT myTree;

    //Create the root *This Step is necesary when yu create the tree*
    myTree.CreateRoot(10);
    node *aux;

    //Delete the root
    myTree.DeleteDeepest();

    //Found the deepest node in an empty tree
    aux=myTree.DeepestNode();
    if(aux!=nullptr)
        cout<<"Deepest Node: "<<aux->value;
    else
        cout<<"\nEmpty Tree\n\n";

    //Push Elements
    for(int i=16; i>1; i--)
        myTree.PushBT(i);

    //Print the Tree
    cout<<"------------ New Tree --------------";
    myTree.PrintBT();

    //Print the tree in the three traversal modes
    cout<<"\n\n----------- PreOrder --------------- \t------------ InOrder --------------\t";
    cout<<"------------- PostOrder -------------\n";
    myTree.PreOrder();
    cout<<"\t";
    myTree.InOrder();
    cout<<"\t";
    myTree.PostOrder();

    //Print the right and left side
    cout<<endl<<endl;
    myTree.PrintLeft();
    cout<<endl<<endl;
    myTree.PrintRight();

    //Search a Node
    aux=myTree.FindNode(20);
    cout<<"\n\n20 is ";
    if(aux!=nullptr)
        cout<<"in the tree";
    else
        cout<<"an inexistent node\n";

    //Found the deepest node
    aux=myTree.DeepestNode();
    if(aux!=nullptr)
        cout<<"Deepest Node: "<<aux->value;
    else
        cout<<"\nEmpty Tree\n\n";

    //Print a Particular level
    cout<<endl;
    myTree.PrintLevel(2);

    //Delete the deepest node and a particular node
    cout<<"\n\nDeleting the deppest node and the node 13.......\n";
    myTree.DeleteNode(13);
    myTree.DeleteDeepest();

    //Print the final Tree
    cout<<"\n------------ Final Tree --------------";
    myTree.PrintBT();

    //Clear the tree and dynamic memory created
    myTree.Clear();
    cout<<endl<<endl;
    myTree.PrintBT();
    return 0;
}