#ifdef _WIN32
#include "..\..\src\Win32_Interop\win32fixes.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>

#include <hiredis.h>
#include <async.h>
#include <adapters\ae.h>

#include "job.h"



void tx_open(struct TinyXmlAdapter* p, const char *fileName);
struct TinyXmlAdapter *tx_create();
void tx_destory(struct TinyXmlAdapter* p);
struct TiXmlDocument *tx_load(const char *fileName);

extern  int logReg(int argc, char **argv);
extern  void logInfo(const char *format, ...);
extern  void logDebug(const char *format, ...);
extern void logError(const char *format, ...);

/* Put event loop in the global scope, so it can be explicitly stopped */
static aeEventLoop *loop;
static jobContext *g_jobContext;

void getCallback(redisAsyncContext *c, void *r, void *privdata) {
    redisReply *reply = r;
    if (reply == NULL) return;
    printf("argv[%s]: %s\n", (char*)privdata, reply->str);

    /* Disconnect after receiving the reply to GET */
   // redisAsyncDisconnect(c);
}

void connectCallback(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        printf("Error: %s\n", c->errstr);
        aeStop(loop);
        return;
    }

    //printf("Connected...\n");
	logInfo("Connected...");
}

void disconnectCallback(const redisAsyncContext *c, int status) {
    if (status != REDIS_OK) {
        printf("Error: %s\n", c->errstr);
        aeStop(loop);
        return;
    }

    printf("Disconnected...\n");
}

void onPopTask(redisAsyncContext *c, void *r, void *privdata) {
	redisReply *reply = r;
	if (reply && reply->str) {
		for (int j = 0; j < reply->elements; j++) {
			printf("%u) %s\n", j, reply->element[j]->str);
		}
		if (reply)
			freeReplyObject(reply);
	}
	
}



void processTask(redisContext *c, const char *task) {
	redisReply *reply = redisCommand(c, "PUBLISH stateEstimateResponseTopic %s", task);
	freeReplyObject(reply);
}

void asyncProcessTask(redisAsyncContext *c, const char *task) {
	redisAsyncCommand(c, NULL, NULL, "PUBLISH stateEstimateResponseTopic %s", task);

}



void processTasks() {
	
	redisContext *c = redisConnect("127.0.0.1", 10001);
	if (c == NULL || c->err) {
		if (c) {
			printf("Error: %s\n", c->errstr);
			// handle error
		}
		else {
			printf("Can't allocate redis context\n");
		}
	}

	redisReply *reply = NULL;
	int i = 0;
	do {
		reply = redisCommand(c, "LPOP RTS79:task:0:queue");
		if (reply == NULL) {
			return;
		}
		else if (reply->type == REDIS_REPLY_ERROR) {
			printf("Error: %s\n", reply->str ? reply->str : "error");
			freeReplyObject(reply);
			return;
		}
			
		//if (reply->type == REDIS_REPLY_ARRAY) {
		//	for (int j = 0; j < reply->elements; j++) {
		//		i++;
		//		printf("%u) %s\n", i, reply->element[j]->str);
		//		//processTask(c, reply->element[j]->str);

		//		
		//	}
		//}
		//else 
			if (reply->type == REDIS_REPLY_STRING) {
			//printf("%d) Task: %s\n",i++, reply->str);
			printf("%d) Task\n", i++);
			//processTask(c, reply->str);
			
		}
		else if (reply->type == REDIS_REPLY_NIL) {
			printf("Task finished.");
			freeReplyObject(reply);
			break;
		}


		freeReplyObject(reply);
	} while (1);

	redisFree(c);
}

extern  struct StateEstimate *createCalculator(const char *settingStr, void(*send_func)(const char *));
extern  void freeCalculator(struct StateEstimate *se);
extern  void configCalculator(struct StateEstimate *se, const char *settingStr);
extern  void runSample(struct StateEstimate *se, const char *sampleStr);


struct StateEstimate *se = NULL;
void sendResponsMessage(const char *msg) {
	processTask(g_jobContext->context, msg);
}
void onStartStateEstimate(redisAsyncContext *c, void *reply, void *privdata) {
	redisReply *r = reply;
	jobContext *jc = privdata;

	if (r->type == REDIS_REPLY_ARRAY) {
		if (r->elements == 3 && r->element[2]->str != NULL) {
			const char * msg = r->element[2]->str;
			jc->count = 0;
			//redisCommand(jc->context, "PUBLISH replyStateEstimateTopic %s", msg);

			if (se == NULL) {
				se = createCalculator(msg, sendResponsMessage);
			}
			
			configCalculator(se, msg);
			
			
			//processTasks();
		}
	}

}
//extern void se_func();


