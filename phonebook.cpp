#include <iostream>
#include <string>
using namespace std;
struct node
{
string firstName;
string lastName;
string phone;
char gender;
string mail;
node *next;
};
class List
{
private:
node *head, *tail;
public:
List()
{
head = NULL;
tail = NULL;
}
void create_contact(string first, string last,string phone,char gender,string mail)
{
node *temp = new node;
temp->firstName = first;
temp->lastName = last;
temp->phone=phone;
temp->gender=gender;
temp->mail=mail;
temp->next = NULL;
if (head == NULL)
{
head = temp;
tail = temp;
temp = NULL;
}
else
{
tail->next = temp;
tail = temp;
}
}
void display_all()
{
int contactNum = 1;
node *temp = new node;
temp = head;
while (temp != NULL)
{
cout << "\nContact Number: " << contactNum << endl;
cout << "First Name: " << temp->firstName << endl;
cout << "Last Name: " << temp->lastName << endl;
cout<<"phone number: "<<temp->phone<<endl;
cout<<"gender: "<<temp->gender<<endl;
cout<<"mail id: "<<temp->mail<<endl;
++contactNum;
temp = temp->next;
}
}
int search(string x)
{
int position=0;
node* current = head;
while (current->firstName != x)
{
current=current->next;
}
cout<<"contact found\n ";
return 1;
}
void updatefirst(string x,string fn)
{
int t=search(x);
if(t==1)
{
cout<<"first name can be updated."<<endl;
node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->firstName=fn;
}
}
void updatelast(string x,string fn)
{
int t=search(x);
if(t==1)
{
cout<<"lastt name can be updated."<<endl;
node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->lastName=fn;
}
}
void updatenum(string x,string fn)
{
int t=search(x);
if(t==1)
{
cout<<"phone number can be updated."<<endl;
node *ptr=head;
while(ptr->firstName!=x)
{
ptr=ptr->next;
}
ptr->phone=fn;
}
}

string modifiedsearch(string x)
{
string t="No match found.";
node*ptr=head;
int s=x.length();
while(ptr!=NULL)
{
if(x.substr(0,x.length())==ptr->firstName.substr(0,x.length()))
{

cout << "First Name: " << ptr->firstName << endl;
cout << "Last Name: " << ptr->lastName << endl;
cout<<"phone number: "<<ptr->phone<<endl;
cout<<"gender: "<<ptr->gender<<endl;
cout<<"mail id: "<<ptr->mail<<endl;
ptr=ptr->next;
}
else
{
}
ptr=ptr->next;
}
}
void delete_n(string x)
{
node *prevptr=head;
node *temp=NULL;
node *currentptr=head->next;
int m=search(x);
if(m==1)
{
if(prevptr->firstName==x)
{
prevptr=prevptr->next;
head=prevptr;
}
else
{
while(currentptr!=NULL)
{
if(currentptr->firstName==x)
{
}
else
{
}
}
}
temp=currentptr;
currentptr=NULL;
prevptr=prevptr->next;
currentptr=currentptr->next;
if(temp!=NULL)
{
}
else
{
prevptr->next=temp->next;
cout<<"Contact deleted..."<<endl;
cout<<"Contact doesn''t exist... "<<endl;
}
}
}
};
int main()
{
List Contacts;
int choice, position;
string firstName,m;
string lastName;
string phone ;
char gender;
string mail;
string t;
do {
cout << "\nWhat would you like to do?: " << endl;
cout << "1. Show All Contacts " << endl;
cout << "2. Add A Contact " << endl;
cout << "3. Remove A Contact " << endl;
cout << "4. Search Contacts " << endl;
cout<< "5. Update contact "<<endl;
cout << "6. Exit The Program " << endl;
cin >> choice;
char hh;
node *temp = new node;
switch (choice)
{
case 1:
cout << endl;
Contacts.display_all();
cout << endl;
break;
case 2:
cout <<endl<< "Enter your first name: ";
cin >> firstName;
cout <<endl<< "Enter your last name: ";
cin >> lastName;
cout<<endl<<"enter the phone number: ";
cin>>phone;
cout<<endl<<"enter the gender: ";
cin>>gender;
cout<<endl<<"enter mail id: ";
cin>>mail;
Contacts.create_contact(firstName, lastName,phone,gender,mail);
cout << endl;
break;
case 3:
cout << "Enter the name of the contact you would like to remove: ";
cin>>firstName;
Contacts.delete_n(firstName);
break;
case 4:
cout<<"Enter the initials of name you want to search for:"<<endl;
cin>>t;
Contacts.modifiedsearch(t);
break;
case 5:
int choice;
cout<<" enter 1 to change first name\n enter 2 to change last name\n enter 3 to change phone number\n "<<endl;
cin>>choice;
if(choice==1){
cout<<"enter first name to be changed"<<endl;
cin>>firstName;
cout<<"enter new first name"<<endl;
cin>>m;
Contacts.updatefirst(firstName,m);
}
else if(choice==2){
cout<<"enter first name to be changed"<<endl;
cin>>firstName;
cout<<"enter new last name"<<endl;
cin>>m;
Contacts.updatelast(firstName,m);
}
else if(choice==3){
cout<<"enter first name of the contact who's number you want to change"<<endl;
cin>>firstName;
cout<<"enter new number"<<endl;
cin>>m;
Contacts.updatenum(firstName,m);
}

else
cout<<"enter a valid option";
break;
case 6:
exit(1);
break;
default:
cout << "Please select a valid option." << endl;
break;
}
}while(choice!=0);
}

