#include "helper_function.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> //collection of general-purpose functions that C++ inherited from the original C language
#include <filesystem>// In C++, std::filesystem is a library (introduced in C++17) that gives your program the ab

using std::string;
using std::cout;
using std::endl;
using std::cin;
namespace fs =std::filesystem;

bool is_executable(const std::string& path) {
    try {
        fs::perms p = fs::status(path).permissions();
        
        // Check if any execution bit is set (Owner, Group, or Others)
        return ((p & fs::perms::owner_exec) != fs::perms::none ||
                (p & fs::perms::group_exec) != fs::perms::none ||
                (p & fs::perms::others_exec) != fs::perms::none);
    } catch (const fs::filesystem_error& e) {
        return false; // Path doesn't exist or isn't accessible
    }
}

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
        string target_file = directory + '/' + argument;
        if(fs::exists(target_file) && is_executable(target_file)){
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