#include <iostream>
#include <windows.h>
#include "SchoolManagement.h"

void SchoolManagement::centerText(const std::string& text) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Get the console handle.
    PCONSOLE_SCREEN_BUFFER_INFO lpScreenInfo = new CONSOLE_SCREEN_BUFFER_INFO(); // Create a pointer to the Screen Info pointing to a temporal screen info.
    GetConsoleScreenBufferInfo(hConsole, lpScreenInfo); // Saves the console screen info into the lpScreenInfo pointer.
    COORD NewSBSize = lpScreenInfo->dwSize; // Gets the size of the screen
    if (NewSBSize.X > text.size()) {
        int newpos = ((NewSBSize.X - text.size()) / 2); // Calculate the number of spaces to center the specific text.
        for (int i = 0; i < newpos; i++) std::cout << " "; // Prints the spaces
    }
    std::cout << text << std::endl;// Prints the text
}
void SchoolManagement::AuthenticateAdmin(){
    centerText("WELCOME TO SCHOOL MANAGEMENT PROGRAM\n");

    // Ask for a password in the console
    std::cout << "Enter your password: ";
    std::string enteredPassword;
    std::getline(std::cin, enteredPassword);

    // Authenticate the user
    if (admin.authenticate("admin", enteredPassword)) {
        centerText( "Login successful. Welcome, admin!\n");
        adminAuth = true;
        // Proceed to the main application or perform other actions
    }
    else {
        centerText("Login failed. Invalid password. Please try again.\n");
        adminAuth = false;
    }
}

