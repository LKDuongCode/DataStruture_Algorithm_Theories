### NGĂN XẾP VÀ NGUYÊN TẮC LIFO

**1. Tổng quan**

- Stack là cấu trúc dữ liệu theo thứ tự tuyến tính. Các phần tử được thêm và xóa chỉ từ một đầu ngăn xếp (đỉnh-top). Được ví như chồng đĩa.
  Thường được biểu diễn dưới dạng array || linked list và tuân theo quy tắc LIFO (last in first out).
- Nguyên tắc LIFO (vào sau ra trước) được áp dụng cho nhiều bài toán như quay lui (backtracking), kiểm tra cặp dấu ngoặc hợp lệ hoặc gọi đệ quy.

- Khởi tạo một stack:
  `array:`

```c
#include <stdio.h>
#define MAX 5 // Kích thước tối đa của ngăn xếp

typedef struct {
    int data[MAX]; // Mảng chứa các phần tử của ngăn xếp
    int top;       // Con trỏ chỉ vị trí phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = -1; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm kiểm tra ngăn xếp đầy
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Hàm thêm phần tử vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngăn xếp đầy. Không thể thêm %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value; // Thêm phần tử vào đỉnh ngăn xếp
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Hàm main
int main() {
    Stack stack;
    initStack(&stack);

    // Thêm dữ liệu cứng vào ngăn xếp
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    // Hiển thị ngăn xếp
    display(&stack);

    return 0;
}
```

`linked list`

```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;           // Giá trị của phần tử
    struct Node *next;  // Con trỏ đến phần tử tiếp theo
} Node;

// Định nghĩa cấu trúc Stack
typedef struct {
    Node *top; // Con trỏ đến phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = NULL; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Hàm thêm phần tử vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Tạo một nút mới
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        return;
    }
    newNode->data = value;       // Gán giá trị cho nút mới
    newNode->next = stack->top;  // Nối nút mới vào đầu ngăn xếp
    stack->top = newNode;        // Cập nhật con trỏ top
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    Node *current = stack->top;
    printf("Các phần tử trong ngăn xếp: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm main
int main() {
    Stack stack;
    initStack(&stack);

    // Thêm dữ liệu cứng vào ngăn xếp
    push(&stack, 5);
    push(&stack, 15);
    push(&stack, 25);
    push(&stack, 35);

    // Hiển thị ngăn xếp
    display(&stack);

    return 0;
}

```

**2. Các thao tác cơ bản**

- `Push` : thêm một phần tử mới vào đỉnh stack
  đối với mảng

```c
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 // Kích thước tối đa của ngăn xếp

typedef struct {
    int data[MAX_SIZE]; // Mảng lưu trữ các phần tử trong ngăn xếp
    int top;            // Chỉ số của phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = -1; // Ngăn xếp bắt đầu rỗng
}

// Hàm kiểm tra ngăn xếp đầy
int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Hàm thêm phần tử mới vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngăn xếp đầy! Không thể thêm %d.\n", value);
        return;
    }
    stack->data[++stack->top] = value; // Thêm phần tử vào đỉnh ngăn xếp
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (stack->top == -1) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Hàm main để thực thi
int main() {
    Stack stack;          // Khởi tạo ngăn xếp
    initStack(&stack);    // Khởi tạo trạng thái ban đầu

    // Thực hiện thao tác Push
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    push(&stack, 60); // Thao tác này sẽ báo lỗi vì ngăn xếp đầy

    // Hiển thị ngăn xếp sau khi thêm phần tử
    display(&stack);

    return 0;
}

```

đối với linkedList

```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;           // Dữ liệu của node
    struct Node *next;  // Con trỏ trỏ tới node tiếp theo
} Node;

// Định nghĩa cấu trúc Stack
typedef struct {
    Node *top; // Con trỏ trỏ tới đỉnh của ngăn xếp
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = NULL; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Hàm thêm phần tử mới vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho node mới
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ để thêm phần tử.\n");
        return;
    }
    newNode->data = value;      // Gán dữ liệu cho node mới
    newNode->next = stack->top; // Con trỏ next trỏ tới phần tử đỉnh hiện tại
    stack->top = newNode;       // Cập nhật đỉnh ngăn xếp
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    Node *temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm main để thực thi
int main() {
    Stack stack;         // Khởi tạo ngăn xếp
    initStack(&stack);   // Khởi tạo trạng thái ban đầu

    // Thực hiện thao tác Push
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Hiển thị ngăn xếp sau khi thêm phần tử
    display(&stack);

    return 0;
}

```

