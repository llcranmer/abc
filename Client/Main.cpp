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
  std::string stSalary;
  std::string midSalary;
  int byte_count;

  std::cin.ignore (256, '\n');

  do {
    std::cout << "Enter a college major: ";
    getline(std::cin, collegeMajor);
    std::cin.clear();

    if (!collegeMajor.empty()) {


      byte_count = send(socketNumber, collegeMajor.c_str(), collegeMajor.size(), 0);

      byte_count = recv(socketNumber, &stSalary, sizeof(stSalary), 0);
      if(stSalary != "DNE"){
        std::cout << "The average early career pay for a " << collegeMajor << " major is $" << stSalary << std::endl;
        byte_count = recv(socketNumber, &midSalary, sizeof(midSalary), 0);
        std::cout << "The corresponding mid-career pay is $"<< midSalary << std::endl;
      } else { std::cout << "That major is not in the table" << std::endl;}
    }

    byte_count = close(socketNumber);
    socketNumber = callSocket(hostName, serverPort);
  } while (!collegeMajor.empty());

  return(0);
}
