#include<string.h>
#include<iostream>
#include "valid.h"
using  namespace std;



class Bank
{
    public:
    char bankname[20];
    char IFSC[20];
    char address[20];

    Bank( )
    {
    strcpy(bankname,"Bank of India");
    strcpy(IFSC,"BKID0000530");
    strcpy(address,"MIT Loni");
    }
};



class SavingAccount: public Bank
{
    int acno;
    float bal;
    char  holdername[20];
    string PAN_num,AADHAR,Mobile_num;
    public:
    SavingAccount( )
    {

    }

void accept( )
{
    cout<<"Enter Account Number : ";
    cin>>acno;

    while(true)
    {
        cout<<"Enter Name of Account Holder : ";
        cin>>holdername;
        if (isNameValid(holdername))
            break;
        else
            cout<<"Name is not valid \n";
    }


    while(true)
    {
        cout<<"Enter your PAN Number : ";
        getline(cin, PAN_num);
         
        if(!isValidPanCardNo(PAN_num))
        {
            cout << "PAN Number is Not Valid. Please enter correct PAN Number\n" << endl;
                
        }
        else
            break;
    }

       while(true)
    {
        cout<<"Enter your AADHAR Number : ";
        getline(cin, AADHAR);
         
        if(!isValidAadhaarNumber(AADHAR))
        {
            cout << "AADHAR Number is Not Valid. Please enter correct AADHAR Number \n" << endl;
                
        }
        else
            break;
    }


        while(true)
       {
            cout<<"Enter your Mobile Number : ";
            getline(cin, Mobile_num);
            
            if(!isValidMobileNumber(Mobile_num))
            {
                cout << "Mobile Number is Not Valid. Please enter correct Mobile Number \n" << endl;
                    
            }
            else
                break;
       }



    while(true)
    {
        cout<<"Enter Opening Balance : ";
        cin>>bal;
        if (isBalance(bal))
        break;
        else
        cout<<"Opening Balance should be greater than 5000\n";

    }

}


void display()
{
    cout << endl;
    cout<<"Bank Name is : "<<bankname << endl;
    cout<<"Account number is : "<<acno << endl;
    cout<<"Holder name is : "<<holdername << endl;
    cout<<"PAN number is : "<<PAN_num << endl;
    cout<<"AADHAR number is : "<<AADHAR << endl;
    cout<<"Mobile number is : "<<Mobile_num << endl;
    cout<<"Your balance is : "<<bal << endl;
    cout << endl;
}



void withdraw(double amount) {
        if (bal >= amount) {
            bal -= amount;
            cout<<"withdrawn sucessfully"<<endl;
        }
        else
        {

            cout << "Insufficient balance!" << endl;
        }
    }




   void deposit(double amount) {
        bal += amount;
        cout<<"deposited sucessfully"<<endl;
    }


    void displayBalance() 
    {
         cout << "Account  : " << acno << endl;
         cout << "Balance: " << bal << endl;
    }


    void transferFund(SavingAccount &recipient,double amt)
    {

        if(amt>0 && bal>=amt)
        {
            bal-=amt;
            recipient.bal+=amt;
            cout << "Tranfered " << amt << " from account " << acno << " to account " << recipient.acno << endl;
        }
        else{
            cout << "Invalid transfer amount or insufficient balance. " << endl;
        }


    }
    
   

};



class CurrentAccount: public Bank
{
    int acno;
    float bal;
    char holdername[20];
    string PAN_num,AADHAR,Mobile_num;

    public:
    CurrentAccount( )
    {

    }

    void accept( )
   {
        cout<<"Enter Account Number ";
        cin>>acno;
        while(true)
        {
            cout<<"Enter Name of Account Holder : ";
            cin>>holdername;
            if (isNameValid(holdername))
                break;
            else
                cout<<"Name is not valid \n";
        }



           while(true)
       {
            cout<<"Enter your PAN Number : ";
            getline(cin, PAN_num);
         
            if(!isValidPanCardNo(PAN_num))
            {
                cout << "PAN Number is Not Valid. Please enter correct PAN Number \n" << endl;
                
            }
            else
                break;
       }


        while(true)
       {
            cout<<"Enter your AADHAR Number : ";
            getline(cin, AADHAR);
            
            if(!isValidAadhaarNumber(AADHAR))
            {
                cout << "AADHAR Number is Not Valid. Please enter correct AADHAR Number \n" << endl;
                    
            }
            else
                break;
       }



         while(true)
       {
            cout<<"Enter your Mobile Number : ";
            getline(cin, Mobile_num);
            
            if(!isValidMobileNumber(Mobile_num))
            {
                cout << "Mobile Number is Not Valid. Please enter correct Mobile Number \n" << endl;
                    
            }
            else
                break;
       }



        while(true)
        {
            cout<<"Enter Opening Balance : ";
            cin>>bal;
            if (isBalance(bal))
                break;
            else
                 cout<<"Opening Balance should be greater than 5000\n";

        }

}


