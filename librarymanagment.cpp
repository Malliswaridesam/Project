#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <ctime>
int main();
using namespace std;
void get_time();
bool Emailcheck(string email_id)
{
    const regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return regex_match(email_id, pattern);
}
class library
{
private:
    string name, id, author, publisher, price;
    int number, number1;
    char buffer[80];
    long long contact_no;
    string email_id, address;

public:
    void add_book();
    void display_book();
    void search_book();
    void update_book();
    void borrow_book();
    void return_update();
    void exit();
};
void library ::add_book()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t------------------------------Adding New Book----------------------------" << endl;
    cout << "\t\t-------------------------------------------------------------------------" << endl;

    cout << "Enter name:";
    cin >> name;
    cout << "Enter Id:";
    cin >> id;
    cout << "Enter author name:";
    cin >> author;
    cout << "Enter publisher name:";
    cin >> publisher;
    cout << "Enter price:";
    cin >> price;
    cout << "Enter no.of books:";
    cin >> number;
    fstream file;
    file.open("libraryrecord.txt", ios ::app | ios ::out);
    file << "\n"
         << name << "\n"
         << id << "\n"
         << author << "\n"
         << publisher << "\n"
         << price << "\n"
         << number << "\n";
    file.close();
}
void library ::display_book()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t-----------------------------Displaying Books----------------------------" << endl;
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    fstream file;
    int total = 1;
    file.open("libraryrecord.txt", ios ::in);
    if (!file)
    {
        cout << "No data is found";
        file.close();
    }
    else
    {
        file >> name >> id >> author >> publisher >> price >> number;
        while (!file.eof())
        {
            cout << "\n";
            cout << "\t\tSerial Number: " << total++ << endl;
            cout << "\t\tName of the book:" << name << endl;
            cout << "\t\tId of book :" << id << endl;
            cout << "\t\tAuthor of book:" << author << endl;
            cout << "\t\tPublisher of book:" << publisher << endl;
            cout << "\t\tPrice of book:" << price << endl;
            cout << "\t\tNumber of books:" << number << endl;
            file >> name >> id >> author >> publisher >> price >> number;
        }
    }
    file.close();
}
void library ::search_book()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t-----------------------------Searching a Book----------------------------" << endl;
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    fstream file;
    string id1;
    file.open("libraryrecord.txt", ios ::in);
    if (!file)
    {
        cout << "No data is present";
        file.close();
    }
    else
    {
        cout << "enter id :";
        cin >> id1;
        file >> name >> id >> author >> publisher >> price >> number;
        while (file.eof() == 0)
        {
            if (id1 == id)
            {
                cout << "\t\tName of book:" << name << endl;
                cout << "\t\tId of book:" << id << endl;
                cout << "\t\tAuthor of book:" << author << endl;
                cout << "\t\tPublisher of book:" << publisher << endl;
                cout << "\t\tPrice of book:" << price << endl;
                cout << "\t\tNo.of books available:" << number << endl;
            }
            file >> name >> id >> author >> publisher >> price >> number;
        }
        file.close();
    }
}
void library ::update_book()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t----------------------------Updating A Book------------------------------" << endl;
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    fstream file, file1;
    file.open("libraryrecord.txt", ios ::in);
    int number1;
    string price1;
    string id1;
    if (!file)
    {
        cout << "No data is present" << endl;
        file.close();
    }
    else
    {
        cout << "enter the id u want to change:";
        cin >> id1;
        file1.open("libraryrecord1.txt", ios ::app | ios ::out);
        file >> name >> id >> author >> publisher >> price >> number;
        while (file.eof() == 0)
        {
            if (id1 == id)
            {
                cout << "Enter price of book:";
                cin >> price1;
                cout << "Enter no of books available:";
                cin >> number1;
                file1 << "\n"
                      << name << "\n"
                      << id << "\n"
                      << author << "\n"
                      << publisher << "\n"
                      << price1 << "\n"
                      << number1 << "\n";
            }
            else
            {
                file1 << "\n"
                      << name << "\n"
                      << id << "\n"
                      << author << "\n"
                      << publisher << "\n"
                      << price << "\n"
                      << number << "\n";
            }
            file >> name >> id >> author >> publisher >> price >> number;
        }
        file1.close();
    }
    file.close();
    remove("libraryrecord.txt");
    rename("libraryrecord1.txt", "libraryrecord.txt");
}

