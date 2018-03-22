#include "FileSystem.h"
#include <string>
using namespace std;

 FileSystem::FileSystem() {
  vector<string> collegeMajors;
  vector<string> stSalaryPay;
  vector<string> midSalaryPay;
}
int FileSystem::inputMajorAndSalary(string fileName) {

  char collegeMajor[70];
  char avgStSalary[10];
  char avgMidSalary[10];
  char line[100];

  FILE *infile;
  infile = fopen(fileName.c_str(), "r");
  if(!infile){
    printf("Couldn't open %s for reading \n", fileName.c_str());
  }

  int row = 0;
  while(row < 512 && fgets(line,sizeof(line),infile) != NULL){
    sscanf(line,"%[^\t]\t%[^\t]\t%[^\n]\n", collegeMajor, avgStSalary, avgMidSalary);
    collegeMajors.push_back(collegeMajor);
    stSalaryPay.push_back(avgStSalary);
    midSalaryPay.push_back(avgMidSalary);
    ++row;
  }
  return collegeMajors.size();
}

string FileSystem::stSalary(string name){
  int stSalaryIndex = -1;
  for(int i = 0; i < collegeMajors.size(); ++i){
    if(name == collegeMajors[i]) {
      stSalaryIndex = i;
    }
  }
  if(stSalaryIndex < 0){
    srand(time(0));
    return rand() % 66 + 11;
  } else {
    return stSalaryPay[stSalaryIndex];
  }
}

string FileSystem::midSalary(string name){
  int midSalaryIndex = -1;
  for(int i = 0; i < collegeMajors.size(); ++i){
    if(name == collegeMajors[i]) {
      midSalaryIndex = i;
    }
  }
  if(midSalaryIndex < 0){
    return "blue";
  } else {
    return midSalaryPay[midSalaryIndex];
  }
}
