/*

  CIS 22C

    Lab5: Use adjacency lists to implement a graph of CIS courses at De Anza
        Allow the user to print the list and search for courses and prereqs.

  Author: Michael Wallerius

  Date: 6/5/2020

*/

#include <iostream>
#include "graph.hpp"

using namespace std;

int main()

{
    int selection;
    string cn;

    cout << "CIS Course Pre-Req Finder\n";
    cout << "-------------------------\n";
    cout << endl;
    cout << "Please pick from the following options: \n";
    cout << " 1. Display all courses and prerequisites\n";
    cout << " 2. Display all courses w/o prerequisites\n";
    cout << " 3. Search for a course's prereqs (use course code)\n";
    cout << " 4. Search for a course's full name (use course code)\n";

    Graph graph("CIS_Courses.txt");
    cout << "Select an option: ";
    cin >> selection;
    cout << endl;

    while (selection != 0){
        switch (selection){
            case 1:
                graph.printFullList();
                break;
            case 2:
                graph.printListNoPreReq();
                break;
            case 3:
                cout << "Enter the course code: ";
                cin >> cn;
                graph.searchForCourse(cn);
                break;
            case 4:
                string input;
                cout << "Enter the course code: ";
                cin >> input;
                cout << "The course title is:";
                graph.printCourseName(input);
                break;
        }
        cout << "Select a new option ('0' to exit): ";
        cin >> selection;
    }
}

/*OUTPUT
CIS Course Pre-Req Finder
-------------------------

Please pick from the following options:
 1. Display all courses and prerequisites
 2. Display all courses w/o prerequisites
 3. Search for a course's prereqs (use course code)
 4. Search for a course's full name (use course code)
Select an option: 1

CIS14A ==> none

CIS14B ==> CIS14A

CIS18A ==> none

CIS18B ==> CIS18A

CIS18C ==> CIS18B

CIS21JA ==> CIS22B, CIS26A

CIS21JB ==> CIS21JA

CIS22A ==> none

CIS22B ==> CIS22A

CIS22C ==> CIS22B, CIS35A

CIS26A ==> CIS22A

CIS26B ==> CIS26A

CIS27 ==> CIS22A, CIS36A

CIS28 ==> none

CIS29 ==> CIS22B, CIS27

CIS30A ==> none

CIS30B ==> CIS30A

CIS31 ==> none

CIS33A ==> none

CIS33B ==> CIS33A

CIS35A ==> none

CIS35B ==> CIS35A

CIS36A ==> none

CIS40 ==> none

CIS41A ==> CIS40

CIS41B ==> CIS41A

CIS64A ==> none

CIS64B ==> CIS64A

CIS64C ==> CIS64B

CIS64D ==> CIS64C

CIS64E ==> CIS64D

CIS64F ==> CIS64E

CIS66 ==> none

CIS67A ==> none

CIS67B ==> none

CIS73 ==> CIS18A, CIS26B

CIS74 ==> none

CIS75A ==> CIS66

CIS75B ==> CIS26B

CIS75D ==> none

CIS75E ==> none

Select a new option ('0' to exit): 2
CIS14A Visual Basic .NET Programming I
CIS14B Visual Basic .NET Programming II
CIS18A Introduction to Unix/Linux
CIS18B Advanced Unix/Linux
CIS18C Bash Scripting
CIS21JA Introduction to x86 Processor Assembly Language and Computer Architecture
CIS21JB Advanced x86 Processor Assembly Programming
CIS22A Beginning Programming Methodologies in C++
CIS22B Intermediate Programming Methodologies in C++
CIS22C Data Abstraction and Structures
CIS26A C as a Second Programming Language
CIS26B Advanced C Programming
CIS27 Programming in C++ for C/Java Programmers
CIS28 Object Oriented Analysis and Design
CIS29 Advanced C++ Programming
CIS30A Introduction to C# Programming
CIS30B Advanced C# Programming
CIS31 Operating System Concepts
CIS33A Programming in Perl
CIS33B Advanced Perl Programming
CIS35A Java Programming
CIS35B Intermediate Problem Solving in Java
CIS36A Introduction to Computer Programming Using Java
CIS40 Introduction to Programming in Python
CIS41A Python Programming
CIS41B Advanced Python Programming
CIS64A Database Management Systems
CIS64B Introduction to SQL
CIS64C Introduction to PL/SQL
CIS64D Database Tuning
CIS64E Introduction to Large Scale Processing Systems
CIS64F Introduction to Big Data and Analytics
CIS66 Introduction to Data Communications and Networking
CIS67A Local Area Networks
CIS67B Introduction to Wide Area Networking
CIS73 Unix/Linux Systems Programming
CIS74 Software Quality Assurance
CIS75A Internet Concepts and TCP/IP Protocols
CIS75B Internet Programming with TCP/IP
CIS75D Enterprise Security Policy management
CIS75E Enterprise Emergency Response Planning

Select a new option ('0' to exit): 3
Enter the course code: CIS22C
CIS22C
Prerequisites: CIS22B, CIS35A

Select a new option ('0' to exit): 4
Enter the course code: CIS22C
The course title is: Data Abstraction and Structures

Select a new option ('0' to exit): 0

Process returned 0 (0x0)   execution time : 25.633 s
Press any key to continue.
*/
