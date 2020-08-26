/*
贪心策略：假设现在自己处于A站，要考虑的是A站要不要加油，加多少油的问题。找到当前可达范围内（距离A站cmax*davg）下一个要加油的站B。
A站可达范围内，分三种情况：

①没有加油站，------- 快到终点了，则加适量油到终点；或者 Impossible，则A站加满油到哪算哪；

②有更便宜的加油站 ------- 则找到第一家比A便宜的加油站B，加尽可能少的油（也可能油够直接开过去）到B站；

③只有价格更高的加油站，------则当下A站加满油，寻找相对最便宜的加油站B 开过去。
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
			if(sta[i].price < nowprice) {  //寻找里程里油价最低的加油站  里程范围里有比现在加油站便宜的油，直接进到目的地
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
		//接下来里程内没有比现在便宜的加油站，在当前的加油站把油箱加满(先加满最便宜的油) 
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
