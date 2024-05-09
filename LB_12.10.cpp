#include <iostream>
#include <cstdlib> // для генерації випадкових чисел

using namespace std;

// Структура вузла бінарного дерева
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Функція для створення нового вузла
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// Функція для додавання вузла до бінарного дерева
void insertNode(Node*& root, int value) {
    if (root == nullptr) {
        root = createNode(value);
    }
    else {
        if (value < root->data) {
            insertNode(root->left, value);
        }
        else {
            insertNode(root->right, value);
        }
    }
}

// Функція для генерації випадкового числа
int randomNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Функція для побудови дерева з випадковими значеннями та випадковою кількістю нащадків
Node* buildRandomTree(int numNodes) {
    Node* root = nullptr;
    for (int i = 0; i < numNodes; ++i) {
        int value = randomNum(1, 100); // генеруємо випадкове значення для вузла
        insertNode(root, value);
        int numChildren = randomNum(0, 3); // генеруємо випадкову кількість нащадків (від 0 до 3)
        for (int j = 0; j < numChildren; ++j) {
            int childValue = randomNum(1, 100); // генеруємо випадкове значення для нащадка
            insertNode(root, childValue);
        }
    }
    return root;
}

// Функція для обчислення кількості вузлів у дереві
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Функція для виведення значень вузлів дерева
void printTreeValues(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTreeValues(root->left);
    cout << root->data << " ";
    printTreeValues(root->right);
}

int main() {
    srand(time(nullptr)); // Ініціалізуємо генератор випадкових чисел від поточного часу

    Node* root = nullptr;

    // Побудова дерева з 10 випадкових вузлів
    root = buildRandomTree(10);

    // Виведення значень вузлів дерева
    cout << "Values of tree nodes: ";
    printTreeValues(root);
    cout << endl;

    // Обчислення кількості вузлів у дереві
    int numNodes = countNodes(root);
    cout << "Number of nodes in the tree: " << numNodes << endl;

    // Видалення дерева для уникнення витоку пам'яті (не обов'язково)
    // Для цього можна використати функцію deleteTree(root), яку вам потрібно написати

    return 0;
}
