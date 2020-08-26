#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std; 
int main()
{
	//初始化 
	int f=0, length, t;
	char s[11]={'*','*','*','*','*','*','*','*','*','*'};  //避免初始化0，影响判断 
	//用于位数的汉字表示，把空格和个位表示也存入数组，便于输出格式 
	char w[][11] = {" Yi"," Qian"," Bai"," Shi"," Wan"," Qian"," Bai"," Shi",""};
	//用于数字的汉字表示，存成数组就不用switch选了 
	char n[][11] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	
	//PAT已经不支持gets()，会报错error: 'gets' was not declared in this scope 
	//gets(s);
 
	cin.getline(s,11);
	length = strlen(s);
	//判断正负 
	if (s[0]=='-')
	{
		printf("Fu ");
		f=1;  //数据处理时，数据从下标1开始 
	}
	t = length-f;  //求除了负号以外的位数 
	
	for (int i=f; i<length; i++)
	{
		//处理0的输出 
		if (s[i]=='0')
		{ 
			if ((s[i+1]!='0' && i!=length-1 && i!=length-5) || (t==1))
			{
				if (i!=f) printf(" ");  //如果不是第一个数，则开头输出一个空格 
				printf("%s", n[0]);
			}
			if (i==length-5) 
			{  //如果是万位上的0 
				if (s[i-1]=='0'&&s[i-2]=='0'&&s[i-3]=='0'&&s[i+1]!='0')
				{  //若存在亿位，且万位到亿位之间全为0，若千位非0，则需输出一个"ling" 
					printf(" %s", n[0]); 
				} else if (!(s[i-1]=='0'&&s[i-2]=='0'&&s[i-3]=='0')) {
					printf("%s", w[4]);  //若万位到亿位之间存在非0数，则输出"wan" 
				}				
			}
		} else {  //非0数的输出 
			int temp = (int)s[i] - (int)'0';  //字符转整数 
			if (i!=f) printf(" ");  
			printf("%s%s", n[temp], w[9-length+i]);
		}
	}
	
	return 0;
 } 
