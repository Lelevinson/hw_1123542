// Name: Levinson
// Student ID: 1123542
// Date of Submission: 2024/11/25
#include <iostream>
#include <vector>
#include <queue>
#include <sstream> // Include this for stringstream

using namespace std;

// Structure to store element value, array index, and element index
struct Element
{
    int value;     // The value of the element
    int arrIndex;  // The index of the array the element comes from
    int elemIndex; // The index of the element in the array

    // Overload the greater than operator to make this a min-heap
    bool operator>(const Element &other) const
    {
        return value > other.value;
    }
};

// Function to merge K sorted arrays using a min priority queue (min-heap)
vector<int> mergeKSortedArrays(const vector<vector<int>> &arrays)
{
    // Min priority queue to store the elements, array index, and element index
    priority_queue<Element, vector<Element>, greater<Element>> minHeap;
    vector<int> result; // To store the merged sorted array

    // Step 1: Insert the first element of each array into the min-heap
    for (int i = 0; i < arrays.size(); ++i)
    {
        if (!arrays[i].empty())
        {
            // Add the first element of each array to the heap
            minHeap.push({arrays[i][0], i, 0});
        }
    }

    // Step 2: Continue the process of extracting the smallest element and
    // inserting the next element from the same array until the heap is empty
    while (!minHeap.empty())
    {
        // Get the smallest element from the heap
        Element current = minHeap.top();
        minHeap.pop();

        // Add the smallest element to the result array
        result.push_back(current.value);

        // Check if there is a next element in the same array
        if (current.elemIndex + 1 < arrays[current.arrIndex].size())
        {
            // Add the next element from the same array to the heap
            int nextValue = arrays[current.arrIndex][current.elemIndex + 1];
            minHeap.push({nextValue, current.arrIndex, current.elemIndex + 1});
        }
    }

    return result; // Return the merged sorted array
}

int main()
{
    int K; // Number of sorted arrays
    cout << "Enter the number of sorted arrays: ";
    cin >> K;     // User input for the number of arrays
    cin.ignore(); // To handle the newline character after K

    vector<vector<int>> arrays(K); // Vector of vectors to store the sorted arrays

    // User input for each array
    for (int i = 0; i < K; ++i)
    {
        cout << "Enter the elements of array " << i + 1 << " (space-separated): ";
        string line;
        getline(cin, line); // Read the entire line for the current array

        // Parse the line into integers and store them in the respective array
        int num;
        stringstream ss(line); // Use stringstream to extract integers from the line
        while (ss >> num)
        {
            arrays[i].push_back(num); // Add the integer to the i-th array
        }
    }

    // Call the function to merge K sorted arrays
    vector<int> mergedArray = mergeKSortedArrays(arrays);

    // Output the merged sorted array
    cout << "Merged Array: [";
    for (size_t i = 0; i < mergedArray.size(); ++i)
    {
        cout << mergedArray[i];
        if (i != mergedArray.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
