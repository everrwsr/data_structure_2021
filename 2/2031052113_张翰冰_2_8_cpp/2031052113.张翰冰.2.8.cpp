#include<stdio.h>
#include<stdlib.h> 
#define OK 1
#define ERROR 0
typedef int ElemType;
typedef int Status; 
typedef struct LNode
{
    ElemType data;  
    LNode *next;     
}LNode, *LinkList;
 
Status il(LinkList &L)
{   
    L = (LNode *)malloc(sizeof(LNode));
    L->next = NULL;
 
    return OK;
}
Status cl(LinkList &L, int e)
{   
    LinkList p = L;
    while(p->next)
        p = p->next;
    LinkList temp = (LinkList)malloc(sizeof(LNode));
    temp->data = e;
    temp->next = NULL;
    p->next = temp;
 
    return OK;
}
Status dis(LinkList &L)
{   
    LinkList p = L->next;
    int i = 0;
    while(p)
    {
        printf("%d\t", p->data);
        i ++;
        p = p->next;
    }
    return OK;
}
Status dme(LinkList &L, int mink, int maxk)
{  
    LinkList p, q, prev=NULL;
    if(mink > maxk) return ERROR;     
    p = L;
    prev = p;      
    p = p->next;  
 
    while(p && p->data < maxk)          
    {
        if(p->data <= mink)       
        {
            prev = p;              
            p = p->next;
         } 
        else                     
        { 
            prev->next = p->next;       
            q = p;
            p = p->next; 
            free(q);            
        }
    }
 
    return OK;
 
}
int main()
{
    int i;
    LinkList L;
 
    il(L);
 
    for(i=1;i<=10; i++)
        cl(L, i);
    
    dis(L);
 
    dme(L, 1, 4.5);
 
    printf("\n");
    dis(L);
 
    return OK;
}
