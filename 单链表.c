#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int elemtype;
typedef struct node {
  elemtype value;
  struct node *node;
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
  list->node = NULL;
  return list;
}
bool is_empty(linked_list list) {
  bool tag = false;
  if(list->node == NULL) {
    tag = true;
  }
  return tag;
}
bool insert(linked_list list, int local, elemtype value) {
  if(list->value < local) {
    return NULL;
  } else {
    
  }
}
ptr_to_node get_local(linked_list list, elemtype value) {

}
ptr_to_node get_value(linked_list list, int local) {

}
bool delete_value(linked_list list, int local) {

}
bool destory_list(linked_list list) {

}

int main() {

}

/*******************
 * TODO
 * []插入操作
 * []按值查找，返回位
 * []按位查找，返回值
 * []删除元素
 * []销毁列表
 * ******************/