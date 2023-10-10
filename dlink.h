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
	dlink() { head = nullptr; }
	void add(int num); // used to add all variables into list 
	void insertionSort(ofstream* ptr); // sorts the list using insertion sort
	void selectionSort(ofstream* ptr); // sorts the list using selection sort
	void print(ofstream* ptr);
	//void swap(node* x, node* y);
private: 
	node* head = nullptr;
	int n = 0;
	void swap(node* x, node* y);
	
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

void dlink::swap(node* x, node* y) {
	if (head == nullptr || head->next == nullptr || x == y)
		return;
	if (x == head)
		head = y;
	else if (y == head)
		head = x;


	node* temp;
	temp = x->next;
	x->next = y->next;
	y->next = temp;

	if (x->next != nullptr)
		x->next->prev = x;
	if (y->next != nullptr)
		y->next->prev = y;

	temp = x->prev;
	x->prev = y->prev;
	y->prev = temp;

	if (x->prev != nullptr)
		x->prev->next = x;
	if (y->prev != nullptr)
		y->prev->next = y;
	return;
}

void dlink::insertionSort(ofstream* ptr) {
	node* cu = head; 
	node* comp;

	if (cu == nullptr || cu->next == nullptr)
		return;
	cu = cu->next;
	
	for (int i = 1; i < n; i++) {	
		cu = head;
		for (int j = 0; j < i; j++)
			cu = cu->next;
		comp = cu->prev;
		while ((comp != nullptr) && (comp->num > cu->num)) {
			swap(comp, cu);
			if (cu->prev == nullptr)
				break;
			comp = cu->prev;
		}
		print(ptr);
	}
	return;
}

void dlink::selectionSort(ofstream* ptr) {
	node* cu = head;
	node* min;
	node* i = head;
	while (i->next != nullptr) {
		cu = i;
		min = i;
		while (cu != nullptr) {
			if (min->num >= cu->num) {
				min = cu;
			}
			cu = cu->next;
		} 
		swap(min, i);
		i = min->next;
		print(ptr);
	}


	return;
}

void dlink::print(ofstream* ptr) {
	node* cu = head;
	*ptr << "[" << cu->num;
	cu = cu->next;
	while (cu != nullptr) {
		*ptr << "," << cu->num;
		cu = cu->next;
	}
	*ptr << "]\n";
	return;
}
#endif