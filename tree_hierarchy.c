
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[30];
    struct Node *children[8];
    int childCount;
} Node;

Node *createNode(char name[]) {
    Node *node = malloc(sizeof(Node));

    if (node == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    strcpy(node->name, name);
    node->childCount = 0;
    return node;
}

void addChild(Node *parent, Node *child) {
    parent->children[parent->childCount++] = child;
}

void displayTree(Node *root, int level) {
    for (int i = 0; i < level; i++)
        printf("  ");

    printf("%s\n", root->name);

    for (int i = 0; i < root->childCount; i++)
        displayTree(root->children[i], level + 1);
}

void levelOrder(Node *root) {
    Node *queue[20];
    int front = 0, rear = 0;

    queue[rear++] = root;

    printf("Level-order traversal: ");

    while (front < rear) {
        Node *current = queue[front++];
        printf("%s ", current->name);

        for (int i = 0; i < current->childCount; i++)
            queue[rear++] = current->children[i];
    }

    printf("\n");
}

void freeTree(Node *root) {
    for (int i = 0; i < root->childCount; i++)
        freeTree(root->children[i]);

    free(root);
}

int main(void) {
    Node *ceo = createNode("CEO");
    Node *hr = createNode("HR");
    Node *finance = createNode("Finance");
    Node *it = createNode("IT");
    Node *dev = createNode("Development");
    Node *testing = createNode("Testing");
    Node *frontend = createNode("Frontend");
    Node *backend = createNode("Backend");

    addChild(ceo, hr);
    addChild(ceo, finance);
    addChild(ceo, it);

    addChild(it, dev);
    addChild(it, testing);

    addChild(dev, frontend);
    addChild(dev, backend);

    printf("Organisational Hierarchy:\n");
    displayTree(ceo, 0);
    levelOrder(ceo);

    freeTree(ceo);
    return 0;
}
