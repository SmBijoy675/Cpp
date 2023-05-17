#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class Student {
public:
    string name;
    int age;
    int grade;
};

void calculateAverageGrade(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    vector<Student> students;
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        Student student;
        getline(ss, student.name, ',');
        ss >> student.age;
        ss.ignore();
        ss >> student.grade;
        students.push_back(student);
    }

    int totalGrades = 0;
    for (const auto& student : students) {
        totalGrades += student.grade;
    }

    double averageGrade = static_cast<double>(totalGrades) / students.size();

    cout << "Average grade: " << averageGrade << endl;

    file.close();
}

int main() {
    string filename = "students.csv";
    calculateAverageGrade(filename);
    return 0;
}
