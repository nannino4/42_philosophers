#include "philo.h"

void *give_life(void *arg)
{
    int id;
    
    id = *(int *)arg;
}

void    create_threads(t_input input)
{
    pthread_t	    thread_id[input.n];
    pthread_mutex_t mutex[input.n];
    int			    i;

    i = -1;
    while (++i < input.n)
    {
        pthread_create(&thread_id[i], NULL, &give_life, (void *)&i);
        pthread_mutex_init(&mutex[i], NULL);
    }
    while (i-- > 0)
    {
        pthread_join(thread_id[i], NULL);
        pthread_mutex_destroy(&mutex[i]);
    }
}

void    read_input(t_input *input)
{
    
}

int main(int argc, char **argv)
{
    t_input     input;

    memset((void *)&input, 0, sizeof(t_input));
    if (argc == 4 || argc == 5)
    {
        read_input(&input);
        create_threads(input);
    }
    else
        printf("\nError: invalid arguments\n\n");
}
