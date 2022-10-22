#!/usr/bin/env python3

import argparse
import itertools

class Process():
    def __init__(self, /,
            name=None,
            burst=None,
            arrival_time=None,
            priority=None,
            time_slice=None,
            waiting_time=None,
            turnaround_time=None):
        self.name            = name
        self.burst           = burst
        self.arrival_time    = arrival_time
        self.priority        = priority
        self.time_slice      = time_slice
        self.waiting_time    = waiting_time
        self.turnaround_time = turnaround_time

    def __repr__(self):
        args = [('name',         self.name),
                ('burst',        self.burst),
                ('arrival_time', self.arrival_time),
                ('priority',     self.priority),
                ('time_slice',   self.time_slice)]
        if self.waiting_time is not None:    args.append(('waiting_time',    self.waiting_time))
        if self.turnaround_time is not None: args.append(('turnaround_time', self.turnaround_time))
        args = [f'{arg[0]}={repr(arg[1])}' for arg in args]
        return f'Process({", ".join(args)})'

def parse_line(line):
    line = line.strip()
    assert(line[0] == '@' and line[-1] == '&')
    line = line[1:-1]
    fields = line.split(';')
    assert(len(fields) == 5)
    process = Process()
    process.name         = fields[0]
    process.burst        = int(fields[1])
    process.arrival_time = int(fields[2])
    process.priority     = int(fields[3])
    process.time_slice   = int(fields[4])
    return process

def read_file(filename):
    with open(filename) as file:
        return [parse_line(line) for line in file.readlines() if line]

# First Come First Serve
#
# The simplest scheduling algorithm, mainly because it does basically no
# scheduling at all! It just runs processes as they arrive until their
# completion.
def fcfs(processes):
    processes.sort(key=lambda process: process.arrival_time)
    # Start simulation at the first arrival.
    current_time = processes[0].arrival_time
    result = []
    for process in processes:
        # Adjust current time if CPU was idle.
        if process.arrival_time > current_time:
            current_time = process.arrival_time
        process.waiting_time = current_time - process.arrival_time
        current_time += process.burst
        process.turnaround_time = current_time - process.arrival_time
        result.append(process)
    return result

# Shortest Job First
#
# The simplest scheduling algorithm that actually does some scheduling. It
# chooses the process with the smallest burst time and runs it to completion.
# This is the non-preemptive version of the algorithm, for the preemptive
# version see `srtf`.
def sjf(processes):
    processes.sort(key=lambda process: process.arrival_time)
    # Start simulation at the first arrival.
    current_time = processes[0].arrival_time
    # Yields the job with the shortest burst that has already arrived.
    def next_process():
        while True:
            nonlocal current_time
            if not processes: return
            next = 0
            # Adjust current time if CPU was idle.
            if processes[next].arrival_time > current_time:
                current_time = processes[next].arrival_time
            for i in range(1, len(processes)):
                # This condition relies on the list being sorted.
                if processes[i].arrival_time > current_time:
                    break
                if processes[i].burst < processes[next].burst:
                    next = i
            # `pop` removes the process from the `processes` list.
            yield processes.pop(next)
    result = []
    for process in next_process():
        process.waiting_time = current_time - process.arrival_time
        current_time += process.burst
        process.turnaround_time = current_time - process.arrival_time
        result.append(process)
    return result

# Shortest Remaining Time First
#
# The preemptive version of `sjf`. The key difference is that whenever a new
# process arrives the scheduler switches if its burst in shorter than the
# remaining burst of the currently running process.
#
# This simulation looks for the shortest remaining burst every unit of time,
# which results in behavior identical to the described above.
def srtf(processes):
    processes.sort(key=lambda process: process.arrival_time)
    # Since this is a preemptive algorithm, that is, processes will not
    # necessarily run until completion uninterrupted, we need to keep track of
    # the remaining burst.
    for i in range(len(processes)):
        processes[i].remaining_burst = processes[i].burst
    # Start simulation at the first arrival.
    current_time = processes[0].arrival_time
    result = []
    while True:
        if not processes: break
        # Find the process with the shortest remaining time.
        next = 0
        # Adjust current time if CPU was idle.
        if processes[next].arrival_time > current_time:
            current_time = processes[next].arrival_time
        for i in range(1, len(processes)):
            # This condition relies on the list being sorted.
            if processes[i].arrival_time > current_time:
                break
            if processes[i].remaining_burst < processes[next].remaining_burst:
                next = i
        # Simulate one unit of time at the time in case another processes
        # arrives.
        processes[next].remaining_burst -= 1
        current_time += 1
        if processes[next].remaining_burst == 0:
            processes[next].completion_time = current_time
            result.append(processes.pop(next))
    for i in range(len(result)):
        result[i].waiting_time = result[i].completion_time - result[i].arrival_time - result[i].burst
        result[i].turnaround_time = result[i].completion_time - result[i].arrival_time
    return result

# Round Robin
#
# This algorithm cycles between every process giving each a time slice to run.
def rr(processes):
    processes.sort(key=lambda process: process.arrival_time)
    # Since this is a preemptive algorithm, that is, processes will not
    # necessarily run until completion uninterrupted, we need to keep track of
    # the remaining burst.
    for i in range(len(processes)):
        processes[i].remaining_burst = processes[i].burst
    # Start simulation at the first arrival.
    current_time = processes[0].arrival_time
    for i in itertools.cycle(range(len(processes))):
        # Terminate if all processes are done.
        if all(process.remaining_burst == 0 for process in processes):
            break
        # Skip this process if it has not yet arrived or if it is completed.
        if processes[i].arrival_time > current_time or processes[i].remaining_burst == 0:
            continue
        current_burst = min(processes[i].remaining_burst, processes[i].time_slice)
        processes[i].remaining_burst -= current_burst
        current_time += current_burst
        if processes[i].remaining_burst == 0:
            processes[i].completion_time = current_time
    for i in range(len(processes)):
        processes[i].waiting_time = processes[i].completion_time - processes[i].arrival_time - processes[i].burst
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time
    return processes

if __name__ == '__main__':
    arg = argparse.ArgumentParser()
    option = arg.add_mutually_exclusive_group()
    option.add_argument('--fcfs', help='First Come First Serve (default)', action='store_true', default=True)
    option.add_argument('--sjf',  help='Shortest Job First',               action='store_true')
    option.add_argument('--srtf', help='Shortest Remaining Time First',    action='store_true')
    option.add_argument('--rr',   help='Round Robin',                      action='store_true')
    arg.add_argument('file', help='Input file', type=str)
    arg = arg.parse_args()

    algorithm = fcfs
    if arg.sjf:  algorithm = sjf
    if arg.srtf: algorithm = srtf
    if arg.rr:   algorithm = rr

    processes = read_file(arg.file)
    processes = algorithm(processes)
    for process in processes:
        print(process)
    print(f'Average waiting time: {sum(process.waiting_time for process in processes) / len(processes)}')
    print(f'Average turnaround time: {sum(process.turnaround_time for process in processes) / len(processes)}')