#include <bits/stdc++.h>
#define Max 100020
using namespace std;
struct Stu{
	string id;
	int Gp, Gmid, Gf, G;
	Stu(){
		Gp = -2;
		Gmid = -2;
		Gf = -2;
	}
}stu[Max];
map<string ,int > mapp; //存 stu_ 的 序号  
int p, m, n;
int cmp(Stu a,Stu b){
	if( a.G == b.G ){
		return a.id < b.id;
	} 
	return a.G > b.G;
}
int main(){
	string id;
	int g;
	int index = 1; 
	cin >> p >> m >> n;
	//Gp
	for(int i = 0; i < p; i++){
		cin >> id >> g;
		if(mapp[id] == 0){
			mapp[id] = index;
			stu[index].id = id;
			stu[index++].Gp = g;
		}else{
			stu[mapp[id]].Gp = g;
		}
	}
	//mid
	for(int i = 0; i < m; i++){
		cin >> id >> g;
		if(mapp[id] == 0){
			mapp[id] = index;
			stu[index].id = id;
			stu[index++].Gmid = g;
		}else {
			stu[mapp[id]].Gmid = g;
		}
	}
	//final
	for(int i = 0; i < n; i++){
		cin >> id >> g;
		if(mapp[id] == 0){
			mapp[id] = index;
			stu[index].id = id;
			stu[index].Gf = g;
			if(stu[index].Gmid > stu[index].Gf){
				stu[index].G = (int)(round(stu[index].Gmid*1.0*0.4 + stu[index].Gf*1.0*0.6)); 
				
			}else{
				 stu[index].G = stu[index].Gf; 
			}
			index++;	
			
		}else {
			stu[mapp[id]].Gf = g;
			if(stu[mapp[id]].Gmid > stu[mapp[id]].Gf){
				stu[mapp[id]].G = (int)(round(stu[mapp[id]].Gmid*1.0*0.4 + stu[mapp[id]].Gf*1.0*0.6)); 
			}else{
				stu[mapp[id]].G = stu[mapp[id]].Gf; 
				 
			}
		}
	}
//	cout <<"----> "<< index << endl;
	sort(stu + 1, stu + 1 + index, cmp);
	for(int i = 1; i < index; i++){
		if(stu[i].Gp >= 200 && (stu[i].G >= 60 && stu[i].G <=100) )
		cout << stu[i].id << " " << (stu[i].Gp==-2?-1:stu[i].Gp)  << " " << (stu[i].Gmid==-2?-1:stu[i].Gmid)<< " " << (stu[i].Gf==-2?-1:stu[i].Gf) << " " << stu[i].G << endl; 
	}
	return 0;
}
/*
卡第四个测试点， 0 不代表 没考试， 所以把原始的 数 改成 -2 如果 为 -2 的话代表没考试 
*/
/*
he/she must first obtain no less than 200 points from the online programming assignments, 
and then receive a final grade no less than 60 out of 100. 
*/
