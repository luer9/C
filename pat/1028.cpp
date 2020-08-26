#include <bits/stdc++.h>
#define Max 100050
using namespace std;
struct Stu{
	string id;
	string name;
	int score;
}stu[Max];
int n, c;
int cmp1(Stu a, Stu b){
	return a.id < b.id;
}
int cmp2(Stu a, Stu b){
	if(a.name == b.name)
		return a.id < b.id;
	return a.name < b.name;
}
int cmp3(Stu a, Stu b){
	if(a.score == b.score)
		return a.id < b.id;
	return a.score < b.score;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> c;
	for(int i = 0; i < n; i++){
		cin >> stu[i].id >> stu[i].name >> stu[i].score;
	}
	if(c == 1){
		sort(stu, stu + n, cmp1);
	}else if(c == 2){
		sort(stu, stu + n, cmp2);
	}else if(c == 3){
		sort(stu, stu + n, cmp3);
	}
	for(int i = 0; i < n; i++){
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].score << endl; 
	} 
	return 0;
}
