#include <iostream>
#include <fstream>
#include <jsoncpp/json/json.h>
using namespace std;

void calculateTotalSalaryExpenditure(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Failed to open the file." << endl;
        return;
    }

    Json::Value jsonData;
    file >> jsonData;

    int totalSalary = 0;
    for (const auto& employee : jsonData["employees"]) {
        int salary = employee["salary"].asInt();
        totalSalary += salary;
    }

    cout << "Total salary expenditure: " << totalSalary << endl;

    file.close();
}

int main() {
    string filename = "employees.json";
    calculateTotalSalaryExpenditure(filename);
    return 0;
}
