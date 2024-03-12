#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class form
{
private:
    string mail_id, password;

public:
    void login_form();
    void signin_form();
    void forgot_password();
    void change_password();
};
void form ::signin_form()
{
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\t-------------------------------Sign In Form-------------------------------"<<endl;
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"Don't have an account!"<<endl;
    cout<<"Create a new one!"<<endl;
    cout << "Enter your mail_id:";
    cin >> mail_id;
    cout << "Enter Password:";
    cin >> password;
    fstream file;
    file.open("login_record.txt", ios ::out | ios ::app);
    file << "\n"
         << mail_id << "\n"
         << password << "\n";
    cout << "Sign in Successfully!!";
}
void form ::login_form()
{
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\t-------------------------------Login Form---------------------------------"<<endl;
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    string fusername, fpassword;
    fstream file;
    file.open("login_record.txt", ios ::in);
    cout<<"Already have a account!"<<endl;
    cout<<"Log in!"<<endl;
    cout << "Enter username:";
    cin >> fusername;
    cout << "Enter password:";
    cin >> fpassword;
    file >> mail_id >> password;
    while (file.eof() == 0)
    {
        if (fusername == mail_id && fpassword == password)
        {
            cout << "Logged in Successfully";
        }
        // else{
        //     cout<<"Invalid details"<<endl;
        //     cout<<"Enter details again!";
        // }
        file >> mail_id >> password;
    }
}
void form ::forgot_password()
{
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\t----------------------------Forgot Password-------------------------------"<<endl;
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    string fusername, fpassword;
    cout << "Enter username:";
    cin >> fusername;
    fstream file;
    file.open("login_record.txt", ios ::in);
    if (!file)
    {
        cout << "No data is found!" << endl;
    }
    file >> mail_id >> password;
    while (file.eof() == 0)
    {
        if (fusername == mail_id)
        {
            cout << "Username:" << mail_id << endl;
            cout << "Password:" << password;
        }
        file >> mail_id >> password;
    }
    file.close();
}
void form ::change_password()
{
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\t----------------------------Change Password-------------------------------"<<endl;
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    string fusername, fpassword;
    fstream file, file1;
    file.open("login_record.txt", ios ::in);
    if (!file)
    {
        cout << "No data is found!";
    }
    else
    {
        cout << "enter username for which u want to change password:";
        cin >> fusername;
        file >> mail_id >> password;
        file1.open("login_record1.txt", ios ::out | ios ::app);
        while (file.eof() == 0)
        {
            if (fusername == mail_id)
            {
                cout << "Enter the password:";
                cin >> fpassword;
                file1 << "\n"
                      << fusername << "\n"
                      << fpassword << "\n";
            }
            else
            {
                file1 << "\n"
                      << mail_id << "\n"
                      << password << "\n";
            }
            file >> mail_id >> password;
        }
    }
    file.close();
    file1.close();
    remove("login_record.txt");
    rename("login_record1.txt", "login_record.txt");
}
void exit(){
    cout<<"Exiting from the page!!";
}
int main()
{
    form f;
    int choice;
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\t-----------------------Login && Registration Form-------------------------"<<endl;
    cout<<"\t\t--------------------------------------------------------------------------"<<endl;
    cout<<"\t\tWelcome to the Page:"<<endl;
    cout<<"\t\t1)Sign in"<<endl;
    cout<<"\t\t2)Log in"<<endl;
    cout<<"\t\t3)Forgot password"<<endl;
    cout<<"\t\t4)Change password"<<endl;
    cout<<"\t\t5)Exit"<<endl;
    cout<<"\t\tEnter What do you want to do:";
    cin>>choice;
    switch(choice){
        case 1:
            f.signin_form();
        break;
        case 2:
            f.login_form();
        break;
        case 3:
            f.forgot_password();
        break;
        case 4:
            f.change_password();
        break;
        case 5:
            exit();
        break;
        default:
            cout<<"Please enter Valid choice!!";
    }
    return 0;

}