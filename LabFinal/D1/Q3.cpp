#include <iostream>
#include <list>

using namespace std;

// Define the Student structure to hold student information.
struct Student {
    int id;
    string name;
    int age;
};

// Create a class to manage the student database using a linked list.
class StudentDatabase {
private:
    list<Student> students;

public:
    // Function to add a new student to the database.
    void addStudent(int id, const string& name, int age) {
        Student student;
        student.id = id;
        student.name = name;
        student.age = age;
        students.push_back(student);
    }

    // Function to search for a student by ID and display their information.
    void searchStudent(int id) {
        for (const Student& student : students) {
            if (student.id == id) {
                cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << endl;
                return; // Student found, exit the function.
            }
        }
        cout << "Student not found with ID " << id << endl;
    }

    // Function to delete a student from the database by ID.
    void deleteStudent(int id) {
        students.remove_if([id](const Student& student) { return student.id == id; });
    }

    // Function to display information of all students in the database.
    void displayStudents() {
        for (const Student& student : students) {
            cout << "ID: " << student.id << "\nName: " << student.name << "\nAge: " << student.age << "\n\n";
        }
    }
};

int main() {
    StudentDatabase database;

    // Example usage:
    database.addStudent(1, "Alice", 20);
    database.addStudent(2, "Bob", 22);
    database.addStudent(3, "Charlie", 21);

    database.displayStudents();

    database.searchStudent(2);

    database.deleteStudent(2);

    database.displayStudents();

    return 0;
}
