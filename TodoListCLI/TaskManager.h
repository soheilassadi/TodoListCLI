#pragma once
#include "Task.h"
#include <iostream>
#include <memory>
#include <vector>

class TaskManager
{
	std::vector<std::unique_ptr<Task>> tasks;

public:
	void AddTask(const std::string&);
	void ShowTasks() const;
	void RemoveTask(size_t);
};

