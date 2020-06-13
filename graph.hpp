/*

  CIS 22C

    Lab5: Use adjacency lists to implement a graph of CIS courses at De Anza
        Allow the user to print the list and search for courses and prereqs.

  Author: Michael Wallerius

  Date: 6/5/2020

*/

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

struct NodeInfo {
    string courseNumber;
    NodeInfo *next;
    NodeInfo(const string cn) { courseNumber = cn; next = nullptr; }
    NodeInfo() { courseNumber = ""; next = nullptr; }
};

class Vertex {
private:
    NodeInfo course;
    NodeInfo *prereqList; // pointer to a list of prerequisits for the course

public:
    Vertex(const string cn) { course.courseNumber = cn; prereqList = nullptr; }

    void prepend(const string courseNumber) // adds course to beginning of list
    {
        NodeInfo *prereq = new NodeInfo(courseNumber);
        prereq->next = prereqList;
        prereqList = prereq;
    }
    NodeInfo getCourse() { return course; }
    NodeInfo *getPrereqList() { return prereqList; }
};


class Graph {
private:
    vector<Vertex> listOfCourses;
    map<string, string> courseTitles; // maps course code to its title

public:
    Graph(string filename);
    void printFullList();
    void printListNoPreReq(); // prints list of courses and immediate prerequis
    void searchForCourse(string cn);
    void printCourseName(string cn) {cout << courseTitles[cn] << endl; cout << endl;} //Takes user input course code and prints course name.
};


#endif /* graph_hpp */
