#include "../headers/job.h"
#include <iostream>

Job::Job(FunctionPointer ptr, int priority, bool periodic, std::chrono::system_clock::time_point exec_time, std::chrono::seconds duration):
    _function(ptr),
    _priority(priority), 
    _is_periodic(periodic),
    _start_time(exec_time), 
    _duration(duration)
{}

void Job::execute() const
{
    if (_function) {
        _function();
    } else {
        printf("[ERROR] : Function pointer is null!\n");
    }
}

bool Job::operator<(const Job& job2) const
{
    if (_start_time == job2._start_time) {
        return _priority < job2._priority;
    }
    return _start_time < job2._start_time ? false : true;
}

Job Job::periodic_clone() const {
    return Job(_function, _priority, _is_periodic, std::chrono::system_clock::now() + _duration, _duration);
}