// 单链表实现

#include "slist.h"
#include <stdlib.h>

struct _snode_t {
  struct _snode_t *next;
  data_t data;
};

slist_t* slist_initialize(void) {
  slist_t *slist;
  if ((slist = malloc(sizeof(snode_t))) == NULL)
    return NULL;

  // 带头结点的单链表
  slist->next = NULL;
  return slist;
}

void slist_finalize(slist_t *slist) {
  while (slist_remove(slist, 1, NULL) > 0);
  free(slist);
}

int slist_append(slist_t *slist, data_t data) {
  snode_t *node;
  if ((node = malloc(sizeof(snode_t))) == NULL)
    return -1;

  node->next = NULL;
  node->data = data;
  
  snode_t *tail = slist->next;
  while (tail->next != NULL)
    tail = tail->next;

  tail->next = node;

  return 0;
}

int slist_insert(slist_t *slist, int pos, data_t data) {
  if (pos < 1)
    return -1;

  int count = 1;
  snode_t *n = slist->next;
  int found = 0;
  while (n->next != NULL) {
    if (count == pos) {
      found = 1;
      break;
    }
    n = n->next;
    count++;
  }

  if (!found)
    return -1;

  snode_t *node;
  if ((node = malloc(sizeof(snode_t))) == NULL)
    return -1;

  node->next = n->next;
  node->data = data;

  n->next = node;

  return 0; 
}

int slist_remove(slist_t *slist, int pos, data_t *data) {
  if (pos < 1)
    return -1;

  int count = 1;
  snode_t *n = slist;
  int found = 0;
  while (n->next != NULL) {
    if (count == pos) {
      found = 1;
      break;
    }
    n = n->next;
    count++;
  }

  if (!found)
    return -1;

  snode_t *node = n->next;
  if (data != NULL)
    *data = node->data;

  n->next = node->next;
  free(node);

  return 0;
}

int slist_locate(slist_t *list, data_t data) {

}

void slist_reverse(slist_t *slist) {
  snode_t *first = slist->next;
  if (first == NULL || first->next == NULL)
    return;

  snode_t *n = first->next;
  first->next = NULL;

  snode_t *temp;
  while (n != NULL) {
    temp = n->next;
    n->next = first;
    first = n;
    n = temp;
  }
}
void slist_sort(slist_t *list, int (*compare)(data_t first, data_t second)) {

}

slist_t* slist_combine(slist_t *first, slist_t *second) {

}

int slist_is_cycle(slist_t *slist) {
  //快慢指针
  snode_t *fast = slist->next;
  snode_t *slow = slist->next;

  while (fast != NULL && slow != NULL) {
    fast = fast->next;
    if (fast == NULL)
      break;

    fast = fast->next;
    slow = slow->next;

    if (fast == slow)
      return 1;
  }

  return 0;
}

snode_t *slist_middle(slist_t *slist) {
  //快慢指针
  snode_t *fast = slist->next;
  snode_t *slow = slist->next;

  while (fast != NULL && slow != NULL) {
    fast = fast->next;
    if (fast == NULL)
      break;

    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}