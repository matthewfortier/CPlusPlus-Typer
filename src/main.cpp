//
//  main.cpp
//  MobyDickTyper
//
//  Created by Matthew Fortier on 4/12/18.
//  Copyright © 2018 Matthew Fortier. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <vector>
#include <sstream>
#include <ctime>
#include "example.h"
using namespace std;

vector<string> explode(const string &str, const char &ch)
{
    string next;
    vector<string> result;

    // For each character in the string
    for (string::const_iterator it = str.begin(); it != str.end(); it++)
    {
        // If we've hit the terminal character
        if (*it == ch)
        {
            // If we have some characters accumulated
            if (!next.empty())
            {
                // Add them to the result vector
                result.push_back(next);
                next.clear();
            }
        }
        else
        {
            // Accumulate the next character into the sequence
            next += *it;
        }
    }
    if (!next.empty())
        result.push_back(next);
    return result;
}

bool moby_dick_check(string input)
{
	ifstream file("moby.txt");
	if (file)
	{
		file.seekg(0, std::ios::end);
		std::streampos length = file.tellg();
		file.seekg(0, std::ios::beg);
		std::vector<char> buffer(length);
		file.read(&buffer[0], length);

		std::string str(buffer.begin(), buffer.end());

		if (str == input) {
			cout << "That's right!\n";
			std::cin.get();
			return true;
		}
		else {
			cout << "That's not right!\n";
			std::cin.get();
			return false;
		}
	}
	else
	{
		cout << "Fail" << endl;
	}
}

string moby_dick()
{
	ifstream file("moby.txt");
	if (file)
	{
		file.seekg(0, std::ios::end);
		std::streampos length = file.tellg();
		file.seekg(0, std::ios::beg);
		std::vector<char> buffer(length);
		file.read(&buffer[0], length);

		std::string str(buffer.begin(), buffer.end());

		cout << str << "\n";

		string result;
		cin >> result;

		return result;
	}
	else
	{
		cout << "Fail" << endl;
	}
}


string wpm()
{
	string input;
	cin >> input;

	return input;
}

bool wpm_check(string input, double duration)
{
	std::vector<std::string> result = explode(input, ' ');
	int count;
	count = result.size();

	float wpm;
	wpm = count / duration;

	std::cout << "Your Words per second : " << wpm << '\n';
	std::cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (wpm > 1) {
		std::cout << "W O W\n";
		std::cin.get();
		return true;
	}
	else {
		std::cout << "that's not fast at all\n";
		std::cin.get();
		return false;
	}
}

string joke()
{
	string input;
	cout << "Complete this classic computer science joke: \nIt's not a bug, it's a ____!\n";
	cin >> input;
	return input;
}

bool joke_check(string input)
{
	std::cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (input == "bug") {
		cout << "\nHaha classic  C O M P U T E R   S C I E N C E!\n";
		std::cin.get();
		return true;
	}
	else {
		cout << "\nS Y N T " << char(123) << " " << char(126) << " A X E " << char(62) << " " << char(168) << " R R O R - O R - O" << char(245) << char(234);
		std::cin.get();
		return false;
	}
}

string reverse()
{
	string input;
	cout << "Re-write this lorem ipsum nonsense in reverse\n";
	cout << "Lorem ipsum dolor sit amet, eam et cibo electram, eu decore mediocritatem pri, vix ei malorum alienum dissentiunt. Id cum consectetuer signiferumque. His probo quando an, no est suas saepe. Abhorreant mnesarchum cotidieque vel ut, tempor salutatus mel ut, nominavi eloquentiam sit id. Id liber persecuti adipiscing nec. Te eos falli facete.\n";
	cin >> input;
	return input;
}

bool reverse_check(string input)
{
	string val = "Lorem ipsum dolor sit amet, eam et cibo electram, eu decore mediocritatem pri, vix ei malorum alienum dissentiunt. Id cum consectetuer signiferumque. His probo quando an, no est suas saepe. Abhorreant mnesarchum cotidieque vel ut, tempor salutatus mel ut, nominavi eloquentiam sit id. Id liber persecuti adipiscing nec. Te eos falli facete.";
	string reversed(val.rbegin(), val.rend());
	std::cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	if (input == reversed) {
		cout << "I'm actually kind of impressed\n";
		std::cin.get();
		return true;
	}
	else {
		cout << "You are a failure\n";
		std::cin.get();
		return false;
	}
}

void ShowMenu()
{
	cout << "Choose a challenge\n";
	cout << "1 - Moby Dick\n";
	cout << "2 - Comp Sci Joke\n";
	cout << "3 - Reverse\n";
	cout << "4 - WPM\n";
	cout << "5 - Quit\n\n";
}

int main(int argc, const char *argv[])
{
	bool Quit = false;
	char option;
	string ans;
	bool val;

	while (!Quit) {

		ShowMenu();
		std::cin >> option;

		switch (option) {
		case '1':
			ans = moby_dick();
			moby_dick_check(ans);
			break;

		case '2':
			ans = joke();
			joke_check(ans);
			break;

		case '3':
			ans = reverse();
			reverse_check(ans);
			break;

		case '4':
			std::cin.clear();
			std::clock_t start;
			double duration;
			start = std::clock();
			ans = wpm();
			duration = (std::clock() - start) / (double)CLOCKS_PER_SEC;
			wpm_check(ans, duration);
			break;

		case '5':
			Quit = true;
			break;

		default:
			std::cout << "Hey, that's not one of the options!" << std::endl;
			break;
		}

	}

    return 0;
}
