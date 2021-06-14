#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

class product
{
public:
int product_id;
int price;
string namep;

void product_input()
{
cout<<endl<<"Enter Id of Product : ";
cin>>product_id;

cout<<endl<<"Enter the name of product : ";
cin>>namep;

cout<<endl<<"Enter the price of product : ";
cin>>price;
}

int get_price()
{
    return price;
}

string get_namep()
{
    return namep;
}

};
class customer
{

 string mem;
string name;
string address;
int memId;

public:
product *list[5];
int cnt=0;
void purchase(product *A)
{
 list[cnt]=new product;
list[cnt++] = A;
}
void printlist()
{
    for(int i=0;i<cnt;i++)
    {
        string str=list[i]->get_namep();
        cout<<endl<< i+1<<"."<<str<<endl;
    }
}
customer(string a,string b,string t){
    name=a;
    address=b;
    mem=t;
 if(mem=="yes" || mem=="YES" || mem=="Yes"){
cout<<"enter membership ID : ";
 cin>>memId;
 }
}

customer(){
    name="empty";
    address="empty";
    mem="empty";
    memId=0;
}

void get_customer(){
 cout<<"Enter name of the customer : ";
 cin>>name;

 cout<<endl<<"Enter address : ";
 cin>>address;

 cout<<endl<<"Are you a member ? (yes/no) :";
 cin>>mem;

 if(mem=="yes" || mem=="YES" || mem=="Yes")
 {
     cout<<endl<<"Enter memberID : ";
     cin>>memId;
 }
}

string get_name()
{
    return name;
}
ll totalcost()
{
    ll tc=0;
    for(int i=0;i<cnt;i++){
        tc+=list[i]->get_price();
    }

    return tc;
}

ll dis(){
 ll sm=0;
 for(int i=0;i<cnt;i++){
 if(mem=="yes" || mem=="YES" || mem=="Yes"){
        sm+=list[i]->get_price()*0.3;
 }
 else{
     sm+=list[i]->get_price();
 }

 return sm;
}
}
};
int main()
{
 customer c;
 c.get_customer();
 cout<<endl;
 int k;
 cout<<"no of products: ";
 cin>>k;
 cout<<endl;
 while(k--){
 product *p=new product;
 p->product_input();
 c.purchase(p);
}

cout<<endl<<" DEAR "<<c.get_name() << " YOUR BILL IS READY!!!";
cout<<endl<<" List of products you bought : ";
c.printlist();

int total=c.totalcost();
int discount=c. dis();
int price=total-discount;
cout<<endl<<"You availed a total discount of : Rs "<<discount;
cout<<endl<<"Total bill is : Rs "<<price;

return 0;
}

