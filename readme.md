### HÀNG ĐỢI VÀ NGUYÊN TẮC FIFO

**1. Tổng quan**

- Là ctdl lưu trữ tập hợp các element, hoạt động theo nguyên lí (fifo = vào trước thì ra trước).
- Đặc điểm:
  - thứ tự: element được sắp xếp theo thứ tự
  - FIFO: được đưa vào trước thì ra trước.
- Các phép toán chính :
  - `enqueue`: thêm vào cuối
  - `dequeue`: loại bỏ phần tử đầu hàng.
- Cách triển khai:
  đối với array.

```c
/**
- front : chỉ số đầu hàng
- rear : chỉ số cuối hàng

- enqueue: kiểm tra nếu hàng đợi chưa đầy thì tăng chỉ số rear và thêm element vào mảng.
- dequeue: kt nếu hàng đ không rỗng thì lấy element ở front, tăng font và trả về giá trị đã lấy.
*/

#include <stdio.h>
#define SIZE 5

// Hàm khởi tạo hàng đợi
void initializeQueue(int queue[]) {
    for (int i = 0; i < SIZE; i++) {
        queue[i] = (i + 1) * 10; // Gán giá trị 10, 20, 30, ...
    }
}

// Hàm in hàng đợi
void printQueue(int queue[]) {
    printf("Hàng đợi: ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int queue[SIZE]; // Khai báo hàng đợi

    // Gọi hàm khởi tạo
    initializeQueue(queue);

    // Gọi hàm in hàng đợi
    printQueue(queue);

    return 0;
}

```

đối với linked list

```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc nút
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Khởi tạo hàng đợi (các con trỏ front và rear)
Node* front = NULL;
Node* rear = NULL;

// Hàm khởi tạo hàng đợi với các giá trị cố định
void initializeQueue() {
    int values[] = {10, 20, 30, 40, 50};
    int size = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < size; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = values[i];
        newNode->next = NULL;

        if (rear == NULL) {
            // Nếu hàng đợi rỗng, cả front và rear đều trỏ đến newNode
            front = rear = newNode;
        } else {
            // Thêm nút vào cuối hàng đợi
            rear->next = newNode;
            rear = newNode;
        }
    }
}

// Hàm in hàng đợi
void printQueue() {
    Node* temp = front;

    if (temp == NULL) {
        printf("Hàng đợi rỗng!\n");
        return;
    }

    printf("Hàng đợi: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm giải phóng bộ nhớ
void freeQueue() {
    Node* temp;

    while (front != NULL) {
        temp = front;
        front = front->next;
        free(temp);
    }
    rear = NULL; // Đặt rear về NULL sau khi giải phóng
}

int main() {
    // Khởi tạo hàng đợi
    initializeQueue();

    // In ra hàng đợi
    printQueue();

    // Giải phóng bộ nhớ sau khi sử dụng
    freeQueue();

    return 0;
}

```

**2. Các thao tác cơ bản** (5)

- Enqueue (Thêm): Thêm một phần tử vào cuối hàng đợi.
- Dequeue (Xóa): Xóa và trả về phần tử ở đầu hàng đợi.
- Peek/Front: Lấy giá trị của phần tử đầu tiên mà không xóa nó.
- IsEmpty: Kiểm tra hàng đợi có rỗng hay không.
- IsFull: Kiểm tra hàng đợi có đầy hay không (trong trường hợp mảng có kích thước cố định).

- Đối với mảng:

```c
#include <stdio.h>
#define SIZE 5

int queue[SIZE];  // Mảng lưu trữ hàng đợi
int front = -1;   // Chỉ số đầu hàng đợi
int rear = -1;    // Chỉ số cuối hàng đợi

// Hàm kiểm tra hàng đợi có rỗng không
int isEmpty() {
    return (front == -1 || front > rear);
}

// Hàm kiểm tra hàng đợi có đầy không
int isFull() {
    return (rear == SIZE - 1);
}

// Hàm thêm phần tử vào hàng đợi (enqueue)
void enqueue(int value) {
    if (isFull()) {
        printf("Hàng đợi đầy, không thể thêm phần tử %d\n", value);
        return;
    }
    if (front == -1) front = 0; // Khởi tạo front khi thêm phần tử đầu tiên
    queue[++rear] = value;      // Tăng rear và thêm phần tử
    printf("Thêm phần tử %d vào hàng đợi\n", value);
}

// Hàm xóa phần tử khỏi hàng đợi (dequeue)
int dequeue() {
    if (isEmpty()) {
        printf("Hàng đợi rỗng, không thể xóa\n");
        return -1;
    }
    int value = queue[front++]; // Lấy phần tử đầu hàng đợi và tăng front
    if (front > rear) {         // Nếu hàng đợi rỗng sau khi xóa
        front = rear = -1;
    }
    return value;
}

// Hàm lấy phần tử đầu hàng đợi mà không xóa (peek)
int peek() {
    if (isEmpty()) {
        printf("Hàng đợi rỗng\n");
        return -1;
    }
    return queue[front];
}

// Hàm in hàng đợi
void printQueue() {
    if (isEmpty()) {
        printf("Hàng đợi rỗng\n");
        return;
    }
    printf("Hàng đợi hiện tại: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    // Thêm phần tử vào hàng đợi
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60); // Hàng đợi đầy, không thêm được

    // In hàng đợi
    printQueue();

    // Lấy phần tử đầu hàng đợi
    printf("Phần tử đầu tiên: %d\n", peek());

    // Xóa phần tử khỏi hàng đợi
    printf("Xóa phần tử: %d\n", dequeue());
    printf("Xóa phần tử: %d\n", dequeue());

    // In hàng đợi sau khi xóa
    printQueue();

    return 0;
}

```

