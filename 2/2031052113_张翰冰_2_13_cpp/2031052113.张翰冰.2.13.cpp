# include <stdio.h>
# include <stdlib.h>

typedef char ElemType;
typedef struct Node
{
	ElemType data;
	struct Node *next;
}LNode,  *LinkList;

void cl(LinkList &L,int m)
{
	int i;
	LinkList p,s;
	L=(LinkList)malloc(sizeof(LNode));
	L->next=NULL;
	p=L;
	if(m!=0)
		printf("请依次输入%d个数据元素：\n",m-1);
	for(i=0;i<m;i++)
	{
		s=(LinkList)malloc(sizeof(LNode));
		scanf("%c",&s->data);
		p->next=s;
		p=p->next;
	}
	p->next=NULL;
}
void cir(LinkList &L)
{
	LinkList p;
	int i;
	p=L;
	for(i=0;p->next;i++)
		p=p->next;
	p->next=L;
}
void dis(LinkList L)
{
	LinkList p;
	int i;
	p=L->next;
	if(!p)
		printf("输出链表失败!\n");
	for(i=0;p;i++)
	{
		printf("%c",p->data);
		p=p->next;
	}
	printf("\n");
}
void li(LinkList &L,int i,ElemType e)
{
	LinkList s,p;
	int j;
	p=L;
	for(j=0;p && j<i-1;j++)
		p=p->next;
	if(!p || j>i-1)
		printf("i值错误\n");
	s=(LinkList)malloc(sizeof(LNode));
	s->data=e;
	s->next=p->next;
	p->next=s;
}
void cl(LinkList L,LinkList &A,LinkList &B,LinkList &C)
{
	LinkList p;
	int i=1,j=1,k=1;
	p=L->next;
	while(p)
	{
		if( ( (p->data)>64&&(p->data)<91) || ((p->data)>96&&(p->data)<123))
		{
			li(A,i++,p->data);
		}
		else if((p->data)>47 && (p->data)<58)
		{
			li(B,j++,p->data);
		}
		else
		{
			li(C,k++,p->data);
		}
		p=p->next;
	}
}
int main()
{
	LinkList L,A,B,C;
	int n;
	printf("请输入数据元素个数: ");
	scanf("%d",&n);
	cl(L,n+1);
	cl(A,0);
	cl(B,0);
	cl(C,0);
	cl(L,A,B,C);
	printf("输出字母:\n");
	dis(A);
	printf("输出数字:\n");
	dis(B);
	printf("输出符号:");
	dis(C);
	cir(A);
	cir(B);
	cir(C);
	return 0;
}

