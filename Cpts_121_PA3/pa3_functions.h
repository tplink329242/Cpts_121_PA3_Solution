/*******************************************************************************************

* Programmer: Guangbei Yi                                                                        *

* Class: CptS 121, Spring 2021; Programming Assignment 3                                            *

* Programming Assignment: Statistical Analysis of Student Records                   *

* Date: February 16, 2021                                                                           *

* Description: This program Write a program that processes numbers, corresponding to student records read in from a file, and writes the required results to an output file.

* File Description: This profile include all function prototype.

* https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA3.htm

*******************************************************************************************/


#ifndef PA3FUNCTIONS_H
#define PA3FUNCTIONS_H

#ifdef __cplusplus
extern "C"
{
#endif

#define _CRT_SECURE_NO_WARNINGS
	
#define MAXLENGTH 5
#define MAX_STUDENTS_NUM 5
#define MAX_STUDENTS_REC 4

#define REC_STUDENTS_ID 0
#define REC_STUDENTS_GPA 1
#define REC_STUDENTS_RANK 2	
#define REC_STUDENTS_AGE 3	
	
#include <stdio.h>
#include <math.h>

// function declaration - function prototype - 

/*Reads one double precision number from the input file.Note: You may assume that the file only contains real numbers.*/
double read_double(FILE* infile); 

/*Reads one integer number from the input file.*/
int read_integer(FILE* infile); 

/*Finds the sum of number1, number2, number3, number4 and number5, and returns the result.*/
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

/*Determines the mean through the calculation sum / number and returns the result.You need to check to make sure that number is not 0. If it is 0 the function returns - 1.0 (we will assume that we are calculating the mean of positive numbers), otherwise it returns the mean.*/
double calculate_mean(double sum, int number); 

/*Determines the deviation of number from the meanand returns the result.The deviation may be calculated as number - mean.*/
double calculate_deviation(double number, double mean); 

/*Determines the variance through the calculation : ((deviation1) ^ 2 + (deviation2) ^ 2 + (deviation3) ^ 2 + (deviation4) ^ 2 + (deviation5) ^ 2) / number and returns the result.Hint : you may call your calculate_mean() function to determine the result.*/
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number); 

/*Calculates the standard deviation as sqrt(variance) and returns the result.Recall that you may use the sqrt() function that is found in math.h.*/
double calculate_standard_deviation(double variance); 

/*Determines the maximum number out of the five input parameters passed into the function, returning the max.*/
double find_max(double number1, double number2, double number3, double number4, double number5); 

/*Determines the minimum number out of the five input parameters passed into the function, returning the min.*/
double find_min(double number1, double number2, double number3, double number4, double number5); 

/*Prints a double precision number(to the hundredths place) to an output file.*/
void print_double(FILE* outfile, double number);

#ifdef __cplusplus
}
#endif	
#endif