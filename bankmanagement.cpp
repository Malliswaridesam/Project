#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int main ();
class bank
{
private:
        string accno, name, address, gender = "N/A", nationality;
        double balance = 0;
        long long contact_no;
        long long aadhar_no;

public:
        void create_acc();
        void display_acc();
        void deposit_money();
        void withdrawl_money();
        void search_acc();
        void update_acc();
        void delete_acc();
};
void bank ::create_acc()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t***********************Creating an Account****************************\n";
        cout << "\t\t***********************************************************************\n";
        cout << "enter name:";
        cin >> name;
        cout << "enter accno:";
        cin >> accno;
        cout << "enter address:";
        cin >> address;
        cout << "enter gender:";
        cin >> gender;
        cout << "enter nationality:";
        cin >> nationality;
        cout << "enter contact_no:";
        cin >> contact_no;
        if (contact_no > 10000000000 || contact_no < 9999999999)
        {
                cout << "contact_no is valid:"<<endl;
        }
        else
        {
                cout << "contact_no is invalid"<<endl;
        }
        cout << "enter aadhar no:";
        cin >> aadhar_no;
        if (aadhar_no > 100000000000 | aadhar_no < 999999999999)
        {
                cout << "aadhar_no is valid"<<endl;
        }
        else
        {
                cout << "aadhar_no is invalid"<<endl;
        }
        fstream file;
        file.open("bank.txt", ios::app | ios::out);
        file << "\n"
             << name << "\n"
             << accno << "\n"
             << gender << "\n"
             << nationality << "\n"
             << balance << "\n"
             << address << "\n"
             << contact_no << "\n"
             << aadhar_no << "\n";
        file.close();
}
void bank ::display_acc()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t***************************Displaying Account**************************\n";
        cout << "\t\t***********************************************************************\n";
        fstream file;
        int total = 1;
        file.open("bank.txt", ios :: in);
        if (!file)
        {
                cout << "No data is found" << endl;
                file.close();
        }
        else
        {
                file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                while (file.eof() == 0)
                {
                        cout<<"\n\n";
                        cout << "\t\tAccount No : " << total++<< endl;
                        cout << "\t\tName : " << name << endl;
                        cout << "\t\tAccount No : " << accno << endl;
                        cout << "\t\tGender : " << gender << endl;
                        cout << "\t\tNationality : " << nationality << endl;
                        cout << "\t\tbalance:" << balance << endl;
                        cout << "\t\tAddress : " << address << endl;
                        cout << "\t\tContact-No : " << contact_no << endl;
                        cout << "\t\tAadhar-No : " << aadhar_no << endl;
                        file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;

        }
                 
}
         file.close();
}
void bank ::deposit_money()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t***************************Depositing Money****************************\n";
        cout << "\t\t***********************************************************************\n";
        int amount;
        string acc_no;
        fstream file, file1;
        file.open("bank.txt", ios ::in );
        if (!file)
        {
                cout << "No data found" << endl;
                file.close();
        }
        else
        {
                cout << "Enter the accno you want to deposit money:";
                cin >> acc_no;
                file1.open("bank1.txt", ios ::app | ios ::out);
                file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                while (file.eof() == 0)
                {
                        if (acc_no == accno)
                        {
                                cout << "Enter the amount you want to deposit:";
                                cin >> amount;
                                balance += amount;
                                cout << "Amount added Successfully"<<endl;
                                file1 << "\n"
                                      << name << "\n"
                                      << accno << "\n"
                                      << gender << "\n"
                                      << nationality << "\n"
                                      << balance << "\n"
                                      << address << "\n"
                                      << contact_no << "\n"
                                      << aadhar_no << "\n";
                        }
                        else
                        {
                                // cout << "Invalid Account Nummber" << endl;
                                file1 << "\n"
                                      << name << "\n"
                                      << accno << "\n"
                                      << gender << "\n"
                                      << nationality << "\n"
                                      << balance << "\n"
                                      << address << "\n"
                                      << contact_no << "\n"
                                      << aadhar_no << "\n";
                        }
                        file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                }
                file1.close();
                file.close();
                remove("bank.txt");
                rename("bank1.txt", "bank.txt");
        }
}
void bank ::withdrawl_money()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t*************************Withdrawing Money*****************************\n";
        cout << "\t\t***********************************************************************\n";
        int amount;
        string acc_no;
        fstream file, file1;
        file.open("bank.txt", ios ::in);
        if (!file)
        {
                cout << "No data found" << endl;
        }
        else
        {
                cout << "Enter the accno you want to withdraw money:";
                cin >> acc_no;
                file1.open("bank1.txt", ios ::app | ios ::out);
                file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                while (file.eof() == 0)
                {
                        if (acc_no == accno)
                        {
                                cout << "Enter the amount you want to withdraw:";
                                cin >> amount;
                                if (amount > balance)
                                {
                                        cout << "Insufficient Balance in account" << endl;
                                        cout << "Balance is : " << balance<<endl;
                                        file1 << "\n"
                                        << name << "\n"
                                        << accno << "\n"
                                        << gender << "\n"
                                        << nationality << "\n"
                                        << balance << "\n"
                                        << address << "\n"
                                        << contact_no << "\n"
                                        << aadhar_no << "\n";
                                }
                                else
                                {
                                        balance -= amount;
                                        cout << "Amount Withdrawn Successfully!" << endl;
                                         file1 << "\n"
                                        << name << "\n"
                                        << accno << "\n"
                                        << gender << "\n"
                                        << nationality << "\n"
                                        << balance << "\n"
                                        << address << "\n"
                                        << contact_no << "\n"
                                        << aadhar_no << "\n";
                                }
                        }
                        else
                        {
                                      // cout << "Invalid Account Nummber" << endl;
                                      file1 << "\n"
                                      << name << "\n"
                                      << accno << "\n"
                                      << gender << "\n"
                                      << nationality << "\n"
                                      << balance << "\n"
                                      << address << "\n"
                                      << contact_no << "\n"
                                      << aadhar_no << "\n";
                        }
                        file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                }
                file1.close();
                file.close();
                remove("bank.txt");
                rename("bank1.txt", "bank.txt");
        }
}
void bank :: search_acc()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t**********************Searching an account*****************************\n";
        cout << "\t\t***********************************************************************\n";
        fstream file;
        string accNo;
        file.open("bank.txt",ios :: in);
        if (!file)
        {
                cout << "No data found" << endl;
                file.close();
        }
        else
        {
                cout << "enter the accNo u want to search:";
                cin >> accNo;
                file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                while (file.eof() == 0)
                {
                        if (accNo == accno)
                        {
                                cout << "\t\tName : " << name << endl;
                                cout << "\t\tAccount No : " << accno << endl;
                                cout << "\t\tGender : " << gender << endl;
                                cout << "\t\tNationality : " << nationality << endl;
                                cout << "\t\tbalance:" << balance << endl;
                                cout << "\t\tAddress : " << address << endl;
                                cout << "\t\tContact-No : " << contact_no << endl;
                                cout << "\t\tAadhar-No : " << aadhar_no << endl;
                                // file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                        }
                         
                     
                        //  else{
                        //          cout<<"Account Not found!"<<endl;
                        //  }
                            file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                }        
                file.close();
        }
        
}
void bank ::update_acc()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t**************************Updating an Account**************************\n";
        cout << "\t\t***********************************************************************\n";
        fstream file, file1;
        double balance1;
        file.open("bank.txt", ios ::in);
        string accNo;
        if (!file)
        {
                cout << "Data not found" << endl;
        }
        else
        {
                cout << "enter the accNo u want to modify the data:" << endl;
                cin >> accNo;
                file1.open("bank1.txt", ios ::app | ios::out);
                file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                while (file.eof() == 0)
                {
                        if (accNo == accno)
                        {
                                cout << "enter balance:";
                                cin >> balance1;
                                file1 << "\n"
                                      << name << "\n"
                                      << accno << "\n"
                                      << gender << "\n"
                                      << nationality << "\n"
                                      << balance1 << "\n"
                                      << address << "\n"
                                      << contact_no << "\n"
                                      << aadhar_no << "\n";
                        }
                        else
                        {
                                file1 << "\n"
                                     << name << "\n"
                                     << accno << "\n"
                                     << gender << "\n"
                                     << nationality << "\n"
                                     << balance << "\n"
                                     << address << "\n"
                                     << contact_no << "\n"
                                     << aadhar_no << "\n";
                        }

                        file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                }
                file1.close();
                file.close();
                remove("bank.txt");
                rename("bank1.txt", "bank.txt");
        }
}
void bank ::delete_acc()
{
        system("cls");
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t*************************Deleting an account***************************\n";
        cout << "\t\t***********************************************************************\n";
        fstream file, file1;
        string accNo;
        file.open("bank.txt", ios ::in);
        if (!file)
        {
                cout << "No data is found" << endl;
        }
        else
        {
                file1.open("bank1.txt", ios ::app | ios ::out);
                cout << "enter the accNo you want to delete:";
                cin >> accNo;
                file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                while (file.eof() == 0)
                {
                        if (accNo == accno)
                        {
                                cout << "Account deleted Successfully!" << endl;
                        }
                        else
                        {
                                file1 <<"\n\n"<< name<<"\n" << accno<<"\n" << gender<<"\n" << nationality<<"\n" << balance<<"\n" << address<<"\n"<< contact_no<<"\n" << aadhar_no;
                        }
                        file >> name >> accno >> gender >> nationality >> balance >> address >> contact_no >> aadhar_no;
                }
                file.close();
                file1.close();
                remove("bank.txt");
                rename("bank1.txt", "bank.txt");
        }
}
void exit()
{
          cout << "Exiting from the bank management system!";        
}
void search(){
        string value;
        cout<<"Do You want to search again?(yes/no)"<<endl;
        cin>>value;
        if(value=="yes"){
                main();
        }
        else{
               exit();
        }
}
int main()
{
        int choice;
        bank b;
        cout << "\t\t***********************************************************************\n";
        cout << "\t\t******************Bank Management System*******************************\n";
        cout << "\t\t***********************************************************************\n";
        cout << "\t\tEnter what you Want to do(1-8)::" << endl;
        cout << "\t\t1.Creating a account" << endl;
        cout << "\t\t2.Display the accounts" << endl;
        cout << "\t\t3.Deposit Money in account" << endl;
        cout << "\t\t4.Withdraw Money in account" << endl;
        cout << "\t\t5.Update an account" << endl;
        cout << "\t\t6.Seatch for an account" << endl;
        cout << "\t\t7.Delete an account:" << endl;
        cout << "\t\t8.EXIT" << endl;
        // b.create_acc();
        // b.display_acc();
        // b.deposit_money();
        cin >> choice;
        switch (choice)
        {
        case 1:
                char s;
                
                do{
                        b.create_acc();
                        cout<<"Do you want to add one more account(y->yes/n->no)";
                        cin>>s;

                }while(s=='y');
                search();
                break;
        case 2:
                b.display_acc();
                search();
                break;
        case 3: 
                b.deposit_money(); 
                search();   
                break;
        case 4:
                b.withdrawl_money();
                search();
                break;
        case 5:
                b.update_acc();
                search();
                break;
        case 6:
                b.search_acc();
                search();
                break;
        case 7:
                b.delete_acc();
                search();
                break;
        case 8:
                exit();
                break;
        default:
                cout << "Enter Valid Choice!!";
                cout << "Try Again!!";
        }

        return 0;
}