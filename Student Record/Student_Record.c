#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<stdlib.h>
#include<ctype.h>
#include<windows.h>
#include<time.h>
#include<wincon.h>
#define MAX 80
FILE *fp,*fp1,*fr;
struct student
{
  char snum[13];
  char fname[20];
  char sname[20];
  char section;
  char year;
  char ccode[10];
  char sfather[50];
  char smother[50];
  char father[50];
  char mother[50];
  char cont[10];

      /*char code1[8];
    char code2[8];
    char code3[8];
    char code4[8];
    char code5[8];
    char code6[8];
    char code7[8];
    char subject1[20];
    char subject2[20];
    char subject3[20];
    char subject4[20];
    char subject5[20];
    char subject6[20];
    char first[50];
  char second[50];
  char third[50];
  char fourth[50];
  char fifth[50];
  char sixth[50];
    char subject7[20];*/
  }e;
void gotoxy(int x,int y)
{
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
int wherex()
{
CONSOLE_SCREEN_BUFFER_INFO csbi;
COORD result;
if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
return -1;
return result.X;
}
int wherey()
{
CONSOLE_SCREEN_BUFFER_INFO csbi;
COORD result;
if(!GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE),&csbi))
return -1;
return result.Y;
}
void delay(unsigned int mseconds)
{

    clock_t goal=mseconds+clock();
    while(goal>clock());
}


int Temp1(void);
int twolinebox(int x1,int y1,int x2,int y2)
{
 int x,y;
 gotoxy(x1,y1);
  printf("-");
 gotoxy(x2,y1);
 printf("-");
  for(y=y1+1;y<y2;y++)
  {
    gotoxy(x1,y); printf("-");
    gotoxy(x2,y); printf("-");
  }
 gotoxy(x1,y2); printf("-");
 gotoxy(x2,y2); printf("-");
  for(x=x1+1;x<x2;x++)
  {
    gotoxy(x,y1);
     printf("-");
    gotoxy(x,y2);
     printf("-");
  }
 gotoxy(x1+1,y1+1);
}

void printxy(int x,int y,char string[])
{
 gotoxy(x,y);
  printf("%s",string);
}

