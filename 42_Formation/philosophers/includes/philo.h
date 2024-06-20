/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:04:12 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/20 04:50:24 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

# define TAKEN_FORK "%d %d has taken a fork.\n"
# define EAT "%d %d is eating.\n"
# define SLEEPING "%d %d is sleeping.\n"
# define THIKING "%d %d is thinking.\n"
# define DIE "%d %d is dead.\n"

typedef struct s_vars		t_vars;
struct						s_vars
{
	int		n_philo;
	int		time_die;
	int		time_eat;
	int		time_sleep;
	int		n_eat;
};

typedef struct s_philo		t_philo;
struct						s_philo
{
	pthread_t			philo;
	int					philo_id;
	t_vars				args;
	int					start_time;
	int					*last_meal;
	int					*life_time;
	int					*died;
	pthread_mutex_t		*m_forkl;
	pthread_mutex_t		*m_forkr;
	pthread_mutex_t		*m_print;
	pthread_mutex_t		*death;
	pthread_mutex_t		*m_time;
	pthread_mutex_t		*m_eat_end;
	pthread_mutex_t		*m_meal;
	int					n_meal;
	int					*end_meal;
};

typedef struct s_monitor	t_monitor;
struct						s_monitor
{
	t_philo				*philosophers;
	t_vars				args;
	pthread_t			inspector;
	pthread_mutex_t		*m_forks;
	pthread_mutex_t		m_print;
	pthread_mutex_t		*m_meal_philos;
	pthread_mutex_t		death;
	pthread_mutex_t		m_time;
	pthread_mutex_t		m_eat_end;
	int					start_time;
	int					died;
};

/*---------- INITIATION: ----------*/
void		init_vars(t_vars *vars);
void		get_args(t_vars *vars, char **av);
int			init_monitor(t_monitor *master, char **av);
int			alloc_init_all_mutex(t_monitor **master);
int			start_mutex(pthread_mutex_t *mutex);
void		create_join_threads(t_monitor *master);

/*---------- ACTIONS: -------------*/
int			die(t_philo *ph);
void		meal(t_philo *ph);
void		sleeping(t_philo *ph);
void		thinking(t_philo *ph);
void		*routine(void *philo);
void		*watching(void *master);

/*---------- VALIDATION: ----------*/
int			validation_args(int ac, char **av);

/*---------- UTILS: ---------------*/
void		print_log(const char *message, t_philo *philo);
long		ft_atol(const char *num);
int			current_time(t_philo *ph);
int			get_time(void);

/*---------- FREE: ----------------*/
void		clear_monitor(t_monitor *monitor);
void		clear_philo(t_philo *philo);

#endif
