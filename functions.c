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


/*
Function: get_option
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: prompts the user for an integer
Input Parameters: void
Returns: an integer between 1 and 3 inputted by the user
Preconditions: an intitalized integer variable set equal to the function
Postconditions: a integer variable with a integer submitted by the user
*/
int get_option(void)
{
	int option = 0;
	
	do
	{
		print_game_menu();
		printf("Select an option: ");
		scanf("%d", &option);
	} while (option < 1 || option > 3);
	system("cls");

	return option;
}

/*
Function: print_game_menu
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Prints out the game title and game menu
Input Parameters: void
Returns: void
Preconditions: none
Postconditions: none
*/
void print_game_menu(void)
{
	printf("==========Welcome to Five Card Draw!==========\n");
	printf("1. Print Game Rules\n");
	printf("2. Play the Game\n");
	printf("3. Exit Game\n");
	printf("==============================================\n");
}

/*
Function: print_game_rules
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Prints out the game rules
Input Parameters: void
Returns: void
Preconditions: void
Postconditions: void
*/
void print_game_rules(void)
{
	
	printf("=========== Five Card Draw Rules ==========\n");
	printf("1. Each player is dealt 5 cards.\n");
	printf("2. Each player can then decide which cards to keep and discard\n");
	printf("3. If a player chooses to discard some cards then they will be dealt new cards equal to number they discarded.\n");
	printf("4. Once each player decides whether or not to discard or not the players will show their hands.\n");
	printf("5. Whoever has the highest hand wins!\n");
	printf("==============================================\n");
}

/*
Function: switch_card_option
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Prompts the user for a character
Input Parameters: void
Returns: a character inputted by the user
Preconditions: an intitalized character variable set equal to the function
Postconditions: a character variable with a character submitted by the user
*/
char switch_card_option(void)
{
	char c = '\0';
	printf("Would you like to change this card (Y\N)?: ");
	scanf(" %c", &c);
	return c;
}

/* This code was supplied by Deitel and Deitel and the purpose of this
function is to shuffle cards in deck */

void shuffle(int wDeck[][13])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */

	/* for each of the 52 cards, choose slot of deck randomly */
	for (card = 1; card <= 52; card++)
	{
		/* choose new random location until unoccupied slot found */
		do
		{
			row = rand() % 4;
			column = rand() % 13;
		} while (wDeck[row][column] != 0);

		/* place card number in chosen slot of deck */
		wDeck[row][column] = card;
	}
}