void SchoolManagement::MainMenu() {
    while (true) {
        centerText("\nMain Menu:\n");
        centerText("1. School Menu\n");
        centerText("2. Student Menu\n");
        centerText("3. Instructor Menu\n");
        centerText("0. Exit\n");

        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            // Call the SchoolMenu function
            SchoolMenu();
        }
        else if (choice == "2") {
            // Call the StudentMenu function
            StudentMenu();
        }
        else if (choice == "3") {
            // Call the InstructorMenu function
            InstructorMenu();
        }
        else if (choice == "0") {
            std::cout << "Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void SchoolManagement::SchoolMenu() {
    while (true) {
        centerText("\nSchool Menu:\n");
        centerText("1. Add Student\n");
        centerText("2. Add Instructor\n");
        centerText("3. Add Course\n");
        centerText("4. View All Students\n");
        centerText("5. View All Instructors\n");
        centerText("6. View All Courses\n");
        centerText("0. Exit\n");
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            AddStudent();
        }
        else if (choice == "2") {
            AddInstructor();
        }
        else if (choice == "3") {
            AddCourse();
        }
        else if (choice == "4") {
            viewStudents();
        }
        else if (choice == "5") {
            viewInstructors();
        }
        else if (choice == "6") {
            viewCourses();
        }
        else if (choice == "0") {
            MainMenu();
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void SchoolManagement::StudentMenu() {
    while (true) {
        centerText("Student Menu\n");
        centerText("1. Enroll in a Course\n");
        centerText("2. Drop a Course\n");
        centerText("3. View Profile\n");
        centerText("0. Go Back to Main Menu\n");
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            editCourseForStudent();
        }
        else if (choice == "2") {
            StudentDeleteCourse();
        }
        else if (choice == "3") {
            viewProfileStudent();
        }
        else if (choice == "0") {
            MainMenu();
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void SchoolManagement::InstructorMenu() {
    while (true) {
        centerText("Instructor Menu\n");
        centerText("1. Assign Course to Teach\n");
        centerText("2. Remove Course Assignment\n");
        centerText("3. View Profile\n");
        centerText("0. Go Back to Main Menu\n");
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            editCourseForInstructor();
        }

        else if (choice == "2") {
            InstructorDeleteCourse();
        }
        else if (choice == "3") {
            viewProfileInstructor();
        }
        else if (choice == "0") {
            MainMenu();
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}




void  SchoolManagement::AddStudent() {
    std::cout << "Enter Student's ID: ";
    std::string idString;
    std::getline(std::cin, idString);
    int id = std::stoi(idString);

    std::cout << "Enter Student's Name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter Student's Age: ";
    std::string ageString;
    std::getline(std::cin, ageString);
    int age = std::stoi(ageString);
  
    Student student(id, name, age);

    admin.createStudent(student);
}

void  SchoolManagement::AddInstructor() {
    std::cout << "Enter Instructor's ID: ";
    std::string idString;
    std::getline(std::cin, idString);
    int id = std::stoi(idString);

    std::cout << "Enter Instructor's Name: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Enter Instructor's Age: ";
    std::string ageString;
    std::getline(std::cin, ageString);
    int age = std::stoi(ageString);

    std::cout << "Enter Instructor's Credential: ";
    std::string credentials;
    std::getline(std::cin, credentials);

    Instructor instructor(id, name, age, credentials);

    admin.createInstructor(instructor);
}

void  SchoolManagement::AddCourse() {
	std::cout << "Enter Course's ID: ";
	std::string idString;
	std::getline(std::cin, idString);
	int id = std::stoi(idString);

	std::cout << "Enter Course's Name: ";
	std::string name;
	std::getline(std::cin, name);

	Course course(name, id);

	admin.addCourse(course);
}

void  SchoolManagement::deleteStudent() {
    std::cout << "Enter Student's ID: ";
    std::string studentIdString;
    std::getline(std::cin, studentIdString);
    int studentId = std::stoi(studentIdString);

    admin.deleteStudent(studentId);
}

void  SchoolManagement::deleteInstructor() {
    std::cout << "Enter Instructor's ID: ";
    std::string instructorIdString;
    std::getline(std::cin, instructorIdString);
    int instructorId = std::stoi(instructorIdString);

    admin.deleteInstructor(instructorId);
}

void  SchoolManagement::deleteCourse() {
	std::cout << "Enter Course's ID: ";
	std::string courseIdString;
	std::getline(std::cin, courseIdString);
	int courseId = std::stoi(courseIdString);

	admin.deleteCourse(courseId);
}

void  SchoolManagement::editCourseForStudent() {
    std::cout << "Enter Student's ID: ";
    std::string studentIdString;
    std::getline(std::cin, studentIdString);
    int studentId = std::stoi(studentIdString);

    std::cout << "Enter Course's ID: ";
    std::string courseIdString;
    std::getline(std::cin, courseIdString);
    int courseId = std::stoi(courseIdString);

    Student* foundStudent = admin.findStudent(studentId);
    Course* foundCourse = admin.findCourse(courseId);

    foundStudent->updateCourse(*foundCourse);
}

void  SchoolManagement::editCourseForInstructor() {
    std::cout << "Enter Student's ID: ";
    std::string studentIdString;
    std::getline(std::cin, studentIdString);
    int studentId = std::stoi(studentIdString);

    std::cout << "Enter Course's ID: ";
    std::string courseIdString;
    std::getline(std::cin, courseIdString);
    int courseId = std::stoi(courseIdString);

    Instructor* foundInstructor = admin.findInstructor(studentId);
    Course* foundCourse = admin.findCourse(courseId);

    foundInstructor->updateCourse(*foundCourse);
}

void SchoolManagement::StudentDeleteCourse() {
	std::cout << "Enter Student's ID: ";
	std::string studentIdString;
	std::getline(std::cin, studentIdString);
	int studentId = std::stoi(studentIdString);

	std::cout << "Enter Course's ID: ";
	std::string courseIdString;
	std::getline(std::cin, courseIdString);
	int courseId = std::stoi(courseIdString);

	Student* foundStudent = admin.findStudent(studentId);
	Course* foundCourse = admin.findCourse(courseId);

	foundStudent->deleteCourse(courseId);
}

void SchoolManagement::InstructorDeleteCourse() {
	std::cout << "Enter Instructor's ID: ";
	std::string instructorIdString;
	std::getline(std::cin, instructorIdString);
	int instructorId = std::stoi(instructorIdString);

	std::cout << "Enter Course's ID: ";
	std::string courseIdString;
	std::getline(std::cin, courseIdString);
	int courseId = std::stoi(courseIdString);

	Instructor* foundInstructor = admin.findInstructor(instructorId);
	Course* foundCourse = admin.findCourse(courseId);

	foundInstructor->deleteCourse(courseId);
}
void SchoolManagement::viewProfileStudent() {
	std::cout << "Enter Student's ID: ";
	std::string studentIdString;
	std::getline(std::cin, studentIdString);
	int studentId = std::stoi(studentIdString);

	Student* foundStudent = admin.findStudent(studentId);

	foundStudent->displaceProfile();
}

void  SchoolManagement::viewProfileInstructor() {
	std::cout << "Enter Instructor's ID: ";
	std::string instructorIdString;
	std::getline(std::cin, instructorIdString);
	int instructorId = std::stoi(instructorIdString);

	Instructor* foundInstructor = admin.findInstructor(instructorId);

	foundInstructor->displaceProfile();
}

void  SchoolManagement::viewStudents() {
	admin.viewAllStudents();
}
void  SchoolManagement::viewInstructors() {
    admin.viewAllInstructors();
}

void  SchoolManagement::viewCourses() {
    admin.viewAllCourses();
}
