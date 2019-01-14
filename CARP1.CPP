#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<string.h>
class p_lot
{
public:
p_lot()
{
next=NULL;
}
char pos[2];
p_lot *next;

}*stack;
class user
{
private:
int empno,code;
char un[50],dun[70],add[50],nmpl[60],con[21],col[45],type[66],email[77],make[22],acomp[30];
public:
p_lot p_pos;
user *link;
void inputc()
{
cout<<"\n*********************************************************";
cout<<"\nWelcome to the parkinglot";
cout<<"\nEnter your name:";
cin>>un;
cout<<"\nEnter the pasengers name if any:";
cin>>dun;
cout<<"\nEnter your address:";
cin>>add;
cout<<"\nEnter your E-maill ID:";
cin>>email;
cout<<"\nEnter the contact number:";
cin>>con;
cout<<"\nEnter the number plate number:";
cin>>nmpl;
cout<<"\nEnter the type of vehicle:";
cin>>type;
cout<<"\nEnter the colour of the vehicle:";
cin>>col;
cout<<"\nEnter the manufacterer:";
cin>>make;
cout<<"\nEnter the desired code:";
cin>>code;
link=NULL;
}

void linking(user*np)
{
link=np;
}

user* retlink()
{
return link;
}

int retcode()
{
return code;
}
char* retname()
{
return un;
}
char* retpname()
{
return dun;
}
char* retnmpl()
{
return nmpl;
}
char* rettype()
{
return type;
}
char* retemail()
{
return email;
}
char* retcon()
{
return con;
}char* retaddr()
{
return add;
}
char* retcolor()
{
return col;
}
char* retmanu()
{
return make;
}

void inputa()
{
cout<<"\n*********************************************************";
cout<<"\nEnter the emp-no:";
cin>>empno;
cout<<"\nEnter the acomp:";
cin>>acomp;
cout<<"\nEnter your name:";
cin>>un;
}

void showc()
{
cout<<"\nName -"<<un;
cout<<"\nAcomp name -"<<dun;
cout<<"\nAddress -"<<add;
cout<<"\nEmaill -"<<email;
cout<<"\nContact number -"<<con;
cout<<"\nNumber plate -"<<nmpl;
cout<<"\nType -"<<type;
cout<<"\nColour -"<<col;
cout<<"\nManufacterer"<<make;
}
}*start,*save,*now,*next;

