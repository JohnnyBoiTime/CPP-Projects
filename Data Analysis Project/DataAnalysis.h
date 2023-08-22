#include "BST.h"

// Class for data analysis
class DataAnalysis {
private:
	BST mTreeSold;
	BST mTreePurchased;
	std::ifstream mCsvStream;
	void openFile();
	void readFile();
	int split();
	void compareTransactions(int units, std::string type, std::string transaction);
	void printTrends();
public:
	DataAnalysis() {}
	~DataAnalysis() {}
	void runAnalysis();
};