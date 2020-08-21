#include "Header.h"

/*
	Name: Koji Natsuhara

	Date: 11/16/2019

	Description: The purpose of the PA7 is to write a program that allows a user to play 5-Card-Draw Poker
	against the computer. Using the starting code supplied by Deitel and Deitel.

	IN THIS PROGRAM I WILL HAVE TO:
	1. Open and close files
	2. Read, write to, and update files
	3. Apply standard library functions: fopen (), fclose (), fscanf (), and fprintf ()
	4. Compose decision statements ("if" conditional statements)
	5. Create and utilize compound conditions
	6. Be able to include while(), do-while(), and for() loops
	7. Define and apply structs in C
	8. Define and apply strings in C
	9. Compose decision statements ("if" conditional statements)
*/

int main(void)
{
	int option = 0;
	/* initialize suit array */
	const char* suit[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };

	/* initialize face array */
	const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };

	/* initalize deck array */
	int deck[4][13] = { 0 };

	/* intialize each players hands*/
	Hand player1 = { 0 };
	Hand player2 = { 0 };

	srand((unsigned)time(NULL)); /* seed random-number generator */

	while (option != 3)
	{
		option = get_option();
		switch (option)
		{
		case 1:
			print_game_rules();
			break;
		case 2:
			intialize_deck(deck);
			shuffle(deck);
			deal(player1, player2, deck, face, suit);
			system("pause");
			system("cls");
			break;
		case 3:
			break;
		}
	}

	return 0;
}