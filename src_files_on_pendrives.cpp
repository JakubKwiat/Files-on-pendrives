#include <stdio.h>
using namespace std;
struct file
{
    int id;
    int size;
};
int partition_size(file *files, int p, int r) {
    int pivot = files[r].size;
    int i = p;
    file bufor;
    for (int j = p;j < r;j++) {
        if (files[j].size <= pivot) {
            bufor = files[i];
            files[i] = files[j];
            files[j] = bufor;
            i++;
        }
    }
    bufor = files[i];
    files[i] = files[r];
    files[r] = bufor;
    return i;
}
int partition_id(file* files, int p, int r) {
    int x = files[r].id;
    int i = p;
    file bufor;
    for (int j = p;j < r;j++) {
        if (files[j].id <= x) {
            bufor = files[i];
            files[i] = files[j];
            files[j] = bufor;
            i++;
        }
    }
    bufor = files[i];
    files[i] = files[r];
    files[r] = bufor;
    return i;
}
void quicksort_size(file* files, int p, int r) {
    if (p < r) {
        int pivot;
        pivot = partition_size(files, p, r);
        quicksort_size(files, p, pivot - 1);
        quicksort_size(files, pivot + 1, r);
    }
}
void quicksort_id(file* files, int p, int r) {
    if (p < r) {
        int pivot;
        pivot = partition_id(files, p, r);
        quicksort_id(files, p, pivot - 1);
        quicksort_id(files, pivot + 1, r);
    }
}
void show(file* pen_1, file* pen_2, int k, int j, int m) {
    quicksort_id(pen_1, 0, j - 1);
    quicksort_id(pen_2, 0, k - 1);
    printf_s("%d", m);
    printf_s("\n");
    printf_s("1: ");
    for (int i = j - 1;i >= 0;i--) {
        printf_s("%d", pen_1[i].id);
        printf_s(" ");
    }
    printf_s("\n");
    printf_s("2: ");
    for (int i = k - 1;i >= 0;i--) {
        printf_s("%d", pen_2[i].id);
        printf_s(" ");
    }
}
void load(file* files, int files_number) {
    for (int i = 0;i < files_number;i++) {
        scanf_s("%d", &files[i].id);
        scanf_s("%d", &files[i].size);
    }
}
void distribute(file* files, file* pen_1, file* pen_2, int& memory_1, int& memory_2, int pen_size,int files_number, int& stop_1, int& stop_2, int& j, int& k, int& m) {
    for (int i = 0;i < files_number;i++) {
        if (memory_1 + files[m].size > pen_size) {
            stop_1 = 1;
        }
        if (memory_2 + files[m].size > pen_size) {
            stop_2 = 1;
        }
        if ((stop_1 == 0)) {
            pen_1[j] = files[m];
            memory_1 += files[m].size;
            m++;
            j++;
        }
        if ((stop_1 == 1) && (stop_2 == 0)) {
            pen_2[k] = files[m];
            memory_2 += files[m].size;
            m++;
            k++;
        }
        if ((stop_1 == 1) && (stop_2 == 1)) {
            break;
        }
    }
}
int main()
{
    int pen_size, files_number, memory_1 = 0, memory_2 = 0, j = 0, k = 0, m = 0, stop_1 = 0, stop_2 = 0;
    file* files, * pen_1, * pen_2;
    scanf_s("%d", &files_number);
    files = new file[files_number];
    pen_1 = new file[files_number];
    pen_2 = new file[files_number];
    scanf_s("%d", &pen_size);
    load(files, files_number);
    quicksort_size(files, 0, files_number - 1);
    distribute(files, pen_1, pen_2, memory_1, memory_2, pen_size, files_number, stop_1, stop_2, j, k, m);
    show(pen_1, pen_2, k, j, m);
    delete[] files;
    delete[] pen_1;
    delete[] pen_2;
    return 0;
}

