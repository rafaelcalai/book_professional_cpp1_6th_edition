#include <iostream>
#include "../src/Employee.hpp"

int main()
{
    std::cout << "Testing The Employee Class!" << std::endl;
    Records::Employee emp { "Jane", "Doe"};
    emp.setFirstName("John");
    emp.setLastName("Doe");
    emp.setEmployeeNumber(312459756);
    emp.setSalary(50'000); 
    emp.promote();
    emp.promote(50);
    emp.hire();
    emp.display();
}

