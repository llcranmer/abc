#include "ServerSetup.cpp"
#include "FileSystem.h"
#include "FileSystem.cpp"
int main () {
  FileSystem fileSystem;
  string fileName;
  cout << "Please enter the file: ";
  cin >> fileName;
  cout << "File Name: " << fileName << endl;

  int listSize = fileSystem.inputMajorAndSalary(fileName);

  int portNumber;
  cout << "Enter server port number: ";
  cin >> portNumber;
  cin.ignore(100, '\n');

  int socketOpen = establish(portNumber);


  char buffer[512];
  string collegeMajor;
  int byte_count;
  int socketConnection;
  do {
    socketConnection = getConnection(socketOpen);
    memset(buffer, 0, sizeof(buffer));
    byte_count = recv(socketConnection,buffer, sizeof(buffer) - 1, 0);
    collegeMajor = string(buffer);

    if(!collegeMajor.empty()) {


      string stSalary = fileSystem.stSalary(collegeMajor);
      string midSalary = fileSystem.midSalary(collegeMajor);

      byte_count = send(socketConnection, &stSalary, sizeof(stSalary), 0);
      byte_count = send(socketConnection, &midSalary, sizeof(midSalary), 0);
    

    }
  } while(socketConnection > 0);
  return(0);
}
