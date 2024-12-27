### ĐỒ THỊ

1. Tổng quan

- là một cấu trúc dữ liệu bao gồm `đỉnh (vertex)` - đại diện cho obj hoặc node và `cạnh (edge)` - liên kết giữa các đỉnh, đại diện cho mqh.
- 3 loại:

  - đồ thị vô hướng: các cạnh không có hướng
    ![vo huong](https://github.com/LKDuongCode/DataStruture_Algorithm_Theories/blob/ss09/vo_huong.jpg?raw=true)
  - đồ thị có hướng: các cạnh có hướng. biểu thị quan hệ một chiều
    ![co huong](https://github.com/LKDuongCode/DataStruture_Algorithm_Theories/blob/ss09/co_huong.jpg?raw=true)
  - đồ thị trong trọng số: các cạnh có trọng số gắn liền (mức độ liên kết giữa các đỉnh).
    ![co trong so](https://github.com/LKDuongCode/DataStruture_Algorithm_Theories/blob/ss09/co_trong_so.jpg?raw=true)

- Các cách biểu diễn đồ thị:

  - Ma trận kề:

    - ma trận vuông V x V (V là số đỉnh). mỗi ô adj[i][j] thể hiện sự tồn tại của các cạnh giữa đỉnh i và đỉnh j.

      - nếu đồ thị là vô hướng: adj[i][j] = adj[j][i]
      - nếu có cạnh giữa hai đỉnh i và j value = 1.(hoặc trọng số của cạnh nếu đồ thị có trọng số) nếu không thì = 0.

      ```c
      #include<stdio.h>
      #define V 4

      void printMatrix(int adj[V][V]){
        for(int i = 0; i< V; i++){
          for(int j = 0; j < V; j++){
            printf("%d", adj[i][j]);
          }
          printf("\n");
        }
      }

      int main(){
        // khoi tao ma tran ke
        int adj[V][V] = {0};

        //them cac canh cho matrix
        adj[0][1] = 1;
        adj[0][2] = 1;
        adj[1][2] = 1;
        adj[2][3] = 1;

        printf("ma tran ke cua do thi: \n");
        printMatrix(adj);
        return 0;
      }
      ```

  - Danh sách kề:

    - sử dụng mảng, trong đố mỗi pt là dslk lưu các đỉnh kề của từng đỉnh.
    - Ưu: tiết kiệm bộ nhớ cho đồ thị thưa, thêm cạnh nhanh chóng.
    - Nhược: Truy cập không trực tiếp, cần duyệt dslk để kiểm tra.

    ```c
    #include <stdio.h>
    #include <stdlib.h>

    //dinh nghia do thi
    #include<stdio.h>
    #include<stdlib.h>
    ```

  // dinh nghia do thi
  struct Node {
  int vertex;
  struct Node\* next;
  };

  struct Graph {
  int numVertices;
  struct Node \*\* adjLists;
  };

  //ham tao moi node (dinh moi) trong ds ke
  struct Node *createNode(int v){
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
  }

  //ham khoi tao do thi
  struct Graph *createGraph(int vertices){
  struct Graph *graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

      graph->adjLists = malloc(vertices * sizeof(struct Node*));
      for(int i = 0; i < vertices; i++){
      	grap->adjList[i] = NULL;
      }

      return graph;

  }

  //them canh vao danh sach ke
  void addEdge(struct Graph * graph, int scr, int dest){
  struct Node *newNode = createGraph(dest);
  newNode->next = graph->adjLists[scr];
  graph->adjLists[scr] = newNode;

      newNode = createGraph(scr); // neu la do thi vo huong
      newNode->next = graph->adjLists[dest];
      graph->adjLists[dest] = newNode;

  }

  // in do thi duoi dang danh sach ke
  void printGraph (struct Graph *graph){
  for (int v = 0; v < graph->numVertices; v++){
  struct Node *temp = graph->adjLists[v];
  printf("\n danh sach ke cua dinh %d \n",v);
  while(temp){
  printf("%d -> ", temp->vertex);
  temp = temp->next;
  }
  printf("NULL \n");
  }
  }
  int main(){
  struct Graph \*graph = createGraph(4);

      addEdge(graph,0,1);
      addEdge(graph,0,2);
      addEdge(graph,1,2);
      addEdge(graph,2,3);

      printGraph(graph);
      return 0;

  }

  ```

  ```

2. Các thuật toán duyệt đồ thị BFS, DFS.

- Duyệt theo chiều rộng (breadth first search) là duyệt tất cả các đỉnh của đồ thị theo từng mức độ bắt đầy từ đỉnh gốc. Sử dụng hàng đợi để lưu trữ các đỉnh cần duyệt

  - Các bước thực hiện:
    - Chọn một đỉnh bắt đầu và đánh dấu đã duyệt.
    - thêm đỉnh này vào hàng đợi
    - lặp lại: lấy đỉnh đầu tiên trong queue và ktra tất cả các đỉnh kề chưa thăm đánh dấu và thêm vào hàng đợi.
    - tiếp tục cho đến khi hàng đợi rỗng.
  - Ưu điểm: tìm kiếm theo mức độ, tìm đường đi ngắn nhất trong đồ thị không trọng số.
  - Nhược điểm: Tốn bộ nhớ nếu đồ thị lớn.

- Duyệt theo chiều sâu (depth first search) là đi sâu vào các đỉnh con của mỗi đỉnh, trước khi quay lại các đỉnh anh em. dùng ngăn xếp hoặc đệ quy.

  - Bước thực hiện: - chọn một đỉnh bắt đầu và đánh dấu đã duyệt - duyệt tất cả các đỉnh kề chưa thăm, gọi đệ quy cho mỗi đỉnh. - tiếp tục cho đến khi duyệt hết đồ thị.
    Ưu điểm: duyệt tất đỉnh
    Nhược điểm: Không đảm bảo tìm kiếm đường đi ngắn nhất và tốn bộ nhớ.

- So sánh hai cách:
  - BFS:
    - Duyệt đồ thị theo mức độ.
    - Dùng hàng đợi (queue).
    - Phù hợp với việc tìm kiếm đường đi ngắn nhất trong đồ thị vô hướng.
    - Dễ dàng tìm ra tất cả các đỉnh ở cùng mức độ.
  - DFS:
    - Duyệt đồ thị theo chiều sâu.
    - Dùng ngăn xếp (stack) hoặc đệ quy.
    - Phù hợp với việc tìm kiếm các thành phần liên thông trong đồ thị.
    - Dễ dàng triển khai nhưng không đảm bảo tìm đường đi ngắn nhất.
