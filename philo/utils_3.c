#include "philo.h"

void ft_msleep(t_philo *philo, int start, int time_to_sleep)
{
    while (msec_from_start(philo) < start + time_to_sleep)
        usleep(EPSILON_USEC);
}
