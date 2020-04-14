#include <iostream>
#include <string>
#include <regex>

//https://ru.wikipedia.org/wiki/����������_���������

//std::regex - ������ ������� ����������� ���������
//std::cmatch - �������������� ���������
//std::regex_match(string.c_str(), cmatch_result, regex_regular); //��������� ��� ������ �� ������������ �������
//std::regex_search(string.c_str(), cmatch_result, regex_regular); //���� ����� ������, ������� ������������� �������
//std::regex for_regex_search("email");//����� ������ �������� ����� � ������ ���.
//std::regex_replace(str.c_str(), regular, "any_replace_string"); //�������� ���������� ���������, ��������� �������

/*
std::regex regular(
					"(:)"
					"([.]*[^\.]+"
					"[^\.]"
					)


					"(:)" ���� ��������� ���������
					"([.]*" ����� �������, ����� ���������� || [.]-���.������� "*" - ������������� ����������
					[^\.]+" - ��������� ��� ����� �����, ������������ ������� ����� "."
					"+" - �������������� ���������� �������� �������
					"(\.)" - ����� ������ �����.
*/

void firstTestRegex()
{
	std::string str = "koska@gmail.com";
	std::cmatch result;
	std::regex regular(
		"([\\w-]+)" //all words
		"(@)" //symbol '@'
		"([\\w-]+)" //all words
		"(\.)" // dot
		"([a-z]{2,6})" //all symbols, size [2,5];
	);

	if (std::regex_match(str.c_str(), result, regular))
		for (size_t i = 0; i < result.size(); ++i)
		{
			std::cout << result[i] << std::endl;
		}

}

void secondTextRegex()
{
	std::string str = "Hello bitches lol@Gmail.com";
	std::cmatch result;
	std::regex regular(
		"([\\w-]+)"
		"(@)"
		"([\\w=]+)"
		"(\.)"
		"([a-z]{2,6})"
	);

	if (std::regex_search(str.c_str(), result, regular))
	{
		for (size_t i = 0; i < result.size(); ++i)
			std::cout << result[i] << std::endl;
	}


}

void thirdTextRegex()
{
	std::string str = "Hello bitches lol@Gmail.com";
	std::cmatch result;
	std::regex regular(
		"([\\w-]+)"
		"(@)"
		"([\\w=]+)"
		"(\.)"
		"([a-z]{2,6})"
	);

	std::cout << std::regex_replace(str.c_str(), regular, "any llol");
}

int main(int argc, char** argv)
{
	
	system("pause >> NULL");
	return 0;
}