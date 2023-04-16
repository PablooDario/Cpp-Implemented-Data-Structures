# Deque
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
