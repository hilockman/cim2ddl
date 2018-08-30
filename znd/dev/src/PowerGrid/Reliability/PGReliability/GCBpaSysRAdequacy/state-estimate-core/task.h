#ifndef TASK_HEADER_________________________
#define TASK_HEADER_________________________
class Task
{
public:
	virtual void run() = 0;
	virtual bool isIdle() = 0;
	virtual ~Task() = 0;
};

#endif // !TASK_HEADER_________________________


