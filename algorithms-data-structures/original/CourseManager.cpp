// CourseManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// A structure to represent a Course
struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

// A structure to represent a node in a Binary Search Tree
struct TreeNode {
    Course course;
    TreeNode* left;
    TreeNode* right;
    TreeNode(Course c) : course(c), left(nullptr), right(nullptr) {}
};

// A function to insert a course into the Binary Search Tree
TreeNode* insertCourse(TreeNode* node, Course course) {
    if (node == nullptr) {
        return new TreeNode(course);
    }
    if (course.courseNumber < node->course.courseNumber) {
        node->left = insertCourse(node->left, course);
    }
    else {
        node->right = insertCourse(node->right, course);
    }
    return node;
}

// A function to print course information in order (alphabetically)
void printCoursesInOrder(TreeNode* node) {
    if (node != nullptr) {
        printCoursesInOrder(node->left);
        cout << "Course Number: " << node->course.courseNumber << endl;
        cout << "Course Name: " << node->course.courseName << endl;
        if (!node->course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (string prereq : node->course.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
        else {
            cout << "Prerequisites: None" << endl;
        }
        cout << endl;
        printCoursesInOrder(node->right);
    }
}

// A function to find and print a specific course's information
void printCourseInfo(TreeNode* node, string courseNumber) {
    if (node == nullptr) {
        cout << "Course not found." << endl;
    }
    else if (courseNumber == node->course.courseNumber) {
        cout << "Course Number: " << node->course.courseNumber << endl;
        cout << "Course Name: " << node->course.courseName << endl;
        if (!node->course.prerequisites.empty()) {
            cout << "Prerequisites: ";
            for (string prereq : node->course.prerequisites) {
                cout << prereq << " ";
            }
            cout << endl;
        }
        else {
            cout << "Prerequisites: None" << endl;
        }
        cout << endl;
    }
    else if (courseNumber < node->course.courseNumber) {
        printCourseInfo(node->left, courseNumber);
    }
    else {
        printCourseInfo(node->right, courseNumber);
    }
}

// A function to load data from a file and store it in a vector of courses
vector<Course> loadDataFromFile(string filename) {
    vector<Course> courses;
    ifstream file(filename);

    if (!file.is_open()) {
        cout << "Could not open file " << filename << endl;
        return courses;
    }

    string line;
    while (getline(file, line)) {
        stringstream stream(line);
        string courseNumber, courseName, prereq;

        getline(stream, courseNumber, ',');
        getline(stream, courseName, ',');

        Course course;
        course.courseNumber = courseNumber;
        course.courseName = courseName;

        while (getline(stream, prereq, ',')) {
            course.prerequisites.push_back(prereq);
        }

        courses.push_back(course);
    }

    file.close();
    return courses;
}

// Main function
int main() {
    TreeNode* root = nullptr;
    vector<Course> courses;
    string filename;
    int choice;

    do {
        cout << "Menu Options:" << endl;
        cout << "1. Load data" << endl;
        cout << "2. Print course list" << endl;
        cout << "3. Print course information" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the course data file name: ";
            cin >> filename;
            courses = loadDataFromFile(filename);
            for (Course course : courses) {
                root = insertCourse(root, course);
            }
            break;
        case 2:
            printCoursesInOrder(root);
            break;
        case 3:
            cout << "Enter course number: ";
            cin >> filename;  // Reusing filename variable to get course number
            printCourseInfo(root, filename);
            break;
        case 9:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
