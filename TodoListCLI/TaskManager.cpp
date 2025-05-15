#include "TaskManager.h"

TaskManager::TaskManager()
{
	if (sqlite3_open("tasks.db", &db) != SQLITE_OK)
	{
		std::cerr << "Error openning database!\n";
	}
}

TaskManager::~TaskManager()
{
	sqlite3_close(db);
}

void TaskManager::CreateTable()
{
	const char *sql = "CREATE TABLE IF NOT EXISTS tasks (id INTEGER PRIMARY KEY, description TEXT);";
	sqlite3_exec(db, sql, nullptr, nullptr, nullptr);
}

void TaskManager::AddTask(const std::string &desc)
{
	std::string sql = "INSERT INTO tasks (description) VALUES (?);";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
	{
		std::cerr << "Failed to prepare statement!\n";
		return;
	}
	sqlite3_bind_text(stmt, 1, desc.c_str(), -1, SQLITE_STATIC);

	if (sqlite3_step(stmt) != SQLITE_DONE)
	{
		std::cerr << "Failed to insert task!\n";
	}
	else
	{
		std::cout << "Task added successfully!\n";
	}

	sqlite3_finalize(stmt);
}

void TaskManager::ShowTasks() const
{
	std::string sql = "SELECT id, description FROM tasks;";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
	{
		std::cerr << "Failed to prepare statement!\n";
		return;
	}

	std::cout << "\nTo-Do List:\n";

	while (sqlite3_step(stmt) == SQLITE_ROW)
	{
		int id = sqlite3_column_int(stmt, 0);
		const char *desc = reinterpret_cast<const char *>(sqlite3_column_text(stmt, 1));

		std::cout << id << ". " << desc << "\n";
	}

	sqlite3_finalize(stmt);
}

void TaskManager::RemoveTask(int taskId)
{
	std::string sql = "DELETE FROM tasks WHERE id = ?;";
	sqlite3_stmt *stmt;

	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
	{
		std::cerr << "Failed to prepare delete statement!\n";
		return;
	}
	sqlite3_bind_int(stmt, 1, taskId);

	if (sqlite3_step(stmt) != SQLITE_DONE)
	{
		std::cerr << "Failed to delete task!\n";
	}
	else
	{
		std::cout << "Task removed successfully!\n";
	}

	sqlite3_finalize(stmt);
}