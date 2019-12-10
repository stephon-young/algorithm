// 单链表接口定义

#if !defined(slist_h__)

#if !defined(DATA_T)
#define data_t int
#endif 

typedef struct _snode_t snode_t, slist_t;

/* 初始化 单链表，成功返回单链表指针，失败，返回NULL */
slist_t* slist_initialize(void);
/* 释放 单链表，循环释放每个节点，最终释放头结点 */
void slist_finalize(slist_t *slist);

/* 获取单链表长度 */
int slist_length(slist_t *list);

/* 在单链表尾部追加节点 */
int slist_append(slist_t *slist, data_t data);
/* 在指定位置插入节点， 如果指定位置不合法(pos < 1 or pos > slist长度 + 1)，返回-1，申请空间失败也返回-1，插入成功返回0 */
int slist_insert(slist_t *slist, int pos, data_t data);
/* 删除指定位置节点， 并返回节点数据，如果指定位置不合法(pos < 1 or pos > slist长度)，返回-1， 删除成功返回0 */
int slist_remove(slist_t *slist, int pos, data_t *data);

/* 获取链表指定位置的数据，返回位置上的数据，如果pos合法，返回0， 否则返回-1 */
int slist_get(slist_t *slist, int pos, data_t *data);

/* 获取数据在链表中匹配的第一个的位置，位置不匹配则返回 0 */
int slist_locate(slist_t *list, data_t data);

/* 反转链表 */
void slist_reverse(slist_t *list);
/* 对链表进行排序 */
void slist_sort(slist_t *list, int (*compare)(data_t first, data_t second));
/* 将两个有序链表合并成一个新的有序链表 */
slist_t* slist_combine(slist_t *first, slist_t *second);
/* 判断链表是否有环 */
int slist_is_cycle(slist_t *slist);
/* 获取链表中间节点指针 */
snode_t *slist_middle(slist_t *slist);

#endif // slist_h__