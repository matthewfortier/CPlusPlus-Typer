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

    return "";
}

string wpm()
{
    string input;
    cin >> input;

    return input;
}

string joke()
{
    string input;
    cout << "Complete this classic computer science joke: \nIt's not a bug, it's a ____!\n";
    cin >> input;
    return input;
}

string reverse()
{
    string input;
    cout << "Re-write this lorem ipsum nonsense in reverse\n";
    cout << "Lorem ipsum dolor sit amet, eam et cibo electram, eu decore mediocritatem pri, vix ei malorum alienum dissentiunt. Id cum consectetuer signiferumque. His probo quando an, no est suas saepe. Abhorreant mnesarchum cotidieque vel ut, tempor salutatus mel ut, nominavi eloquentiam sit id. Id liber persecuti adipiscing nec. Te eos falli facete.\n";
    cin >> input;
    return input;
}

int main(int argc, const char *argv[])
{
    bool Quit = false;
    char option;
    string ans;
    bool val;

    while (!Quit)
    {

        ShowMenu();
        std::cin >> option;

        switch (option)
        {
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
