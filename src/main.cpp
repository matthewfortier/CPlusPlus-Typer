//
//  main.cpp
//  MobyDickTyper
//
//  Created by Matthew Fortier on 4/12/18.
//  Copyright © 2018 Matthew Fortier. All rights reserved.
//

#include <cstdlib>
#include <stdio.h>
#include "example.h"
using namespace std;

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

        int count = 0;
        int errors = 0;

        int start = clock();
        double diff;
        do
        {
            // do stuff
            diff = (clock() - start) / (double)(CLOCKS_PER_SEC);
            cout << diff << endl;

            cout << endl;
            cout << endl;
            cout << result[count] << endl;
            string answer;
            cin >> answer;

            if (result[count] != answer)
            {
                errors++;
                continue;
            }

            count++;

            system("cls");
            system("clear");

            cout << "Errors: " << errors << endl;

            for (int i = 0; i < count; i++)
            {
                cout << result[i] << " ";
            }
            cout << endl;

        } while (diff < 0.005000);
    }
    else
    {
        cout << "Fail" << endl;
    }

    return 0;
}
