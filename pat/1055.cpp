#include <bits/stdc++.h>
#define Max 100005
using namespace std;
struct Rich{
	string name;
	int age;
	int worth;
}richer[Max], valid[Max];
int n, k, m;
int amin, amax;
int book[Max];
int cmp(Rich a, Rich b){
	if(a.worth == b.worth){
		if(a.age == b.age){
			return a.name < b.name;
		}
		return a.age < b.age;
	}
	return a.worth > b.worth;
}
int main(){
	ios::sync_with_stdio(false);
	memset(book, 0, sizeof(book));
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> richer[i].name >> richer[i].age >> richer[i].worth; 
	}
	sort(richer, richer + n, cmp); 
	int validNum = 0;
	for(int i = 0; i < n; i++){
		if(book[richer[i].age] <= 100){
			book[richer[i].age] ++;
			valid[validNum++] = richer[i];
		}//只保留每个年龄的人数小于100的富豪 
	} 
	for(int Case = 1; Case <= k; Case++){
		int flag = 0;
		cin >> m >> amin >> amax;
		cout << "Case #" << Case << ":" << endl;
		for(int i = 0, j = 0; j < m && i < validNum; i++){
			if(valid[i].age >= amin && valid[i].age <= amax){
				cout << valid[i].name << " " << valid[i].age << " " << valid[i].worth << endl;
				j++;
				flag = 1;
			}
		} 
		if(!flag) cout <<"None" << endl;
	}
	return 0;
} 
