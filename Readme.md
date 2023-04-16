![Banner](../Banner.png)

# History and Motivation

I created this project when I was in my first year of college to understand the background and how data structures really work, because I think that to really learn new things we should know how they work behind scenes and not just memorize the code.

So 1 year later I decided to create this repository, beacuse I think this project can help people, like it helped me, to understand the implementation of many Data Structures, and improve their understanding when using Data Structures.

# Contribution/Comments

I know there are many ways of implementation and surely there are better than mine, but as I said, I created this project when I was in the first year of my college and I tried make it as good as possible; so if you found a bug, a way to improve or want to contribute, feel free to comment or pull request.

# Requirements
- Know c++
- Know the basics of OOP
- Know what each structure is for

# User Instructions

All the data structures where implemented in C++; for a better order, a folder was given to each structure, which has 2 files each one: 
- The library: that has all the implementation
- An example code: that has an example of how to use the structure. U can use it as a guide to create your own program using that structure. 

In order to understand the implementation you have to study the library file and then read the complexity table, which is below.

If you want to use a structure just download the library and in the same folder create a cpp code including that library **(#include "structure.h")**, use the cpp files as a guide.

# Short explanation of each Structure and its complexity

## Linked List / Double Linked List / Circular List

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

## Stack
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

## Queue
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

## Deque
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