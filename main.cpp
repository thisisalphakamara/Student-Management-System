#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;
};

class StudentManagementSystem {
private:
    vector<Student> students;
    int nextId;

public:
    StudentManagementSystem() : nextId(1) {}

    void addStudent() {
        Student s;
        s.id = nextId++;
        cout << "Enter student name: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Enter student age: ";
        cin >> s.age;
        cout << "Enter student course: ";
        cin.ignore();
        getline(cin, s.course);
        students.push_back(s);
        cout << "Student added successfully!\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students to display.\n";
            return;
        }

        cout << "\n--- Student List ---\n";
        for (const auto &student : students) {
            cout << "ID: " << student.id << "\n"
                 << "Name: " << student.name << "\n"
                 << "Age: " << student.age << "\n"
                 << "Course: " << student.course << "\n\n";
        }
    }

    void deleteStudent() {
        int id;
        cout << "Enter the ID of the student to delete: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully!\n";
                return;
            }
        }

        cout << "Student with ID " << id << " not found.\n";
    }

    void updateStudent() {
        int id;
        cout << "Enter the ID of the student to update: ";
        cin >> id;

        for (auto &student : students) {
            if (student.id == id) {
                cout << "Enter new name (current: " << student.name << "): ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Enter new age (current: " << student.age << "): ";
                cin >> student.age;
                cout << "Enter new course (current: " << student.course << "): ";
                cin.ignore();
                getline(cin, student.course);
                cout << "Student updated successfully!\n";
                return;
            }
        }

        cout << "Student with ID " << id << " not found.\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Delete Student\n";
        cout << "4. Update Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sms.addStudent();
            break;
        case 2:
            sms.displayStudents();
            break;
        case 3:
            sms.deleteStudent();
            break;
        case 4:
            sms.updateStudent();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
