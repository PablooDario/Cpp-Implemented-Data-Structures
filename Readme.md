# Table of Contents
- [ Requirements](#Req)
- [ User Instructions ](#Inst)
- [ Short explanation of each Structure and its complexity ](#Short)
- [ 1 Linear Structrures ](#Linear)
    - [ 1.1 Linked List / Double Linked List / Circular List](#Linked)
    - [ 1.2 Stack](#Stack)
    - [ 1.3 Queue](#Queue)
    - [ 1.4 Deque](#Deque)
- [ 2 Trees](#Trees)
    - [ 2.1 Binary Trees](#Bin)
    - [ 2.2 Complete Binary Tree](#CBT)
    - [ 2.3 Binary Search Tree](#BST)
    - [ 2.4 AVL Tree](#AVL)
    - [ 2.4 Heap/Priority Queue](#Heap)

<a id="Hist"></a>

I started this project in my first year of college to get a deeper understanding of how data structures actually work. I believe that to truly learn something, you need to understand the underlying mechanics, not just memorize the code.

A year later, I decided to share it through this repository because I think it can help others, just like it helped me, to better grasp the implementation of various data structures and improve their overall understanding when working with them.

<a id="Req"></a>
# Requirements
- Know c++
- Know the basics of OOP

<a id="Inst"></a>
# User Instructions

All the data structures are implemented in C++, and to keep things organized, each structure has its own folder. Each folder contains two files:

The library: This file includes the full implementation of the data structure.
The example code: This shows how to use the structure and can serve as a guide for creating your own programs.
To understand the implementation, start by studying the library file, then check the complexity table provided below.

If you want to use a structure, simply download the library, and in the same folder, create a .cpp file that includes the library like this: #include "structure.h". You can use the example .cpp files as a reference for how to implement it.

In some cases, I've added extra functions or methods that aren't typically used in standard programs, but I included them to show how they can be implemented in certain scenarios.

<a id="Short"></a>
# Short explanation of each Structure and its complexity

<a id="Linear"></a>
# 1 Linear Structures

<a id="Linked"></a>
## 1.1 Linked List / Double Linked List / Circular List

**Linked List**
Serially Connected Nodes consisting of 2 fields:
- Data 
- A pointer to the next node

**Double Linked List**
Serially Connected Nodes consisting of 3 fields:
- Data 
- A pointer to the next node
- A pointer to the previous node

This doesn`t change the way the list works, it is just another type of list that can facilitate the implementation.

**Circular List**
Serially Connected Nodes consisting of 2 fields:
- Data 
- A pointer to the next node

The only difference between a linked list and a circular list is that in the linked list the last node points to `NULL` and in a circular points to the first element.

**Disclaimer**: in the implementation of linked and circular list I only use a pointer to save the head of the list, but in the double linked list implementation I use another pointer to save the tail, which reduces complexity in the insertion / deletion of the last element from **O(n)** to **O(1)**.

**Good for:**
- Simple Storage
- Acces to an index
- Insert / Delete in the front
- Insert / Delete by index

**Bad for:**
- Search
- Insert / Delete lasts elements

**Complexity**
|Operation      |Time Complexity|
|      ---      |      ---      |
|Push Front     |    `O(1)`     |
|Insert by Index|    `O(n)`     |
|Push Back      |    `O(n)`     |
|Empty          |    `O(1)`     |
|Print          |    `O(n)`     |
|Pop Front      |    `O(1)`     |
|Pop Back       |    `O(n)`     |
|Erase by index |    `O(n)`     |

<a id="Stack"></a>
## 1.2 Stack
Serially Connected Nodes consisting of 2 fields: 
- Data 
- A pointer to the next node

This structure follows the LIFO rule (*Last In First Out*). You can only insert in the fornt and delete in the front.

**Disclaimer**: in this implementation I use 1 pointer to save the top the stack, since we only can insert and delete in the front.

**Good for:**
- LIFO operations
- Insert in the front
- Delete in the front

**Bad for:**
- Insert / Delete by index
- Search 

**Complexity**
|Operation|Time Complexity|
|   ---   |      ---      |
|Push     |    `O(1)`     |
|Pop      |    `O(1)`     |
|Top      |    `O(1)`     |
|Size     |    `O(1)`     |
|Empty    |    `O(1)`     |
|Print    |    `O(n)`     |
|Clear    |    `O(n)`     |

<a id="Queue"></a>
## 1.3 Queue
Serially Connected Nodes consisting of 2 fields: 
- Data 
- A pointer to the next node

This structure follows the FIFO rule (*First In First Out*). You can only insert in the back and delete in the front.

**Disclaimer**: in this implementation I use 2 pointers to save the head and the tail of the queue to reduce complexity, since we use the pointer to the tail to insert and the pointer to the head to delete.

**Good for:**
- FIFO operations
- Insert in the back
- Delete in the front

**Bad for:**
- Insert / Delete by index 

**Complexity**
|Operation|Time Complexity|
|   ---   |      ---      |
|Push     |    `O(1)`     |
|Pop      |    `O(1)`     |
|Front    |    `O(1)`     |
|Back     |    `O(1)`     |
|Size     |    `O(1)`     |
|Empty    |    `O(1)`     |
|Print    |    `O(n)`     |
|Clear    |    `O(n)`     |

<a id="Deque"></a>
## 1.4 Deque
Serially Connected Nodes consisting of 2 fields: 
- Data 
- A pointer to the next node

This structure is a double ended queue, despite beig a queue, it doesn`t follows the FIFO rule (*First In First Out*). In this structure the insertion and the deletion can either be performed by the front or by the tail.

**Disclaimer**: in this implementation I use 2 pointers to save the head and the tail of the deque to reduce complexity, as in the queue.

**Good for:**
- Insert in the front/back
- Delete in the front/back

**Bad for:**
- Insert / Delete by index 

**Complexity**
|Operation      |Time Complexity|
|      ---      |      ---      |
|Push Front     |    `O(1)`     |
|Push Back      |    `O(1)`     |
|Pop Front      |    `O(1)`     |
|Pop Back       |    `O(n)`     |
|Empty          |    `O(1)`     |
|Print          |    `O(n)`     |
|Front          |    `O(1)`     |
|Back           |    `O(1)`     |
|Clear          |    `O(n)`     |

<a id="Trees"></a>
# 2 Trees

Connected Nodes consisting of 3 fields: 
- Data 
- A pointer to the left child
- A pointer to the right child

Tress are useful for O(log2 (n)) operations, despite this, binary tree and full binary tree operations have linear complexities, because they are general trees and their implementation is tedious; the benefits come in trees with more specific functionalities, such as AVL or heap. 

<a id="Bin"></a>
## 2.1 Binary Tree

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

<a id="CBT"></a>
## 2.2 Complete Binary Tree

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

<a id="BST"></a>
## 2.3 Binary Search Tree

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

<a id="AVL"></a>
## 2.4 AVL Tree

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

<a id="Heap"></a>
## 2.5 Min Heap/ Max Heap / Priority Queue

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
