//任务是写一个程序判断玩家的数字决定最后的赢家
//每个玩家给出的数字 不能是之前已经存在的 npos
// n是玩家的数量  m是比赛回合
//如果第i个玩家在第k轮出局就打印 Round…… i is out 这个玩家剩下给的数字都被忽略
//如果超过一个玩家在相同的回合out，那么就升序打印他们的下标
//如果一个玩家给出的数 不等于 前一个玩家 与 之前给出的两个数字之后的差值
//则 out   之后的差是与正确结果的差相比
//游戏结束后 打印最后的玩家 升序

#include <bits/stdc++.h>
#define Max 100050
using namespace std;
set<int> allNum;//所有数字
int isIng[Max];//判断这个数是否可以被忽略
set<int> cha; //差
int n, m;// 玩家数量 ， m是比赛回合
int roun[11][1003]; //第i个人 第 j 轮的数字
int a0, b0;//初始数
void procha() {
	set<int> ::iterator it1,it2;
	for(it1 = allNum.begin(); it1 != allNum.end(); it1++) {
		for(it2 = allNum.begin(); it2 != allNum.end(); it2++) {
			cha.insert((*it1)-(*it2));
			cha.insert((*it2)-(*it1));
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	memset(isIng, 0, sizeof(isIng));
	cin >> a0 >> b0;
	allNum.insert(a0);
	allNum.insert(b0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> roun[i][j];
		}
	}
	//m轮

	for(int j = 1; j <= m; j++) {
		set<int> out;//记录每轮出局的人
		out.clear();
		//人
		for(int i = 1; i <= n; i++) {
			//如果第i个人没有被忽略
			if(!isIng[i]) {
				procha();
				//差里找不到  或者之前出现过  out
//				cout << "***-》 " << cha.count(roun[i][j]) << " " << allNum.count(roun[i][j]) << endl;
				if(cha.count(roun[i][j]) == 0 || allNum.count(roun[i][j]) != 0) {
					out.insert(i);
					isIng[i] = 1;
				} else {
					allNum.insert(roun[i][j]);
				}
			}
		}
		set<int>::iterator ss;
		if(out.size() == 1) {

			cout << "Round #" << j << ": " << (*out.begin()) << " is out." << endl;
		} else if(out.size() > 1) {
			cout << "Round #" << j << ":";
			for(ss = out.begin(); ss != out.end(); ss++) {
				cout << " " << (*ss);

			}
//			cout << endl;
			cout << " is out." << endl;
		}
	}
	set<int> win;
	win.clear();
	for(int i = 1; i <= n; i++) {
		if(!isIng[i]) win.insert(i);
	}
	if(win.size() != 0) {
		cout << "Winner(s):";
	} else {
		cout << "No winner.";
	}
	set<int> ::iterator winner;
	for(winner = win.begin(); winner != win.end(); winner++) {
		cout << " " << (*winner);
	}
	return 0;
}
