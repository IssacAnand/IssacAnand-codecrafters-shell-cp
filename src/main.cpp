#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::cin;

bool is_in_builtin(string cmd){
std::vector<string> BUILT_IN_TYPES = {"echo", "exit", "type"}; // basic arrays dont have methods, so need to loop through manually
for(string b: BUILT_IN_TYPES){
  if(cmd == b){
    return true;
  }
}
  return false;
}

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

    else if(command.substr(0,4)=="type"){
      string argument = command.erase(0,5);
      if (is_in_builtin(argument)){
        cout << argument << " is a shell builtin"<<endl;
      }
      else{
        cout << argument << ": not found"<<endl;
      }
      }

    else if(command.substr(0,4)== "echo"){ // removes the space as well
      string argument = command.erase(0,5); //erase changes the value of the variable itself
      cout << argument <<endl;
    }

    else{
    cout << command << ": command not found" <<endl;
    }
  }
  

return 0; // The program finished successfully
  
}
