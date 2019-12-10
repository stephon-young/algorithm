// 单链表单元测试

#include "slist.h"
#include <stdio.h>
#include <stdlib.h> // for NULL.

void test_slist() {

  printf("slist test......\n");
  printf(" [initialize] ");
  slist_t *list;
  if ((list = slist_initialize()) == NULL) {
    printf("failed\n");
    return;
  }
  printf("pass\n");

  int append_fail = 0;
  int length_fail = 0;
  for (int i = 0; i < 10; i++) {
    if (slist_append(list, i) != 0)
      append_fail++;

    if (slist_length(list) != i + 1)
      length_fail++;
  }
  printf(" [append] %s\n", (append_fail > 0 ? "failed" : "pass"));
  printf(" [length] %s\n", (length_fail > 0 ? "failed" : "pass"));

  int get_fail = 0;
  int locate_fail = 0;
  for (int i = 0; i < 10; i++) {
    int data;
    if (slist_get(list, i + 1, &data) != 0 || data != i)
      get_fail++;

    if (slist_locate(list, i) != i + 1)
      locate_fail++;
  }
  printf(" [get] %s\n", (get_fail > 0 ? "failed" : "pass"));
  printf(" [locate] %s\n", (locate_fail > 0 ? "failed" : "pass"));

  int remove_fail = 0;
  for (int i = 10; i > 0; i--) {
    if (slist_remove(list, i, NULL) != 0)
      remove_fail++;
  }
  printf(" [remove] %s\n", (remove_fail > 0 ? "failed" : "pass"));

  int insert_fail = 0;
  for (int i = 0; i < 10; i++) {
    if (slist_insert(list, i + 1, i) != 0)
      insert_fail++;
  }
  printf(" [insert] %s\n", (insert_fail > 0 ? "failed" : "pass"));

  get_fail = 0;
  locate_fail = 0;
  for (int i = 0; i < 10; i++) {
    int data;
    if (slist_get(list, i + 1, &data) != 0 || data != i)
      get_fail++;
    if (slist_locate(list, i) != i + 1)
      locate_fail++;
  }
  printf(" [get] %s\n", (get_fail > 0 ? "failed" : "pass"));
  printf(" [locate] %s\n", (locate_fail > 0 ? "failed" : "pass"));

  slist_reverse(list);
  get_fail = 0;
  locate_fail = 0;
  for (int i = 0; i < 10; i++) {
    int data;
    if (slist_get(list, i + 1, &data) != 0 || data !=  9 - i)
      get_fail++;
    if (slist_locate(list, 9 - i) != i + 1)
      locate_fail++;
  }
  printf(" [reverse] %s\n", (get_fail > 0 ? "failed" : "pass"));
  printf(" [get] %s\n", (get_fail > 0 ? "failed" : "pass"));
  printf(" [locate] %s\n", (locate_fail > 0 ? "failed" : "pass"));

  int cycle;
  cycle = slist_is_cycle(list);
  printf(" [is cycle] %s\n", (cycle == 1 ? "failed" : "pass"));

  slist_finalize(list);
}

int main() {
  test_slist();
  return 0;
}