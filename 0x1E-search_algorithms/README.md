# 0x1E. C - Search Algorithms

#Requirements
--General
Allowed editors: vi, vim, emacs
All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
All your files should end with a new line
A README.md file, at the root of the folder of the project, is mandatory
Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
You are not allowed to use global variables
No more than 5 functions per file
You are only allowed to use the printf function of the standard library. Any call to another function like strdup, malloc, … is forbidden.
In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
The prototypes of all your functions should be included in your header file called search_algos.h
Don’t forget to push your header file
All your header files should be include guarded


#More Info
You will be asked to write files containing big O notations. Please use this format:

O(1)
O(n)
O(n!)
n*m -> O(nm)
n square -> O(n^2)
sqrt n -> O(sqrt(n))
log(n) -> O(log(n))
n * log(n) -> O(nlog(n))
…

#PROJECT TASKS
0. Linear search

0-linear.c: C function that searches for a value in an array of integers using linear search.
If the value is not present or the array is NULL, returns -1.
Otherwise, returns the first index where value is located.
1. Binary search

1-binary.c: C function that searches for a value in a sorted array of integers using binary search.
Assumes the array is sorted in ascending order and that the value to search for is not repeated in the array.
If the value is not present or the array is NULL, returns -1.
Otherwise, returns the index where value is located.
2. Big O #0

2-O: Text file containing the worst case time complexity of linear search.
3. Big O #1

3-O: Text file containing the worst case space complexity of iterative linear search.
4. Big O #2

4-O: Text file containing worst case case time complexity of binary search.
5. Big O #3

5-O: Text file containing the worst case space complexity of binary search.
6. Big O #4

6-O: Text file containing the space complexity of the following algorithm
