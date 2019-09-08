#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	char name[20];
	int price;
	struct node *link;
}*list=NULL,*cart=NULL;
void insertEnd(int x,char y[20],struct node *z)
{
	struct node *n,*p;
	n=(struct node*)malloc(sizeof(struct node));
	strcpy(n->name,y);
	n->price=x;
	n->link=NULL;
	if(z==NULL)
	{
	    if(z==list)
        {
            list=n;
        }
        else
        {
            cart=n;
        }
	}
	else
	{
		p=z;
		while(p->link != NULL)
		{
			p=p->link;
		}
		p->link=n;
	}
}
void deleteSpecific(char key[20],struct node *x)
{
	int n;
	struct node *p=list,*q=list;
	if(x==NULL)
	{
		printf("\nLL is empty");
		return;
	}
	else
	{
		if(p->link==NULL)
		{
			if((strcmp(key,p->name))!=0)
			{
				printf("\nKey not found!");
				return;
			}
			else
			{
				if(x==list)
				{
					list=NULL;
				}
				else
				{
					cart=NULL;
				}
				printf("\nItem Deleted");
				return;
			}
		}
		else
		{
			while(p!= NULL)
			{
				if((strcmp(p->name,key))==0)
				{
					if(p==x)
					{
						if(x==list)
						{
							list=p->link;
						}
						else
						{
							cart=p->link;
						}
						return;
					}
					q->link=p->link;
					return;
				}
				q=p;
				p=p->link;
			}
			if(p==NULL)
			{
				printf("\nKey not found");
			}
		}
	}
}
void traverse(struct node *x)
{
	struct node *p=x;
	if(x==NULL)
	{
		printf("\n LL is Empty");
	}

	while(p!=NULL)
	{
		printf("\n%s   %d",p->name,p->price);
		p=p->link;
	}
}
void display(struct  node *l)
{
	int n,i,j,k=1,total=0;
	system("cls");
	if(l==NULL)
	{
		printf("\nLL is Empty");
	}

	for(n=0;n<=30;n++)
	{
		printf("-");
	}
	printf("\nID Name                Price\n");
	for(n=0;n<=30;n++)
	{
		printf("-");
	}
	while(l!=NULL)
	{
	    total=total+l->price;
		j=20-(strlen(l->name));
		printf("\n%d  ",k);
		printf("%s",l->name);
		for(i=0;i<j;i++)
		{
			printf(" ");
		}
		printf("%d",l->price);
		l=l->link;
		k++;
	}
	printf("\nTOTAL IS %d",total);
	getch();
}
void main()
{
	int ch=0,s,k;
	char Name[20];
	printf("\nEnter your choice");
	do
	{
		printf("\n1:INSERT\n2:DELETE\n3:TRAVERSE\n4:DISPLAY");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("\nEnter the name to be inserted:");
				scanf("%s",&Name);
				printf("\nEnter the price");
				scanf("%d",&s);
				insertEnd(s,Name,list);
                break;
			case 2: printf("\nEnter the name of the item to be deleted:");
				scanf("%s",&Name);
				deleteSpecific(Name,list);
				break;
			case 3: traverse(list);
				break;
			case 4: display(list);
				break;
		}
	}while(ch<4);
}
