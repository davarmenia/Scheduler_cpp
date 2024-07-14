#include <chrono>
#include <string>
#include <functional>

class Job
{
public:
    using FunctionPointer = std::function<void()>;
    Job(FunctionPointer ptr, int, bool, std::chrono::system_clock::time_point, std::chrono::seconds);
    //  Scheduler will call the exection of job
    virtual void execute() const;
    //  The job must have the < operator defined for the scheduler to compare priority
    bool operator<(const Job &job2) const;
    //  Getting to of start (using in scheduler for sleep_untile)
    virtual std::chrono::system_clock::time_point get_start_time() const { return _start_time; }
    //  Clone job for periodic add
    Job periodic_clone() const;
    void delete_job()               { _deleted = false;     }
    bool get_periodic()     const   { return _is_periodic;  }
    bool get_job_deleted()  const   { return _deleted;      }

private:
    FunctionPointer _function;                              //  Function which job will execute
    int _priority;
    bool _is_periodic;
    std::chrono::system_clock::time_point _start_time;      //  time to start job
    std::chrono::seconds _duration;                         //  duration for periodic job
    bool _deleted = false;                                  //  using to delete job
};
