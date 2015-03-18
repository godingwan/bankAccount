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
// Including below allows you to read input or output to a file
#include <fstream> 
using namespace std;

char mainMenu();
bool validateMainMenu(char);

int main() 
{
  // Output the main menu and store the choice
  char choice = mainMenu();
  switch (choice)
  {
    case 'q':
    case 'Q':
    {
      cout << "Goodbye";
      break;
    }
    case 'c':
    case 'C':
    {  
      string account;
      string password;
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
  }
}

char mainMenu()
{
  char choice = 'a';

  // Continues to show the menu until a valid choice is made
  while (!validateMainMenu(choice)) 
  {
    cout << "Main Menu: \n";
    cout << "C: Create a bank account.\n";
    cout << "L: Log into account.\n"; 
    cout << "Q: Quit.\n";
    cin >> choice;
  }
  return choice; 
}

bool validateMainMenu(char input)
{
  if (input == 'C')
    return true;
  else if (input == 'c')
    return true;
  else if (input == 'L')
    return true;
  else if (input == 'l')
    return true;
  else if (input == 'Q')
    return true;
  else if (input == 'q')
    return true;
  else
    return false;
}