- `Pop ` : lấy phần tử trên cùng ra khỏi ngăn xếp và trả lại giá trị đã lấy ra.
  đối với array

```c
#include <stdio.h>
#define MAX 100 // Kích thước tối đa của ngăn xếp

// Định nghĩa cấu trúc Stack
typedef struct {
    int data[MAX]; // Mảng lưu trữ các phần tử
    int top;       // Chỉ số của phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = -1; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm kiểm tra ngăn xếp đầy
int isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Hàm thêm phần tử mới vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Ngăn xếp đầy, không thể thêm phần tử.\n");
        return;
    }
    stack->data[++stack->top] = value; // Tăng top, sau đó thêm phần tử vào mảng
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}

// Hàm lấy phần tử trên cùng ra khỏi ngăn xếp (Pop)
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng, không thể thực hiện thao tác pop.\n");
        return -1; // Giá trị đặc biệt khi ngăn xếp rỗng
    }
    int poppedValue = stack->data[stack->top--]; // Lấy giá trị tại top, sau đó giảm top
    printf("Đã lấy %d ra khỏi ngăn xếp.\n", poppedValue);
    return poppedValue;
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Hàm main để thực thi
int main() {
    Stack stack;         // Khởi tạo ngăn xếp
    initStack(&stack);   // Khởi tạo trạng thái ban đầu

    // Thêm phần tử vào ngăn xếp
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Hiển thị ngăn xếp
    display(&stack);

    // Lấy phần tử ra khỏi ngăn xếp
    pop(&stack);
    pop(&stack);

    // Hiển thị ngăn xếp sau khi Pop
    display(&stack);

    return 0;
}

```

đối với linked list

```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;           // Dữ liệu của node
    struct Node *next;  // Con trỏ trỏ tới node tiếp theo
} Node;

// Định nghĩa cấu trúc Stack
typedef struct {
    Node *top; // Con trỏ trỏ tới đỉnh của ngăn xếp
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = NULL; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Hàm thêm phần tử mới vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Cấp phát bộ nhớ cho node mới
    if (newNode == NULL) {
        printf("Không đủ bộ nhớ để thêm phần tử.\n");
        return;
    }
    newNode->data = value;      // Gán dữ liệu cho node mới
    newNode->next = stack->top; // Con trỏ next trỏ tới phần tử đỉnh hiện tại
    stack->top = newNode;       // Cập nhật đỉnh ngăn xếp
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}

// Hàm lấy phần tử trên cùng ra khỏi ngăn xếp (Pop)
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng, không thể thực hiện thao tác pop.\n");
        return -1; // Trả về giá trị đặc biệt nếu ngăn xếp rỗng
    }
    Node *temp = stack->top;         // Lưu lại phần tử trên cùng
    int poppedValue = temp->data;    // Lấy giá trị của phần tử này
    stack->top = stack->top->next;   // Cập nhật đỉnh ngăn xếp
    free(temp);                      // Giải phóng bộ nhớ của phần tử cũ
    printf("Đã lấy %d ra khỏi ngăn xếp.\n", poppedValue);
    return poppedValue;              // Trả về giá trị vừa lấy
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    Node *temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm main để thực thi
int main() {
    Stack stack;         // Khởi tạo ngăn xếp
    initStack(&stack);   // Khởi tạo trạng thái ban đầu

    // Thêm phần tử vào ngăn xếp
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Hiển thị ngăn xếp
    display(&stack);

    // Lấy phần tử ra khỏi ngăn xếp
    pop(&stack);
    pop(&stack);

    // Hiển thị ngăn xếp sau khi Pop
    display(&stack);

    return 0;
}

```

- `Peek ` : kiểm tra giá trị của phần tử trên cùng stack.
  đối với array

