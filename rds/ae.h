#define AE_NONE 0
#define AE_READ 1
#define AE_WRITE 2


typedef void aeFileProcess(struct aeEventLoop *eventLoop, int fd, void *clientData, int mask);

typedef struct aeFileEvent {
    int mask;
    aeFileProcess *readFileProc;
    aeFileProcess *writeFileProc;
    void *client_data;
} aeFileEvent;

typedef struct aeEventLoop {
    int max_fx;
} aeEventLoop;
