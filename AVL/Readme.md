# Trees

Connected Nodes consisting of 3 fields: 
- Data 
- A pointer to the left child
- A pointer to the right child

Tress are useful for O(log2 (n)) operations, despite this, binary tree and full binary tree operations have linear complexities, because they are general trees and their implementation is tedious; the benefits come in trees with more specific functionalities, such as AVL or heap. 

# AVL Tree

This structure consits in nodes with at most 2 childs per node parent. An AVL tree is a Binary Search Tree, so it has all the properties of this one, with the exception that the AVL tree is a strictly self-balancing tree  through rotations.

Due to this all the insertions, deletions and searchs are logaritmic even in the worst case.

**Disclaimer**: in this implementation repeated data is not allowed.

**Complexity**
|Operation      |Time Complexity|
|      ---      |      ---      |
|Insert         |    `O(log n)` |
|Print          |    `O(n)`     |
|Find           |    `O(log n)` |
|Max / Min      |    `O(log n)` |
|Delete         |    `O(log n)` |
|Empty          |    `O(1)`     |
|Clear          |    `O(n)`     |
|Traverse Tree  |    `O(n)`     |