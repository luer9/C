#include <iostream>
#include <string.h>

using namespace std;

int L,N,l;//LΪ�������ȣ�NΪ����1�ĸ���,lΪ�̴�����
char a[50];//�洢�̴�����1��ʼ��
int flag=0;//�ɹ�ƥ��Ĵ�����0����ʧ�ܣ�2�����ϴ�������

void dfs(int num_1, int len, int i)//num_1ΪĿǰ�����1��������lenΪĿǰ����õ��ĳ��볤�ȣ�iΪ��Ҫ�������ʼλ��
{
    if(i==l)//���������һλΪ���뿪ʼ�ĵط�
    {
        dfs(num_1+a[i]-'0',len+1,i+1);
        return;
    }
    if(i>l)//һ���������
    {
        if(len==L && num_1==N)
        {
            flag++;
        }
        return;
    }
    if(len>L || num_1>N || flag>=2) return;//��Ȼ�������������������������˳�
    if(a[i]=='0')//0�Ļ�ֻҪ������һ�����룬num_1����
    {
        dfs(num_1,len+1,i+1);
        return;
    }
    //��������a[i]==1�����
    if(a[i-1]=='1') return;//��0110��010ƥ�䣬��Ϊ֮ǰ�Ѿ������
    long long temp=0;//����i~j��һ������Ƽ���1����Ȼ��Ŀ�����16*1024*8=131072λ����int��Χ�ڣ����������ʱ����ܳ���
    if(a[i+1]=='0')//����010
    {
        dfs(num_1+1,len+1,i+1);
        //��дreturn����Ϊ����������벻�У���Ҫ�������ź������룬����10100�������101111��1111100����˻���Ҫ�μ�forѭ��
    }
    if(a[i+1]=='1' && a[i+2]!='1')//����0110�����ﲻ��=='0'����Ϊ�������
    {
        dfs(num_1+2,len+2,i+2);
    }
    //�����������ϵ�1ͬʱ���֣�����0110���ͳ�11������������
    for(int j=i;j<=l;j++)
    {
        temp*=2;//����һλ
        temp+=a[j]-'0';//�������
        if(temp+num_1>N || temp+len>L) break;//ʧ��
        if(temp>j-i+1 && a[j+1]!='1')//ʡ����010���ظ�����
            dfs(num_1+temp,len+temp,j+1);//i~j��һ�����룬a[j+1]Ϊ0�����
    }
}


int main()
{
    cin>>L>>N;
    cin>>(a+1);
    l=strlen(a+1);
    dfs(0,0,1);
    if(flag==1) cout<<"YES"<<endl;
    if(!flag) cout<<"NO"<<endl;
    if(flag>=2) cout<<"NOT UNIQUE"<<endl;
    return 0;
}


