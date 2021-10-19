# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define SRAND 501 
# define M 60  
typedef struct LB{    
	int data;   
	struct LB* Q; 
}LB;
LB *Insert(LB *head,int DATA);  
LB *HB(LB *A,LB *B);
int main(){
    int i;
    LB *P=NULL,*S=NULL,*T=NULL,*X,*Y;
	srand(time(NULL));
	for(i=0;i<M;i++)
	{
		P=Insert(P,rand()%SRAND);
		S=Insert(S,rand()%SRAND);
	}
    X=P;Y=S;
    printf("PÁ´±í<ÉýÐò>:\n");
	for(i=0;i<M;i++)
	{
		printf("%03d%c",X->data,(i+1)%10?' ':'\n');
	   X=X->Q;
	}
	printf("SÁ´±í<ÉýÐò>:\n");
	for(i=0;i<M;i++)
	{
		printf("%03d%c",Y->data,(i+1)%10?' ':'\n');
	   Y=Y->Q;
	}
	T=HB(P,S);
	printf("ºÏ²¢ºóµÄTÁ´±í<½µÐò>:\n");
	for(i=0;i<2*M;i++)
	{
		printf("%03d%c",T->data,(i+1)%10?' ':'\n');
	   T=T->Q;
	}
	return 0;
}
LB *HB(LB *A,LB *B)
{
	LB *pa=A,*pb=B,*pre=NULL,*C,*q;
	while(pb||pa)  
	{
		if(pb&&pa&&pa->data<pb->data||!pb)
		{               
			C=pa;       
			q=pa->Q;    
			pa->Q=pre;    
			pa=q;         
		}
		else         
		{
			C=pb;
			q=pb->Q;
			pb->Q=pre;
			pb=q;             
		}
	   pre=C;    
	}
	return C; 
}
LB *Insert(LB *head,int DATA)  
{
	LB *R=head,*S=head,*temp=NULL;
	S=(LB *)malloc(sizeof(LB));
	if(!S)  
	{
		printf("ÉêÇëÄÚ´æÊ§°Ü,³ÌÐòÍ£Ö¹ÔËÐÐ!\n");
		getchar();
		exit (0);
	}
	S->Q=NULL;  
	S->data=DATA;  
	if(!head)    
		head=S;
	else        
	{
		while(R->data<DATA&&R->Q) 
		{
			temp=R;           
			R=R->Q;    
		}
		if(R->data>=DATA)    
		{
			if(R==head)         
			{
				S->Q=head;     
				head=S;    
			}
			else
			{
				R=temp;     
				S->Q=R->Q;
				R->Q=S;
			}
		}
		else            
			R->Q=S;
	}
	return head;     
}
