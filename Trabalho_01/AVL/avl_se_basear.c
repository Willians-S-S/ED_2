#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore AVL
struct Node {
    int data;
    int height;
    struct Node* left;
    struct Node* right;
};

// Função para calcular a altura de um nó
int getHeight(struct Node* node) {
    if (node == NULL)
        return -1;
    return node->height;
}

// Função para calcular o fator de balanceamento de um nó
int getBalanceFactor(struct Node* node) {
    if (node == NULL)
        return 0;
    return getHeight(node->left) - getHeight(node->right);
}

// Função para atualizar a altura de um nó
void updateHeight(struct Node* node) {
    int leftHeight = getHeight(node->left);
    int rightHeight = getHeight(node->right);
    node->height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Função para realizar uma rotação simples à esquerda
struct Node* rotateLeft(struct Node* node) {
    struct Node* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->left = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Função para realizar uma rotação simples à direita
struct Node* rotateRight(struct Node* node) {
    struct Node* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    updateHeight(node);
    updateHeight(newRoot);
    return newRoot;
}

// Função para balancear a árvore AVL após a inserção
struct Node* balance(struct Node* node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (getBalanceFactor(node->left) < 0)
            node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balanceFactor < -1) {
        if (getBalanceFactor(node->right) > 0)
            node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

// Função para inserir um valor em uma árvore AVL
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->height = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return balance(root);
}

// Função para imprimir a árvore em ordem
void inOrder(struct Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("Valor %d : Altura %d\n", node->data, node->height);

        inOrder(node->right);
    }
}

// Função principal
int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    printf("Árvore AVL em ordem: ");
    inOrder(root);
    printf("\n");

    return 0;
}
