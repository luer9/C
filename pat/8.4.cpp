#include <bits/stdc++.h>
#define Max 100050
using namespace std;
int n, m;
int a[Max];
int vis[Max];
vector<int> vec,ans[Max]; 
int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		vis[a[i]] = 1;
	}
	int i, j;	
	for(i = 0; i < n; i++){
		if(vec.size() != m){
			vec.push_back(a[i]);
		}else{
			sort(vec.begin(),vec.end()); //排序 把最小的找出来 
			int minn = (*vec.begin());
			if(vis[minn] == vis[a[i]] && minn < a[i]){
				vec.erase((*vec.begin()));
				vec.push_back(a[i]);
				ans[vis[a[i]]].push_back(minn);
			}else {
				for(int i = 0; i < vec.size(); i++){
					if(vis[vec[i]] != vis[a[i]])
						continue;
					
					if(vec[i] < )
				}
			}
		}
		
	}
	
	return 0;
}
