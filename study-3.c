#include "stdio.h"
#include "stdbool.h"



/** 
 * * SE 1105 study material
 * 
 * * OUTPUT WITH LOOPS
 * 
 * * Author: Dindar ÖZ
 */

/* -------------------------------------------------------------------------- */
/*                            PROGRAMMING EXERCISES                           */
/* -------------------------------------------------------------------------- */


/**
 * * OUTPUT QUESTIONS:
 * * There are a set of functions each of which creates a certain output (Like a symbol, a shape or a letter) on the screen.
 * * You need to read each function and try to figure out what that output is 
 * */


/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-1                             */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape1() and 
// * run the program to see if your answer is correct 

void printShape1()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i % 10 == 0 || i + j == 10)
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}



/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-2                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape2() and 
// * run the program to see if your answer is correct 

void printShape2()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i + j == 5 || i + j == 15 || i - j == 5 || j - i == 5)
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}

}



/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-3                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape3() and 
// * run the program to see if your answer is correct 

void printShape3()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if ( ( i<5 && ( j == 5-i || j == 5+i ) ) ||  j == 5  )
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}



/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-4                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape4() and 
// * run the program to see if your answer is correct 

void printShape4()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if ((i<5 && (j == i || j == 10 - i)) || (i>=5 && j == 5))
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}



/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-5                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape5() and 
// * run the program to see if your answer is correct 

void printShape5()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (i % 6 == 0 || (j % 10 == 0 && i<6) || (i>6 && (j + 1) % 4 == 0))
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}


/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-6                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape6() and 
// * run the program to see if your answer is correct 

void printShape6()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (	( j % 3 == 2 && i > 6 )   ||
					( i == 6 && abs(j - 5)<3) ||
					( j == 5)						)
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}


/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-7                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape7() and 
// * run the program to see if your answer is correct 

void printShape7()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if ( (j==5) ||  ( i<10 && abs(10-2*j)<=i ) )
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}



/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-8                            */
/* -------------------------------------------------------------------------- */

// * When you think you have found the output, go to main() function and call printShape8() and 
// * run the program to see if your answer is correct 

void printShape8()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if ( i + 2*j == 10 || 2*j-i ==10 || (i==5 &&  10-i < 2*j && i+10>2*j) )
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}





/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-9                            */
/* -------------------------------------------------------------------------- */
// ? CHALLENGE
// * When you think you have found the output, go to main() function and call printShape9() and 
// * run the program to see if your answer is correct 

void printShape9()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if (	( i<8 && j == 5) ||
					( i==5 && abs(j-5)<4) ||
					( i<3 && abs(j-5)<2) ||
					( i + j == 12 && j<5) ||
					( i == j+2 && j>5)
				)
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}

/* -------------------------------------------------------------------------- */
/*                              OUTPUT QUESTION-10                            */
/* -------------------------------------------------------------------------- */
// ? CHALLENGE
// * When you think you have found the output, go to main() function and call printShape10() and 
// * run the program to see if your answer is correct 

void printShape10()
{
	for (int i = 0; i <= 10; i++)
	{
		for (int j = 0; j <= 10; j++)
		{
			if ( (	(i%10 == 0) || 
					(j%10 == 0) || 
					(j % 5 == 2 && (i-4)*(i-3)==0) || 
					(j % 5 == 3 && (i-4)*(i-3)==0) ||
					( i== 6 && j==5) ||
					(i == 7 && (j - 2)*(j - 8) == 0) ||
					(i == 8 && abs(j-5)<3)				) && ( (i%10)+(j%10)!=0) )
				printf("* ");
			else printf("  ");
		}
		printf("\n");
	}
}



int main() {

	printf("\n");
	
	//* Change the function here to see the output of the function you want
	printShape5();


	printf("\n\n");

}

