#pragma once
#include "Task.h"
#include <sqlite3.h>
#include <iostream>
#include <memory>
#include <vector>

class TaskManager
{
	sqlite3 *db;
	// std::vector<std::unique_ptr<Task>> tasks;

public:
	TaskManager();
	~TaskManager();
	void CreateTable();
	void AddTask(const std::string &);
	void ShowTasks() const;
	void RemoveTask(int);
};
