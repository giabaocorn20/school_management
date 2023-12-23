#include "Student.h"
#include "Admin.h"
#include <iostream>

Student::Student(int id, std::string name, int age) : PersonnelInterface(id, name, age) {}

void Student::updateCourse(const Course& newCourse) {
    enrolledCourses.push_back(newCourse);
    std::cout << name << " Add course: " << newCourse.name << ".\n";
    Admin::addCourse(newCourse);
}

void Student::deleteCourse(int courseId)  {
    auto remove_list = std::remove_if(enrolledCourses.begin(), enrolledCourses.end(),
        [courseId](const Course& course) { return course.courseId == courseId; });

    if (remove_list != enrolledCourses.end()) {
        enrolledCourses.erase(remove_list, enrolledCourses.end());
        std::cout << name << "'s course with ID " << courseId << " deleted.\n";
    }
    else {
        std::cout << name << " is not enrolled in a course with ID " << courseId << ".\n";
    }
}
void Student::displaceProfile()  {
    std::cout << "Student: " << name << "- id: " << id << "- age: " << age << ":\n";
    std::cout << "Courses of " << name << ":\n";
    for (const Course& course : enrolledCourses) {
        std::cout << "- " << course.name << ".\n";
    }
}

