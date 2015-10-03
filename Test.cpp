#include "Test.h"

using std::ostream;
using std::istream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::cerr;
using std::cin;
using std::endl;


void Test(string input_filename, string result_filename,
          string correct_result_filename, int(*foo)(istream&, ostream&)) {
  // read input data from file
  ifstream input;
  input.open(input_filename);
  if (!input.is_open()) {
    cerr << "Cannot open file: " << input_filename << "\n";
    throw std::exception();
  }


  ofstream result;
  result.open(result_filename);
  // input.good() && !input.eof()
  if (!result.is_open()) {
    cerr << "Cannot open file: " << result_filename << "\n";
    throw std::exception();
  }

  // should be rewritten to support  _INPUT_ @ _OUTPUT_ format
  // see here http://stackoverflow.com/questions/236129/split-a-string-in-c
  // actually run the program and write output to result_filename
  std::string line;
  while (std::getline(input, line)) {
    std::stringstream in(line);
    // std::cout << "Input: " << in.str() << endl;
    foo(in, result);
    // std::cout << "Input after: " << in.str() << endl;
    // eat leading whitespaces
    input >> std::ws;
  }

  // while ((next_byte = input.peek()) != EOF) {
    // foo(input, result);
    // // eat leading whitespaces
    // input >> std::ws;
  // }
  result.close();
  input.close();


  ifstream expected;
  expected.open(correct_result_filename);
  if (!expected.is_open()) {
    cerr << "Cannot open file: " << correct_result_filename << "\n";
    throw std::exception();
  }

  ifstream program_output;
  program_output.open(result_filename);
  if (!program_output.is_open()) {
    cerr << "Cannot open file: " << result_filename << "\n";
    throw std::exception();
  }

  int j = 0;
  bool correct = true;
  string got_string, expected_string;
  while (expected.good()) {
    j++;
    std::getline(expected, expected_string);
    std::getline(program_output, got_string);
    // cerr << got_string << endl;
    // cerr << expected_string << endl;
    if (got_string != expected_string) {
      cerr << j << "-the strings are not equal" << "\n";
      cerr << "Expected:   " << expected_string << "\n";
      cerr << "Got     :   " << got_string << "\n";
      correct = false;
    } else {
      cerr <<  j << "-th test passed\n" ;
    }
  }
  if (correct) {
    cerr << "ALL TESTS HAVE BEEN COMPLETED WITHOUT MISSES" << endl;
  }
  program_output.close();
  expected.close();
}
