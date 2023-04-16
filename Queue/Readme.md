# Queue
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