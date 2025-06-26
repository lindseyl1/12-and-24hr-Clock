/*
@author: Lindsey Langston
@Date: 05/24/2025
@version: 2.0
*/


#include <iostream>
#include <string>
using namespace std;

int hour;
int minute;
int second;

void printMenuOptions(){
    cout << "**************************" << endl;
    cout << "*     1- Add Hour        *" << endl;
    cout << "*     2- Add Minute      *" << endl;
    cout << "*     3- Add Second      *" << endl;
    cout << "*     4- Exit Program    *" << endl;
    cout << "**************************" << endl;
    cout << "Please select an option above" << endl;
}



string iniTime;
void promptIniTime(){

    cout << "What is your time in HH:MM:SS format?" << endl;
    cin >> iniTime;

    if (iniTime[0] <= '1'){ //first number in hour needs to be less than 2
        iniTime = iniTime;
    }
    bool hasColon = false;
    int i;

    if (iniTime.length() == 8 && iniTime[2] == ':' && iniTime[5] == ':') { //Checks for colons
    // Valid format
    cout << "Your time is: " << iniTime << endl;
    } 
    else { // Invalid format
    cout << "Incorrect format. Please try again." << endl;
    promptIniTime();
    }
    
}

void addHour() {
    int hour = stoi(iniTime.substr(0, 2));
    hour = (hour % 12) + 1; // Add hour after number 12
    
    iniTime = (hour < 10 ? "0" : "") + to_string(hour) + iniTime.substr(2);
}

void addMinute() {
    int minute = stoi(iniTime.substr(3, 2));
    minute = (minute + 1) % 60; // Add minute after number 60

    iniTime = iniTime.substr(0, 3) + (minute < 10 ? "0" : "") + to_string(minute) + iniTime.substr(5);
}

void addSecond() {
    int second = stoi(iniTime.substr(6, 2));
    second = (second + 1) % 60; // Add second after number 60

    iniTime = iniTime.substr(0, 6) + (second < 10 ? "0" : "") + to_string(second);
}

void askIfAmPm() {
    char ampm;
    cout << "Is this time in AM or PM? (A/P): ";
    cin >> ampm;
    if (ampm == 'P' || ampm == 'p') {
        int hour = stoi(iniTime.substr(0, 2));
        if (hour < 12) {
            hour += 12; // Convert to 24-hour format
            iniTime = (hour < 10 ? "0" : "") + to_string(hour) + iniTime.substr(2);
        }
    } else if (ampm != 'A' && ampm != 'a') {
        cout << "Invalid input. Please enter A for AM or P for PM." << endl;
        askIfAmPm(); //Invalid input
    }
}
void printDomesticClock() {
    int hour12 = stoi(iniTime.substr(0, 2));
    string ampm = "AM";
    if (hour12 >= 12) ampm = "PM";
    if (hour12 == 0) hour12 = 12;
    else if (hour12 > 12) hour12 -= 12;

    string hourStr = (hour12 < 10 ? "0" : "") + to_string(hour12);

    cout << "**************************" << endl;
    cout << "*      12-Hour Clock     *" << endl;
    cout << "*        " << hourStr << iniTime.substr(2,6) <<" " << ampm << "     *" << endl;
    cout << "**************************" << endl;
}

void printInternationalClock() {
    cout << "**************************" << endl;
    cout << "*    24-Hour Clock       *" << endl;
    cout << "*        " << iniTime << "       *" << endl;
    cout << "**************************" << endl;
}

int main() {
    promptIniTime();
    askIfAmPm(); // Ask if the time is AM or PM
    printMenuOptions();
    string menuNumber;
    cin >> menuNumber;
    if (menuNumber == "1") { //Add hour option
        addHour();
    } 
    else if (menuNumber == "2") { //Add minute option
        addMinute();
    } 
    else if (menuNumber == "3") { //Add second option
        addSecond();
    } 
    else if (menuNumber == "4") { //Exit option
        cout << "Exiting the program." << endl;
        return 0;
    }
    else {
        cout << "Invalid input. Please try again." << endl;
        main(); // Restart program
    }
    printDomesticClock();
    printInternationalClock();
    

    return 0;
}
