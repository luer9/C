//把数N 分解成 K个正整数的P次幂 ，答案不唯一 给出元素之和最大的解 
#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int sumind = -1;
vector<int> v, ans, temp;
void init(){
	//预处理 
	for(int i = 0; i * i <= n; i++){
		v.push_back(pow(i, p)); 
	}
}
//ind是当前元素下标，sum是元素p次幂之和，nowk是加了多少元素，sumindex是元素之和 
void dfs(int ind, int sum, int nowk, int sumindex){
	if(nowk == k && sum == n){
		if(sumindex > sumind){
			sumind = sumindex;
			ans = temp;
		}
		return;
	}
	//剪枝 
	if(sum > n || nowk > k) return ;
	if(ind >= 1){
		temp.push_back(ind);//选择ind元素 
		dfs(ind, sum + v[ind], nowk + 1,sumindex + ind);
		temp.pop_back(); //不选
		dfs(ind - 1, sum, nowk, sumindex); 
	}
}
int main(){
	cin >> n >> k >> p;
	init();
	dfs(v.size() - 1, 0, 0, 0);
	if(sumind == -1) cout << "Impossible" << endl;
	else {
		cout << n << " = " << ans[0] << "^" << p;
		for(int i = 1; i < ans.size(); i++){
			cout << " + " << ans[i] << "^" << p;
		}
	}
	return 0; 
}
