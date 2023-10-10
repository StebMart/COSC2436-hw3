#ifndef DLINK_H
#define DLINK_H

#include <iostream>

using namespace std;

struct node {
	int num;
	node* prev = nullptr;
	node* next = nullptr;
};

class dlink {
public:
	dlink() { head == nullptr; }
	void add(int num); // used to add all variables into list 
	void insertionSort(); // sorts the list using insertion sort
	void selectionSort(); // sorts the list using selection sort
	void print(/*ofstream* output*/);
private: 
	node* head = nullptr;
	int n = 0;
};

void dlink::add(int num) {
	node* cu = head;
	node* temp = new node;
	temp->num = num;
	n++;
	if (head == nullptr) {
		head = temp;
		return;
	}
	while (cu->next != nullptr)
		cu = cu->next;
	temp->prev = cu;
	cu->next = temp;
	return;
}

void dlink::insertionSort() {
	node* cu = head; 
	node* comp;
	node* key;

	if (cu == nullptr || cu->next == nullptr)
		return;
	cu = cu->next;
	
	while (cu != nullptr) {	
		print();
		cout << "cu is: " << cu->num << endl;
		comp = cu->prev;
		cout << comp->num << " " << cu->num << endl;
		while ((comp != nullptr) && (comp->num > cu->num)) {
			cout << "hey";
			comp->next = comp;
			if (comp->prev == nullptr)
				break;
			comp = comp->prev;
		}
		comp->next = cu;
		cu = cu->next;
	}
	return;
}

void dlink::selectionSort() {


	return;
}

void dlink::print(/*ofstream* output*/) {
	node* cu = head;
	while (cu != nullptr) {
		cout << cu->num << " ";
		cu = cu->next;
	}
	return;
}
#endif