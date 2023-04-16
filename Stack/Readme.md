# Stack
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