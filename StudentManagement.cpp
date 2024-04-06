#include <iostream>
#include<string>
#include <fstream>
#include<stdlib.h>
using namespace std;

class Node {
public:
    int roll_no;
    string name, father_name, qualification, phone_no;
    Node* next;
};

class Linked_List {
public:
    Node* head;

    Linked_List() {
        head = NULL;
    }

    void insert() {
        Node* new_node = new Node();
        fstream file("Items.txt", ios::app);

        cout << "\nEnter roll number: ";
        cin >> new_node->roll_no;
        file << new_node->roll_no << endl;

        cout << "\nEnter name: ";
        cin >> new_node->name;
        file << new_node->name << endl;

        cout << "\nEnter father's name: ";
        cin >> new_node->father_name;
        file << new_node->father_name << endl;

        cout << "\nEnter qualification: ";
        cin >> new_node->qualification;
        file << new_node->qualification << endl;

        cout << "\nEnter phone number: ";
        cin >> new_node->phone_no;
        file << new_node->phone_no << endl;

        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
        file.close();
        cout << "\nNew node inserted";
    }

    void search() {
        int roll_no, found = 0;
        cout << "\nEnter roll number to search: ";
        cin >> roll_no;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->roll_no == roll_no) {
                cout << "\nRecord found: ";
                cout << "\nRoll number: " << temp->roll_no;
                cout << "\nName: " << temp->name;
                cout << "\nFather's name: " << temp->father_name;
                cout << "\nQualification: " << temp->qualification;
                cout << "\nPhone number: " << temp->phone_no;
                found = 1;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\nRecord not found";
        }
    }

    void display() {
        Node* temp = head;
        if (temp == NULL) {
            cout << "\nList is empty";
        } else {
            while (temp != NULL) {
                cout << "\nRoll number: " << temp->roll_no;
                cout << "\nName: " << temp->name;
                cout << "\nFather's name: " << temp->father_name;
                cout << "\nQualification: " << temp->qualification;
                cout << "\nPhone number: " << temp->phone_no;
                temp = temp->next;
            }
        }
    }

    void update() {
        int roll_no, found = 0;
        cout << "\nEnter roll number to update: ";
        cin >> roll_no;

        Node* temp = head;

        while (temp != NULL) {
            if (temp->roll_no == roll_no) {
                cout << "\nEnter new roll number: ";
                cin >> temp->roll_no;

                cout << "\nEnter new name: ";
                cin >> temp->name;

                cout << "\nEnter new father's name: ";
                cin >> temp->father_name;

                cout << "\nEnter new qualification: ";
                cin >> temp->qualification;

                cout << "\nEnter new phone number: ";
                cin >> temp->phone_no;

                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "\nRecord not found";
        }
    }

    void delete_node() {
        int roll_no, found = 0;
        Node* temp, *prev;

        cout << "\nEnter roll number to delete: ";
        cin >> roll_no;

        if (head->roll_no == roll_no) {
            temp = head;
            head = head->next;
            delete temp;
            found = 1;
        } else {
            temp = head;
            prev = NULL;
            while (temp != NULL) {
                if (temp->roll_no == roll_no) {
                    prev->next = temp->next;
                    delete temp;
                    found = 1;
                    break;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        if (!found) {
            cout << "\nRecord not found";
        }
    }
};

int main() {
    Linked_List list;
    int choice;
    while (1) {
        cout << "\n\n1. Insert record";
        cout << "\n2. Search record";
        cout << "\n3. Display record";
        cout << "\n4. Update record";
        cout << "\n5. Delete record";
        cout << "\n6. Exit";

        cout << "\n\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.insert();
                break;
            case 2:
                list.search();
                break;
            case 3:
                list.display();
                break;
            case 4:
                list.update();
                break;
            case 5:
                list.delete_node();
                break;
            case 6:
                exit(0);
            default:
                cout << "\nInvalid choice!";
        }
    }

    return 0;
}
