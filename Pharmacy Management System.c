#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
//global structs

struct CUSTOMER{
		char name[20];
		int age;
		char phone[20];
	};
struct ITEM{
	char productname[40],productcomp[40];
	int price;
	int Qnt;
};
//bill and daily report
int dailyrep();
int billgenerator();
//record funcs
int Addrecord();
int Viewrecord();
int Modifyrecord();
int Deleterecord();
int Searchrecord();
//item funcs
int Additem();
int Viewitem();
int Modifyitem();
int Deleteitem();
int Searchitem();
//Design funcs
void gotoxy(int x,int y);
void loading(int N);
int mainmenu();
int recordMenu();
int stockMenu();
int recordsScreen();
int stockScreen();

int main(){
	int i;
	
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(15,8);
	for(i=0;i<30;i++)
    	printf("%c",219);
    gotoxy(15,9);
    printf("%c%cPharmacy Management System%c%c",219,219,219,219);
    gotoxy(15,10);
	for(i=0;i<30;i++)
    	printf("%c",219);	
    loading(10000000);
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	mainmenu();
	return 0;
}
int mainmenu(){
	system("cls");
	int option;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	int i;
	gotoxy(15,3);
	for(i=0;i<15;i++)
    	printf("%c",219);
    gotoxy(15,4);
    printf("%c%c Main Menu %c%c",219,219,219,219);
    gotoxy(15,5);
	for(i=0;i<15;i++)
    	printf("%c",219);
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	printf("%c",219);
    gotoxy(9,8);
    printf("%c 1 : Customer Records    %c",219,219);
    gotoxy(9,9);
    printf("%c 2 : Stock Management    %c",219,219);
    gotoxy(9,10);
    printf("%c 3 : Bill Generator      %c",219,219);
    gotoxy(9,11);
    printf("%c 4 : Daily Report        %c",219,219);
    gotoxy(9,12);
    printf("%c  Any other key to exit  %c",219,219);
    gotoxy(9,13);
    printf("%c     Choose an option:   %c",219,219);
    gotoxy(9,15);
	for(i=0;i<27;i++)
    	printf("%c",219);
	gotoxy(9,14);
	printf("%c                         %c",219,219);
	gotoxy(19,14);
	scanf("%d",&option);
	switch(option)
	{
		case 1:
		{
		system("cls");
		if(recordsScreen()==0){
			puts("\n\nPress any key to go back.");
			getch();
		}
		mainmenu();
		break;
		}
	case 2:
		{
		system("cls");
		if(stockScreen()==0){
			puts("\n\nPress any key to go back.");
			getch();
		}
		mainmenu();
		break;
		}
	case 3:
		{
		system("cls");
		billgenerator();
		puts("\n\nPress any key to go back.");
		getch();
		mainmenu();
		break;
		}
	case 4:
		{
		system("cls");
		dailyrep();
		puts("\n\nPress any key to go back.");
		getch();
		mainmenu();
		break;
		}
	default:
		{
		puts("\n\n            Press any key to Exit.");
		getch();
		return 0;
		}
	}
	return 0;
    
}
int recordsScreen(){
	int i;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(20,8);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(20,9);
    printf("%c%cCustomer Records%c%c",219,219,219,219);
    gotoxy(20,10);
	for(i=0;i<20;i++)
    	printf("%c",219);	
    loading(10000000);
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	if(recordMenu()==1);
		return 1;
	return 0;
}
int recordMenu(){
	system("cls");
	int option;
    time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	int i;
	gotoxy(13,3);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(13,4);
    printf("%c%cCustomer Records%c%c",219,219,219,219);
    gotoxy(13,5);
	for(i=0;i<20;i++)
    	printf("%c",219);
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	printf("%c",219);
//
	gotoxy(9,8);
    printf("%c 1 : Add Record.         %c",219,219);
    gotoxy(9,9);
    printf("%c 2 : View Record.        %c",219,219);
    gotoxy(9,10);
    printf("%c 3 : Search Record.      %c",219,219);
    gotoxy(9,11);
    printf("%c 4 : Modify Record.      %c",219,219);
    gotoxy(9,12);
    printf("%c 5 : Delete Record.      %c",219,219);
    gotoxy(9,13);
    printf("%c  Any other key to exit  %c",219,219);
    gotoxy(9,14);
	printf("%c Choose an option:       %c",219,219);
//
	gotoxy(9,16);
	for(i=0;i<27;i++)
    	printf("%c",219);
	gotoxy(9,15);
	printf("%c                         %c",219,219);
	gotoxy(19,15);
//
	scanf("%d",&option);

	switch(option){
	case 1:
		{
		system("cls");
		Addrecord();
		recordMenu();
		break;
		}
	case 2:
		{
		system("cls");
		Viewrecord();
		puts("\n\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 3:
		{
		system("cls");
		Searchrecord();
		puts("\n\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 4:
		{
		system("cls");
		Modifyrecord();
		puts("\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	case 5:
		{
		system("cls");
		Deleterecord();
		puts("\nPress any key to go back.");
		getch();
		recordMenu();
		break;
		}
	default:
		{
		fflush(stdin);
		puts("\n\n            Press any key to Exit.");
		getch();
		return 1;
		}
	}
	return 0;
}
int Addrecord(){
	int flag=0;
	struct CUSTOMER c1,temp;
    FILE *fptr,*ft;
    fptr=fopen("Customers.txt","a+");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (1)
    {
    	system("cls");
        printf("\nEnter Name: ");
        fflush(stdin);
        gets(c1.name);
        c1.name[0]=toupper(c1.name[0]);
        
        ft=fopen("Customers.txt","r");
        if(ft==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
    	while(fread(&temp,sizeof(temp),1,ft)==1){
    		if(strcmp(c1.name,temp.name)==0){
				flag=1;
			}
		}
		fclose(ft);
		if(flag==1){
			printf("\nThis Name already exists can't add again!\nPress any key to go back");
			getch();
			break;
		}
        while(1){
        printf("\nEnter age: ");
        scanf("%d",&c1.age);
        if(c1.age>10&&c1.age<100)
        	break;
        else
        	printf("Age must be greater than 10 and less than 100");
		}
        printf("\nEnter Phone Number: ");
        fflush(stdin);
        gets(c1.phone);
        
        fwrite(&c1,sizeof(c1),1,fptr);
        break;
    }
    fclose(fptr);
    return 0;
}
int Viewrecord(){
	struct CUSTOMER c1;
    FILE *fptr;
    fptr=fopen("Customers.txt","r");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
		printf("\n\nName: %s",c1.name);
		printf("\nAge: %d",c1.age);
		printf("\nPhone Number: %s",c1.phone);
    }
    fclose(fptr);
    return 0;
}
int Modifyrecord(){
	struct CUSTOMER c1;
	char nameMOD[20],flag=0;
    FILE *fptr,*temp;
    fptr=fopen("Customers.txt","r+");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record modification
    printf("Which record do u want to modify?\nEnter the name of the customer:");
    fflush(stdin);
    gets(nameMOD);
	nameMOD[0]=toupper(nameMOD[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {		
		if(strcmp(nameMOD,c1.name)!=0){
			fwrite(&c1,sizeof(c1),1,temp);
		}
    	if(strcmp(nameMOD,c1.name)==0){
			flag=1;
			//start modification
			printf("\nEnter Name: ");
	        fflush(stdin);
	        gets(c1.name);
	        printf("\nEnter age: ");
	        scanf("%d",&c1.age);
	        printf("\nEnter Phone Number: ");
	        fflush(stdin);
	        gets(c1.phone);
	        c1.name[0]=toupper(c1.name[0]);
	        fwrite(&c1,sizeof(c1),1,temp);
			//end modification	
		}
    }
    //close files before renaming and deleting
    fclose(fptr);
	fclose(temp);
	
    if(flag==1){
		remove("Customers.txt");
	    rename("temp.txt","Customers.txt");
	    printf("\nRecord Modified Successfully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no customer with that name!");
	}
	return 0;
}
int Deleterecord(){
	struct CUSTOMER c1;
	char nameDLT[20],flag=0;
    FILE *fptr,*temp;
    fptr=fopen("Customers.txt","r+");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record removal
    printf("Which record do u want to delete?\nEnter the name of the customer:");
    fflush(stdin);
    gets(nameDLT);
	nameDLT[0]=toupper(nameDLT[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
    	if(strcmp(nameDLT,c1.name)==0)
			flag=1;		
		if(strcmp(nameDLT,c1.name)!=0){
			fwrite(&c1,sizeof(c1),1,temp);
		}
    }
    //close files before renaming and deleting
    fclose(fptr);
	fclose(temp);
    if(flag==1){
		remove("Customers.txt");
	    rename("temp.txt","Customers.txt");
	    printf("\nRecord Deleted Successfully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no customer with that name!");
	}
	return 0;
}
int Searchrecord(){
	struct CUSTOMER c1;
	char nameSRCH[20],flag=0;
    FILE *fptr;
    fptr=fopen("Customers.txt","r");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    printf("Which record do u want to search for?\nEnter the name of the customer:");
    fflush(stdin);
    gets(nameSRCH);
	nameSRCH[0]=toupper(nameSRCH[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
    	if(strcmp(nameSRCH,c1.name)==0){
			printf("\nName: %s",c1.name);
			printf("\nAge: %d",c1.age);
			printf("\nPhone Number: %s",c1.phone);
			flag=1;
    	}
	}
    fclose(fptr);
    if(flag==0)
	    printf("\nThere is no customer with that name!");
    return 0;
}
int stockScreen(){
	int i;
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	gotoxy(20,8);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(20,9);
    printf("%c%cStock Management%c%c",219,219,219,219);
    gotoxy(20,10);
	for(i=0;i<20;i++)
    	printf("%c",219);	
    loading(10000000);
    gotoxy(19,15);
    printf("Press any key to continue.");
    getch();
	if(stockMenu()==1);
		return 1;
	return 0;
}
int stockMenu(){
	system("cls");
	int option;
//
	int i;
	gotoxy(12,3);
	for(i=0;i<20;i++)
    	printf("%c",219);
    gotoxy(12,4);
    printf("%c%cStock Management%c%c",219,219,219,219);
    gotoxy(12,5);
	for(i=0;i<20;i++)
    	printf("%c",219);
	gotoxy(9,7);
	for(i=0;i<27;i++)
    	printf("%c",219);
//
	gotoxy(9,8);
    printf("%c 1 : Add Products.       %c",219,219);
    gotoxy(9,9);
    printf("%c 2 : View Products.      %c",219,219);
    gotoxy(9,10);
    printf("%c 3 : Search Products.    %c",219,219);
    gotoxy(9,11);
    printf("%c 4 : Modify Products.    %c",219,219);
    gotoxy(9,12);
    printf("%c 5 : Delete Products.    %c",219,219);
    gotoxy(9,13);
    printf("%c  Any other key to exit  %c",219,219);
    gotoxy(9,14);
	printf("%c Choose an option:       %c",219,219);
//
	gotoxy(9,16);
	for(i=0;i<27;i++)
    	printf("%c",219);
	gotoxy(9,15);
	printf("%c                         %c",219,219);
	gotoxy(19,15);

//
	scanf("%d",&option);

	switch(option){
	case 1:
		{
		system("cls");
		Additem();
		stockMenu();
		break;
		}
	case 2:
		{
		system("cls");
		Viewitem();
		puts("\n\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 3:
		{
		system("cls");
		Searchitem();
		puts("\n\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 4:
		{
		system("cls");
		Modifyitem();
		puts("\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	case 5:
		{
		system("cls");
		Deleteitem();
		puts("\nPress any key to go back.");
		getch();
		stockMenu();
		break;
		}
	default:
		{
		fflush(stdin);
		puts("\n\n            Press any key to Exit.");
		getch();
		return 1;
		}
	}
	return 0;
}
int Additem(){
	int flag=0;
	struct ITEM it,temp;
    FILE *fp,*ft;
    fp=fopen("Medicines.txt","a+");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (1)
    {
    	system("cls");
    	printf("\nEnter Product Name: ");
        fflush(stdin);
        gets(it.productname);
        it.productname[0]=toupper(it.productname[0]);
        
        
        char ch;
        ch= toupper(ch);
        ft=fopen("Medicines.txt","r");
        if(ft==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
    	while(fread(&temp,sizeof(temp),1,ft)==1){
    		if(strcmp(it.productname,temp.productname)==0){
				flag=1;
			}
		}
		fclose(ft);
		if(flag==1){
			printf("\nThis Product already exists can't add again!\nPress any key to go back");
			getch();
			break;
		}
        
        printf("\nEnter Product Company: ");
        fflush(stdin);
        gets(it.productcomp);
        it.productcomp[0]=toupper(it.productcomp[0]);
        while(1){
		printf("\nEnter Product Price: ");
        scanf("%d",&it.price);
        printf("\nEnter Product Quantity: ");
        scanf("%d",&it.Qnt);
        if((it.price>0)&&(it.Qnt>0))
        	break;
        else
        	printf("\nPrice and quantity must be greater than 0");
		}
        fwrite(&it,sizeof(it),1,fp);
        break;
    }
    fclose(fp);
    return 0;
}
int Viewitem(){
	struct ITEM it;
    FILE *fp;
    fp=fopen("Medicines.txt","r");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    while (fread(&it,sizeof(it),1,fp)==1)
    {
		printf("\n\nProduct Name: %s", it.productname);
		printf("\nCompany Name: %s", it.productcomp);
		printf("\nProduct Price: %d", it.price);
		printf("\nProduct Quantity: %d", it.Qnt);
    }
    fclose(fp);
    return 0;
}
int Modifyitem(){
	struct ITEM it;
	char nameMOD[20];
	int flag=0;
    FILE *fp,*temp;
    fp=fopen("Medicines.txt","r+");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record modification
    printf("Which record do u want to modify?\nEnter the Product Name:");
    fflush(stdin);
    gets(nameMOD);
	nameMOD[0]=toupper(nameMOD[0]);
    while (fread(&it,sizeof(it),1,fp)==1)
    {		
		if(strcmp(nameMOD,it.productname)!=0){
			fwrite(&it,sizeof(it),1,temp);
		}
		if(strcmp(nameMOD,it.productname)==0){
			flag=1;
			//start modification
			printf("\nProduct Name: %s", it.productname);
			printf("\nCompany Name: %s", it.productcomp);
			printf("\nProduct Price: %d", it.price);
			printf("\nProduct Quantity: %d\n", it.Qnt);
			printf("\nEnter Product Name: ");
	        fflush(stdin);
	        gets(it.productname);
	        printf("\nEnter Company Name: ");
	        fflush(stdin);
	        gets(it.productcomp);
	        printf("\nEnter Price: ");
	        scanf("%d",&it.price);
	        printf("\nEnter Quantity: ");
	        scanf("%d",&it.Qnt);
	        it.productname[0]=toupper(it.productname[0]);
            it.productcomp[0]=toupper(it.productcomp[0]);
	        fwrite(&it,sizeof(it),1,temp);
			//end modification	
		}
    }
    //close files before renaming and deleting
    fclose(fp);
	fclose(temp);
    if(flag==1){
		remove("Medicines.txt");
	    rename("temp.txt","Medicines.txt");
	    printf("\nRecord Modified Successfully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no Product with that Name!");
	}
	return 0;
}
int Deleteitem(){
	struct ITEM it;
	char nameDLT[20],flag=0;
    FILE *fp,*temp;
    fp=fopen("Medicines.txt","r+");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    temp=fopen("temp.txt","w+");
    if(temp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    //ask name for record removal
    printf("Which record do u want to delete?\nEnter the Product Name:");
    fflush(stdin);
    gets(nameDLT);
	nameDLT[0]=toupper(nameDLT[0]);
    while (fread(&it,sizeof(it),1,fp)==1)
    {
    	if(strcmp(nameDLT,it.productname)==0)
			flag=1;		
		if(strcmp(nameDLT,it.productname)!=0){
			fwrite(&it,sizeof(it),1,temp);
		}
    }
    //close files before renaming and deleting
    fclose(fp);
	fclose(temp);
    if(flag==1){
		remove("Medicines.txt");
	    rename("temp.txt","Medicines.txt");
	    printf("\nRecord Deleted Successfully!");
    }
    else{
    	remove("temp.txt");
    	printf("\nThere is no product with that Name!");
	}
	return 0;
}
int Searchitem(){
	struct ITEM it;
	char nameSRCH[20],flag=0;
    FILE *fp;
    fp=fopen("Medicines.txt","r");
    if(fp==NULL){
        printf("File could not be opened!");
        exit(1);
    }
    printf("Which record do u want to search for?\nEnter the Product Name:");
    fflush(stdin);
    gets(nameSRCH);
	nameSRCH[0]=toupper(nameSRCH[0]);
    while (fread(&it,sizeof(it),1,fp)==1)
    {
    	if(strcmp(nameSRCH,it.productname)==0){
			printf("\nProduct Name: %s", it.productname);
			printf("\nCompany Name: %s", it.productcomp);
			printf("\nProduct Price: %d", it.price);
			printf("\nProduct Quantity: %d\n", it.Qnt);
			flag=1;
    	}
	}
    fclose(fp);
    if(flag==0)
	    printf("\nThere is no Medicine with that name!");
    return 0;
}
int billgenerator(){
	int i,quantity;
	float sum=0,bill=0;
	
	time_t t;
	time(&t);
	printf("\n\t\t\t\t\t\t%s",ctime(&t));
	
	struct CUSTOMER c1; 
	struct ITEM it;
	char nameSRCH[20],name[20],f=0,flag=0,option,newday;
    FILE *fp,*temp,*fptr,*fbill;
    fptr=fopen("Customers.txt","r");
    if(fptr==NULL){
        printf("File could not be opened!");
        exit(1);
		}
	printf("\n\t\tMembers get 15%% off their total order !\n\n");
	printf("Is this the first transaction of the day (Y/N) ?");
	fflush(stdin);
	scanf("%c",&newday);
	if(newday!='Y'&&newday!='y'){ //if not a new day				
		fbill=fopen("Bill.txt","r");
    	if(fbill==NULL){
        	printf("File could not be opened!\nThis might be a new day and you didn't enter Y/y");
        	exit(1);
		}
		rewind(fbill);
		fread(&bill,sizeof(bill),1,fbill);//reads file and store previous bill in "bill"
		fclose(fbill);
	}
    printf("\nEnter Customer Name: ");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);
    while (fread(&c1,sizeof(c1),1,fptr)==1)
    {
		if(strcmp(name,c1.name)==0)
		{	
			f=1;
		};
	}
    while(1)
    {
    	fp=fopen("Medicines.txt","r");
    	if(fp==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
    	temp=fopen("temp.txt","w+");
    	if(temp==NULL){
        	printf("File could not be opened!");
        	exit(1);}
    	printf("Enter the Product Name:");
    	fflush(stdin);
    	gets(nameSRCH);
		nameSRCH[0]=toupper(nameSRCH[0]);
    	while (fread(&it,sizeof(it),1,fp)==1)//searches for product in the file
    	{
    		if(strcmp(nameSRCH,it.productname)!=0)
    		{
    			fwrite(&it,sizeof(it),1,temp);	//if item doesn't match it copies to temp
			}
    		if(strcmp(nameSRCH,it.productname)==0)
			{                                             //if item matches
    			while(1)
    			{
    				printf("Enter Quantity: ");//asks for quantity
    				scanf("%d",&quantity);
    				if(it.Qnt==0){//if out of stock
    					break;
					}
    				else if(quantity > it.Qnt)//if quantity asked for if greater than quantity available
    				{
    				printf("Quantity not available, retry please.\n");
    				continue;
					}
					else
						break;
				}
				if(it.Qnt==0){
    					printf("Sorry we need to restock this item!\n");
				}
				else{//calculates the sum and reduces the items in stock
					printf("\nProduct Name: %s\tProduct Price: PKR %d\tQuantity: %d", it.productname, it.price, quantity);
					it.Qnt= it.Qnt - quantity;
					sum = sum + (it.price * quantity);
				}
				flag=1;
				fwrite(&it,sizeof(it),1,temp);//copies updated stock to temp if item found
			}
		}
		if(flag==0){//if item not found
			printf("\nThere is no Medicine with that name!");
		}
		fclose(temp);
		fclose(fp);
		printf("\nDo you want to continue?(Y/N) ");//asks if more items need to be bought
		fflush(stdin);
		scanf("%c",&option);
		if(flag==1)//if stock is updated, file is updated
    	{
    		remove("Medicines.txt");
	    	rename("temp.txt","Medicines.txt");
	  	}
	  	else if(flag==0){//if stock unchanged file unchanged
			remove("temp.txt");
		}
		if(option != 'y' && option != 'Y')//if no more items are bought
		{ 	
			if(f == 1)//if customer is a member ,discount is applied
			{
				printf("\nMembership discount of 15%% applied\n");
				sum = sum - (sum * 0.15);
				printf("Gross Total: PKR %.2f\n", sum);
			}
			else//if new customer no discount applied
				printf("Gross Total: PKR %.2f\n", sum);
			//Daily report calculations
			if(newday!='Y'&&newday!='y') //if not a new day
				bill+=sum;//adds (new transaction)sum to bill
			else
				bill=sum;//if a new day 1st transaction is stored in bill
			fbill=fopen("Bill.txt","w");
		    if(fbill==NULL){
		        printf("File could not be opened!");
		        exit(1);
			}
			fwrite(&bill,sizeof(bill),1,fbill);//stores bill in file
			fclose(fbill);
			break;
		}
	}
	fclose(fptr);
    return 0;		
}
int dailyrep(){
	struct ITEM it;
	FILE *fmeds,*fbill;
	int i;
	float bill;
	gotoxy(13,3);
	for(i=0;i<16;i++)
    	printf("%c",219);
    gotoxy(13,4);
    printf("%c%cDaily Report%c%c",219,219,219,219);
    gotoxy(13,5);
	for(i=0;i<16;i++)
    	printf("%c",219);
	fmeds=fopen("Medicines.txt","r");
	if(fmeds==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
	fbill=fopen("Bill.txt","r");
	if(fbill==NULL){
        	printf("File could not be opened!");
        	exit(1);
    	}
    printf("\n\nIf this is the end of the day here is your daily report:");
	printf("\nUpdated Inventory:");
    while (fread(&it,sizeof(it),1,fmeds)==1)
    {
		printf("\n\nProduct Name: %s", it.productname);
		printf("\nCompany Name: %s", it.productcomp);
		printf("\nProduct Price: %d", it.price);
		printf("\nProduct Quantity: %d", it.Qnt);
    }
	fread(&bill,sizeof(bill),1,fbill);
	printf("\n\nTotal Sales for the day: PKR %.3f",bill);
    fclose(fmeds);
    fclose(fbill);
}
void gotoxy(int x,int y) //function to print anything at desired position...
{
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void loading(int N) //function for loading screen
{	
	int i,j; 
	gotoxy(25,12);
	printf("Loading....");
	gotoxy(23,14);
	for(i=1;i<=15;i++)
	{
		for(j=0; j<=N;j++); //determine speed of loading screen
		{
			 //219 is ASCII code for Character which is to be printed
		}
		printf("%c", 219);
	}
}
