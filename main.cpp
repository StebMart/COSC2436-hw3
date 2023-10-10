#include <iostream>
#include <fstream>
#include "dlink.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[]) {

	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));


	/*ifstream input("input1.txt");
	ofstream output("output.txt");*/

	dlink list;
	string line;
	getline(input, line);
	stringstream ss(line);
	int num;
	ofstream* ptr = &output;

	while (ss >> num) {
		list.add(num);
	}
	getline(input, line);
	if (line == "Insertion") {
		list.insertionSort(ptr);
	}
	else if (line == "Selection") {
		list.selectionSort(ptr);
	}
	else {
		output << "Input is invalid.";
	}

	input.close();
	output.close();


	return 0;
}