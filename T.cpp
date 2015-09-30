// Copyright (c) 2015 Shvechikov Pavel
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

#ifdef DEBUG
#include "../Tests/Test.h"
#endif

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::istream;
using std::ostream;

const int NO_PREVIOS_FLAG = -1;

vector<int> ReadInput(istream& in);

void PrintOutput(ostream& out, const vector<int> &subsequence);

int SubMain(istream& in, ostream& out);


int main() {
#ifdef DEBUG
    Test("1.A_input.txt", "1.A_output.txt",
         "1.A_correct.txt",  &SubMain);
    return 0;
#else
    return SubMain(cin, cout);
#endif
}


int SubMain(istream& in, ostream& out){
    PrintOutput(out, ReadInput(in));
    return 0;
}

vector<int> ReadInput(istream &in) {
    // prepare stream
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);

    int numberCount;
    in >> numberCount;

    vector<int> sequence(numberCount);
    for (int i = 0; i < numberCount; ++i) {
        in >> sequence[i];
    }

    return sequence;
}

void PrintOutput(ostream& out, const vector<int> &subsequence) {
    for (size_t i = 0, size = subsequence.size(); i < size; ++i) {
        if (i != 0) {
            out << " ";
        }
        out << subsequence[i];
    }
    // flush buffer
    out << endl;
}

