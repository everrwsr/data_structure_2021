#include <stdio.h>
#include <stdlib.h>
typedef struct linknode
{
	int data;
	struct linknode *next;
}LN;
void cre(LN *&l, int n, int a[])
{
	LN *p, *q;
	int i;
	l = (LN *)malloc(sizeof(LN));
	p = l;
	for(i=0; i<n; i++)
	{
		q = (LN *)malloc(sizeof(LN));
		q->data = a[i];
		p->next = q;
		p = q;
	}
	p->next = NULL;
}
void de(LN *&l)
{
	LN *p, *pre;    
	LN *maxp, *maxpre;
	pre = l;
	p = l->next;
	maxp = p;
	maxpre = pre;
	while(p != NULL)
	{
		if(maxp->data < p->data)   {
			maxp = p;
			maxpre = pre;
		}
		pre = p;    
		p = p->next;
	}
	maxpre->next = maxp->next;   
	free(maxp);
}
void dis(LN *l)
{
	LN *p;
	p = l->next;
	while(p != NULL)
	{
		printf("%d ",p->data);
		p = p->next;
	}
	printf("\n");
}

int main(void)
{
	int a[100];
	int i,n;
	LN *l, *l1, *l2;
	printf("请输入元素总个数:\n");
	scanf("%d",&n);
	printf("请输入元素:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	
	cre(l,n,a);
	de(l);
	printf("删除后l是:\n");
	dis(l);
	return 0;
}

