#include "Task.h"
#include "TaskManager.h"

int main()
{
    TaskManager manager;
    manager.CreateTable(); // Ensuring the database table exists
    int choice;

    while (true)
    {
        std::cout << "\nTo-Do List Manager\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Remove Task\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Prevent newline issues

        if (choice == 1)
        {
            std::string task;
            std::cout << "Enter task description: ";
            std::getline(std::cin, task);
            manager.AddTask(task);
        }
        else if (choice == 2)
        {
            manager.ShowTasks();
        }
        else if (choice == 3)
        {
            manager.ShowTasks();
            std::cout << "Enter task ID to remove: ";
            int taskId;
            std::cin >> taskId;
            manager.RemoveTask(taskId);
        }
        else if (choice == 4)
        {
            std::cout << "Goodbye!\n";
            break;
        }
        else
        {
            std::cout << "Invalid choice, try again!\n";
        }
    }
}