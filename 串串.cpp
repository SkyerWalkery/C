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
					return 0; //利用return结束程序
				}
	cout << -1; 
	return 0;
}

/*附：
W同学十分喜欢吃串串，但是每次他只在这三样东西中进行选择：3元一串的金针菇，5元一串的鹌鹑蛋，还有7元一串的基围虾。
现在假设W同学吃串花了n元钱，请你计算他的菜单中可能点了多少串金针菇，多少串鹌鹑蛋，多少串基围虾。
输入：1行，一个数n，表示一共花费了n元(0<=n<=1000)。
输出：1行，如果不能得出有效的组合方案，输出-1；否则，分别输出金针菇、鹌鹑蛋、基围虾的串数，如果有多组组合方案，任意输出一种即可。
*/

/*自解
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

