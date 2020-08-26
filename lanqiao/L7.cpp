#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int n,a;
priority_queue<int, vector<int>,greater<int> > q; 
int main() {
	
	while(!q.empty()) q.pop();
	cin >> n;
	for(int i = 0; i < n;i++){
		cin >> a;
		q.push(a);
	} 
//	cout << q.size() << endl;
	int ans = 0;
	while(q.size() != 1) {
		int a1 = q.top(); q.pop();
		int a2 = q.top(); q.pop();
//		cout << a1 << " " << a2 << endl;
		ans = ans + a1 + a2;
		q.push(a1+a2);
	}
//	if(q.size() == 1){
//		int a1 = q.top(); q.pop();
//		ans = ans + a1;
//	} 
	cout << ans << endl; 
	return 0;
}
