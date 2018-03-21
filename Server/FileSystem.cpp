#include "FileSystem.h"
#include <string>
using namespace std;

 FileSystem::FileSystem() {
  vector<string> collegeMajorList;
  vector<int> salaryList;
}
int FileSystem::inputMajorAndSalary(string fileName) {
  string data;
  ifstream readFile;

  readFile.open(fileName.c_str());

  while(readFile.good()) {

    readFile >> data;
    cout << "Data: " << data << endl;
    collegeMajorList.push_back(data);

    int salary;

    readFile >> salary;
    // To do
    // pushback the starting salary and then the mid salary
    cout << "salary: " << salary << endl;
    salaryList.push_back(salary);

  }
  readFile.close();
  for(int i = 0; i <collegeMajorList.size(); ++i){
    cout << "Here is the major: " << collegeMajorList[i] << std::endl;
  }
  return collegeMajorList.size();
}

int FileSystem::returnSalary(string name) {
  int salaryIndex = -1;
  for (int i = 0; i < collegeMajorList.size(); i++) {
    if(name == collegeMajorList[i]) {
      salaryIndex = i;
    }
  }
  if(salaryIndex < 0) {
    srand(time(0));
    return rand() % 66 + 11;
  } else {
    return salaryList[salaryIndex];
  }
}
