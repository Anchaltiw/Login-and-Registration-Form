#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
class User
{
private:
    string Username, Password;

public:
    User(string name, string Pass)
    {
        Username = name;
        Password = Pass;
    }
    string getUsername()
    {
        return Username;
    }
    string getPassword()
    {
        return Password;
    }
};
class UserManager
{
private:
    vector<User> Users; // creating vector object.
public:
//Function to register user....
    void RegisterUser()
    {
        string username, password;
        cout << "\t\tEnter Username :";
        cin >> username;
        cout << "\t\tEnter Password :";
        cin >> password;
        User newuser(username, password);
        Users.push_back(newuser);
        cout << "\t\tUser registered successfully....";
    }
//Function to login user....    
    bool LoginUser(string name, string pass)
    {
        for (int i = 0; i < Users.size(); i++)
        {
            if (Users[i].getUsername() == name && Users[i].getPassword() == pass)
            {
                cout << "\t\t Login Successfully....";
                return true;
            }
        }
        cout << "\t\tInvalid User Id And Password...";
        return false;
    }
//Function to show user list....    
    void ShowUserlist()
    {
        cout << "\t\t.....USER LIST....." << endl;
        for (int i = 0; i < Users.size(); i++)
        {
            cout << "\t\t" << Users[i].getUsername() << endl;
        }
    }
//Function to search user....    
    void SearchUser(string name)
    {
        int f = 0;
        for (int i = 0; i < Users.size(); i++)
        {
            if (Users[i].getUsername() == name)
            {
                f = 1;
                cout << "\t\tUSER FOUND";
                break;
            }
        }
        if (f == 0)
        {
            cout << "\t\tUSER NOT FOUND";
        }
    }
//Function to delete user....    
    void DeleteUser(string name)
    {
        for (int i = 0; i < Users.size(); i++)
        {
            if (Users[i].getUsername() == name)
            {
                Users.erase(Users.begin() + i);
                cout << "\t\tUser Removed Successfully....";
            }
        }
    }
};
int main()
{
    UserManager Usermanage;
    int option;
    char choice;
    do
    {
        system("cls");
        cout << "\n\n\t\t1. Register User " << endl;
        cout << "\t\t2. Login " << endl;
        cout << "\t\t3. Show User List " << endl;
        cout << "\t\t4. Search User " << endl;
        cout << "\t\t5. Delete User " << endl;
        cout << "\t\t6. Exit " << endl;
        cout << "\t\tEnter Your Choice : ";
        cin >> option;
        switch (option)
        {
        case 1:
        {
            Usermanage.RegisterUser();
            break;
        }
        case 2:
        {
            string username, password;
            cout << "\t\tEnter Username : ";
            cin >> username;
            cout << "\t\tEnter Password : ";
            cin >> password;
            Usermanage.LoginUser(username, password);
            break;
        }
        case 3:
        {
            Usermanage.ShowUserlist();
            break;
        }
        case 4:
        {
            string Username;
            cout << "\t\tEnter Username :";
            cin >> Username;
            Usermanage.SearchUser(Username);
            break;
        }
        case 5:
        {
            string username;
            cout << "\t\tEnter Username :";
            cin >> username;
            Usermanage.DeleteUser(username);
            break;
        }
        case 6:
        {
            cout<<"\t\tPROGRAM TERMINATED....";
            exit(1);
        }
        }
        cout << "\n\n\t\tDo You Want To Continue [Y/N]";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    return 0;
}