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
    if(delete_node == NULL) {
      free(delete_node);
      list->next = NULL;
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

}
void print_value(double_linked_list list) {
  list = list->next;
  while(list != NULL) {
    printf("%d ", list->value);
    list = list->next;
  }
  printf("\n");
}

int main() {
  double_linked_list list = init_list();
  int input = true;
  while(input) {
    printf("* **************************************\n");
    printf("* 已初始化一个空双链表，请进行如下操作\n");
    printf("* 0: 退出程序\n");
    printf("* 1: 指定位置插入数据\n");
    printf("* 2: 删除指定位置的数据\n");
    printf("* 3: 修改指定位置的数据\n");
    printf("* 4: 销毁列表\n");
    printf("* 5: 判断双链表谁否为空\n");
    printf("* 6: 打印双链表\n");
    printf("* 7: 由指定数据生成重复的指定长度双链表\n");
    printf("* **************************************\n");
    scanf("%d", &input);

    switch(input){
    int local;
    elemtype value;

    case 0:
      printf("程序结束\n");
      break;
    case 1:
      printf("* 请输入插入的位置和值\n");
      printf("* 或者使用q键取消本次输入\n");
      bool cycle_tag = true;
      while(cycle_tag) {
        scanf("%d", &local);
        if(local == 'q' ) {
          cycle_tag = false;
        } else {
          scanf("%d", &value);
          local = (int)local;
          insert(list, local, value);
          printf("! 是否继续插入\n");
          printf("* 继续插入输入: 1\n");
          printf("* 取消插入输入: 0\n");
          scanf("%d", &cycle_tag);
        }
      }
      break;
    case 6:
      printf("* 双链表内容如下\n");
      print_value(list);
      break;
    default:
      printf("需要输入指定的操作\n");
      break;
    }
  }
}