void center(int y,char string[])
{
int x=(80-strlen(string)+1)/2;
gotoxy(x,y);
printf("%s",string);
}
void modify()
{
int found=0,count=0;
char id[20];
system("cls");
fp=fopen("temp1.dat","r");
fp1=fopen("temp.dat","w");
twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     center(7,"Modify Record");
     printxy(23,11,"Enter the Emp ID you want to Modify");
	 gotoxy(37,15);
     scanf("%s",&id);
while(1)
{
    fscanf(fp,"%s %s %s %c %c %s %s %s %s %s %s",&e.snum,&e.fname,&e.sname,&e.year,&e.section,&e.ccode,&e.father,&e.sfather,&e.mother,&e.smother,&e.cont);
if(feof(fp))
{
break;
}
system("cls");
if(strcmp(e.snum,id)==0)
{
found=1;
Temp2();
gotoxy(19,8);
   scanf(" ");
   gets(e.snum);
   fflush(stdin);
   gotoxy(19,9);
   scanf(" ");
   gets(e.fname);
   fflush(stdin);
   gotoxy(19,10);
   scanf(" ");
   gets(e.sname);
   fflush(stdin);
   gotoxy(19,11);
   e.section=getche();
   e.section=toupper(e.section);
   gotoxy(19,12);
   e.year=getche();
   e.year=toupper(e.year);
   gotoxy(19,13);
   scanf(" ");
   gets(e.ccode);
   fflush(stdin);
   gotoxy(31,14);
   scanf(" ");
   gets(e.father);
   fflush(stdin);
   gotoxy(31,15);
   scanf(" ");
   gets(e.sfather);
   fflush(stdin);
   gotoxy(31,16);
   scanf(" ");
   gets(e.mother);
   fflush(stdin);
   gotoxy(31,17);
   scanf(" ");
   gets(e.smother);
   fflush(stdin);
   gotoxy(24,18);
   scanf(" ");
   gets(e.cont);
   fflush(stdin);
fprintf(fp1,"%s %s %s %c %c %s %s %s %s %s %s \n",e.snum,e.fname,e.sname,e.year,e.section,e.ccode,e.father,e.sfather,e.mother,e.smother,e.cont);
}
else
{
fprintf(fp1,"%s %s %s %c %c %s %s %s %s %s %s \n",e.snum,e.fname,e.sname,e.year,e.section,e.ccode,e.father,e.sfather,e.mother,e.smother,e.cont);
}
}
fclose(fp);
fclose(fp1);

if(found==0)
{
    /*twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);*/
     twolinebox(2,2,79,25);
center(15,"Sorry No Record Found\n\n");
}
else
{
fp=fopen("temp1.dat","w");
fp1=fopen("temp.dat","r");

while(1)
{
    fscanf(fp1,"%s %s %s %c %c %s %s %s %s %s %s",&e.snum,&e.fname,&e.sname,&e.year,&e.section,&e.ccode,&e.father,&e.sfather,&e.mother,&e.smother,&e.cont);
    if(feof(fp1))
{
break;
}
fprintf(fp,"%s %s %s %c %c %s %s %s %s %s %s \n",e.snum,e.fname,e.sname,e.year,e.section,e.ccode,e.father,e.sfather,e.mother,e.smother,e.cont);
}
}
fclose(fp);
fclose(fp1);
}
void Create(void)
{
  char opt;
  center(21,"WARNING!!!");
  center(22,"You are about to create a new file");
  center(23,"This will erase all records in the file...");
  center(24,"Are you sure you want to proceed?[Y/N] ");
  opt=getche();
  opt=toupper(opt);
  if(opt=='Y')
  {

   fp=fopen("temp1.dat","w");

   /*ft=fopen("TimeTable.dat","w");
   fr=fopen("SubjectList.dat","w");*/
   center(24,"                                             ");
   center(24,"File successfully created!");
  }
   getch();
 fclose(fp);
}
int Temp1(void)
{
  twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"ADD RECORD");
  printxy(6,8,"Student no: ");
  printxy(6,9,"First Name: ");
  printxy(6,10,"Last Name: ");
  printxy(6,11,"Section:");
  printxy(6,12,"Year:");
  printxy(6,13,"Course Code: ");
  printxy(6,14,"Father Name(First Name): ");
  printxy(6,15,"Father Name(Last Name): ");
  printxy(6,16,"Mother Name(First Name): ");
  printxy(6,17,"Mother Name(Last Name); ");
  printxy(6,18,"Contact Num:+91- ");
  center(21," Course Code: [BCA], [BSC.CS], [BSC.Anim], [B.TECH], [MCA]");
  gotoxy(19,7);
}
int Temp2(void)
{
  twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"Modify The Record Details");
  printxy(6,8,"Student no: ");
  printxy(6,9,"First Name: ");
  printxy(6,10,"Last Name: ");
  printxy(6,11,"Section:");
  printxy(6,12,"Year:");
  printxy(6,13,"Course Code: ");
  printxy(6,14,"Father Name(First Name): ");
  printxy(6,15,"Father Name(Last Name): ");
  printxy(6,16,"Mother Name(First Name): ");
  printxy(6,17,"Mother Name(Last Name); ");
  printxy(6,18,"Contact Num:+91- ");
}
/*printxy(6,8,"First: ");
  printxy(6,10,"Second: ");
  printxy(6,12,"Third: ");
  printxy(6,14,"Fourth:");
  printxy(6,16,"Fifth:");
  printxy(6,18,"Sixth: ");
}
int temp3(void)
{
  twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"ADD Code With Subjects Details");
  printxy(6,8,"Code: ");
  printxy(20,8,"Subject: ");
  printxy(6,10,"Code: ");
  printxy(20,10,"Subject: ");
  printxy(6,12,"Code: ");
  printxy(20,12,"Subject: ");
  printxy(6,14,"Code:");
  printxy(20,14,"Subject: ");
  printxy(6,16,"Code:");
  printxy(20,16,"Subject: ");
  printxy(6,18,"Code: ");
  printxy(20,18,"Subject: ");
  printxy(6,20,"Code: ");
  printxy(20,20,"Subject: ");
}*/

