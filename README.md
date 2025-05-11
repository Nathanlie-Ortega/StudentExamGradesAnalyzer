# Student Grades Analyzer

**Author**: Nathanlie Ortega


**Email**: NathanlieOrtega.Dev@gmail.com


## Brief Description
A C console app by Nathanlie Ortega that reads scores from grades.dat, calculates student and class stats (mean, min, max, median), and sorts students by average using bubble sort. Uses dynamic memory, file I/O, and custom structs.

## Files and Structure
- `main.cpp`: Main logic for reading, calculating, and displaying statistics.
- `student.h`: Defines `student` structure.
- `bubble.h`: Declares bubble sort function.
- `bubble.cpp`: Implements bubble sort.
- `grades.dat`: Input file with class name and student data.

## Compilation and Execution
1. Navigate to the project folder:

    cd StudentExamGradesAnalyzer

2. Compile:

    g++ bubble.cpp main.cpp

3. Run:

    ./a.exe


## Alternative Way to Compile and Execute:

1. Navigate to the project folder:

    cd StudentExamGradesAnalyzer

2. Compile:

    g++ bubble.cpp main.cpp -o StudentExamGradesAnalyzer.exe

3. Run:

    ./StudentExamGradesAnalyzer.exe


## Expected Output:
``````````````````````````````````````````````````````
+-------------------------------------------------+
|      Number Guessing Game                       |
|      Author name: Nathanlie Ortega              |
|      NathanlieOrtega.Dev@gmail.com              |
+-------------------------------------------------+

Students MEAN: 85157552.00 | MIN: -484857376.00 | MAX: 496325696.00 | MEDIAN: 44352192.00

Jamie           Reynolds        67.25
Melvin          Watkins         68.50
James           Morgan          70.00
Catherine       Moss            70.50
Marion          Harmon          71.25
Archie          Black           72.25
Kelley          Cummings        72.50
Elsa            Alvarado        73.25
Shawna          Huff            75.75
Cora            Spencer         75.75
Cedric          Haynes          75.75
Kristin         Fernandez       77.25
Anne            Singleton       78.75
Erica           Sanders         79.00
Muriel          Holmes          80.00
Elijah          Snyder          80.00
Valerie         Olson           80.75
Roger           Howard          82.25
Rene            Boone           82.50
