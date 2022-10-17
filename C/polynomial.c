#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int coef;
	int exp;
	struct node *link;
}poly;
poly *p1, *p2,*p3;

poly* insert(poly *s, poly *temp)
{
	poly *ptr;
	if(s==NULL)
	 s=temp;
	else
	{
		ptr=s;
		while(ptr->link!=NULL)
		 ptr=ptr->link;
		 
		ptr->link=temp;
	}
	return s;
}
poly* add(poly *p1, poly *p2, poly *p3)
{
	poly *temp;
	while(p1!=NULL && p2!=NULL)
	{
		temp=(poly*)malloc(sizeof(poly));
		if(p1->exp>p2->exp)
		{
			temp->coef=p1->coef;
			temp->exp=p1->exp;
			temp->link=NULL;
			p3=insert(p3,temp);
			p1=p1->link;
		}
		else if(p1->exp<p2->exp)
		{
			temp->coef=p2->coef;
			temp->exp=p2->exp;
			temp->link=NULL;
			p3=insert(p3,temp);
			p2=p2->link;
		}
		else
		{
			temp->coef=p1->coef+p2->coef;
			temp->exp=p2->exp;
			temp->link=NULL;
			p3=insert(p3,temp);
			p1=p1->link;
			p2=p2->link;
		}
	}
	if(p1==NULL)
	 p3=insert(p3,p2);
	else
	 p3=insert(p3,p1);
	 
	 return p3;
}
void display(poly *s)
{
	poly *ptr;
	if(s==NULL)
	 printf("\n List is Empty ");
	else
	{
		ptr=s;
		while(ptr->link!=NULL)
		{
			printf(" %dX^%d + ",ptr->coef,ptr->exp);
			ptr=ptr->link;
		}
		printf(" %dX^%d  ",ptr->coef,ptr->exp);
		printf("\n");
	}
}
void main()
{
	int t1,i,t2;
	poly *temp;
	p1=NULL;
	p2=NULL;
	p3=NULL;
	printf("\n Enter the term : ");
	scanf("%d",&t1);
	for(i=1;i<=t1;i++)
	{
		temp=(poly*)malloc(sizeof(poly));
		printf("Enter coef & exp : ");
		scanf("%d%d",&temp->coef,&temp->exp);
		temp->link=NULL;
		
		p1=insert(p1,temp);
	}
	printf("\n Enter the term for second : ");
	scanf("%d",&t2);
	for(i=1;i<=t2;i++)
	{
		temp=(poly*)malloc(sizeof(poly));
		printf("Enter coef & exp : ");
		scanf("%d%d",&temp->coef,&temp->exp);
		temp->link=NULL;
		
		p2=insert(p2,temp);
	}
	
	p3=add(p1,p2,p3);
	display(p1);
	display(p2);
	display(p3);
	
	
}
