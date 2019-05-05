#include "pch.h"
#include "../Typer/example.h"
#include "../Typer/example.cpp"
#include "../Typer/main.cpp"

TEST(TestCaseName, TestName)
{
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);
}


TEST(example, add)
{
	double res;
	res = add_numbers(1.0, 2.0);
	ASSERT_NEAR(res, 3.0, 1.0e-11);
}

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
		EXPECT_TRUE(ans);

	}
	else
	{
		cout << "Fail" << endl;
	}
}