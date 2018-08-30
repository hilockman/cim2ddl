#ifndef JOB_CONTEXT_HEADER______________________
#define JOB_CONTEXT_HEADER______________________

typedef struct jobContext {
	redisContext *context;
	int count;
} jobContext;

#endif // !JOB_CONTEXT_HEADER______________________
