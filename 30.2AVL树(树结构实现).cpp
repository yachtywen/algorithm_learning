#include <iostream>
#include <algorithm>
using namespace std;

// 节点结构：包含键、值、高度、左右子节点
struct Node {
    int key;
    string value; // 存放数据，便于演示“修改”
    int height;
    Node* left;
    Node* right;

    Node(int k, string v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

class AVLTree {
private:
    Node* root;

    int getHeight(Node* n) {
        if (n == nullptr) return 0;
        return n->height;
    }

    int getBalance(Node* n) {
        if (n == nullptr) return 0;
        return getHeight(n->left) - getHeight(n->right);
    }

    // 右旋
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

        return x;
    }

    // 左旋
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
        y->height = max(getHeight(y->left), getHeight(y->right)) + 1;

        return y;
    }

    // 插入节点 (Create)
    Node* insertNode(Node* node, int key, string value) {
        if (node == nullptr) return new Node(key, value);

        if (key < node->key)
            node->left = insertNode(node->left, key, value);
        else if (key > node->key)
            node->right = insertNode(node->right, key, value);
        else {
            node->value = value; // 如果key已存在，则更新值
            return node;
        }

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        // LL Case
        if (balance > 1 && key < node->left->key)
            return rightRotate(node);
        // RR Case
        if (balance < -1 && key > node->right->key)
            return leftRotate(node);
        // LR Case
        if (balance > 1 && key > node->left->key) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        // RL Case
        if (balance < -1 && key < node->right->key) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr)
            current = current->left;
        return current;
    }

    // 删除节点 (Delete)
    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;

        if (key < root->key)
            root->left = deleteNode(root->left, key);
        else if (key > root->key)
            root->right = deleteNode(root->right, key);
        else {
            if ((root->left == nullptr) || (root->right == nullptr)) {
                Node* temp = root->left ? root->left : root->right;
                if (temp == nullptr) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }
                delete temp;
            }
            else {
                Node* temp = minValueNode(root->right);
                root->key = temp->key;
                root->value = temp->value;
                root->right = deleteNode(root->right, temp->key);
            }
        }

        if (root == nullptr) return root;

        root->height = 1 + max(getHeight(root->left), getHeight(root->right));
        int balance = getBalance(root);

        if (balance > 1 && getBalance(root->left) >= 0)
            return rightRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && getBalance(root->right) <= 0)
            return leftRotate(root);
        if (balance < -1 && getBalance(root->right) > 0) {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }

        return root;
    }

    // 查找节点 (Read)
    Node* searchNode(Node* root, int key) {
        if (root == nullptr || root->key == key)
            return root;
        if (key < root->key)
            return searchNode(root->left, key);
        return searchNode(root->right, key);
    }

    // 中序遍历
    void inOrder(Node* root) {
        if (root != nullptr) {
            inOrder(root->left);
            cout << "Key: " << root->key << ", Value: " << root->value << ", H: " << root->height << endl;
            inOrder(root->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    // 增
    void insert(int key, string value) {
        root = insertNode(root, key, value);
    }
    // 删
    void remove(int key) {
        root = deleteNode(root, key);
    }
    // 查
    string search(int key) {
        Node* res = searchNode(root, key);
        return res ? res->value : "Not Found";
    }
    // 改
    bool modify(int key, string newValue) {
        Node* res = searchNode(root, key);
        if (res) {
            res->value = newValue;
            return true;
        }
        return false;
    }
    // 打印
    void display() {
        inOrder(root);
        cout << "----------------" << endl;
    }
};

int main() {
    AVLTree tree;

    // 1. Create (增)
    cout << "## Insert Data" << endl;
    tree.insert(10, "Ten");
    tree.insert(20, "Twenty");
    tree.insert(30, "Thirty"); // 触发旋转
    tree.insert(40, "Forty");
    tree.insert(50, "Fifty");
    tree.insert(25, "Twenty-Five");
    tree.display();

    // 2. Read (查)
    cout << "## Search Key 25: " << tree.search(25) << endl;
    cout << "## Search Key 99: " << tree.search(99) << endl;

    // 3. Update (改)
    cout << "## Modify Key 10 to 'Updated Ten'" << endl;
    tree.modify(10, "Updated Ten");
    cout << "Result: " << tree.search(10) << endl;

    // 4. Delete (删)
    cout << "## Delete Key 30 (Root or internal node)" << endl;
    tree.remove(30);
    tree.display();

    return 0;
}