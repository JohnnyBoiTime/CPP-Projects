#include "DataAnalysis.h"


// Opens file
void DataAnalysis::openFile() {
	mCsvStream.open("data.csv");
	readFile();
}

// Reads file
void DataAnalysis::readFile() {

	std::string line = "";

	std::getline(mCsvStream, line, '\n'); // Skips first line

	// Loops through file 
	while (!mCsvStream.eof()) {
		split();
		if (split() == 1) { // If end of file,  returns 1 and stops reading file
			break;
		}
	}
}

// Splits file
int DataAnalysis::split() {
	
	int units = 0;
	int done = 0;
	std::string line = "";
	std::string type = "";
	std::string transaction = "";

	std::getline(mCsvStream, line, ','); // Gets the units
	if (line == "") {
		done = 1;
		return done;
	}
	units = stoi(line);
	std::getline(mCsvStream, type, ','); // Gets the type
	std::getline(mCsvStream, transaction, '\n'); // Gets the transaction

	// Compares fields
	compareTransactions(units, type, transaction);
	
	return done;
}

// Sorts transactions
void DataAnalysis::compareTransactions(int units, std::string type, std::string transaction) {
	if (transaction == "Purchased") {
		mTreePurchased.insert(units, type);
	}
	if (transaction == "Sold") {
		mTreeSold.insert(units, type);
	}

}

// Prints trends
void DataAnalysis::printTrends() {

	// Creates transaction node objects and finds the smalles and largest of the respective trees
	TransactionNode smallestPurchase = mTreePurchased.findSmallest(mTreePurchased.getRoot());
	TransactionNode largestPurchase = mTreePurchased.findLargest(mTreePurchased.getRoot());
	TransactionNode smallestSold = mTreeSold.findSmallest(mTreeSold.getRoot());
	TransactionNode largestSold = mTreeSold.findLargest(mTreeSold.getRoot());


	// Prints out data
	std::cout << "PURCHASED: \n\n";
	std::cout << "Least Purchased: " << smallestPurchase.getData() << " " << smallestPurchase.getUnits() << "\n";
	std::cout << "Most Purchased " << largestPurchase.getData() << " " << largestPurchase.getUnits() << "\n\n";
	std::cout << "SOLD: \n\n";
	std::cout << "Least Sold: " << smallestSold.getData() << " " << smallestSold.getUnits() << "\n";
	std::cout << "Most Sold: " << largestSold.getData() << " " << largestSold.getUnits() << "\n";
}

// Runs analysiss
void DataAnalysis::runAnalysis() {

	openFile();
	std::cout << "Curent contents of purchased tree: \n";
	mTreePurchased.inOrderTraversal();

	std::cout << "\n";

	std::cout << "Current contents of sold: \n";
	mTreeSold.inOrderTraversal();
	std::cout << "\n";
	printTrends();

}
