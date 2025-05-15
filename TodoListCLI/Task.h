#pragma once
#include <string>

class Task
{
public:
	std::string description;
	Task(std::string desc) : description(desc) {}
};

