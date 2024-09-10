#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if (!newNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


TreeNode* insertNode(TreeNode *root, int data) {
    
    if (root == NULL) {
        return createNode(data);
    }
    
    
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    
    
    return root;
}


int height(TreeNode *root) {
    if (root == NULL) {
        return -1;  
    }
    
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
   subtrees
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}


void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


void freeTree(TreeNode *root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main() {
    TreeNode *root = NULL;
    int choice, data;
    
    while (1) {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Display Tree (In-order Traversal)\n");
        printf("3. Calculate Tree Height\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                break;
                
            case 2:
                printf("In-order traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
                
            case 3:
                {
                    int treeHeight = height(root);
                    printf("Height of the tree: %d\n", treeHeight);
                }
                break;
                
            case 4:
                freeTree(root);
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    }
    
    return 0;
}
