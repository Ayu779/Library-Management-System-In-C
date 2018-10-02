#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>

COORD coord = {0, 0};
void gotoxy (int x, int y)
{
coord.X = x; coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
FILE *fp;
char password[10]={"password"};
struct library{
	char bookname[50];
	char author[20];
	char code[20];
	int quantity;
	struct library* next;
};

struct library* start=NULL;
struct library* end=NULL;
struct library* temp=NULL;
int ct=0;
int count=0;
void add(char booknam[],char autho[],char cod[],int quantit){
	temp=(struct library*)malloc(sizeof(struct library));
	strcpy(temp->bookname,booknam);
	strcpy(temp->code,cod);
	strcpy(temp->author,autho);

	temp->quantity=quantit;

	temp->next=NULL;

	if(start==NULL){
		start=temp;
		end=temp;
	}
	else{
		end->next=temp;
		end=temp;
	}
}

void display(){
	system("cls");
	system("COLOR 0A");
	struct library* move=start;
	int ypos=10;
	while(move!=NULL){
		gotoxy(50,ypos);
	printf("%s %s %s %d\n",move->bookname,move->author,move->code,move->quantity);
	move=move->next;
	ypos+=2;
	}
}
/*int length(FILE* ft){
	ft=fopen("lib.txt","r");
	int ct=0;
	char boknam[50];
	char author[50];
	char cod[50];
	int quant;
	while(fscanf(fp,"%s %s %s %d",boknam,author,cod,&quant)!=EOF){
		ct++;
}
return ct;
}*/
int numberofbooks;
int numberofcodes;
void displays(FILE *fs,char ch2[]){
	//FILE *fs;
    system("cls");
    system("COLOR 0A");
	char ch;
	int i=0;
	int ypos=10;
	fs=fopen(ch2,"r");
	for(i=0;i<numberofbooks;i++){

	gotoxy(50,ypos);

	while(1){
		ch=fgetc(fs);
		if((ch=='\n')||(ch==EOF))
		break;
		else
		printf("%c",ch);
	}
	ypos+=2;}
	fclose(fs);

	}


void show(FILE *fs,char ch2[]){
	//FILE *fs;
    system("cls");
    system("COLOR 0A");
	char ch;
	int i=0;
	int ypos=10;
	fs=fopen(ch2,"r");
	for(i=0;i<numberofcodes;i++){

	gotoxy(50,ypos);

	while(1){
		ch=fgetc(fs);
		if((ch=='\n')||(ch==EOF))
		break;
		else
		printf("%c",ch);
	}
	ypos+=2;}
	fclose(fs);

	}

void Password()
{
system("cls");
system("COLOR 0A");
char d[25]="Enter The Password";
char ch;
char pass[10];
int i=0;
int j=0;
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf(":");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf(":");
}
gotoxy(10,10);
gotoxy(15,7);
system("color 0A");
printf("Enter Password:");

while(ch!=13)
{
ch=getch();

if(ch!=13 && ch!=8){
putch('*');
pass[i] = ch;
i++;
}
}
pass[i] = '\0';
if(strcmp(pass,password)==0)
{
gotoxy(15,9);
printf("WELCOME IN !!");
gotoxy(17,10);
printf("\nPress any key to countinue...");
getch();
adminoption();
}
else
{
gotoxy(15,16);
system("color 0C");
printf("\aWarning!! Incorrect Password");
getch();
Password();
}
}
void admin(void)
{
	Password();
	getch();
}
void addingbook(){
	system("cls");
	fp=fopen("lib.txt","a");
	FILE* bcod;
	bcod=fopen("bcod.txt","a");
	char book[50];
	char bcodbook[50];
	char bcodcode[20];
	char authorname[20];
	char bookcode[20];
	int quant;
	system("color 0A");
	printf("ENTER THE NAME OF THE BOOK\n");
	scanf("%s",book);
	printf("ENTER THE AUTHOR NAME\n");
	scanf("%s",authorname);
	printf("ENTER THE BOOK CODE\n");
	scanf("%s",bookcode);
	printf("ENTER THE QUANTITY\n");
	scanf("%d",&quant);
	strcpy(bcodbook,book);
	strcpy(bcodcode,bookcode);
	fprintf(fp,"%s %s %s %d\n",book,authorname,bookcode,quant);
	printf("BOOK ADDED SUCCESSFULLY!!!\n");
	//scanf("%s %s",bcodbook,bcodcode);
	fprintf(bcod,"%s  %s\n",bcodbook,bcodcode);
	numberofbooks++;
	numberofcodes++;
	fclose(fp);
	fclose(bcod);
	printf("\n\n\n Please Wait...");
	Sleep(5000);
adminoption();

}
void removebook(){
	//FILE *fp;
	system("cls");
	displays(fp,"lib.txt");
	fp=fopen("lib.txt","r");
	FILE *fp1;
	fp1=fopen("tmp.txt","w");
	char boknam[50];
	char author[50];
	char cod[50];
	int quant;
	char codeuser[20];
	printf("\nENTER THE CODE OF THE BOOK YOU WANT TO REMOVE\n");
	scanf("%s",codeuser);
	printf("HOW MANY BOOKS YOU WANT TO REMOVE?\n");
	int num;
	scanf("%d",&num);
	while(fscanf(fp,"%s %s %s %d",boknam,author,cod,&quant)!=EOF){

		if((strcmp(codeuser,cod)==0))
{
	       quant=quant-num;
		if(quant<=0){
			numberofbooks--;
		}
		else{

		fprintf(fp1,"%s %s %s %d\n",boknam,author,cod,quant);

		}
	}
		else{
			fprintf(fp1,"%s %s %s %d\n",boknam,author,cod,quant);
		}

	}
	printf("BOOK REMOVED SUCCESSFULLY!!!\n");
	fclose(fp);
	fclose(fp1);
	fp=fopen("lib.txt","w");
	fp1=fopen("tmp.txt","r");


		while(fscanf(fp1,"%s %s %s %d",boknam,author,cod,&quant)!=EOF)
		{
			fprintf(fp,"%s %s %s %d\n",boknam,author,cod,quant);
		}
		fclose(fp);
	fclose(fp1);
	printf("Press Any Key To Go Back To Admin Options...");
    if(getch())
    adminoption();

}

