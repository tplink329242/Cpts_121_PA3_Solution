/*******************************************************************************************

* Programmer: Guangbei Yi                                                                        *

* Class: CptS 121, Spring 2021; Programming Assignment 3                                            *

* Programming Assignment: Statistical Analysis of Student Records                   *

* Date: February 16, 2021                                                                           *

* Description: This program Write a program that processes numbers, corresponding to student records read in from a file, and writes the required results to an output file.

* File Description: This profile include all function definitions for the above functions.

* https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA3.htm

*******************************************************************************************/



#include "pa3_functions.h"

/*************************************************************
 * Function: double read_double(FILE* infile)                *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Reads one double precision number from the    *
 * input file. Note: You may assume that the file only       *
 * contains real numbers.                                    *
 * Input parameters: FILE* infile                            *
 * Returns: double credits.                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double read_double(FILE* infile)
{
	double credits = 0;
	fscanf(infile, "%lf", &credits);
	return credits;
}

/*************************************************************
 * Function: int read_integer(FILE* infile)                  *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Reads one integer number from the input file. *
 * Input parameters: FILE* infile                            *
 * Returns: int credits                                      *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
int read_integer(FILE* infile)
{
	int credits = 0;
	fscanf(infile, "%d", &credits);
	return credits;
}

/*************************************************************
 * Function: double calculate_sum(double number1,            *
 * double number2, double number3, double number4,           *
 * double number5)                                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Finds the sum of number1, number2, number3,   *
 * number4, and number5 and returns the result.              *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double calculate_sum(double number1, double number2, double number3, double number4, double number5)
{
	double num_sum = 0;
	num_sum = number1 + number2 + number3 + number4 + number5;
	return num_sum;
}

/*************************************************************
 * Function: calculate_mean(double sum, int number)          *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Determines the mean through the calculation   *
 * sum / number and returns the result. You need to check    *
 * to make sure that number is not 0. If it is 0 the function*
 * returns -1.0 (we will assume that we are calculating      *
 * the mean of positive numbers), otherwise it returns       *
 * the mean.                                                 *
 * Input parameters: double sum, int number                  *
 * Returns: double mean.                                     *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double calculate_mean(double sum, int number)
{
	if (number == 0)
	{
		printf("\nNumber equals to zero!");
		return -1.0;
	}
	else
	{
		double mean = 0;
		mean = sum / number;
		return mean;
	}	
}

/*************************************************************
 * Function: double double calculate_deviation(double number,*
 * double mean)                                              *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Determines the deviation of number from the   *
 * mean and returns the result. The deviation may be         *
 * calculated as number - mean.                              *
 * Input parameters: double number, double mean              *
 * Returns: double deviation.                                *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double calculate_deviation(double number, double mean)
{
	double deviation = 0;
	deviation = number - mean;
	return deviation;
}

/*Determines the variance through the calculation : ((deviation1) ^ 2 + (deviation2) ^ 2 + (deviation3) ^ 2 + (deviation4) ^ 2 + (deviation5) ^ 2) / number and returns the result. Hint : you may call your calculate_mean() function to determine the result.*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number)
{
	if (number == 0)
	{
		printf("\nNumber equals to zero!");
		return -1.0;
	}
	double variance = 0;
	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number;
	return variance;
}

/*************************************************************
 * Function: calculate_standard_deviation(double variance)   *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Calculates the standard deviation as sqrt     *
 * (variance) and returns the result.                        *
 * Input parameters: double variance                         *
 * Returns: double deviation;.                               *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double calculate_standard_deviation(double variance)
{
	if (variance<0)
	{
		printf("\ninvalid variance!");
		return -1.0;
	}
	else
	{
		double deviation = 0;
		deviation = sqrt(variance);
		return deviation;
	}
}

/*************************************************************
 * Function: double find_max(double number1, double number2, *
 * double number3, double number4, double number5)           *
 *                                                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Determines the maximum number out of the five *
 * input parameters passed into the function, returning      *
 * the max.                                                  *
 * Input parameters: double numbers                          *
 * Returns: double num_max.                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double find_max(double number1, double number2, double number3, double number4, double number5)
{
	double num_max = number1;
	double num_array[MAXLENGTH];

	/*load array for listing*/
	num_array[0] = number1;
	num_array[1] = number2;
	num_array[2] = number3;
	num_array[3] = number4;
	num_array[4] = number5;

	for (int i = 1; i < MAXLENGTH; i++)
	{
		if (num_max < num_array[i])
		{
			num_max = num_array[i];
		}
	}
	
	return num_max;
}

/*************************************************************
 * Function: find_min(double number1, double number2,        *
 * double number3, double number4, double number5)           *
 *                                                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Determines the minimum number out of the five *
 * input parameters passed into the function, returning      *
 * the min.                                                  *
 * Input parameters: double numbers                          *
 * Returns: double num_min;.                                 *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
double find_min(double number1, double number2, double number3, double number4, double number5)
{
	double num_min = number1;
	double num_array[MAXLENGTH];

	/*load array for listing*/
	num_array[0] = number1;
	num_array[1] = number2;
	num_array[2] = number3;
	num_array[3] = number4;
	num_array[4] = number5;

	for (int i = 1; i < MAXLENGTH; i++)
	{
		if (num_min > num_array[i])
		{
			num_min = num_array[i];
		}
	}

	return num_min;
}

/*************************************************************
 * Function: print_double(FILE* outfile, double number)      *
 *                                                           *
 * Date Created:                                             *
 * Date Last Modified:                                       *
 * Description:Determines the minimum number out of the five *
 * input parameters passed into the function, returning      *
 * the min.                                                  *
 * Input parameters: FILE* outfile, double number            *
 * Returns:                                                  *
 * Preconditions:                                            *
 * Postconditions:                                           *
 *************************************************************/
void print_double(FILE* outfile, double number)
{
	fprintf(outfile, "%.2lf\n", number);
}
