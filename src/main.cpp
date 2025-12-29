#include "helper_function.h" // the header file is a reference to tell the compiler that we will provide the implementation later
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //collection of general-purpose functions that C++ inherited from the original C language

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

bool condition{true}; // bool is built-in condition in c++



while (condition){
    cout << "$ ";
    std::getline(cin,command); // getline() is a function that reads a whole chunk of text until it hits a specific "stop sign."
    if(command == "exit"){
      condition = false;
    }

    else if(command.substr(0,4)=="type"){
      string argument = command.erase(0,5);
      string result = is_in_builtin(argument);
      if ( result =="echo"|| result == "exit" || result =="type"){
        cout << result << " is a shell builtin"<<endl;
      }
      else if (result != ""){
        cout << argument << " is " << result<<endl;
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
        string result;
        char* raw_path =  std::getenv("PATH");
        cout<< command<<endl;
        // cout << raw_path;
        if (raw_path != nullptr) {
          string current_path = raw_path;

          result = check_external_program(current_path, command); // stores the program path
          }
        if (result != ""){
          int num_of_args = command.length();
          cout << "Program was passed " << num_of_args << " args (including program name)" <<endl;
        }
        else{
          cout << command << ": command not found" <<endl;
        }
  }
  

return 0; // The program finished successfully
  
}
}
