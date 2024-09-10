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


void inorderTraversal(TreeNode *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}


TreeNode* mirrorTree(TreeNode *root) {
    if (root == NULL) {
        return NULL;
    }
    
    
    TreeNode *temp = root->left;
    root->left = mirrorTree(root->right);
    root->right = mirrorTree(temp);
    
    return root;
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
    TreeNode *mirroredRoot = NULL;
    int choice, data;
    
    while (1) {
        printf("\nBinary Tree Operations Menu:\n");
        printf("1. Insert Node\n");
        printf("2. Print Original Tree (In-order Traversal)\n");
        printf("3. Print Mirrored Tree (In-order Traversal)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = insertNode(root, data);
                mirroredRoot = mirrorTree(root);
                break;
                
            case 2:
                printf("Original tree in-order traversal: ");
                inorderTraversal(root);
                printf("\n");
                break;
                
            case 3:
                printf("Mirrored tree in-order traversal: ");
                inorderTraversal(mirroredRoot);
                printf("\n");
                break;
                
            case 4:
                freeTree(root);
                freeTree(mirroredRoot);
                printf("Exiting...\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    }
    
    return 0;
}
