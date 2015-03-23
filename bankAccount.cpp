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
using namespace std;

char mainMenu();
bool validateMainMenu(char);
string navigateMenu(char);
bool login();
void createAccount();

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
  if (output == "loggedIn")
  {
    // loginMenu();
  }
  else
  {
    cout << "Thanks for stopping by!\n" << endl;
  }
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
      return "loggedIn";
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
