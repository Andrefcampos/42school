/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:04:12 by andrefil          #+#    #+#             */
/*   Updated: 2024/06/19 04:37:35 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

# define TAKEN_FORK "%d - Philosopher %d has taken a fork.\n"
# define EAT "%d - Philosopher %d is eating.\n"
# define SLEEPING "%d - Philosopher %d is sleeping.\n"
# define THIKING "%d - Philosopher %d is thinking.\n"
# define DIE "%d - Philosopher %d is dead.\n"

typedef struct s_vars	t_vars;
struct					s_vars
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
	t_vars				args;
	pthread_mutex_t		*m_print;
	pthread_mutex_t		*m_forkl;
	pthread_mutex_t		*m_forkr;
	pthread_mutex_t		*dead;
	pthread_mutex_t		*m_time;
	int					*start_time;
	int					*last_meal;
	int					*life_time;
	int					*die;
	int					philo_id;
	int					n_meals;
};

typedef struct s_monitor		t_monitor;
struct						s_monitor
{
	t_philo				*philosophers;
	t_vars				args;
	pthread_mutex_t		*m_forks;
	pthread_mutex_t		dead;
	pthread_mutex_t		m_print;
	pthread_mutex_t		m_time;
	int					start_time;
	int					die;
};

/*---------- INITIATION: ----------*/
void		init_vars(t_vars *vars);
void		get_args(t_vars *vars, char **av);
int			init_monitor(t_monitor *monitor, char **av);
void		start_threads(char **av);


/*---------- ACTIONS: -------------*/
void		die(t_philo ph);
void		meal(t_philo ph, int *n_eats);
void		sleeping(t_philo ph);
void		thinking(t_philo ph);
void		*routine(void *philo);

/*---------- VALIDATION: ----------*/
int			check_av(char *arg);
int			validation_args(int ac, char **av);

/*---------- UTILS: ----------*/
void		print_log(const char *message, t_philo philo);
long		ft_atol(const char *num);
int			current_time(t_philo ph);
int			get_time();

#endif
