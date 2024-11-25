// Name: Levinson
// Student ID: 1123542
// Date of Submission: 2024/11/25
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Define a structure for the binary tree node
struct TreeNode
{
    int val;         // Node's value
    TreeNode *left;  // Pointer to left child
    TreeNode *right; // Pointer to right child

    // Constructor to initialize the node
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to build the binary tree from level-order input
TreeNode *buildTree(const vector<int> &values)
{
    if (values.empty() || values[0] == -1)
        return NULL;

    // Create the root of the tree
    TreeNode *root = new TreeNode(values[0]);

    // Use a queue to facilitate level-order construction
    queue<TreeNode *> q;
    q.push(root);

    int i = 1; // Index to track position in the input array

    while (!q.empty() && i < values.size())
    {
        TreeNode *current = q.front();
        q.pop();

        // Handle the left child
        if (values[i] != -1)
        {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;

        // Ensure we don't go out of bounds
        if (i >= values.size())
            break;

        // Handle the right child
        if (values[i] != -1)
        {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }

    return root;
}

// Helper function to calculate the diameter and height of the tree
// This function returns the height of the tree and updates the diameter
int calculateDiameter(TreeNode *root, int &maxDiameter)
{
    // Base case: If the node is null, the height is 0
    if (!root)
        return 0;

    // Recursively calculate the height of the left and right subtrees
    int leftHeight = calculateDiameter(root->left, maxDiameter);
    int rightHeight = calculateDiameter(root->right, maxDiameter);

    // The diameter at this node is the sum of the heights of the left and right subtrees
    int currentDiameter = leftHeight + rightHeight;

    // Update the maximum diameter if the current one is larger
    maxDiameter = max(maxDiameter, currentDiameter);

    // Return the height of the current node (1 + max of left or right subtree heights)
    return 1 + max(leftHeight, rightHeight);
}

// Function to find the diameter of the binary tree
int findDiameter(TreeNode *root)
{
    int maxDiameter = 0; // To store the maximum diameter
    calculateDiameter(root, maxDiameter);
    return maxDiameter;
}

int main()
{
    // Input: Level-order traversal of the binary tree (using -1 for null nodes)
    cout << "Enter the level-order traversal of the binary tree (-1 for null nodes, space-separated): ";

    vector<int> values;
    int value;

    // Read integers from input until end of input (EOF or new line)
    while (cin >> value)
    {
        values.push_back(value);
        // Break the loop on new line input (optional)
        if (cin.peek() == '\n')
            break;
    }

    // Step 1: Build the binary tree from the input
    TreeNode *root = buildTree(values);

    // Step 2: Calculate the diameter of the tree
    int diameter = findDiameter(root);

    // Step 3: Output the result
    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
