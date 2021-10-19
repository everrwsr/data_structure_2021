//3.12
#include<stdio.h>
 
#define maxSize 20
 
/* ˳������Ͷ��� */
typedef struct {
	int data[maxSize];
	int front;// ����ָ��
	int rear;// ��βָ��
	int tag;// ��ʾ�����ǿջ��ǲ��գ�Լ��tag=0ʱ�ӿգ�tag=1ʱ�Ӳ���
} SqQueue;
 
/* ��ʼ������ */
void initQueue(SqQueue &qu) {
	qu.front=0;// ���׺Ͷ�βָ���غϲ�ָ��0
	qu.rear=0;
	qu.tag=0;// ��־λ��ʾ�ӿ�
}
 
/* �ж϶ӿ� */
int isQueueEmpty(SqQueue qu) {
	if(qu.tag==0&&qu.front==qu.rear) { // tag=0��ʾ�ӿ�
		return 1;// 1��ʾ�жϽ��Ϊ��
	} else {
		return 0;// 0��ʾ�жϽ��Ϊ�ǿ�
	}
}
 
/* �ж϶��� */
int isQueueFull(SqQueue qu) {
	if(qu.tag==1&&qu.front==qu.rear) { // �����б�־λtag���ʿ����ô˵�ʽ�ж��Ƿ����
		return 1;
	} else {
		return 0;
	}
}
 
/* ��� */
int enQueue(SqQueue &qu,int x) {
	if(isQueueFull(qu)==1) {
		return 0;
	} else {
		qu.rear=(qu.rear+1)%maxSize;// ����δ�������ƶ�ָ��
		qu.data[qu.rear]=x;// �ٴ���Ԫ��
		qu.tag=1;// ֻҪ���Ӿͽ�tag����Ϊ1����Ϊֻ�н��Ӳſ��ܻᷢ������
		return 1;
	}
}
 
/* ���� */
int deQueue(SqQueue &qu,int &x) {
	if(isQueueEmpty(qu)==1) { // ���ӿգ����ܳ���
		return 0;
	} else {
		qu.front=(qu.front+1)%maxSize;// ���Ӳ��գ����ƶ�ָ��
		x=qu.data[qu.front];// ��ȡ��Ԫ��
		qu.tag=0;// ֻҪ��Ԫ�س��ӣ��Ͱ�tag��Ϊ0����Ϊֻ�г��Ӳſ��ܶӿ�
		return 1;
	}
}
 
/* ��ӡ���� */
void printQueue(SqQueue qu) {
	printf("\n");
	while(qu.rear!=qu.front) {
		qu.front=(qu.front+1)%maxSize;
		printf("%d\t",qu.data[qu.front]);
	}
	printf("\n");
}
 
int main() {
	SqQueue qu;
	int nums[]= {1,2,3,4,5,6};
	int n=6;
	for(int i=0; i<n; i++) {
		int m=enQueue(qu,nums[i]);// �������е�Ԫ�����
	}
	printQueue(qu);// ��ӡ����
 
	int x;
	deQueue(qu,x);// ��Ԫ��1����
	printQueue(qu);// ��ӡ����
	return 0;
}