int adminoption(){
system("cls");
system("COLOR 0A");
gotoxy(15,7);
printf("PRESS 1 FOR ADDING A BOOK");
gotoxy(15,9);
printf("PRESS 2 FOR REMOVING A BOOK");
gotoxy(15,11);
printf("PRESS 3 TO VIEW THE TOTAL STOCKS");
gotoxy(15,13);
printf("PRESS 4 TO GO TO HOME");
int choice;
gotoxy(15,15);
scanf("%d", &choice);

switch(choice){
	case 1:
	{
		addingbook();
		break;
	}
	case 2:
	{
		removebook();
		break;
	}
	case 3:
		{
			fp=fopen("lib.txt","r");
		displays(fp,"lib.txt");
		fclose(fp);
		printf("\nPress Any Key To Go Back...");
		if(getch())
		adminoption();
		break;
		}
	case 4:
		{
			home();
			break;
		}
	default :
{
	gotoxy(10,21);
	printf("\aWrong Entry!!Please re-entered correct option");
	if(getch())
	adminoption();
}
}
return;
}
void custom(void){
system("cls");

system("color 0A");
gotoxy(15,7);
printf("PRESS 1 FOR SEARCH A BOOK");
gotoxy(15,9);
printf("PRESS 2 FOR VIEW AVAILABLE BOOKS");
gotoxy(15,11);
printf("PRESS 3 FOR ISSUE A BOOK");
gotoxy(15,13);
printf("PRESS 4 FOR RETURNING A BOOK");
gotoxy(15,15);
printf("PRESS 5 TO GO TO HOME");
int choice;
gotoxy(15,17);
scanf("%d", &choice);

void search(void);


switch(choice){
	case 1:
	{
		search();
		break;
	}
	case 2:
	{

		//FILE *fp;

		displays(fp,"lib.txt");
		printf("\nPress Any Key To Go Back...\n");
		getch();
		custom();

		break;
	}
	case 3:
		{
		issue();
		break;
		}
	case 4:
		{
		returnbook();
		break;
		}
		case 5:
		{
		home();
		break;
		}
	default :
{
	gotoxy(10,21);
	system("COLOR 0C");
	printf("\aWrong Entry!!Please re-entered correct option");
	if(getch())
	home();
}
}
}


