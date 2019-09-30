#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define password 1337

//node created
struct node
{
	char name[20];
	int price;
	struct node *link;
}*list=NULL,*cart=NULL;

//insertend function for linked list
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

//delete function for linked list
void deleteSpecific(char key[20],struct node *x)
{
	int n;
	struct node *p,*q;
	if(x==list)
	{
		p=list;
		q=list;
	}
	else
	{
		p=cart;
		q=cart;
	}
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

//sample list generated
void insert_list()
{
    char name[20];
    strcpy(name,"Lays_chips");
    insertEnd(20,name,list);
    strcpy(name,"Pepsi");
    insertEnd(45,name,list);
    strcpy(name,"Santoor_soap");
    insertEnd(30,name,list);
    strcpy(name,"Dettol_handwash");
    insertEnd(50,name,list);
    strcpy(name,"Cheese");
    insertEnd(100,name,list);
    strcpy(name,"T-shirt");
    insertEnd(500,name,list);
    strcpy(name,"Watch");
    insertEnd(1000,name,list);
    strcpy(name,"frozen food");
    insertEnd(200,name,list);
    strcpy(name,"Ice cream");
    insertEnd(100,name,list);
    strcpy(name,"pendrive");
    insertEnd(500,name,list);

}

int count(struct node *p)
{
    int i;
	if(p==NULL)
		return(0);
	else
	{
		for(i=0;p!=NULL;i++)
		{
			p=p->link;
		}
		return(i);
	}
}
//traverse linked list by id to delete items from list
void deleteid(int id,struct node *n)
{
    struct node *p=n;
    int i;
    for(i=0;i<id;i++)
    {

        p=p->link;
		if(p == NULL)
		{
			printf("\n\n\n\n\n\n                                    ID not found");
			return;
		}
    }
    deleteSpecific(p->name,n);
    printf("\n\n\n\n\n\n                                    Item deleted!");
}

void printLine()
{
	int n;
	nextline(1);
	space(40);
	for(n=0;n<=38;n++)
	{
		if(n == 0 || n == 6 || n == 27 || n == 38)
		{
			printf("+");
		}
		else
			printf("-");
	}
}

void displayList(struct  node *l)
{
	int i=0,j,k;
	system("cls");
	nextline(2);
	space(55);
    printf("VB SUPERMARKET");
    nextline(1);
	if(l==NULL)
	{

		printf(SPACE "EMPTY");
		printf("\n\n\n\n\n\n\n\n\n\n                                             Enter any key to return");
	}
    else
	{
		printLine();
		nextline(1);
		space(40);
		printf("| ID  |        Name        |  Price   |");
		printLine();
		while(l!=NULL)
		{
			nextline(1);
			space(40);
			printf("|%3d  |  %s",i,l->name);
			space(18-(strlen(l->name)));
			printf("|  %6d  |",l->price);
			l=l->link;
			i++;
		}
		printLine();
	}
}


void displayCart(struct  node *l)
{
	int i=0,j;
	float k=0;
	system("cls");
	nextline(2);
	space(53);
    printf("VB SUPERMARKET");
    nextline(1);
	if(l==NULL)
	{
	    nextline(5);
        space(55);
		printf("CART IS EMPTY!");
		return;
	}
    else
	{
		printLine();
		nextline(1);
		space(40);
		printf("| ID  |        Name        |  Price   |");
		printLine();
		while(l!=NULL)
		{
			nextline(1);
			space(40);
			printf("|%3d  |  %s",i,l->name);
			space(18-(strlen(l->name)));
			printf("|  %6d  |",l->price);
			k=k+l->price;
			l=l->link;
			i++;
		}
		printLine();
		nextline(1);
		space(40);
		printf("| TOTAL                    | %7.2f  |",k);
		printLine();
	}
}
//display function for linked list in tabular form
void displayCheckout(struct node *l)
{
	int i=0,j;
	float k=0,gst;
	system("cls");
	nextline(2);
	space(52);
    printf("VB SUPERMARKET");
    nextline(1);
	if(l==NULL)
	{
	    nextline(5);
        space(55);
		printf("CART IS EMPTY!");
		return;
	}
    else
	{
		printLine();
		nextline(1);
		space(40);
		printf("| ID  |        Name        |  Price   |");
		printLine();
		while(l!=NULL)
		{
			nextline(1);
			space(40);
			printf("|%3d  |  %s",i,l->name);
			space(18-(strlen(l->name)));
			printf("|  %6d  |",l->price);
			k=k+l->price;
			l=l->link;
			i++;
		}
		printLine();
		nextline(1);
		space(40);
		printf("| Sub Total                | %7.2f  |",k);
		printLine();
		gst=(k*2.5)/100;
		nextline(1);
		space(40);
		printf("| CGST                 2.5%%| %7.2f  |",gst);
		nextline(1);
		space(40);
		printf("| SGST                 2.5%%| %7.2f  |",gst);
		printLine();
		nextline(1);
		space(40);
		printf("| TOTAL                    | %7.2f  |",k+(2*gst));
		printLine();
	}
}
//admin page gui
void admin_menu()
{
    int i,id,ch,pric;
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
            case 1 : displayList(list);
                     getch();
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
                    displayList(list);
                    printf("\n\n\n\n                                Enter  Item ID:");
                    scanf("%d",&id);
                    deleteid(id,list);
                    nextline(5);
                    space(15);
                    getch();
                    break;
        }
    }while(ch<4);
}

