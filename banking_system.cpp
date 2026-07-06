#include<iostream>
#include<vector>
using namespace std;
class Customer
{
    public:
            int customerId;
            string name;
            string phone;

        void createCustomer(){
            cout<<"Enter customer ID:"<<endl;
            cin>>customerId;

            cout<<"Enter Name :"<<endl;
            cin>>name;

            cout<<"Enter you'r contact num :"<<endl;
            cin>>phone;
        }

        void displayCustomer(){
            cout << "\nCustomer ID : " << customerId << endl;
            cout << "Name : " << name << endl;
            cout << "Phone : " << phone << endl;
        }
};

class Transaction{
    public:
        string Type;
        float amount;

        Transaction(string t , float a ){
            Type = t;
            amount = a;
        }
};

class Account {
    public:
    int accountNum;
    float balance;

    Customer  customer;
    vector<Transaction>history; 

    void createAccount(){
        cout<<"Enter Account Number:"<<endl;
        cin>>accountNum;
        
        balance = 0;
    }

    void deposit(){
        float amount;

        cout<<" Enter Diposit Amount :"<<endl;
        cin>>amount;
        
        balance = balance + amount ;

         history.push_back(Transaction("Deposit", amount));

        cout << "Amount Deposited Successfully.\n";
    }

        void withdraw(){
        float amount;

        cout<<" Enter withdraw Amount :"<<endl;
        cin>>amount;

        if(amount <= balance)
        {
            balance = balance - amount;

         history.push_back(Transaction("Withdraw", amount));

        cout << "Amount Withdrawn Successfully.\n";

        }

        else{
            cout<<"Insufficient Balance." ;
        }
    }

        
    void transfer(Account &receiver)
    {
        float amount;

                cout << "Enter Transfer Amount : ";
        cin >> amount;

        if(amount <= balance)
        {
            balance = balance - amount;

                    receiver.balance = receiver.balance + amount;

            history.push_back(Transaction("Transfer Sent", amount));

            receiver.history.push_back(Transaction("Transfer Received", amount));

            cout << "Transfer Successful.\n";
               
                    }
        else
        {
            cout << "Insufficient Balance.\n";
        }
    }

        void showHistory()
    {
        cout << "\nTransaction History\n";

        for(int i=0;i<history.size();i++)
        {
            cout << history[i].Type << " : " << history[i].amount << endl;
        }
    }

        void displayAccount()
    {
        customer.displayCustomer();

        cout << "Account Number : " << accountNum << endl;

                cout << "Balance : " << balance << endl;
    }
};

int main()
{
    Account account1;
    Account account2;

        cout << "Enter First Customer Details\n";

    account1.customer.createCustomer();

    account1.createAccount();

    cout << "\nEnter Second Customer Details\n";

    account2.customer.createCustomer();

        account2.createAccount();

    int choice;

    do
    {
        cout << "\n===== BANK MENU =====\n";
        cout << "1. Deposit\n";
                cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. Display Account\n";
        cout << "5. Transaction History\n";
        cout << "6. Exit\n";

        cout << "Enter Choice : ";
           

                cin >> choice;

        switch(choice)
        {
            case 1:
                account1.deposit();
                break;

            case 2:
                account1.withdraw();
                break;

            case 3:
                account1.transfer(account2);
                break;

            case 4:
                account1.displayAccount();
                break;

            case 5:
                account1.showHistory();
                break;

            case 6:
                cout << "Thank You.\n";
                break;

            default:
                cout << "Invalid Choice.\n";
        }

    }while(choice!=6);

    return 0;
}
