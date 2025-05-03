#include <iostream>
#include "Database.hpp"
#include "Employee.hpp"

using namespace Records;

int displayMenu();
void doHire(Database& db);
void doFire(Database& db);
void doPromote(Database& db);

int main()
{
    Database employeeDatabase;
    bool done { false };

    while(!done)
    {
        int selection { displayMenu() };
        switch (selection)
        {
            case 0:
                done = true;
                break;
            case 1:
                doHire(employeeDatabase);
                break;
            case 2:
                doFire(employeeDatabase);
                break;
            case 3:
                doPromote(employeeDatabase);
                break;
            case 4:
                employeeDatabase.displayAll();
                break;
            case 5:
                employeeDatabase.displayCurrent();
                break;
            case 6:
                employeeDatabase.displayFormer();
                break;
            default:
                std::cerr << "Unknown command" << std::endl;
                break;
        }
    }
    return 0;
}

int displayMenu()
{
    int selection;
    std::cout << std::endl;
    std::cout << "Employee Database" << std::endl;
    std::cout << "-------------------------" << std::endl;
    std::cout << "1) Hire a new employee" << std::endl;
    std::cout << "2) Fire an employee" << std::endl;
    std::cout << "3) Promote an employee" << std::endl;
    std::cout << "4) List all employees" << std::endl;
    std::cout << "5) List current employees" << std::endl;
    std::cout << "6) List former employees" << std::endl;
    std::cout << "0) Quit" << std::endl << std::endl;
    std::cout << "----> ";
    std::cin >> selection;
    
    return selection;
}

void doHire(Database& db)
{
    std::string firstname;
    std::string lastName;

    std::cout << "First name?  ";
    std::cin >> firstname;

    std::cout << "Last name?  ";
    std::cin >> lastName;

    auto& employee { db.addEmployee(firstname, lastName) };
    std::cout << "Hired employee " << firstname << " " << lastName << " with employee number "
        << employee.getEmployeeNumber() << std::endl;
}

void doFire(Database& db)
{
    int employeeNumber;
    std::cout << "Employee number?   ";
    std::cin >> employeeNumber;

    try 
    {
        auto& emp { db.getEmployee(employeeNumber) };
        emp.fire();
        std::cout << "Employee " << employeeNumber << " terminated" << std::endl;
    }
    catch (const std::logic_error& exception)
    {
        std::cerr << "Unable to terminate employee " << employeeNumber << exception.what() << std::endl;
    }
}

void doPromote(Database& db)
{
    int employeeNumber;
    std::cout << "Employee number?   ";
    std::cin >> employeeNumber;

    int raiseAmount;
    std::cout << "How much of a raise?   ";
    std::cin >>raiseAmount;

    try 
    {
        auto& emp { db.getEmployee(employeeNumber) };
        emp.promote(raiseAmount);
        std::cout << "Employee " << employeeNumber << " received a raise of " << raiseAmount << std::endl;
    }
    catch (const std::logic_error& exception)
    {
        std::cerr << "Unable to promote employee " << employeeNumber << exception.what() << std::endl;
    }
}