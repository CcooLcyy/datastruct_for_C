/********************
 * TODO
 * [x]初始化双链表
 * [x]链表判空
 * [x]插入链表
 * [x]删除元素
 * [x]修改已插入的值
 * [x]销毁列表
 * [x]打印值
 * []利用实现的基本操作函数做一个小demo 
 * *****************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"linked_list.h"

typedef struct node {
  struct node *prev;
  elemtype value;
  struct node *next;
} node;
typedef node *ptr_to_node;
typedef ptr_to_node double_linked_list;

double_linked_list init_list(void);
bool is_empty(double_linked_list list);
bool insert(double_linked_list list, int local, elemtype value);
bool delete(double_linked_list list, int local);
bool change_value(double_linked_list list, int local, elemtype value);
bool destory_list(double_linked_list list);
void print_value(double_linked_list list);

double_linked_list init_list(void) {
  double_linked_list list = (double_linked_list)malloc(sizeof(double_linked_list));
  list->next = NULL;
  list->value = 0;
  list->prev = NULL;

  return list;
}
bool is_empty(double_linked_list list) {
  if(list->value == 0) {
    return true;
  } else {
    return false;
  }
} 
bool insert(double_linked_list list, int local, elemtype value) {
  // 使表长加1
  list->value++;
  if(local <= list->value && local > 0) {
    int counter = 1;
    while(counter < local) {
      // 查找到需要插入的位置
      list = list->next;
      counter++;
    }
    double_linked_list new_node = (ptr_to_node)malloc(sizeof(ptr_to_node));
    if(list->next == NULL) {
      new_node->next = list->next;
      new_node->prev = list;
      list->next = new_node;
      new_node->value = value;
    } else {
      // 先操作新的节点，防止覆盖
      new_node->next = list->next;
      new_node->prev = list;
      list->next->prev = new_node;
      list->next = new_node;
      new_node->value = value;
    }
  } else {
    return false;
  }
}
bool delete(double_linked_list list, int local) {
  if(local <= list->value && local > 0) {
    list->value--;
    int counter = 1;
    while(counter < local) {
      list = list->next;
      counter++;
    }
    ptr_to_node delete_node = list->next;
    if(delete_node->next == NULL) {
      list->next = delete_node->next;
      free(delete_node);
    } else {
      list->next = delete_node->next;
      delete_node->next->prev = list;
      free(delete_node);
    }
    return true;
  } else {
    return false;
  }
}
bool change_value(double_linked_list list, int local, elemtype value) {
  int counter = 1;
  if(local > 0 && local <= list->value) {
    while(counter <= local) {
      counter++;
      list = list->next;
    }
    list->value = value;
  }
}
bool destory_list(double_linked_list list) {
  if(list->value <= 0 ) {
    return false;
  } else {
    int cycle_time = list->value;
    for(int i = 1; i <= cycle_time; i++) {
      delete(list, list->value);
    }
  }
  return true;
}
void print_value(double_linked_list list) {
  list = list->next;
  while(list != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("\n");
}

// int main() {
//   double_linked_list list = init_list();
//   for(int i = 1; i <= 3; i++) {
//     insert(list, 1, 1);
//   }
//   print_value(list);
//   destory_list(list);
// }