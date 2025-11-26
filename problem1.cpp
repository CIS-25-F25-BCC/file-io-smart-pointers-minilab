// Problem 1: Broken File Reading
// This code attempts to read student records from a CSV file, but has several bugs.
// Fix all the issues so the program correctly reads and displays the data.
//
// Expected output when fixed (using data/students.csv):
//   Loaded 3 students:
//   Alice Johnson (ID: 1001, GPA: 3.80)
//   Bob Smith (ID: 1002, GPA: 3.50)
//   Carol White (ID: 1003, GPA: 3.90)

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string name;
    int id;
    double gpa;
};

std::vector<Student> readStudentsFromFile(std::string filename) {
    std::vector<Student> students;

    // BUG 1: No error checking if file opens successfully
    std::ifstream file(filename);

    std::string line;

    // BUG 2: Should skip the header row, but doesn't

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        Student s;

        // BUG 3: Using wrong delimiter (space instead of comma)
        std::getline(ss, s.name, ' ');

        std::getline(ss, field, ',');
        s.id = std::stoi(field);

        std::getline(ss, field, ',');
        s.gpa = std::stod(field);

        students.push_back(s);
    }

    // BUG 4: File is never closed (though RAII would handle this,
    // explicitly closing is good practice when you're done early)

    return students;
}

int main() {
    std::vector<Student> students = readStudentsFromFile("data/students.csv");

    std::cout << "Loaded " << students.size() << " students:" << std::endl;
    for (int i = 0; i < students.size(); i++) {
        std::cout << students[i].name
                  << " (ID: " << students[i].id
                  << ", GPA: " << students[i].gpa << ")" << std::endl;
    }

    return 0;
}