void Add(void)
{
int i,n;
fp=fopen("temp1.dat","a");
system("cls");
Temp1();
{
   gotoxy(19,8);
   scanf(" ");
   gets(e.snum);
   fflush(stdin);
   gotoxy(19,9);
   scanf(" ");
   gets(e.fname);
   fflush(stdin);
   gotoxy(19,10);
   scanf(" ");
   gets(e.sname);
   fflush(stdin);
   gotoxy(19,11);
   e.section=getche();
   e.section=toupper(e.section);
   gotoxy(19,12);
   e.year=getche();
   e.year=toupper(e.year);
   gotoxy(19,13);
   scanf(" ");
   gets(e.ccode);
   fflush(stdin);
   gotoxy(31,14);
   scanf(" ");
   gets(e.father);
   fflush(stdin);
   gotoxy(31,15);
   scanf(" ");
   gets(e.sfather);
   fflush(stdin);
   gotoxy(31,16);
   scanf(" ");
   gets(e.mother);
   fflush(stdin);
   gotoxy(31,17);
   scanf(" ");
   gets(e.smother);
   fflush(stdin);
   gotoxy(24,18);
   scanf(" ");
   gets(e.cont);
   fflush(stdin);
   gotoxy(5,22);
   system("cls()");
   printxy(79,22,"-");
   fprintf(fp,"%s %s %s %c %c %s %s %s %s %s %s \n",e.snum,e.fname,e.sname,e.year,e.section,e.ccode,e.father,e.sfather,e.mother,e.smother,e.cont);
   gotoxy(5,21);
   twolinebox(2,2,79,24);
   printxy(27,11,"Record successfully added!");
   printxy(79,21,"-");
   gotoxy(53,22);
   delay(1000);
   printxy(25,13,"Press any key to go to main menu...");
   getch();
   fclose(fp);
}
}