//code for newline
void nextline(int x)
{
	int i;
    for(i=0 ; i<x ; i++)
    {
        printf("\n");
	}
}

//code for aesthetic spacing
void space(int x)
{
	int i;
    for(i = 0 ; i < x ; i++)
            printf(" ");
}

//code for admin login gui
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

//function to take id and insert in cart
void insertProduct(int key)
{
    int i,pric;
    char name[20];
    struct node *p=list;
    for(i=0;i<key;i++)
    {
        p=p->link;
		if(p == NULL)
		{
			printf("\n\n\n\n\n\n                              ID not found");
			return;
		}
    }
    pric=p->price;
    strcpy(name,p->name);
    insertEnd(pric,name,cart);
}

//loop for adding multiple elements in cart
void Add_cart()
{
    int product;
    char ch;
    do{
        system("cls");
        displayList(list);
        printf("\n                                        Enter the product ID:");
        scanf("%d",&product);
        insertProduct(product);
        printf("\n                                         Do you want to add another item to cart[y/n]");
        ch=getch();
    }while(ch != 'n');
}

//bill gui code
void checkout()
{
    system("cls");
    displayCheckout(cart);
    printf("\n\n\n\n                                        THANK YOU FOR SHOPPING WITH OUR STORE");
    getch();
    main_menu();
}

//customer login gui
void cust_login()
{
    int i,id,ch,c;
    char name[20];
    do{
        system("cls");
        printf("\n\n\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n\n\n\n         1--->View Products   \n\n         2--->View Cart(%d) \n\n         3--->Logout",count(cart));
        printf("\n\n\n\n         ");
        for(i=0;i<100;i++)
        {
            printf("=");
        }
        printf("\n         Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : displayList(list);
                    printf("\n\n\n\n         1--->Add to cart   \n\n         2--->back");
                    scanf("%d",&c);
                    if(c== 1)
                        Add_cart();
                    break;
            case 2 : displayCart(cart);
            		printf("\n\n\n\n         1--->Checkout      \n\n         2--->delete Item \n\n         3-->back");
                    scanf("%d",&c);
                    if(c== 1)
                    	checkout();
                    else if(c==2)
                    {
                    	system("cls");
                        displayList(cart);
                        printf("\n\n\n\n                                Enter  Item ID:");
                        scanf("%d",&id);
                        deleteid(id,cart);
                        nextline(5);
                        space(15);
                        getch();
                        break;
					}
                    break;
        }
    }while(ch<3);
}

//main homepage gui
void main_menu()
{
    int i,ch;
    do{
        system("cls");
        printf("\n\n\n\t\t\t\t\t\t  VB SUPERMARKET");
        printf("\n\n\n\n         ");
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
            case 3 : exit(0);
            break;
        }
    }while(ch<3);

}
int main()
{
    system("color f0");
    insert_list();
    main_menu();
    return 0;
}
