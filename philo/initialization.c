#include "philo.h"

static void	ft_init_data(t_data *data, char **argv)
{
	data->n = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (data->n <= 0
		|| data->time_to_die <= 0
		|| data->time_to_eat <= 0
		|| data->time_to_sleep <= 0)
		ft_error("Error:\ninvalid values\n", data);
	if (argv[5])
	{
		data->meals_goal = ft_atoi(argv[5]);
		if (data->meals_goal < 0)
            ft_error("Error:\ninvalid values\n", data);
	}
	else
		data->meals_goal = -1;
	data->start_msec = get_time();
	data->goals_achieved = 0;
}

static void	ft_init_philos(t_data *data)
{
	int	i;

	i = -1;
	data->philosopher = (t_philo *)malloc(sizeof(t_philo) * data->n);
	if (!data->philosopher)
        ft_error("Error:\nMalloc \"philosophers\"\n", data);
	while (++i < data->n)
	{
		data->philosopher[i].data = data;
		data->philosopher[i].philo_id = i + 1;
		data->philosopher[i].meals_amount = 0;
		data->philosopher[i].time_last_meal = 0;
		data->philosopher[i].fork_sx_id = i;
		data->philosopher[i].fork_dx_id = (i + 1) % (data->n);
	}
}

static void	ft_init_mutex(t_data *data)
{
	int	i;

	i = -1;
	data->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * data->n);
	if (!data->forks)
        ft_error("Error:\nMalloc \"fork\"\n", data);
	while (++i < data->n)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
            ft_error("Error:\nMutex \"fork\" Init\n", data);
	}
	if (pthread_mutex_init(&data->print, NULL))
		ft_error("Error:\nMutex \"print\" Init\n", data);
	if (pthread_mutex_init(&data->execution, NULL))
		ft_error("Error:\nMutex \"print\" Init\n", data);
}

void	ft_initialize(t_data *data, char **argv)
{
	ft_init_data(data, argv);
	ft_init_philos(data);
	ft_init_mutex(data);
}