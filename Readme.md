# Table of Contents
- [ Description and Motivation](#Hist)
- [ Contribution/Comments ](#Cont)
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
# History and Motivation

I created this project when I was in my first year of college to understand the background and how data structures really work, because I think that to really learn new things we should know how they work behind scenes and not just memorize the code.

So 1 year later I decided to create this repository, beacuse I think this project can help people, like it helped me, to understand the implementation of many Data Structures, and improve their understanding when using Data Structures.

<a id="Cont"></a>
# Contribution/Comments

I know there are many ways of implementation and surely there are better than mine, but as I said, I created this project when I was in the first year of my college and I tried make it as good as possible; so if you found a bug, a way to improve or want to contribute, feel free to comment or pull request.

<a id="Req"></a>
# Requirements
- Know c++
- Know the basics of OOP
- Know what each structure is for

<a id="Inst"></a>
# User Instructions

All the data structures where implemented in C++; for a better order, a folder was given to each structure, which has 2 files each one: 
- The library: that has all the implementation
- An example code: that has an example of how to use the structure. U can use it as a guide to create your own program using that structure. 

In order to understand the implementation you have to study the library file and then read the complexity table, which is below.

If you want to use a structure just download the library and in the same folder create a cpp code including that library **(#include "structure.h")**, use the cpp files as a guide.

In some data structures I added some functions/methods that arent used in a normal program, just in an specific program; but I added just to see how they can be implemented.

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