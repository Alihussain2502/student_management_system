#include <iostream>
#include <vector>
using namespace std;

class Student {
private:
    int rollno, age;
    string name;

public:
    Student(int stdRollno, int stdAge, string stdName) {
        rollno = stdRollno;
        age = stdAge;
        name = stdName;
    }
    void setRollno(int stdRollno) { rollno = stdRollno; }
    int getRollno() const { return rollno; }
    void setName(const string &stdName) { name = stdName; }
    string getName() const { return name; }
    void setAge(int stdAge) { age = stdAge; }
    int getAge() const { return age; }
    void displayStudent() const {
        cout << "Rollno: " << rollno << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

void UpdateStudent(vector<Student> &students) {
    string name;
    bool found = false;
    cout << "Enter the name of the student to update: ";
    cin.ignore(); // Ignore any leftover newline characters in the input buffer
    getline(cin, name);
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {
            found = true;
            cout << "Student Found!" << endl;
            cout << "1. Update Rollno" << endl;
            cout << "2. Update Name" << endl;
            cout << "3. Update Age" << endl;
            cout << "Enter Your Choice: ";
            int choice;
            cin >> choice;
            switch (choice) {
            case 1: {
                int rollno;
                cout << "Enter the new Rollno: ";
                cin >> rollno;
                students[i].setRollno(rollno);
                break;
            }
            case 2: {
                string newName;
                cout << "Enter the new Name: ";
                cin.ignore(); // Ignore any leftover newline characters in the input buffer
                getline(cin, newName);
                students[i].setName(newName);
                break;
            }
            case 3: {
                int age;
                cout << "Enter new Age: ";
                cin >> age;
                students[i].setAge(age);
                break;
            }
            default:
                cout << "Invalid Number" << endl;
            }
            break;
        }
    }
    if (!found) {
        cout << "Record not found" << endl;
    }
}

void SearchStudent(const vector<Student> &students) {
    int rollno;
    cout << "Enter Rollno to search: ";
    cin >> rollno;
    bool found = false;
    for (const auto &student : students) {
        if (student.getRollno() == rollno) {
            cout << "Student found:" << endl;
            student.displayStudent();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Student not found" << endl;
    }
}

void DisplayAllStudents(const vector<Student> &students) {
    if (students.empty()) {
        cout << "No student found" << endl;
        return;
    }
    for (const auto &student : students) {
        student.displayStudent();
        cout << endl;
    }
}

void addNewStudent(vector<Student> &students) {
    int rollno, age;
    string name;

    cout << "Enter Rollno: ";
    cin >> rollno;
    for (const auto &student : students) {
        if (student.getRollno() == rollno) {
            cout << "Student already exists" << endl;
            return;
        }
    }
    cout << "Enter Name: ";
    cin.ignore(); // Ignore any leftover newline characters in the input buffer
    getline(cin, name);
    cout << "Enter Age: ";
    cin >> age;
    Student newStudent(rollno, age, name);
    students.push_back(newStudent);

    cout << "Student Added successfully" << endl;
}

void deleteStudent(vector<Student> &students) {
    string name;
    cout << "Enter name to Delete: ";
    cin.ignore(); // Ignore any leftover newline characters in the input buffer
    getline(cin, name);
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {
            students.erase(students.begin() + i);
            cout << "Student Deleted Successfully" << endl;
            return; // Exit after deleting to avoid iterator invalidation
        }
    }
    cout << "Student not found" << endl;
}

int main() {
    vector<Student> students;
    students.push_back(Student(1, 20, "Ali"));
    char choice;
    do {
        int option;
        cout << "1. Add New Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Update Student" << endl;
        cout << "5. Delete Student" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> option;
        switch (option) {
        case 1:
            addNewStudent(students);
            break;
        case 2:
            DisplayAllStudents(students);
            break;
        case 3:
            SearchStudent(students);
            break;
        case 4:
            UpdateStudent(students);
            break;
        case 5:
            deleteStudent(students);
            break;
        case 6:
            return 0;
        default:
            cout << "Invalid Number" << endl;
        }
        cout << "Do you want to continue (yes/no): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
}