void insertnode(user*np)
{
if(start==NULL)
{
start=np;
}
else
{
save=start;
start=np;
np->linking(save);
}
}
void push(p_lot *temp)
{
p_lot *mov;
mov=stack;
while(mov->next!=NULL)
{
mov=mov->next;
}
mov->next=temp;
}
void  leave()
{
user*np,f;
ofstream wf;
int cn;
np=start;
cout<<"\nPlease enter your code...";
cin>>cn;
wf.open("vehicle.dat",ios::out|ios::app);
if(np->retcode()==cn)
{
cout<<"\nThank you for using our parking lot, please come again...";
save=np;
wf.write((char*)save,sizeof(user));
start=np->retlink();
}
else
while(np->retlink()!=NULL)
{

if(cn==np->retlink()->retcode())
{
cout<<"\nThank you for using our parking lot, please come again...";
save=np->retlink();
wf.write((char*)save,sizeof(user));
np->linking(np->retlink()->retlink());
break;
}
np=np->retlink();
}
push(&(save->p_pos));
wf.close();
}
void searchfilename()
{
ifstream f;
user p;
int flag=0;
char nm[50];
cout<<"Enter the name to be searched:";
cin>>nm;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retname(),nm)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfilenmpl()
{
ifstream f;
user p;
int flag=0;
char num[50];
cout<<"Enter the number of the plate number:";
cin>>num;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retnmpl(),num)==0)
{
p.showc();
flag=1;
break;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfilepname()
{
ifstream f;
user p;
int flag=0;
char pnm[50];
cout<<"Enter the name of the passenger to be searched:";
cin>>pnm;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retpname(),pnm)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfileadd()
{
ifstream f;
user p;
int flag=0;
char addr[50];
cout<<"Enter the address to be searched:";
cin>>addr;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retaddr(),addr)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfileemail()
{
ifstream f;
user p;
int flag=0;
char em[50];
cout<<"Enter the email to be searched:";
cin>>em;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retemail(),em)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfilecon()
{
ifstream f;
user p;
int flag=0;
char cont[50];
cout<<"Enter the number of the plate number:";
cin>>cont;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retcon(),cont)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfilecol()
{
ifstream f;
user p;
int flag=0;
char col[50];
cout<<"Enter the color of the vehecle to be searched:";
cin>>col;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retcolor(),col)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfiletype()
{
ifstream f;
user p;
int flag=0;
char type[50];
cout<<"Enter the type of the vehecle to be searched:";
cin>>type;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.rettype(),type)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchfilemanu()
{
ifstream f;
user p;
int flag=0;
char man[50];
cout<<"Enter the number of the plate number:";
cin>>man;
f.open("vehicle.dat",ios::in);
f.seekg(0);
while(!f.eof())
{
f.read((char *)&p,sizeof(user));
if(strcmp(p.retmanu(),man)==0)
{
p.showc();
flag=1;
}
}
if(flag==0)
{
cout<<"Record not found!";
}
f.close();

}
void searchll()
{
int cod,flag=0;
cout<<"Enter the code:";
cin>>cod;
if(cod>10)
{
cout<<"Parking lot not Available!";
}
next=start;
while(next!=NULL)
{
if(cod==next->retcode())
{
next->showc();
flag=1;
break;
}
next=next->retlink();
}
if(flag==0)
{
cout<<"Empty lot!";
}
}
p_lot* pop()
{
p_lot *temp,*temp1;
if(stack==NULL)
{
return NULL;
}
else
{
if(stack->next==NULL)
{
temp1=stack;
stack=NULL;
return temp1;
}
else
{
temp=stack;
while(temp->next->next!=NULL)
{
  temp=temp->next;
}
temp1=temp->next;
temp->next=NULL;
return temp1;

}
}
}
void insertlot(user *new1,p_lot *temp)
{
new1->p_pos=*temp;
cout<<"\nThe parking Location assigned for you is:"<<new1->p_pos.pos<<"\n";
}
void create_parkinglot()
{
int i=0;
p_lot *new1,*temp;
char name[][2]={'A','0','A','1','A','2','A','3','A','4','A','5','A','6','A','7','A','8','A','9'};
while(i<10)
{
new1=new p_lot();
new1->pos[0]=name[i][0];
new1->pos[1]=name[i][1];
if(stack==NULL)
stack=new1;
else
{
temp=stack;
while(temp->next!=NULL)
temp=temp->next;
temp->next=new1;
}
i++;
}

}

void main()
{
user *x,*xp;
int n=0,s,space=10,v,a;
p_lot *temp=NULL;
stack=NULL;
clrscr();
create_parkinglot();
while(n!=3)
{

cout<<"\nWelcome to the parking lot";
cout<<"\n**************************"<<"\n1.I am a customer"<<"\n2.I am the administrator."<<"\n3.Exit";
cout<<"\nEnter your choice";
cin>>n;
if(n==1)
{
cout<<"\n1.Register"<<"\n2.Logout"<<"\n3.Exit"<<"\nEnter your choice:";
cin>>s;
switch(s)
{
case 1:
x=new user();
x->inputc();
xp=x;
temp=pop();
cout<<"\nDetails are successfully entered...";
if(temp!=NULL)
if(xp!=NULL&&space!=0)
{
cout<<"\nCreated record successfully"<<"\nEntering into the database";
       //	cout<<xp;
insertnode(xp);
insertlot(xp,temp);
space--;
}
else if(xp!=NULL&&space==0)
{
cout<<"\nParking lot is full";
}
else
{
cout<<"\nMallfunction...";
}
else
cout<<"\nParking lot is full";
break;
case 2:
leave();
break;

}
}
else if(n==2)
{
cout<<"\n1.Search the Vehicles in the Parking Lot"<<"\n2.Search the records "<<"\nEnter your choice";
cin>>v;
switch(v)
{
case 1:
searchll();
break;//TO SEARCH FOR THE CAR IN THE LINKED LIST
case 2://TO SEARCH FOR THE CAR IN THE CAR USING THE FILE CREATED IN THE FUNCTION LEAVE
cout<<"\nSearch the records by";
cout<<"\n1.Name";
cout<<"\n2.Passenger name";
cout<<"\n3.Address";
cout<<"\n4.E-Mail";
cout<<"\n5.Contact number";
cout<<"\n6.Number plate number";
cout<<"\n7.Type of vehicle";
cout<<"\n8.Color of the vehicle";
cout<<"\n9.Manufacterer";
cout<<"\nEnter your option:-";
cin>>a;
if(a==1)
{
searchfilename();
}
if(a==2)
{
searchfilepname();
}
if(a==3)
{
searchfileadd();
} if(a==4)
{
searchfileemail();
}
if(a==5)
{
searchfilecon();
}
if(a==6)
{
searchfilenmpl();
}
if(a==7)
{
searchfiletype();
}
if(a==8)
{
searchfilecol();
}
if(a==9)
{
searchfilemanu();
}

break;
}
}
}
}