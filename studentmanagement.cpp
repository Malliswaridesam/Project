#include <iostream>
#include <regex>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
int main();
//  Function to  check the email Id;
bool Emailcheck(string email)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email, pattern);
}
class student
{

private:
    string name, roll_no, course, address, email_id;
    long long contact_no;

public:
    void add_data();
    void display_data();
    void modify_data();
    void search_data();
    void delete_data();
    void exit();
};
void student ::add_data()
{
    system ("cls");
    cout << "\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t-----------------------------Adding Student Details-------------------------------\n";
    cout << "\t\t----------------------------------------------------------------------------------\n";
    cout << "Enter the details:" << endl;
    cout << "Enter name of the student:";
    cin >> name;
    cout << "Enter rollNo of the student:";
    cin >> roll_no;
    cout << "Enter course of the student:";
    cin >> course;
    cout << "Enter mail of the student:";
    cin >> email_id;
    if (Emailcheck(email_id))
    {
        cout << "Email ID is valid" << endl;
    }
    else
    {
        cout << "Email ID is Invalid";
    }
    cout << "Enter address of the student:";
    cin >> address;
    cout << "Enter the contact No:";
    cin >> contact_no;
    if (contact_no > 1000000000 || contact_no < 9999999999)
    {
        cout << "Contact No is valid" << endl;
    }
    else
    {
        cout << "Contact No is Invalid" << endl;
    }
    fstream file;
    file.open("student_record.txt", ios ::app | ios ::out);
    file << "\n\n"
         << name << "\n"
         << roll_no << "\n"
         << course << "\n"
         << email_id << "\n"
         << address << "\n"
         << contact_no << "\n\n";
    file.close();
}
void student ::display_data()
{

    system("cls");
    cout << "\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t-----------------------------Displaying Student Details---------------------------\n";
    cout << "\t\t----------------------------------------------------------------------------------\n";
    fstream file;
    int total = 1;
    file.open("student_record.txt", ios ::in);
    if (!file)
    {
        cout << "No data is Present" << endl;
        file.close();
    }

    else
    {
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (!file.eof())
        {
            cout << "\n\n\t\tStudent No.: " << total++ << endl;
            cout << "\t\tName: " << name << "\n";
            cout << "\t\tRoll No.: " << roll_no << "\n";
            cout << "\t\tCourse: " << course << "\n";
            cout << "\t\tEmail Id: " << email_id << "\n";
            cout << "\t\tContact No.: " << contact_no << "\n";
            cout << "\t\tAddress: " << address << "\n";
            file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        }
        if (total == 0)
        {
            cout << "No data is present" << endl;
        }
    }

    file.close();
}
void student ::modify_data()
{   system("cls");
    cout << "\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t-----------------------------Modifying Student Details----------------------------\n";
    cout << "\t\t----------------------------------------------------------------------------------\n";
    fstream file, file1;
    string roll;
    string mail_id, address;
    long long phone_no;
    int found = 0;
    file.open("student_record.txt", ios ::in);
    if (!file)
    {
        cout << "No data is present" << endl;
    }
    else
    {
        cout << "enter the rollno of the student u want to change:";
        cin >> roll;
        file1.open("student_record1.txt", ios ::app | ios ::out);
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (file.eof() == 0)
        {
            if (roll != roll_no)
            {
                file1 << name << "\n"
                      << roll_no << "\n"
                      << course << "\n"
                      << email_id << "\n"
                      << address << "\n"
                      << contact_no << "\n";
            }
            else
            {
                cout << "enter mail_id:";
                cin >> mail_id;
                if (Emailcheck(mail_id))
                {
                    cout << "mail ID is valid" << endl;
                }
                else
                {
                    cout << "mail ID is Invalid";
                }
                cout << "enter phone_no:";
                cin >> phone_no;
                if (phone_no > 1000000000 || phone_no < 9999999999)
                {
                    cout << "phone No is valid" << endl;
                }
                else
                {
                    cout << "phone No is Invalid" << endl;
                }
                cout << "enter address:";
                cin >> address;
                file1 <<"\n"<< name << "\n"
                      << roll_no << "\n"
                      << course << "\n"
                      << mail_id << "\n"
                      << address << "\n"
                      << phone_no<<"\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        }
        file1.close();
        file.close();
        remove("student_record.txt");
        rename("student_record1.txt", "student_record.txt");
    }
}
void student ::search_data()
{ 
    system("cls");
    cout << "\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t-----------------------------Searching Student Details----------------------------\n";
    cout << "\t\t----------------------------------------------------------------------------------\n";
    fstream file;
    string rollno;
    file.open("student_record.txt");
    if (!file)
    {
        cout << "No data is found" << endl;
    }
    else
    {
        cout << "enter the roll no for which u want to search the data:";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (file.eof() == 0)
        {
            // if(rollno!=roll_no){
            //     cout<<"No data is there for this roll No"<<endl;
            // }
            if (rollno == roll_no)
            {
                cout << "The details of the student are:" << endl;
                cout << "\t\tName:" << name << endl;
                cout << "\t\trollno:" << roll_no << endl;
                cout << "\t\tCourse:" << course << endl;
                cout << "\t\tEmail-id:" << email_id << endl;
                cout << "\t\tAddress:" << address << endl;
                cout << "\t\tContact-No:" << contact_no << endl;
            }
            file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        }
        file.close();
    }
}
void student ::delete_data()
{   system("cls");
    string rollNo;
    int found = 0;
    fstream file, file1;
    file.open("student_record.txt", ios ::in);
    if (!file)
    {
        cout << "no data found!" << endl;
    }
    else
    {
        cout << "enter the rollno u want to delete data:";
        cin >> rollNo;
        file1.open("student_record1.txt", ios ::app | ios ::out);
        file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        while (file.eof() == 0)
        {
            if (rollNo != roll_no)
            {
                file1 << name << "\n"
                      << roll_no << "\n"
                      << course << "\n"
                      << email_id << "\n"
                      << address << "\n"
                      << contact_no;
            }
            else
            {
                cout << "\t\t\nData Deleted Successfully!!" << endl;
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> address >> contact_no;
        }
        if (found == 0)
        {
            cout << "No data found" << endl;
        }
        file.close();
        file1.close();
        remove("student_record.txt");
        rename("student_record1.txt", "student_record.txt");
    }
}
void exit()
{
          cout << "Exiting from the student management system!";        
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
    student st;
    cout << "\t\t----------------------------------------------------------------------------------\n";
    cout << "\t\t-----------------------------Student Management System-----------------------------\n";
    cout << "\t\t-----------------------------------------------------------------------------------\n";
    cout << "\t\tEnter what you want to do???" << endl;
    cout << "\t\t1.Add data of the student" << endl;
    cout << "\t\t2.Display the data of the student" << endl;
    cout << "\t\t3.modify the data of the student" << endl;
    cout << "\t\t4.Search the data of the student" << endl;
    cout << "\t\t5.Delete the data of the student" << endl;
    cout << "\t\t6.Exit " << endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        st.add_data();
        char s;
        cout << "Do you want to add another student details:";
        cin >> s;
        if (s == 'x' || s == 'X')
        {
            st.add_data();
        }
        search();
        break;
    case 2:
        st.display_data();
        search();
        break;
    case 3:
        st.modify_data();
        search();
        break;
    case 4:
        st.search_data();
        search();
        break;      
    case 5:
        st.delete_data();
        search();
        break;
    case 6:
        exit();
        break;
    default:
        cout << "please enter Valid choice!!";
    }
    // system("cls");

    return 0;
}