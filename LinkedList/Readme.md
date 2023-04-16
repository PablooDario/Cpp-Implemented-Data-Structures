# Linked List / Double Linked List / Circular List

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