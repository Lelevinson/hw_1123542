# Data Structure HW 2
### by Levinson_1123542
--------------------------------------------------------------------------------------------
Question 1: Binary Tree - Find the Diameter of a Binary Tree
<br>
Problem Statement:
Write a program to calculate the diameter of a binary tree. The diameter of a binary tree is the length of the longest path between any two nodes in the tree. The path may or may not pass through the root.
<br>
You are required to:
Build the binary tree using level-order input. Use -1 to represent null nodes.
Implement a function to calculate the diameter of the binary tree efficiently using recursion.
<br>
Input Format:
The first line contains a list of integers representing the level-order traversal of the binary tree. Use -1 for null nodes.
<br>
Output Format:
Print an integer representing the diameter of the binary tree.
<br>
Example:
<br>
Input:
[1, 2, 3, 4, 5, -1, -1, -1, -1, 6, 7]
<br>
Output:
5

--------------------------------------------------------------------------------------------
Question 2: Heap Sort - Build a Priority Queue for Tasks
<br>
Problem Statement:
Write a program to manage a task priority queue using a max heap. Each task has a name and a priority level. Your program should allow:
Add a Task: Add a task with a given priority.
Get the Highest Priority Task: Remove and return the task with the highest priority.
Display the Remaining Tasks: Print the remaining tasks in descending order of priority.
<br>
Input Format:
The first line contains an integer N, the number of operations.
The next N lines contain either:
"ADD task_name priority" to add a task.
"GET" to fetch the highest-priority task.
<br>
Output Format:
For every "GET" operation, print the name of the task with the highest priority.
At the end, print the list of remaining tasks in descending order of priority.
<br>
Example:
<br>
Input:
<br>
5
<br>
ADD Task1 3
<br>
ADD Task2 6
<br>
ADD Task3 9
<br>
GET
<br>
ADD Task4 7
<br>
Output:
<br>
Task3
<br>
Remaining tasks: [('Task4', 7), ('Task2', 6), ('Task1', 3)]

--------------------------------------------------------------------------------------------
Question 3: Merge K Sorted Arrays Using Min Priority Queue
<br>
You are given K sorted arrays of integers. Write a Python program to merge these arrays into a single sorted array using a Min Priority Queue.
Your program should:
Insert the first element of each array into a Min Priority Queue along with the array index and element index.
Extract the smallest element from the queue, add it to the result array, and insert the next element from the same array into the queue.
Continue this process until all elements from all arrays are merged.
<br>
Input Format
An integer K, the number of sorted arrays.
K sorted arrays, each entered on a new line, with elements separated by spaces.
<br>
Output Format
A single line containing the merged sorted array.
<br>
Example Input
<br>
3
<br>
21 23 26
<br>
22 24 25
<br>
27 28 29
<br>
Example Output
Merged Array: [21, 22, 23, 24, 25, 26, 27, 28, 29]

--------------------------------------------------------------------------------------------
Question 4: Schedule Tasks with Deadlines Using Max Priority Queue
<br>
You are given N tasks, each with a profit and a deadline. Write a Python program to schedule the tasks such that the maximum profit is achieved, using a Max Priority Queue.
Each task must be completed within its deadline (1-based index), and only one task can be scheduled at a time.
<br>
Input Format
An integer N, the number of tasks.
N lines containing two integers each: profit and deadline of a task.
<br>
Output Format
The maximum profit that can be achieved.
The list of scheduled tasks in the order they are executed.
<br>
Example Input
<br>
4
<br>
40 1
<br>
20 2
<br>
30 1
<br>
10 2
<br>
Example Output
Maximum Profit: 60
<br>
Scheduled Tasks: [40, 20]
<br>
Explanation
<br>
Input represents 4 tasks with (profit, deadline) as (40, 1), (20, 2), (30, 1), (10, 2).
<br>
Using a Max Priority Queue, tasks with higher profit are prioritized while ensuring deadlines are respected:
<br>
Task (20, 2) is scheduled in slot 2.
<br>
Task (40, 1) is scheduled in slot 1.
<br>
Total profit: 20 + 40 = 60.