void search(){
	char name[20];
	int enroll;
	system("cls");
	system("COLOR 0A");
	//maincopy();
	FILE* fs;
	show(fs,"bcod.txt");
	fp=fopen("lib.txt","r");
	char codeuser[20];
//	FILE *fp1;
	char booknames[50];
	char authors[20];
	char codes[20];
	int quantities;
//	fp1=fopen("tmp.txt","w");
	char bs[20];
	gotoxy(50,40);
	printf("\n\tPLEASE ENTER THE CODE OF THE BOOK YOU WANT TO SEARCH\n");
		scanf("%s",codeuser);
	int check=0;

	while(fscanf(fp,"%s %s %s %d",booknames,authors,codes,&quantities)!=EOF){

		if(quantities==0)
		printf("BOOK UNAVAILABLE");

		else
		{
			if(strcmp(codeuser,codes)==0){
				printf("BOOK AVAILABLE\n");
				printf("BOOK NAME: %s\n",booknames);
				printf("BOOK AUTHOR: %s\n",authors);
				printf("QUANTITY: %d\n",quantities);
				check=1;
			break;
			}

		  }
	}
	if(check==0)
	{
	system("COLOR 0C");
	printf("BOOK UNAVAILABLE\n");
	}

//	fclose(fp1);
	fclose(fp);

printf("\n\n\n Please Wait...");
Sleep(5000);
custom();

}


void issue(){
	char name[20];
	int enroll;
	system("cls");
	system("COLOR 0A");
	//maincopy();
	FILE* fs;
	displays(fs,"lib.txt");
	fp=fopen("lib.txt","r");
	char codeuser[20];
	FILE *fp1;
	char booknames[10];
	char authors[4];
	char codes[4];
	int quantities;
	fp1=fopen("tmp.txt","w");
	char bs[20];
	printf("\nPLEASE ENTER THE CODE OF THE BOOK YOU WANT TO ISSUE\n");
		scanf("%s",codeuser);


	while(fscanf(fp,"%s %s %s %d",booknames,authors,codes,&quantities)!=EOF){

		if(quantities==0)
	{
		system("COLOR 0C");
		printf("BOOK UNAVAILABLE");	}
		else
		{
		  if(strcmp(codeuser,codes)==0){
		strcpy(bs,booknames);

		quantities--;
		fprintf(fp1,"%s %s %s %d\n",booknames,authors,codes,quantities);

		}
		else{
			fprintf(fp1,"%s %s %s %d\n",booknames,authors,codes,quantities);
		}}
	}
	fclose(fp1);
	fclose(fp);


	fp=fopen("lib.txt","w");
	fp1=fopen("tmp.txt","r");
	while(fscanf(fp1,"%s %s %s %d",booknames,authors,codes,&quantities)!=EOF){

       	fprintf(fp,"%s %s %s %d\n",booknames,authors,codes,quantities);

}

remove("tmp.txt");
fclose(fp1);
	fclose(fp);
printf("ENTER YOUR NAME ");
scanf("%s", name);
printf("ENTER YOUR ENROLLMENT NUMBER ");
scanf("%d", &enroll);
printf("THE BOOK %s IS SUCCESSFULLY ISSUED TO %s (%d).", bs, name, enroll);
printf("\n\n\n Please Wait...");
Sleep(5000);
custom();

}


