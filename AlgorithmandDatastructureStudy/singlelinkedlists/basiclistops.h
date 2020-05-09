typedef struct _mylist{
    int *ptr;
    struct _mylist *next;
 }mylist;

void disp_list(mylist* node);
int rem_node_by_index(int idx,mylist** head);
void free_my_list(mylist** head);
void print_rever(mylist* head);
mylist *create_list(int num);
mylist *create_looped_list(int num);
void rem_node_by_addr(mylist** node);
mylist* find_middle_node(mylist* head);
void print_node(mylist* ndoe);
int checkif_loop_exist(mylist* head);

#define offsetof(type,member) ((size_t)&(((type*)0)->member))

#define container_of(ptr,type,member) ({ \
                           const  typeof(((type*)0)->member) *mptr = ptr; \
        (type*)((char*)mptr - offsetof(type,member));})
                                

