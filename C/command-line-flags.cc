#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>


namespace CommandLineFlags {

static std::map<std::string, std::pair<std::string, std::string> > FLAGS;

/*
class CommandLineFlags {
 public: 
  CommandLineFlags();

  static void AddString(std::string name) {
    std::cout << "name: " << name;
  }


 private:
  static std::vector<std::string> strings;

};
*/

#define DEFINE_flag(name, type, description) \
  CommandLineFlags::FLAGS[name] = std::pair<std:string, std:string>(type, description)
//make_pair(type, description)

#define DEFINE_string(name, description) \
  DEFINE_flag(name, 'string', description)
  

// CommandLineFlags::strings.push_back(name);
//  CommandLineFlags::AddString(name) \


//DEFINE_string(filename)

}  // namepace CommandLineFlags

int main(int argv, char* argc) {
  std::vector<int> a;
  std::pair<char, int> b; 
  b = std::pair<char, int>('T', 4);
  

 // DEFINE_string("filename", "This is the file to be opened");
  std::cout << "DONE\n";
  return 1;

}
