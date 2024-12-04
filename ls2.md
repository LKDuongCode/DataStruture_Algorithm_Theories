2. Thiết kế giải thuật đệ quy:

   - b1. xác định tham số truyền vào và lấy ra.
   - b2. đưa bài toán về trường hợp nhỏ hơn cùng tính chất dần đến suy biến.
   - b3. tìm suy biến (điểm dừng).

3. ví dụ tính giai thừa một số:

   ```c
   /*
   áp dụng vào bài toán tính giai thừa.
   ct: n! = n*(n-1)*(n-2)...*1
   => 0! = 1
   1! = 1
   2! = 2*1 = 2
   3! = 3*2*1 = 6
   ==> ct chung: n! = n*(n-1)!

   n truyền vào và lấy ra n*(n-1)!
   mỗi lần gọi hàm n-1 tiến dần về 0
    */
    int factorial(int n){
       if(n==0){
           return 1; // vì 0! = 1
       }
       return n*factorial(n-1);
    }
   ```

   - mỗi lần hàm gọi chính nó thì bản sao mới được tạo ra với tham số mới và lưu trong stack, tiếp tục cho đến base case => quay ngược lại return giá trị từ cuối lên đầu.
   - giải thích:
     - fac(3) => 3 _ fac(2) ; fac(2) => 2 _ fac(1) ; fac(1) => 1\*fac(0); fac(0)=> 1

4. ví dụ tính fibonacci

   - là một chuỗi số, mỗi số là tổng hai số liền trước và hai số đầu tiên là 0 ; 1
   - công thức tính số n trong dãy fibo:
     f(n) = f(n-1) + f(n-2)
     f(0) = 0; f(1) = 1

   ```c
   int fibo(int n){
       if(n==0){
           return 0;
       }
       if(n==1){
           return 1;
       }
       return fibo(n-1) + fibo(n-2);
   }

   ```

5. bài toán tháp hà nội

- Giả sử có 3 cột và một số đĩa xếp chồng từ lớn đến nhỏ. Cần chuyển tất cả đĩa từ cột A sang C nhưng:
  chỉ di chuyển một đĩa một lần
  không được đặt đĩa lớn hơn lên trên đĩa nhỏ hơn

```c
int T(int n,char from, char to, char aux){
    if(n==1){
        printf("di chuyen dia 1 tu %c den %c \n", from, to);
        return;
    }
    T(n-1,from,aux,to);
    printf("di chuyen dia %d tu %c den %c",n,from,to);
        T(n-1,aux,to,from);
}
```

- khi gọi T(3,'a','c','b')=> đưa ra từng bước để chuyển từ a sang c, b là cột phụ trợ.
