#include <bits/stdc++.h>
#define Max 10001
using namespace std;
struct Stu{
	string name, id;
	int grade;
}stu[Max];
int n;
bool cmp(Stu a,Stu b){
	return a.grade > b.grade;
}
int main(){
	int g1, g2;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> stu[i].name >> stu[i].id >> stu[i].grade;
	}
	cin >> g1 >> g2;
	sort(stu, stu + n, cmp);
	int flag = 0;
	for(int i = 0; i < n; i++){
		if(stu[i].grade >= g1 && stu[i].grade <= g2){
			flag = 1;
			cout << stu[i].name << " " << stu[i].id << endl;
		}
	}
	
	if(!flag) {
		cout << "NONE" << endl; 
	}
	return 0;
} 
