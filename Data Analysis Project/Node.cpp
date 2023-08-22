#include "Node.h"

Node::Node(std::string newData) {
    mData = newData;
    this->mpLeft = nullptr;
    this->mpRight = nullptr;
}

// Getter for data
std::string Node::getData() {

    return mData;
}

// Setter for data
void Node::setData(std::string newData) {
    this->mData = newData;
}

// Getter for right pointer
Node*& Node::getRightPtr() {
    return this->mpRight;
}

// Setter for right pointer
void Node::setRightPtr(Node* pNewRightPtr) {
    this->mpRight = pNewRightPtr;
}

// Getter for left pointer
Node*& Node::getLeftPtr() {
    return this->mpLeft;
}

// Setter for left pointer
void Node::setLeftPtr(Node* pNewLeftPtr) {
    this->mpLeft = pNewLeftPtr;
}
