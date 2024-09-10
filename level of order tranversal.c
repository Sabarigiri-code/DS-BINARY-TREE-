#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;


typedef struct QueueNode {
    TreeNode *treeNode;
    struct QueueNode *next;
} QueueNode;


typedef struct Queue {
    QueueNode *front;
    QueueNode *rear;
} Queue;


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


QueueNode* createQueueNode(TreeNode *treeNode) {
    QueueNode *newQueueNode = (QueueNode *)malloc(sizeof(QueueNode));
    if (!newQueueNode) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newQueueNode->treeNode = treeNode;
    newQueueNode->next = NULL;
    return newQueueNode;
}


void initQueue(Queue *queue) {
    queue->front = NULL;
    queue->rear = NULL;
}


int isQueueEmpty(Queue *queue) {
    return queue->front == NULL;
}


void enqueue(Queue *queue, TreeNode *treeNode) {
    QueueNode *newQueueNode = createQueueNode(treeNode);
    if (isQueueEmpty(queue)) {
        queue->front = newQueueNode;
        queue->rear = newQueueNode;
    } else {
        queue->rear->next = newQueueNode;
        queue->rear = newQueueNode;
    }
}


TreeNode* dequeue(Queue *queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }
    QueueNode *temp = queue->front;
    TreeNode *treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

void levelOrderTraversal(TreeNode *root) {
    if (root == NULL) {
        printf("Tree is empty.\n");
        return;
    }
    
    Queue queue;
    initQueue(&queue);
    enqueue(&queue, root);
    
    while (!isQueueEmpty(&queue)) {
        TreeNode *current = dequeue(&queue);
        printf("%d ", current->data);
        
        if (current->left != NULL) {
            enqueue(&queue, current->left);
        }
        if (current->right != NULL) {
            enqueue(&queue, current->right);
        }
    }
    printf("\n");
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
        printf("2. Print Tree (In-order Traversal)\n");
        printf("3. Print Tree (Level-order Traversal)\n");
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
                printf("Level-order traversal: ");
                levelOrderTraversal(root);
                break;
                
            case 4:
                freeTree(root);
                printf("Exiting...\n");
     
            default:
                printf("Invalid choice! Please enter a number between 1 and 4.\n");
                break;
        }
    }
    
    return 0;
}
      
