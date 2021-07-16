/**
 * 实现链表。
 * 删除链表，还没有实现
 */
#include <stdlib.h>
#include "io_utils_teacher.h"

typedef struct ListNode {
  int value;
  struct ListNode *next;
} ListNode;

/**
 * 创建一个链表节点
 * @param value
 * @return
 */
ListNode *CreateListNode(int value) {
  ListNode *node = malloc(sizeof(ListNode));
  if (!node) exit(1); //如果申请内存失败，则退出

  node->value = value;
  return node;
}

/**
 * 销毁节点
 * @param node_ptr
 */
void DestroyListNode(ListNode **node_ptr) {
  (*node_ptr)->next = NULL;
  free(*node_ptr);
  *node_ptr = NULL;
}

/**
 * 创建链表
 * @param arr
 * @param length
 * @return
 */
ListNode *CreateList(int arr[], int length) {
  if (length <= 0) return NULL;
  ListNode *head = CreateListNode(arr[0]);
  ListNode *current = head;
  for (int i = 1; i < length; ++i) {
    current->next = CreateListNode(arr[i]);
    current = current->next;
  }
  return head;
}

/**
 * 销毁链表
 * @param list
 */
void DestroyList(ListNode **list) {
  if (!list || !(*list)) {
    printf("List is empty!\n");
    return;
  }

  ListNode *cur = *list;
  while (cur) {
    ListNode *tobe_destroy = cur;
    cur = cur->next;
    DestroyListNode(&tobe_destroy);
  }

  list = NULL;
  printf("List is cleared!\n");
}

/**
 * 打印链表元素
 * @param head
 */
void PrintList(ListNode *head) {
  printf("[");
  while (head) {
    printf("%d", (head->value));
    head = head->next;
    if (head) {
      printf(", ");
    }
  }
  printf("]\n");
}

/**
 * 插入链表
 * @param list
 * @param value
 * @param index
 */
void InsertListNode(ListNode **list, int value, int index) {
  if (!list || index < 0) {
    printf("Insert Failed\n");
    return ;
  };

  ListNode *new_node = CreateListNode(value);
  ListNode *head = *list;
  if (index == 0) { //插入头节点
    new_node->next = head;
    *list = new_node; //header 应该执行最前面
  } else {
    ListNode *pre = *list;
    while (index > 1) {

      pre = pre->next;
      if (!pre) {
        printf("Insert Failed, index too big: %d\n", index);
        return;
      }
      index--;
    }
    new_node->next = pre->next;
    pre->next = new_node;
  }

}

int main() {

  int arr[] = {0, 1, 2, 3, 4, 5};
  ListNode *list = CreateList(arr, 6);
  PrintList(list);

  InsertListNode(&list, 66, 0);
  InsertListNode(&list, 65, 0);
  InsertListNode(&list, 64, 5);
  InsertListNode(&list, 640, 7);

  PrintList(list);
  DestroyList(&list);

  return 0;
}