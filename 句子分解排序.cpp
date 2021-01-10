#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <string>
#include <cstring>
using namespace std;

/*
输入一个英文句子，识别句子中的不同单词，并按字母顺序输出。 
注意：拼写相同大小写不同的单词应视为相同的单词，输出统一为小写的单词。要求使用链表存储输入和输出的单词。
*/

struct Node {
	char word[12];
	Node* next;
};

void Iden(char sent[]);
void Print(Node* head);
void Sort(Node*& head);
void Insert(Node** head, Node* p);


int main() {
	char sent[64] = "\0";
	cin.getline(sent, 50);
	Iden(sent);
	cin.get();
	return 0;
 }


void Iden(char sent[]) {
	for (int i = 0; sent[i] != '\0'; i++) {
		if (sent[i] >= 'A' && sent[i] <= 'Z')
			sent[i] = sent[i] + 'a' - 'A';
	}

	Node* head = NULL, * tail = NULL;
	int index1 = 0, index2 = 0;

	while (sent[index2] != '\0') {
		if (sent[index2] == ' ') {
			Node* p = new Node;
			int i = index1;
			for (; i < index2; i++) {
				p->word[i - index1] = sent[i];
			}
			p->word[i - index1] = '\0';
			p->next = NULL;
			if (!head) head = p;
			else tail->next = p;
			tail = p;
			index1 = (++index2);
		}
		else index2++;
	}

	Sort(head);
	Print(head);
}


void Print(Node* head) {
	while (head) {
		cout << head->word<<" ";
		head = head->next;
	}
}


void Sort(Node*& head) {
	if (head == NULL || head->next == NULL) return;
	Node* cur = head->next;
	head->next = NULL;
	while (cur) {
		Node* prev = cur;
		cur = cur->next;
		Insert(&head,prev);
	}
}


void Insert(Node** head,Node* p) {
	if (strcmp(p->word, (*head)->word) < 0) {
		p->next = (*head);
		(*head) = p;
	}
	else {
		Node* p1 = *head, * p2 = *head;
		while (p1 && strcmp(p->word, p1->word) >= 0) {
			p2 = p1;
			p1 = p1->next;
		}
		p->next = p1;
		p2->next = p;
	}
}


