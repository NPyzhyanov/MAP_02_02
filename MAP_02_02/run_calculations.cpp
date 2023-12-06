#include <thread>
#include <string>
#include <sstream>
#include <chrono>
#include <cmath>

#include "run_calculations.h"
#include "consts.h"
#include "generate_random_value.h"
#include "print_here.h"

void run_calculations(const int thread_number, const int calc_complexity)
{
    const int line = thread_number + 1;
    
    int length = 0;
    
    std::string th_num_str = std::to_string(thread_number) + " \t ";
    length = print_here(line, length, th_num_str);
    
    auto th_id = std::this_thread::get_id();
    std::stringstream ss_id;
    ss_id << th_id;
    std::string id = ss_id.str() + " \t ";
    length = print_here(line, length, id);
    
    auto start = std::chrono::steady_clock::now(); // <-- Time recording started
    
    const double progress_to_reach = static_cast<double>(calc_complexity);
    double total_progress = 0.0;
    int fill_symbols_shown = 0;
    
    while (total_progress < progress_to_reach)
    {
        double d_delay = generate_random_value(consts::min_step_delay, consts::max_step_delay);
        std::chrono::milliseconds time_delay { static_cast<int> (d_delay) };
        std::this_thread::sleep_for(time_delay);
        
        total_progress += generate_random_value(consts::min_step_progress, consts::max_step_progress);
        
        int show_new_symbol = static_cast<int>(floor(total_progress)) - fill_symbols_shown;
        if (show_new_symbol)
        {
            fill_symbols_shown += show_new_symbol;
            for (int i = 0; i < show_new_symbol; i++)
            {
                length = print_here(line, length, consts::fill_symbol);
            }
        }
    }
    
    auto end = std::chrono::steady_clock::now(); // <-- Time recording finished
    
    auto diff = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::stringstream ss_duration;
    ss_duration << diff.count() / 1000.0;
    length = print_here(line, length, "\t" + ss_duration.str() + " ms");
}