void onStateEstimate(redisAsyncContext *c, void *reply, void *privdata) {
	jobContext *jc = privdata;
	redisReply *r = reply;
	if (reply == NULL) return;


	if (r->type == REDIS_REPLY_ARRAY) {

		if (r->elements == 3 && r->element[2]->str != NULL) {
			const char * msg = r->element[2]->str;
			//logInfo(msg);
			//if (!strcmp(msg, "start")) {
			//	count = 0;
			//} else if (!strcmp(msg, "stop")) {
			//	count = 0;
			//}
			//else {
				//processTasks();
				//printf("%u) %s\n", jc->count++, "task");
				//processTask(jc->context, msg);
				runSample(se, msg);
				//struct TinyXmlAdapter *t = tx_create();
				
				//asyncProcessTask(c, msg);
				//se_func();
			//}
		}

		
	}
}
void onMessage(redisAsyncContext *c, void *reply, void *privdata) {
	redisReply *r = reply;
	if (reply == NULL) return;

	if (r->type == REDIS_REPLY_ARRAY) {
		for (int j = 0; j < r->elements; j++) {
			

			printf("%u) %s\n", j, r->element[j]->str);
		}
	}
}
void onClose(redisAsyncContext *c, void *reply, void *privdata) {
	redisReply *r = reply;
	if (reply == NULL) return;

	if (r->type == REDIS_REPLY_ARRAY) {
		for (int j = 0; j < r->elements; j++) {

			if (j == 2 && r->element[j]->str) {
				printf("exit");
				exit(0);
			}
			printf("%u) %s\n", j, r->element[j]->str);
        }
	}
}


int main (int argc, char **argv) {
	logReg(argc, argv);
#ifndef _WIN32
	signal(SIGPIPE, SIG_IGN);
#endif
	//struct TinyXmlAdapter *tx = tx_create();
//	struct TiXmlDocument *doc = tx_load("E:/data/RTS79/RSResult.xml");

#ifdef _WIN32
	/* For Win32_IOCP the event loop must be created before the async connect */
	loop = aeCreateEventLoop(1024 * 10);
#endif


	const char *address = "127.0.0.1";
	if (argc > 1)
		address = argv[1];

	int port = 10001;
	if (argc > 2)
		port = atoi(argv[2]);

	//const char address[] = "192.168.1.50";
	//int port = 7000;

	printf("connect to %s, p = %d. \n", address, port);
	redisAsyncContext *c = redisAsyncConnect(address, port);
	
    if (c->err) {
        /* Let *c leak for now... */
        printf("Error: %s\n", c->errstr);
        return 1;
    }

	jobContext jc;
	g_jobContext = &jc;
	jc.context = redisConnect(address, port);
	jc.count = 0;
	if (jc.context == NULL || jc.context->err) {
		if (jc.context) {
			printf("Error: %s\n", jc.context->errstr);
			// handle error
		}
		else {
			printf("Can't allocate redis context\n");
		}
    }

#ifndef _WIN32
    loop = aeCreateEventLoop(64);
#endif
    redisAeAttach(loop, c);
    redisAsyncSetConnectCallback(c,connectCallback);
    redisAsyncSetDisconnectCallback(c,disconnectCallback);
   // redisAsyncCommand(c, NULL, NULL, "SET key %b", argv[argc-1], strlen(argv[argc-1]));
 ///   redisAsyncCommand(c, getCallback, (char*)"end-1", "GET key");
//	redisAsyncCommand(c, onMessage, NULL, "SUBSCRIBE testtopic");
//	redisAsyncCommand(c, onClose, NULL, "SUBSCRIBE exittopic");
	redisAsyncCommand(c, onStateEstimate, &jc, "SUBSCRIBE stateEstimateTopic");
	redisAsyncCommand(c, onStartStateEstimate, &jc, "SUBSCRIBE startStateEstimateTopic");
	//redisAsyncCommand(c, onPopTask, NULL, "LPOP RTS79:task:0:queue");
    aeMain(loop);
    return 0;
}

