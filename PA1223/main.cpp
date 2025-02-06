#include <iostream>
#include <string>
#include <forward_list>
#include <iterator>
#include "node.hpp"
#include <ctime>
#include "List.hpp"
#include "Data.hpp"
#include "CSVLoader.hpp"


using namespace std;

void displayMainMenu()
{
	cout << "Main Menu:" << endl;
	cout << "1. Play Game!" << endl;
	cout << "2. Add Command" << endl;
	cout << "3. Remove Command" << endl;
	cout << "4. Display All Commands" << endl;
	cout << "5. Exit" << endl;
	cout << "Please Enter Your Choice: \n";
}

void playGame(List<Data>& commandList)
{
	
	
	loadFromCSV(commandList, "Commands.csv");
	
	
	cout << "Playing the game" << endl;
	int numQuestions;
	std::cout << "Enter number of quesitons: ";
	std::cin >> numQuestions;

	std::srand(std::time(0));

	int score = 0;

	for (int i = 0; i < numQuestions; i++)
	{
		int randomIndex = std::rand() % 10;
		Node<Data>* currentNode = commandList.begin();
		for (int j = 0; j < randomIndex && currentNode != nullptr; j++)
		{
			currentNode = currentNode->next;
		}
		if (currentNode == nullptr) {
			std::cout << "Error: couldn't get command" << std::endl;
			continue;
		}
		std::cout << "What does the command \"" << currentNode->data.key << "\" do?" << std::endl;
		std::cout << "select the correct description" << std::endl;

		Node<Data>* tempNode = commandList.begin();
		std::string correctDescription = currentNode->data.value;
		std::string options[3];

		options[0] = correctDescription;

		int optionIndex = 1;
		while (optionIndex < 3)
		{
			randomIndex = std::rand() % 10;
			tempNode = commandList.begin();
			for (int j = 0; j < randomIndex && tempNode != nullptr; ++j)
			{
				tempNode = tempNode->next;

			}
			if (tempNode != nullptr && tempNode->data.value != correctDescription)
			{
				options[optionIndex] = tempNode->data.value;
				++optionIndex;
			}
		}
		for (int i = 0; i < 3; ++i)
		{
			int swapIndex = std::rand() % 3;
			std::swap(options[i], options[swapIndex]);
		}
		for (int i = 0; i < 3; ++i)
		{
			std::cout << i + 1 << ". " << options[i] << std::endl;
		}
		int answer;
		std::cout << "Your answer (1-3): ";
		std::cin >> answer;

		if (options[answer - 1] == correctDescription)
		{
			std::cout << "Correct!" << std::endl;
			score += currentNode->data.key.length();

		}
		else {
			std::cout << "Incorrect! The correct answer was: " << correctDescription << std::endl;
		}
	}

	std::cout << "Game Over! Your score: " << score << std::endl;
}

void addCommand(List<Data>& commandList)
{
	string key, value;
	cout << "Enter command key: ";
	cin >> key;
	cout << "Enter command description: ";
	cin.ignore(); // will ignore newline left by previous
	getline(cin, value);
	commandList.insertAtFront(Data(key, value));
	cout << "Command added" << endl;
}

void removeCommand(List<Data>& commandList)
{
	string key;
	cout << "Enter command key to remove: ";
	cin >> key;
	if (commandList.removeNode(key))
	{
		cout << "Command removed" << endl;
	}
	else {
		cout << "Command not found" << endl;
	}
}

void displayAllCommands(const List<Data>& commandList)
{
	commandList.display();
}

int main()
{
	List<Data> commandList;


	string userInput;
	bool running = true;

	while (running)
	{
		displayMainMenu();
		cin >> userInput;

		switch (stoi(userInput))
		{
			case 1: //Play
				playGame(commandList);
				break;
			case 2: //Add Command
				addCommand(commandList);
				break;
			case 3: //Remove Command
				removeCommand(commandList);
				break;
			case 4: //Display all commands
				displayAllCommands(commandList);
				break;
			case 5: //Exit
				cout << "Exiting program..." << endl;
				running = false;
				break;
			default:
				cout << "Invalid choice, please re-try" << endl;
		}
	}
	return 0;
}