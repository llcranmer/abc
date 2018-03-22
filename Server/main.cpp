#include "ServerSetup.cpp"
#include "FileSystem.h"
#include "FileSystem.cpp"
int main () {

  FileSystem fileSystem;
  string fileName;
  cout << "Please enter the file: ";
  cin >> fileName;
  cout << "File Name: " << fileName << endl;
  fileSystem.inputMajorAndSalary(fileName);

  int portNumber;
  cout << "Enter server port number: ";
  cin >> portNumber;
  cin.ignore(100, '\n');

  int socketOpen = establish(portNumber);
  char buffer[512];

  string collegeMajor;
  string stSalary;
  string midSalary;

  int byte_count;
  int socketConnection;
  do {
    socketConnection = getConnection(socketOpen);
    memset(buffer, 0, sizeof(buffer));
    byte_count = recv(socketConnection,buffer, sizeof(buffer) - 1, 0);
    collegeMajor = string(buffer);
    if(!collegeMajor.empty()) {
      stSalary = fileSystem.stSalary(collegeMajor);
      midSalary = fileSystem.midSalary(collegeMajor);
      cout << "The average early career pay for a " << collegeMajor << " is $" << stSalary << endl;
      cout << "The corresponding mid-career pay is $" << midSalary << endl;
      salary = salary;
      byte_count = send(socketConnection, &salary, sizeof(salary), 0);
    }
  } while(socketConnection > 0);
  return(0);
}
