#include <iostream>
using namespace std;

int main() {
    int a;

    cin >> a;

    for(int i=0; i<a; ++i) {
        a++;
    }

    // 紅黑樹節點結構
    struct Node {
        int data;
        bool isRed;
        Node* left;
        Node* right;
        Node* parent;
        
        Node(int val) : data(val), isRed(true), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    // 紅黑樹類
    class RedBlackTree {
    private:
        Node* root;

        // 左旋操作
        void leftRotate(Node* x) {
            Node* y = x->right;
            x->right = y->left;
            if (y->left != nullptr)
                y->left->parent = x;
            y->parent = x->parent;
            if (x->parent == nullptr)
                root = y;
            else if (x == x->parent->left)
                x->parent->left = y;
            else
                x->parent->right = y;
            y->left = x;
            x->parent = y;
        }

        // 右旋操作
        void rightRotate(Node* y) {
            Node* x = y->left;
            y->left = x->right;
            if (x->right != nullptr)
                x->right->parent = y;
            x->parent = y->parent;
            if (y->parent == nullptr)
                root = x;
            else if (y == y->parent->right)
                y->parent->right = x;
            else
                y->parent->left = x;
            x->right = y;
            y->parent = x;
        }

        // 插入修復
        void insertFixup(Node* z) {
            while (z->parent != nullptr && z->parent->isRed) {
                if (z->parent == z->parent->parent->left) {
                    Node* y = z->parent->parent->right;
                    if (y != nullptr && y->isRed) {
                        z->parent->isRed = false;
                        y->isRed = false;
                        z->parent->parent->isRed = true;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->right) {
                            z = z->parent;
                            leftRotate(z);
                        }
                        z->parent->isRed = false;
                        z->parent->parent->isRed = true;
                        rightRotate(z->parent->parent);
                    }
                } else {
                    Node* y = z->parent->parent->left;
                    if (y != nullptr && y->isRed) {
                        z->parent->isRed = false;
                        y->isRed = false;
                        z->parent->parent->isRed = true;
                        z = z->parent->parent;
                    } else {
                        if (z == z->parent->left) {
                            z = z->parent;
                            rightRotate(z);
                        }
                        z->parent->isRed = false;
                        z->parent->parent->isRed = true;
                        leftRotate(z->parent->parent);
                    }
                }
            }
            root->isRed = false;
        }

    public:
        RedBlackTree() : root(nullptr) {}

        // 插入操作
        void insert(int val) {
            Node* z = new Node(val);
            Node* y = nullptr;
            Node* x = root;

            while (x != nullptr) {
                y = x;
                if (z->data < x->data)
                    x = x->left;
                else
                    x = x->right;
            }

            z->parent = y;
            if (y == nullptr)
                root = z;
            else if (z->data < y->data)
                y->left = z;
            else
                y->right = z;

            insertFixup(z);
        }

        // 中序遍歷（用於測試）
        void inorderTraversal(Node* node) {
            if (node != nullptr) {
                inorderTraversal(node->left);
                cout << node->data << " ";
                inorderTraversal(node->right);
            }
        }

        void printTree() {
            cout << "紅黑樹中序遍歷：";
            inorderTraversal(root);
            cout << endl;
        }
    };

    // 測試紅黑樹
    RedBlackTree rbt;
    rbt.insert(7);
    rbt.insert(3);
    rbt.insert(18);
    rbt.insert(10);
    rbt.insert(22);
    rbt.insert(8);
    rbt.insert(11);
    rbt.printTree();

    cout << "原始值 a = " << a << endl;
}