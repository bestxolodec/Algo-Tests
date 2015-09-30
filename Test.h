#ifndef _TEST_H

#include <iostream>
#include <fstream>
#include <string>


void Test(std::string input_filename, std::string result_filename,
          std::string correct_result_filename, int(*foo)(std::istream&, std::ostream&));

#endif
