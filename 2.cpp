//4d2 ̰���㷨 ��������  

#include <iostream>   
using namespace std;   
  
const int N = 7;  
  
void Knapsack(int n,float M,float v[],float w[],float x[]);  
  
int main()  
{  
    float M = 150;//�����������ɵ�����  
    //�����������Ʒ����λ��ֵ��������  
    float w[] = {35,30,60,50,40,10,25};//�±��1��ʼ  
    float v[] = {10,40,30,50,35,40,30};  
  
    float x[N+1];  
  
    cout<<"�����������ɵ�����Ϊ��"<<M<<endl;  
    cout<<"��װ��Ʒ�������ͼ�ֵ�ֱ�Ϊ��"<<endl;  
    for(int i=1; i<=N; i++)  
    {  
        cout<<"["<<i<<"]:("<<w[i]<<","<<v[i]<<")"<<endl;  
    }  
      
    Knapsack(N,M,v,w,x);  
  
    cout<<"ѡ��װ�µ���Ʒ�������£�"<<endl;  
    for(int i=1; i<=N; i++)  
    {  
        cout<<"["<<i<<"]:"<<x[i]<<endl;  
    }  
  
    return 0;  
}  
  
void Knapsack(int n,float M,float v[],float w[],float x[])  
{  
    //Sort(n,v,w);//����ٶ�w[],v[]�Ѱ�Ҫ���ź���  
    int i;  
    for (i=1;i<=n;i++)  
    {  
        x[i]=0;//��ʼ������x[]  
    }  
  
    float c=M;  
    for (i=1;i<=n;i++)//��Ʒ������װ��,x[i]=1  
    {  
        if (w[i]>c)  
        {  
            break;  
        }  
        x[i]=1;  
        c-=w[i];  
    }  
  
    //��Ʒiֻ�в��ֱ�װ��  
    if (i<=n)  
    {  
        x[i]=c/w[i];  
    }  
}  
