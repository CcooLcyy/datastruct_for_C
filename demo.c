#include"double_linked_list.c"
int input = true;

void case0();
void case1(double_linked_list list);
void case2(double_linked_list list);
void case3(double_linked_list list);
void case4(double_linked_list list);
void case5(double_linked_list list);
void case6(double_linked_list list);
void case7(double_linked_list list);

void case0() {
  printf("程序结束\n");
}
void case1(double_linked_list list) {
  bool cycle_tag = true;
  int local;
  elemtype value;
    while(cycle_tag) {
      printf("* 请输入插入的位置和值\n");
      printf("* 中间使用空格间隔\n");
      scanf("%d %d", &local, &value);
      printf("* 正在插入\n");
      insert(list, local, value);
      printf("* 插入成功\n");
      printf("\n? 是否继续插入\n");
      printf("* 继续插入输入: 1\n");
      printf("* 取消插入输入: 0\n");
      scanf("%d", &cycle_tag);
      printf("\n");
    }
}
void case2(double_linked_list list) {
  bool cycle_tag = true;
  int local;
  elemtype value;
  while(cycle_tag) {
    printf("* 请输入需要删除的位置\n");
    scanf("%d", &local);
    // 判断位置是否合法
    while(local <= 0 || local >list->value) {
      printf("! 输入的位置不合法请输入正确位置\n");
      scanf("%d", &local);
    }
    printf("* 正在删除...\n");
    bool tag = delete(list, local);
    if(tag) {
      printf("* 删除成功\n");
    } else {
      printf("! 删除失败！");
    }
    printf("* 是否继续？\n");
    printf("* 继续输入1，返回上一层输入0\n");
    scanf("%d", cycle_tag);
  }
}
void case3(double_linked_list list) {
  bool cycle_tag = true;
  int local;
  elemtype value;
  while(cycle_tag) {
    printf("* 请输入需要修改的位置与值\n");
    scanf("%d %d", &local, &value);
    while(local <= 0 || local > list->value) {
      printf("! 输入位置不合法\n");
      printf("* 请重新输入\n");
      scanf("%d", &local);
    }
    printf("* 正在修改...\n");
    bool change_tag = change_value(list, local, value);
    if(change_tag) {
      printf("* 修改成功\n\n");
      printf("? 是否继续\n");
      printf("* 继续输入1\n");
      printf("* 退出输入0\n");
    } else {
      printf("! 修改失败\n");
    }
    scanf("%d", &cycle_tag);
  }

}
void case4(double_linked_list list) {
  int destory_tag = 0;
  printf("! 是否确认销毁链表\n");
  printf("* 确认输入1\n");
  printf("* 取消输入0\n");
  scanf("%d", &destory_tag);
  while(destory_tag != 0 && destory_tag != 1) {
    printf("! 请输入有效指令\n");
    scanf("%d", &destory_tag);
  }
  if(destory_tag == 1) {
    printf("! 正在销毁列表...\n");
    destory_list(list);
    printf("! 列表销毁成功\n");
  }
}
void case5(double_linked_list list) {
  if(is_empty(list)) {
    printf("* 链表为空\n");
  } else {
    printf("* 链表非空\n");
  }
}
void case6(double_linked_list list) {
  printf("* 双链表内容如下\n");
  print_value(list);
  printf("\n");
}
void case7(double_linked_list list) {
  int length;
  elemtype value;
  printf("* 请指定长度，并指定需要以什么数字填充\n");
  scanf("%d %d", &length, &value);
  printf("\n* 正在生成...\n");
  for(int i = 1; i <= length; i++) {
    insert(list, i, value);
  }
  printf("* 生成完成\n\n");
}

int main() {
  double_linked_list list = init_list();
  // 这里的input既是控制循环是否继续，又控制输入的指令，使用int
  while(input) {
    printf("* **************************************\n");
    printf("* 已初始化一个空双链表，请进行如下操作\n");
    printf("* 0: 退出程序\n");
    printf("* 1: 指定位置插入数据\n");
    printf("* 2: 删除指定位置的数据\n");
    printf("* 3: 修改指定位置的数据\n");
    printf("* 4: 销毁列表\n");
    printf("* 5: 判断双链表否为空\n");
    printf("* 6: 打印双链表\n");
    printf("* 7: 由指定数据生成重复的指定长度双链表\n");
    printf("* **************************************\n");
    scanf("%d", &input);
    printf("\n");

    switch(input){
    case 0:
      case0();
      break;
    case 1:
      case1(list);
      break;
    case 2:
      case2(list);
      break;
    case 3:
      case3(list);
      break;
    case 4:
      case4(list);
      break;
    case 5:
      case5(list);
      break;
    case 6:
      case6(list);
      break;
    case 7:
      case7(list);
      break;
    default:
      printf("! 需要输入指定的操作\n\n");
      break;
    }
  }
}
