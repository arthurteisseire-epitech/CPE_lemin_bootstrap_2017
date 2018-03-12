/*
** EPITECH PROJECT, 2017
** File Name : main.c
** File description:
** by Arthur Teisseire
*/

#include <stdlib.h>
#include <stdio.h>
#include "link.h"
#include "my.h"

link_t *create_link(int data)
{
	link_t *link = malloc(sizeof(link_t));

	link->data = data;
	return (link);
}

void print_link(link_t *link)
{
	printf("%d\n", link->data);
}

void connect_links(link_t *link1, link_t *link2)
{
	link1->next = link2;
}

void print_data_connected_links(link_t *link)
{
	while (link != NULL) {
		print_link(link);
		link = link->next;
	}
}

void free_links(link_t *link)
{
	link_t *tmp;

	while (link != NULL) {
		tmp = link;
		link = link->next;
		free(tmp);
	}
}

int main(void)
{
	link_t *link1 = NULL;
	link_t *link2 = create_link(2);
	link_t *link3 = create_link(3);

	connect_links(link3, link2);
	connect_links(link2, link1);
	print_data_connected_links(link3);
	free_links(link3);
	return (0);
}
