#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string msg;
    string op1, op2, op3, op4;
    int mood;
    // Changed to double to support 2.5 and 7.5
    double point1, point2, point3, point4; 
    Node* next;
    Node* path1 = nullptr;
    Node* path2 = nullptr;
    Node* path3 = nullptr;

    Node(string msg, string op1, string op2, string op3, string op4, int mood) {
        this->msg = msg;
        this->op1 = op1;
        this->op2 = op2;
        this->op3 = op3;
        this->op4 = op4;
        this->point1 = 2.5;
        this->point2 = 5.0;
        this->point3 = 7.5;
        this->point4 = 10.0;
        this->mood = mood;
        // FIX: Properly initialize the member pointer
        this->next = nullptr; 
    }
};

class Tree {
public:
    // Changed to double to match the node points
    double point = 0.0; 
    // FIX: Initialize root to nullptr
    Node* root = nullptr; 

    void add(string msg, string op1, string op2, string op3, string op4, int mood) {
        if (root == nullptr) {
            root = new Node(msg, op1, op2, op3, op4, mood);
        } else {
            Node* cur = root;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = new Node(msg, op1, op2, op3, op4, mood);
        }
    }

    int counter() {
        int count = 0;
        Node* cur = root;
        while (cur != nullptr) {
            count++;
            cur = cur->next;
        }
        return count;
    }

    void judge(Node* n1, Node* n2, Node* n3) {
        if (root == nullptr) return; // Safety check
        
        Node* cur = root;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        if (point >= counter() * 7.5) {
            cur->next = n1;
        } else if (point >= counter() * 5) {
            cur->next = n2;
        } else {
            cur->next = n3;
        }
    }

    void ask() {
        Node* cur = root;
        while (cur != nullptr) {
            cout << cur->msg << endl;
            cout << "1. " << cur->op1 << endl;
            cout << "2. " << cur->op2 << endl;
            cout << "3. " << cur->op3 << endl;
            cout << "4. " << cur->op4 << endl;
            
            int choice;
            cout << "Enter your choice (1-4): ";
            cin >> choice;
            
            switch (choice) {
                case 1:
                    point += cur->point1;
                    break;
                case 2:
                    point += cur->point2;
                    break;
                case 3:
                    point += cur->point3;
                    break;
                case 4:
                    point += cur->point4;
                    break;
                default:
                    cout << "Invalid choice, no points added." << endl;
                    break;
            }
            cur = cur->next;
            cout << "Current points: " << point << "\n\n";
        }
    }
};

int main() {
    Tree* t1 = new Tree();
    t1->add("Do you currently own a home?", "Yes", "No, but I plan to", "No, and I don't plan to", "Not sure", 1);
    t1->add("Would your partner own a home?", "Yes", "No, but they plan to", "No, and they don't plan to", "Not sure", 1);
    t1->ask();
    
    // Clean up memory (good practice)
    delete t1;
    return 0;
}