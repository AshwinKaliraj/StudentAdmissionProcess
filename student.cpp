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
void Registration(Student& s) { 
    cout << "\nRegistration Form \n";
    if (s.name.empty())  s.name  = askLine("Enter student name: ");
    if (s.program.empty()) s.program = askLine("Enter Department: ");

    cout << "Complete Registration Process\n";
    cout << "Form has sent  to corresponding departments\n";
    cout << "Saved to Student Information DB \n";

}

void AdmissionOffice(Student& s) { 
    cout << "\n Admission Office   Verification \n";
    cout << "Receive form for " << s.name << " (" << s.program << ")\n";
    do {
        cout << "Checking details\n";
        s.verified = askYesNo("Are details verified?");
        if (!s.verified) {
            cout << "Return form for correction. Please correct details\n";
            // allow edits if user wants
            if (askYesNo("Edit name?"))    s.name    = askLine("New name: ");
            if (askYesNo("Edit program?")) s.program = askLine("New program: ");
        }
    } while (!s.verified);

    cout << "Verified\n";
}


void Visa(Student& s) { 
    cout << "\nVisa \n";
    s.needsVisa = askYesNo("Need visa?");
    if (s.needsVisa) {
        cout << "Inform student for Visa Application.\n";
        do {
            s.visaApplied = askYesNo("Has the visa been applied?");
            if (!s.visaApplied) cout << "Waiting until visa applied.\n";
        } while (!s.visaApplied);
        cout << "Visa application acknowledged.\n";
    } else {
        cout << "No visa required.\n";
    }
    
}

