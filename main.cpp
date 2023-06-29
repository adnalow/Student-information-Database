#include <iostream>
using namespace std;

struct Node {
    string name;
    string scode;
    string subj;
    string prof;
    string sched;
    Node* next;
};

Node* head = NULL;

void InsertNode(string name, string scode, string subj, string prof, string sched) {
    Node* n = new Node();
    n->name = name;
    n->scode = scode;
    n->subj = subj;
    n->prof = prof;
    n->sched = sched;
    n->next = head;
    head = n;
}

void displayList() {
    int max;
    Node* curr = head;
    while (curr != NULL) {

            cout << "Name: " << curr->name << endl;
            cout << "SR-CODE: " << curr->scode << endl;
            cout << "SUBJECT: " << curr->subj << endl;
            cout << "PROFESSOR: " << curr->prof << endl;
            cout << "SCHEDULE: " << curr->sched << endl;
            cout << endl;
            curr = curr->next;
        
    }
}

void displayStudentDetails(string srCode) {
    Node* curr = head;
    while (curr != NULL) {
        if (curr->scode == srCode) {
            cout << "Name: " << curr->name << endl;
            cout << "SR-CODE: " << curr->scode << endl;
            cout << "SUBJECT: " << curr->subj << endl;
            cout << "PROFESSOR: " << curr->prof << endl;
            cout << "SCHEDULE: " << curr->sched << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Student with SR-CODE " << srCode << " not found." << endl;
}

int main() {
    int max;
    string name, scode, subj, prof, sched;
    char back;

    do {
        cout << "How many students do you want to add? ";
        cin >> max;
    } while (max <= 0);

    for (int i = 0; i < max; i++) {
        system("CLS");
        cout << "Enter the name of the student: ";
        cin >> name;
        cout << "Enter the SR-Code of the student: ";
        cin >> scode;
        cout << "Enter the Subject to be taken by the student: ";
        cin >> subj;
        cout << "Enter the name of the professor: ";
        cin >> prof;
        cout << "Enter the schedule time for the entered subject: ";
        cin >> sched;

        InsertNode(name, scode, subj, prof, sched);
    }

    system("CLS");
    cout << "All the information of the inputted students:\n\n";
    displayList();

    char opt;
    cout << "Do you want to know only the details of a specific student? [Y/N]: ";
    cin >> opt;

    do{
    if (opt == 'Y' || opt == 'y') {
        string srCode;
        cout << "Enter the SR-Code of the student: ";
        cin >> srCode;
        cout << endl;
        displayStudentDetails(srCode);
    } else if (opt == 'N' || opt == 'n') {
        cout << endl;
        cout << "Thank you for using the program." << endl;
    } else {
        cout << "Invalid choice." << endl;
    }

        cout<<endl;
        cout<<"DO YOU STILL WANT TO FIND SPECIFIC STUDENT?[Y/N]";
        cin>>back;
        cout << endl << endl;
    }while (back == 'y' || back == 'Y');

    return 0;
}
