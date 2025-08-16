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
void TuitionFee(Student& s) {
    cout << "\n Tuition Fee \n";
    cout << "Student makes payment\n";
    do {
        s.feePaid = askYesNo("Fee paid?");
        if (!s.feePaid) cout << "Wait until payment done\n";
    } while (!s.feePaid);

    cout << "Payment confirmed \n";
}

void Accommodation(Student& s) { 
    cout << "\n Accommodation (A) \n";
    s.wantsAccommodation = askYesNo("Ask for accommodation?");
    if (s.wantsAccommodation) {
        s.accommodation = askLine("Assign accommodation (room/hostel name): ");
        cout << "Accommodation assigned: " << s.accommodation << "\n";
    } else {
        cout << "No accommodation requested.\n";
    }
}

void PersonalTutor(Student& s) { 
    cout << "\n Personal Tutor \n";
    if (s.tutor.empty())
        s.tutor = askLine("Assign tutor (enter tutor name): ");
    cout << "Student meets Personal Tutor " << s.tutor << ".\n";
}
void ExtraCourse(Student& s) { 
    cout << "\n Extra Course \n";
    s.hasExtraCredits = askYesNo("Has extra credits?");
    if (s.hasExtraCredits) {
        s.extraCourse = askLine("Choose additional course: ");
        cout << "Additional course chosen: " << s.extraCourse << "\n";
    } else {
        cout << "No extra course selected.\n";
    }
    
}


void FullyRegistered(const Student& s) {
    cout << "\n Fully Registered \n";
    cout << "Completed Registration for " << s.name << " (" << s.program << ")\n";
    cout << "Summary:\n";
    cout << "  Verified: " << (s.verified ? "Yes" : "No") << "\n";
    cout << "  Visa: " << (s.needsVisa ? (s.visaApplied ? "Applied" : "Required (not applied)") : "Not required") << "\n";
    cout << "  Fee Paid: " << (s.feePaid ? "Yes" : "No") << "\n";
    cout << "  Accommodation: " << (s.wantsAccommodation ? s.accommodation : string("Not requested")) << "\n";
    cout << "  Tutor: " << (s.tutor.empty() ? string("Not assigned") : s.tutor) << "\n";
    cout << "  Extra Course: " << (s.hasExtraCredits ? s.extraCourse : string("None")) << "\n";
    cout << "Registration Completed \n";
}

int main() {
    Student s;

    
    Registration(s);       
    AdmissionOffice(s);    
    Visa(s);               
    TuitionFee(s);         
    Accommodation(s);      
    PersonalTutor(s);     
    ExtraCourse(s);        
    FullyRegistered(s);    

    return 0;
}

