# Name Surfer
## Description
This console program allows users to search for a specific name and display a visual representation of its popularity throughout the decades. 
It creates a linked list of the top 1000 baby names in the United States over the past century (1900 to 2010), using a text file 
containing data collected by the Social Security Administration.

## File Format
The program parses a text file containing rankings for approximately 4500 names. Each line lists the name, followed by twelve numbers, 
which represent its rank for each decade, from the 1900s to the 2010s. More popular names have smaller numbers, with the exception of
zero, which indicates that the name did not appear in the top 1000 for the decade. 

## Interface
Users have three options for displaying data. 

|choice|action|
|---|---|
1 |Displays the rankings of a single name for all decades.
2|Displays the rankings of the names of your choice for a given decade.
3|Exits the program|


## Visualization
The rank of a name is portrayed using stars (asterisks). Each star is one-tenth of a rank. The more popular the name, the less stars 
are present. 0 indicates that the name did not reach the top 1000 for that decade.

## Use Case
```
1: Enter a name
2: Enter a year
3: Exit
Enter a choice: 2
Enter a year: 1970
Enter how many names you want to compare:  3
Enter name 1: Jennifer
Enter name 2: peter
Enter name 3: SaM
You selected the decade 1970
Jennifer       -1
Peter          *****-55
Sam            **************************************-380
 
1: Enter a name
2: Enter a year
3: Exit
Enter a choice: 1
Enter a name: Dentist
Name not found
```

