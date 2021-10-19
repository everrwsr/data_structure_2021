#include <stdio.h>
void re(int a[],int n)
{
    int i, j, t;
    for (i = 0, j = n-1; i < j; i++, j--)
    {
        t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
}
int main()
{
    int a[10],i;
    printf("input 10 numbers:");
    for (i = 0; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    re(a,10);
    for (i = 0; i < 10; i++)
    {
        printf("%5d", a[i]);
    }
    return 0;
}


/*单链表原地逆置 
#include <stdio.h>
#include <stdlib.h>
#define ElemType char
typedef struct Node   
{ 
	ElemType data;
	struct Node  * next;
}Node, *LinkList;  


LinkList CreateFromTail()

{ 
	LinkList L;
	Node *r, *s;
	char c;
	int   flag =1; 
	L=(Node * )malloc(sizeof(Node));     
	L->next=NULL;	 		
	r=L;                
	while(flag)        
	{
		c=getchar();
		if(c!='$')
		{
			s=(Node*)malloc(sizeof(Node));
			s->data=c;
			r->next=s;
			r=s;
		}
		else
		{
			flag=0;
			r->next=NULL;   
		}
	}  
	return L;
} 

void  ReverseList(LinkList  L)
{ 
	Node *p,*q;
	p=L->next;
	L->next=NULL;
	while(p!=NULL)
	{ 
		q=p->next;    
		p->next=L->next;
		L->next=p;    
		p=q;          
	} 
}

int main()
{
	LinkList l;
	Node *p;
	printf("用尾插法建立单链表,请输入链表数据,以$结束!\n");
    l = CreateFromTail();
	printf("输入的单链表为:\n");
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
	ReverseList(l);
	printf("逆置后的单链表为:\n");
	p = l->next;
	while(p!=NULL)
	{
		printf("%c\n",p->data);
		p=p->next;
	}
}*/
