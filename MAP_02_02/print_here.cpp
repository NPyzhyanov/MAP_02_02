#include <iostream>
#include <string>
#include <windows.h>
#include <mutex>

#include "print_here.h"

extern std::mutex print_mut;

int print_here(int line_number, int size_before, std::string text_to_print)
{
    int size_after = size_before + text_to_print.size();
    
    COORD coord;
    coord.X = size_before;
    coord.Y = line_number;
    
    std::lock_guard<std::mutex> print_grd(print_mut); // print_mut activated
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << text_to_print;
    
    return size_after; // print_mut deactivated
}