void List(void)
{
int count=0,i,x=0,page=1,BCA=0,BSCCS=0,BSCAni=0,BTECH=0,MCA=0;
fp=fopen("temp1.dat","r");


 system("cls");
 center(2,"Teerthanker Mahaveer University");
 center(3,"Moradabad");
 center(5,"College of Computer Science and Information Technology");
 printxy(10,7,"Record   StudentID       Name             Year   Section   Course");
 for(i=1;i<80;i++)
 {
 gotoxy(i,8);
 puts("-");
 }
while(fscanf(fp,"%s %s %s %c %c %s %s %s %s %s %s",&e.snum,&e.fname,&e.sname,&e.year,&e.section,&e.ccode,&e.father,&e.sfather,&e.mother,&e.smother,&e.cont)!=EOF)
 {
    if(count!=0&&count%10==0)
    {
    printxy(5,23,"Press any key to continue...");
    getch();
    x=0;
    for(i=10;i<=25;i++)
    {
    gotoxy(1,i);
    }
    system("cls");
    page++;
    center(2,"Teerthanker Mahaveer University");
 center(3,"Moradabad");
 center(5,"College of Computer Science and Information Technology");
 printxy(10,7,"Record   StudentID       Name             Year   Section   Course");
  for(i=1;i<80;i++)
 {
 gotoxy(i,8);
 puts("-");
 }
    }
    gotoxy(70,4);
    printf("Page %d",page);
    gotoxy(13,10+x);
    printf("%d",count+1);
    gotoxy(19,10+x);
    printf("%s",e.snum);
    gotoxy(35,10+x);
    printf("%s %s",e.fname,e.sname);
    gotoxy(53,10+x);
    printf("%c     %c",e.year,e.section);
    gotoxy(69,10+x);
    printf("%s",e.ccode);
    fflush(stdin);
    /*switch(e.ccode[10])
    {
	 case 'BCA': printf("BCA");
		   BCA++;
		   fflush(stdin);
		   break;
	 case 'BSC.CS': printf("BSC.CS");
		   BSCCS++;
		   fflush(stdin);
		   break;
	 case 'BSC.ANIM': printf("BSC.Anim");
		   BSCAni++;
		   fflush(stdin);
		   break;
	 case 'B.TECH': printf("B.TECH");
		   BTECH++;
		   fflush(stdin);
		   break;
	 case 'MCA': printf("MCA");
		   MCA++;
		   fflush(stdin);
		   break;
       }*/
  x++;
  count++;
 }
 /*printxy(25,17,"TOTAL");
 gotoxy(15,18);
 printf("BCA: %d",BCA);
 gotoxy(15,19);
 printf("BSC.CS: %d",BSCCS);
 gotoxy(15,20);
 printf("BSC.Animation: %d",BSCAni);
 gotoxy(15,21);
 printf("B.TECH: %d",BTECH);
 gotoxy(15,22);
 printf("MCA: %d",MCA);
 printxy(5,23,"Press any key to go to main menu...");*/
 getch();

 fclose(fp);
}
/*void Lists(void)
{
int count=0,i,x=0,page=1;
ft=fopen("TimeTable.dat","r");


 system("cls");
 center(2,"Teerthanker Mahaveer University");
 center(3,"Moradabad");
 center(5,"College of Computer Science and Information Technology");
 printxy(10,7,"    First      Second      Third      Fourth      Fifth      Sixth");
  printxy(1,10,"Monday: ");
  printxy(1,11,"Tuesday: ");
  printxy(1,12,"Wednesday: ");
  printxy(1,13,"Thursday:");
  printxy(1,14,"Friday:");
  printxy(1,15,"Saturday: ");

   for(i=1;i<80;i++)
 {
 gotoxy(i,8);
 puts("-");
 }
while((fscanf(ft,"%s %s %s %s %s %s",&e.first,&e.second,&e.third,&e.fourth,&e.fifth,&e.sixth)!=EOF)&&(fscanf(fr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",&e.code1,&e.subject1,&e.code2,&e.subject2,&e.code3,&e.subject3,&e.code4,&e.subject4,&e.code5,&e.subject5,&e.code6,&e.subject6,&e.code7,&e.subject7)!=EOF))
 {

    gotoxy(70,4);
    printf("BCA C");

    gotoxy(13,10+x);
    printf("%s",e.first);
    gotoxy(25,10+x);
    printf("%s",e.second);
    gotoxy(37,10+x);
    printf("%s",e.third);
    gotoxy(48,10+x);
    printf("%s",e.fourth);
    gotoxy(59,10+x);
    printf("%s",e.fifth);
    gotoxy(70,10+x);
    printf("%s",e.sixth);
 printxy(15,19,"[102]-Opps&C++                 [103]-English");
 printxy(15,20,"[104]-Accounts                 [105]-Computer Graphics");
 printxy(15,21,"[106]-Software Engg            [107]-Opps&C++ Lab");
 printxy(15,22,"[108]-Computer Graphics Lab");
 x++;
}
 printxy(5,23,"Press any key to go to main menu...");
 getch();

 fclose(ft);
}*/


