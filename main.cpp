#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "bubble.h"

using namespace std;

// The first data structure is classStats
struct classStats
{
    float mean;      // Variables mean (float)
    float min;       // Variables min (float)
    float max;       // Variables max (float)
    float median;    // Variables median (float)
    string name;     // Use std::string for safer handling of the name
};

int main()
{
    // A display of the title, my name, and e-mail address
    cout << "+-------------------------------------------------+" << endl;
    cout << "|      Student Exam Grades Analyzer              |" << endl;
    cout << "|      Author name: Nathanlie Ortega             |" << endl;
    cout << "|      NathanlieOrtega.Dev@gmail.com             |" << endl;
    cout << "+-------------------------------------------------+\n" << endl;

    // Open the grades.dat file for reading
    FILE *data_file = fopen("grades.dat", "r");

    if (data_file == NULL) 
    {
        printf("There's an error opening this file.\n");
        return 1;
    }

    // Read class stats name (Assume we have a valid class name in data)
    classStats statsData;
    char nameBuffer[100];
    fscanf(data_file, "%99s", nameBuffer);  // Read the class name safely
    statsData.name = nameBuffer;  // Use the buffer directly, no need for malloc

    student *students[19];  // Create an array of 19 student pointers

    for (int i = 0; i < 19; i++)
    {
        students[i] = (student *)malloc(sizeof(student));  // Allocate space for each student
        
        // Use fscanf to read in student data: first, last name and 4 exam scores
        fscanf(data_file, "%ms %ms %d %d %d %d", &students[i]->first, &students[i]->last,
            &students[i]->exam1, &students[i]->exam2, &students[i]->exam3, &students[i]->exam4);

        // Calculate the mean of each student
        students[i]->mean = (students[i]->exam1 + students[i]->exam2 + students[i]->exam3 + students[i]->exam4) / 4.0;
    }

    fclose(data_file);  // Close the file after reading

    // Sort the students using the bubble sort code
    bubble(students, 19);  // Sorting students by their mean score

    // Calculate class statistics
    statsData.min = students[0]->mean;
    statsData.max = students[18]->mean;
    statsData.median = (students[9]->mean + students[10]->mean) / 2.0;

    // Calculate the class mean score
    float total = 0;
    for (int i = 0; i < 19; i++) 
    {
        total += students[i]->mean;
    }
    statsData.mean = total / 19;

    // Output for class statistics data
    printf("%s MEAN: %.2f | MIN: %.2f | MAX: %.2f | MEDIAN: %.2f  \n", statsData.name.c_str(), statsData.mean, statsData.min, statsData.max, statsData.median);

    // Output for each student's name and mean score
    for (int i = 0; i < 19; i++) 
    {
        printf("%-15s %-15s %.2f\n", students[i]->first, students[i]->last, students[i]->mean);
        
        // Free the allocated memory
        free(students[i]->first);
        free(students[i]->last);
        free(students[i]);
    }

    // std::string handles memory cleanup automatically, no need for free on name
    return 0;
}
