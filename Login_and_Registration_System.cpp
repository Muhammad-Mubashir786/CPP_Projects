/*The login And Registration System project in
C++ involves mainly the user registration
process. User Credentials like usernames and
passwords are asked from the user. If the
registration of the user is successful then with
the given credentials a file will be created of a
particular user in the database.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Signup
{
private:
    string username;
    string password;

public:
    void setSignup()
    {
        cout << "\t\t\t\tRegistration Page\n\n";
        cout << "Enter your username: ";
        cin >> username;
        cout << "Enter your password: ";
        cin >> password;
        ofstream registration;
        registration.open("Registration.txt", ios::app);
        registration << username << endl;
        registration << password << endl;
        registration.close();
        system("cls");
        cout << "Registration Successful" << endl;
    }
    void getLogin()
    {
        string userId, storedUser, pass, storedPass;
        cout << "\t\t\t\tLogin Page\n\n";
        cout << "Enter your username: ";
        cin >> userId;
        cout << "Enter your password: ";
        cin >> pass;
        ifstream login("Registration.txt");
        if (!login)
        {
            cout << "Error opening the file!" << endl;
            return;
        }
        getline(login, storedUser);
        getline(login, storedPass);
        login.close();
        if (userId == storedUser && pass == storedPass)

        {
            cout << "Login Successful" << endl;
        }
        else
        {
            string forget, storedUser, userId, storedPass;
            cout << "Invalid Credentials" << endl;
            cout << "Forgot your password? (Yes,No)" << endl;
            cin >> forget;
            if (forget == "yes")
            {
                cout << "Enter your username: ";
                cin >> userId;
                ifstream registration("Registration.txt");
                while (registration >> storedUser >> storedPass)
                {
                    if (storedUser == userId)
                    {
                        cout << "Account found. Your password is: " << storedPass << endl;
                        registration.close();
                    }
                    else{
                        cout << "Account not found" << endl;
                        registration.close();
                    }
                }
            }
            else
            {
                cout << "\t\t\t\tLogin Failed";
            }
        }
    }
}

;

int main()
{
    int choice;
    cout << "\t\t\t\tLogin And Registration System\n\n";
    cout << "1. Registration\n";
    cout << "2. Login\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1)
    {
        Signup registration;
        registration.setSignup();
    }
    else if (choice == 2)
    {
        Signup login;
        login.getLogin();
    }
    else
    {
        cout << "Invalid Choice" << endl;
    }

    return 0;
}