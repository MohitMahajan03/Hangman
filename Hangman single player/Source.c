#include <stdio.h>
#include<conio.h>
#include<string.h>
#include<filesystem>
	
int t1 = 0, t2 = 0;
int c1 = 0, c2 = 0, c3 = 0, c4 = 0;


//void letters();
void check(guess, alpha);
void play(word, n, ans, alpha);
void draw(miss);
void game_board(n, ans);
void input();

void input()
{
	int i, n, s;
	char word[50], ans[50], alpha[4][8];
	int next = 0, try = 0;

	FILE* ptr;
	ptr = NULL;
	printf("Themes Available -\n1. ASTRONOMY\n2. COUNTRIES\n3. GAMES\n4. MOVIES AND TV SHOWS\n\n");
	printf("Enter the theme of choice\n");
	scanf_s("%d", &t1);
//	printf("%d", t1);//test case
	
	switch (t1)
	{
	case 1: ptr = fopen("astronomy.txt", "r");
//		printf("Successfully opened astronomy.txt\n"); //test point
		c1++;
		next = c1;
		break;
	case 2: ptr = fopen("countries.txt", "r");
	//	printf("Successfully opened countries.txt\n"); //test point
		c2++;
		next = c2;
		break;
	case 3: ptr = fopen("games.txt", "r");
	//	printf("Successfully opened games.txt\n"); //test point
		c3++;
		next = c3;
		break;
	case 4: ptr = fopen("movies and shows.txt", "r");
	//	printf("Successfully opened movies and shows.txt\n"); //test point
		c4++;
		next = c4;
		break;
	default: printf("Theme not available\n");
		exit(0);
	}
	
	if(t1==t2)
	{
		//printf("continued with the same file\n"); // test point
		//_getch();// test point
	}
	
	while ((next > try) && fgets(word, 50, ptr)!= NULL)
	{
	//	printf(" %s\n", word);// test point
		n = strlen(word);
	//	printf("%d\n", n-1);// test point
		try++;
	}
	//_getch(); // kept for verification
	system("cls");
	play(word, n, ans, alpha);
}


void game_board(int n, char ans[])
{
	int i;
	for (i = 0;i < n;i++)
	{
		printf(" %c", ans[i]);
	}
	printf("\n");
}

void play(char word[], int n, char ans[], char alpha[4][8])
{
	int i = 0, j = 0, count = 0, miss = 0, strikes = 0, letter = 97;
	char guess = ' ', consent[5];
	for (i = 0;i < n-1;i++)
	{
		ans[i] = '_';
		if (word[i] == ' ')
		{
			ans[i] = ' ';
		}
	}
	ans[i] = '\0';

	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 8;j++)
		{
			alpha[i][j] = (char)letter;
			letter++;
			if (letter > 123)
			{
				alpha[i][j] = ' ';
			}
		}
	}

	while (miss != 6 && strikes != n)
	{
		
		printf("\n\n\n");
		count = 0;
		check(alpha, guess);
		printf("\n\n");
		printf("Enter your guess character\n");
		//printf("\n\n");
		game_board(n, ans);
		draw(miss);
		scanf_s("%c", &guess);
		for (i = 0;i < n;i++)
		{
			if (guess == word[i])
			{
				ans[i] = guess;
			}
			else
			{
				count++;
			}
		}

		//game_board(n, ans);
		if (count == (n))
		{
			miss++;
		}
		strikes = 0;
		for (i = 0;i < n;i++)
		{
			if (ans[i] == word[i])
			{
				strikes++;

			}
		}
		system("cls");
	}
	if (strikes == n)
	{
		game_board(n, ans);
		draw(miss);
		printf("YOU WIN!\n\n");
		_getch();
	}

	if (miss == 6)
	{
		game_board(n, ans);
		draw(miss);
		printf("The correct answer is - %s", word);
		printf("YOU LOSE!\n");
	}
	printf("Do you wish to continue? yes or no\n");
	scanf(" %s", consent);
	if (strcmp(consent,"yes") == 0)
	{
		input();
	}
	else
	{
		exit(0);
	}
}

void draw(int miss)
{
	//bar					
	printf("\t\t\t\t\t\t\t\t\t\t------------------\n");
	printf("\t\t\t\t\t\t\t\t\t\t|\t\t | \n");
	printf("\t\t\t\t\t\t\t\t\t\t|\t\t | \n");
	printf("\t\t\t\t\t\t\t\t\t\t|\t\t | \n");
	printf("\t\t\t\t\t\t\t\t\t\t|");
	if (miss >= 1)
	{
		//pole and face
		printf("\t\t 0\n");
	}
	else
	{
		printf("\n");
	}
	printf("\t\t\t\t\t\t\t\t\t\t|");
	if (miss >= 2)
	{
		//pole and neck
		printf("\t\t |\n");

	}
	else
	{
		printf("\n");
	}
	printf("\t\t\t\t\t\t\t\t\t\t|");
	if (miss >= 3)
	{
		//body with hands
		printf("\t\t/$\\ \n");
	}
	else
	{
		printf("\n");
	}
	printf("\t\t\t\t\t\t\t\t\t\t|");
	if (miss >= 4)
	{
		//body 2
		printf("\t\t $  \n");

	}
	else
	{
		printf("\n");
	}
	printf("\t\t\t\t\t\t\t\t\t\t|");
	if (miss >= 5)
	{
		//body 3
		printf("\t\t $  \n");

	}
	else
	{
		printf("\n");
	}
	printf("\t\t\t\t\t\t\t\t\t\t|");
	if (miss == 6)
	{
		//legs
		printf("\t\t/ \\ \n");
	}
	else
	{
		printf("\n");
	}
	printf("\t\t\t\t\t\t\t\t\t\t|\n");
	printf("\t\t\t\t\t\t\t\t\t\t|\n");	
}


void check(char alpha[4][8], char guess)
{
	int i, j;
	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 8;j++)
		{
			if (alpha[i][j] == guess)
			{
				alpha[i][j] = ' ';
			}
			printf(" %c", alpha[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	FILE* fp;
	int i, j;
	char data[100];
	fp = fopen("art.txt", "r");
	while (fgets(data, 100, fp) != NULL)
	{
		//printf("%d
		printf("%s", data);
	}
	fclose(fp);
	_getch();
	system("cls");
	input();
	_getch();
}