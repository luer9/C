//wa
//#include <bits/stdc++.h>
//#define Max 10002
//using namespace std;
//struct test{
//	string id;
//	int score;
//}t[Max];
//
//int n, m;
//int cmp(test a,test b){
//	if(a.score == b.score){
//		return a.id < b.id;
//	}
//	return a.score > b.score;
//}
//
//int main(){
//	ios::sync_with_stdio(false);
//	cin >> n >> m;
//	for(int i = 0; i < n; i++){
//		cin >> t[i].id >> t[i].score;	
//	}
//	sort(t, t+n, cmp);
//	for(int C = 1; C <= m; C++){
//		int type; string term;
//		cin >> type >> term;
//		if(type == 1){
//			int flag = 0; //判断是否有数据输出 
//			cout << "Case " << C << ": " << type << " " <<term << endl;
//			for(int j = 0; j < n; j++){
//				if(t[j].id[0] == term[0]){
//					flag = 1;
//					cout << t[j].id << " " << t[j].score << endl; 
//				}
//			}
//			if(!flag) {
//				cout << "NA" << endl;
//			}
//		}else if(type == 2){
//			int cnt = 0, total = 0, flag = 0;
//			for(int j = 0; j < n; j++){
//				string temp = t[j].id.substr(1,3);
////				cout << temp << endl;
//				if(temp == term) {
//					flag = 1;
//					cnt++;
//					total += t[j].score;
//				}
//			}
//			cout << "Case " << C << ": " << type << " " <<term << endl;
//			if(!flag) {
//				cout << "NA" << endl;
//				continue;
//			}
//			cout << cnt <<" "<< total << endl;
//		}else if(type == 3){
//			int flag = 0;
//			map<string,int> mapp; mapp.clear();
//			vector<test> ans; ans.clear();
//			for(int j = 0; j < n; j++){
//				if(t[j].id.substr(4, 6) == term){
//					flag = 1;
//					mapp[t[j].id.substr(1,3)]++;
//				}
//			}
//			if(!flag) cout << "NA" << endl;
//			else{
//			 	map<string,int>::iterator it;
//			 	for(it = mapp.begin(); it!= mapp.end(); it++){
//			 		ans.push_back({it->first, it->second});
//				 }
//			}
//			sort(ans.begin(), ans.end(), cmp);
//			for(int j = 0; j < ans.size(); j++){
//				cout << ans[j].id << " " << ans[j].score << endl;
//			}
//		} 
//	}
//	return 0;
//}

#include <bits/stdc++.h>
using namespace std;
struct node {
    string t;
    int value;
};
bool cmp(const node &a, const node &b) {
    return a.value != b.value ? a.value > b.value : a.t < b.t;
}
int main() {
    int n, k, num;
    string s;
    cin >> n >> k;
    vector<node> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i].t >> v[i].value;
    for (int i = 1; i <= k; i++) {
        cin >> num >> s;
        printf("Case %d: %d %s\n", i, num, s.c_str());
        vector<node> ans; ans.clear();
        int cnt = 0, sum = 0;
        if (num == 1) {
            for (int j = 0; j < n; j++)
                if (v[j].t[0] == s[0]) ans.push_back(v[j]);
        } else if (num == 2) {
            for (int j = 0; j < n; j++) {
                if (v[j].t.substr(1, 3) == s) {
                    cnt++;
                    sum += v[j].value;
                }
            }
            if (cnt != 0) printf("%d %d\n", cnt, sum);
        } else if (num == 3) {
            unordered_map<string, int> m; m.clear();  //unordered_map不会超时…………我去 
            for (int j = 0; j < n; j++)
                if (v[j].t.substr(4, 6) == s) m[v[j].t.substr(1, 3)]++;
            unordered_map<string, int>::iterator it;
			for(it = m.begin(); it != m.end(); it++){
				 ans.push_back({it->first, it->second});
			} 
        }
        sort(ans.begin(), ans.end(),cmp);
        for (int j = 0; j < ans.size(); j++)
            printf("%s %d\n", ans[j].t.c_str(), ans[j].value);
        if (((num == 1 || num == 3) && ans.size() == 0) || (num == 2 && cnt == 0)) printf("NA\n");
    }
    return 0;
}
