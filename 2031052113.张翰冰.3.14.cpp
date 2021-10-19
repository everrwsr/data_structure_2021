//3.14,����3.11����С���� 
//����⣬�о����Ǽ򵥵Ĳ�ӣ�Ȼ��һ����ɾ�� 
#include "stdio.h"
#include "stdlib.h"
struct dnode 
{
	int data;
	dnode *next;
 	dnode *av;
};
void cquene(dnode *&L,int a[],int n)
{
	dnode *temp,*node;
	L=(dnode *)malloc(sizeof(dnode));
	L->next=NULL;
	L->av=NULL;
	temp=L;
	for(int i=0; i<n; i++) 
	{ 
		node=(dnode *)malloc(sizeof(dnode)); 
		node->data=a[i];
		temp->next=node;
		temp=node;
	}
	temp->next=L;
	L->av=temp;
}
void display(dnode *L) 
{
	dnode *temp;
	temp=L->next;
	printf("\n");
	while(temp!=L) 
	{
		printf("%d\t",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void inquene(dnode *&av,int x) 
{
	dnode *newNode=(dnode *)malloc(sizeof(dnode));
	newNode->data=x;
	newNode->next=av->next;
	av->next=newNode;
	av=newNode;
}

int deQueue(dnode *&av,int &x) 
{
	dnode *tempDelNode;
	if(av->next==av) 
	{
		return 0;
	} 
	else 
	{
		tempDelNode=av->next->next;
		x=tempDelNode->data;
		av->next->next=tempDelNode->next; 
		if(tempDelNode==av) 
		{
			av=av->next;
		}
		free(tempDelNode);
		return 1;
	}
}
 
int main()
{
	dnode *la,*t1,*t2;
	int a[]= {0};
	cquene(la,a,1);
	printf("��ʼ����Ԫ��Ϊ��\n");
	display(la);
	inquene(la->av,4);
	inquene(la->av,5);
	inquene(la->av,6);
	printf("��Ӻ����Ԫ��Ϊ��\n");
	display(la);
	int x=0,y=1,z=2,k=3;	
	deQueue(la->av,x);
	deQueue(la->av,y);
	deQueue(la->av,z);
	deQueue(la->av,k);
	printf("ɾ�������Ԫ��Ϊ��\n");
	display(la);
	return 0;
}
