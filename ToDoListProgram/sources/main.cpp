#include <iostream>
#include <string>
#include <vector>
#include "../header/header.h"
using namespace std;

int main() {

   toDoList userTasks;
   
   // Vector that stores user's tasks needed completion
   vector<string> toDoItems; 
   
   // Calls function so user can add tasks to to-do list
   userTasks.addToDoItems(toDoItems); 

   return 0;
}  