void returnbook(){
	char name[20];
	int enroll;
	system("cls");
	system("COLOR 0A");
	displays(fp,"lib.txt");
	fp=fopen("lib.txt","r");
	char codeuser[20];
	FILE *fp1;
	char booknames[10];
	char authors[4];
	char codes[4];
	int quantities;
	fp1=fopen("tmp.txt","w");
	char bs[20];
	printf("\nPLEASE ENTER THE CODE OF THE BOOK YOU WANT TO RETURN\n");
		scanf("%s",codeuser);


	while(fscanf(fp,"%s %s %s %d",booknames,authors,codes,&quantities)!=EOF){

		//if(quantities==0)
		//printf("BOOK UNAVAILABLE");



		  if(strcmp(codeuser,codes)==0){
		strcpy(bs,booknames);

		quantities++;
		fprintf(fp1,"%s %s %s %d\n",booknames,authors,codes,quantities);

		}
		else{
			fprintf(fp1,"%s %s %s %d\n",booknames,authors,codes,quantities);
		}
	}
	fclose(fp1);
	fclose(fp);


	fp=fopen("lib.txt","w");
	fp1=fopen("tmp.txt","r");
	while(fscanf(fp1,"%s %s %s %d",booknames,authors,codes,&quantities)!=EOF){

       	fprintf(fp,"%s %s %s %d\n",booknames,authors,codes,quantities);

}

remove("tmp.txt");


fclose(fp1);
	fclose(fp);

printf("ENTER YOUR NAME ");
scanf("%s", name);
printf("ENTER YOUR ENROLLMENT NUMBER ");
scanf("%d", &enroll);
printf("THE BOOK %s IS SUCCESSFULLY RETURNED BY %s (%d)", bs, name, enroll);
printf("\n\n\n Please Wait...");
Sleep(5000);
custom();

}

void close(){
system("cls");
system("COLOR 0A");
gotoxy(52,3);
printf("\a This Project is made by");
gotoxy(40,5);
printf("\tAyush");
gotoxy(40,7);
printf("\tas the part of II Semester project");
gotoxy(35,9);
printf("\t for the partial fulfillment of the BTECH Degree");
gotoxy(40,11);
printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::");
gotoxy(40,13);
printf("::::::::::::::::::::::::::::::::::::::::::::::::::::::");
gotoxy(20,20);
printf("Exiting in 3 second...........>");
Sleep(3000);
exit(0);
}
int home(){
system("cls");
system("COLOR 0A");
char d[25]="CHOOSE YOUR IDENTITY";
char ch,pass[10];
int i=0,j;
gotoxy(10,4);
for(j=0;j<20;j++)
{
Sleep(50);
printf(":");
}
for(j=0;j<20;j++)
{
Sleep(50);
printf("%c",d[j]);
}
for(j=0;j<20;j++)
{
Sleep(50);
printf(":");
}

gotoxy(15,7);
printf("IF YOU ARE ADMIN PRESS 1");
gotoxy(15,9);
printf("IF YOU ARE CUSTOMER PRESS 2");
gotoxy(15,11);
printf("PRESS 3 TO CLOSE THE APPLICATION");
int choice;
gotoxy(15,13);
scanf("%d", &choice);

switch(choice){
	case 1:
	{
		admin();
		break;
	}
	case 2:
	{
		custom();
		break;
	}
	case 3:
		{
		close();
		break;
		}
	default :
{
	gotoxy(10,21);
	system("COLOR 0C");
	printf("\aWrong Entry!!Please re-enter correct option");
	if(getch())
	home();
}
}
}

int main(){

	fp=fopen("lib.txt","r");
	FILE* ft3;
	ft3=fopen("bcod.txt","r");
	char booknam[50];
	char autho[20];
	char cod[20];
	int quantit;

	while(fscanf(fp,"%s %s  %s %d",booknam,autho,cod,&quantit)!=EOF){
		//printf("%s\n",cod);
		add(booknam,autho,cod,quantit);
		ct++;
	}
		while(fscanf(ft3,"%s %s",booknam,autho)!=EOF){
		//printf("%s\n",cod);
	//	add(booknam,autho,cod,quantit);
		count++;
	}


numberofbooks=ct;
numberofcodes=count;
printf("%d\n",ct);
printf("%d",count);
	fclose(fp);
	fclose(ft3);
	home();
	getch();
	return 0;
}
