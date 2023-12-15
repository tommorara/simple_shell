#include "shell.h"

/**
 * add_node - Inserts a new node at the beginning of a linked list.
 * @head: Pointer to the head of the list.
 * @str: String to store in the new node.
 * @num: Index number for the new node.
 * Return: Pointer to the new node.
 */
list_t *add_node(list_t **head, const char *str, int num)
{
    list_t *new_node;

    if (!head)
        return (NULL);
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);
    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;
    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }
    new_node->next = *head;
    *head = new_node;
    return (new_node);
}

/**
 * add_node_end - Appends a new node at the end of a linked list.
 * @head: Pointer to the head of the list.
 * @str: String to store in the new node.
 * @num: Index number for the new node.
 * Return: Pointer to the new node.
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
    list_t *new_node, *temp;

    if (!head)
        return (NULL);

    temp = *head;
    new_node = malloc(sizeof(list_t));
    if (!new_node)
        return (NULL);
    _memset((void *)new_node, 0, sizeof(list_t));
    new_node->num = num;
    if (str)
    {
        new_node->str = _strdup(str);
        if (!new_node->str)
        {
            free(new_node);
            return (NULL);
        }
    }
    if (temp)
    {
        while (temp->next)
            temp = temp->next;
        temp->next = new_node;
    }
    else
        *head = new_node;
    return (new_node);
}

/**
 * print_list_str - Prints the 'str' element of each node in a linked list.
 * @h: Pointer to the head of the list.
 * Return: The number of nodes in the list.
 */
size_t print_list_str(const list_t *h)
{
    size_t count = 0;

    while (h)
    {
        _puts(h->str ? h->str : "(nil)");
        _puts("\n");
        h = h->next;
        count++;
    }
    return (count);
}

/**
 * delete_node_at_index - Removes a node at a specified index in the list.
 * @head: Pointer to the head of the list.
 * @index: Index of the node to be removed.
 * Return: 1 if successful, 0 otherwise.
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
    list_t *current, *previous;
    unsigned int i = 0;

    if (!head || !*head)
        return (0);

    current = *head;
    if (index == 0)
    {
        *head = current->next;
        free(current->str);
        free(current);
        return (1);
    }

    while (current && i < index)
    {
        previous = current;
        current = current->next;
        i++;
    }

    if (current)
    {
        previous->next = current->next;
        free(current->str);
        free(current);
        return (1);
    }
    return (0);
}

/**
 * free_list - Deallocates all nodes in the linked list.
 * @head_ptr: Pointer to the head of the list.
 * Return: None.
 */
void free_list(list_t **head_ptr)
{
    list_t *node, *next_node;

    if (!head_ptr || !*head_ptr)
        return;

    node = *head_ptr;
    while (node)
    {
        next_node = node->next;
        free(node->str);
        free(node);
        node = next_node;
    }
    *head_ptr = NULL;
}

