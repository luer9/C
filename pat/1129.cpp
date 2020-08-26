#include <bits/stdc++.h>
#define Max 55555
using namespace std;
struct node{
	int num, cnt;
	node(int num,int cnt):num(num),cnt(cnt){}
	bool operator < (const node &a) const{
		return cnt != a.cnt ? cnt > a.cnt : num < a.num;
	}
};
set<node> s;
int times[Max], n, k, num;
int main(){
	memset(times, 0, sizeof(times));
	cin >> n >> k;
	
	for(int i = 0; i < n; i++){
		cin >> num;
		if(i != 0){
			cout << num << ":";
			int cnt = 0;
			set<node> ::iterator it;
			for(it = s.begin(); cnt < k && it!=s.end(); it++){
				cout << " " << (*it).num;
				cnt++;
			}
			cout << endl;
		}
		set<node> ::iterator it;
		it = s.find(node(num,times[num]));
		if(it != s.end()) s.erase(it);
		times[num]++;//更新浏览次数 加入set中
		s.insert(node(num,times[num])); 
	}
	return 0;
}
