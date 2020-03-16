#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int itemId();
void admin();
void newitems();
void displayitems();
void user();
char fitems[]={"Items.txt"};
char fdetails[]={"details.txt"};
char fbill[]={"bill.txt"};
struct items
 { int id;
   char name[20];
   int price;
   int qty;
 };
struct bill
 { int iid;
   char iname[20];
   int qty;
   int iprice;
 };
struct details
 { int num;
 };
struct node
 {
   int id;
   char name[20];
   int price;
   int qty;
   int bill;
   struct node*link;
 };
struct node *first=NULL;
void additems();
int deleteitems();
int bill();
int total(struct node *first);
struct items finditems(int id);
void insertcart(int id);
int main()
 { FILE *fp;
   int ch;
   //clrscr();
   printf("\n\t||------------------------------------||\n");
   printf("\t||--------WELCOME TO THE STORE--------||\n");
   printf("\t||____________________________________||\n");
   while(1)
    {
      printf("\n--ENTER YOUR CHOICE--\n 1.Admin \n 2.User\n 3.Exit\n");
      scanf("%d",&ch);
      switch(ch)
       { case 1:admin();
		break;
	 case 2:user();
		break;
	 case 3:exit(0);
		break;
       }
      getch();
    }
 }
int itemId()
 { FILE *fp;
    int val=0;
    fp=fopen("itemID.txt","r");
    if(fp==NULL)
      { fp=fopen("itemID.txt","w");
	fprintf(fp,"%d",0);
	fclose(fp);
	fp=fopen("itemID.txt","r");
      }
    fscanf(fp,"%d",&val);
    fclose(fp);
    fp=fopen("itemID.txt","w");
    fprintf(fp,"%d",val+1);
    fclose(fp);
    return val+1;
 }
void admin()
 {  int ch;
    int back=0;
    //clrscr();
    while(1)
     {
       printf("\n\t--------------------------\n");
       printf("\t\-----ONLY BY ADMINS------\n");
       printf("\t--------------------------\n");
       printf("\n\t-----------------------------\n");
       printf("\t\n1.Newitems 2.Displayitems 3.Back\n");
       printf("\t-----------------------------------\n");
       printf("\t---SELECT OPTION---\n");
       scanf("%d",&ch);
       switch(ch)
	{ case 1:newitems();
		 break;
	  case 2:displayitems();
		 break;
	  case 3:back=1;
		 break;
	}
	if(back==1)
	  { //clrscr();
	  break;
	  }
	else
	 {
       getch();
       //clrscr();
     }
      }
 }
void newitems()
 {  FILE *fp;
    struct items t1;
    //clrscr();
    fp=fopen(fitems,"a");
    t1.id=itemId();
    printf("Enter the items name\n");
    scanf("%s",&t1.name);
    printf("Enter the price\n");
    scanf("%d",&t1.price);
    printf("Enter the quantity\n");
    scanf("%d",&t1.qty);
    fwrite(&t1,sizeof(t1),1,fp);
    fclose(fp);
    fflush(stdin);
 }
void displayitems()
 {  FILE *fp;
    struct items t;
    int id;
    //clrscr();
    fp=fopen(fitems,"r");
    printf("\n\t  |||-----------------------|||\n");
    printf("\t  ///-----ITEMS IN MARKET-----\\\n");
    printf("\n\tID\t NAME\t QUANTITY\t PRICE\n");
    printf("\t--\t ----\t --------\t -----\n");
    while(1)
     { fread(&t,sizeof(t),1,fp);
       if(feof(fp))
	 break;
       else
       { printf("\t%d\t",t.id);
	printf("%s\t",t.name);
	printf("\t%d\t",t.qty);
	printf("%d\t\t\n",t.price);
       }
     }
     printf("\t__________________________\n");
     fclose(fp);
 }
void user()
 {  int ch,n,back=0;
    FILE *fp;
    struct details t7;
    fp=fopen(fdetails,"a");
    printf("Enter your phone no.\n");
    scanf("%d",&n);
    fwrite(&t7,sizeof(t7),1,fp);
    fclose(fp);
    //clrscr();
     printf("\n\t||\\-----WELCOME TO OUR SHOP----//||\n");
     printf("\t||----------------------------------||\n");
     printf("\n\t/|--------HOW CAN WE HELP YOU?------|\n");
     printf("\t|||________________________________|||");
    while(1)
     {
	   printf(" \n1.Add_items\n2.Delete_items\n3.Bill\n4.Back\n");
	   printf("\t\--- SELECT YOUR WISH ---/\n");
	   scanf("%d",&ch);
	   switch(ch)
	    { case 1:additems();
		     break;
	      case 2:deleteitems();
		     break;
	      case 3:bill();
		     break;
	      case 4:back=1;
		     break;
	     }
	   if(back==1)
	    {//clrscr();
	     break;
	    }
	   else
	   { getch();
	   //clrscr();
	   }
    }
 }
