#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int findLetter(string line) {
    int i = 0;
    bool isLetter = false;
    while(!isLetter) {
        if (line[i] >= 'A' && line[i] <= 'Z' || line[i] >= 'a' && line[i] <= 'z') {
            isLetter = true;
            return i;
        } else {
            i++;
        }
    }
    cout<<i;
    return '\0';
}

class Node {
public:
    Node(string line) {
        char tab = '\t';
        amount = stod(line.substr(0, tab));
        name = line.substr(findLetter(line));
        involvedInTransaction = false;
        next = nullptr;
    };
    double amount;
    string name;
    Node* next;
    bool involvedInTransaction;
    friend istream& operator>>(istream& ins, Node& node);
    friend ostream& operator<<(ostream& outs, Node& node);

};

istream& operator>>(istream& ins, Node& node) {
    char TAB = '\t';
    string amtInput;
    string nameInput;
    ins >> amtInput >> TAB >> nameInput;
    node.amount = stod(amtInput);
    node.name = nameInput;
    return ins;
}

ostream& operator<<(ostream& outs, Node& node) {
    outs << node.amount << " " << node.name;
    return outs;
}

double averageOfPaid(Node* head) {
    Node* current = head;
    double sumOfPaid = 0;
    double counter = 0;
    while (current != nullptr) {
        sumOfPaid += current->amount;
        counter++;
        current = current->next;
    }
    delete[] current;
    return sumOfPaid / counter;
}

void moveMoney(Node* head) {
    Node* start = head;
    Node* point = head;
    Node* runner = head->next;
    double average = averageOfPaid(head);
    double payment = 0;
    double pointDifference = 0;
    double runnerDifference = 0;
    for (int i = 0; point != nullptr; i++) {
        pointDifference = point->amount - average;
        if (point->amount < average) { // point underpaid
            point->involvedInTransaction = true;
            while(runner != nullptr && point->amount < average) {
                runnerDifference = runner->amount - average;
                if (runner->amount > average && abs(pointDifference) > abs(runnerDifference)) { // if point difference > runner difference
                    runner->involvedInTransaction = true;
                    point->amount += abs(runnerDifference);
                    runner->amount -= abs(runnerDifference);
                    cout << point->name << ", you give " << runner->name << " $" << abs(runnerDifference)<<endl; // abs could be int function, be careful
                } else if (runner->amount > average && abs(pointDifference) < abs(runnerDifference)) { // if point difference < runner difference
                    runner->involvedInTransaction = true;
                    point->amount += abs(pointDifference);
                    runner->amount -= abs(pointDifference); 
                    cout << point->name << ", you give " << runner->name << " $" << abs(pointDifference)<<endl; // abs could be int function, be careful
                }
                runner = runner->next;
            }
        } else if (point->amount > average) { // point overpaid
            point->involvedInTransaction = true;
            while(runner != nullptr && point->amount > average) {
                runnerDifference = runner->amount - average;
                if (runner->amount < average && abs(pointDifference) > abs(runnerDifference)) { // if point difference > runner difference
                    runner->involvedInTransaction = true;
                    point->amount -= abs(runnerDifference);
                    runner->amount += abs(runnerDifference);
                    cout << runner->name << ", you give " << point->name << " $" << abs(runnerDifference)<<endl; // abs could be int function, be careful
                } else if (runner->amount < average && abs(pointDifference) < abs(runnerDifference)) { // if point difference < runner difference
                    runner->involvedInTransaction = true;
                    point->amount -= abs(pointDifference);
                    runner->amount += abs(pointDifference);
                    cout << runner->name << ", you give " << point->name << " $" << abs(pointDifference)<<endl; // abs could be int function, be careful
                }
                runner = runner->next;
            }
        } else if (point->amount == average && point->involvedInTransaction == false) {
            cout << point->name << " you don't need to do anything."<<endl;
        }
        point = point->next;
        runner = start;
    }
    cout<<"In the end, you all should have spent about $"<<average<<endl;
    delete start;
    delete point;
    delete runner;
}

void openInputFile(ifstream& inFile) {
    string filename;
    cout <<"What filename?: ";
    cin >> filename;
    inFile.open(filename);
    while(!inFile) {
        cout << "FILE FAILED TO OPEN!" << endl;
        cout<< "What filename?: ";
        cin >> filename;
        inFile.clear();
        inFile.open(filename);
    }
}

int main() {
    ifstream myFile;
    openInputFile(myFile);

    Node* head = nullptr;
    Node* current = nullptr;

    string line;

    // reading in the file and creating the linked list
    while (getline(myFile, line)) {
        Node* newNode = new Node(line);
        if (head == nullptr) {
            head = newNode;
            current = newNode;
        } else {
            current->next = newNode;
            current = newNode;
        }
    }
    myFile.close();

    moveMoney(head);
    
    // deleting the linked list
    current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    delete head;
    delete current;

    return 0;
}
