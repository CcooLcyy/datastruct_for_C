#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;
typedef struct node {
  elemtype value;
  struct node *next;
} node;
typedef node *ptr_to_node;
typedef ptr_to_node linked_list;

linked_list init_list();
bool is_empty(linked_list list);
ptr_to_node insert(linked_list list, int local, elemtype value);
ptr_to_node get_local(linked_list list, elemtype value);
ptr_to_node get_value(linked_list list, int local);
bool delete_value(linked_list list, int local);
bool destory_list(linked_list list);
void print_list(linked_list list);

linked_list init_list() {
  ptr_to_node list = (ptr_to_node)malloc(sizeof(ptr_to_node));
  list->value = 0;
  // 第一个节点用来保存表长
  list->next = NULL;
  return list;
}
bool is_empty(linked_list list) {
  bool tag = false;
  if(list->next == NULL) {
    tag = true;
  }
  return tag;
}
ptr_to_node insert(linked_list list, int local, elemtype value) {
  /*************************
   * 判断插入位置是否合法
   * 当链表为空的时候也应该插入，所以list.value+1
   * **********************/
  if(local <= list->value + 1 && local >0) {
    list->value++;
    int counter = 0;
    /**
     * 找到需要插入位置之前的一个位置
     * 从插入位置之前断开
    */
    while(local - 1 > counter) {
      list = list->next;
      counter++;
    }
    ptr_to_node now_node = (ptr_to_node)malloc(sizeof(ptr_to_node));
    now_node->value = value;
    now_node->next = list->next;
    list->next = now_node;
    return now_node;
  } else {
    return NULL;
  }
}
ptr_to_node get_local(linked_list list, elemtype value) {
  list = list->next;
  while(list->value != value) {
    list = list->next;
  }
  return list;
}
ptr_to_node get_value(linked_list list, int local) {
  if(list->value < local) {
    return NULL;
  } else {
    int counter = 0;
    while(counter < local) {
      list = list->next;
      counter++;
    }
  }
  return list;
}
bool delete_value(linked_list list, int local) {
  // 先将表长减一
  list->value--;
  int counter = 0;
  while(local <= list->value - 1 && local > 0) {
  // 索引到上一个节点，以便能将要删除的节点更改指针。
    counter++;
    list = list->next;
  }
  ptr_to_node delete_node = list->next;
  list->next = delete_node->next;
  free(delete_node);
}
bool destory_list(linked_list list) {
  while(list->next != NULL) {
    delete_value(list, list->value);
  }
}
void print_list(linked_list list){
  ptr_to_node list_copyed = list;
  list_copyed = list_copyed->next;
  while(list_copyed != NULL) {
    printf("%d ", list_copyed->value);
    list_copyed = list_copyed->next;
  }
  printf("\n");
}

int main() {
  linked_list list = init_list();
  for(int i = 1; i <= 10; i++) {
    insert(list, i, i);
  }
  print_list(list);
}

/**************************
 * TODO
 * [x]插入操作
 * [x]按值查找，返回位
 * [x]按位查找，返回值
 * [x]删除元素
 * [x]销毁列表
 * [x]打印单链表中的值
 * ************************/