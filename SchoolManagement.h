// school_management.h
#pragma once

#include <iostream>
#include <string>
#include "Admin.h" // Include the necessary header file for Admin

class SchoolManagement {
public:
    // Flag to track admin authentication status
    bool adminAuth = false;
    /*
    * @brief Function to display the main menu
    */
    void centerText(const std::string& text);
    /*
    * @brief Function to authenticate the admin
    */
    void AuthenticateAdmin();
    /*
    * @brief Function to display the school menu
	*/
    void SchoolMenu();
    /*
    * @brief Function to display the student menu
    */
    void StudentMenu();
    /*
    * @brief Function to display the instructor menu
    */
    void InstructorMenu();
    /*
    * @brief Function to display the main menu
    */
    void MainMenu();
    /*
    * @brief Function to add new student
	*/
    void AddStudent();
    /*
    * @brief Function to add new instructor
    */
    void AddInstructor();
    /*
    * @brief Function to add new course
    */
    void AddCourse();
    /*
    * @brief Function to delete student
    */
    void deleteStudent();
    /*
    * @brief Function to delete instructor
    */
    void deleteInstructor();
    /*
    * @brief Function to delete course
    */
    void deleteCourse();
    /*
    * @brief Function to add course for chosen student
	*/
    void editCourseForStudent();
    /*
    * @brief Function to add course for chosen instructor
    */
    void editCourseForInstructor();
    /*
    * @brief Function to delete course for chosen student
    */
    void StudentDeleteCourse();
    /*
    * @brief Function to delete course for chosen instructor
    */
    void InstructorDeleteCourse();
    /*
    * @brief Function to view profile of chosen student
    */
    void viewProfileStudent();
    /*
    * @brief Function to view profile of chosen instructor
    */
    void viewProfileInstructor();
    /*
    * @brief Function to display all the students
    */
    void viewStudents();
    /*
    * @brief Function to display all the instructors
    */
    void viewInstructors();
    /*
    * @brief Function to display all the courses
    */
    void viewCourses();

private:
    Admin admin; // Instance of the Admin class

    
};