```c
#include <stdio.h>
#define MAX 100 // Kích thước tối đa của ngăn xếp

// Định nghĩa cấu trúc Stack
typedef struct {
    int data[MAX]; // Mảng lưu trữ các phần tử
    int top;       // Chỉ số của phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = -1; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Hàm thêm phần tử mới vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    if (stack->top == MAX - 1) {
        printf("Ngăn xếp đầy, không thể thêm phần tử.\n");
        return;
    }
    stack->data[++stack->top] = value;
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}

// Hàm kiểm tra giá trị của phần tử trên cùng (Peek)
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng, không có phần tử nào để kiểm tra.\n");
        return -1; // Giá trị đặc biệt cho biết ngăn xếp rỗng
    }
    return stack->data[stack->top]; // Trả về giá trị của phần tử trên cùng
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    printf("Các phần tử trong ngăn xếp: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");
}

// Hàm main để thực thi
int main() {
    Stack stack;         // Khởi tạo ngăn xếp
    initStack(&stack);   // Khởi tạo trạng thái ban đầu

    // Thêm phần tử vào ngăn xếp
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Hiển thị ngăn xếp
    display(&stack);

    // Kiểm tra phần tử trên cùng bằng Peek
    int topValue = peek(&stack);
    if (topValue != -1) {
        printf("Phần tử trên cùng của ngăn xếp là: %d\n", topValue);
    }

    // Hiển thị ngăn xếp sau thao tác Peek (không thay đổi)
    display(&stack);

    return 0;
}

```

đối với linked list

```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc Node
typedef struct Node {
    int data;           // Giá trị của phần tử
    struct Node *next;  // Con trỏ đến phần tử tiếp theo
} Node;

// Định nghĩa cấu trúc Stack
typedef struct Stack {
    Node *top; // Con trỏ đến phần tử trên cùng
} Stack;

// Hàm khởi tạo ngăn xếp
void initStack(Stack *stack) {
    stack->top = NULL; // Ban đầu ngăn xếp rỗng
}

// Hàm kiểm tra ngăn xếp rỗng
int isEmpty(Stack *stack) {
    return stack->top == NULL;
}

// Hàm thêm phần tử vào ngăn xếp (Push)
void push(Stack *stack, int value) {
    Node *newNode = (Node *)malloc(sizeof(Node)); // Tạo một nút mới
    if (newNode == NULL) {
        printf("Không thể cấp phát bộ nhớ.\n");
        return;
    }
    newNode->data = value;    // Gán giá trị cho nút
    newNode->next = stack->top; // Nối nút mới vào đầu ngăn xếp
    stack->top = newNode;     // Cập nhật con trỏ top
    printf("Đã thêm %d vào ngăn xếp.\n", value);
}

// Hàm kiểm tra giá trị phần tử trên cùng (Peek)
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng, không có phần tử nào để kiểm tra.\n");
        return -1; // Giá trị đặc biệt cho biết ngăn xếp rỗng
    }
    return stack->top->data; // Trả về giá trị phần tử trên cùng
}

// Hàm hiển thị các phần tử trong ngăn xếp
void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Ngăn xếp rỗng.\n");
        return;
    }
    Node *current = stack->top;
    printf("Các phần tử trong ngăn xếp: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Hàm main để thực thi
int main() {
    Stack stack;         // Khởi tạo ngăn xếp
    initStack(&stack);   // Khởi tạo trạng thái ban đầu

    // Thêm phần tử vào ngăn xếp
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    // Hiển thị ngăn xếp
    display(&stack);

    // Kiểm tra phần tử trên cùng bằng Peek
    int topValue = peek(&stack);
    if (topValue != -1) {
        printf("Phần tử trên cùng của ngăn xếp là: %d\n", topValue);
    }

    // Hiển thị ngăn xếp sau thao tác Peek (không thay đổi)
    display(&stack);

    return 0;
}

```

**3. Ứng dụng**

- **Quản lí đệ quy**: quản lí các hàm gọi đệ quy. thông tin hàm được gọi lưu vào ngăn xếp. Khi hoàn thành, thông tin đó được lấy ra từ stack và quay trở lại thời điểm gọi.
- **Kiểm tra cặp dấu ngoặc**: vuông, đơn, nhọn. Logic: gặp dấu mở => thêm vào stack ; gặp dấu đóng kiểm tra stack xem có tương ứng không. Nếu không biểu thức invalid.
- **Biểu thức hậu tố và tiền tố (post fix - pre fix)**: lưu trữ toán hạng vào stack và thực hiện phép toán khi gặp toán tử.
- **Lịch sử truy cập trong trình duyệt**: lưu trữ lịch sử truy cập của người dùng.
- **Undo/Redo**: mỗi thao tác thực hiện được thêm vào ngăn xếp cho phép người dùng undo/redo.
- **Phân tích biểu thức**: phân tích cú pháp biểu thức trong ngôn ngữ lập trình => thực hiện trình biên dịch hoặc thông dịch.
- **Chuyển đổi giữa các hệ đếm**: quản lí các số hệ đếm nhị phân, thập phân,...
