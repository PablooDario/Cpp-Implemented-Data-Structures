![Banner](../Banner.png)

# History and Motivation

I created this project when I was in my first year of college to understand the background and how data structures really work, because I think that to really learn new things we should know how they work behind scenes and not just memorize the code.

So 1 year later I decided to create this repository, beacuse I think this project can help people, like it helped me, to understand the implementation of many Data Structures, and imrpove their understanding when using Data Structures.

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

## Linked List / Circular List
Serially Connected Nodes consisting of 2 fields: data and a pointer to the next node.

**Disclaimer**: in this implementation I only use a pointer to save the headof the list, but other implementations use another pointer to save the tail, which reduces complexity in the insertion / deletion of the last element from **O(n)** to **O(1)**; but I decided to use the classic implementation.

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
|Push Back      |    `O(n)`     |