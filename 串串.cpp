#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
	int n; 
	cin >> n; 
	for (int i = 0; i <= n / 7; ++i)
		for (int j = 0; j <= n / 5; ++j)
			for (int k = 0; k <= n / 3; ++k)
				if (i * 7 + j * 5 + k * 3 == n) {
					cout << k << ' ' << j << ' ' << i << endl; 
					return 0; //����return��������
				}
	cout << -1; 
	return 0;
}

/*����
Wͬѧʮ��ϲ���Դ���������ÿ����ֻ�������������н���ѡ��3Ԫһ���Ľ��빽��5Ԫһ�������ȵ�������7Ԫһ���Ļ�ΧϺ��
���ڼ���Wͬѧ�Դ�����nԪǮ������������Ĳ˵��п��ܵ��˶��ٴ����빽�����ٴ����ȵ������ٴ���ΧϺ��
���룺1�У�һ����n����ʾһ��������nԪ(0<=n<=1000)��
�����1�У�������ܵó���Ч����Ϸ��������-1�����򣬷ֱ�������빽�����ȵ�����ΧϺ�Ĵ���������ж�����Ϸ������������һ�ּ��ɡ�
*/

/*�Խ�
int main(){
    int n, n3, n5, n7;
    cin >> n;
    bool flag = true;
    for (n3=0; n3 * 3 <= n&&flag; n3++){
        for (n5=0; n5 * 5 <= n&&flag; n5++){
            for (n7=0; n7 * 7 <= n&&flag; n7++){
                if (n == n3 * 3 + n5 * 5 + n7 * 7){
                    cout << n3 <<" "<< n5 <<" "<< n7 << endl;
                    flag = false;
                }
            }
        }
    }
        if (flag==true) cout<<"-1";
    return 0;
}
*/

