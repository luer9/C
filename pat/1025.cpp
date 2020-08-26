#include <bits/stdc++.h>
#define Max 33333
using namespace std;
struct Stu{
	string id;
	int score;
	int fk;//final rank
	int lnum; //地区编号
	int lk; //所在地排名 
}stu[Max];
int n, k; 
int cmp(Stu a, Stu b){
	if(a.score != b.score) return a.score > b.score;
	else return a.id < b.id;
}
int main(){
	int ind = 0; //总人数 
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> k;
		for(int j = 0; j < k; j++){
			cin >> stu[ind].id >> stu[ind].score;
			stu[ind].lnum = i;
			ind ++;
		}
		sort(stu + ind - k, stu + ind, cmp);
		stu[ind - k].lk = 1;
		for(int j = ind - k + 1; j < ind; j++){
			if(stu[j].score == stu[j-1].score){
				stu[j].lk = stu[j-1].lk;
			}else {
				stu[j].lk = j - (ind - k) + 1;
			}
		}		
	} 
	//输出总人数 
	cout << ind << endl; 
	sort(stu, stu + ind, cmp);
	int rk = 1;
	stu[0].fk = rk;
	cout << stu[0].id << " " << stu[0].fk << " " << stu[0].lnum << " " << stu[0].lk << endl;
	for(int i = 1; i < ind; i++){
		if(stu[i].score != stu[i-1].score){
			rk = i + 1;
		}
		cout << stu[i].id << " " << rk << " " << stu[i].lnum << " " << stu[i].lk << endl;
	} 
	return 0;
}
