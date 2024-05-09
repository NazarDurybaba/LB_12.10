#include <iostream>
#include <cstdlib> // ��� ��������� ���������� �����

using namespace std;

// ��������� ����� �������� ������
struct Node {
    int data;
    Node* left;
    Node* right;
};

// ������� ��� ��������� ������ �����
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

// ������� ��� ��������� ����� �� �������� ������
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

// ������� ��� ��������� ����������� �����
int randomNum(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// ������� ��� �������� ������ � ����������� ���������� �� ���������� ������� �������
Node* buildRandomTree(int numNodes) {
    Node* root = nullptr;
    for (int i = 0; i < numNodes; ++i) {
        int value = randomNum(1, 100); // �������� ��������� �������� ��� �����
        insertNode(root, value);
        int numChildren = randomNum(0, 3); // �������� ��������� ������� ������� (�� 0 �� 3)
        for (int j = 0; j < numChildren; ++j) {
            int childValue = randomNum(1, 100); // �������� ��������� �������� ��� �������
            insertNode(root, childValue);
        }
    }
    return root;
}

// ������� ��� ���������� ������� ����� � �����
int countNodes(Node* root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// ������� ��� ��������� ������� ����� ������
void printTreeValues(Node* root) {
    if (root == nullptr) {
        return;
    }
    printTreeValues(root->left);
    cout << root->data << " ";
    printTreeValues(root->right);
}

int main() {
    srand(time(nullptr)); // ���������� ��������� ���������� ����� �� ��������� ����

    Node* root = nullptr;

    // �������� ������ � 10 ���������� �����
    root = buildRandomTree(10);

    // ��������� ������� ����� ������
    cout << "Values of tree nodes: ";
    printTreeValues(root);
    cout << endl;

    // ���������� ������� ����� � �����
    int numNodes = countNodes(root);
    cout << "Number of nodes in the tree: " << numNodes << endl;

    // ��������� ������ ��� ��������� ������ ���'�� (�� ����'������)
    // ��� ����� ����� ����������� ������� deleteTree(root), ��� ��� ������� ��������

    return 0;
}
