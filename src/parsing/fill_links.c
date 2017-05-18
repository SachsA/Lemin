/*
** fill_links.c for fill_links in /home/sachs_a/delivery/c_prog_elem/
**
** Made by Alexandre Sachs
** Login   <sachs_a@epitech.net>
**
** Started on  Thu Apr 13 15:50:25 2017 Alexandre Sachs
** Last update Apr Apr 26 19:47:22 2017
*/

#include <stdlib.h>
#include "my.h"
#include "basics.h"
#include "parsing.h"
#include "get_next_line.h"

int		check_multi(t_room *node, char *link)
{
  t_link	*tmp;

  tmp = node->link;
  while (tmp != NULL)
    {
      if (my_strcmp(tmp->room->name, link) == 0)
	return (-1);
      tmp = tmp->next;
    }
  return (0);
}

int		push_links(t_room *node, char *link, t_room **room)
{
  t_link	*new_link;
  t_room	*tmp;

  tmp = *room;
  while (tmp != NULL && my_strcmp(link, tmp->name) != 0)
    tmp = tmp->next;
  if (check_multi(node, link) == -1)
    return (0);
  if ((new_link = malloc(sizeof(t_link))) == NULL)
    return (84);
  new_link->room = tmp;
  new_link->next = node->link;
  node->link = new_link;
  return (0);
}

int		verif_node(char **node, t_room **room)
{
  t_room	*tmp;

  tmp = *room;
  while (tmp != NULL && my_strcmp(node[0], tmp->name) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (-1);
  tmp = *room;
  while (tmp != NULL && my_strcmp(node[1], tmp->name) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (-1);
  return (0);
}

int		add_link(char *str, t_room **room)
{
  t_room	*tmp;
  char		**tab_links;

  if ((tab_links = my_str_to_wordtab(str, '-')) == NULL)
    return (84);
  if (my_tablen(tab_links) != 2 || verif_node(tab_links, room) == -1)
    return (my_free_tab(tab_links), 1);
  tmp = *room;
  while (tmp != NULL && my_strcmp(tmp->name, tab_links[0]) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (my_free_tab(tab_links), 1);
  if (push_links(tmp, tab_links[1], room) == 84)
    return (my_free_tab(tab_links), 84);
  tmp = *room;
  while (tmp != NULL && my_strcmp(tmp->name, tab_links[1]) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    return (my_free_tab(tab_links), 1);
  if (push_links(tmp, tab_links[0], room) == 84)
    return (my_free_tab(tab_links), 84);
  my_free_tab(tab_links);
  return (0);
}

int		fill_links(char *str, t_room **room)
{
  int		rt;

  my_printf("#tunnels\n");
  if ((rt = add_link(str, room)) == 84)
    return (84);
  else if (rt == 1)
    return (0);
  my_printf("%s\n", str);
  while ((str = get_next_line(0)) != NULL)
    {
      str = my_clean(str);
      if (*str == '\0')
	{
	  free(str);
	  continue;
	}
      if ((rt = add_link(str, room)) == 84)
	return (84);
      else if (rt == 1)
	return (0);
      my_printf("%s\n", str);
      free(str);
    }
  return (0);
}
