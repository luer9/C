//����N �ֽ�� K����������P���� ���𰸲�Ψһ ����Ԫ��֮�����Ľ� 
#include <bits/stdc++.h>
using namespace std;
int n, k, p;
int sumind = -1;
vector<int> v, ans, temp;
void init(){
	//Ԥ���� 
	for(int i = 0; i * i <= n; i++){
		v.push_back(pow(i, p)); 
	}
}
//ind�ǵ�ǰԪ���±꣬sum��Ԫ��p����֮�ͣ�nowk�Ǽ��˶���Ԫ�أ�sumindex��Ԫ��֮�� 
void dfs(int ind, int sum, int nowk, int sumindex){
	if(nowk == k && sum == n){
		if(sumindex > sumind){
			sumind = sumindex;
			ans = temp;
		}
		return;
	}
	//��֦ 
	if(sum > n || nowk > k) return ;
	if(ind >= 1){
		temp.push_back(ind);//ѡ��indԪ�� 
		dfs(ind, sum + v[ind], nowk + 1,sumindex + ind);
		temp.pop_back(); //��ѡ
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
