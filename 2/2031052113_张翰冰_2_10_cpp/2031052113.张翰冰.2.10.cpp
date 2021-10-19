#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define ElemType int
 
struct _lnklist {
    ElemType data;
    struct _lnklist* next;
};
 
typedef struct _lnklist Node;
typedef struct _lnklist* LinkList;
 
int is(LinkList L, int k, ElemType* p_ele) {
    int count = 1;
    LinkList tmp = L;
    int i = 0;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
        count++;
    }
    tmp = L;
    if (k > count||k<=0)
    {
        return 0;
    }
    else
    {
        for (i = 0; i < count - k; i++)
        {
            tmp = tmp->next;
        }
        *p_ele = tmp->data;
        return 1;
    }
}
 
LinkList cl(int m)
{
    LinkList Head = (LinkList)malloc(sizeof(Node) * 2);
    if (Head == NULL) return NULL;
    Head->data = m;
    Head->next = NULL;
    return Head;
}
void c(LinkList L, int n)
{
    LinkList Node = (LinkList)malloc(sizeof(Node) * 2);
    if (Node == NULL) return;
 
    while (L->next != NULL)
    {
        L = L->next;
    }
 
    L->next = Node;
    Node->data = n;
    Node->next = NULL;
}
 
void dis(LinkList L)
{
    while (L->next != NULL)
    {
        printf("%d ", L->data);
        L = L->next;
    }
    printf("%d ", L->data);
    printf("\n");
}
 
 
int main()
{
    int k = 0;
    printf("������������ҵڼ�λ�����֣���������:>\n");
    scanf("%d", &k);
    ElemType p_ele;
 
    printf("������Ӵ�С���������س�������һ�����֣���ctrl+z��������:>\n");
    int m = 0;
    scanf("%d", &m);
    LinkList L = cl(m);
    if (L == NULL) return -1;
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        c(L, n);
    }
    dis(L);
    if (is(L, k, &p_ele))
    {
        printf("�ҵ��ˣ�%d", p_ele);
    }
    else 
    {
        printf("û�ҵ�");
    }
 
    return 0;
}

