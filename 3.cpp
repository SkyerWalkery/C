#include <iostream>
//#include <iomanip>
//#include <cstdio>
//#include <cmath>
//#include <cstdlib>
//#include <ctime>
//#include <string>
#include <cstring>
//#include <algorithm>
//#include <assert.h>
using namespace std;

class Number {
	int inte[100];
	int deci[100];
	int len_inte, len_deci;
public:
	Number() {
		for (int i = 0; i < 100; i++) {
			inte[i] = 0;//�������ֵ�����
			deci[i] = 0;//С�����ֵ�����
		}
		len_inte = 0, len_deci = 0;
	}

	void GetNum();
	Number operator+ (const Number& other) const;
	void Display();
};

int main() {
	int num_case;
	cin >> num_case;
	for (int i = 1; i <= num_case; i++) {
		Number num1, num2, num3;
		num1.GetNum();
		num2.GetNum();
		num3 = num1 + num2;
		num3.Display();
		cout << endl;
	}

	return 0;
}


void Number::GetNum() {
	char numstr[103] = "\0";
	cin >> numstr;
	char* phead = numstr, *pdot = numstr, *ptail = NULL;
	for (; *pdot != '.' && *pdot!='\0'; pdot++, len_inte++);//ע���������������
	for (ptail = pdot + 1; *ptail != '\0'; ptail++, len_deci++);//��λ�ָ�
	ptail--;//��ptailָ��������������'\0'

	while (*ptail == '0') {
		*ptail = '\0';
		ptail--;
		len_deci--;
	}//��ȥĩβ�����0

	char* ptemp = pdot - 1;
	for (int i = 0; i < len_inte; i++) {
		inte[i] = *ptemp-'0';
		ptemp--;
	}
	ptemp = pdot + 1;
	for (int i = 0; i < len_deci; i++) {
		deci[i] = *ptemp-'0';
		ptemp++;
	}
}


Number Number::operator+ (const Number& other) const {
	Number temp;
	temp.len_inte = (this->len_inte > other.len_inte) ? this->len_inte : other.len_inte;
	temp.len_deci = (this->len_deci > other.len_deci) ? this->len_deci : other.len_deci;

	for (int i = temp.len_deci - 1; i > 0; i--) {
		temp.deci[i] += this->deci[i] + other.deci[i];
		if (temp.deci[i] > 9) {
			temp.deci[i - 1] += 1;
			temp.deci[i] -= 10;
		}
	}
	temp.deci[0] += this->deci[0] + other.deci[0];
	if (temp.deci[0] > 9) {
		temp.deci[0] -= 10;
		temp.inte[0] += 1;
	}//С�����ֵ�������λ

	for (int i = 0; i < temp.len_inte; i++) {
		temp.inte[i] += this->inte[i] + other.inte[i];
		if (temp.inte[i] > 9) {
			temp.inte[i + 1] += 1;
			temp.inte[i] -= 10;
		}
	}
	if (temp.inte[temp.len_inte] > 0) temp.len_inte++;//�������ֵ�������λ

	while (temp.deci[temp.len_deci - 1] == 0)
		temp.len_deci--;//ȥ��С�������0

	return temp;
}


void Number::Display() {
	for (int i = len_inte - 1; i >= 0; i--)
		cout << inte[i];
	if (len_deci > 0) {
		cout << ".";
		for (int i = 0; i < len_deci; i++)
			cout << deci[i];
	}
}