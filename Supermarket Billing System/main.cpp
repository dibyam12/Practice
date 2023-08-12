#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<windows.h>


using namespace std;

class shopping{
  private:
  int pcode;
  float discount;
  float price;
  string pname;
  int quantity;
  public:
  void Mainmenu();
  void adminstrator();
  void adminpannel();
  void add();
  void buyer();
  void edit();
  void rem();
  void receipt();
  void lists();
  void login();
  void registration();
  void forgot();
};


void shopping :: Mainmenu(){
  m:
  int choice;
  system("cls");
  string email;
  cout<<"\t\t\t\t\t\t__________________________\t\t\t\t\t\t\n";
  cout<<"\t\t\t\t\t\t   Shopping Center List   \t\t\t\t\t\t\n";
  cout<<"\t\t\t\t\t\t__________________________\t\t\t\t\t\t\n\n";
  cout<<"\t\t\t\t\t\t   1) | Administrator |       \t\t\t\t\t\t\n";
  cout<<"\t\t\t\t\t\t   2) | Buyer |             \t\t\t\t\t\t\n";
  cout<<"\t\t\t\t\t\t   3) | Exit  |              \t\t\t\t\t\t\n";
  cout<<"\n\t\t\t\t\t\t   Please Enter a Choice : ";
  cin>>choice;
  system("cls");
  switch(choice)
  {
   case 1:
      adminpannel();
      break;
    case 2:
      buyer();
      break;
    case 3:
      exit(0);
      break;
    default:
      cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t Please Enter a Valid Chocie!!! ";
      sleep(3);
      break;
  }
  goto m;
}

void shopping::adminpannel(){
    int choice;
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\t\t\t\t\t Welcome To Admin Pannel ";
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\t\t\t\t | 1) Login |";
    cout<<"\n\n\t\t\t\t | 2) Register |";
    cout<<"\n\n\t\t\t\t | 3) Forgot Password |";
    cout<<"\n\n\t\t\t\t | 4) Mainmenu |";
    cout<<"\n\n\t\t\t\t Enter Choice : ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        login();
        break;
    case 2:
        registration();
        break;
    case 3:
        forgot();
        break;
    case 4:
        Mainmenu();
        break;
    default:
        cout<<"\n\n\n\n\n\t\t\t\t\t\t Please Enter a Valid Choice !!!";
        break;
    }
}

void shopping::login(){
    int count=0;
    string userId , Id;
    int password, pass ;
    system("cls");
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\t\t\t\t\t\t\t LOGIN";
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t\tPlease Enter the Email and Password";
    cout<<"\n\n\t\t\t\t Email : ";
    cin>>userId;
    cout<<"\n\n\t\t\t\t Password : ";
    cin>>password;
    ifstream input("records.txt");
    while(input>>Id>>pass){
        if(Id==userId && pass==password){
            count=1;
            system("cls");
        }
    }
    input.close();
    if(count==1){
        cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t\t Login successfull !!!";
        sleep(3);
        system("cls");
        adminstrator();
    }
    else{
            system("cls");
        cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t Login ERROR !!!  ";
        sleep(3);
        Mainmenu();
    }
}


void shopping::registration(){
    string ruserId ,rId ;
    int rpassword , rpass;
    system("cls");
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t\t\t\t REGISTRATION FORM ";
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t Enter Username or Email  : ";
    cin>>ruserId;
    cout<<"\n\n\t\t\t\t Enter Password  : ";
    cin>>rpassword;
    ofstream f1("records.txt",ios::app);
    f1<<ruserId<<" "<<rpassword<<endl;
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t Registration Successful !!! ";
    sleep(3);
    adminpannel();
}

