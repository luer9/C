#include <bits/stdc++.h>
using namespace std;
int main(){
	int v1, v2, t, s, l;
	int i = 0; //ÃëÊý
	int len1 = 0, len2 = 0; 
	int flag;
	int ff = 0;
	cin >> v1 >> v2 >> t >> s >> l;
	for(i = 1; ;) {
	
		len1 += v1;
		len2 += v2;
		if(len1 == len2 && len1 >= l){
			flag = 0;
			break;
		}else if(len1 >= l){
			flag = -1;break;
		}else if(len2 >= l) {
			flag = 1;break;
		}
		if((len1 - len2) >= t) {
			for(int j = 0; j < s;j++){
				len2 += v2;
				i++;
				if(len2 >= l) {
					flag = 1;
					ff = 1;
					break;
				}
			}
		}
		
		if(ff == 1) break;
		i++;			
	}
	if(flag == 1) {
		cout << "T" << endl << i << endl; 
	}else if(flag == -1) {
		cout << "R" << endl << i << endl; 
	}else if(flag == 0) {
		cout << "D" << endl << i << endl;
	}
	return 0;
}
