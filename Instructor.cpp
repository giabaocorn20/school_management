#include "Instructor.h"
#include "Admin.h"
#include <iostream>

Instructor::Instructor(int id, std::string name, int age, std::string credentials)
    : PersonnelInterface(id, name, age), credentials(credentials) {}

void Instructor::updateCourse(const Course& newCourse) {
    taughtCourses.push_back(newCourse);
    std::cout << name << " Teach course: " << newCourse.name << ".\n";
    Admin::addCourse(newCourse);
}
void Instructor::deleteCourse(int courseId) {
    auto remove_list = std::remove_if(taughtCourses.begin(), taughtCourses.end(),
        [courseId](const Course& course) { return course.courseId == courseId; });

    if (remove_list != taughtCourses.end()) {
        taughtCourses.erase(remove_list, taughtCourses.end());
        std::cout << name << "'s course with ID " << courseId << " deleted.\n";
    }
    else {
        std::cout << name << " doesn't teach in a course with ID " << courseId << ".\n";
    }
}
void Instructor::displaceProfile(){
    std::cout << "Instructor: " << name << "- id: " << id << "- age: " << age << "- credentials: " << credentials << ":\n";
    std::cout << "Courses of " << name << ":\n";
    for (const Course& course : taughtCourses) {
        std::cout << "- " << course.name << ".\n";
    }
}

