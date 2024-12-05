### Tổng quan về danh sách liên kết

1. Giới thiệu

- Là cấu trúc dữ liệu thường dùng lưu và quản lí các phần tử (or nút).
- Cấu trúc: gồm chuỗi các nút, mỗi nút chứa 2 tp chính:
  - `dữ liệu` thông tin lưu trữ.
  - `liên kết (con trỏ)` tham chiếu đến nút tiếp theo trong list.
- Phân loại:
  - `dslk đơn` mỗi nút chỉ chứa 1 con trỏ đến nút tiếp.
  - `dslk đôi` chứa 2 con trỏ - trước đó và tiếp theo.
- Các thao tác cơ bản:
  - `Thêm nút (Insertion):` chèn nút mới vào.
  - `Xóa nút (Deletion):` xóa 1 nút.
  - `Tìm kiếm (Searching):` tìm dựa trên giá trị dữ liệu.
  - `Duyệt danh sách (Traversal):` thực hiện hành động trên mỗi nút.
- Ưu điểm:
  - linh hoạt: không cần thay đổi kích thước và chuyển vị trí như mảng khi thêm, xóa.
  - không cần xác định trước kích thước.
- Nhược điểm:
  - tốn bộ nhớ do dùng con trỏ: mỗi node cần thêm con trỏ.
  - muốn truy cập một nút cần duyệt từ đầu.
- Ứng dụng:
  - thuật toán duyệt đồ thị, quản lí hàng đợi, ngăn xếp.
  - thường xuyên thêm or xóa.

2. Cấu trúc của một nút trong dslk

- `data`: lưu trữ thông tin mà nút đại diện (type any)
- `link/pointer`: con trỏ đến nút tiếp theo. Trong dslk đơn 1 ptr(node tiếp)/node; đôi 2 ptr(node tiếp-node trước)/node.
- ví dụ định nghĩa một node trong C:

```c
struct Node{
    int data; //dữ liệu lưu trữ
    struct Node*next; //con trỏ đến node sau.
}
```

- giả sử có danh sách liên kết đơn với 3 nút cấu trúc sẽ như sau
  - node1: data = 5; next(node2)
  - node2: data = 9; next(node3)
  - node3: data = 20; next(null)

3. Các thao tác cơ bản (4)

- `Insertion`

  - vị trí: đầu, giữa, cuối.
  - **thêm vào đầu:**

    ```c
    // Định nghĩa cấu trúc nút
    typedef struct Node {
      int data;
      struct Node* next;
    } Node;

    // Hàm thêm vào đầu danh sách
    void addAtHead(Node** head, int value) {
      // Bước 1: Tạo nút mới
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->data = value;

      // Bước 2: Gán con trỏ của nút mới trỏ đến nút đầu hiện tại
      newNode->next = *head;

      // Bước 3: Cập nhật con trỏ đầu danh sách
      *head = newNode;
    }

    // Hàm in danh sách
    void printList(Node* head) {
      while (head != NULL) {
          printf("%d -> ", head->data);
          head = head->next;
      }
      printf("NULL\n");
    }

    int main() {
      Node* head = NULL; // Danh sách ban đầu rỗng

      addAtHead(&head, 10); // Thêm 10 vào đầu danh sách
      addAtHead(&head, 20); // Thêm 20 vào đầu danh sách
      addAtHead(&head, 30); // Thêm 30 vào đầu danh sách

      printList(head); // In danh sách: 30 -> 20 -> 10 -> NULL

      return 0;
    }
    ```

  - **thêm vào cuối:** duyệt từ đầu => kiểm tra node có next(null) => thay next node cuối = next(&node mới)

  ```c
  // Định nghĩa cấu trúc một nút trong danh sách liên kết
  struct Node {
      int data;
      struct Node* next;
  };

  // Hàm tạo một nút mới
  struct Node* createNode(int value) {
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = value;
      newNode->next = NULL;
      return newNode;
  }

  // Hàm thêm nút vào cuối danh sách
  void append(struct Node** head, int value) {
      struct Node* newNode = createNode(value);

      // Nếu danh sách rỗng, đặt nút mới là đầu danh sách
      if (*head == NULL) {
          *head = newNode;
          return;
      }

      // Duyệt qua danh sách cho đến khi tìm nút cuối cùng
      struct Node* temp = *head;
      while (temp->next != NULL) {
          temp = temp->next;
      }

      // Cập nhật con trỏ của nút cuối cùng để trỏ đến nút mới
      temp->next = newNode;
  }

  // Hàm in danh sách liên kết
  void printList(struct Node* head) {
      struct Node* temp = head;
      while (temp != NULL) {
          printf("%d -> ", temp->data);
          temp = temp->next;
      }
      printf("NULL\n");
  }

  int main() {
      struct Node* head = NULL;  // Khởi tạo danh sách liên kết rỗng

      append(&head, 10);  // Thêm 10 vào cuối danh sách
      append(&head, 20);  // Thêm 20 vào cuối danh sách
      append(&head, 30);  // Thêm 30 vào cuối danh sách

      printList(head);  // In danh sách

      return 0;
  }
  ```

  - **thêm vào giữa:** duyệt từ đầu đến vị trí thêm => node trước sẽ trỏ vào node mới, node mới sẽ trỏ vào node cũ.

