#include "SchoolManagement.h"
#include <iostream>

int main() {
    SchoolManagement schoolManagement;

    // Authenticate the admin
    schoolManagement.AuthenticateAdmin();

    // Check if the admin authentication was successful
    if (schoolManagement.adminAuth) {
        // Main menu loop
        schoolManagement.MainMenu();
    }
    else {
        std::cout << "Admin authentication failed. Exiting...\n";
    }

    return 0;
}
