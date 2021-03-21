#include <iostream>
//#include <iomanip>
#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <cstring>
//#include <algorithm>
using namespace std;


struct Node {
	int coef;//系数
	int index;//指数
	Node* next;
};//链表中，按指数降序排列

struct Polynomial {
	Node* phead;
};


int GetNum(const char* begin, const char* end);//将字符串转为int型数据
void Insert(Node* &head, Node* &p);
Polynomial InitPolynomial(const char* str);
Polynomial Add(const Polynomial &pa, const Polynomial &pb);
Polynomial Minus(const Polynomial &pa, const Polynomial &pb);
Polynomial Multiply(const Polynomial &pa, const Polynomial &pb);
Polynomial Power(const Polynomial &pa, int index);
void PrintPolynomial(const Polynomial &poly);
void RmZero(Node *&head);
void Deletion(Node *&head);


int main() {
	const int nMaxLen = 200;
	char str1[nMaxLen], str2[nMaxLen], str3[nMaxLen], str4[nMaxLen];
	cin>> str1 >> str2 >> str3 >> str4;

	Polynomial poly1 = InitPolynomial(str1);
	Polynomial poly2 = InitPolynomial(str2);
	Polynomial poly3 = InitPolynomial(str3);
	Polynomial poly4 = InitPolynomial(str4);

	PrintPolynomial(poly1);
	PrintPolynomial(poly2);
	PrintPolynomial(poly3);
	PrintPolynomial(poly4);

	PrintPolynomial(Add(poly1, poly2));
	PrintPolynomial(Minus(poly2, poly1));
	PrintPolynomial(Add(poly1, poly1));
	PrintPolynomial(Minus(poly1, poly1));

	/*PrintPolynomial(Multiply(poly1, poly1));
	PrintPolynomial(Power(poly1, 2));
	PrintPolynomial(Power(poly2, 4));
	PrintPolynomial(Multiply(poly2, poly3));
	PrintPolynomial(Power(poly4, 6));
	

	return 0;
}


int GetNum(const char* begin, const char* end) {
	int num = 0;
	int i = 1;
	char* p = (char*)end;
	while (p != begin) {
		num += (*p - '0') * i;
		i *= 10;
		p--;
	}
	num += (*p - '0') * i;
	return num;
}


void Insert(Node* &head, Node* &p) {
	Node *cur = head, *pre = head;

	while(cur){
		if(cur->index == p->index){
			cur->coef += p->coef;
			return;
		}
		cur = cur->next;
	}//已有同类项

	cur = head;
	if(p->index > head->index){
		p->next = head;
		head = p;
	}
	else{
		while(cur){
			if(p->index>cur->index)
				break;
			pre = cur;
			cur = cur->next;
		}
		p->next = pre->next;
		pre->next = p;
	}//插入排序
}


Polynomial InitPolynomial(const char* str) {
	Polynomial poly;
	poly.phead = NULL;
	char* p = (char*)str;

	while (*p != '\0') {
		int flag;
		if (*p == '+') flag = 1;
		else if (*p == '-') flag = -1;
		p++;

		char* cbegin = p;//系数开头
		for (; *p != 'x'; p++);
		char* cend = p - 1;//系数结尾
		int coef = GetNum(cbegin, cend) * flag;

		p += 2;
		char* ibegin = p;//指数开头
		for (; *p != '-' && *p != '+' && *p != '\0'; p++);
		char* iend = p - 1;//指数结尾
		int index = GetNum(ibegin, iend);

		Node* pnode = new Node;
		pnode->coef = coef, pnode->index = index, pnode->next = NULL;
		if (poly.phead == NULL) {
			poly.phead = pnode;
		}
		else {
			Insert(poly.phead, pnode);
			//RmZero(poly.phead);
		}//将数据存入链表并合并同类项
	}

	return poly;
}


Polynomial Add(const Polynomial &pa, const Polynomial &pb){
	Polynomial res;
	res.phead = NULL;
	Node *ppa = pa.phead, *ppb = pb.phead;

	while(ppa){
		Node *ptemp = new Node;
		ptemp->coef = ppa->coef, ptemp->index = ppa->index, ptemp->next = NULL;
		if(res.phead == NULL)
			res.phead = ptemp;
		else{
			Insert(res.phead, ptemp);
			//RmZero(res.phead);
		}
		ppa = ppa->next;
	}

	while(ppb){
		Node *ptemp = new Node;
		ptemp->coef = ppb->coef, ptemp->index = ppb->index, ptemp->next = NULL;
		if(res.phead == NULL)
			res.phead = ptemp;
		else{
			Insert(res.phead, ptemp);
			//RmZero(res.phead);
		}
		ppb = ppb->next;
	}

	return res;
}


Polynomial Minus(const Polynomial &pa, const Polynomial &pb){
	Polynomial res;
	res.phead = NULL;
	Node *ppa = pa.phead, *ppb = pb.phead;

	while(ppa){
		Node *ptemp = new Node;
		ptemp->coef = ppa->coef, ptemp->index = ppa->index, ptemp->next = NULL;
		if(res.phead == NULL)
			res.phead = ptemp;
		else{
			Insert(res.phead, ptemp);
			//RmZero(res.phead);
		}
		ppa = ppa->next;
	}

	while(ppb){
		Node *ptemp = new Node;
		ptemp->coef = ppb->coef * (-1), ptemp->index = ppb->index, ptemp->next = NULL;
		if(res.phead == NULL)
			res.phead = ptemp;
		else{
			Insert(res.phead, ptemp);
			//RmZero(res.phead);
		}
		ppb = ppb->next;
	}

	return res;
}


Polynomial Multiply(const Polynomial &pa, const Polynomial &pb){
	Polynomial res;
	res.phead = NULL;
	Node *ppa = pa.phead, *ppb = pb.phead;

	if(!ppa || !ppb)
		return res;//其中有多项式为0的情况

	while(ppa){
		while(ppb){
			Node *ptemp = new Node;
			ptemp->coef = ppa->coef * ppb->coef, ptemp->index = ppa->index + ppb->index;
			ptemp->next = NULL;
			if(res.phead == NULL)
				res.phead = ptemp;
			else{
				Insert(res.phead, ptemp);
				//RmZero(res.phead);
			}
			ppb = ppb->next;
		}
		ppa = ppa->next;
		ppb = pb.phead;//初始化以再次遍历
	}

	return res;
}


Polynomial Power(const Polynomial &pa, int index){
	Polynomial res;
	Node *head = new Node;
	head->coef = 1, head->index = 0, head->next = NULL;
	res.phead = head;

	for (int i = 0; i < index;i++){
		Polynomial temp = Multiply(pa, res);
		Deletion(res.phead);
		res = temp;
	}

		return res;
}


void PrintPolynomial(const Polynomial &poly){
	Node *p = poly.phead;
	while(p){
		if(p->coef!=0){
			if(p->coef>0)
				cout << "+";
		cout << p->coef << "x^" << p->index;
		}
		p = p->next;
	}
	cout << endl;
}


void RmZero(Node* &head){
	while(head && head->coef==0){
		Node *cur = head;
		head = head->next;
		delete cur;
	}
	
	if(!head)
		return;

	Node *pre = head, *cur = head->next;
	while(cur){
		if(cur->coef==0){
			pre->next = cur->next;
			delete cur;
			cur = pre->next;
			continue;
		}
		pre = cur;
		cur = cur->next;
	}
}


void Deletion(Node* &head){
	while(head){
		Node *p = head;
		head = head->next;
		delete p;
	}
}