/* 
    Name: Joshua Lee
    Date: March 17, 2015
    Purpose: Creating a bank account program that allows users to login and save information.
    Algorithm: 
        1) Show a menu to allow user to either create a bank account, login, and close
        2) Validate that the user chose a valid option
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


