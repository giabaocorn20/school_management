#include "Admin.h"
#include <iostream>
#include <vector>
#include <algorithm>

Admin::Admin() {}
std::vector<Course> Admin::allCourses;
void Admin::addCourse(const Course& newCourse) {
    for (const Course& course : allCourses) {
        if (course.courseId == newCourse.courseId) {
            return;
        }
    }
    allCourses.push_back(newCourse);
}

void Admin::createStudent(Student& newStudent) {
    students.push_back(newStudent);
}

void Admin::createInstructor(Instructor& newInstructor) {
    instructors.push_back(newInstructor);
}

void Admin::deleteStudent(int id) {
    auto remove_list = remove_if(students.begin(), students.end(), [id](const Student& student) { return student.id == id; });
    if (remove_list != students.end()) {
        students.erase(remove_list, students.end());
        std::cout  << " student with ID " << id << " deleted.\n";
    }
    else {
        std::cout  << " There is no student with ID " << id << ".\n";
    }
}
void Admin::deleteInstructor(int id) {
    auto remove_list = remove_if(instructors.begin(), instructors.end(), [id](const Instructor& instructor) { return instructor.id == id; });
    if (remove_list != instructors.end()) {
        instructors.erase(remove_list, instructors.end());
        std::cout << " Instructor " << id << " deleted.\n";
    }
    else {
        std::cout  << " There is no instructor with ID " << id << ".\n";
    }
}

void Admin::deleteCourse(int id) {
    auto remove_list = std::remove_if(allCourses.begin(), allCourses.end(), [id](const Course& course) { return course.courseId == id; });
    if (remove_list != allCourses.end()) {
        allCourses.erase(remove_list, allCourses.end());
        for (auto& student : students) {
            student.deleteCourse(id); // Assuming removeCourse method is available in Student class
        }

        for (auto& instructor : instructors) {
            instructor.deleteCourse(id); // Assuming removeCourse method is available in Instructor class
        }
        std::cout << " Course " << id << " deleted.\n";
    }
    else {
        std::cout << " There is no course with ID " << id << ".\n";
    }
}
void Admin::viewAllStudents() {
    std::cout << "All students:\n";
    for (const auto& student : students) {
        std::cout << "- " << student.name << " (ID: " << student.id << ")\n";
        if (!student.enrolledCourses.empty()) {
            std::cout << "  Courses:\n";
            for (const auto& course : student.enrolledCourses) {
                std::cout << "    - " << course.name << " (ID: " << course.courseId << ")\n";
            }
        }
    }
}

void Admin::viewAllInstructors() {
    std::cout << "All instructors:\n";
    for (const auto& instructor : instructors) {
        std::cout << "- " << instructor.name << " (ID: " << instructor.id << ")\n";
        if (!instructor.taughtCourses.empty()) {
            std::cout << "  Courses:\n";
            for (const auto& course : instructor.taughtCourses) {
                std::cout << "    - " << course.name << " (ID: " << course.courseId << ")\n";
            }
        }
    }
}

void Admin::viewAllCourses() {
    std::cout << "All courses:\n";
    for (const Course& course : allCourses) {
        std::cout << "Course: " << course.name << ", ID: " << course.courseId << "\n";
    }
}

bool Admin::authenticate(std::string uname, std::string pwd) {
	if (uname == username && pwd == password) {
        std::cout << "Welcome " << username << "\n";
        return true;
	}
	else {
        std::cout << "Invalid username or password" << "\n";
        return false;
	}
}

Student* Admin::findStudent(int id) {
	for (auto& student : students) {
		if (student.id == id) {
            std::cout << "Student found: " << student.name << "\n";
			return &student;
		}
	}
    std::cout << "Student not found" << "\n";
    return nullptr;
}

Instructor* Admin::findInstructor(int id) {
    for (auto& instructor : instructors) {
        if (instructor.id == id) {
            std::cout << "Instructor found: " << instructor.name << std::endl;
            return &instructor;
        }
    }
    std::cout << "Student not found" << std::endl;
    return nullptr;  // Return nullptr if student is not found
}

Course* Admin::findCourse(int id) {
    for (auto& course : allCourses) {
        if (course.courseId == id) {
            std::cout << "Course found: " << course.name << std::endl;
            return &course;
        }
    }
    std::cout << "Course not found" << std::endl;
    return nullptr;
}

