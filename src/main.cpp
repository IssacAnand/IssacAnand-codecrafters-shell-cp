#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //collection of general-purpose functions that C++ inherited from the original C language
#include <filesystem>// In C++, std::filesystem is a library (introduced in C++17) that gives your program the ability to "talk" to your computer's operating system about files and folders

using std::string;
using std::cout;
using std::endl;
using std::cin;
namespace fs =std::filesystem;



string check_path(string full_path, string argument) {
  // check functionality
  bool condition{true};

  while(!full_path.empty()){
    // break the string and test here
    size_t colon_pos = full_path.find(':');
    string directory;

    if(colon_pos != string::npos){ //npos is a way of saying not found, since cant return 0 as 0 is an index
       directory = full_path.substr(0,colon_pos);
      string target_file = directory + '/' + argument;
      full_path.erase(0,colon_pos+1);
    }
      else{
        //check the last path
        directory= full_path;
        full_path.clear();
      }
        string target_file = full_path + '/' + argument;
        if(fs::exists(target_file)){
        cout << argument << " is " << target_file <<endl;
        return target_file;
        }
  }
 return "";
}


string is_in_builtin(string cmd){
std::vector<string> BUILT_IN_TYPES = {"echo", "exit", "type"}; // basic arrays dont have methods, so need to loop through manually
for(string b: BUILT_IN_TYPES){
  if(cmd == b){
    return cmd;
  }
} // ADD THE PATH Functionality here
  char* raw_path =  std::getenv("PATH");
  // cout << raw_path;
  if (raw_path != nullptr) {
    string current_path = raw_path;
    return check_path(current_path, cmd); //return true or false
  }
}

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
      if (result != ""){
        cout << argument << " is " << "usr" + '/' + result<<endl;
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
