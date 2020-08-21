// Authors: Deitel & Deitel - C How to Program
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

typedef struct card
{
	int suit;
	int rank;
} Card;

typedef struct hand
{
	Card arr[5];
} Hand;



int get_option(void);
void print_game_menu(void);
void print_game_rules(void);
char switch_card_option(void);
void shuffle(int wDeck[][13]);
void deal(Hand player1, Hand player2, const int wDeck[][13], const char* wFace[], const char* wSuit[]);
void print_hand(Hand player, int num);
int check_pair(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5);
int check_two_pair(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5);
int check_three_kind(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5);
int check_four_kind(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5);
int check_flush(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5);
int check_stright(Hand player, int* ptr_card1, int* ptr_card2, int* ptr_card3, int* ptr_card4, int* ptr_card5);
void intialize_deck(int wDeck[][13]);