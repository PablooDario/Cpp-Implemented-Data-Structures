# Trees

Connected Nodes consisting of 3 fields: 
- Data 
- A pointer to the left child
- A pointer to the right child

Tress are useful for O(log2 (n)) operations, despite this, binary tree and full binary tree operations have linear complexities, because they are general trees and their implementation is tedious; the benefits come in trees with more specific functionalities, such as AVL or heap. 

# Binary Search Tree

This structure consits in nodes with at most 2 childs per node parent, where the leftchild is less than its parent and the right child is greater than its parent. This tree is used to order the nodes depending on their data, which helps us for the search, also due to this order, the complexity of its operations are logarithmic (in some cases the operations are O(n), due to this AVL tree was created).

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