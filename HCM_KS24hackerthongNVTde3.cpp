#include <stdio.h>

int main() {
    int arr[100], n, i, j, temp, count_even = 0, count_odd = 0, second_largest, pos, value, key, found;
    
    while (1) {
        printf("\n===== MENU =====\n");
        printf("1. Nhap so phan tu va gia tri cho mang\n");
        printf("2. In gia tri cac phan tu trong mang\n");
        printf("3. So nguyen co trong mang\n");
        printf("4. Tim gia tri lon thu hai trong mang\n");
        printf("5. Them mot phan tu vao vi tri xac dinh\n");
        printf("6. Xoa phan tu tai vi tri xac dinh\n");
        printf("7. Sap xep mang theo thu tu giam dan\n");
        printf("8. Kiem tra mot so co ton tai trong mang\n");
        printf("0. Thoat\n");
        printf("================\n");
        printf("Nhap lua chon: ");
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Nhap so phan tu (toi da 100): ");
                scanf("%d", &n);
                for (i = 0; i < n; i++) {
                    printf("Nhap arr[%d]: ", i);
                    scanf("%d", &arr[i]);
                }
                break;
                
            case 2:
                printf("Cac phan tu trong mang:\n");
                for (i = 0; i < n; i++) {
                    printf("arr[%d] = %d\n", i, arr[i]);
                }
                break;
                
            case 3:
               
            case 4:
                if (n < 2) {
                    printf("Khong the tim gia tri lon thu hai (mang phai co it nhat 2 phan tu).\n");
                } else {
                    int largest = arr[0];
                    second_largest = -1;
                    for (i = 1; i < n; i++) {
                        if (arr[i] > largest) {
                            second_largest = largest;
                            largest = arr[i];
                        } else if (arr[i] > second_largest && arr[i] != largest) {
                            second_largest = arr[i];
                        }
                    }
                    printf("Gia tri lon thu hai: %d\n", second_largest);
                }
                break;
                
            case 5:
                printf("Nhap vi tri muon them (0 <= vi tri <= %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos > n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    printf("Nhap gia tri can them: ");
                    scanf("%d", &value);
                    for (i = n; i > pos; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    n++;
                    printf("Them phan tu thanh cong.\n");
                }
                break;
                
            case 6:
                printf("Nhap vi tri muon xoa (0 <= vi tri < %d): ", n);
                scanf("%d", &pos);
                if (pos < 0 || pos >= n) {
                    printf("Vi tri khong hop le.\n");
                } else {
                    for (i = pos; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Xoa phan tu thanh cong.\n");
                }
                break;
                
            case 7:
                for (i = 1; i < n; i++) {
                    temp = arr[i];
                    j = i - 1;
                    while (j >= 0 && arr[j] < temp) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = temp;
                }
                printf("Mang da sap xep giam dan.\n");
                break;
                
            case 8:
                printf("Nhap so can tim: ");
                scanf("%d", &key);
                
                int left = 0, right = n - 1;
                found = 0;
                while (left <= right) {
                    int mid = (left + right) / 2;
                    if (arr[mid] == key) {
                        found = 1;
                        break;
                    } else if (arr[mid] < key) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                if (found)
                    printf("So %d ton tai trong mang.\n", key);
                else
                    printf("So %d khong ton tai trong mang.\n", key);
                break;
                
            case0:
                printf("Thoat chuong trinh.\n");
                return 0;
                
            break;
                printf("Lua chon khong hop le.\n");
        }
    }
    return 0;
}