```c
// Định nghĩa cấu trúc một nút trong danh sách liên kết
struct Node {
   int data;
   struct Node* next;
};

// Hàm tạo một nút mới
struct Node* createNode(int value) {
   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
   newNode->data = value;
   newNode->next = NULL;
   return newNode;
}

// Hàm thêm nút vào giữa danh sách
void insertAtPosition(struct Node** head, int value, int position) {
   struct Node* newNode = createNode(value);

   // Nếu chèn vào đầu danh sách (position = 0)
   if (position == 0) {
       newNode->next = *head;
       *head = newNode;
       return;
   }

   // Duyệt đến vị trí cần chèn
   struct Node* temp = *head;
   int currentPosition = 0;

   while (temp != NULL && currentPosition < position - 1) {
       temp = temp->next;
       currentPosition++;
   }

   // Nếu vị trí hợp lệ, chèn nút mới
   if (temp != NULL) {
       newNode->next = temp->next;
       temp->next = newNode;
   } else {
       printf("Vị trí không hợp lệ\n");
   }
}

// Hàm in danh sách liên kết
void printList(struct Node* head) {
   struct Node* temp = head;
   while (temp != NULL) {
       printf("%d -> ", temp->data);
       temp = temp->next;
   }
   printf("NULL\n");
}

int main() {
   struct Node* head = NULL;  // Khởi tạo danh sách liên kết rỗng

   // Thêm nút vào đầu danh sách
   insertAtPosition(&head, 10, 0);  // Thêm 10 vào đầu
   insertAtPosition(&head, 20, 1);  // Thêm 20 vào cuối
   insertAtPosition(&head, 30, 1);  // Thêm 30 vào vị trí 1

   printList(head);  // In danh sách

   return 0;
}
```

