#include "../headers/job.h"
#include <queue>

class Scheduler
{
private:
    std::priority_queue <Job> _jobs;        //  Jobs that in execution queue
    bool _stop_scheduler = false;

public:
    void add_job(Job job);
    void delete_job();
    void start();
    void stop();
};

