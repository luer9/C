/*
̰�Ĳ��ԣ����������Լ�����Aվ��Ҫ���ǵ���AվҪ��Ҫ���ͣ��Ӷ����͵����⡣�ҵ���ǰ�ɴﷶΧ�ڣ�����Aվcmax*davg����һ��Ҫ���͵�վB��
Aվ�ɴﷶΧ�ڣ������������

��û�м���վ��------- �쵽�յ��ˣ���������͵��յ㣻���� Impossible����Aվ�����͵������ģ�

���и����˵ļ���վ ------- ���ҵ���һ�ұ�A���˵ļ���վB���Ӿ������ٵ��ͣ�Ҳ�����͹�ֱ�ӿ���ȥ����Bվ��

��ֻ�м۸���ߵļ���վ��------����Aվ�����ͣ�Ѱ���������˵ļ���վB ����ȥ��
https://blog.csdn.net/tiantangrenjian/article/details/19175831?utm_medium=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase&depth_1-utm_source=distribute.pc_relevant.none-task-blog-BlogCommendFromMachineLearnPai2-1.nonecase

*/ 
#include <bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
struct station {
	double price, dis;
};
bool cmp(station a, station b) {
	return a.dis < b.dis;
}
double cmax, d, davg;
int n;
int main() {

	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	vector<station> sta(n + 1);
	sta[0] = {0.0, d};
	for(int i = 1; i <= n; i++)
		scanf("%lf%lf", &sta[i].price, &sta[i].dis);
	sort(sta.begin(), sta.end(), cmp);
	double nowdis = 0.0, maxdis = 0.0, nowprice = 0.0, totalPrice = 0.0, leftdis = 0.0;
	if(sta[0].dis != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	} else {
		nowprice = sta[0].price;
	}
	while(nowdis < d) {
		maxdis = nowdis + cmax * davg;
		double minPriceDis = 0, minPrice = inf;
		int flag = 0;
		for(int i = 1; i <= n && sta[i].dis <= maxdis; i++) {
			if(sta[i].dis <= nowdis) continue;
			if(sta[i].price < nowprice) {  //Ѱ��������ͼ���͵ļ���վ  ��̷�Χ���б����ڼ���վ���˵��ͣ�ֱ�ӽ���Ŀ�ĵ�
				totalPrice += (sta[i].dis - nowdis - leftdis) * nowprice / davg;
				leftdis = 0.0;
				nowprice = sta[i].price;
				nowdis = sta[i].dis;
				flag = 1;
				break;
			}
			if(sta[i].price < minPrice) {
				minPrice = sta[i].price;
				minPriceDis = sta[i].dis;
			}
		}
		//�����������û�б����ڱ��˵ļ���վ���ڵ�ǰ�ļ���վ���������(�ȼ�������˵���) 
		if(flag == 0 && minPrice != inf) {
			totalPrice += (nowprice * (cmax - leftdis / davg));
			leftdis = cmax * davg - (minPriceDis - nowdis);
			nowprice = minPrice;
			nowdis = minPriceDis;
		}
		if(flag == 0 && minPrice == inf) {
			nowdis += cmax * davg;
			printf("The maximum travel distance = %.2f", nowdis);
			return 0;
		}
	}
	printf("%.2f", totalPrice);
	return 0;
}
