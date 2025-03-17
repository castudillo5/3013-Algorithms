## 06-H02
### Carlos Astudillo
### Description:

Google drawings on linear probing and chaining
 
### Files:

|  #  |  File  |  Description  |
| :---: | ---------------- | -------------------------------------------------- |
|  1  |  [Link 1](https://github.com/castudillo5/3013-Algorithms/blob/main/Assignments/06-H02/hashing%20-4.jpg)  |  Directory to image for exercise 1  |
|  2  |  [Link 2](https://github.com/castudillo5/3013-Algorithms/blob/main/Assignments/06-H02/Linear%20probing%20.jpg)  |  Directory to image for exercise 2 |
|  3  |  [Link 3](https://github.com/castudillo5/3013-Algorithms/blob/main/Assignments/06-H02/poor%20table%20sizes.jpg)  |  Directory to image for exercise 3  |



### Conceptual Questions:

### 1.Define Hashing and Collision Resolution
### What is a hash table and why is collision resolution necessary?
A hash table stores key-value pairs using a hash function to map keys to an index. Collisions happen when different keys get the same index. To handle this, we use collision resolution methods like:
Separate Chaining – Store multiple values in a list at the same index.
Open Addressing – Find another open spot in the table using probing techniques.
### Explain the key differences between open hashing (chaining) and closed hashing (open addressing).
Open hashing (chaining) stores multiple values in a bucket using linked lists, requiring extra memory but handling collisions efficiently, while closed hashing (open addressing) keeps all entries in the table, resolving collisions by probing for empty slots, which can lead to clustering and slower performance.
### 2.Collision Resolution Techniques

### Briefly describe at least two methods for resolving collisions in open addressing (e.g., linear probing, quadratic probing, double hashing).In open addressing, collisions are resolved by finding another open slot in the table. Two common methods are:
Linear Probing – If a collision occurs, check the next available slot (index + 1, index + 2, ...). Simple but can cause clustering (many keys group together).
Quadratic Probing – Instead of checking the next slot linearly, use a quadratic sequence (index + 1², index + 2², ...). Reduces clustering but may not use all slots efficiently.

### Explain the pros and cons of each method.
Linear Probing
Pros: Simple and fast to compute.
Cons: Causes primary clustering, where groups of occupied slots form, slowing searches.
Quadratic Probing
Pros: Reduces clustering by spreading values out more evenly.
Cons: May not find an empty slot if the table size isn’t carefully chosen (e.g., must be prime).
### Which collision resolution technique can handle more values than table slots. Explain.
Separate Chaining (Open Hashing) can handle more values than there are table slots because each index stores multiple values using linked lists (or other structures like binary trees). When a collision occurs, new values are simply appended to the existing list at that index. This allows the hash table to store an unlimited number of values (limited only by available memory), unlike Open Addressing, where the total number of elements is restricted by table size.
### What is the worst performance (big oh) for each type of collision resolution technique?
Separate Chaining (Open Hashing) – O(n)
If all keys hash to the same index, the linked list (or tree) at that index grows, leading to O(n) search time in the worst case.
Using balanced trees instead of linked lists improves worst-case to O(log n).
Linear Probing (Open Addressing) – O(n)
In the worst case (if the table is nearly full and clustering occurs), searching may require scanning almost the entire table.
Quadratic Probing (Open Addressing) – O(n)
If too many collisions occur and the table is poorly sized, it may require scanning multiple spots before finding an empty one.
Double Hashing (Open Addressing) – O(n)
In the worst case, all hash probes may cycle through most of the table, making search time O(n).
Performs better than linear probing in practice due to reduced clustering.
### 3.Impact of Hash Table Size

### How does the choice of table size affect the distribution of keys?
The table size affects key distribution by influencing collisions. A prime number table size ensures better distribution, while a power-of-two size may cause patterns leading to clustering. The load factor also impacts distribution; a higher load factor increases collisions, and resizing the table helps maintain efficiency. The collision resolution method also affects performance.
### What are the pitfalls of using a poor table size (for example, a table size that is a round number or a power of 2)?
poor table sizes can result in uneven key distribution, inefficient memory usage, and reduced performance.
