#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>
#include <time.h>

void categories();
void selectCategory(int choice);
void startGame(char words[][15], char category[]);
void drawHangman(int attempts);

int main()
{
	system("mode con cols=80 lines=25");
	categories();
	system("pause");
	return 0;
}

void categories()
{
	int choice;
	do
	{
		system("cls");
		printf("\n\t\t\t\tHANGMAN GAME\n\n");
		printf(" CATEGORIES\n\n");
		printf(" 1. Fruits\n");
		printf(" 2. Animals\n");
		printf(" 3. Countries\n");
		printf(" 4. Objects\n\n");
		printf(" Enter a choice: ");
		scanf("%i", &choice);
	} while (choice < 1 || choice > 4);

	selectCategory(choice);
}

void selectCategory(int choice)
{
	char categoryNames[4][15] = {"fruits", "animals", "countries", "objects"};
	char fruits[10][15] = {"melon", "papaya", "watermelon", "apple", "pear", "orange", "grape", "cherry", "plum", "kiwi"};
	char animals[10][15] = {"dog", "cat", "horse", "chicken", "giraffe", "monkey", "cow", "rabbit", "turtle", "wolf"};
	char countries[10][15] = {"peru", "colombia", "argentina", "nicaragua", "italy", "mexico", "canada", "venezuela", "ecuador", "brazil"};
	char objects[10][15] = {"backpack", "watch", "shoe", "furniture", "notebook", "chair", "table", "phone", "door", "headphones"};

	switch (choice)
	{
	case 1:
		startGame(fruits, categoryNames[choice - 1]);
		break;
	case 2:
		startGame(animals, categoryNames[choice - 1]);
		break;
	case 3:
		startGame(countries, categoryNames[choice - 1]);
		break;
	case 4:
		startGame(objects, categoryNames[choice - 1]);
		break;
	}
}

void startGame(char words[][15], char category[])
{
	int option, i, j, wordLength, remainingSpaces, points = 1200;
	char letter;
	int correctGuesses = 0;
	int attempts = 0;
	srand(time(NULL));

	option = rand() % 10;
	wordLength = strlen(words[option]);
	char guessedWord[wordLength];

	for (i = 0; i < wordLength; i++)
	{
		guessedWord[i] = '_';
	}

	do
	{
		correctGuesses = 0;
		system("cls");
		printf("\n\t\t\t\tHANGMAN GAME\n\n");
		printf(" CATEGORY: %s\n\n", category);
		printf(" Remaining Attempts: %i\t\t\t\tScore: %i\n\n", 6 - attempts, points);
		drawHangman(attempts);

		printf("\n\n\n");
		for (i = 0; i < wordLength; i++)
		{
			printf(" %c ", guessedWord[i]);
		}

		if (attempts == 6)
		{
			printf("\n\n YOU LOST!!\n");
			printf(" THE SOLUTION WAS: %s\n\n", words[option]);
			printf(" Press any key to play again..");
			getch();
			categories();
		}

		remainingSpaces = 0;

		for (i = 0; i < wordLength; i++)
		{
			if (guessedWord[i] == '_')
				remainingSpaces++;
		}

		if (remainingSpaces == 0)
		{
			printf("\n\n CONGRATULATIONS.. YOU WON!!\n\n");
			printf(" Press any key to play again..");
			getch();
			categories();
		}

		printf("\n\n Enter a letter: ");
		scanf(" %c", &letter);

		for (j = 0; j < wordLength; j++)
		{
			if (letter == words[option][j])
			{
				guessedWord[j] = letter;
				correctGuesses++;
			}
		}

		if (correctGuesses == 0)
		{
			attempts++;
			points -= 200;
		}
	} while (attempts != 7);

	printf("\n\n");
}

void drawHangman(int attempts)
{
	switch (attempts)
	{
	case 0:
		printf("\n     _______\n    |       |\n    |\n    |\n    |\n    |\n    |\n ----------");
		break;
	case 1:
		printf("\n     _______\n    |       |\n    |       0\n    |\n    |\n    |\n    |\n ----------");
		break;
	case 2:
		printf("\n     _______\n    |       |\n    |       0\n    |       |\n    |\n    |\n    |\n ----------");
		break;
	case 3:
		printf("\n     _______\n    |       |\n    |       0\n    |      /|\n    |\n    |\n    |\n ----------");
		break;
	case 4:
		printf("\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |\n    |\n    |\n ----------");
		break;
	case 5:
		printf("\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      /\n    |\n    |\n ----------");
		break;
	case 6:
		printf("\n     _______\n    |       |\n    |       0\n    |      /|\\\n    |      / \\\n    |\n    |\n ----------");
		break;
	}
}
