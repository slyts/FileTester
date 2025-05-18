#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

void fileParser(vector<string>& lines, string file_name, bool& check)
{
	string line;
	ifstream file(file_name);
	if (!file.is_open())
	{
		cout << "Не удалось открыть файл: " << file_name << endl;
		check = false;
	}

	while (getline(file, line))
	{
		lines.push_back(line);
		check = true;
	}
	file.close();
}

int main()
{
	setlocale(LC_ALL, "Russian.UTF-8");

	int counter = 0;
	int user_answer = 0;
	int balls = 0;

	vector<string> test_lines;
	vector<string> answer_lines;

	vector<int> answer_cin;
	vector<int> answer_number;

	bool testExist = false;
	bool answerExist = false;

	fileParser(test_lines, "Test.txt", testExist);
	fileParser(answer_lines, "Answer.txt", answerExist);

	if (testExist == true && answerExist == true)
	{
		cout << "Добро пожаловать в тестирование" << endl;

		for (string line : test_lines)
		{
			counter++;
			cout << counter << "." << line << ": ";
			cin >> user_answer;
			answer_cin.push_back(user_answer);
		}

		for (const auto& str : answer_lines)
		{
			int num = stoi(str);
			answer_number.push_back(num);
		}

		if (answer_cin.size() != answer_number.size())
		{
			cout << "Размеры векторов не совпадают." << endl;
			return 1;
		}

		for (size_t i = 0; i < answer_number.size(); i++)
		{
			if (answer_cin[i] == answer_number[i])
			{
				balls++;
			}
		}
		cout << "Вы набрали " << balls << " баллов" << endl;
	}
	system("pause");
}