void additems()
 {
    struct node *temp,*p;
    int id,z,y,price;
    char name;
    while(1)
     { //clrscr();
       printf("\n\tDo you want to purchase?\n\t[y=1/n=0]\n");
       scanf("%d",&z);
       if(z==1)
	{ FILE *fp,*fp1;
	  struct bill t1;
	  struct items t2;
	  fp=fopen(fbill,"a");
	  //clrscr();
	  displayitems();
	  p=(struct node*)malloc(sizeof(struct node));
	  fp1=fopen("items.txt","r");
	  printf("Enter the item-ID you need\n");
	  scanf("%d",&id);
	  t2=finditems(id);
	  t1.iid=t2.id;
	  p-> id=t1.iid;
	  scanf("%d",&p->id);
	  scanf("%s",&(p->name));
	  printf("Enter the quantity\n");
	  scanf("%d",&(p->qty));
	  t1.iprice=t2.price;
	  p-> price=t1.iprice;
	  p->link=NULL;
	  if(first==NULL)
	    { first=p;
	      printf("\t--Product added--");
	    }
	  else
	    { temp=first;
	      while(temp->link!=NULL)
	       { temp=temp->link;
		}
	      temp->link=p;
	      printf("\t--Product added--");
	    }
	  fclose(fp1);
	  fclose(fp);
	}//clrscr();
     printf("\n\tWant to continue?[y=1/n=0]\n");
     scanf("%d",&y);
     if(y==0)
      {break;
      }
     }
 }
int deleteitems()
 { struct node *temp=first,*prev=NULL;
   int Did;
   bill();
   printf("\n\n\t--Enter the item-ID to be removed\n");
   scanf("%d",&Did);
    { if(temp->id==Did)
       {
	prev=temp;
	first=prev->link;
	}
      else
       {
	while(temp->id!=Did)
	 {
	    prev = temp;
	    temp = temp->link;
	 }
	 prev->link = temp->link;
       }
   }   free(temp);
      printf("\t---Item removed : %s---",temp->name);

   return 0;
 }
int bill()
 { struct node *temp;
   //clrscr();
   temp=first;
   if(temp==NULL)
    {
     printf("\t-------LIST IS EMPTY---------\n");
    }
   else
    {
     printf("\n\t________BILLING__________\n");
     printf("\n\t-----Items in the list are-----\n");
     printf("\n-item -- quantityXprice -- cost\n");
     while(temp!=NULL)
      {
	 printf("\n%d.%s\t %dX%d\n",temp->id,temp->name,temp->qty,temp->price);
	 temp->bill=(temp->qty)*(temp->price);
	 printf("\t\t\t=%d",temp->bill);
	 temp=temp->link;
       }
      printf("\n-----------------------------");
     printf("\nTotal cost::\t%d",total(first));
     } return 0;
 }
int total(struct node *first)
 { int total=0;
   while(first!=NULL)
    {
      total+=first->bill;
      first=first->link;
    }
   return total;
 }
struct items finditems(int id)
 {
   FILE *fp;
   struct items t1;
   fp=fopen(fitems,"r");
   while(1)
    {
      fread(&t1,sizeof(t1),1,fp);
      if(feof(fp))
	{
	  break;
	}
      if(id==t1.id)
	{
	 insertcart(id);
	 break;
	}
     }
   fclose(fp);
   return t1;
 }
void insertcart(int id)
 {
    FILE *fp;
    struct items t;
    int found=0;
    fp=fopen(fitems,"r");
    while(1)
     {
       fread(&t,sizeof(t),1,fp);
       if(feof(fp))
	  break;
       if(t.id==id)
	 { found=1;
	     break;
	 }
      }
       if(found==0)
	 { printf("out of stock");
	 }
       else
	  { printf("enter the item name\n");
	   }
    fclose(fp);
 }
