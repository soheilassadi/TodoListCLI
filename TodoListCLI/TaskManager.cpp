#include "TaskManager.h"

void TaskManager::AddTask(const std::string& desc)
{
	tasks.emplace_back(std::make_unique<Task>(desc));
}

void TaskManager::ShowTasks() const
{
	if (tasks.empty())
	{
		std::cout << "No tasks available!\n";
		return;
	}
	std::cout << "To-Do List:\n";
	for (size_t i = 0; i < tasks.size(); i++)
	{
		std::cout << i + 1 << ". " << tasks[i]->description << "\n";
	}
}

void TaskManager::RemoveTask(size_t index)
{
	if (index == 0 || index > tasks.size()) {
		std::cout << "Invalid task number!\n";
		return;
	}
	tasks.erase(tasks.begin() + (index - 1));
	std::cout << "Task removed successfully!\n";
}