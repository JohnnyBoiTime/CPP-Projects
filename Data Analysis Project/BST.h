#include "TransactionNode.h"

// BST Class
class BST {
    // Private variable/functions
private:
    Node* mpRoot;
    void destroyTree(Node* node);
    void insert(Node*& node, int newUnits, std::string newData);
    void inOrderTraversal(Node* node);
    // Public variable/functions 
public:
    BST() {
        mpRoot = nullptr;
    }
    ~BST() {
        destroyTree(mpRoot);
    }
    Node*& getRoot();
    void setRoot(Node*& newMpRoot);
    void insert(int newUnits, std::string newData);
    TransactionNode& findSmallest(Node*& node);
    TransactionNode& findLargest(Node*& node);
    void inOrderTraversal();
};