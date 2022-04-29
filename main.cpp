/**
 * @file main.cpp
 * @author David Flowers
 * @brief Just a simple coding exercise where I try to use
 *        classes to create an Exam generator.
 * @version 0.1
 * @date 2022-04-19
 */

#include <iostream>
#include <string>
#include <fstream>
#include "question.h"

using std::cout;
using std::cin;
using std::string;
using std::stoi;
using std::getline;
using std::ofstream;

int main() {
    int total;
    int TorFtotal;
    int multipleTotal;
    int shortTotal;
    int questionNum = 1;
    string s;

    do {
        cout << "How many questions would you like to generate? ";
        cin >> total;

        cout << "How many questions would you like to be true or false? ";
        cin >> TorFtotal;

        cout << "How many questions would you like to be multiple choice? ";
        cin >> multipleTotal;

        cout << "How many questions would you like to be short answer? ";
        cin >> shortTotal;

        if ((TorFtotal + multipleTotal + shortTotal) > total) 
            cout << "Totals for each of those exceed total number of generated questions. Please try again. (Total Entered: " << TorFtotal + multipleTotal + shortTotal << ".\n\n";

        if ((TorFtotal + multipleTotal + shortTotal) < total) 
            cout << "Totals for each of those is less than total number of generated questions. Please try again. (Total Entered: " << TorFtotal + multipleTotal + shortTotal << ".\n\n";
    } while ((TorFtotal + multipleTotal + shortTotal) != total);
    
    question torfArray[TorFtotal];
    question multiArray[multipleTotal];
    question shortArray[shortTotal];

    cout << "Generated question arrays.\nTime to set them up.\n\n";

    cout << "Generation for True or False Questions.\n";
    if (TorFtotal == 0) {
        cout << "None needed.\n\n";
    }

    cin.ignore();

    for(int i = 0; i < TorFtotal; i++) {
        torfArray[i].unset = false;
        torfArray[i].setType('T');
        
        cout << i+1 << ". Enter question: ";
        getline(cin, s);

        torfArray[i].setQuestion(s);
    }

    cout << "\nGeneration for Multiple Choice Questions.\n";
    if (multipleTotal == 0) {
        cout << "None needed.\n\n";
    }

    for(int i = 0; i < multipleTotal; i++) {
        multiArray[i].unset = false;
        multiArray[i].setType('M');

        cout << i+1 << ". Enter Question: ";
        getline(cin, s);
        multiArray[i].setQuestion(s);

        cout << "    " << i+1 << "a. Enter Option 1: ";
        getline(cin, s);
        multiArray[i].option1 = s;

        cout << "    " << i+1 << "a. Enter Option 2: ";
        getline(cin, s);
        multiArray[i].option2 = s;

        cout << "    " << i+1 << "a. Enter Option 3: ";
        getline(cin, s);
        multiArray[i].option3 = s;

        cout << "    " << i+1 << "a. Enter Option 4: ";
        getline(cin, s);
        multiArray[i].option4 = s;
    }

    cout << "\nGeneration Short Answer Questions.\n";
    if (shortTotal == 0) {
        cout << "None needed.\n\n";
    }

    for(int i = 0; i < shortTotal; i++) {
        shortArray[i].unset = false;
        shortArray[i].setType('M');

        cout << i+1 << ". Enter Question: ";
        getline(cin, s);

        shortArray[i].setQuestion(s);
    }

    cout << "Printing Questions: \n\n";


    for(int i = 0; i < TorFtotal; i++) {
        cout << questionNum++ << ". " << torfArray[i].getQuestion() << "\n";
        cout << "    True\n" << "    False\n\n";
    }

    for(int i = 0; i < multipleTotal; i++) {
        cout << questionNum++ << ". " << multiArray[i].getQuestion() << "\n";

        cout << "    a. " << multiArray[i].option1 << "\n";
        cout << "    b. " << multiArray[i].option2 << "\n";
        cout << "    c. " << multiArray[i].option3 << "\n";
        cout << "    d. " << multiArray[i].option4 << "\n\n";
    }

    for(int i = 0; i < shortTotal; i++) {
        cout << questionNum++ << ". " << shortArray[i].getQuestion() << "\n\n\n\n\n";
    }

    total = 0;

    cout << "Make sure to double check the questions.\nWould you like to save them to a file (y/n)?";
    cin.ignore();
    getline(cin, s);
    
    if (s == "n") {
        return 0;
    } else {
        questionNum = 1;
        ofstream examfile("ExamFile.txt");

        if (!examfile){
            cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
            return 1;
        }

        for(int i = 0; i < TorFtotal; i++) {
            examfile << questionNum++ << ". " << torfArray[i].getQuestion() << "\n";
            examfile << "    True\n" << "    False\n\n";
        }

        for(int i = 0; i < multipleTotal; i++) {
            examfile << questionNum++ << ". " << multiArray[i].getQuestion() << "\n";

            examfile << "    a. " << multiArray[i].option1 << "\n";
            examfile << "    b. " << multiArray[i].option2 << "\n";
            examfile << "    c. " << multiArray[i].option3 << "\n";
            examfile << "    d. " << multiArray[i].option4 << "\n\n";
        }

        for(int i = 0; i < shortTotal; i++) {
            examfile << questionNum++ << ". " << shortArray[i].getQuestion() << "\n\n\n\n\n";
        }

        examfile.close();
    }

    return 0;
}