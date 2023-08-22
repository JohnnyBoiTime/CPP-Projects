#include "TransactionNode.h"

// TransactionNode constructor
TransactionNode::TransactionNode(std::string newData, int newUnits) : Node(newData) {
	this->mUnits = newUnits;

}

// Gets units 
int TransactionNode::getUnits() {
	return mUnits;
}

// Sets units
void TransactionNode::setUnits(int newUnits) {
	mUnits = newUnits;
}

// Prints data
void TransactionNode::printData() {

	std::cout << this->mData << ": " << this->mUnits << "\n";

}