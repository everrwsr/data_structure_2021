#include <stdio.h>
#include <malloc.h>
typedef struct NODE
{
int data;
struct NODE *next;
}List;
void Print(List *head)
{
int i,j=0;
List *p;
p=head->next;
while(j!=5)
{
for(i=0;i<10;i++)
{
printf("%d ",p->data);
p=p->next;
}
j++;
}
printf("......");
}
void Dels(List *s)
{
List *p,*q;;
p=s;
while(p->next->next!=s)
{
p=p->next;
}
q=p->next;
p->next=s;
free(q);
}
main()
{
int i;
List *p,*q,*head,*s;
head=q=(List *)malloc(sizeof(List));
for(i=0;i<10;i++)
{
p=(List *)malloc(sizeof(List));
p->data=i;
q->next=p;
if(i==5)s=p;
q=p;
}
q->next=head->next;
printf("未删除s前驱结点的循环列表\n");
Print(head->next);
Dels(s);
printf("\n删除s前驱结点后的循环列表\n");
Print(head->next);
}
