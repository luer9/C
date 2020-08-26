#include <iostream>
#include <algorithm>
using namespace std;
struct item{
    int weight;//物品的重量 
    int value;//物品的价值 
    float bi;//物品单位重量的价值 
    float rate;//使用率：1代表物品完整放入，小于1代表被分割后放入 
}items[100];
bool cmp(const item &a,const item &b){
    return a.bi>b.bi;
}
int main(){
    int n;//n件物品
    float c;//背包容量为c
    cout<<"输入物品件数和背包容量："<<endl; 
    cin>>n>>c;
    cout<<"依次输入每件物品的价值和重量："<<endl;
    float v[n],w[n];//v[n]：n件物品的价值，w[n]：n件商品的重量 
    for(int i=0;i<n;i++){
        cin>>items[i].value>>items[i].weight;
        items[i].bi=items[i].value/items[i].weight;//计算单位重量价值
        items[i].rate=0;//初始化每件物品的使用率 
    }
    sort(items,items+n,cmp);//按照单位重量的价值排序 
    int sum=0,j=0;
    for(j=0;j<n;j++){
        if(items[j].weight<=c){//选择单位价值重量最大的并且不超过背包容量的 
            items[j].rate=1;
            sum+=items[j].weight;
            c-=items[j].weight;
            cout<<"重："<<items[j].weight<<"、价值："<<items[j].value<<"的物品被放入了背包"<<endl<<"放入比例："<<items[j].rate<<endl;
        }
        else break;
    } 
    if(j<n){//物品未装完 
        items[j].rate=c/items[j].weight;//背包容量还剩c,计算出未装入的物品能装多少的比例 
        sum+=items[j].rate*items[j].weight;//加上装入部分比例物品的重量 
        cout<<"重："<<items[j].weight<<"、价值："<<items[j].value<<"被放入了背包"<<endl<<"放入比例："<<items[j].rate<<endl; 
    }
    return 0; 
    
    
}
