#include<iostream>
#include<fstream>
#include<string>
#include<stdlib.h>
#include<cstdio>
using namespace std;
class shopping
{
private:
    int pcode;
    int price;
    int dis;
    string pname;
public:
    void menu();
    void adminstr();
    void buyer();
    void add();
    void edit();
    void remv();
    void lst();
    void receipt();
};
void shopping :: menu()
{
    int choice;
    string email;
    string paswrd;
    do
    {
        cout<<"\n\n\n\n\t\t\t\t--------------------------------------\n\n";
        cout<<"\t\t\t\t        Supermarket Main Menu         \n\n";
        cout<<"\t\t\t\t--------------------------------------\n\n";
        cout<<"\t\t\t\t\t| 1) Administrator  |\n\n";
        cout<<"\t\t\t\t\t| 2) Buyer          |\n\n";
        cout<<"\t\t\t\t\t| 3) Exit           |\n\n";
        cout<<"\n\t\t\t   Please select: ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<"\n\t\t\t   Please login \n";
            cout<<"\t\t\t   Enter Email: " ;
            cin>>email;
            cout<<"\n\t\t\t    Password: ";
            cin>>paswrd;

            if(email=="roby@gmail.com"&&paswrd=="roby123")
            {
                adminstr();
            }
            else
                cout<<"\nInvalid Email or Password\n";
            break;
        case 2:
            buyer();
            break;
        case 3:
            cout<<"\n\t\t\tThank you for your Interest!\n";
            break;
        default:
            cout<<"\n\t\t Please Select from the given option!\n";

        }
    }
    while(choice!=3);
}
void shopping::adminstr()
{
    int choice;
    do
    {
        cout<<"\n\n\t\t\tAdministrator Menu ";
        cout<<"\n\t\t\t|________1) Add the product_____________|";
        cout<<"\n\t\t\t|                                       |";
        cout<<"\n\t\t\t|________2) Modify the product__________|";
        cout<<"\n\t\t\t|                                       |";
        cout<<"\n\t\t\t|________3) Delete the product__________|";
        cout<<"\n\t\t\t|                                       |";
        cout<<"\n\t\t\t|________4) Back to main menu___________|";
        cout<<"\n\n\t\t Please select your choice!";
        cin>>choice;

        switch(choice)
        {
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            remv();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"\n\t\tInvalid choice! Please select from the given option.";
        }
    }
    while(1);
}
void shopping::buyer()
{
    int choice;
    do
    {
        cout<<"\n\t\t\t  Buyer    \n";
        cout<<"\t\t\t_____________\n\n";
        cout<<"\t\t\t 1) Buy product \n\n";
        cout<<"\t\t\t 2) Go back     \n\n";

        cout<<"\t\tPlease select your choice \t:  ";
        cin>>choice;

        switch(choice)
        {
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"\n\n\t\t\t Invalid choice \n";
        }
    }
    while(1);
}
void shopping::add(){
    int token = 0;
    m:
        int c;
        float p;
        float d;
        string n;

        cout<<"\n\t\t\tAdd new product\n";
        cout<<"\n\tProduct_code of product:  ";
        cin>>pcode;
        cout<<"\n\tName of the product:  ";
        cin>>pname;        cout<<"\n\tPrice of the product:  ";
        cin>>price;
        cout<<"\n\tDiscount on product:  ";
        cin>>dis;
        fstream data;
        data.open("Market_Database.txt",ios::in);

        if(!data){
            data.open("Market_Database.txt",ios::out | ios::app);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
        }
        else{
           data>>c>>n>>p>>d;
           while(!data.eof()){
            if(c==pcode)
                token++;
            data>>c>>n>>p>>d;
           }
           data.close();
           if(token == 1){
            cout<<"\n\t\tAlready inserted\n";
            goto m;
           }
           else{
            data.open("Market_Database.txt",ios::out | ios::app);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            data.close();
           }
        }

    cout<<"\n\n\t\t\t Record Inserted !\n";
}

void shopping::edit(){
    fstream data, data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\tModify the record\n";
    cout<<"\n\t\t\tProduct code\n";
    cin>>pkey;
    data.open("Market_Database.txt",ios::in);
    if(!data){
        cout<<"\n\t\tFile doesn't exist ";
    }
    else{
        data1.open("Market_Database1.txt",ios::out | ios::app);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\tNew product code: ";
                cin>>c;
                cout<<"\n\t\tName of the product: ";
                cin>>n;
                cout<<"\n\t\tPrice: ";
                cin>>p;
                cout<<"\n\t\tDiscount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\t\tRecord edited\n";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("Market_Database.txt");
        rename("Market_Database1.txt","Market_Database.txt");

        if(token==0){
            cout<<"\n\t\tRecord not found, sorry!\n";
        }
    }
}

void shopping::remv(){
    fstream data, data1;
    int pkey;
    int token = 0;

    cout<<"\n\t\t\tDelete Product\n";
    cout<<"\t\t\tProduct code\n";
    cin>>pkey;
    data.open("Market_Database.txt",ios::in);
    if(!data){
        cout<<"\n\t\tFile doesn't exist ";
    }
    else{
        data1.open("Market_Database1.txt",ios::out | ios::app);

        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\tData delete successfully\n";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("Market_Database.txt");
        rename("Market_Database1.txt","Market_Database.txt");

        if(token==0){
            cout<<"\n\t\tRecord not found, sorry!\n";
        }
    }
}

void shopping::lst(){
    fstream data;
    data.open("Market_Database.txt",ios::in);
    cout<<"\n\n____________________________________________________________\n";
    cout<<"\tProduct_No.\t\tProduct_Name\t\tProduct_Price\n";
    cout<<"\n\n____________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<"  \t"<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<endl;
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}

void shopping::receipt(){
    fstream data;

    int arrc[100];
    int arrq[100];
    string choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;

    cout<<"\n\n\t\t\tReceipt \n";
    data.open("Market_Database.txt",ios::in);
    if(!data){
        cout<<"\n\t\tEmpty Database\n";
    }
    else{
        data.close();
        lst();
        cout<<"\n\n\t______________________________________\n\n";
        cout<<"\n\t           Please Place order          \n\n";
        cout<<"\n\t______________________________________\n";
        do{
            m:
            cout<<"\n\tEnter Product code: ";
            cin>>arrc[c];
            cout<<"\n\n\tEnter Product quantity: ";
            cin>>arrq[c];
            for(int i=0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\n\tDuplicate Product code. Please try again!\n";
                    goto m;
                }

            }
            c++;
            cout<<"\n\tDo you want to buy another product? If yes then press y else no: ";
            cin>>choice;
        }
        while(choice=="y");

        cout<<"\n\n\t\t\t___________________Receipt_____________________________";
        cout<<"\n\nProduct_No.\tProduct_name\tProduct_quantity\tPrice\tAmount\tAmount with discount\n";

        for(int i=0;i<c;i++){
            data.open("Market_Database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode==arrc[i]){
                    amount = price*arrq[i];
                    dis = amount - (amount*dis/100);
                    total = total+dis;
                    cout<<"\n\t"<<pcode<<"\t\t"<<pname<<" \t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
            data.close();
        }

    }
    cout<<"\n\n\t_______________________________________";
    cout<<"\n\t\t\tTotal amount: "<<total<<endl;
}
int main()
{
    shopping s;
    s.menu();
    return 0;
}
