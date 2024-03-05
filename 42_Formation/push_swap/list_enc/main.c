/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:52:36 by andrefil          #+#    #+#             */
/*   Updated: 2024/03/04 20:25:46 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

long ft_atol(const char *nstr);

typedef struct s_list {
  int num;
  struct s_list *next;
  struct s_list *prev;
} t_list;

t_list *create_node(int data) {
  t_list *set;

  set = malloc(sizeof(t_list));
  if (!set)
    return (NULL);
  set->num = data;
  set->prev = NULL;
  set->next = NULL;
  return (set);
}

void add_next_first(t_list **head, t_list *new_node) {
  if (!new_node)
    return;
  if (*head == NULL) {
    (*head)->prev = new_node;
    new_node->prev = NULL;
    new_node->next = NULL;
    return;
  }
  new_node->next = *head;
  (*head)->prev = new_node;
  new_node->prev = NULL;
  *head = new_node;
}

void add_next_last(t_list **head, t_list *new_node) {
  t_list *upd;

  if (!new_node)
    return;
  if (!*head) {
    *head = new_node;
    return;
  }
  upd = *head;
  while (upd->next)
    upd = upd->next;
  new_node->prev = upd;
  upd->next = new_node;
}

void del_one_node(t_list **head, int val) {
  t_list *temp;

  if (!*head)
    return;
  temp = *head;
  while (temp != NULL && temp->num != val)
    temp = temp->next;
  if (temp == NULL)
    return;
  if (temp == *head)
    *head = temp->next;
  if (temp->prev != NULL)
    temp->prev->next = temp->next;
  if (temp->next != NULL)
    temp->next->prev = temp->prev;
  free(temp);
  printf("\ndel one element:\n");
}

void swap_first_second_node(t_list **head) {
  t_list *first;
  t_list *second;

  if (*head == NULL || (*head)->next == NULL)
    return;
  first = *head;
  second = (*head)->next;
  first->next = second->next;
  first->prev = second;

  second->next = first;
  second->prev = NULL;

  *head = second;
  if (first->next != NULL)
    first->next->prev = first;
  printf("\nswap first to second:\n");
}

void swap_first_last_node(t_list **head) {
  t_list *first;
  t_list *second;
  t_list *last;

  if (*head == NULL || (*head)->next == NULL)
    return;
  first = *head;
  last = *head;
  second = last->next;
  while (last->next != NULL) {
    first->prev = last;
    last = last->next;
  }
  last->next = first;
  first->next = NULL;
  second->prev = NULL;
  *head = second;
  printf("swap first to last list :\n");
}

void swap_last_first_node(t_list **head) {
  t_list *first;
  t_list *last;
  t_list *second_last;

  if (*head == NULL || (*head)->next == NULL)
    return;
  first = *head;
  last = *head;
  second_last = NULL;
  while (last->next != NULL) {
    second_last = last;
    last = last->next;
  }
  last->next = first;
  first->prev = last;
  last->prev = NULL;
  second_last->next = NULL;
  *head = last;
}

int max_node(t_list **list) {
  t_list *temp;
  int max;

  temp = *list;
  max = temp->num;
  while (temp) {
    if (max <= temp->num)
      max = temp->num;
    temp = temp->next;
  }
  return (max);
}

int min_node(t_list **list) {
  t_list *temp;
  int min;

  temp = *list;
  min = temp->num;
  while (temp) {
    if (min >= temp->num)
      min = temp->num;
    temp = temp->next;
  }
  return (min);
}
void print_list(t_list **list) {
  t_list *temp;

  if (!*list)
    return;
  temp = *list;
  while (temp) {
    printf("nó: %d\n", temp->num);
    temp = temp->next;
  }
  printf("fim.\n");
}

void send_in_list(t_list **stack1, t_list **stack2) {
  t_list *first_stack1;
  t_list *current_node;

  if (*stack1 == NULL || stack2 == NULL)
    return;
  first_stack1 = *stack1;
  current_node = first_stack1;
  first_stack1 = first_stack1->next;
  first_stack1->prev = NULL;
  *stack1 = first_stack1;
  current_node->next = NULL;
  current_node->prev = NULL;
  if (!*stack2) {
    *stack2 = current_node;
    return;
  }
  add_next_first(stack2, current_node);
}

int main(int ac, char **av) {
  t_list *list;
  t_list *list2;
  int i;
  t_list *temp;

  list = NULL;
  list2 = NULL;
  if (ac < 1)
    return (1);
  i = 1;

  while (av[i]) {
    add_next_last(&list, create_node(ft_atol(av[i])));
    printf("valor do arr: %ld\n", ft_atol(av[i]));
    i++;
  }
  temp = list;
  while (temp) {
    if (temp->prev != NULL)
      printf("prev: %d->", temp->prev->num);
    else
      printf("start list:\nNULL-> ");
    printf("targ: %d->", temp->num);
    if (temp->next != NULL)
      printf("next: %d\n", temp->next->num);
    else
      printf("NULL\nend\n");
    temp = temp->next;
  }
  // del_one_node(&list, ft_atol(av[5]));
  // temp = list;
  // while (temp)
  // {
  // 	if (temp->prev != NULL)
  // 		printf("prev: %d ", temp->prev->num);
  // 	printf("targ: %d\n\n", temp->num);
  // 	temp = temp->next;
  // }
  // printf("valor do primeiro nó: %d\n", list->num);
  // printf("valor minimo da lista: %d\n", min_node(&list));
  // printf("valor máximo da lista: %d\n", max_node(&list));
  swap_first_last_node(&list);
  print_list(&list);
  swap_first_second_node(&list);
  print_list(&list);
  swap_last_first_node(&list);
  print_list(&list);
  // list2 = create_node(0);
  add_next_first(&list, create_node(50));
  print_list(&list);
  while (list->next != NULL)
    send_in_list(&list, &list2);
  print_list(&list);
  print_list(&list2);
  // printf("\nnó atual -> %d.\n", list2->num);
  // printf("next: %d\n", list2->next->num);
  return (0);
}
