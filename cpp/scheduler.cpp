#include "../headers/scheduler.h"
#include <chrono>
#include <thread>

void Scheduler::add_job(Job job)
{
    printf("[INFO] : added job\n");
    _jobs.push(job);
}

void Scheduler::delete_job()
{
    if (!_jobs.empty()) {
        _jobs.pop();
        printf("[INFO] : job succesfully deleted\n");
    } else {
        printf("[ERROR] : There are no any job\n");
    }
}

void Scheduler::start()
{
    printf("[INFO] : Starting Scheduler...\n");
    //  Scheduler will call execute all jobs
    for (; !_jobs.empty(); _jobs.pop()) {
        Job current_job = _jobs.top();
        //  Skip job if it deleted
        if (current_job.get_job_deleted())
            continue;
        //  Getting the job start time, waiting for it and executing job
        auto start_time = current_job.get_start_time();
        std::this_thread::sleep_until(start_time);
        current_job.execute();
        //  Stopping scheduler with erasing last executed job
        if (_stop_scheduler) {
            _jobs.pop();
            break;
        }
        //  Adding periodic job
        if (current_job.get_periodic()) {
            add_job(current_job.periodic_clone());
        }
    }
}

void Scheduler::stop()
{
    _stop_scheduler = true;
}