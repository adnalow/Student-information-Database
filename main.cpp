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
    bool found = false;
    while (curr != NULL) {
        if (curr->scode == srCode) {
            cout << "Name: " << curr->name << endl;
            cout << "SR-CODE: " << curr->scode << endl;
            cout << "SUBJECT: " << curr->subj << endl;
            cout << "PROFESSOR: " << curr->prof << endl;
            cout << "SCHEDULE: " << curr->sched << endl;
            found = true;
        }
        curr = curr->next;
    }
    if (!found)
        cout << "Student with SR-CODE " << srCode << " not found." << endl;
}

void RemoveNode(string srCode) {
    if (head == NULL) {
        cout << "List is empty. Cannot remove student." << endl;
        return;
    }

    if (head->scode == srCode) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Student with SR-CODE " << srCode << " has been removed." << endl;
        return;
    }

    Node* curr = head;
    Node* prev = NULL;

    while (curr != NULL) {
        if (curr->scode == srCode) {
            prev->next = curr->next;
            delete curr;
            cout << "Student with SR-CODE " << srCode << " has been removed." << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }

    cout << "Student with SR-CODE " << srCode << " not found. Cannot remove student." << endl;
}

int main() {
    int max;
    string name, scode, subj, prof, sched;
    char opt;

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

    do {
        cout << "Do you want to remove a specific student? [Y/N]: ";
        cin >> opt;

        if (opt == 'Y' || opt == 'y') {
            string srCode;
            cout << "Enter the SR-Code of the student to remove: ";
            cin >> srCode;
            RemoveNode(srCode);
        } else if (opt == 'N' || opt == 'n') {
            cout << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }

        cout << endl;
        cout << "All the information of the remaining students:\n\n";
        displayList();
        cout << endl;
    } while (true);

    do {
        cout << "Do you want to search for a specific student? [Y/N]: ";
        cin >> opt;

        if (opt == 'Y' || opt == 'y') {
            string srCode;
            cout << "Enter the SR-Code of the student to search: ";
            cin >> srCode;
            cout << endl;
            displayStudentDetails(srCode);
        } else if (opt == 'N' || opt == 'n') {
            cout << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }

        cout << endl;
    } while (true);

    cout << "Do you want to add another student? [Y/N]: ";
    cin >> opt;

    while (opt == 'Y' || opt == 'y') {
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

        cout << "Do you want to add another student? [Y/N]: ";
        cin >> opt;
    }

    system("CLS");
    cout << "All the information of the inputted students:\n\n";
    displayList();

    do {
        cout << "Do you want to remove a specific student? [Y/N]: ";
        cin >> opt;

        if (opt == 'Y' || opt == 'y') {
            string srCode;
            cout << "Enter the SR-Code of the student to remove: ";
            cin >> srCode;
            RemoveNode(srCode);
        } else if (opt == 'N' || opt == 'n') {
            cout << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }

        cout << endl;
        cout << "All the information of the remaining students:\n\n";
        displayList();
        cout << endl;
    } while (true);

    do {
        cout << "Do you want to search for a specific student? [Y/N]: ";
        cin >> opt;

        if (opt == 'Y' || opt == 'y') {
            string srCode;
            cout << "Enter the SR-Code of the student to search: ";
            cin >> srCode;
            cout << endl;
            displayStudentDetails(srCode);
        } else if (opt == 'N' || opt == 'n') {
            cout << endl;
            break;
        } else {
            cout << "Invalid choice." << endl;
        }

        cout << endl;
    } while (true);

    system("CLS");
    cout << "Final information of all the students:\n\n";
    displayList();

    cout << endl;
    cout << "Thank you for using the program." << endl;

    return 0;
}

