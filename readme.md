### DANH SÁCH LIÊN KẾT ĐÔI

1. Tổng quan.

- là dạng cấu trúc dữ liệu, các element kết nối với nhau thành một chuỗi. Mỗi phần tử là một node.
- Cấu trúc:(3) data - next - prev.

2. Đặc điểm.

- khả năng truy cập hai chiều.
- dễ chèn và xóa.

3. Ưu nhược.

- U duyệt theo cả hai hướng
- U thêm xóa không cần di chuyển toàn bộ dữ liệu.
- N tốn thêm bộ nhớ cho prev
- N các thao tác truy cập trực tiếp (truy cập ngẫu nhiên) không nhanh bằng mảng do phải duyệt từng nút.

4. Ứng dụng: các ứng dụng yêu cầu khả năng truy cập hai chiều

- trình duyệt web, trình phát đa phương tiện, quản lí bộ nhớ.

5. Các thao tác cơ bản (3)

- `Chèn node mới` : đầu, cuối, giữa.

  - Chèn vào đầu:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;
      struct Node* prev; // Con trỏ trỏ tới nút trước
      struct Node* next; // Con trỏ trỏ tới nút sau
  } Node;

  //hàm tạo node mới
  Node* createNode(int data) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      if (!newNode) {
          printf("Không đủ bộ nhớ để tạo nút mới.\n");
          exit(1);
      }
      newNode->data = data;
      newNode->prev = NULL;
      newNode->next = NULL;
      return newNode;
  }

  void addAtHead(Node** head, int data) {
      Node* newNode = createNode(data); // Tạo nút mới

      if (*head == NULL) { // Nếu danh sách rỗng
          *head = newNode; // Nút mới trở thành đầu danh sách
      } else {
          newNode->next = *head;    // Nút mới trỏ đến nút đầu hiện tại
          (*head)->prev = newNode;  // Nút đầu hiện tại trỏ về nút mới
          *head = newNode;          // Cập nhật Head để nút mới trở thành đầu danh sách
      }
  }

  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại: ");
      while (temp != NULL) {
          printf("%d ", temp->data);
          temp = temp->next;
      }
      printf("\n");
  }

  int main() {
      Node* head = NULL; // Khai báo con trỏ Head trong hàm main

      addAtHead(&head, 10); // Thêm nút với giá trị 10
      addAtHead(&head, 20); // Thêm nút với giá trị 20
      addAtHead(&head, 30); // Thêm nút với giá trị 30

      printList(head); // In danh sách: 30 20 10

      return 0;
  }
  ```

  - chèn vào cuối:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  Node* createNode(int data) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      if (!newNode) {
          printf("Không đủ bộ nhớ để tạo nút mới.\n");
          exit(1);
      }
      newNode->data = data;
      newNode->prev = NULL;
      newNode->next = NULL;
      return newNode;
  }

  void addAtTail(Node** head, Node** tail, int data) {
      Node* newNode = createNode(data); // Tạo nút mới

      if (*tail == NULL) { // Nếu danh sách rỗng
          *head = newNode; // Cả head và tail đều trỏ tới nút mới
          *tail = newNode;
      } else {
          (*tail)->next = newNode;  // Nút cuối hiện tại trỏ đến nút mới
          newNode->prev = *tail;    // Nút mới trỏ ngược lại về nút cuối hiện tại
          *tail = newNode;          // Cập nhật tail để nút mới trở thành cuối danh sách
      }
  }
  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại (đầu -> cuối): ");
      while (temp != NULL) {
          printf("%d ", temp->data);
          temp = temp->next;
      }
      printf("\n");
  }

  int main() {
      Node* head = NULL; // Con trỏ đầu danh sách
      Node* tail = NULL; // Con trỏ cuối danh sách

      addAtTail(&head, &tail, 10); // Thêm nút có giá trị 10 vào cuối
      addAtTail(&head, &tail, 20); // Thêm nút có giá trị 20 vào cuối
      addAtTail(&head, &tail, 30); // Thêm nút có giá trị 30 vào cuối

      printList(head); // In danh sách: 10 20 30

      return 0;
  }

  ```

  - chèn vào giữa:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  Node* createNode(int data) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      if (!newNode) {
          printf("Không đủ bộ nhớ để tạo nút mới.\n");
          exit(1);
      }
      newNode->data = data;
      newNode->prev = NULL;
      newNode->next = NULL;
      return newNode;
  }

  void addAtPosition(Node** head, Node** tail, int position, int data) {
      if (position <= 0) {
          printf("Vị trí không hợp lệ.\n");
          return;
      }

      Node* newNode = createNode(data);
      if (*head == NULL) { // Danh sách rỗng
          *head = newNode;
          *tail = newNode;
          return;
      }

      if (position == 1) { // Thêm vào đầu danh sách
          newNode->next = *head;
          (*head)->prev = newNode;
          *head = newNode;
          return;
      }

      Node* temp = *head;
      int currentPosition = 1;

      // Tìm vị trí chèn
      while (temp != NULL && currentPosition < position - 1) {
          temp = temp->next;
          currentPosition++;
      }

      if (temp == NULL) { // Nếu vị trí vượt quá cuối danh sách, thêm vào cuối
          newNode->prev = *tail;
          (*tail)->next = newNode;
          *tail = newNode;
      } else { // Chèn vào giữa
          newNode->next = temp->next;
          newNode->prev = temp;

          if (temp->next != NULL) {
              temp->next->prev = newNode;
          } else { // Nếu thêm ở cuối, cập nhật tail
              *tail = newNode;
          }

          temp->next = newNode;
      }
  }

  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại (đầu -> cuối): ");
      while (temp != NULL) {
          printf("%d ", temp->data);
          temp = temp->next;
      }
      printf("\n");
  }

  int main() {
      Node* head = NULL; // Con trỏ đầu danh sách
      Node* tail = NULL; // Con trỏ cuối danh sách

      // Thêm vào danh sách
      addAtPosition(&head, &tail, 1, 10); // Thêm 10 vào vị trí 1
      addAtPosition(&head, &tail, 2, 20); // Thêm 20 vào vị trí 2
      addAtPosition(&head, &tail, 3, 30); // Thêm 30 vào vị trí 3
      addAtPosition(&head, &tail, 2, 15); // Thêm 15 vào vị trí 2
      addAtPosition(&head, &tail, 5, 40); // Thêm 40 vào cuối danh sách

      // In danh sách
      printList(head);

      return 0;
  }

  ```

- `Xóa node`: đầu, cuối, giữa.

  - xóa ở đầu:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  void deleteAtHead(Node** head, Node** tail) {
      if (*head == NULL) { // Kiểm tra danh sách rỗng
          printf("Danh sách rỗng, không thể xóa.\n");
          return;
      }

      Node* temp = *head;  // Lưu con trỏ đến nút đầu
      if (*head == *tail) { // Nếu danh sách chỉ có một phần tử
          *head = NULL;
          *tail = NULL;
      } else { // Nếu danh sách có nhiều phần tử
          *head = (*head)->next;   // Cập nhật head trỏ đến nút tiếp theo
          (*head)->prev = NULL;    // Đặt prev của nút mới thành NULL
      }

      free(temp); // Giải phóng bộ nhớ của nút đầu
      printf("Đã xóa nút ở đầu danh sách.\n");
  }

  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại (đầu -> cuối): ");
      while (temp != NULL) {
          printf("%d ", temp->data);
          temp = temp->next;
      }
      printf("\n");
  }

  int main() {
      Node* head = NULL; // Con trỏ đầu danh sách
      Node* tail = NULL; // Con trỏ cuối danh sách

      // Tạo danh sách ví dụ
      Node* node1 = (Node*)malloc(sizeof(Node));
      Node* node2 = (Node*)malloc(sizeof(Node));
      Node* node3 = (Node*)malloc(sizeof(Node));

      node1->data = 10; node1->prev = NULL; node1->next = node2;
      node2->data = 20; node2->prev = node1; node2->next = node3;
      node3->data = 30; node3->prev = node2; node3->next = NULL;

      head = node1;
      tail = node3;

      printf("Danh sách ban đầu:\n");
      printList(head);

      // Xóa nút ở đầu danh sách
      deleteAtHead(&head, &tail);
      printList(head);

      // Xóa tiếp
      deleteAtHead(&head, &tail);
      printList(head);

      // Xóa nút cuối cùng
      deleteAtHead(&head, &tail);
      printList(head);

      // Thử xóa khi danh sách rỗng
      deleteAtHead(&head, &tail);

      return 0;
  }

  ```

  - xóa ở giữa:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  void deleteAtPosition(Node** head, Node** tail, int position) {
      if (*head == NULL) { // Kiểm tra danh sách rỗng
          printf("Danh sách rỗng, không thể xóa.\n");
          return;
      }

      Node* temp = *head;
      int i;

      // Duyệt đến vị trí cần xóa
      for (i = 1; i < position && temp != NULL; i++) {
          temp = temp->next;
      }

      // Nếu vị trí không hợp lệ
      if (temp == NULL) {
          printf("Vị trí không hợp lệ.\n");
          return;
      }

      // Xóa nút đầu
      if (temp == *head) {
          *head = temp->next;
          if (*head != NULL) (*head)->prev = NULL;
          else *tail = NULL; // Nếu danh sách chỉ còn 1 phần tử
      }
      // Xóa nút cuối
      else if (temp == *tail) {
          *tail = temp->prev;
          (*tail)->next = NULL;
      }
      // Xóa nút ở giữa
      else {
          temp->prev->next = temp->next;
          temp->next->prev = temp->prev;
      }

      free(temp); // Giải phóng bộ nhớ của nút bị xóa
      printf("Đã xóa nút ở vị trí %d.\n", position);
  }

  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại (đầu -> cuối): ");
      while (temp != NULL) {
          printf("%d ", temp->data);
          temp = temp->next;
      }
      printf("\n");
  }

  int main() {
      Node* head = NULL; // Con trỏ đầu danh sách
      Node* tail = NULL; // Con trỏ cuối danh sách

      // Tạo danh sách ví dụ
      Node* node1 = (Node*)malloc(sizeof(Node));
      Node* node2 = (Node*)malloc(sizeof(Node));
      Node* node3 = (Node*)malloc(sizeof(Node));
      Node* node4 = (Node*)malloc(sizeof(Node));

      node1->data = 10; node1->prev = NULL; node1->next = node2;
      node2->data = 20; node2->prev = node1; node2->next = node3;
      node3->data = 30; node3->prev = node2; node3->next = node4;
      node4->data = 40; node4->prev = node3; node4->next = NULL;

      head = node1;
      tail = node4;

      printf("Danh sách ban đầu:\n");
      printList(head);

      // Xóa nút ở vị trí 2
      deleteAtPosition(&head, &tail, 2);
      printList(head);

      // Xóa nút ở vị trí 3 (nút cuối)
      deleteAtPosition(&head, &tail, 3);
      printList(head);

      // Xóa nút đầu
      deleteAtPosition(&head, &tail, 1);
      printList(head);

      // Thử xóa khi danh sách chỉ còn 1 nút
      deleteAtPosition(&head, &tail, 1);
      printList(head);

      // Thử xóa khi danh sách rỗng
      deleteAtPosition(&head, &tail, 1);

      return 0;
  }

  ```

  - xóa ở giữa:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  void deleteFromTail(Node** head, Node** tail) {
      // Kiểm tra nếu danh sách rỗng
      if (*tail == NULL) {
          printf("Danh sách rỗng, không thể xóa.\n");
          return;
      }

      Node* temp = *tail;

      // Nếu danh sách chỉ có một nút
      if (*head == *tail) {
          *head = *tail = NULL;
      } else {
          // Cập nhật con trỏ Tail để trỏ đến nút trước
          *tail = (*tail)->prev;
          // Đặt con trỏ Next của nút cuối mới thành NULL
          (*tail)->next = NULL;
      }

      // Xóa nút cũ để giải phóng bộ nhớ
      free(temp);
      printf("Nút ở cuối danh sách đã được xóa.\n");
  }

  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại (đầu -> cuối): ");
      while (temp != NULL) {
          printf("%d ", temp->data);
          temp = temp->next;
      }
      printf("\n");
  }

  int main() {
      Node* head = NULL;  // Con trỏ đầu danh sách
      Node* tail = NULL;  // Con trỏ cuối danh sách

      // Tạo danh sách ví dụ
      Node* node1 = (Node*)malloc(sizeof(Node));
      Node* node2 = (Node*)malloc(sizeof(Node));
      Node* node3 = (Node*)malloc(sizeof(Node));

      node1->data = 10; node1->prev = NULL; node1->next = node2;
      node2->data = 20; node2->prev = node1; node2->next = node3;
      node3->data = 30; node3->prev = node2; node3->next = NULL;

      head = node1;
      tail = node3;

      // In danh sách ban đầu
      printf("Danh sách ban đầu:\n");
      printList(head);

      // Xóa nút ở cuối danh sách
      deleteFromTail(&head, &tail);

      // In lại danh sách sau khi xóa
      printf("Danh sách sau khi xóa nút ở cuối:\n");
      printList(head);

      return 0;
  }

  ```

