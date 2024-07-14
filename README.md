# Scheduler

A job scheduler is a computer application for controlling unattended background program execution of jobs.

## Installation

Clone the GitHub repository and build project 

```bash
cd Task_Schaduler/
make
```

## Cleaning

To clean the executable

```bash
make clean
```

## Usage

You can find simple example in Main.cpp

Use this syntax to make a job
```c++
Job job1(function_pointer, priority, periodic, start_time, duration);
```
Scheduler functions

```c++
void add_job(Job job1);  // adding job to scheduler
void delete_job();       // deleting job from scheduler
void start();            // start scheduler to execute jobs
void stop();             // stop scheduler
```

## Contributing

Be free to use my code for your project. You can also open an issue or suggest changes.