#ifndef TASK_CLEAN_STORAGE_H
#define TASK_CLEAN_STORAGE_H

#include <queue>
#include <set>

#include "utility/file/FilePath.h"
#include "utility/scheduling/Task.h"
#include "utility/utility.h"

class Storage;

class TaskCleanStorage
	: public Task
{
public:
	TaskCleanStorage(
		Storage* storage,
		const std::set<FilePath>& filePaths
	);

	virtual void enter();
	virtual TaskState update();
	virtual void exit();

	virtual void interrupt();
	virtual void revert();

private:
	Storage* m_storage;
	std::queue<FilePath> m_filePaths;
	const size_t m_fileCount;

	utility::TimePoint m_start;
};

#endif // TASK_PARSE_CXX_H
