# Trees

Connected Nodes consisting of 3 fields: 
- Data 
- A pointer to the left child
- A pointer to the right child

Tress are useful for O(log2 (n)) operations, despite this, binary tree and full binary tree operations have linear complexities, because they are general trees and their implementation is tedious; the benefits come in trees with more specific functionalities, such as AVL or heap. 

# Binary Tree

This structure consits in nodes with at most 2 childs per node parent, beacuse of this, it is no longer a linear structure.

**Disclaimer**: in this implementation repeated data is not allowed. The implementation is a bit confusing because it was made with the object oriented paradigm and we must be very specific where we want to place the node, in the other trees the implementation is much simpler and easier to understand. 

Due to this difficult implementation, some operations increase the complexity, in order to have a better understanding I will put the complexity of the operations that I implemented

**Complexity**
|Operation      |Time Complexity|
|      ---      |      ---      |
|Insert         |    `O(n)`     |
|Level of a node|    `O(n)`     |
|Tree Height    |    `O(1)`     |
|Find           |    `O(n)`     |
|Delete         |    `O(n)`     |
|Deepest Node   |    `O(n)`     |
|Clear          |    `O(n)`     |
|Traverse Tree  |    `O(n)`     |