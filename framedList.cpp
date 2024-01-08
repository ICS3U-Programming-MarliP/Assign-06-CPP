// Copyright (c) 2023 Marli Peters All Rights Reserved
// Created by: Marli Peters
// Date: Nov. 8, 2023
// This program asks the user for a list
// then frames the list and displays it
// back to the user.
#include <iostream>
#include <list>
#include <string>

// create function to frame the list
void frameList(std::list<std::string> userList) {
    // find length of longest string in list
    int maxLength = 0;
    for (std::string word : userList) {
        maxLength = std::max(maxLength, static_cast<int>(word.length()));
    }

    // set border to right size and display top border
    std::string border(maxLength + 4, '*');
    std::cout << border << "\n";

    // display each word in list with right size border
    for (std::string word : userList) {
        int spaces = maxLength - word.length();
        std::cout << "* " << word << std::string(spaces, ' ') << " *\n";
    }

    // display bottom border
    std::cout << border << "\n\n";
}

// main function to run code
int main() {
    // welcome message
    std::cout << "Hello and welcome to the framed list program!"
    " You will be asked to enter a list of words then it will"
    " be put in a frame of asterisks. Enter blank to stop adding words.\n\n";

    // create list and word variable to add to list
    std::list<std::string> userList;
    std::string userWord;

    // collect words and add them to list until user enters blank
    do {
        std::cout << "Enter a word: ";
        getline(std::cin, userWord);
        if (!userWord.empty()) {
            userList.push_back(userWord);
        } else {
            std::cout << "\n";
        }
    } while (!userWord.empty());

    // run function to frame the list
    frameList(userList);

    return 0;
}
