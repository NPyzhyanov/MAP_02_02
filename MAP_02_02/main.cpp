#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

#include "run_calculations.h"

std::mutex print_mut;

int main()
{
    const int threads_amount = 5;
    const int calc_complexity = 20;
    
    const std::string Progress_Bar = "Progress Bar";
    const int Progress_Bar_size = static_cast<int>(Progress_Bar.size());
    const int progress_bars_symbolic_length = ((calc_complexity - Progress_Bar_size) < 0) ? Progress_Bar_size : calc_complexity;
    std::cout << "#  id \t" << Progress_Bar;
    for (int i = 0; i < (progress_bars_symbolic_length - Progress_Bar_size); i++)
    {
        std::cout << " ";
    }
    std::cout << "\tTime\n";
    
    std::vector<std::thread> Threads;
    
    for (int th = 0; th < threads_amount; th++)
    {
        Threads.push_back(std::thread(run_calculations, th, calc_complexity));
    }
    
    for (auto& el : Threads)
    {
        el.join();
    }
    
    return 0;
}