void search()
{
char choice;
char sname[20];
char lname[20];
char recno[13];
system("cls");
fp=fopen("temp1.dat","a+");
     twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     center(7,"SEARCH MENU");
     printxy(30,9,"Press:");
     printxy(30,11,"[A]-SEARCH BY NAME");
     printxy(30,12,"[B]-SEARCH BY STUDENTID");

     printxy(30,16,"Enter your choice...");
     gotoxy(50,16);
     choice=getch();
     choice=toupper(choice);
switch(choice)
{
case 'A':
    system("cls");

     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     printxy(24,9,"Enter The Student Name To Search\n");
     printxy(30,11,"Enter The First Name-");
     scanf("                                %s",sname);
     printxy(30,12,"Enter The Last Name-");
     scanf("                                %s",lname);
     fflush(stdin);
system("cls");
while(fscanf(fp,"%s %s %s %c %c %s %s %s %s %s %s",&e.snum,&e.fname,&e.sname,&e.year,&e.section,&e.ccode,&e.father,&e.sfather,&e.mother,&e.smother,&e.cont)!=EOF)
{
if((strcmp(sname,e.fname)==0)&&(strcmp(lname,e.sname)==0))

{
    twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"DETAIL OF STUDENT");
  gotoxy(6,8);
  printf("Student no: %s",e.snum);
  gotoxy(6,9);
  printf("First Name: %s",e.fname);
  gotoxy(6,10);
  printf("Last Name: %s",e.sname);
  gotoxy(6,11);
  printf("Section: %c",e.section);
  gotoxy(6,12);
  printf("Year: %c",e.year);
  gotoxy(6,13);
  printf("Course Code: %s",e.ccode);
  gotoxy(6,14);
  printf("Father Name: %s %s",e.father,e.sfather);
  gotoxy(6,15);
  printf("Mother Name: %s %s",e.mother,e.smother);
  gotoxy(6,16);
  printf("Contact Num: +91-%s",e.cont);
  center(21," Course Code: [BCA], [BSC.CS], [BSC.Anim], [B.TECH], [MCA]");
  gotoxy(19,7);
}
}
if((strcmp(sname,e.fname)!=0)&&(strcmp(lname,e.sname)!=0))
{

    twolinebox(2,2,79,25);
center(15,"Sorry No Record Found");
}

break;
case 'B':
    system("cls");
    twolinebox(20,5,60,18);
    twolinebox(2,20,79,25);
    twolinebox(2,2,79,25);
    printxy(25,9,"Enter The Student Id To Search\n");
    gotoxy(37,11);
    scanf("%s", &recno);
system("cls");
while(fscanf(fp,"%s %s %s %c %c %s %s %s %s %s %s",&e.snum,&e.fname,&e.sname,&e.year,&e.section,&e.ccode,&e.father,&e.sfather,&e.mother,&e.smother,&e.cont)!=EOF)
{
if(strcmp(recno,e.snum)==0)
{
twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"DETAIL OF STUDENT");
  gotoxy(6,8);
  printf("Student no: %s",e.snum);
  gotoxy(6,9);
  printf("First Name: %s",e.fname);
  gotoxy(6,10);
  printf("Last Name: %s",e.sname);
  gotoxy(6,11);
  printf("Section: %c",e.section);
  gotoxy(6,12);
  printf("Year: %c",e.year);
  gotoxy(6,13);
  printf("Course Code: %s",e.ccode);
  gotoxy(6,14);
  printf("Father Name: %s %s",e.father,e.sfather);
  gotoxy(6,15);
  printf("Mother Name: %s %s",e.mother,e.smother);
  gotoxy(6,16);
  printf("Contact Num: +91-%s",e.cont);
  center(21," Course Code: [BCA], [BSC.CS], [BSC.Anim], [B.TECH], [MCA]");
  gotoxy(19,7);
}
}
if(strcmp(recno,e.snum)!=0)
{

    twolinebox(2,2,79,25);
center(15,"Sorry No Record Found");
}
break;
}

getch();
}

