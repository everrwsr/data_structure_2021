#include <stdio.h>
#include <stdlib.h>
#define elemtype int
int num=0;
typedef struct cNode
{
    elemtype data1;
    elemtype data2;
    struct cNode *next;
}cNode;
typedef cNode* Circlelist;
void in(Circlelist *L)
{
    *L=(Circlelist)malloc(sizeof(cNode));
    (*L)->next=*L;
}
void cl(Circlelist L)
{
    int i=0;
    cNode *r,*s;
    r=L;
    elemtype a,b;
    while(i!=num)
    {
        scanf("%d%d",&a,&b);
        s=(cNode*)malloc(sizeof(cNode));
        s->data1=a;
        s->data2=b;
        r->next=s;
        r=s;
        i++;
    }
    r->next=L;
}
void cfh(Circlelist L)
{
    int i=0;
    cNode *s;
    elemtype a,b;
    while(i!=num)
    {
        scanf("%d%d",&a,&b);
        s=(cNode*)malloc(sizeof(cNode));
        s->data1=a;
        s->data2=b;
        s->next=L->next;
        L->next=s;
        i++;
    }
}
void dv(Circlelist L)
{
    cNode *q,*p,*rear;
    int i=0;
    rear=L;q=L->next;p=L;
    while(rear->next!=L)
    {
        rear=rear->next;
        if(rear->data2%2==0)
        {
            i++;
        }
    }
    while(i!=0)
    {
        if(q->data2%2==0)
        {
            p->next=q->next;
            q->next=L;
            rear->next=q;
            rear=q;
            q=p->next;
            i--;
        }
        else
        {
            p=p->next;
            q=p->next;
        }
    }}
void vi(Circlelist L)
{
    cNode *p;
    p=L->next;
    printf("�����ζ���ʽΪ��\n");
    int flog=0;
    while((p->data2)%2!=0)
    {
        if(flog==0)
        {
            printf("%dx^%d",p->data1,p->data2);
        }
        else
        {
            printf("+%dx^%d",p->data1,p->data2);
        }
        p=p->next;
        flog++;
    }
    printf("\n");
    printf("ż���ζ���ʽΪ��\n");
    while(p!=L)
    {
        printf("%dx^%d",p->data1,p->data2);
        if(p->next!=L)
        {
            printf("+");
        }
        p=p->next;
    }
    printf("\n");
}
int main()
{
    Circlelist L;
    in(&L);
    printf("��������--����ʽ���ܸ�����\n");
    scanf("%d",&num);
    printf("��ʹ��ͷ�巨������--'H'\n");
    printf("��ʹ��β�巨������--��T��\n");
    char I;scanf("%s",&I);
    printf("����������ÿ������ʽ��ϵ����ָ����\n");
    if(I=='H')
    {
        cfh(L);
    }
    else
    {
        cl(L);
    }
    dv(L);
    vi(L);
    return 0;
}

