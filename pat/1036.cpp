#include <bits/stdc++.h>
using namespace std;
struct student{
	string name;
	char sex;
	string id;
	int score;
	student(){
		name = "Absent";
	}
}minMale, maxFemale;
string na, idd;
char sex; 
int ss;
int main(){
	int mins = 0x3f3f3f3f, maxs = -1, n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> na >> sex >> idd >> ss;
		//男的  找最低 
		if(sex == 'M'){
			if(ss < mins){
//				cout << na << " -- > " << endl;
				mins = ss;
				minMale.name = na; 
				minMale.sex = sex;
				minMale.id = idd;
				minMale.score = ss;
			} 
		}else{ //女的 
			if(ss > maxs){
//				cout << na << "< --" << endl;
				maxs = ss;
				maxFemale.name = na;
				maxFemale.sex = sex;
				maxFemale.id = idd;
				maxFemale.score = ss;
			}
		} 
	}
	int flag = 0;
	if(maxFemale.name == "Absent"){
		flag = 1;
		cout << "Absent" << endl;
	}else {
		cout << maxFemale.name << " " << maxFemale.id << endl;
	}
	if(minMale.name == "Absent"){
		flag = 1;
		cout << "Absent" << endl; 
	}else {
		cout << minMale.name << " " << minMale.id << endl;
	}
	if(flag) cout << "NA" << endl;
	else cout << maxFemale.score - minMale.score << endl; 
	return 0;
} 

/*

*/ 
