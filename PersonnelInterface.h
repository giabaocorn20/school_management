#pragma once
#include "Course.h"
#include <string>

/**
* @brief PersonnelInterface class that stores the id, name and age of a personnel
* @type {int} id ID of the personnel
* @type {string} name Name of the personnel
* @type {int} age Age of the personnel
*/
class PersonnelInterface {
public:
    int id;
    std::string name;
    int age;
    /**
    * @brief Construct a new PersonnelInterface object
    * @param {int} id ID of the personnel
    * @param {string} name Name of the personnel
    * @param {int} age Age of the personnel
    */
    PersonnelInterface(int id, std::string name, int age);
    /**
    * @brief update the course of the personnel teaches/takes
    * @param {Course} course the new course that the personnel teaches/takes
    */
    virtual void updateCourse(const Course& course) = 0;
    /**
    * @brief delete the course of the personnel teaches/takes
    * @param {int} courseId the id of the course that the personnel teaches/takes
    */
    virtual void deleteCourse(int courseId) = 0;
    /**
    * @brief display the course of the personnel teaches/takes
    */
    virtual void displaceProfile() = 0;
};
