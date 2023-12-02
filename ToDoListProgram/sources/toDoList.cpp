#include <iostream>
#include <string>
#include <vector>
#include "../header/header.h"
using namespace std;

void toDoList::addToDoItems(vector<string>& toDoItems) {
   int count = toDoItems.size()+1;
   char capitalizeFirstLetter;
   string userInput;

   cout << "\nPlease enter a task that you would like added to your to-do-list: ";
   getline(cin, userInput);
   cout << endl;

   while (userInput != "q") {
      capitalizeFirstLetter = toupper(userInput.at(0)); // Capitalizes first letter of first word of a task
      userInput.erase(0,1);
      userInput = to_string(count) + ". " + capitalizeFirstLetter + userInput; // Adds modified task with correct capitalization to vector
      toDoItems.push_back(userInput); // Adds user task to list of things to do
      cout << "Add another task or press q if you are done: ";
      getline(cin, userInput);
      cout << endl;
      ++count;
   } // end while

   cout << "Here's what you need to accomplish today:\n" << endl;

   for (int i = 0; i < toDoItems.size(); ++i) { // Outputs the user's tasks needed to be done
      cout << toDoItems.at(i) << endl;
   } // end if

   cout << "\nPlease press 'd' if you would like to check off your items on your to-do list or press any other key to be done: ";
   cin >> userInput;
   cin.ignore();
   cout << endl;

   if (userInput == "d") {
      deleteToDoItems(toDoItems); // Calls functions so user can delete tasks completed
   } // end if

   else {
      cout << "Have a good day!\n" << endl; // Ends program
   } // end else
}

void toDoList::deleteToDoItems(vector<string>& toDoItems) {
   int taskNumToDelete;
   int count = 1;
   string tasksLeft;
   string userInput;

   cout << "Please enter the number of the task that you have completed (refer to list above): ";
   cin >> taskNumToDelete;
   cin.ignore();
   cout << endl;

   while (taskNumToDelete != -1) {

      toDoItems.erase(toDoItems.begin()+(taskNumToDelete)-1); //deletes one of the tasks in the vector based on the number the user entered

      cout << "Please enter the number of the next task that you have accomplished (enter -1 to see remaining tasks if applicable): ";
      cin >> taskNumToDelete;
      cin.ignore();
      cout << endl;
   }

   if (toDoItems.size() > 0) {

      if (toDoItems.size() == 1) {
         cout << "You are so close to being done! You have " << toDoItems.size() << " more task to do!\n" << endl;   
      }

      else {
         cout << "You are so close to being done! You have " << toDoItems.size() << " more tasks to do!\n" << endl;
      }

      for (int i = 0; i < toDoItems.size(); ++i) { //outputs remaining tasks
         tasksLeft = toDoItems.at(i);
         tasksLeft.erase(0,1); //erases orignal number of task

         cout << count << tasksLeft << endl; //outputs the remaining tasks with new numbers
         ++count;
      }

      cout << endl;
      cout << "Please press 'd' to check more items off, press 'a' to add more items to your list, or press any other key to be done: ";
      cin >> userInput;
      cin.ignore();
      cout << endl;

      if (userInput == "d") {
         deleteToDoItems(toDoItems); //calls function if user wants to delete more completed tasks
      }

      else if(userInput == "a") {
         addToDoItems(toDoItems); //calls function if user wants to add more tasks
      }

      else {
         cout << "Have a good day!\n" << endl; //ends program
      }

   }

   else {
      cout << "Congratulations! You finished all your tasks! Now you can relax :)\n" << endl;
   }

}