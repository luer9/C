#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
int main()
{
	//��ʼ�� 
	int f=0, length, t;
	char s[11]={'*','*','*','*','*','*','*','*','*','*'};  //�����ʼ��0��Ӱ���ж� 
	//����λ���ĺ��ֱ�ʾ���ѿո�͸�λ��ʾҲ�������飬���������ʽ 
	char w[][11] = {" Yi"," Qian"," Bai"," Shi"," Wan"," Qian"," Bai"," Shi",""};
	//�������ֵĺ��ֱ�ʾ���������Ͳ���switchѡ�� 
	char n[][11] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	
	//PAT�Ѿ���֧��gets()���ᱨ��error: 'gets' was not declared in this scope 
	//gets(s);
 
	cin.getline(s,11);
	length = strlen(s);
	//�ж����� 
	if (s[0]=='-')
	{
		printf("Fu ");
		f=1;  //���ݴ���ʱ�����ݴ��±�1��ʼ 
	}
	t = length-f;  //����˸��������λ�� 
	
	for (int i=f; i<length; i++)
	{
		//����0����� 
		if (s[i]=='0')
		{ 
			if ((s[i+1]!='0' && i!=length-1 && i!=length-5) || (t==1))
			{
				if (i!=f) printf(" ");  //������ǵ�һ��������ͷ���һ���ո� 
				printf("%s", n[0]);
			}
			if (i==length-5) 
			{  //�������λ�ϵ�0 
				if (s[i-1]=='0'&&s[i-2]=='0'&&s[i-3]=='0'&&s[i+1]!='0')
				{  //��������λ������λ����λ֮��ȫΪ0����ǧλ��0���������һ��"ling" 
					printf(" %s", n[0]); 
				} else if (!(s[i-1]=='0'&&s[i-2]=='0'&&s[i-3]=='0')) {
					printf("%s", w[4]);  //����λ����λ֮����ڷ�0���������"wan" 
				}				
			}
		} else {  //��0������� 
			int temp = (int)s[i] - (int)'0';  //�ַ�ת���� 
			if (i!=f) printf(" ");  
			printf("%s%s", n[temp], w[9-length+i]);
		}
	}
	
	return 0;
 } 