void Quit(void)
{
 system("cls");
 twolinebox(2,2,79,24);
 center(8,"MADE");
 center(10,"BY");
 center(12,"LOGIC_VIEW");
 center(14,"SOFTECH");
 delay(2000);
 exit(1);
 fclose(fp);
}
/*void subject()
{

    fr=fopen("SubjectList.dat","a");
    system("cls");
    temp3();
    {
   gotoxy(11,8);
   scanf(" ");
   gets(e.code1);
   fflush(stdin);
   gotoxy(29,8);
   scanf(" ");
   gets(e.subject1);
   fflush(stdin);
   gotoxy(11,10);
   scanf(" ");
   gets(e.code2);
   fflush(stdin);
   gotoxy(29,10);
   scanf(" ");
   gets(e.subject2);
   fflush(stdin);
   gotoxy(11,12);
   scanf(" ");
   gets(e.code3);
   fflush(stdin);
   gotoxy(29,12);
   scanf(" ");
   gets(e.subject3);
   fflush(stdin);
   gotoxy(11,14);
   scanf(" ");
   gets(e.code4);
   fflush(stdin);
   gotoxy(29,14);
   scanf(" ");
   gets(e.subject4);
   fflush(stdin);
   gotoxy(11,16);
   scanf(" ");
   gets(e.code5);
   fflush(stdin);
   gotoxy(29,16);
   scanf(" ");
   gets(e.subject5);
   fflush(stdin);
   gotoxy(11,18);
   scanf(" ");
   gets(e.code6);
   fflush(stdin);
   gotoxy(29,18);
   scanf(" ");
   gets(e.subject6);
   fflush(stdin);
   gotoxy(11,20);
   gets(e.code7);
   fflush(stdin);
   gotoxy(29,20);
   scanf(" ");
   gets(e.subject7);
   fflush(stdin);
   gotoxy(5,22);
   system("cls()");
   printxy(79,22,"-");
   fprintf(fr,"%s %s %s %s %s %s %s %s %s %s %s %s %s %s\n",e.code1,e.subject1,e.code2,e.subject2,e.code3,e.subject3,e.code4,e.subject4,e.code5,e.subject5,e.code6,e.subject6,e.code7,e.subject7);
   gotoxy(5,21);
   twolinebox(2,2,79,24);
   printxy(27,11,"Time Table Record successfully added!");
   printxy(79,21,"-");
   gotoxy(53,22);
   delay(1000);
   printxy(25,13,"Press any key to go to main menu...");
   getch();
   fclose(fr);
}
}
void monday()
{
 int i,n;
ft=fopen("TimeTable.dat","a");
system("cls");
Temp2();
{
   gotoxy(19,8);
   scanf(" ");
   gets(e.first);
   fflush(stdin);
   gotoxy(19,10);
   scanf(" ");
   gets(e.second);
   fflush(stdin);
   gotoxy(19,12);
   scanf(" ");
   gets(e.third);
   fflush(stdin);
   gotoxy(19,14);
   scanf(" ");
   gets(e.fourth);
   fflush(stdin);
   gotoxy(19,16);
   scanf(" ");
   gets(e.fifth);
   fflush(stdin);
   gotoxy(19,18);
   scanf(" ");
   gets(e.sixth);
   fflush(stdin);
   gotoxy(5,22);
   system("cls()");
   printxy(79,22,"-");
   fprintf(ft,"%s %s %s %s %s %s\n\n",e.first,e.second,e.third,e.fourth,e.fifth,e.sixth);
   gotoxy(5,21);
   twolinebox(2,2,79,24);
   printxy(27,11,"Time Table Record successfully added!");
   printxy(79,21,"-");
   gotoxy(53,22);
   delay(1000);
   printxy(25,13,"Press any key to go to main menu...");
   getch();
   fclose(ft);
}
}*/

