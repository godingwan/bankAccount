/*
    Name: Joshua Lee
    Date: March 17, 2015
    Purpose: Creating a bank account program that allows users to login and save information.
    Algorithm:
        1) Show a menu to allow user to either create a bank account, login, and close 2) Validate that the user chose a valid option
        3) If the user wants to create a login, allow them to create and save the info to a file
        4) If the user wants to login, validate that the info matches and log them in and show a new menu
        5) If the user wants to quit, send a goodbye message
        6) Once logged in, show another menu to withdraw, deposit, request balance, and quit
           check that the choice is a valid option, if not show menu again
        7) If withdraw, then ask for a number and validate it is possible
        8) If deposit, ask for number and add the money to the user account
        9) If checking balance, get the user's account balance
        10 If quit, then send bad to the first menu

*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

char mainMenu();
bool validateMainMenu(char);
string navigateMenu(char);
bool login();
void createAccount();
char loginMenu();
string navigateLoginMenu(char);
void displayAmount();
string depositAmount();

// Global variables used to set account detail
string account = "notSet";
string password;
double balance = 0.0;

int main()
{
  cout << "Hi! Welcome to Future Computer Programmer ATM Machine!";
  // Output the main menu and store the choice
  char choice = mainMenu();
  string output;

  // Send the choice and make the program do what the user wants
  output = navigateMenu(choice);
  while (output == "Created")
  {
    choice = mainMenu();
    output = navigateMenu(choice);
  }
  while (output == "loggedIn")
  {
    choice = loginMenu();
    navigateLoginMenu(choice);
  }
  cout << "Thanks for stopping by!\n" << endl;
}

string navigateLoginMenu(char choice)
{
  switch(choice)
  {

    case 'd':
    case 'D':
    {
      depositAmount();
      return "loggedIn";
    }
    /*
    case 'w':
    case 'W':
    {
      // withdrawAmount();
    }
    */
    case 'r':
    case 'R':
    {
      displayAmount();
      return "loggedIn";
    }
    default:
    {
      return "Goodbye";
    }
  }
}

string depositAmount()
{
  double deposit;
  cout << "Enter amount of deposit: $";
  cin >> deposit;
  while (deposit <= 0)
  {
    cout << "Enter an amount greater than 0: $";
    cin >> deposit;
  }
  balance += deposit;
  return "loggedIn";
}

void displayAmount()
{
  cout << "Your balance is $" << setprecision(2) << fixed << balance << endl;
}

char loginMenu()
{
  char choice;
  cout << "Please select an option from the menu below\n";
  cout << "D -> Deposit Money\n";
  cout << "W -> Withdraw Money\n";
  cout << "R -> Request Balance\n";
  cout << "Q -> quit\n";
  cin >> choice;
  return choice;
}

void createAccount()
{
  // Set a random password that will never be set
  string verifyPassword = "ewriouti3489715ydhfasdfneiru";

  cout << "What would you like as a user id? ";
  cin >> account;
  cout << "Please set a password. ";
  cin >> password;
  // Keep asking to verify password until it is the same
  while (verifyPassword != password)
  {
    cout << "Please verify the password. ";
    cin >> verifyPassword;
  }
  cout << "Account successfully created.\n";
}

string navigateMenu(char choice)
{
  switch (choice)
  {
    case 'q':
    case 'Q':
    {
      return "Goodbye";
      break;
    }
    case 'c':
    case 'C':
    {
      createAccount();
      return "Created";
      break;
    }
    case 'l':
    case 'L':
    {
      bool loggedIn;
      if (account == "notSet")
      {
        cout << "Please create a username.\n";
        return "Goodbye";
      }
      else
      {
        loggedIn = login();
        if (loggedIn == true)
        {
          cout << "Access Granted!\n";
          return "loggedIn";
        }
        else
        {
          return "Goodbye";
        }
      }
      break;
    }
    default:
    {
      return "Goodbye";
    }
  }
}

bool login()
{
  string username;
  string verifyPassword;

  cout << "Enter username: ";
  cin >> username;

  if (username == account)
  {
    cout << "Enter password: ";
    cin >> verifyPassword;
    if (verifyPassword == password)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

char mainMenu()
{
  char choice = 'a';

  // Continues to show the menu until a valid choice is made
  while (!validateMainMenu(choice))
  {
    cout << "Please select an option from the menu below:\n";
    cout << "C -> Create a bank account.\n";
    cout << "L -> Log into account.\n";
    cout << "Q -> Quit.\n";
    cout << "Enter your choice: ";
    cin >> choice;
  }
  return choice;
}

bool validateMainMenu(char input)
{
  switch (input)
  {
    case 'C':
    case 'c':
    {
      return true;
      break;
    }
    case 'L':
    case 'l':
    {
      return true;
      break;
    }
    case 'Q':
    case 'q':
    {
      return true;
      break;
    }
    default:
      return false;
  }
}
