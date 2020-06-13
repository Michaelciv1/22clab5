/*

  CIS 22C

    Lab5: Use adjacency lists to implement a graph of CIS courses at De Anza
        Allow the user to print the list and search for courses and prereqs.

  Author: Michael Wallerius

  Date: 6/5/2020

*/

#include "graph.hpp"

//This constructor takes in the input file and creates the lists for courses and prereqs. There is no return.
Graph::Graph(string filename){
    ifstream courseList(filename);
    string line, cn, courseName;
    int increment = 0;

    if (!courseList.is_open())
        cout << "File failed to open";

    while (!courseList.eof()){
        std::getline(courseList, line);
        stringstream segment(line);
        std::getline(segment, cn, ',');
        Vertex newCourse(cn);
        listOfCourses.push_back(cn);
        std::getline(segment, courseName, ',');
        courseTitles[cn] = courseName;

        while (std::getline(segment, cn)){
            cn = cn.substr(1, cn.length());
			listOfCourses.at(increment).prepend(cn);
        }
        increment++;
    }
    courseList.close();
}

//This function takes no inputs and prints the list of course codes with prereqs. There is no return.
void Graph::printFullList() {
    for (int i = 0; i < listOfCourses.size(); i++){
    NodeInfo* nodePtr = listOfCourses[i].getPrereqList();
		cout << listOfCourses[i].getCourse().courseNumber << " ==> ";
		if (nodePtr != nullptr){
			while (nodePtr != nullptr)
			{
				cout << nodePtr->courseNumber;
				nodePtr = nodePtr->next;
			}
		}
		else{
			cout << "none";
		}
		cout << "\n\n";
    }
}

//This function prints the list of course codes and names without prereqs.
void Graph::printListNoPreReq(){
    for (auto const& pair: courseTitles) {
		std::cout << pair.first << pair.second << "\n";
	}
	cout << endl;
}

//This function takes a user input course code and searches for the course. It prints the prereqs. There is no return.
void Graph::searchForCourse(string cn){
	for (int i = 0; i < listOfCourses.size(); i++){
		if (cn == listOfCourses[i].getCourse().courseNumber){
			NodeInfo* nodePtr = listOfCourses[i].getPrereqList();
			cout << listOfCourses[i].getCourse().courseNumber << endl << "Prerequisites: ";
			if (nodePtr != nullptr) {
				while (nodePtr != nullptr) {
					cout << nodePtr->courseNumber;
					nodePtr = nodePtr->next;
					if (nodePtr != nullptr){
						cout << ",\n";
					}
				}
			}
			else {
				cout << "none\n\n";
			}
		}
	}
	cout << "\n\n";
}



