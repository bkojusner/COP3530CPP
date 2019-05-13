# COP3530CPP
Data Structures and Algorithms course projects

Project 1 - Recursive Derminant of a Sparse Matrix </br>
Write a program that uses a recursive algorithm to calculate the determinant of a matrix.
The program should read a matrix and calculate and print the determinant.  Your matrix 
implementation should be that of a "sparse" matrix.  Only matrix elements that are non-zero
should be allocated in memory.  This means you cannot implement your matrix with a 2D array.

Project 2 - Hashing Analysis</br>
Perform an analysis of hash table number of collisions versus load factor as a function of 
collision resolution scheme and hash function.Choose three hash table sizes.  Make one of 
the hash table sizes a prime number. For each hash table size, randomly generate key values
between 0 and 3 times the hash table size. As each key value is placed in the hash table, 
record the current load factor and the number of collisions that have occurred.  When counting 
collisions, for each key there is at most one collision. Perform this experiment for four 
combinations of hash function and collision resolution scheme.
Hash functions: key mod table size, mid square
