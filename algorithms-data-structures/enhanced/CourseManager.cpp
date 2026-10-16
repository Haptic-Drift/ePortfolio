// CourseManager.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>  // for max() use...

// ### 9-24-2026 ###
// CS 499 Algorithms and Data Structures Enhancement
// The original binary search tree was enhanced to use AVL balancing.
// Course prerequisite relationships are also validated before insertion.

using namespace std;

// A structure to represent a Course
struct Course {
    string courseNumber;
    string courseName;
    vector<string> prerequisites;
};

// A structure to represent a node in an AVL Tree
struct TreeNode {
    Course course;
    TreeNode* left;
    TreeNode* right;
    int height;
    TreeNode(Course c) : course(c), left(nullptr), right(nullptr), height(1) {}
};

// A small helper function to ask "What is the height of this node?"
int getHeight(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    return node->height;
}

// A way to determine whether a node is leaning too far left or right
int getBalanceFactor(TreeNode* node) {
    if (node == nullptr) {
        return 0;
    }

    return getHeight(node->left) - getHeight(node->right);
}

// A function to perform a right rotation to rebalance a left-heavy subtree
TreeNode* rotateRight(TreeNode* node) {
    TreeNode* newRoot = node->left;
    TreeNode* movedSubtree = newRoot->right;

    newRoot->right = node;
    node->left = movedSubtree;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// A function to perform a left rotation to rebalance a right-heavy subtree
TreeNode* rotateLeft(TreeNode* node) {
    TreeNode* newRoot = node->right;
    TreeNode* movedSubtree = newRoot->left;

    newRoot->left = node;
    node->right = movedSubtree;

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    newRoot->height = 1 + max(getHeight(newRoot->left), getHeight(newRoot->right));

    return newRoot;
}

// A function to insert a course into the AVL Tree
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

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    int balanceFactor = getBalanceFactor(node);

    // Left-left case
    if (balanceFactor > 1 && course.courseNumber < node->left->course.courseNumber) {
        return rotateRight(node);
    }

    // Right-right case
    if (balanceFactor < -1 && course.courseNumber > node->right->course.courseNumber) {
        return rotateLeft(node);
    }

    // Left-right case
    if (balanceFactor > 1 && course.courseNumber > node->left->course.courseNumber) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }

    // Right-left case
    if (balanceFactor < -1 && course.courseNumber < node->right->course.courseNumber) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
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

// A function to check whether a course number exists in the loaded course data
bool courseExists(const vector<Course>& courses, const string& courseNumber) {
    for (const Course& course : courses) {
        if (course.courseNumber == courseNumber) {
            return true;
        }
    }

    return false;
}

// A function to validate that all prerequisite courses exist in the loaded course data
bool validatePrerequisites(const vector<Course>& courses) {
    bool isValid = true;

    for (const Course& course : courses) {
        for (const string& prerequisite : course.prerequisites) {
            if (!courseExists(courses, prerequisite)) {
                cout << "Validation error: " << prerequisite
                    << " is listed as a prerequisite for "
                    << course.courseNumber
                    << " but does not exist in the course data." << endl;

                isValid = false;
            }
        }
    }

    return isValid;
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

            if (validatePrerequisites(courses)) {
                for (Course course : courses) {
                    root = insertCourse(root, course);
                }

                cout << "Course data loaded successfully." << endl;
            }
            else {
                cout << "Course data was not loaded due to validation errors." << endl;
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