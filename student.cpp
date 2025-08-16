#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    string name;
    string program;

    bool verified = false;

    bool needsVisa = false;
    bool visaApplied = false;

    bool feePaid = false;

    bool wantsAccommodation = false;
    string accommodation;

    string tutor;
    bool hasExtraCredits = false;
    string extraCourse;
};


void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

bool askYesNo(const string& prompt) {
    while (true) {
        cout << prompt << " (y/n): ";
        char c;
        if (!(cin >> c)) { clearLine(); continue; }
        c = tolower(c);
        if (c == 'y') return true;
        if (c == 'n') return false;
        cout << "Please enter y or n.\n";
    }
}

string askLine(const string& prompt) {
    cout << prompt;
    string s;
    clearLine();                 
    getline(cin, s);
    return s;
}