- `Duyệt danh sách`: đầu -> cuối; cuối-> đầu.

  - duyệt đầu -> cuối:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  void traverseFromHead(Node* head) {
      Node* temp = head;

      // Duyệt qua từng nút trong danh sách
      while (temp != NULL) {
          // Xử lý dữ liệu của nút
          printf("%d ", temp->data);
          temp = temp->next; // Di chuyển đến nút tiếp theo
      }

      printf("\n");
  }

  void printList(Node* head) {
      Node* temp = head;
      printf("Danh sách hiện tại (đầu -> cuối): ");
      traverseFromHead(head); // Sử dụng hàm duyệt
  }

  int main() {
      Node* head = NULL; // Con trỏ đầu danh sách
      Node* tail = NULL; // Con trỏ cuối danh sách

      // Tạo danh sách ví dụ
      Node* node1 = (Node*)malloc(sizeof(Node));
      Node* node2 = (Node*)malloc(sizeof(Node));
      Node* node3 = (Node*)malloc(sizeof(Node));
      Node* node4 = (Node*)malloc(sizeof(Node));

      node1->data = 10; node1->prev = NULL; node1->next = node2;
      node2->data = 20; node2->prev = node1; node2->next = node3;
      node3->data = 30; node3->prev = node2; node3->next = node4;
      node4->data = 40; node4->prev = node3; node4->next = NULL;

      head = node1;
      tail = node4;

      printf("Danh sách ban đầu:\n");
      printList(head); // In danh sách

      return 0;
  }

  ```

  - duyệt từ cuối -> đầu:

  ```c
  #include <stdio.h>
  #include <stdlib.h>

  // Định nghĩa cấu trúc Node
  typedef struct Node {
      int data;              // Dữ liệu
      struct Node* prev;     // Con trỏ đến nút trước
      struct Node* next;     // Con trỏ đến nút sau
  } Node;

  void traverseFromTail(Node* tail) {
      Node* temp = tail;

      // Duyệt qua từng nút từ cuối đến đầu
      while (temp != NULL) {
          // Xử lý dữ liệu của nút
          printf("%d ", temp->data);
          temp = temp->prev; // Di chuyển đến nút trước đó
      }

      printf("\n");
  }

  void printListReverse(Node* tail) {
      Node* temp = tail;
      printf("Danh sách (cuối -> đầu): ");
      traverseFromTail(tail); // Sử dụng hàm duyệt
  }

  int main() {
      Node* head = NULL; // Con trỏ đầu danh sách
      Node* tail = NULL; // Con trỏ cuối danh sách

      // Tạo danh sách ví dụ
      Node* node1 = (Node*)malloc(sizeof(Node));
      Node* node2 = (Node*)malloc(sizeof(Node));
      Node* node3 = (Node*)malloc(sizeof(Node));
      Node* node4 = (Node*)malloc(sizeof(Node));

      node1->data = 10; node1->prev = NULL; node1->next = node2;
      node2->data = 20; node2->prev = node1; node2->next = node3;
      node3->data = 30; node3->prev = node2; node3->next = node4;
      node4->data = 40; node4->prev = node3; node4->next = NULL;

      head = node1;
      tail = node4;

      printf("Danh sách ban đầu:\n");
      printListReverse(tail); // In danh sách từ cuối lên đầu

      return 0;
  }

  ```
