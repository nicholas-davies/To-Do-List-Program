# To-Do List Program

## Overview

This simple C++ program allows users to create and manage a to-do list. Users can add tasks, mark them as completed, and view their remaining tasks. The program consists of three files: `main.cpp`, `toDoList.cpp`, and `header.h`.

## Instructions

### 1. `main.cpp`

The `main.cpp` file contains the main function that initializes the `toDoList` object and allows users to add tasks to their to-do list.

```cpp
#include <iostream>
#include <string>
#include <vector>
#include "../header/header.h"
using namespace std;

int main() {
   toDoList userTasks;
   vector<string> toDoItems;
   userTasks.addToDoItems(toDoItems);
   return 0;
}
