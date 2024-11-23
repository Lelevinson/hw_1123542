// Name: Levinson
// Student ID: 1123542
// Date of Submission: 2024/11/25
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// Structure to represent a task
struct Task
{
    int profit;
    int deadline;

    // Constructor to initialize a task
    Task(int p, int d) : profit(p), deadline(d) {}
};

// Comparator to sort tasks by their profit in descending order
bool compare(Task t1, Task t2)
{
    return t1.profit > t2.profit;
}

int main()
{
    int N;

    // Step 1: Input the number of tasks
    cout << "Enter the number of tasks: ";
    cin >> N;

    vector<Task> tasks;

    // Step 2: Input profit and deadline for each task
    cout << "Enter the profit and deadline for each task:\n";
    for (int i = 0; i < N; ++i)
    {
        int profit, deadline;
        cin >> profit >> deadline;
        tasks.emplace_back(profit, deadline); // Adding tasks to the vector
    }

    // Step 3: Sort tasks by profit in descending order
    sort(tasks.begin(), tasks.end(), compare);

    // Step 4: Create a max heap (priority queue) to schedule tasks by deadline
    // We will store which slots (days) are available in a boolean array
    int maxDeadline = 0;

    // Find the maximum deadline among all tasks
    for (int i = 0; i < N; ++i)
    {
        if (tasks[i].deadline > maxDeadline)
            maxDeadline = tasks[i].deadline;
    }

    // Create a vector to keep track of scheduled tasks (1-based index for slots)
    vector<int> slots(maxDeadline + 1, -1); // Initially all slots are available
    int maxProfit = 0;                      // To track total profit
    vector<int> scheduledTasks;             // To store the scheduled tasks (profits)

    // Step 5: Schedule the tasks
    for (int i = 0; i < N; ++i)
    {
        // Try to find a free slot for the current task, starting from its deadline
        for (int j = tasks[i].deadline; j > 0; --j)
        {
            if (slots[j] == -1)
            {                                              // If the slot is available
                slots[j] = i;                              // Assign this task to the slot
                scheduledTasks.push_back(tasks[i].profit); // Save the task's profit
                maxProfit += tasks[i].profit;              // Add the task's profit
                break;                                     // Move to the next task
            }
        }
    }

    // Step 6: Output the results
    cout << "\nMaximum Profit: " << maxProfit << endl;
    cout << "Scheduled Tasks: [";
    for (int i = 0; i < scheduledTasks.size(); ++i)
    {
        cout << scheduledTasks[i];
        if (i != scheduledTasks.size() - 1)
        {
            cout << ", "; // Add a comma between profits
        }
    }
    cout << "]" << endl;

    return 0;
}
