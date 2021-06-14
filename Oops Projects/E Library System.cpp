 #include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

class book	{
private:
	char *author,*title;
	float *price;
	int *stock;

public:
	book()	{
	author= new char[20];
	title=new char[20];
	price= new float;
	stock=new int;

	}
	void feeddata();
	void showdata();
	int search(char[],char[]);
	void buybook();


};

void book::feeddata()	{
	cin.ignore();
	cout<<"\nEnter Author Name: ";      cin.getline(author,20);
	cout<<"Enter Title Name: ";       cin.getline(title,20);
	cout<<"Enter Price: ";            cin>>*price;
	cout<<"Enter Stock Position: ";   cin>>*stock;

}


void book::showdata()	{
	cout<<"\nAuthor Name: "<<author;
	cout<<"\nTitle Name: "<<title;

	cout<<"\nPrice: "<<*price;
	cout<<"\nStock Position: "<<*stock;

}

int book::search(char tbuy[20],char abuy[20] )	{
	if(strcmp(tbuy,title)==0 && strcmp(abuy,author)==0)
		return 1;
	else return 0;

}

void book::buybook()	{
	int count;
	cout<<"\nEnter Number Of Books to buy: ";
	cin>>count;
	if(count<=*stock)	{
		*stock=*stock-count;
		cout<<"\nBooks Bought Sucessfully";
		cout<<"\nAmount: Rs. "<<(*price)*count;
	}
	else
		cout<<"\nRequired Copies not in Stock";
}
int removeColon(string s)
{
    if (s.size() == 4)
        s.replace(1, 1, "");

    if (s.size() == 5)
        s.replace(2, 1, "");

    return stoi(s);
}
int diff(string s1, string s2)
{
    int time1 = removeColon(s1);
    int time2 = removeColon(s2);

    int hourDiff = time2 / 100 - time1 / 100 - 1;
    int minDiff = time2 % 100 + (60 - time1 % 100);

    if (minDiff >= 60) {
        hourDiff++;
        minDiff = minDiff - 60;
    }
    int x=hourDiff*3600+minDiff*60;
    return x;
}
void bookslot()
{
	string starttime;
	string endtime;
    cout<<"\nEnter starttime : ";
    cin>>starttime;
	cout<<"\nEnter endtime: ";
	cin>>endtime;

	cout<<"YOUR SLOT HAS BEEN SUCCESSFULLY BOOKED !!";

	int x=diff(starttime,endtime);
	int hours=x/3600;
    int minutes=(x%3600)/60;
    cout <<endl<<"Duration of your slot is : "<< hours <<" hours "<< minutes<<" minutes ";

    cout<<endl<<"The total amount to be paid : Rs "<<x*2<<endl;



}
int main()	{
	book *B[20];
	int i=0,r,t,choice;
	char titlebuy[20],authorbuy[20];
	while(1)	{
		cout<<"\n\n\t\tMENU"
		<<"\n1. Entry of New Book"
		<<"\n2. Buy Book"
		<<"\n3. Search For Book"
		<<"\n4. Book time slot for reading in library"
		<<"\n5. Exit"
		<<"\n\nEnter your Choice: ";
		cin>>choice;

		switch(choice)	{
			case 1:	B[i] = new book;
				B[i]->feeddata();
				i++;	break;

			case 2: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);
				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						B[t]->buybook();
						break;
					}
				}
				if(t==1)
				cout<<"\nThis Book is Not in Stock";

				break;
			case 3: cin.ignore();
				cout<<"\nEnter Title Of Book: "; cin.getline(titlebuy,20);
				cout<<"Enter Author Of Book: ";  cin.getline(authorbuy,20);

				for(t=0;t<i;t++)	{
					if(B[t]->search(titlebuy,authorbuy))	{
						cout<<"\nBook Found Successfully";
						B[t]->showdata();
						break;
					}
				}
				if(t==i)
				cout<<"\nThis Book is Not in Stock";
				break;
			case 4: cin.ignore();
				bookslot();
						break;



			case 5: exit(0);
			default: cout<<"\nInvalid Choice Entered";

		}
	}




	return 0;
}
