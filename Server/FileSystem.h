#ifndef FileSystem_h
#define FileSystem_h

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <cctype>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>
#include <vector>
#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class FileSystem {
  public:
    FileSystem();
    int inputMajorAndSalary(string fileName);
    string stSalary(string name);
    string midSalary(string name);
  private:
    vector<string> collegeMajors;
    vector<string> stSalaryPay;
    vector<string> midSalaryPay;
};

#endif
