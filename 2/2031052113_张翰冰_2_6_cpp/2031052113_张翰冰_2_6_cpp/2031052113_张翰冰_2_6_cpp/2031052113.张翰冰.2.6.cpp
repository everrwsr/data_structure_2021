#include <stdio.h>
#include <stdlib.h>
typedef  struct
{ 
	int  elem[100]; 
	int       last;    
}SeqList;
void as(SeqList  *L)
{
	int i=0,j=L->last;
	int temp;
	while(i<j)
	{  
		while(L->elem[i]%2 != 0)
			i++;  
	    while(L->elem[j]%2 == 0)
			j--;     
		if(i<j)
		{
			temp = L->elem[i];
			L->elem[i]= L->elem[j];
			L->elem[j]=temp;
		}
	}
	
}
void display(SeqList *l)
{
	int i;
		for(i=0; i<=l->last; i++)
	{
		printf("%d  ",l->elem[i]);
	}	
}
int  main()
{
	SeqList *l;
	int r;
	int i;
	l=(SeqList*)malloc(sizeof(SeqList));
	printf("���������Ա�ĳ���:");
	scanf("%d",&r);
	l->last = r-1;
	printf("���������Ա�ĸ�Ԫ��ֵ:\n");
	for(i=0; i<=l->last; i++)
	{
		scanf("%d",&l->elem[i]);
	}
	printf("���Ա�Ԫ��Ϊ:\n");
	display(l);
	as(l);
	printf("\n");
	printf("����������Ա�Ԫ��Ϊ:\n");
	display(l);
}
