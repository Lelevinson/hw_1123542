# Data Structure HW 2
# Levinson_1123542
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
6
ADD Task1 10
ADD Task2 15
ADD Task3 5
GET
ADD Task4 20
GET
<br>
Output:
Task2
Task4
Remaining tasks: [('Task1', 10), ('Task3', 5)]

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
1 4 7
<br>
2 5 8
<br>
3 6 9
<br>
Example Output
Merged Array: [1, 2, 3, 4, 5, 6, 7, 8, 9]

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
100   2
<br>
19   1
<br>
27   2
<br>
25   1
<br>
Example Output
Maximum Profit: 127
<br>
Scheduled Tasks: [100, 27]
<br>
Explanation
<br>
Input represents 4 tasks with (profit, deadline) as (100, 2), (19, 1), (27, 2), (25, 1).
<br>
Using a Max Priority Queue, tasks with higher profit are prioritized while ensuring deadlines are respected:
<br>
Task (100, 2) is scheduled in slot 2.
<br>
Task (27, 2) is scheduled in slot 1.
<br>
Total profit: 100 + 27 = 127.
