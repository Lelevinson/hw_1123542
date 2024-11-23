// Name: Levinson
// Student ID: 1123542
// Date of Submission: 2024/11/25
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Structure to store task name and priority
struct Task
{
    string name;
    int priority;

    // Overload the less than operator to compare tasks based on priority
    // This is for max-heap (we want the highest priority to come first)
    bool operator<(const Task &other) const
    {
        return priority < other.priority;
    }
};

// Function to add a task to the priority queue
void addTask(priority_queue<Task> &taskQueue, string taskName, int priority)
{
    Task newTask = {taskName, priority}; // Create a new task
    taskQueue.push(newTask);             // Add it to the max-heap (priority queue)
}

// Function to get and remove the highest priority task
void getHighestTask(priority_queue<Task> &taskQueue, vector<Task> &completedTasks)
{
    if (!taskQueue.empty())
    {
        Task topTask = taskQueue.top();    // Get the highest priority task
        cout << topTask.name << endl;      // Print the task name
        taskQueue.pop();                   // Remove the task from the queue
        completedTasks.push_back(topTask); // Keep track of tasks that have been fetched
    }
    else
    {
        cout << "No tasks available!" << endl; // If queue is empty
    }
}

// Function to display remaining tasks in descending order of priority
void displayRemainingTasks(priority_queue<Task> &taskQueue)
{
    vector<Task> remainingTasks;

    // Copy all remaining tasks from the priority queue to a vector
    while (!taskQueue.empty())
    {
        remainingTasks.push_back(taskQueue.top());
        taskQueue.pop();
    }

    // Display the remaining tasks
    cout << "Remaining tasks: [";
    for (size_t i = 0; i < remainingTasks.size(); ++i)
    {
        cout << "('" << remainingTasks[i].name << "', " << remainingTasks[i].priority << ")";
        if (i != remainingTasks.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main()
{
    int N; // Number of operations
    cout << "Enter the number of operations: ";
    cin >> N;     // User input for number of operations
    cin.ignore(); // To handle the newline character after N

    priority_queue<Task> taskQueue; // Priority queue to store tasks
    vector<Task> completedTasks;    // To keep track of tasks that were fetched by 'GET'

    // Loop through N operations
    for (int i = 0; i < N; ++i)
    {
        string command;
        cout << "Enter command (ADD task_name priority or GET): ";
        getline(cin, command); // Get the entire line as input

        if (command.substr(0, 3) == "ADD")
        {
            // If the command is ADD, extract the task name and priority
            string taskName;
            int priority;
            size_t pos1 = command.find(' ', 4);        // Find space after "ADD "
            taskName = command.substr(4, pos1 - 4);    // Extract task name
            priority = stoi(command.substr(pos1 + 1)); // Extract priority

            addTask(taskQueue, taskName, priority); // Add task to queue
        }
        else if (command == "GET")
        {
            // If the command is GET, retrieve the highest priority task
            getHighestTask(taskQueue, completedTasks);
        }
    }

    // After all operations, display remaining tasks in descending priority order
    displayRemainingTasks(taskQueue);

    return 0;
}
