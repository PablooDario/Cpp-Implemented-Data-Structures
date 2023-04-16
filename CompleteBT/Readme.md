# Trees

Connected Nodes consisting of 3 fields: 
- Data 
- A pointer to the left child
- A pointer to the right child

Tress are useful for O(log2 (n)) operations, despite this, binary tree and full binary tree operations have linear complexities, because they are general trees and their implementation is tedious; the benefits come in trees with more specific functionalities, such as AVL or heap. 

# Complete Binary Tree

This structure consits in nodes with at most 2 childs per node parent, the difference between a normal Binary Tree, is that here you can not insert the nodes where you want, the nodes are added to the leftmost parent node that has an empty child.

Due to this you dont have to worry about where the node goes, yo just push; the same for delete a node, the node that you delete is the deepest or the last added.

**Disclaimer**: in this implementation repeated data is not allowed.

**Complexity**
|Operation      |Time Complexity|
|      ---      |      ---      |
|Insert         |    `O(n)`     |
|Print          |    `O(n)`     |
|Find           |    `O(n)`     |
|Delete         |    `O(n)`     |
|Deepest Node   |    `O(n)`     |
|Clear          |    `O(n)`     |
|Traverse Tree  |    `O(n)`     |