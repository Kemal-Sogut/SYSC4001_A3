/**
 * @file interrupts.cpp
 * @author Sasisekhar Govind
 * @brief template main.cpp file for Assignment 3 Part 1 of SYSC4001
 * 
 */

#include<interrupts_student1_student2.hpp>

bool isSortingDone = false;

void EP(std::vector<PCB> &ready_queue) {
    // PRIORITY SORTING
            std::sort(ready_queue.begin(), ready_queue.end(),
                [](const PCB &a, const PCB &b) {
                    return a.PID > b.PID;  
                });
    isSortingDone = true;
}

std::tuple<std::string, std::string > run_simulation(std::vector<PCB> list_processes) {

    
    std::vector<PCB> ready_queue;   //The ready queue of processes
    std::vector<PCB> wait_queue;    //The wait queue of processes
    std::vector<PCB> job_list;      //A list to keep track of all the processes. This is similar
                                    //to the "Process, Arrival time, Burst time" table that you
                                    //see in questions. You don't need to use it, I put it here
                                    //to make the code easier :).

    unsigned int current_time = 0;
    PCB running;
    int time_slice = 100; //Time slice for Round Robin // Set 2 fro testing, can be changed as needed

    //Initialize an empty running process
    idle_CPU(running);

    std::string execution_status;
    std::string bonus_status;

    //make the output table (the header row)
    execution_status = print_exec_header();

    //Loop while till there are no ready or waiting processes.
    //This is the main reason I have job_list, you don't have to use it.
    while(!all_process_terminated(job_list) || job_list.empty()) {
        
        //Inside this loop, there are three things you must do:
        // 1) Populate the ready queue with processes as they arrive
        // 2) Manage the wait queue
        // 3) Schedule processes from the ready queue

        //Population of ready queue is given to you as an example.
        //Go through the list of proceeses
        for(auto &process : list_processes) {
            if(process.arrival_time == current_time) {
                
                assign_memory(process);

                process.state = READY; 
                ready_queue.push_back(process);
                job_list.push_back(process);

                execution_status += print_exec_status(current_time, process.PID, NEW, READY);
                isSortingDone = false;
            }
        }

        ///////////////////////MANAGE WAIT QUEUE/////////////////////////
        //This mainly involves keeping track of how long a process must remain in the ready queue

        for (auto it = wait_queue.begin(); it != wait_queue.end(); ) {

            it->io_wait_remaining--;
    
            std::cout << "Process " << it->PID << " IO wait remaining: " << it->io_wait_remaining << std::endl;

            if (it->io_wait_remaining == 0) { 

                execution_status += print_exec_status(
                        current_time,
                        it->PID,
                        WAITING,
                        READY);

                it->state = READY;
                it->quantum = 0;
                ready_queue.push_back(*it);
                sync_queue(job_list, *it);
                it = wait_queue.erase(it);  
            }else {
                ++it;
            }
        }



        /////////////////////////////////////////////////////////////////

        //////////////////////////SCHEDULER//////////////////////////////
        
        //If there is no running process, get one from the ready queue
        if (running.state != RUNNING && !ready_queue.empty()) {

            if (!isSortingDone) {
                EP(ready_queue);
            }

            run_process(running, job_list, ready_queue, current_time);
            execution_status += print_exec_status(current_time, running.PID, READY, RUNNING);
            running.processed_time = 0;  
        }


        // Check if the running process needs to perform IO

        if (running.state == RUNNING && running.io_freq > 0 && running.processed_time == running.io_freq && running.remaining_time > 0)
        {
            std::cout << "Process " << running.PID << " is performing I/O." << std::endl;
            execution_status += print_exec_status(
                    current_time,
                    running.PID,
                    RUNNING,
                    WAITING);
            running.processed_time = 0;
            running.quantum = 0;
            running.state = WAITING;
            running.io_wait_remaining = running.io_duration;
            wait_queue.push_back(running);
            sync_queue(job_list, running);
            idle_CPU(running);
        } 
        
        
        // RR preemption 
        else if (running.state == RUNNING && running.quantum == time_slice && running.remaining_time > 0) {
            execution_status += print_exec_status(current_time, running.PID, RUNNING, READY);
            running.state = READY;
            running.quantum = 0;  // Reset quantum
            ready_queue.push_back(running);
            sync_queue(job_list, running);
            idle_CPU(running);
            continue;
            
        }
        

        //Normal process
        else if (running.state == RUNNING) {

            running.remaining_time--;
            running.processed_time++;
            running.quantum++;
            sync_queue(job_list, running);
            
            // Check termination
            if (running.remaining_time == 0) {
                execution_status += print_exec_status(current_time, running.PID, RUNNING, TERMINATED);
                bonus_status += print_bonus_status(current_time, running.PID);
                terminate_process(running, job_list);
                idle_CPU(running);
                continue;
            }
        }

        /////////////////////////////////////////////////////////////////


        current_time++; //Increment the current time
    }
    
    //Close the output table
    execution_status += print_exec_footer();

    return std::make_tuple(execution_status, bonus_status);
}


int main(int argc, char** argv) {

    //Get the input file from the user
    if(argc != 2) {
        std::cout << "ERROR!\nExpected 1 argument, received " << argc - 1 << std::endl;
        std::cout << "To run the program, do: ./interrutps <your_input_file.txt>" << std::endl;
        return -1;
    }

    //Open the input file
    auto file_name = argv[1];
    std::ifstream input_file;
    input_file.open(file_name);

    //Ensure that the file actually opens
    if (!input_file.is_open()) {
        std::cerr << "Error: Unable to open file: " << file_name << std::endl;
        return -1;
    }

    //Parse the entire input file and populate a vector of PCBs.
    //To do so, the add_process() helper function is used (see include file).
    std::string line;
    std::vector<PCB> list_process;
    while(std::getline(input_file, line)) {
        auto input_tokens = split_delim(line, ", ");
        auto new_process = add_process(input_tokens);
        list_process.push_back(new_process);
    }
    input_file.close();

    //With the list of processes, run the simulation
    auto [exec,bonus] = run_simulation(list_process);

     //Write the bonus output to a file
    write_output(bonus, "bonus.txt");


    write_output(exec, "execution.txt");

    return 0;
}