#include <iostream>
#include "../src/Database.hpp"

using namespace Records;

int main()
{
    std::cout << "Testing The Database Class!" << std::endl;
    Database myDB;
    Employee employeeOne { myDB.addEmployee("Greg", "Wallis")};
    employeeOne.fire();

    Employee employeeTwo { myDB.addEmployee("Marc", "White")};
    employeeTwo.setSalary(100'000);

    Employee employeeThree { myDB.addEmployee("John", "Doe")};
    employeeThree.setSalary(10'000);
    employeeThree.promote();

    std::cout << "Print all employees" << std::endl;
    myDB.displayAll();

    std::cout << "Print current employees" << std::endl;
    myDB.displayCurrent();

    std::cout << "Print former employees" << std::endl;
    myDB.displayFormer();
}