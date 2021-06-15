#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>

typedef struct s_input
{
    int n;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int least_amount;
}   t_input
