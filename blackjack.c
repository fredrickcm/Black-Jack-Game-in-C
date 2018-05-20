#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int shuff(int cards[])
{

	int t;
	int i;
	int card_deck[52];
	for (i=0;i<52;i++)
		card_deck[i] = (i/13+3)*100 + i%13 + 1;

	srand(time(NULL));
	for (i = 0; i < 52; i++)
	{
		do
		{
			t = rand() % 52;
		} while (card_deck[t] == 0);
		cards[i] = card_deck[t];
		card_deck[t] = 0;
	}

	return 0;
}

int convertion(int a)
{
	if ((a%100==11) ||(a%100==12) ||(a%100==13)) return (a/100)*100+10;
	else return a;
}

void pic(int num)
{
	char fl;
	int num_set;

	fl = num / 100;
	num_set = num % 100;
	switch (num_set)
	{
		case 1:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("* %c   *\n", fl);
			printf("*   A *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("* %c   *\n", fl);
			printf("*  %2d *\n", num_set);
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 11:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("* %c   *\n", fl);
			printf("*   J *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 12:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("* %c   *\n", fl);
			printf("*   Q *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}
		case 13:
		{
			printf("*******\n");
			printf("*     *\n");
			printf("* %c   *\n", fl);
			printf("*   K *\n");
			printf("*     *\n");
			printf("*******\n");
			break;
		}

	}
}

int play(void)
{
	int i;
	int sum_set_one=0;
	int sum_set_two=0;
	int set_one_cards[5]={0};
	int set_two_cards[5]={0};
	int cards[52];
	char go_on;
	char d;

	printf("Welcome to SimpleBlackJack!\n"
	"Anytime you can press Ctrl+C to exit.\n"
	"Enjoy! Press Enter to go on......\n");
	do{
		go_on = getchar();
	} while (go_on != '\n');
	printf("\n");

	//shuff the cards
	shuff(cards);

	//give the cards
	set_one_cards[0]=cards[0];
	set_one_cards[1]=cards[1];
	set_two_cards[0]=cards[2];
	set_two_cards[1]=cards[3];

	//the 2 cards player get
	printf("One of computer's cards:\n");
	pic(set_two_cards[0]);
	printf("\n");
	printf("Cards of player:\n");
	pic(set_one_cards[0]);
	//printf("\n");
	pic(set_one_cards[1]);
	//printf("\n");

	i=0;
	for (i=0; i<2; i++)
	{
		if (set_one_cards[i]%100 == 1)
		{
			printf("choose A value of the card %d, input 'y' for 11 or 'n' for 1 :\n", i+1);
			do{
				d = getchar();
			} while (d!='y' && d!='n');

			if (d == 'y')
			{
				printf("You've chosen value 11 for card A.\n");
				sum_set_one = sum_set_one + 11;
			}
			else if(d == 'n')
			{
				printf("You've chosen value 1 for card A.\n");
				sum_set_one = sum_set_one +1;
			}
		}
		else if (convertion(set_one_cards[i]) %100 ==10) sum_set_one = sum_set_one + 10;
		else sum_set_one = sum_set_one + set_one_cards[i]%100;

		if (sum_set_one > 21)
		{
			printf("Sum of player's cards now:%d\n\n",sum_set_one);
			printf("Computer win!\n");
			return 1;
		}
		else if (sum_set_one == 21)
		{
			printf("Sum of player's cards now:%d\n\n",sum_set_one);
			printf("Player win!\n");
			return 0;
		}
	}
	printf("Sum of player's cards now:%d\n\n",sum_set_one);

	//whether player get another cards
	i=0;
	for (i=0; i<3; i++)
	{
		char j = 'n';

		printf("Want more cards? Input y or n:\n");
		do{
			j = getchar();
		} while (j!='y' &&j!='n');

		if (j=='y')
		{
			printf("You've got another card now.\n");
			set_one_cards[i+2]=cards[i+4];
			printf("and your card %d is:\n", i+3);
			pic(set_one_cards[i+2]);

			if (set_one_cards[i+2]%100 == 1)
			{
				printf("Choose A value of the card %d, input 'y' for 11 or 'n' for 1:\n", i+3);
				do{
					d = getchar();
				} while (d!='y' && d!='n');
				if (d == 'y')
				{
					printf("You've chosen value 11 for card A.\n");
					sum_set_one = sum_set_one + 11;
				}
				else if(d == 'n')
				{
					printf("You've chosen value 1 for card A.\n");
					sum_set_one = sum_set_one +1;
				}
			}
			else if (convertion(set_one_cards[i+2]) %100 ==10) sum_set_one = sum_set_one + 10;
			else sum_set_one = sum_set_one + set_one_cards[i+2]%100;

			if (sum_set_one > 21)
			{
				printf("Sum of player's cards now:%d\n\n",sum_set_one);
				printf("Computer win!\n");
				return 1;
			}
			else if (sum_set_one == 21)
			{
				printf("Sum of player's cards now:%d\n\n",sum_set_one);
				printf("Player win!\n");
				return 0;
			}
			else printf("Sum of player's cards now:%d\n\n",sum_set_one);
		}
		else
		{
			printf("Sum of player's cards now:%d\n\n",sum_set_one);
			break;
		}
	}
	if (i == 3)
	{
		printf("Player win! Because the sum of your 5 cards is no larger than 21! So lucky!\n");
		return 0;
	}

	//the 2 cards of boss/computer
	//i=0;
	printf("Computer's cards:\n");
	pic(set_two_cards[0]);
	pic(set_two_cards[1]);

	if (set_two_cards[0]%100 + set_two_cards[1]%100 == 2)
	{
		sum_set_two=12; //two A cards
		printf("Sum of computer's cards now:%d\n\n", sum_set_two);
	}
	else if ((convertion(set_two_cards[0]))%100 + (convertion(set_two_cards[1]))%100 ==1)
	{
		sum_set_two=21;
		printf("Sum of computer's cards now:%d\n\n", sum_set_two);
		printf("Computer win!\n");
		return 1;
	}
	else if (set_two_cards[0]%100==1 || set_two_cards[1]%100==1)
	{
		sum_set_two=(set_two_cards[0]+set_two_cards[1])%100+(rand()%2)*10;
		printf("Sum of computer's cards now:%d\n\n", sum_set_two);
	}
	else
	{
		sum_set_two = (convertion(set_two_cards[0]))%100 + (convertion(set_two_cards[1]))%100;
		printf("Sum of computer's cards now:%d\n\n", sum_set_two);
	}

	//whether computer get another cards until sum_set_two>16
	//i=0;
	for (i=0; i<3 && sum_set_two<17; i++)
	{
		set_two_cards[i+2]=cards[i+7];
		printf("Computer's card %d is:\n", i+3);
		pic(set_two_cards[i+2]);

		if (set_two_cards[i+2]%100 == 1)
		{
			if (sum_set_two+11 <= 21)
			{
				printf("Computer has chosen A as 11\n");
				sum_set_two = sum_set_two+11;
				printf("Sum of computer's cards now:%d\n\n", sum_set_two);
			}
			else
			{
				printf("Computer has chosen A as 1\n");
				sum_set_two = sum_set_two+1;
				printf("Sum of computer's cards now:%d\n\n", sum_set_two);
			}
		}
		else
		{
			sum_set_two = sum_set_two + convertion(set_two_cards[i+2])%100;
			printf("Sum of computer's cards now:%d\n\n", sum_set_two);
		}
	}
	if (i == 3)
	{
		printf("Computer win! Because the sum of its 5 cards is no larger than 21! So lucky!\n");
		return 1;
	}

	//the last step
	if (sum_set_two>21 || sum_set_one>sum_set_two)
	{
		printf("Player win!\n");
		return 0;
	}
	else if (sum_set_one == sum_set_two)
	{
		printf("Oh, player and computer get the same score!\n");
		return 3;
	}
	else if (sum_set_one < sum_set_two)
	{
		printf("Computer win!\n");
		return 1;
	}

	return 3;
}

int main(void)
{
	char play_again;

	play();

	printf("\nAnd now would you like to play again? Input 'y' or 'n':\n");
	do{
		play_again = getchar();
	} while (play_again!='y' && play_again!='n');

	if (play_again == 'y')
	{
		printf("\nOK, let's go play_again!\n\n");
		main();
	}

	return 0;
}
