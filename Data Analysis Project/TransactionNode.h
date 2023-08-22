#include "Node.h"

// TransactionNode classs
class TransactionNode : public Node {
private:
	int mUnits;
public:
	~TransactionNode() {}
	TransactionNode(std::string newData = "", int newUnits = 0);
	int getUnits();
	void setUnits(int newUnits);
	void printData();
};