- Enqueue (Thêm): Thêm một phần tử vào cuối hàng đợi.
- Dequeue (Xóa): Xóa và trả về phần tử ở đầu hàng đợi.
- Peek/Front: Lấy giá trị của phần tử đầu tiên mà không xóa nó.
- IsEmpty: Kiểm tra hàng đợi có rỗng hay không.

- Đối với linked list:

```c
#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
typedef struct Node {
    int data;            // Dữ liệu của nút
    struct Node* next;   // Con trỏ trỏ đến nút tiếp theo
} Node;

// Định nghĩa hàng đợi với hai con trỏ front và rear
typedef struct Queue {
    Node* front;         // Con trỏ đầu hàng đợi
    Node* rear;          // Con trỏ cuối hàng đợi
} Queue;

// Hàm khởi tạo hàng đợi rỗng
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

// Hàm kiểm tra hàng đợi rỗng
int isEmpty(Queue* q) {
    return (q->front == NULL);
}

// Hàm thêm phần tử vào hàng đợi (enqueue)
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (q->rear == NULL) { // Nếu hàng đợi rỗng
        q->front = q->rear = newNode;
        printf("Thêm phần tử %d vào hàng đợi\n", value);
        return;
    }

    q->rear->next = newNode; // Gắn nút mới vào cuối hàng đợi
    q->rear = newNode;       // Di chuyển rear đến nút mới
    printf("Thêm phần tử %d vào hàng đợi\n", value);
}

// Hàm xóa phần tử khỏi hàng đợi (dequeue)
int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng, không thể xóa\n");
        return -1;
    }

    Node* temp = q->front;     // Lấy nút đầu hàng đợi
    int value = temp->data;    // Lưu giá trị của nút đầu
    q->front = q->front->next; // Di chuyển front đến nút tiếp theo

    if (q->front == NULL) {    // Nếu hàng đợi rỗng sau khi xóa
        q->rear = NULL;
    }

    free(temp);                // Giải phóng bộ nhớ của nút đầu
    return value;
}

// Hàm lấy giá trị đầu hàng đợi mà không xóa (peek)
int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng\n");
        return -1;
    }
    return q->front->data;
}

// Hàm in hàng đợi
void printQueue(Queue* q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng\n");
        return;
    }

    Node* temp = q->front;
    printf("Hàng đợi hiện tại: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Hàm giải phóng bộ nhớ của hàng đợi
void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    // Khởi tạo hàng đợi
    Queue* q = createQueue();

    // Thêm phần tử vào hàng đợi
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    // In hàng đợi
    printQueue(q);

    // Lấy phần tử đầu hàng đợi
    printf("Phần tử đầu tiên: %d\n", peek(q));

    // Xóa phần tử khỏi hàng đợi
    printf("Xóa phần tử: %d\n", dequeue(q));
    printf("Xóa phần tử: %d\n", dequeue(q));

    // In hàng đợi sau khi xóa
    printQueue(q);

    // Giải phóng bộ nhớ của hàng đợi
    freeQueue(q);

    return 0;
}

```

**3. Ứng dụng**

- Quản Lý Tác Vụ trong Hệ Thống Đa Nhiệm
- Kết Nối Tới Cơ Sở Dữ Liệu
- Truy Xuất Dữ Liệu (Data Streaming)
- Quản Lý Tác Vụ Được Đặt Hẹn (Scheduling)
- Thuật Toán Tìm Kiếm và Duyệt Cây
- Lập Trình Mạng
- Xử Lý Yêu Cầu từ Người Dùng
