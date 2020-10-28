#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
struct account
 {
  long accno,balance;
  char name[20];
 };

int insert(account queue[]);
void remove(account queue[]);
void display(account queue[]);

const int size=10;
int front=-1, rear=-1;

void main()
{clrscr();

 account Queue[size];
 int res;
 char ch='y';

 while(ch=='y')
 {
  res=insert(Queue);
  if(res==-1)
  {
  cout<<"OVERFLOW , Aborting"<<endl;
  exit(1);
  }
  else
  cout<<"\naccount inserted successfully \n\n";
  cout<<"Want to enter more accounts (y-yes/n-no) : ";
  cin>>ch;
 }

 cout<<"\nThe queue now is \n";
 display(Queue);

 cout<<"\nenter your choice to delete an account (y/n) : ";
 cin>>ch;
 while(ch=='y')
 {
  remove(Queue);
  cout<<"\nWant to delete more (y/n) : ";
  cin>>ch;
 }
 cout<<"\nThe queue now is \n";
 display(Queue);

getch();
}

int insert(account queue[])
{
 if(rear==size-1)
 return -1;

 else
 {
  if(rear==-1)
  rear=front=0;
  else
  rear++;

  cout<<"enter details of account number to be added \n";
  cout<<"enter account number : ";
  cin>>queue[rear].accno;
  cout<<"enter name : ";
  gets(queue[rear].name);
  cout<<"enter account balance : ";
  cin>>queue[rear].balance;

  return 0;
 }
}

void remove(account queue[])
{
 if(front==-1)
  {
  cout<<"UNDERFLOW , Abortimg \n";
  exit(1);
  }

 else
 {
  cout<<"account deleted is \n";
  cout<<"account number : "<<queue[front].accno<<"\n"
      <<"account name : "<<queue[front].name<<"\n"
      <<"account balance : "<<queue[front].balance<<"\n";

  if(front==rear)
  front=rear=-1;
  else
  front++;
 }
}

void display(account queue[])
{
 if(front==-1)
 {
 cout<<"UNDERFLOW";
 exit(1);
 }

 for(int i=front;i<=rear;++i)
 {
 cout<<"account number:"<<queue[i].accno<<endl;
 cout<<"name :"<<queue[i].name<<endl;
 cout<<"balance :"<<queue[i].balance<<endl;
 }
}