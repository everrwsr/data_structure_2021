#include <stdio.h>
#include <stdlib.h>
typedef  struct
{ 
	int  elem[100]; 
	int       last;    
}SeqList;
void dr(SeqList *L){
	int i=0,j=1;
	while (j<=L->last)
	{
		if(L->elem[i]==L->elem[j])
		j++;
		else
		{
			L->elem[i+1]==L->elem[j];
			i++;
			j++;
					
		}
	}
	L->last=i;
}
int main()
{
	SeqList *l;
	int r;
	int i;
	l=(SeqList*)malloc(sizeof(SeqList));
	printf("请输入线性表的长度:");
	scanf("%d",&r);
	l->last = r-1;
	printf("请输入线性表的各元素值:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	printf("线性表元素为:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
	dr(l);
	printf("\n");
	printf("调整后的线性表元素为:\n");
	for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}
}
