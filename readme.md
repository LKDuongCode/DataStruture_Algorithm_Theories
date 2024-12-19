### GIẢI THUẬT TÌM KIẾM

1. Tìm kiếm tuyến tính:

- Ý tưởng: duyệt từng phần tử cho đến khi tìm thấy hoặc hết ds. Nếu không tìm thấy thì trả về -1 or null. Nếu tìm thấy trả về index.
- Thời gian: 0(n) - n là số element trong ds.
- Khi nào dùng:
  - ds không sắp xếp.
  - kích thước ds nhỏ.

```c
int linearSearch(int arr[], int size, int target){
    for(int i = 0; i< size; i++){
        if(arr[i] == target){
            return i; // trả về chỉ mục phần tử tìm thấy
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 4;

    int indexFound = linearSearch(arr,size,target);

    if(indexFound != -1){
        printf("tim thay %d", result);
    }else{
        printf("khong thay");
    }
    return 0;
}
```

2. Tìm kiếm nhị phân

- Ý tưởng: chia ds thành các phần nhỏ và chỉ tìm kiếm trong phần có thể chứa phần tử cần tìm. Với điều kiện ds đã được sắp xếp.
- Hoạt động:
  - tính chỉ mục trung tâm ds
  - so sánh phần tử trung tâm với phần tử cần tìm.
    - Nếu mid = value . return index tìm thấy.
    - Nếu mid > value . Tiếp tục tìm nửa bên trái.
    - Nếu mid < value . Tìm kiếm nửa bên phải.
  - lặp lại cho không còn phần tử nào.
  - nếu không thấy return -1 or null.
- Khi nào dùng:
  - mảng lớn
  - thời gian: 0 (log n)
  - mảng đã được sắp xếp tăng dần.

```c
int binarySearch (int arr[], int size, int target){
    int first = 0; //chỉ mục ele đầu tiên
    int last = size - 1; // chỉ mục ele cuối

    while(first <= last){
        int mid = (low + high) / 2; //tính chỉ mục giữa.

        if(arr[mid] == target){
            return mid; // nếu bằng
        }

        if(arr[mid] > target){
            last = mid - 1; // nếu mid > target
        }

        if(arr[mid] < target){
            first = mid  + 1; // nếu mid < target
        }

    }
    return -1; //nếu không thấy.
}
```

3. Ứng dụng

- Tìm kiếm trong các hệ thống csdl: nhị phân, tuyến tính, BFS, DFS.
- Tìm kiếm trong công cụ tìm kiếm: nhị phân, tuyến tính
- Tìm kiếm trong hệ thống phân tán và mạng: BFS, nhị phânphân
- Tìm kiếm trong trò chơi và AI: A\*, DFS, BFSBFS
- Tìm kiếm trong hệ thống gợi ý, đề xuất : tuyến tính, nhị phân
- Tìm kiếm trong ứng dụng e-commerce: tuyến tính, nhị phânphân
- Tìm kiếm trong bài toán đồ thị: DFS,BFS, nhị phânphân
- Tìm kiếm trong công nghệ blockchain: tuyến tính, nhị phânphân
