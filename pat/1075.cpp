#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
#define MaxP 6
#define MaxUser 10001
int N,K,M;//ѧ������������������ύ��
int Full_Score[MaxP];
/*����һ��ѧ���ڵ�*/
typedef struct Node {
	int id;//ѧ��id
	int flag=0; //�жϸ����ɼ��Ƿ�����ı��
	int total_score=0;   //ѧ�����ܷ�
	int score[MaxP]= {-1,-1,-1,-1,-1,-1}; //ÿ����Ŀ�ĵ÷�
	int total_number=0;   //�����ȷ����Ŀ����
} Student;
Student studentList[MaxUser];   //����һ���ṹ��������ѧ����Ϣ
/*���뺯��*/
void Input(Student List[]) {
	int i,j;
	int tmpid,tmp_problemid,tmpscore;
	//����ÿ���������
	for(i=1; i<=K; i++) {
		cin>>Full_Score[i];
	}
	//����ÿһ����¼
	for(i=0; i<M; i++) {
		cin>>tmpid>>tmp_problemid>>tmpscore;
		List[tmpid].id=tmpid;
		//��һ���ύ֮����Ӧ����Ŀ����ֵ�ȱ�Ϊ0������֮�����
		if(List[tmpid].score[tmp_problemid]==-1) {
			List[tmpid].score[tmp_problemid]=0;
		}
		//�����Ӧ��Ŀ����>=0.��˵����ͨ��������ͨ����
		if(List[tmpid].score[tmp_problemid]<=tmpscore) {
			//���ø�ѧ��������Ϊ1
			List[tmpid].flag=1;
			//�����ܷ�
			List[tmpid].total_score+=(tmpscore-List[tmpid].score[tmp_problemid]);
			//���ĳ��Ŀ�ύ��Σ�������߳ɼ����м�¼
			List[tmpid].score[tmp_problemid]=tmpscore;
		}
	}
}
/*����ÿ��ѧ����ȫ��Ե���Ŀ����*/
void Calculate(Student studentList[]) {
	int i,j;
	for(i=1; i<=N; i++) {
		if(studentList[i].total_score!=0) {
			for(j=1; j<=K; j++) {
				if(studentList[i].score[j]==Full_Score[j]) {
					studentList[i].total_number++;
				}
			}
		}
	}
}
/*������������*/
bool cmp(Student a,Student b) {
	if(a.total_score>b.total_score||//���շ����ߵ�����
	        (a.total_score==b.total_score&&a.total_number>b.total_number)||  //������ͬ������ȫ�����Ŀ�����������
	        (a.total_score==b.total_score&&a.total_number==b.total_number&&a.id<b.id)) { //ǰ���߶���ͬ�Ļ����Ͱ���id��������
		return true;
	}
	return false;
}
//�������
void output(Student studentList[]) {
	int i,j;
	int number=1;
	for(i=1; i<=N; i++) {
		//������λ1
		if(studentList[i].flag>0) {
			cout<<number<<' ';
			if(studentList[i+1].total_score!=studentList[i].total_score) {
				number=i+1;
			}
			printf("%05d %d",studentList[i].id,studentList[i].total_score);
			for(j=1; j<=K; j++) {
				if(studentList[i].score[j]==-1) {
					printf(" -");
				} else {
					printf(" %d",studentList[i].score[j]);
				}
			}

			printf("\n");
		}

	}
}
int main() {
	cin>>N>>K>>M;
	Input(studentList);
	Calculate(studentList);
	sort(studentList+1,studentList+N+1,cmp);
	output(studentList);
	return 0;
}
