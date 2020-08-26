#include<bits/stdc++.h>
using namespace std;
struct Good{
 	double sum;
	double price;
	double ef;
}good[1001]; 
int n, d;
int cmp(Good a, Good b){
	return a.ef > b.ef;
}
int main(){
	cin >> n >> d;
	for(int i = 0; i < n; i++)
		cin >> good[i].sum;
	for(int i = 0; i < n; i++){
		cin >> good[i].price;
		good[i].ef = good[i].price / good[i].sum*1.0;
	}
	sort(good, good+n, cmp);
	double ans = 0;
	for(int i = 0; i < n; i++){
		if(good[i].sum <= d){
			ans += good[i].price;
			d -= good[i].sum;
		}else {
			ans += (good[i].ef * d);
			d = 0;
//			break;
		}
	}
	cout << fixed << setprecision(2) << ans << endl;
	return 0;
} 