/* deal cards in deck */
void deal(Hand player1, Hand player2, const int wDeck[][13], const char* wFace[], const char* wSuit[])
{
	int row = 0;    /* row number */
	int column = 0; /*column number */
	int card = 0;   /* card counter */
	int count1 = 0, count2 = 0, total_cards = 0;
	int new_count1 = 0, new_count2 = 0;
	char player1_char = '\0', player2_char = '\0';
	int p1_card1 = 0, p1_card2 = 0, p1_card3 = 0, p1_card4 = 0, p1_card5 = 0;
	int p2_card1 = 0, p2_card2 = 0, p2_card3 = 0, p2_card4 = 0, p2_card5 = 0;
	int p1_pair = 0, p1_2pair = 0, p1_trips = 0, p1_quads = 0, p1_straight = 0, p1_flush = 0;
	int p2_pair = 0, p2_2pair = 0, p2_trips = 0, p2_quads = 0, p2_straight = 0, p2_flush = 0;
	int p2_check = 0;
	int p1_win = 0, p2_win = 0, p1_break = 0, p2_break = 0, p1_discard = 0;

	/* deal each of the 52 cards */
	for (card = 1; card <= 20; card++)
	{
		/* loop through rows of wDeck */
		for (row = 0; row <= 3; row++)
		{
			/* loop through columns of wDeck for current row */
			for (column = 0; column <= 12; column++)
			{
				/* if slot contains current card, display card */
				if (wDeck[row][column] == card)
				{
					// The cards are dealt to each players hands
					if (p1_break == 0)
					{
						printf("=========Player 1 Hand=========\n");
						p1_break = 1;
					}
					if (count1 < 5)
					{
						printf("Player 1 Card %d: ", count1 + 1);
						player1.arr[count1].rank = column;
						player1.arr[count1].suit = row;

						//printf("Player 1 Card %d: [%d][%d] \n", count1 + 1, player1.arr[count1].suit, player1.arr[count1].rank);
						
						printf("%s of %s\n", wFace[column], wSuit[row]);
						count1++;
						total_cards++;
					}
					else if (count1 == 5 && count2 < 5)
					{
						if (p2_break == 0)
						{
							printf("=========Player 2 Hand=========\n");
							p2_break = 1;
						}
						printf("Player 2 Card %d: ", count2 + 1);
						player2.arr[count2].rank = column;
						player2.arr[count2].suit = row;
						printf("%s of %s\n", wFace[column], wSuit[row]);
						count2++;
						total_cards++;
					}

					if (total_cards >= 10 && new_count1 < 5)
					{
						if (p1_discard == 0)
						{
							printf("----------------Player 1 Discard Phase----------------\n");
							p1_discard = 1;
						}
						printf("Player 1 Card %d: ", new_count1 + 1);
						player1_char = switch_card_option();
						if (player1_char == 'Y')
						{
							player1.arr[new_count1].rank = column;
							player1.arr[new_count1].suit = row;
							//printf("%s of %s\n", wFace[column], wSuit[row]);
						}
						new_count1++;
					}


					if (total_cards >= 10 && new_count1 == 5 && new_count2 < 5)
					{
						if (p2_check == 0)
						{
							p2_pair = check_pair(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
							p2_2pair = check_two_pair(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
							p2_trips = check_three_kind(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
							p2_quads = check_four_kind(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
							p2_straight = check_stright(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
							p2_flush = check_flush(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
							p2_check = 1;
						}
						if (new_count2 == 0)
						{
							if (p2_card1 == 0)
							{
								player2.arr[new_count2].rank = column;
								player2.arr[new_count2].suit = row;
								//printf("%s of %s\n", wFace[column], wSuit[row]);
							}
						}
						else if (new_count2 == 1)
						{
							if (p2_card2 == 0)
							{
								player2.arr[new_count2].rank = column;
								player2.arr[new_count2].suit = row;
								//printf("%s of %s\n", wFace[column], wSuit[row]);
							}
						}
						else if (new_count2 == 2)
						{
							if (p2_card3 == 0)
							{
								player2.arr[new_count2].rank = column;
								player2.arr[new_count2].suit = row;
								//printf("%s of %s\n", wFace[column], wSuit[row]);
							}
						}
						else if (new_count2 == 3)
						{
							if (p2_card4 == 0)
							{
								player2.arr[new_count2].rank = column;
								player2.arr[new_count2].suit = row;
								//printf("%s of %s\n", wFace[column], wSuit[row]);
							}
						}
						else if (new_count2 == 4)
						{
							if (p2_card5 == 0)
							{
								player2.arr[new_count2].rank = column;
								player2.arr[new_count2].suit = row;
								//printf("%s of %s\n", wFace[column], wSuit[row]);
							}
						}
						new_count2++;
					}
					// cards are identified by wFace[column] for number, wSuit[row] for suit
					// you will give these to the hands
					// this loop's first iteration is the first card drawn, the second the second card and so on
					//printf("%5s of %-8s%c", wFace[column], wSuit[row], card % 5 == 0 ? '\n' : '\t'); //condition ? true : false
					//%5s buffer of 5 characters with right alignment & %-8s buffer of 8 characters with left alignment
				}
			}
		}
	}
	//AFTER DRAW AND DISCARD PHASE
	printf("----------------Player 1 Hand----------------\n");
	print_hand(player1, 1);
	p1_pair = check_pair(player1, &p1_card1, &p1_card2, &p1_card3, &p1_card4, &p1_card5);
	p1_2pair = check_two_pair(player1, &p1_card1, &p1_card2, &p1_card3, &p1_card4, &p1_card5);
	p1_trips = check_three_kind(player1, &p1_card1, &p1_card2, &p1_card3, &p1_card4, &p1_card5);
	p1_quads = check_four_kind(player1, &p1_card1, &p1_card2, &p1_card3, &p1_card4, &p1_card5);
	p1_straight = check_stright(player1, &p1_card1, &p1_card2, &p1_card3, &p1_card4, &p1_card5);
	p1_flush = check_flush(player1, &p1_card1, &p1_card2, &p1_card3, &p1_card4, &p1_card5);
	printf("----------------Player 2 Hand----------------\n");
	print_hand(player2, 2);
	p2_pair = check_pair(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
	p2_2pair = check_two_pair(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
	p2_trips = check_three_kind(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
	p2_quads = check_four_kind(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
	p2_straight = check_stright(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);
	p2_flush = check_flush(player2, &p2_card1, &p2_card2, &p2_card3, &p2_card4, &p2_card5);

	//pair check
	if (p2_pair > p1_pair)
	{
		p1_win = 0;
		p2_win = 1;
	}
	if (p1_pair > p2_pair)
	{
		p1_win = 1;
		p2_win = 0;
	}
	//2pair check
	if (p2_2pair > p1_2pair)
	{
		p1_win = 0;
		p2_win = 1;
	}
	if (p1_2pair > p2_2pair)
	{
		p1_win = 1;
		p2_win = 0;
	}
	//trips check
	if (p2_trips > p1_trips)
	{
		p1_win = 0;
		p2_win = 1;
	}
	if (p1_trips > p2_trips)
	{
		p1_win = 1;
		p2_win = 0;
	}
	//straight check
	if (p2_straight > p1_straight)
	{
		p1_win = 0;
		p2_win = 1;
	}
	if (p1_straight > p2_straight)
	{
		p1_win = 1;
		p2_win = 0;
	}
	//flush check
	if (p2_flush > p1_flush)
	{
		p1_win = 0;
		p2_win = 1;
	}
	if (p1_flush > p2_flush)
	{
		p1_win = 1;
		p2_win = 0;
	}
	//quad check
	if (p2_quads > p1_quads)
	{
		p1_win = 0;
		p2_win = 1;
	}
	if (p1_quads > p2_quads)
	{
		p1_win = 1;
		p2_win = 0;
	}
	if (p2_win > p1_win)
	{
		printf("Player 2 wins!\n");
	}
	else if (p1_win > p2_win)
	{
		printf("Player 1 wins!\n");
	}
	else
	{
		printf("The game is tied!\n");
	}
}

/*
Function: print_hand
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Prints out the hand of each player
Input Parameters: Hand player, int num
Returns: void
Preconditions: none
Postconditions: none
*/
void print_hand(Hand player, int num)
{
	const char* face[13] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight",
		"Nine", "Ten", "Jack", "Queen", "King" };
	const char* suits[4] = { "Hearts", "Diamonds", "Clubs", "Spades" };
	int suit = 0, rank = 0;
	for (int i = 0; i < 5; i++)
	{
		suit = player.arr[i].suit;
		rank = player.arr[i].rank;
		printf("Player %d Card %d: %s of %s\n", num, i + 1, face[rank], suits[suit]);
	}
}

/*
Function: check_pair
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have two matching cards of the same rank
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
int check_pair(Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5)
{
	int collect[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int index = 0, pair = 0;
	for (int i = 0; i < 5; i++)
	{
		index = player.arr[i].rank;
		collect[index]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (collect[i] == 2)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == player.arr[j].rank)
				{
					if (j == 0)
					{
						*ptr_card1 = 1;
					}
					else if (j == 1)
					{
						*ptr_card2 = 1;
					}
					else if (j == 2)
					{
						*ptr_card3 = 1;
					}
					else if (j == 3)
					{
						*ptr_card4 = 1;
					}
					else
					{
						*ptr_card5 = 1;
					}
				}
			}
			pair = 1;
			return pair;
		}
	}
	return pair;
}

/*
Function: check_two_pair
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have two pairs of matching cards of the same rank
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
int check_two_pair(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5)
{
	int collect[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, pair = 0;
	for (int i = 0; i < 5; i++)
	{
		index = player.arr[i].rank;
		collect[index]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (collect[i] == 2)
		{
			pair++;
			for (int j = 0; j < 5; j++)
			{
				if (i == player.arr[j].rank)
				{
					if (j == 0)
					{
						*ptr_card1 = 1;
					}
					else if (j == 1)
					{
						*ptr_card2 = 1;
					}
					else if (j == 2)
					{
						*ptr_card3 = 1;
					}
					else if (j == 3)
					{
						*ptr_card4 = 1;
					}
					else
					{
						*ptr_card5 = 1;
					}
				}
			}
		}
	}
	if (pair == 2)
	{
		pair = 1;
	}
	else
	{
		pair = 0;
	}
	return pair;
}

/*
Function: check_three_kind
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have three matching cards of the same rank
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
int check_three_kind(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5)
{
	int collect[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, trips = 0;
	for (int i = 0; i < 5; i++)
	{
		index = player.arr[i].rank;
		collect[index]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (collect[i] == 3)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == player.arr[j].rank)
				{
					if (j == 0)
					{
						*ptr_card1 = 1;
					}
					else if (j == 1)
					{
						*ptr_card2 = 1;
					}
					else if (j == 2)
					{
						*ptr_card3 = 1;
					}
					else if (j == 3)
					{
						*ptr_card4 = 1;
					}
					else
					{
						*ptr_card5 = 1;
					}
				}
			}
			trips = 1;
		}
	}
	return trips;
}

/*
Function: check_four_kind
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have four matching cards of the same rank
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
int check_four_kind(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5)
{
	int collect[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, quads = 0;
	for (int i = 0; i < 5; i++)
	{
		index = player.arr[i].rank;
		collect[index]++;
	}
	for (int i = 0; i < 13; i++)
	{
		if (collect[i] == 4)
		{
			for (int j = 0; j < 5; j++)
			{
				if (i == player.arr[j].rank)
				{
					if (j == 0)
					{
						*ptr_card1 = 1;
					}
					else if (j == 1)
					{
						*ptr_card2 = 1;
					}
					else if (j == 2)
					{
						*ptr_card3 = 1;
					}
					else if (j == 3)
					{
						*ptr_card4 = 1;
					}
					else
					{
						*ptr_card5 = 1;
					}
				}
			}
			quads = 1;
		}
	}
	return quads;
}

/*
Function: check_flush
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have 5 cards of the same suit
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
int check_flush(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5)
{
	int collect[4] = { 0, 0, 0, 0};
	int index = 0, flush = 0;
	for (int i = 0; i < 5; i++)
	{
		index = player.arr[i].suit;
		collect[index]++;
	}
	for (int i = 0; i < 4; i++)
	{
		if (collect[i] == 5)
		{
			flush = 1;
			*ptr_card1 = 1;
			*ptr_card2 = 1;
			*ptr_card3 = 1;
			*ptr_card4 = 1;
			*ptr_card5 = 1;
		}
	}
	return flush;
}

/*
Function: check_straight
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have 5 cards in consecutive order with their rank
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
int check_stright(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5)
{
	int collect[13] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int index = 0, straight = 0;
	for (int i = 0; i < 5; i++)
	{
		index = player.arr[i].rank;
		collect[index]++;
	}
	for (int i = 0; i < 9; i++)
	{
		if (collect[i] == 1 && collect[i + 1] == 1 && collect[i + 2] == 1 && collect[i + 3] == 1 && collect[i + 4] == 1)
		{
			straight = 1;
			*ptr_card1 = 1;
			*ptr_card2 = 1;
			*ptr_card3 = 1;
			*ptr_card4 = 1;
			*ptr_card5 = 1;
		}
	}
	if (collect[0] == 1 && collect[12] == 1 && collect[11] == 1 && collect[10] == 1 && collect[9] == 1)
	{
		straight = 1;
		*ptr_card1 = 1;
		*ptr_card2 = 1;
		*ptr_card3 = 1;
		*ptr_card4 = 1;
		*ptr_card5 = 1;
	}
	return straight;
}

/*
Function: check_straight
Date Created: 11/16/2019
Date Modified: 11/16/2019
Description: Checks the hand of a player to see if they have 5 cards in consecutive order with their rank
Input Parameters: Hand player, int *ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4 , int* ptr_card5
Returns: returns an integer of 1 if the player's hand fufills the conditional
Preconditions: none
Postconditions: none
*/
void intialize_deck(int wDeck[][13])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			wDeck[i][j] = 0;
		}
	}
}