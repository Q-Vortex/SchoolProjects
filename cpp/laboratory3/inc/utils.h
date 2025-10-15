#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using namespace std;

// Write an line of chars with 'n' size
void write_line(char c, int n);

// Function for header info visualisation
void show_header(string header_text);

// Get content from vector and transform it on string line
string vector_out(vector<string>& content, string separator);

// Clear method based on ASCII
void clear_line(int lines_num);

// Same function but clear all in console 
void clear_all();

// Store the information from the vector into the data structure
void write_vector(vector<string>& buffer);

void safe_input(string& input, int buf_size);

#endif