/********************
 * TODO
 * []初始化双链表
 * []链表判空
 * []插入链表
 * []删除链表
 * []修改已插入的值
 * []销毁列表
 * []打印值
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
bool delete(double_linked_list list, int local, elemtype value);
bool change_value(double_linked_list list, int local, elemtype value);
bool destory_list(double_linked_list list);
void print_value(double_linked_list list);

double_linked_list init_list(void) {

}
bool is_empty(double_linked_list list) {

} 
bool insert(double_linked_list list, int local, elemtype value) {

}
bool delete(double_linked_list list, int local, elemtype value) {

}
bool change_value(double_linked_list list, int local, elemtype value) {

}
bool destory_list(double_linked_list list) {

}
void print_value(double_linked_list list) {

}

int main() {

}
