#include <chrono>
#include <iostream>


int main(int argc, char const *argv[])
{
    
        auto now_date = std::chrono::system_clock::now(); // steady_clock
        time_t c_now_time = std::chrono::system_clock::to_time_t(now_date);
        auto time_tm = localtime(&c_now_time);
        char *str_now_time = new char[1]; // XXX: 这里应该怎么初始化？// char str_now_time[17];
        sprintf(str_now_time,
                "%d-%02d-%02d %02d:%02d:%02d",
                time_tm->tm_year + 1900,
                time_tm->tm_mon + 1,
                time_tm->tm_mday,
                time_tm->tm_hour,
                time_tm->tm_min,
                time_tm->tm_sec);
        std::cout << str_now_time << std::endl;
        delete[] str_now_time;

    return 0;
}
