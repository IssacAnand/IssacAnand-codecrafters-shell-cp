#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::cin;

int main() {
  // Flush after every std::cout / std:cerr
  std::cout << std::unitbuf;
  std::cerr << std::unitbuf;

  // TODO: Uncomment the code below to pass the first stage
string command;
while (true){
    cout << "$ ";
    std::getline(cin,command);
    cout << command << ": command not found" <<endl;
  }
  

  
  
}
