#include <iostream>
#include <fstream>
#include "dlink.h"
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[]) {

	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));


	/*ifstream input("input3.txt");
	ofstream output("output.txt");*/

	dlink list;
	string line;
	getline(input, line);
	stringstream ss(line);
	int num;
	while (ss >> num) {
		list.add(num);
	}
	getline(input, line);
	if (line == "Insertion") {
		list.insertionSort();
	}
	else if (line == "Selection") {
		list.selectionSort();
	}
	ofstream* ptr = &output;
	list.print(ptr);

	input.close();
	output.close();


	return 0;
}