#pragma once
#include <vector>
#include <string>
/**
 * @brief Course class that stores the name and id of a course
 **/

class Course {
public:
    std::string name;
    int courseId;
    /**
     * @brief Construct a new Course object
     * 
     * @param string n name of the course
     * @param int id id of the course
     */
    Course(std::string n, int id);
};

extern std::vector<Course> allCourses; // still works if you remove this line. have this to avoiding multiple definitions:

