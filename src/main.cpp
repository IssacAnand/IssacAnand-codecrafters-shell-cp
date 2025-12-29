#include "helper_function.h" // the header file is a reference to tell the compiler that we will provide the implementation later
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //collection of general-purpose functions that C++ inherited from the original C language
#include <filesystem>// In C++, std::filesystem is a library (introduced in C++17) that gives your program the ability to "talk" to your computer's operating system about files and folders

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
    cout << command << ": command not found" <<endl;
    }
  }
  

return 0; // The program finished successfully
  
}
