#include <iostream>
#include <list>

using namespace std;

// Define the Student structure to hold student information.
struct Student {
    int id;
    string name;
    int age;
};

// Create a linked list to store student records.
list<Student> studentDatabase;

// Function to add a new student to the database.
void addStudent(int id, const string& name, int age) {
    Student student;
    student.id = id;
    student.name = name;
    student.age = age;
    studentDatabase.push_back(student);
}

// Function to search for a student by ID and display their information.
void searchStudent(int id) {
    for (const Student& student : studentDatabase) {
        if (student.id == id) {
            cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << endl;
            return; // Student found, exit the function.
        }
    }
    cout << "Student not found with ID " << id << endl;
}

// Function to delete a student from the database by ID.
void deleteStudent(int id) {
    studentDatabase.remove_if([id](const Student& student) { return student.id == id; });
}

// Function to display information of all students in the database.
void displayStudents() {
    for (const Student& student : studentDatabase) {
        cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << "\n\n";
    }
}

int main() {
    // Example usage:
    addStudent(1, "Alice", 20);
    addStudent(2, "Bob", 22);
    addStudent(3, "Charlie", 21);

    displayStudents();

    searchStudent(2);

    deleteStudent(2);

    cout << "After deleting student 2:\n";
    displayStudents();

    return 0;
}
