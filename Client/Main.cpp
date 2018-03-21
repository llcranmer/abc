#include "ClientSocket.cpp"

int main() {
  int socketNumber;
  std::string hostName;
  int serverPort;

  do {
    std::cout << "Enter a server host name: ";
    std::cin >> hostName;
    std::cout << "Enter a server port number: ";
    std::cin >> serverPort;
    socketNumber = callSocket(hostName, serverPort);
  } while (socketNumber < 0);


  std::string collegeMajor;
  int salary, byte_count;
  std::cin.ignore (256, '\n');


  do {
    std::cout << "Enter a college major: ";
    getline(std::cin, collegeMajor);
    std::cin.clear();

    if (!collegeMajor.empty()) {
      byte_count = send(socketNumber, collegeMajor.c_str(), collegeMajor.size(), 0);
      byte_count = recv(socketNumber, &salary, sizeof(salary), 0);
      salary = ntohs(salary); // ntohs
      std::cout << "The average early career pay for a " << collegeMajor << " is $" << salary << std::endl;
    }

    byte_count = close(socketNumber);
    socketNumber = callSocket(hostName, serverPort);
  } while (!collegeMajor.empty());

  return(0);
}
