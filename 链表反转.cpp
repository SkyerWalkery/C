#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <cstring>
using namespace std;

struct Node {
	int data;
	Node* next;
};

void Print(Node* head);
Node* CreatList(int num_node);
Node* Reverse(Node* head);


int main() {
	int num_node;
	cin >> num_node;
	Node* head = CreatList(num_node);
	Print(head);
	cout << endl;
	head = Reverse(head);
	Print(head);
 	cin.get();
	return 0;
 }


void Print(Node* head) {
	while (head) {
		cout << head->data<<" ";
		head = head->next;
	}
}


Node* CreatList(int num_node) {
	Node* head = NULL, * tail = head;
	for (int i = 1; i <= num_node; i++) {
		Node* p = new Node;
		p->data = i;
		p->next = NULL;
		if (!head) head = p;
		else tail->next = p;
		tail = p;
	}
	return head;
}


Node* Reverse(Node* head) {
	if (!head || !(head->next)) return head;
	else {
		Node* p1 = head, * p2 = head->next, * p3 = head->next->next;
		p1->next = 0;
		while (p3) {
			p2->next = p1;
			p1 = p2, p2 = p3, p3 = p3->next;
		}
		p2->next = p1;
		return p2;
	}
}


