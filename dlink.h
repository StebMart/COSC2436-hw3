#ifndef DLINK_H
#define DLINK_H

struct node {
	int num;
	node* prev = nullptr;
	node* next = nullptr;
};

class dlink {
public:
	dlink() { head == nullptr; }
	void add(int num);
private: 
	node* head = nullptr;
};

void dlink::add(int num) {
	node* cu = head;
	node* temp = new node;
	temp->num = num;
	if (head == nullptr) {
		head = temp;
		return;
	}
	while (cu->next != nullptr)
		cu = cu->next;
	temp->prev = cu;
	cu->next = temp;
	   
	

}

#endif