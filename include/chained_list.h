/*
** EPITECH PROJECT, 2023
** Personal_Clib [WSL: fedora]
** File description:
** chained_list
*/

#ifndef CHAINED_LIST_H_
    #define CHAINED_LIST_H_
    #define ASSERT_MALLOC(ptr, retrn) if (ptr == ((void *)0)) return retrn;

    typedef struct node_s node_t;
    typedef struct list_s list_t;
    typedef struct list_interface list_interface_t;
    typedef struct node_s {
        void *data;
        node_t *next;
    } node_t;

    typedef struct list_s {
        node_t *head;
        node_t *tail;
        int size;
        list_interface_t *intrf;
    } list_t;

    typedef struct list_interface {
        int (*append)(list_t *list, void *data);
        int (*insert)(list_t *list, void *data);
        void *(*popf)(list_t *list);
        void *(*pop)(list_t *list, void *data);
        void (*append_list)(list_t *list_dest, list_t *list_src);
        void (*insert_list)(list_t *list_dest, list_t *list_src);
        void (*print)(list_t *list, void (*printdata)(void *), const char *sep);
        node_t *(*find)(list_t *list, void const *const data);
        void (*destroy)(list_t *list, void (*free_data)(void *));
    } list_interface_t;

    node_t *init_node(void *data);
    list_t *init_list(void);

    int append_node(list_t *list, void *data);
    int insert_node(list_t *list, void *data);

    void *pop_first_node(list_t *list);
    void *pop_node(list_t *list, void *data);

    void append_list(list_t *list_dest, list_t *list_src);
    void insert_list(list_t *list_dest, list_t *list_src);

    void node_exec(list_t *list, void (*exec_data)(void *));
    node_t *find_node(list_t *list, void const *const data);

    int delete_node(list_t *list, void *data, void (*free_data)(void *));
    int destroy_node(list_t *list, void (*free_data)(void *));
    void destroy_list(list_t *list, void (*free_data)(void *));

    void print_list(list_t *list, void (*print_data)(void *), const char *sep);
    void **list_build(list_t *list);

    void free_string(void *data);
#endif /* !CHAINED_LIST_H_ */
