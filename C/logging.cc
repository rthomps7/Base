#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

#ifndef BASE_LOGGING_H
#define BASE_LOGGING_H

namespace Logging {

enum LOG_FILE {
  INFO,
  WARNING,
  ERROR
};

static std::fstream info_stream;

//class InfoStream


std::ostream& LOG_DATA(LOG_FILE file) {
  return std::cout;
}

}  // namespace Logging


// Associated Macros
#define LOG(type) Logging::LOG_DATA(type)


#endif // BASE_LOGGING_H





/*

// Should all actually be classes that inherit ostream so I can add more to it.
// For example, we always want to write to the all_stream, so we'd like 
// info_stream etc. to also call all_stream's write. 
// 
// Likewise, we want to end the program if fatal_stream is called
static std::fstream info_stream;
static std::fstream warning_stream;
static std::fstream fatal_stream;
static std::fstream all_stream;

// Open up correct log files
void Initialize() {

}

// Close all log files
void Finish() {
}

std::ostream& log_info() { return std::cout; }
std::ostream& log_warning() { return warning_stream; }
std::ostream& log_fatal() { return fatal_stream; }
std::ostream& log(std::string type) {
  return log_info();
}
}  // namespace Logging


#define LOG() log_info()
#define LOG(WARNING) Logging::log_warning()

#define INITIALIZE() \
  Logging::Initialize()
// add flags initialize too
// Give buld info in makefiles? or G++

#define FINISH() \
  Logging::Finish()


*/


