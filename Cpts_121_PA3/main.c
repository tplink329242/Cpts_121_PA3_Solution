/*******************************************************************************************

* Programmer: Guangbei Yi                                                                        *

* Class: CptS 121, Spring 2021; Programming Assignment 3                                            *

* Programming Assignment: Statistical Analysis of Student Records                   *

* Date: February 16, 2021                                                                           *

* Description: This program Write a program that processes numbers, corresponding to student records read in from a file, and writes the required results to an output file.

* File Description: This profile include the main entertance.

* https://eecs.wsu.edu/~aofallon/cpts121/progassignments/PA3.htm

*******************************************************************************************/

#include "pa3_functions.h"

int main(int argc, char* argv[])
{
	//open file
	FILE* infile = NULL;
	infile = fopen("input.dat", "r");
	if (infile == NULL)
	{
		perror("Error: ");
		return(-1);
	}

	printf("\nOpening success");
	
	double array_students[MAX_STUDENTS_NUM][MAX_STUDENTS_REC];

	/*load data from files*/
	for (int i = 0; i < MAX_STUDENTS_NUM; ++i)
	{
		array_students[i][REC_STUDENTS_ID] = read_integer(infile);
		array_students[i][REC_STUDENTS_GPA] = read_double(infile);
		array_students[i][REC_STUDENTS_RANK] = read_integer(infile);
		array_students[i][REC_STUDENTS_AGE] = read_double(infile);
	}

	/*Compute GPA Mean*/
	double num_sum_gpa = 0.0;
	double num_avg_gpa = 0.0;
	
	for (int i = 0; i < MAX_STUDENTS_NUM; ++i)
	{
		num_sum_gpa += array_students[i][REC_STUDENTS_GPA];
	}

	num_avg_gpa = calculate_mean(num_sum_gpa, MAX_STUDENTS_NUM);

	/*Compute Rank Mean*/
	double num_sum_rank = 0.0;
	double num_avg_rank = 0.0;

	for (int i = 0; i < MAX_STUDENTS_NUM; ++i)
	{
		num_sum_rank += array_students[i][REC_STUDENTS_RANK];
	}

	num_avg_rank = calculate_mean(num_sum_rank, MAX_STUDENTS_NUM);

	/*Compute Age Mean*/
	double num_sum_age = 0.0;
	double num_avg_age = 0.0;

	for (int i = 0; i < MAX_STUDENTS_NUM; ++i)
	{
		num_sum_age += array_students[i][REC_STUDENTS_AGE];
	}

	num_avg_age = calculate_mean(num_sum_age, MAX_STUDENTS_NUM);

	
	/*Compute GPA standard deviation*/
	double num_students_gpa_deviation = 0;
	double num_students_gpa_standard_deviation = 0;
	double array_students_gpa_deviation[MAX_STUDENTS_NUM];
	double deviation1 = 0;
	double deviation2 = 0;
	double deviation3 = 0;
	double deviation4 = 0;
	double deviation5 = 0;

	for (int i = 0; i < MAX_STUDENTS_NUM; ++i)
	{
		array_students_gpa_deviation[i] = calculate_deviation(array_students[i][REC_STUDENTS_GPA], num_avg_gpa);
	}

	deviation1 = array_students_gpa_deviation[0];
	deviation2 = array_students_gpa_deviation[1];
	deviation3 = array_students_gpa_deviation[2];
	deviation4 = array_students_gpa_deviation[3];
	deviation5 = array_students_gpa_deviation[4];

	num_students_gpa_deviation = calculate_variance(deviation1, deviation2, deviation3, deviation4, deviation5, MAX_STUDENTS_NUM);
	num_students_gpa_standard_deviation = calculate_standard_deviation(num_students_gpa_deviation);

	
	/*find man and min*/
	double num_students_max = 0;
	double num_students_min = 0;

	num_students_max = find_max(array_students[0][REC_STUDENTS_GPA], array_students[1][REC_STUDENTS_GPA], array_students[2][REC_STUDENTS_GPA], array_students[3][REC_STUDENTS_GPA], array_students[4][REC_STUDENTS_GPA]);
	num_students_min = find_min(array_students[0][REC_STUDENTS_GPA], array_students[1][REC_STUDENTS_GPA], array_students[2][REC_STUDENTS_GPA], array_students[3][REC_STUDENTS_GPA], array_students[4][REC_STUDENTS_GPA]);


	/*writing data*/
	FILE* outfile = NULL;
	outfile = fopen("output.dat", "w");
	if (infile == NULL)
	{
		perror("Error: ");
		return(-1);
	}

	print_double(outfile, num_avg_gpa);
	print_double(outfile, num_avg_rank);
	print_double(outfile, num_avg_age);
	
	fprintf(outfile, "\n");
	
	print_double(outfile, num_students_gpa_standard_deviation);
	print_double(outfile, num_students_min);
	print_double(outfile, num_students_max);

	fclose(infile);
	fclose(outfile);

	printf("\nWriting success");
	
	return 0;
}