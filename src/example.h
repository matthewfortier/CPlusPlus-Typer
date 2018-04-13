#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <sstream>
using namespace std;

#pragma once

double add_numbers(const double f1, const double f2);

double subtract_numbers(const double f1, const double f2);

double multiply_numbers(const double f1, const double f2);

vector<string> explode(const string &str, const char &ch);

void reverseStr(string &str);

bool moby_dick_check(string input);

bool wpm_check(string input, double duration);

bool joke_check(string input);

bool reverse_check(string input);

void ShowMenu();