void shopping::forgot(){
    m:
    int option;
    system("cls");
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t\t\t Forgotten Password ! No Worries !";
    cout<<"\n\t--------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t\t\t\t | Press 1 to search your Id by username | ";
    cout<<"\n\n\t\t\t\t | Press 2 to go back to the Mainmenu    | ";
    cout<<"\n\n\t\t\t\t Enter your choice : ";
    cin>>option;
    switch(option)
    {
        case 1:
        {
            int count=0;
            string suserId ,sId;
            int pass ;
            system("cls");
            cout<<"\n\n\t\t\t\t Enter the last user name you remembered  : ";
            cin>>suserId;
            ifstream f2("records.txt");
            while(f2>>sId>>pass){
                if(sId==suserId){
                    count=1;
                }
            }
            f2.close();
            if(count==1){
                cout<<"\n\n\t\t\t\t Your account is found !! ";
                cout<<"\n\n\t\t\t\t Your password is : "<<pass;
                sleep(5);
                Mainmenu();
            }
            else{
                cout<<"\n\n\t\t\t\t Your account is not found !!!";
                sleep(3);
            }
            break;
        }
        case 2:
        {
        Mainmenu();
        break;
        }
        default:
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\t\t\t\t\t\t Wrong Choice !!! Try Again ";
            sleep(3);
            break;
    }
    goto m;
}

void shopping::adminstrator(){
  m:
  int yourchoice;
  system("cls");
  cout<<"\n\n\t\t****************************************************************************************";
  cout<<"\n\t\t\t\t\t Welcome to Admin Pannel !!!";
  cout<<"\n\t\t***************************************************************************************";
  cout<<"\n\n\t\t\t\t\t  1) | Add Items | ";
  cout<<"\n\t\t\t\t\t  2) | Modify Items | ";
  cout<<"\n\t\t\t\t\t  3) | Delete Items | ";
  cout<<"\n\t\t\t\t\t  4) | View Items | ";
  cout<<"\n\t\t\t\t\t  5) | Main Menu | ";
  cout<<"\n\n\t\t\t\t\t Enter your Choice : ";
  cin>>yourchoice;
  system("cls");
  switch (yourchoice)
  {
  case 1 :
    add();
    break;
  case 2:
    edit();
    break;
  case 3 :
    rem();
    break;
  case 4:
    lists();
    break;
  case 5:
    Mainmenu();
    break;
  default:
    cout<<"\n\n\t\t\t\t Invalid input !!!";
    sleep(3);
  }
  goto m;
}

void shopping :: buyer(){
  system("cls");
  int choice;
  m:
  cout<<"\n\n\t\t**************************************";
  cout<<"\n\n\t\t\t\t BUYER ";
  cout<<"\n\n\t\t**************************************";
  cout<<"\n\t\t\t\t | 1) Buy Product |";
  cout<<"\n\t\t\t\t | 2) Go Back | ";
  cout<<"\n\n\t\t\t\t Enter your choice : ";
  cin>>choice;
  system("cls");
  switch (choice)
  {
  case 1:
    receipt();
    break;
  case 2:
    Mainmenu();
    break;
  default:
    cout<<"\n\n\t\t\t\t Enter a valid choice !!! ";
    sleep(3);
    break;
  }
  goto m;
}

void shopping::add(){
    n:
    system("cls");
    fstream data;
    int c;
    float token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t****************************************************************";
    cout <<"\n\n\t\t\t\t |  Add new product |";
    cout<<"\n\n\t\t*****************************************************************";
    cout<<"\n\n\t\t\t\t | 1) Code of the product | :  ";
    cin>>pcode;
    cout<<"\n\n\t\t\t\t | 2) Name of the product |: ";
    cin>>pname;
    cout<<"\n\n\t\t\t\t | 3) Price of the product |: ";
    cin>>price;
    cout<<"\n\n\t\t\t\t | 4) Discount amount |: ";
    cin>>discount;
    data.open("database.txt",ios::in);
    if (!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if (c==pcode){
                token++;
            }
            data>>c>>n>>p>>d;
        }
        data.close();

        if (token==1){
            system("cls");
            cout<<"\n\n\n\n\n\n\n\t\t\t\t\t\t Product code already exists : \n\n\n";
            sleep(3);
            goto n;
        }
        else{
            data.open("database.txt",ios::app|ios::out);
            data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            data.close();
        }
    }
    system("cls");
    cout<<"\n\n\n\n\n\n\t\t\t\t\t\t\t Record Inserted !!!";
    sleep(3);
    system("cls");
    adminstrator();
}

