#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include "utils.h"

// The life/time saver
using namespace std;

// Simple exteption
struct ExitInput : public exception {};

// write an line of chars with 'n' size
void write_line(char c, int n) {
  for (int i = 0; i < n; ++i) {
    cout << c;
  }
  cout << endl;
}

// Function for header info visualisation
void show_header(string header_text) {
  write_line('=', header_text.size());
  cout << header_text << endl;
  write_line('=', header_text.size());
}

// Get content from vector and transform it on string line
string vector_out(vector<string>& content, string separator = "\n") {
  string result = "";
  for (int i = 0; i < content.size(); ++i) {
    result += content[i];
    if (i != content.size() - 1) result += separator; 
  }
  return result;
}

// Clear method based on ASCII
void clear_line(int lines_num) {
  for (int i = 0; i < lines_num; ++i) {
    cout << "\033[1A\033[2K" << flush;
  }
}

// Clear all console in same ASCII way 
// If your pc is srongest then my put max of console buffer not 200
void clear_all() {
    cout << "\033[999B";
    for (int i = 0; i < 200; ++i) {
        cout << "\033[2K\033[1A" << flush;
    }
    cout << "\033[H" << flush;
}

// Store the information from the vector into the data structure
void write_vector(vector<string>& buffer) {
  while (true)
  {
    string line;
    cin >> line;

    if (line == "-e") {
      clear_line(1);
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      break;
    }
    if (line == "-exit") throw ExitInput();

    buffer.push_back(line);
  }
}

void safe_input(string& input, int buf_size) {
  input.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  string tmp;
  getline(cin, tmp);

  if ((int)tmp.size() > buf_size) tmp = tmp.substr(0, buf_size);

  if (tmp == "-exit") throw ExitInput();

  input = tmp;
}