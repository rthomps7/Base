// Base.h
//
// Sets up everything in base that should be required for most programs

#include <iostream>
#include <sstream>
#include <string>
#include "sys/stat.h"
#include "unistd.h"

#include "logging.cc"

// Always use these namespaces
using namespace Logging;
using std::string;

static void INITIALIZE(int *argc, char*** argv) {
  // TODO(rft): This isn't very safe... :(
  char directory[256];
  getcwd(directory, 256);
  
  std::ostringstream log_file_stream;
  log_file_stream << directory << '/' << (*argv)[0] << ".INFO.log";
  std::cout << log_file_stream.str() << "\n";

}


// Show prototype of user defined main
int t_main(int argc, char** argv);

// Main always run in program
int main(int argc, char** argv) {
  INITIALIZE(&argc, &argv);
  int r_value = t_main(argc, argv);
  //FINISH();
  return r_value;
}
