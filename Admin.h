#pragma once
#include "Student.h"
#include "Instructor.h"
#include "Course.h"
/**
* @brief Admin class
* @type {string} username Username of the admin
* @type {string} password Password of the admin
* @type {vector<Student>} students List of students
* @type {vector<Instructor>} instructors List of instructors
* @type {vector<Course>} allCourses List of all courses
 */
class Admin {
private:
    std::string username = "admin";
    std::string password = "1";

public:
    std::vector<Student> students;
    std::vector<Instructor> instructors;
    static std::vector<Course> allCourses;

    /**
    * @brief Construct a new Admin object
    *
    * @param {string} uname Username of the admin
    * @param {string} pwd Password of the admin
    */
    Admin();

    /**
    * @brief add a new course to the list of all courses
    * @param {Course} newCourse the new course that the admin wants to add
    */
    static void addCourse(const Course& newCourse);
    /**
    * @brief add a new student to the list of all students
    * @param {Student} newStudent the new student that the admin wants to add
    */
    void createStudent(Student& newStudent);
    /**
    * @brief add a new instructor to the list of all instructor
    * @param {Instructor} newInstructor the new student that the admin wants to add
    */
    void createInstructor(Instructor& newInstructor);
    /**
     * @brief delete a student from the list of all students
     * @param {int} id the id of the student that the admin wants to delete
     */
    void deleteStudent(int id);
    /**
     * @brief delete a instructor from the list of all instructor
     * @param {int} id the id of the instructor that the admin wants to delete
     */
    void deleteInstructor(int id);
/**
	 * @brief delete a course from the list of all courses
	 * @param {int} id the id of the course that the admin wants to delete
	 */
    void deleteCourse(int id);
    /**
    * @brief view all students
    */
    void viewAllStudents();
    /**
    * @brief view all instructors
    */
    void viewAllInstructors();
    /**
    * @brief view all courses
    */
    void viewAllCourses();
    /**
    * @brief authenticate the admin
    * @param {string} uname the username of the admin
    * @param {string} pwd the password of the admin
    * @return {bool} true if the admin is authenticated, false otherwise
    */

    bool authenticate(std::string uname, std::string pwd);

    /**
    * @brief find a student by id
    * @param {int} id the id of the student that the admin wants to find
    * @return {Student*} the pointer to the student if found, nullptr otherwise
    */
    Student* findStudent(int id);

    /**
    * @brief find an instructor by id
    * @param {int} id the id of the instructor that the admin wants to find
    * @return {Instructor*} the pointer to the instructor if found, nullptr otherwise
    */
    Instructor* findInstructor(int id);
    /**
    * @brief find a course by id
    * @param {int} id the id of the course that the admin wants to find
    * @return {Instructor*} the pointer to the course if found, nullptr otherwise
    */
    Course* findCourse(int id);
};
