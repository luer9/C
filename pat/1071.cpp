#include <bits/stdc++.h>
using namespace std;
string s;
//用set存放 字符串
//用map记录个数
set<string> se;
map<string, int> mapp;
int main() {
	int len;
	string temp = "";
	se.clear();
	mapp.clear();
	getline(cin, s);
	transform(s.begin(), s.end(), s.begin(),::tolower);
//	cout << s << endl;
	len = s.length();
	for(int i = 0; i < len; i++) {
		if((s[i] >= 'a' && s[i] <= 'z')|| (s[i] >= '0' && s[i] <= '9')) {
			temp += s[i];
		} else {
			if(temp != "") {
				se.insert(temp);
				mapp[temp]++;
			}

			temp = "";
		}
	}
	//!最后一个单词！！ 最后一个测试用例坑点
	if(temp != "") {
		se.insert(temp);
		mapp[temp]++;
	}
	string maxS = "";
	int maxCnt = -1;
	set<string>::iterator it;
	for(it = se.begin(); it != se.end(); it++) {

		if(mapp[(*it)] > maxCnt) {
			maxS = (*it);
			maxCnt = mapp[(*it)];
		}
	}
	cout << maxS << " " << maxCnt << endl;
	return 0;
}