void admin()
{
char choice;
	char pwrd[]="qwerty";
	char code[MAX];
	char temp1[25],temp2[25],uname[]="maddy",ch;
	int i=0;
	system("cls");
	twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     center(7,"LOGIN");
     printxy(30,11,"ENTER THE LOGIN ID-");
	 gets(temp1);
	 printxy(30,13,"ENTER THE PASSWORD");
	while(1)
	{
		ch=getch();
		if(ch==13)
		break;
		printf("*");
		temp2[i++]=ch;
	}
	temp2[i]='\0';
	if(!strcmp(uname,temp1)&&!strcmp(temp2,pwrd))
	{


	center(21,"Welcome In Main Menu");
	getch();

   do
   {
     system("cls");
     twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);

     center(7,"MAIN MENU");
     printxy(30,9,"Press:");
     /*printxy(30,10,"[T]-Time Table");*/
     printxy(30,11,"[A]-Create File");
     printxy(30,12,"[B]-Add Record");
     printxy(30,13,"[C]-List Record");
     printxy(30,14,"[D]-LOGIN MENU");
     printxy(30,15,"[S]-Search Record");
     printxy(30,16,"[M]-Modify Record");
     /*printxy(30,16,"[V]-List Time");*/
     printxy(30,17,"Enter your choice..."); gotoxy(50,16);
     choice=getch(); choice=toupper(choice);
       switch(choice)
       {
	  case 'A': Create(); break;
	  case 'B': Add(); break;
	  case 'C': List(); break;
	  case 'S': search();break;
	  case 'D': main(); break;
	  case 'M': modify();break;
	  /*case 'V': Lists();break;*/
	  /*case 'Q': subject();break;*/
	  /*default: Err_mess(); break;*/
       }
   }
   while(choice!='D');
}
getch();
}

void user()
{
    char recno[13],m;
    int found;
    system("cls");
    fp=fopen("temp1.dat","a+");
    twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);
     center(22,"Copyright (C) 2016, 2017 LOGICVIEW SOFTECH");
     center(7,"LOGIN");
     printxy(30,11,"ENTER THE LOGIN ID-");
	 gotoxy(37,15);
    scanf("%s", &recno);
    system("cls");

while(fscanf(fp,"%s %s %s %c %c %s %s %s %s %s %s",&e.snum,&e.fname,&e.sname,&e.year,&e.section,&e.ccode,&e.father,&e.sfather,&e.mother,&e.smother,&e.cont)!=EOF)
{
if(strcmp(recno,e.snum)==0)

{
twolinebox(2,6,79,20);
  twolinebox(2,20,79,24);
  twolinebox(2,2,79,24);
  center(4,"DETAIL OF STUDENT");
  gotoxy(6,8);
  printf("Student no: %s",e.snum);
  gotoxy(6,9);
  printf("First Name: %s",e.fname);
  gotoxy(6,10);
  printf("Last Name: %s",e.sname);
  gotoxy(6,11);
  printf("Section: %c",e.section);
  gotoxy(6,12);
  printf("Year: %c",e.year);
  gotoxy(6,13);
  printf("Course Code: %s",e.ccode);
  gotoxy(6,14);
  printf("Father Name: %s %s",e.father,e.sfather);
  gotoxy(6,15);
  printf("Mother Name: %s %s",e.mother,e.smother);
  gotoxy(6,16);
  printf("Contact Num: +91-%s",e.cont);
  center(21," Main Menu Press Any Key");
  center(22," Modify The Record Press-[M]");
  m=getch(); m=toupper(m);
  switch(m)
  {
      case 'M' : modify();
                 break;
      case 'B' : main();
                 break;
  }

}
else if(strcmp(recno,e.snum)!=0)
{

    twolinebox(2,2,79,25);
center(15,"Sorry No Record Found");
}
}
getch();
}


int main(void)
{
    /*WinExec("attrib +h C:\\users\\public\\TimeTable.dat /S /D",SW_HIDE);*/

    char choice;
    do
   {
     system("cls");
     system("color 97");
     twolinebox(29,6,51,8);
     twolinebox(20,5,60,18);
     twolinebox(2,20,79,25);
     twolinebox(2,2,79,25);

     center(7,"LOGIN MENU");
     printxy(30,9,"Press:");
     printxy(30,11,"[A]-ADMIN");
     printxy(30,12,"[B]-USER");
     printxy(30,13,"[Q]-QUIT");
      center(22,"Copyright (C) 2016, 2017 LOGICVIEW SOFTECH");
   printxy(30,16,"Enter your choice..."); gotoxy(50,16);
     choice=getch(); choice=toupper(choice);
       switch(choice){
	  case 'A': admin(); break;
	  case 'B': user(); break;
	 case 'Q': Quit(); break;
	  /*default: Err_mess(); break;*/
       }
   }while(choice!='Q');
}
