#include <bits/stdc++.h>
#define Max 50005
using namespace std;
int pre[Max], in[Max], n;
int flag;
void postTravel(int now, int l, int r){
	if( l > r || flag == 1) {
		return ;
	}
	int i = l;
	while( in[i] != pre[now] ) i++;
	postTravel(now+1, l, i-1);
	postTravel(now+1+i-l, i+1, r);
	if(!flag){
		cout << pre[now];
		flag = 1;
	}
}
int main(){
	flag = 0;
	memset(pre, 0, sizeof(pre));
	memset(in, 0, sizeof(in));
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> pre[i];
	}
	for(int i = 0; i < n; i++){
		cin >> in[i];
	}
	postTravel(0, 0, n-1);
	return 0;
} 
//������������һ��Ԫ���������������ĸ��ڵ�
/*

���ý���
���ȣ����������һ��һ���Ǹ��ڵ㡣������ʱ����NOW��������������λ�ã�������ǰ�ڵ㣩
Ȼ��������������ҵ�NOW��λ�ã�����λ���±���POS���������������ô��ߵľ�����������L ~ POS-1�����ұߵľ�����������POS+1 ~ R����(����ָ�������)
һ��ʼ�ķ�Χ��0~N-1��L ~ R)
������������
���ڵ��±���NOW+1���������������߽���Ȼ�� L , �ұ߽���POS - 1.
������������
���ڵ㣺NOW+1+��POS-L�� ��߽磺POS+1 �ұ߽磺R

Ȼ��ݹ�����Ϳ����ˣ�����ֻҪ�����������ĵ�һ���ڵ㣬���������ֱ��return��

*/
