#include <iostream>
#include <string>
#include <fstream>

// Class for node
class Node {

    // Protected member variables
protected:
    std::string mData;
    Node* mpLeft;
    Node* mpRight;

    // Public member functions
public:
    virtual ~Node() {}
    Node(std::string newData);
    std::string getData();
    void setData(std::string newData);
    Node*& getRightPtr();
    void setRightPtr(Node* pNewRightPtr);
    Node*& getLeftPtr();
    void setLeftPtr(Node* pNewLeftPtr);
    virtual void printData() = 0;
};