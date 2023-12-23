#pragma once
#include "PersonnelInterface.h"


/**
* @brief Student class extends from PersonnelInterface class that stores the id, name and age of the Student
* * @type {int} id ID of the instructor
* * @type {string} name Name of the instructor
* * @type {int} age Age of the instructor
* * @type {string} credentials Credentials of the instructor
* * @type {vector<Course>} taughtCourses Courses that the instructor teaches
* */
class Student : public PersonnelInterface {
private:
   

public:
    std::vector<Course> enrolledCourses;
    /**
    * @brief Constructor for the Student class
    * @param {int} id ID of the student
    * @param {string} name Name of the student
    * @param {int} age Age of the student
	*/
    Student(int id, std::string name, int age);
    /**
    * @brief Update the course that the student enrolls
    * @param {Course} newCourse New course that the student enrolls
    */
    void updateCourse(const Course& newCourse) override;
    /**
    * @brief Delete the course that the student enrolls
    * @param {int} id of the course that the student enrolls
    */
    void deleteCourse(int courseId) override;
    /**
    * @brief Update the profile of the student
    */
    void displaceProfile() override;
};
