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

int main(int argc, const char *argv[])
{
    // insert code here...
    ifstream file("moby.txt");
    if (file)
    {
        file.seekg(0, std::ios::end);
        std::streampos length = file.tellg();
        file.seekg(0, std::ios::beg);
        std::vector<char> buffer(length);
        file.read(&buffer[0], length);

        std::string str(buffer.begin(), buffer.end());

        std::vector<std::string> result = explode(str, ' ');

        cout << add_numbers(2.0, 4.0) << endl;

        int count = 0;
        while (count < result.size())
        {
            cout << result[count] << endl;
            string answer;
            getline(cin, answer);

            if (result[count] != answer)
                continue;

            count++;
        }
    }
    else
    {
        cout << "Fail" << endl;
    }

    //    stringstream ss(str);
    //    istream_iterator<std::string> begin(ss);
    //    istream_iterator<std::string> end;
    //    vector<std::string> vstrings(begin, end);
    //    std::copy(vstrings.begin(), vstrings.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
    //
    //    cout << str << endl;

    return 0;
}