    void display()
    {
        cout << endl;
        cout<<"Bank Name is : "<<bankname<<endl;
        cout<<"Account number is : "<<acno<<endl;
        cout<<"Holder name is : "<<holdername<<endl;
        cout<<"PAN number is : "<<PAN_num<<endl;
        cout<<"AADHAR number is : "<<AADHAR<<endl;
        cout<<"Mobile number is : "<<Mobile_num<<endl;
        cout<<"Your balance is : "<<bal<<endl;
        cout << endl;
    }


    void withdraw(double amount) {
        if (bal >= amount) {
            bal -= amount;
            cout<<"withdrawn sucessfully"<<endl;
        }
        else
        {

            cout << "Insufficient balance!" << endl;
        }
    }


    void deposit(double amount) {
        bal += amount;
        cout<<"deposited sucessfully"<<endl;
    }


    void displayBalance() 
    {
        cout << "Account Number: " << acno << endl;
        cout << "Balance: " << bal<< endl;
    }


    void transferFund(CurrentAccount &recipient,double amt)
    {

        if(amt>0 && bal>=amt)
        {
            bal-=amt;
            recipient.bal+=amt;
            cout << "Tranfered " << amt << " from account " << acno << " to account " << recipient.acno << endl;
        }
        else{
            cout << "Invalid transfer amount or insufficient balance. " << endl;
        }


    }
    
       
    
};



int main()
{
int n,m;
cout<<"Enter the number of records to be stored for CurrentAccount : "<<endl;
cin>>n;
CurrentAccount ca[n];

for(int i=0;i<n;i++)
{
   ca[i].accept( );
   cout << endl;
}


for(int i=0;i<n;i++)
{
   ca[i].display( );
   cout << endl;
}

cout<<"Enter the number of records to be added for savingaccount : "<<endl;
cin>>m;
SavingAccount sa[m];

for(int i=0;i<m;i++)
{
   sa[i].accept( );
   cout << endl;
}

for(int i=0;i<m;i++)
{
   sa[i].display( );
   cout << endl;
}

cout << "\nBank Accounts Created!" << endl;
    bool flag = false;
    while (!flag) {
        cout << "\nChoose an option:" << endl;
        cout << "1. Deposit to Savings Account" << endl;
        cout << "2. Withdraw from Savings Account" << endl;
        cout << "3. Deposit to Current Account" << endl;
        cout << "4. Withdraw from Current Account" << endl;
        cout << "5. Display Balances for Saving Account" << endl;
        cout << "6. Display Balances for Current Account" << endl;
        cout << "7. Transfer Funds Between Saving Account" << endl;
        cout << "8. Transfer Funds Between Current Account" << endl;
        cout << "9. Exit" << endl;

        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                double savingsDepositAmount;
                int a;
                cout << "Enter the amount to deposit into Savings Account and its number: ";
                cin >> savingsDepositAmount>>a;
                sa[a].deposit(savingsDepositAmount);
                break;
            case 2:
                double savingsWithdrawAmount;
                int b;
                cout << "Enter the amount to withdraw from Savings Account and its number: ";
                cin >> savingsWithdrawAmount >> b;
                sa[b].withdraw(savingsWithdrawAmount);
                break;
            case 3:
                double currentDepositAmount;
                int c;
                cout << "Enter the amount to deposit into Current Account and its number: ";
                cin >> currentDepositAmount >> c;
                ca[c].deposit(currentDepositAmount);
                break;
            case 4:
                double currentWithdrawAmount;
                int d;
                cout << "Enter the amount to withdraw from Current Account and its number: ";
                cin >> currentWithdrawAmount >> d;
                ca[d].withdraw(currentWithdrawAmount);
                break;
            case 5:
                int e;
                
                cout << "\nSavings Account: " << endl;
                cout << "Enter the index number : ";
                cin >> e;
                sa[e].displayBalance();
                break;
            case 6:
                int f;
                cout << "\nCurrent Account: " << endl;
                cout << "Enter the index number : ";
                cin >> f;
                ca[f].displayBalance();
                break;
            case 7 :
                int x,y, amt;
                cout << "Enter the sender Saving Account index : " << endl;
                cin >> x;
                cout << "Enter the receiver Saving Account index : " << endl;
                cin >> y;
                cout << "Enter the Account to be transfered : " << endl;
                cin >> amt;
                sa[x].transferFund(sa[y],amt);
                break;

            case 8 :
                int x,y, amt;
                cout << "Enter the sender Current Account index : " << endl;
                cin >> x;
                cout << "Enter the receiver Current Account index : " << endl;
                cin >> y;
                cout << "Enter the Account to be transfered : " << endl;
                cin >> amt;
                ca[x].transferFund(ca[y],amt);
                break;

            case 9:
                flag = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

