#include <stdio.h>
#include <time.h>

void compare_time_functions() {

    // clock() kullanarak CPU süresini ölçme
    clock_t start_clock = clock();
    printf("Start_clock: %ld\n", start_clock);
    for (long i = 0; i < 1000000; i++);
    clock_t end_clock = clock();
    double cpu_time_used = ((double) (end_clock - start_clock)) / CLOCKS_PER_SEC;
    printf("CPU time used (clock): %f seconds\n", cpu_time_used);

    // time(0) kullanarak gerçek dünya zamanını ölçme
    time_t start_time = time(0);
    printf("Start_time: %ld\n", start_time);
    for (long i = 0; i < 1000000; i++);
    time_t end_time = time(0);
    double real_time_used = difftime(end_time, start_time);
    printf("Real world time used (time): %f seconds\n", real_time_used);
}

int main() {
    compare_time_functions();
    return 0;
}