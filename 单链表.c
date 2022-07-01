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
bool insert(linked_list list, int local, elemtype value);
ptr_to_node get_local(linked_list list, elemtype value);
ptr_to_node get_value(linked_list list, int local);
bool delete_value(linked_list list, int local);
bool destory_list(linked_list list);

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
bool insert(linked_list list, int local, elemtype value) {
  if(local <= list->value && local >=0) {
    int counter = 0;
    while(local - 1 >= counter) {
      list = list->next;
      counter++;
    }
    ptr_to_node now_node = (ptr_to_node)malloc(sizeof(ptr_to_node));
    now_node->value = value;
    now_node->next = list->next;
    list->next = now_node;
  } else {
    return NULL;
  }
}
ptr_to_node get_local(linked_list list, elemtype value) {
  
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

}
bool destory_list(linked_list list) {

}

int main() {

}

/**************************
 * TODO
 * [x]插入操作
 * []按值查找，返回位
 * [x]按位查找，返回值
 * []删除元素
 * []销毁列表
 * ************************/