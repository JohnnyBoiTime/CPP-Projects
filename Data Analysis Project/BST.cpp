#include "BST.h"

// Gets the reference of the root
Node*& BST::getRoot() {
    return mpRoot;
}

// Sets the reference of the root
void BST::setRoot(Node*& newMpRoot) {
    this->mpRoot = newMpRoot;
}

// Inserts nodes into the tree
void BST::insert(int newUnits, std::string newData) {
    insert(this->mpRoot, newUnits, newData);
}

// Recursive insert function
void BST::insert(Node*& node, int newUnits, std::string newData) {

    // Dynamic casting from derived class
    TransactionNode* newNode = dynamic_cast<TransactionNode*> (node);

    // Base Case
    if (this->mpRoot == nullptr) {
        mpRoot = new TransactionNode(newData, newUnits);
    }
    // Inserts node to right of tree if unit is greater than current node
    else if (newUnits > newNode->getUnits()) {
        if (node->getRightPtr() == nullptr) {
            node->setRightPtr(new TransactionNode(newData, newUnits));
        }
        else {
            insert(newNode->getRightPtr(), newUnits, newData);
        }
    }
    // Inserts node to left of tree if unit is less than current node
    else if (newUnits < newNode->getUnits()) {
        if (node->getLeftPtr() == nullptr) {
            node->setLeftPtr(new TransactionNode(newData, newUnits));
        }
        else {
            insert(newNode->getLeftPtr(), newUnits, newData);
        }

    }

}

// Finds smallest value in the tree
TransactionNode& BST::findSmallest(Node*& node) {
    // Dynamic casting from derived class
    TransactionNode* newNode = dynamic_cast<TransactionNode*>(node);

    // Goes all the way to the left, as the left has the smallest value
    while (newNode->getLeftPtr() != nullptr) {
        newNode = dynamic_cast<TransactionNode*>(newNode->getLeftPtr());
    }

    return *newNode;

}

TransactionNode& BST::findLargest(Node*& node) {
    // Dynamic casting from derived class
    TransactionNode* newNode = dynamic_cast<TransactionNode*>(node);

    // Goes all the way to the right of the tree to find the largest value
    while (newNode->getRightPtr() != nullptr) {
        newNode = dynamic_cast<TransactionNode*>(newNode->getRightPtr());
    }

    return *newNode;
}

// Traverses tree 
void BST::inOrderTraversal() {
    inOrderTraversal(this->mpRoot);
}

// Searches tree from left to right to find the node than
// prints out data
void BST::inOrderTraversal(Node* node) {

    TransactionNode* newNode = dynamic_cast<TransactionNode*>(node);
    

    // Makes sure tree is not empty
    if (node != nullptr) {
        inOrderTraversal(node->getLeftPtr());
        newNode->printData();
        inOrderTraversal(node->getRightPtr());
    }
}

// Deletes tree from left to right
void BST::destroyTree(Node* node) {

    if (node != nullptr) {
        destroyTree(node->getLeftPtr());
        destroyTree(node->getRightPtr());
        delete node;
    }
}