void shopping::edit(){
    system("cls");
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t*************************************************************";
    cout <<"\n\n\t\t\t\t |  Modify the product |";
    cout<<"\n\n\t\t**************************************************************";
    lists();
    cout<<"\n\n\t\t\t\t | 1) Product code | : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\t\t\t\t File doesn't exists !!! ";
    }
    else {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;

        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\n\t\t\t\t | 1) Product new code : | ";
                cin>>c;
                cout<<"\n\n\t\t\t\t | 2) Name of the product  : | ";
                cin>>n;
                cout<<"\n\n\t\t\t\t | 3) Price of the product : | ";
                cin>>p;
                cout<<"\n\n\t\t\t\t | 4) Discount on the product : | ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t\t\t Record Edited !!!";
                token++;
                sleep(3);
            }
            else {
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if (token==0){
            cout<<"\n\n\t\t\t\t Record not found !!!";
            sleep(3);
            adminpannel();
        }
    }
}

void shopping::rem(){
    system("cls");
    fstream data, data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t\t**************************************************************************";
    cout <<"\n\n\t\t\t\t\t |  Delete the product |";
    cout<<"\n\n\t\t***************************************************************************";
    lists();
    cout<<"\n\n\t\t\t\t | 1) Product code | : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n\t\t\t\t File doesn't exists !!! ";
        sleep(3);
        adminpannel();
    }
    else {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>discount;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\t\t\t\t Product deleted successfully !!!";
                token++;
                sleep(3);
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<discount<<"\n";
            }
            data>>pcode>>pname>>price>>discount;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if (token==0){
            cout<<"\n\n\t\t\t\t Record not found !!!";
            sleep(3);
        }
    }
}

void shopping::lists(){
    system("cls");
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n\t\t************************************************************************************************";
    cout<<"\n\n\t\t\t\t | Prd No | \t | Prd Name | \t | Prd Price | \n";
    data>>pcode>>pname>>price>>discount;
    while(!data.eof()){
        cout<<"\n\n\t\t\t\t\t"<<pcode<<" \t "<<pname<<"\t\t"<<price;
        data>>pcode>>pname>>price>>discount;
    }
    data.close();
    getch();
}

void shopping::receipt() {
    system("cls");
    fstream data;

    int arrc[100],arrq[100];
    char choice;
    int c=0;
    float amount=0;
    float dis=0;
    float total=0;
    cout<<"\n\n\t\t\t Receipt ";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else{
        data.close();
        lists();
        cout<<"\n\n\t\t**************************************************************************";
        cout<<"\n\n\t\t\t |  Please Place The Order | \n";
        cout<<"\n\n\t\t**************************************************************************";
        do{
            m:
            cout<<"\n\n\t\t\t Product Code : ";
            cin>>arrc[c];
            cout<<"\n\t\t\t Product Quantity : ";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {
                if(arrc[c] == arrc[i])
                {
                    cout<<"\n\n Duplicate Product Code. Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Want to buy another product? Press y for yes and n for no : ";
            cin>>choice;
        } while(choice == 'y');
        system("cls");
        cout<<"\n\n\t\t\t\t\t\t\t |  RECEIPT |";
        cout<<"\n\n\n\t\t***********************************************************************************";
        cout<<"\n\n\t    | Prd No |\t|    Prd Name  |\t| Quantity |\t| Price |\t| Amount |\t| Amt with Discount |\n";
        cout<<"\n\n\t\t************************************************************************************";
        for(int i=0;i<c;i++)
			{
				data.open("database.txt",ios::in);
				data>>pcode>>pname>>price>>dis;
				while(!data.eof())
				{
					if(pcode == arrc[i])
					{
						amount = price*arrq[i];
						dis = amount - (amount*dis/100);
						total =total+ dis;
						cout<<"\n\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
					}
					   data>>pcode>>pname>>price>>dis;
				}
				data.close();
			}
			cout<<"\n\n------------------------------------------------------------------------------------------------------------------------";
			cout<<"\n\n\t\t\t\t\t\t\t\t | Total Amount | : "<<total;
		}
}

int main(){

  sleep(2);
  system("cls");
  shopping a;
  a.Mainmenu();
  return 0;
}
