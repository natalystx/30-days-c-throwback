#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to perform Breadth-First Search (BFS)
void bfs(struct Node* root) {
    if (root == NULL)
        return;

    // Create a queue for BFS
    struct Node** queue = (struct Node**)malloc(sizeof(struct Node*) * 100);
    int front = 0;
    int rear = 0;

    // Enqueue the root node
    queue[rear++] = root;

    while (front < rear) {
        // Dequeue a node from the queue
        struct Node* currentNode = queue[front++];

        // Process the current node
        printf("%d ", currentNode->data);

        // Enqueue the left child if it exists
        if (currentNode->left != NULL)
            queue[rear++] = currentNode->left;

        // Enqueue the right child if it exists
        if (currentNode->right != NULL)
            queue[rear++] = currentNode->right;
    }

    // Free the memory allocated for the queue
    free(queue);
}

// Function to perform Depth-First Search (DFS)
void dfs(struct Node* root) {
    if (root == NULL)
        return;

    // Process the current node
    printf("%d ", root->data);

    // Recursively traverse the left subtree
    dfs(root->left);

    // Recursively traverse the right subtree
    dfs(root->right);
}

int main() {
    // Create a sample binary tree
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("BFS traversal: ");
    bfs(root);

    printf("\nDFS traversal: ");
    dfs(root);

    return 0;
}