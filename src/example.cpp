#include "example.h"

double add_numbers(const double f1, const double f2)
{
    return f1 + f2;
}

double subtract_numbers(const double f1, const double f2)
{
    return f1 - f2;
}

double multiply_numbers(const double f1, const double f2)
{
    return f1 * f2;
}

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

void reverseStr(string &str)
{
    int n = str.length();

    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
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

        if (str == input)
        {
            cout << "That's right!\n";
            std::cin.get();
            return true;
        }
        else
        {
            cout << "That's not right!\n";
            std::cin.get();
            return false;
        }
    }
    else
    {
        cout << "Fail" << endl;
    }

    return false;
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
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (wpm > 1)
    {
        std::cout << "W O W\n";
        //std::cin.get();
        return true;
    }
    else
    {
        std::cout << "that's not fast at all\n";
        //std::cin.get();
        return false;
    }
}

bool joke_check(string input)
{
    std::cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (input == "bug")
    {
        cout << "\nHaha classic  C O M P U T E R   S C I E N C E!\n";
        //std::cin.get();
        return true;
    }
    else
    {
        cout << "\nS Y N T " << char(123) << " " << char(126) << " A X E " << char(62) << " " << char(168) << " R R O R - O R - O" << char(245) << char(234);
        //std::cin.get();
        return false;
    }
}

bool reverse_check(string input)
{
    string val = "Lorem ipsum dolor sit amet, eam et cibo electram, eu decore mediocritatem pri, vix ei malorum alienum dissentiunt. Id cum consectetuer signiferumque. His probo quando an, no est suas saepe. Abhorreant mnesarchum cotidieque vel ut, tempor salutatus mel ut, nominavi eloquentiam sit id. Id liber persecuti adipiscing nec. Te eos falli facete.";
    string reversed(val.rbegin(), val.rend());
    std::cin.clear();
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (input == reversed)
    {
        cout << "I'm actually kind of impressed\n";
        //std::cin.get();
        return true;
    }
    else
    {
        cout << "You are a failure\n";
        //std::cin.get();
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
