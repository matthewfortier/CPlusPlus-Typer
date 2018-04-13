#include "gtest/gtest.h"
#include "example.h"

TEST(main, moby)
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

        cout << str;

        bool ans = moby_dick_check(str);
        EXPECT_FALSE(ans);
    }
    else
    {
        cout << "Fail" << endl;
    }
}

TEST(main, wpm_under)
{
    bool ans;
    ans = wpm_check("a", 1.01);
    EXPECT_FALSE(ans);
}

TEST(main, joke_true)
{
    bool ans;
    ans = joke_check("bug");
    EXPECT_TRUE(ans);
}

TEST(main, joke_false)
{
    bool ans;
    ans = joke_check("not bug");
    EXPECT_FALSE(ans);
}

TEST(main, wpm)
{
    bool ans;
    ans = wpm_check("a a", 1.01);
    EXPECT_TRUE(ans);
}

TEST(main, reverse)
{
    EXPECT_TRUE(reverse_check(".etecaf illaf soe eT .cen gnicsipida itucesrep rebil dI .di tis maitneuqole ivanimon ,tu lem sutatulas ropmet ,tu lev euqeiditoc muhcrasenm tnaerrohbA .epeas saus tse on ,na odnauq oborp siH .euqmurefingis reutetcesnoc muc dI .tnuitnessid muneila murolam ie xiv ,irp metatircoidem eroced ue ,martcele obic te mae ,tema tis rolod muspi meroL"));
}