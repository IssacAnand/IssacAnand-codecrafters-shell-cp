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
bool condition; // bool is built-in condition in c++
condition = true;
while (condition){
    cout << "$ ";
    std::getline(cin,command);
    if(command == "exit"){
      condition = false;
    }
    else if(command.substr(0,4 )== "echo"){
      string argument = command.erase(0,4);
      cout << argument <<endl;
    }
    else{
    cout << command << ": command not found" <<endl;
    }
  }
  

return 0; // The program finished successfully
  
}
