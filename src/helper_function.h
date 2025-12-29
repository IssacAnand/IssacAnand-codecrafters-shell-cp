#ifndef HELPER_FUNCTION_H
#define HELPER_FUNCTION_H

#include <string>
using std::string;

bool is_executable(const std::string& path);
string check_path(string full_path, string argument);
string is_in_builtin(string cmd);

#endif