
// [porting] from parse.js to parse.cpp

#include <iostream>
#include <string>
#include <vector>

typedef struct
{
	char mode;
	std::string token;
} mode_token;

std::vector<mode_token> parse(std::string program)
{
	char mode = ' ';
	std::string token = "";
	std::vector<mode_token> list = {};
	bool escaping = false;
	for (unsigned i = 0; i < program.length(); i++)
	{
		char character = program[i];
		char next_character = '\0';

		if ((i + 1) < program.length())
			next_character = program[i + 1];

		if (mode == ' ')
			if (character == '@' || character == '"')
			{
				mode = character;
				continue;
			}

		if (!escaping && character == '\\' && next_character == '"')
		{
			escaping = true;
			continue;
		}

		bool stop = mode == '"' && character == '"' && !escaping;
		stop = stop || (mode == '@' && character == ' ');
		if (stop)
		{
			list.push_back({mode, token});
			mode = ' ';
			token = "";
		}

		if (mode != ' ')
			token += character;
		escaping = false;
	}

	return list;
}

void cout_token_list(std::vector<mode_token> list)
{
	for (const auto &entry : list)
	{
		std::cout << "mode: " << entry.mode << ", token: " << entry.token << std::endl;
	}
}

int main()
{
	std::string program = R"( @write-line "hello dear friends ! escaped quote: \" ... "
	@write-line "testing multiple lines"
	@write-line "testing multi-line string :
1- line 1
2- line 2
3- line 3"
	)";
	std::vector<mode_token> list = parse(program);
	cout_token_list(list);
	std::cout << "------------------------" << std::endl;
	std::cout << list[1].token << std::endl;
	std::cout << list[5].token << std::endl;
}
