#include "headers/scheduler.h"
#include <iostream>
#include <chrono>

void foo1 () { std::cout << "job1" << std::endl; }
void foo2 () { std::cout << "job2" << std::endl; }
void foo3 () { std::cout << "job3" << std::endl; }
void foo4 () { std::cout << "job4" << std::endl; }

int main(int argc, char** argv) {
    using namespace std::literals;
    Scheduler scheduler;
    std::chrono::system_clock::time_point job1_start (std::chrono::system_clock::now());
    std::chrono::system_clock::time_point job2_start (std::chrono::system_clock::now() + 10s);
    std::chrono::seconds job1_duration(3);
    std::chrono::seconds job2_duration(3);
    std::chrono::seconds job3_duration(3);
    std::chrono::seconds job4_duration(3);

    Job job1(&foo1, 3, false, job1_start, job1_duration);
    Job job2(&foo2, 2, false, job1_start, job2_duration);
    Job job3(&foo3, 1, false, job1_start, job3_duration);
    Job job4(&foo4, 6, true, job1_start, job4_duration);
    Job job5([&scheduler]() {scheduler.stop();}, 6, true, job2_start, job4_duration);
    scheduler.add_job(job1);
    scheduler.add_job(job2);
    scheduler.add_job(job3);
    scheduler.delete_job();
    scheduler.add_job(job4);
    scheduler.add_job(job5);
    scheduler.start();

    return 0;
}