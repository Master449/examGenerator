#ifndef QUESTION_H
#define QUESTION_H

#include <string>
#include <iostream>

using std::cout;
using std::string;

class question {
    private:
        bool trueorfalse = false;
        bool multiplechoice = false;
        bool shortanswer = false;

        string questionTitle;
        string answerChoices;

        int questionNumber;

    public:
        bool unset;

        string option1;
        string option2;
        string option3;
        string option4;

        question();
        question(char, string, string, int);

        char getType();
        string getQuestion();
        string getAnswers();

        void setType(char);
        void setQuestion(string);
        void setAnswers(string);

        void print();
};

question::question() {
    unset = true;
}

question::question(char type, string title, string answers, int num){
    switch(type){
        case 'T':
            trueorfalse = true;
            break;
        case 'M':
            multiplechoice = true;
            break;
        case 'S':
            shortanswer = true;
            break;
    }
    questionTitle = title;
    answerChoices = answers;
    questionNumber = num;
}

char question::getType(){
    if (trueorfalse == true)
        return 'T';

    if (multiplechoice == true)
        return 'M';

    if (shortanswer == true)
        return 'S';
    
    return 'X';
}

string question::getQuestion(){
    return questionTitle;
}

string question::getAnswers(){
    return answerChoices;
}

void question::setType(char t){
    switch(t){
        case 'T':
            trueorfalse = true;
            multiplechoice = false;
            shortanswer = false;
            break;
        case 'M':
            trueorfalse = false;
            multiplechoice = true;
            shortanswer = false;
            break;
        case 'S':
            trueorfalse = false;
            multiplechoice = false;
            shortanswer = true;
            break;
    }
}

void question::setQuestion(string t){
    questionTitle = t;
}

void question::setAnswers(string a){
    answerChoices = a;
}

void question::print() {
    cout << questionNumber << ". " << questionTitle << "?\n\n";
    cout << answerChoices;
}

#endif