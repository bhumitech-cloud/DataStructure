#include <stdio.h>
#include <stdlib.h>
#define password 1337

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
				nextline(1);
				space(20);
				printf("Key not found!");
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
void display(struct  node *l,int totale)
{
	int n,i,j,pk,k=0,total=0;
	system("cls");
	if(l==NULL)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                               NO STOCKS AVAILABLE");
		printf("\n\n\n\n\n\n\n\n\n\n                                             Enter any key to return");
	}
	else
    {
        printf("\n");
        int num = 40;
        for(pk = 0 ; pk < num ; pk++)
        {
                printf(" ");
		}
        for(n=0;n<=38;n++)
        {
            if(n == 0 || n == 6 || n == 27 || n == 38)
            {
                printf("+");
            }
            else
                printf("-");
        }
        printf("\n");
        for(pk = 0 ; pk < num ; pk++)
        {
                printf(" ");
    	}
        printf("| ID  |        Name        |  Price   |\n");
      //  printf("\n              ");
        for(pk = 0 ; pk < num ; pk++)
                printf(" ");
        for(n=0;n<=38;n++)
        {
            if(n == 0 || n == 6 || n == 27 || n == 38)
            {
                printf("+");
            }
            else
                printf("-");
        }
        printf("\n");
        //for(int pk = 0 ; pk < num ; pk++)
        //        printf(" ");
        do
        {
            for(pk = 0 ; pk < num ; pk++)
                printf(" ");
            total=total+l->price;
            //k = 999;
            j=20-(strlen(l->name));
            printf("|%3d  |",k);
            printf("  %s",l->name);
            for(i=0;i<j-2;i++)
            {
                printf(" ");
            }
            printf("|  %6d  |\n",l->price);
            l=l->link;
            k++;
        }while(l!=NULL);
        //printf("\n");
        for(pk = 0 ; pk < num ; pk++)
                printf(" ");
        for(n=0;n<=38;n++)
        {
            if(n == 0 || n == 6 || n == 27 || n == 38)
            {
                printf("+");
            }
            else
                printf("-");
        }
        for(pk = 0 ; pk < num ; pk++)
                printf(" ");
        if(totale==1)
        {
            printf("\nTOTAL IS %d",total);
        }
        else if(totale==0)
        {
            printf("                                         Enter Any key");
            getch();
        }
    }
}
void admin_menu()
{
    int i,ch,pric;
    char name[20],condition;
    do{
        system("cls");
        printf("\n\n\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n\n\n\n         1--->View Products   \n\n         2--->Add Product  \n\n         3--->Remove Product \n\n         4--->Logout");
        printf("\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n         Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : display(list,0);
            break;
            case 2 : do{
                        system("cls");
                        printf("\n\n\n\n\n\n\n\n\n\n                           Name:");
                        scanf("%s",name);
                        printf("\n\n\n\n                           Price:");
                        scanf("%d",&pric);
                        insertEnd(pric,name,list);
                        printf("\n\n\n                           Succesfully inserted");
                        printf("\n\n\n\n\n                         Do you want to Add More?[y/n]:");
                        condition = getch();
                    }while(condition!= 'n');
                    break;
            case 3 : system("cls");
                    printf("\n\n\n\n\n\n\n\n                                Enter  the name of Item:");
                    scanf("%s",name);
                    deleteSpecific(name,list);
                    nextline(5);
                    space(15);
                    printf("Press Any Key");
                    getch();
                    break;
        }
    }while(ch<4);
}
void nextline(int x)
{
	int i;
    for(i=0 ; i<x ; i++)
    {
        printf("\n");
	}
}
void space(int x)
{
	int i;
    for(i = 0 ; i < x ; i++)
            printf(" ");
}
void login()
{
    int pass;
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n                                                     PASSWORD:");
    scanf("%d",&pass);
    if(pass== password)
    {
        admin_menu();
    }
    else
    {
        printf("\n\n\n\n\n\n\n                                          INVALID PASSWORD, PLEASE TRY AGAIN");
        getch();
    }
}
void insertProduct(int key)
{
    int i,pric;
    char name[20];
    struct node *p=list;
    for(i=0;i<key;i++)
    {
        p=p->link;
    }
    pric=p->price;
    strcpy(name,p->name);
    insertEnd(pric,name,cart);
}
void Add_cart()
{
    int product;
    char ch;
    do{
        system("cls");
        display(list,69);
        printf("\n                                        Enter the product ID:");
        scanf("%d",&product);
        insertProduct(product);
        printf("\n                                         Do you want to add another item to cart[y/n]");
        ch=getch();
    }while(ch != 'n');
}
void checkout()
{

}
void cust_login()
{
    int i,ch,c;
    char name[20];
    do{
        system("cls");
        printf("\n\n\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n\n\n\n         1--->View Products   \n\n         2--->View Cart \n\n         3--->Logout");
        printf("\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n         Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : display(list,69);
                    printf("\n\n\n\n         1--->Add to cart   \n\n         2--->back");
                    scanf("%d",&c);
                    if(c== 1)
                        Add_cart();
                    break;
            case 2 : display(cart,1);
            		printf("\n\n\n\n         1--->Checkout      \n\n         2--->delete Item \n\n         3-->back");
                    scanf("%d",&c);
                    if(c== 1)
                    	checkout();
                    else if(c==2)
                    {
                    	system("cls");
						printf("\n\n\n\n\n\n\n\n                                Enter  the name of Item:");
         	           	scanf("%s",name);
            	        deleteSpecific(name,cart);
                	    nextline(5);
                    	space(15);
                    	printf("Item Deleted");
						getch();
					}
                    break;
        }
    }while(ch<3);
}
void main_menu()
{
    int i,ch;
    do{
        system("cls");
        printf("\n\n\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n\n\n\n         1--->Admin login   \n\n         2--->Customer \n\n         3--->Exit");
        printf("\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n         Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : login();
            break;
            case 2 : cust_login();
            break;
        }
    }while(ch<3);

}
int main()
{
    system("color f0");
    main_menu();
    return 0;
}
