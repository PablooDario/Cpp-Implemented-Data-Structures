# Trees

Connected Nodes consisting of 3 fields: 
- Data 
- A pointer to the left child
- A pointer to the right child

Tress are useful for O(log2 (n)) operations, despite this, binary tree and full binary tree operations have linear complexities, because they are general trees and their implementation is tedious; the benefits come in trees with more specific functionalities, such as AVL or heap. 

# Min Heap/ Max Heap / Priority Queue

This structure consits in nodes with at most 2 childs per node parent. A Min heap is used to order the data, where the node parent is less than its children, so we can infer the root is the minimun node in all the tree. The same happen with the Max Heap, only instead of being the minimun is the maximun.

Despite being a tree, the implementation is with an array or vector.
Since the heap is used for Priority Queues, I implemented these Heaps as Priority Queues, but the operations are essentially the same; the only difference is that in a priority queue only the front node can be removed.

**Disclaimer**: in this implementation repeated data is not allowed.

**Complexity**
|Operation      |Time Complexity|
|      ---      |      ---      |
|Push           |    `O(log n)` |
|Pop            |    `O(log n)` |
|Top            |    `O(1)`     |
|Size           |    `O(1)`     |
|Empty          |    `O(1)`     |
|Print          |    `O(n)`     |
|Clear          |    `O(n)`     |