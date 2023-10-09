#include <iostream>
#include <fstream>
#include "dlink.h"
#include "ArgumentManager.h"

using namespace std;

void insertionSort(dlink list) {

	return;
}

void selectionSort(dlink list) {

	return;
}


int main(int argc, char* argv[]) {

	ArgumentManager am(argc, argv);
	ifstream input(am.get("input"));
	ofstream output(am.get("output"));


	ifstream input("input1.txt");
	ofstream output("output1.txt");


	dlink list;
	string line;
	while (getline(input, line, ' ')) {
		list.add


	}



	if (line == "insertion") {
		insertionSort(list);
	}
	else if (line == "selection") {
		selectionSort(list);
	}


	return 0;
}