#pragma once
#include "PersonnelInterface.h"

/**
* @brief Instructor class extends from PersonnelInterface class that stores the id, name and age of a instructor
* @type {string} credentials Credentials of the instructor
* @type {vector<Course>} taughtCourses Courses that the instructor teaches
*/
class Instructor : public PersonnelInterface {
public:
    /**
     * @brief Construct a new Instructor object
     *
     * @param {int} id ID of the instructor
     * @param {string} name Name of the instructor
     * @param {int} age Age of the instructor
     * @param {string} credentials Credentials of the instructor
     */
    std::string credentials;
    std::vector<Course> taughtCourses;
    Instructor(int id, std::string name, int age, std::string credentials);
    
    /**
    * @brief update the course of the instructor teaches 
    * @type  {Course} newCourse the new course that the instructor teaches
    */
    void updateCourse(const Course& newCourse) override;

    /**
    * @brief delete the course of the instructor teaches
    * @param {int} courseId the id of the course that the instructor teaches
    */
    void deleteCourse(int courseId) override;
    /**
   * @brief display the profile of the instructor
   */
    void displaceProfile() override;
};
