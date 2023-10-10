#include <iostream>
#include <fstream>
#include "dlink.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[]) {

	/*ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));*/


	ifstream input("input3.txt");
	ofstream output("output1.txt");

	dlink list;
	string line;
	getline(input, line);
	stringstream ss(line);
	int num;
	while (ss >> num) {
		list.add(num);
	}
	getline(input, line);
	list.print();
	cout << endl;
	if (line == "Insertion") {
		cout << "using insertion sort..." << endl;
		list.insertionSort();
	}
	else if (line == "Selection") {
		cout << "using selection sort..." << endl;
		list.selectionSort();
	}
	cout << "The final results are: " << endl;
	list.print(/*&output*/);

	input.close();
	output.close();


	return 0;
}