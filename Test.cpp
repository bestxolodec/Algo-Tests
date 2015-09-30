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


  // actually run the program and write output to result_filename
  ofstream result;
  result.open(result_filename);
  // input.good() && !input.eof()

  int next_byte;
  while ((next_byte = input.peek()) != EOF) {
    cerr << (char)next_byte << endl;
    foo(input, result);
    // eat leading whitespaces
    input >> std::ws;
  }
  result.close();
  input.close();


  ifstream expected;
  expected.open(correct_result_filename);

  ifstream program_output;
  program_output.open(result_filename);


  int j = 0;
  bool correct = true;
  string got_string, expected_string;
  while (expected.good() && program_output.good()) {
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
    }
    // expected >> std::ws;
    // program_output >> std::ws;

  }
  if (correct) {
    cerr << "ALL TESTS HAVE BEEN COMPLETED WITHOUT MISSES" << endl;
  }
  program_output.close();
  expected.close();
}
