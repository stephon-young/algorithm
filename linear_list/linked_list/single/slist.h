// 单链表接口定义

#if !defined(slist_h__)

#if !defined(DATA_T)
#define data_t int
#endif 

typedef struct _snode_t snode_t, slist_t;

slist_t* slist_initialize(void);
void slist_finalize(slist_t *slist);

int slist_append(slist_t *slist, data_t data);
int slist_insert(slist_t *slist, int pos, data_t data);
int slist_remove(slist_t *slist, int pos, data_t *data);

int slist_locate(slist_t *list, data_t data);

void slist_reverse(slist_t *list);
void slist_sort(slist_t *list, int (*compare)(data_t first, data_t second));
slist_t* slist_combine(slist_t *first, slist_t *second);
int slist_is_cycle(slist_t *slist);
snode_t *slist_middle(slist_t *slist);

#endif // slist_h__