void library ::borrow_book()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t----------------------------Borrowing A Book-----------------------------" << endl;
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    fstream file, file1, file2;
    // int number1;
    string id1;
    // string price1;
    file.open("libraryrecord.txt", ios ::in);
    if (!file)
    {
        cout << "No data is present";
        file.close();
    }
    else
    {
        file >> name >> id >> author >> publisher >> price >> number;
        file1.open("library_borrow.txt", ios ::app | ios ::out);
        file2.open("library.txt", ios ::app | ios ::out);
        cout << "Enter id of book u want to borrow:" << endl;
        cin >> id1;
        while (file.eof() == 0)
        {
            if (id1 == id)
            {
                cout << "Book is borrowed Successfully!";
                number1 = number - 1;
                time_t now = time(0);
                tm *localtm = localtime(&now);
                char buffer[80];
                strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", localtm);

                file1 << "\n"
                      << name << "\n"
                      << id1 << "\n"
                      << buffer << "\n"
                      << number1 << "\n\n";

                file2 << "\n"
                      << name << "\n"
                      << id << "\n"
                      << author << "\n"
                      << publisher << "\n"
                      << price << "\n"
                      << number1 << "\n";
            }
            else
            {
                file2 << "\n"
                      << name << "\n"
                      << id << "\n"
                      << author << "\n"
                      << publisher << "\n"
                      << price << "\n"
                      << number << "\n";
            }
            file >> name >> id >> author >> publisher >> price >> number;
        }
    }
    file1.close();
    file.close();
    file2.close();
    remove("libraryrecord.txt");
    rename("library.txt", "libraryrecord.txt");
}

void library ::return_update()
{
    system("cls");
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t---------------------------Returning A Book------------------------------" << endl;
    cout << "\t\t-------------------------------------------------------------------------" << endl;
    fstream file, file1, file2;
    int number1;
    string id1;
    file.open("libraryrecord.txt", ios ::in);
    if (!file)
    {
        cout << "No data is present" << endl;
    }
    else
    {
        cout << "Enter id of book u want to return:";
        cin >> id1;
        file >> name >> id >> author >> publisher >> price >> number;
        file1.open("library_return.txt", ios ::app | ios ::out);
        file2.open("library1.txt", ios ::app | ios ::out);
        while (file.eof() == 0)
        {
            if (id1 == id)
            {
                cout << "Book returned succesfully";
                number1 = number + 1;
                time_t now = time(0);
                tm *localtm = localtime(&now);
                char buffer[80];
                strftime(buffer, 80, "%d-%m-%Y %H:%M:%S", localtm);
                file1 << "\n"
                      << name << "\n"
                      << id1 << "\n"
                      << buffer << "\n"
                      << number1 << "\n\n";
                file2 << "\n"
                      << name << "\n"
                      << id1 << "\n"
                      << author << "\n"
                      << publisher << "\n"
                      << price << "\n"
                      << number1 << "\n";
            }
            else
            {
                file2 << "\n"
                      << name << "\n"
                      << id1 << "\n"
                      << author << "\n"
                      << publisher << "\n"
                      << price << "\n"
                      << number << "\n";
            }
            file >> name >> id >> author >> publisher >> price >> number;
        }
    }
    file1.close();
    file.close();
    file2.close();
    remove("libraryrecord.txt");
    rename("library1.txt", "libraryrecord.txt");
}
void exit()
{
    cout << "\t\t---------------------------------------------------------------------" << endl;
    cout << "\t\t----------------------------Exit from LMS----------------------------" << endl;
    cout << "\t\t---------------------------------------------------------------------" << endl;
    cout << "\t\tExiting from Library Management System" << endl;
}
void search()
{
    string value;
    cout << "Do You want to search again?(yes/no)" << endl;
    cin >> value;
    if (value == "yes")
    {
        main();
    }
    else
    {
        exit();
    }
}
int main()
{
    int choice;
    cout << "\t\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t\t------------------------Library Management System------------------------" << endl;
    cout << "\t\t\t-------------------------------------------------------------------------" << endl;
    cout << "\t\t\t1)Add new book" << endl;
    cout << "\t\t\t2)Display all books" << endl;
    cout << "\t\t\t3)Search a book" << endl;
    cout << "\t\t\t4)Update a book" << endl;
    cout << "\t\t\t5)Issue a book" << endl;
    cout << "\t\t\t6)Return a book" << endl;
    cout << "\t\t\t7)Exit from LMS" << endl;
    cout << "\t\t\tEnter what u want to do:";
    cin >> choice;

    library l;
    switch (choice)
    {
    case 1:
        l.add_book();
        search();
        break;
    case 2:
        l.display_book();
        search();
        break;
    case 3:
        l.search_book();
        search();
        break;
    case 4:
        l.update_book();
        search();
        break;
    case 5:
        l.borrow_book();
        search();
        break;
    case 6:
        l.return_update();
        search();
        break;
    case 7:
        exit();
        break;
    default:
        cout << "Enter valid choice" << endl;
    }
    return 0;
}