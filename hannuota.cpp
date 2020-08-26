#include <bits/stdc++.h>
using namespace std;
void Hanoi(int n, char a, char b, char c){
	if(n == 1) { // 递归出口 
		cout << "将第 " << n << " 个盘片从 " << a << " 移动到 " << c << endl;
		return ; 
	}else{
		Hanoi(n-1, a, c, b); // 把n-1个圆盘从 a 借助 c 移动 到 b 
		cout << "将第 " << n <<" 个盘片从 " << a << " 移动到 " << c << endl; 
		Hanoi(n-1, b, a, c); //把n-1个圆盘从 b 借助 a 移动到 c 
	}
}
int main(){
	int n; // 汉诺塔盘子的数目
	cout << "请输入汉诺塔盘子的数目：" << endl;
	cin >> n;
	cout << n << " 个盘片移动过程：" << endl; 
	Hanoi(n,'A','B','C'); 
	return 0;
}