- `Deletion`

  - vị trí: đầu, cuối, giữa
  - **Xóa đầu:** head trỏ đến node thứ 2 => giải phóng node đầu.

  ```C
  // Định nghĩa cấu trúc một nút trong danh sách liên kết
  struct Node {
      int data;
      struct Node* next;
  };

  // Hàm tạo một nút mới
  struct Node* createNode(int value) {
      struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
      newNode->data = value;
      newNode->next = NULL;
      return newNode;
  }

  // Hàm thêm nút vào đầu danh sách
  void insertAtHead(struct Node** head, int value) {
      struct Node* newNode = createNode(value);
      newNode->next = *head;
      *head = newNode;
  }

  // Hàm xóa nút đầu danh sách
  void deleteHead(struct Node** head) {
      if (*head == NULL) {
          printf("Danh sách rỗng, không thể xóa.\n");
          return;
      }

      struct Node* temp = *head;  // Lưu nút đầu
      *head = (*head)->next;      // Cập nhật con trỏ đầu danh sách
      free(temp);                 // Giải phóng bộ nhớ nút đầu
      printf("Đã xóa nút đầu danh sách.\n");
  }

  // Hàm in danh sách liên kết
  void printList(struct Node* head) {
      struct Node* temp = head;
      while (temp != NULL) {
          printf("%d -> ", temp->data);
          temp = temp->next;
      }
      printf("NULL\n");
  }

  int main() {
      struct Node* head = NULL;  // Khởi tạo danh sách rỗng

      // Thêm nút vào đầu danh sách
      insertAtHead(&head, 10);
      insertAtHead(&head, 20);
      insertAtHead(&head, 30);

      printf("Danh sách ban đầu:\n");
      printList(head);

      // Xóa nút đầu danh sách
      deleteHead(&head);

      printf("Danh sách sau khi xóa nút đầu:\n");
      printList(head);

      return 0;
  }
  ```

  - **Xóa cuối** tìm node trước cuối => chuyển node đó next(null)=> free(node cuối)

  ```C
  // Định nghĩa cấu trúc nút
  typedef struct Node {
      int data;
      struct Node* next;
  } Node;

  // Hàm xóa nút cuối
  void deleteLastNode(Node** head) {
      // Kiểm tra danh sách rỗng
      if (*head == NULL) {
          printf("Danh sách rỗng.\n");
          return;
      }

      // Trường hợp chỉ có một nút
      if ((*head)->next == NULL) {
          free(*head);
          *head = NULL;
          return;
      }

      // Trường hợp nhiều nút
      Node* temp = *head;
      while (temp->next->next != NULL) { // Duyệt đến nút trước nút cuối
          temp = temp->next;
      }

      free(temp->next); // Giải phóng nút cuối
      temp->next = NULL; // Cập nhật con trỏ nút trước thành NULL
  }

  // Hàm tạo nút mới
  Node* createNode(int data) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->data = data;
      newNode->next = NULL;
      return newNode;
  }

  // Hàm hiển thị danh sách
  void printList(Node* head) {
      while (head != NULL) {
          printf("%d -> ", head->data);
          head = head->next;
      }
      printf("NULL\n");
  }

  // Main
  int main() {
      Node* head = createNode(10);
      head->next = createNode(20);
      head->next->next = createNode(30);

      printf("Danh sách ban đầu:\n");
      printList(head);

      printf("\nXóa nút cuối:\n");
      deleteLastNode(&head);
      printList(head);

      printf("\nXóa nút cuối lần nữa:\n");
      deleteLastNode(&head);
      printList(head);

      return 0;
  }
  ```

  - **Xóa giữa** tìm node(trước) node xóa => node(xóa): next(node sau) => free(node xóa)

  ```C
  // Định nghĩa cấu trúc nút
  typedef struct Node {
      int data;
      struct Node* next;
  } Node;

  // Hàm xóa nút tại vị trí `position`
  void deleteAtPosition(Node** head, int position) {
      // Kiểm tra danh sách rỗng
      if (*head == NULL) {
          printf("Danh sách rỗng.\n");
          return;
      }

      Node* temp = *head;

      // Nếu nút cần xóa là nút đầu tiên
      if (position == 0) {
          *head = temp->next; // Cập nhật head trỏ đến nút thứ hai
          free(temp);         // Giải phóng nút đầu tiên
          return;
      }

      // Tìm nút trước nút cần xóa
      for (int i = 0; temp != NULL && i < position - 1; i++) {
          temp = temp->next;
      }

      // Nếu vị trí không hợp lệ (vượt quá số nút)
      if (temp == NULL || temp->next == NULL) {
          printf("Vị trí không hợp lệ.\n");
          return;
      }

      // Lưu con trỏ tới nút cần xóa
      Node* nodeToDelete = temp->next;
      temp->next = nodeToDelete->next; // Bỏ qua nút cần xóa
      free(nodeToDelete);             // Giải phóng bộ nhớ của nút cần xóa
  }

  // Hàm tạo nút mới
  Node* createNode(int data) {
      Node* newNode = (Node*)malloc(sizeof(Node));
      newNode->data = data;
      newNode->next = NULL;
      return newNode;
  }

  // Hàm hiển thị danh sách
  void printList(Node* head) {
      while (head != NULL) {
          printf("%d -> ", head->data);
          head = head->next;
      }
      printf("NULL\n");
  }

  // Main
  int main() {
      Node* head = createNode(10);
      head->next = createNode(20);
      head->next->next = createNode(30);
      head->next->next->next = createNode(40);

      printf("Danh sách ban đầu:\n");
      printList(head);

      printf("\nXóa nút tại vị trí 2:\n");
      deleteAtPosition(&head, 2); // Xóa nút "30"
      printList(head);

      printf("\nXóa nút tại vị trí 0:\n");
      deleteAtPosition(&head, 0); // Xóa nút "10"
      printList(head);

      return 0;
  }
  ```

- `Traversal`
  - truy cập và thực hiện các thao tác như in, tìm kiếm, tính toán / node.
  ```html
  1.Bắt đầu từ con trỏ head (đầu danh sách). 2.Sử dụng vòng lặp để truy cập từng
  node trong danh sách. 3.Tại mỗi bước, thực hiện hành động cần thiết (ví dụ: in
  giá trị của node). 4.Tiếp tục cho đến khi gặp node có con trỏ next là NULL
  (cuối danh sách).
  ```

```C
// Định nghĩa cấu trúc nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hàm duyệt danh sách và in ra các giá trị
void traverseList(Node* head) {
    Node* current = head; // Bắt đầu từ nút đầu tiên
    printf("Danh sách: ");
    while (current != NULL) { // Duyệt đến khi gặp NULL
        printf("%d -> ", current->data); // In giá trị của nút hiện tại
        current = current->next; // Di chuyển đến nút tiếp theo
    }
    printf("NULL\n");
}

// Hàm tạo nút mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Main
int main() {
    // Tạo danh sách liên kết
    Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    // Duyệt danh sách và in giá trị các nút
    traverseList(head);

    return 0;
}
```
