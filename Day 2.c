#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* ============================================================
 *  MODUL 4: POINTER DAN STRUCT
 * ============================================================
 *
 *  Topik:
 *   1. Alamat memori dan operator &
 *   2. Deklarasi, inisialisasi, dan assignment pointer
 *   3. Operator dereference (*)
 *   4. Double pointer
 *   5. Pointer dan array
 *   6. Pass by value vs pass by reference
 *   7. Struct
 *   8. Memory dinamis (malloc, calloc, free)
 *
 * ============================================================ */

/*
 * --- POINTER ---
 *
 *  Pointer = variabel yang menyimpan ALAMAT MEMORI.
 *
 *  Deklarasi  : int *ptr;
 *  Inisialisasi: int *ptr = &var;
 *  Assignment : ptr = &var;     (tanpa * di kiri)
 *
 *  Operator & (address-of) : mendapatkan alamat variabel
 *  Operator * (dereference) : mengakses nilai di alamat pointer
 *
 *  Contoh:
 *    int var = 55;
 *    int *ptr = &var;
 *    printf("%d\n", *ptr);  // 55
 *    *ptr = 20;             // ubah var melalui pointer
 *    printf("%d\n", var);   // 20
 */

/*
 * --- DOUBLE POINTER ---
 *
 *  int **dptr = &ptr;
 *  **dptr -> nilai variabel asal
 */

/*
 * --- POINTER DAN ARRAY ---
 *
 *  Nama array adalah pointer ke elemen pertama.
 *  arr[i] setara dengan *(arr + i)
 *
 *  int arr[5] = {1,2,3,4,5};
 *  int *ptr = arr;
 *  *(ptr + 2) == arr[2] == 3
 */

/*
 * --- PASS BY VALUE vs PASS BY REFERENCE ---
 *
 *  Pass by value    : salin nilai, asli tidak berubah
 *  Pass by reference: kirim alamat, asli bisa berubah
 *
 *  void tambah_val(int x)   { x++; }       // tidak mengubah asli
 *  void tambah_ref(int *x)  { (*x)++; }    // mengubah asli
 */

/*
 * --- STRUCT ---
 *
 *  Tipe data buatan yang mengelompokkan variabel berbeda tipe.
 *
 *  struct NamaStruct {
 *      tipe member1;
 *      tipe member2;
 *  };
 *
 *  Akses member  : variabel.member
 *  Via pointer   : ptr->member   (setara (*ptr).member)
 */

/*
 * --- MEMORY DINAMIS ---
 *
 *  #include <stdlib.h>
 *
 *  malloc(n)        : alokasikan n byte, isi tidak diinisialisasi
 *  calloc(n, size)  : alokasikan n elemen ukuran size, isi 0
 *  free(ptr)        : bebaskan memori yang dialokasikan
 *
 *  SELALU cek NULL setelah malloc/calloc!
 *  SELALU free() setelah selesai!
 *  Set ptr = NULL setelah free() untuk hindari dangling pointer.
 *
 *  Common pitfalls:
 *   - Memory leak    : lupa free()
 *   - Dangling pointer: akses setelah free()
 *   - Double free    : free() dua kali
 *   - Buffer overflow: akses di luar alokasi
 */

/* Struct Mahasiswa */
struct Mahasiswa {
    char nama[50];
    long nim;
    float ipk;
};

/* Fungsi pass by value - TIDAK mengubah nilai asli */
void tambah_val(int x) {
    x = x + 1;
}

/* Fungsi pass by reference - MENGUBAH nilai asli */
void tambah_ref(int *x) {
    *x = *x + 1;
}

/* Contoh program Modul 4 */
void contoh_modul4() {
    printf("\n=== Contoh Modul 4: Pointer dan Struct ===\n");

    /* Pointer dasar */
    int var = 55;
    int *ptr = &var;
    printf("var       = %d\n", var);
    printf("&var      = %p\n", (void *)&var);
    printf("ptr       = %p\n", (void *)ptr);
    printf("*ptr      = %d\n", *ptr);
    *ptr = 20;
    printf("*ptr = 20 -> var = %d\n", var);

    /* Double pointer */
    int **dptr = &ptr;
    printf("**dptr    = %d\n", **dptr);

    /* Pointer dan array */
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;
    printf("\narr[2]       = %d\n", arr[2]);
    printf("*(p+2)       = %d\n", *(p + 2));

    /* Pass by value vs reference */
    int a = 5;
    tambah_val(a);
    printf("\nsetelah tambah_val(a): a = %d  (tidak berubah)\n", a);
    tambah_ref(&a);
    printf("setelah tambah_ref(&a): a = %d  (berubah!)\n", a);

    /* Struct */
    struct Mahasiswa mhs;
    strcpy(mhs.nama, "Ani");
    mhs.nim = 5025231001;
    mhs.ipk = 3.9;
    printf("\nMahasiswa: %s, NIM: %ld, IPK: %.2f\n",
           mhs.nama, mhs.nim, mhs.ipk);

    /* Pointer ke struct */
    struct Mahasiswa *mptr = &mhs;
    printf("Via pointer: %s, IPK: %.2f\n", mptr->nama, mptr->ipk);

    /* Memory dinamis */
    int *dyn = (int *)malloc(5 * sizeof(int));
    if (dyn == NULL) {
        printf("Alokasi gagal!\n");
        return;
    }
    for (int i = 0; i < 5; i++) dyn[i] = i * 10;
    printf("\nDynamic array: ");
    for (int i = 0; i < 5; i++) printf("%d ", dyn[i]);
    printf("\n");
    free(dyn);
    dyn = NULL;  /* hindari dangling pointer */
}

/*
 * --- SOAL LATIHAN MODUL 4 ---
 *
 *  Soal 1: Fungsi tambah(a, b, &c) simpan hasil a+b ke c via pointer.
 *          Contoh: tambah(1, 2, &c) -> c = 3
 *
 *  Soal 2: Struct data nilai UN (nama, MTK, IPA, B.Indo, B.Ing).
 *          Input list data, tampilkan nilai berdasarkan nama.
 *
 *  Soal 3: Fungsi reverse(arr, n) membalik array menggunakan pointer.
 *          Input : 5 / 8 4 2 3 1
 *          Output: 1 3 2 4 8
 */


/* ============================================================
 *  MODUL 5: ALGORITMA SORTING DAN SEARCHING
 * ============================================================
 *
 *  Topik:
 *   Sorting:
 *     1. Bubble Sort     - O(n^2)
 *     2. Insertion Sort  - O(n^2)
 *     3. Merge Sort      - O(n log n)
 *     4. Quick Sort      - O(n log n) rata-rata
 *   Searching:
 *     5. Linear Search   - O(n)
 *     6. Binary Search   - O(log n), array HARUS terurut
 *
 * ============================================================ */

/*
 * --- PERBANDINGAN KOMPLEKSITAS SORTING ---
 *
 *  Algoritma     | Best     | Average  | Worst    | In-place
 *  --------------|----------|----------|----------|---------
 *  Bubble Sort   | O(n)     | O(n^2)   | O(n^2)   | Ya
 *  Insertion Sort| O(n)     | O(n^2)   | O(n^2)   | Ya
 *  Merge Sort    | O(n logn)| O(n logn)| O(n logn)| Tidak
 *  Quick Sort    | O(n logn)| O(n logn)| O(n^2)   | Ya
 *
 *  Merge Sort vs Quick Sort:
 *   - Quick Sort lebih sering dipilih karena in-place
 *     (tidak butuh memori tambahan).
 *   - Merge Sort selalu O(n log n) tapi butuh memori O(n).
 */

/* Helper: swap dua integer */
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* Helper: cetak array */
void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

/* --- 1. BUBBLE SORT ---
 * Bandingkan dan tukar elemen bersebelahan secara berulang.
 * Elemen terbesar "gelembung" ke akhir tiap iterasi. */
void bubbleSort(int arr[], int n) {
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = 1;
            }
        }
        if (swapped == 0) break;  /* optimasi: sudah terurut */
    }
}

/* --- 2. INSERTION SORT ---
 * Ambil satu elemen, sisipkan di posisi yang tepat
 * pada bagian yang sudah terurut (mirip kartu remi). */
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

/* --- 3. MERGE SORT ---
 * Divide and conquer: bagi dua, sort masing-masing,
 * lalu gabungkan (merge). */
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else               arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    free(L);
    free(R);
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

/* --- 4. QUICK SORT ---
 * Divide and conquer berbasis pivot.
 * Elemen < pivot ke kiri, elemen > pivot ke kanan, rekursif. */
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

/* --- 5. LINEAR SEARCH ---
 * Periksa satu per satu dari awal.
 * Kembalikan indeks jika ditemukan, -1 jika tidak. */
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

/* --- 6. BINARY SEARCH ---
 * Cari pada array TERURUT dengan membagi search space jadi dua
 * setiap iterasi. Kompleksitas O(log n).
 *
 * SYARAT: array HARUS sudah terurut! */
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if      (arr[mid] == target) return mid;   /* ketemu */
        else if (arr[mid] <  target) low = mid + 1; /* cari kanan */
        else                         high = mid - 1; /* cari kiri */
    }
    return -1;  /* tidak ditemukan */
}
/*
 * Contoh binary search: cari 13 dalam [2,3,8,10,13,17,28,35]
 *
 *  Iter 1: mid=3, arr[3]=10 < 13  -> cari kanan [4..7]
 *  Iter 2: mid=5, arr[5]=17 > 13  -> cari kiri  [4..4]
 *  Iter 3: mid=4, arr[4]=13 = 13  -> KETEMU! indeks 4
 *
 *  Hanya 3 iterasi dari 8 elemen (vs linear: bisa 5 iterasi).
 */

/* Contoh program Modul 5 */
void contoh_modul5() {
    printf("\n=== Contoh Modul 5: Sorting dan Searching ===\n");

    int a[] = {64, 34, 25, 12, 22, 11, 90};
    int b[] = {64, 34, 25, 12, 22, 11, 90};
    int c[] = {64, 34, 25, 12, 22, 11, 90};
    int d[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;

    printf("Original      : "); printArr(a, n);

    bubbleSort(a, n);
    printf("Bubble Sort   : "); printArr(a, n);

    insertionSort(b, n);
    printf("Insertion Sort: "); printArr(b, n);

    mergeSort(c, 0, n - 1);
    printf("Merge Sort    : "); printArr(c, n);

    quickSort(d, 0, n - 1);
    printf("Quick Sort    : "); printArr(d, n);

    /* Searching */
    int sorted[] = {2, 3, 8, 10, 13, 17, 28, 35};
    int sn = 8;
    printf("\nArray sorted  : "); printArr(sorted, sn);

    int target = 13;
    int idx_lin = linearSearch(sorted, sn, target);
    int idx_bin = binarySearch(sorted, sn, target);
    printf("Cari %d:\n", target);
    printf("  Linear Search : indeks %d\n", idx_lin);
    printf("  Binary Search : indeks %d\n", idx_bin);

    target = 99;
    printf("Cari %d:\n", target);
    printf("  Linear Search : %d (tidak ada)\n", linearSearch(sorted, sn, target));
    printf("  Binary Search : %d (tidak ada)\n", binarySearch(sorted, sn, target));
}

/*
 * --- SOAL LATIHAN MODUL 5 ---
 *
 *  Soal 1: Binary Search pada array sorted.
 *          Cek apakah nilai K ada dalam array.
 *
 *  Soal 2: Binary Search straight forward.
 *
 *  Soal 3: Lower/Upper Bound menggunakan Binary Search.
 *
 *  Soal 4: Hamburgers - temukan fungsi monoton, gunakan Binary Search.
 *          (Mirip: cari K terkecil sehingga fungsi f(K) = true)
 *
 *  Soal 5: Vasya and String - fix L/R, cari pasangan maksimal
 *          dengan binary search.
 */


/* ============================================================
 *  MODUL X: MATERI TAMBAHAN
 * ============================================================
 *
 *  Topik:
 *   1. Bitwise operators (&, |, ^, ~, <<, >>)
 *   2. sizeof() operator
 *   3. Address-of (&) dan dereference (*) - ringkasan
 *   4. Conditional operator (?:)
 *   5. Comma operator (,)
 *   6. Subscript operator ([])
 *
 * ============================================================ */

/*
 * --- BITWISE OPERATORS ---
 *
 *  Bekerja pada level bit (basis 2).
 *
 *  &   AND      : 1 jika KEDUA bit 1               12 &  5 = 4
 *  |   OR       : 1 jika MINIMAL SATU bit 1         12 |  5 = 13
 *  ^   XOR      : 1 jika kedua bit BERBEDA          12 ^  5 = 9
 *  ~   COMPLEMENT: balik semua bit                  ~12     = -13
 *  <<  SHIFT LEFT : geser bit ke kiri sebanyak n    13 << 2 = 52
 *  >>  SHIFT RIGHT: geser bit ke kanan sebanyak n   13 >> 2 = 3
 *
 *  Contoh: 12 = 1100, 5 = 0101
 *    12 & 5  = 0100 = 4
 *    12 | 5  = 1101 = 13
 *    12 ^ 5  = 1001 = 9
 *
 *  Shift Left setara dengan perkalian 2^n:
 *    13 << 2  = 13 * 4  = 52
 *
 *  Shift Right setara dengan pembagian 2^n (integer):
 *    13 >> 2  = 13 / 4  = 3
 */

/*
 * --- sizeof() OPERATOR ---
 *
 *  Mengembalikan ukuran memori (byte) dari tipe data atau variabel.
 *
 *  sizeof(int)    = 4
 *  sizeof(float)  = 4
 *  sizeof(double) = 8
 *  sizeof(char)   = 1
 *
 *  Cara hitung jumlah elemen array:
 *    int arr[10];
 *    int n = sizeof(arr) / sizeof(arr[0]);  // = 10
 */

/*
 * --- CONDITIONAL OPERATOR (?:) ---
 *
 *  Sudah dibahas di Modul 1. Ringkasan:
 *  (kondisi) ? nilai_true : nilai_false
 *
 *  int abs_x = (x >= 0) ? x : -x;
 */

/*
 * --- COMMA OPERATOR (,) ---
 *
 *  Sebagai operator binary, hanya kembalikan nilai operand kanan.
 *  int n = (5, 23);  // n = 23
 *
 *  Lebih sering dipakai sebagai separator:
 *  int a, b, c;
 *  for (int i=0, j=10; i<j; i++, j--)  // update ganda
 */

/*
 * --- SUBSCRIPT OPERATOR ([]) ---
 *
 *  Akses elemen array berdasarkan indeks.
 *  arr[i] setara dengan *(arr + i)
 */

/* Contoh program Modul X */
void contoh_modul_x() {
    printf("\n=== Contoh Modul X: Materi Tambahan ===\n");

    int a = 12, b = 5;
    printf("a = %d (biner: 1100)\n", a);
    printf("b = %d (biner: 0101)\n", b);
    printf("a &  b = %d  (AND)\n", a & b);
    printf("a |  b = %d  (OR)\n",  a | b);
    printf("a ^  b = %d  (XOR)\n", a ^ b);
    printf("~a     = %d  (COMPLEMENT)\n", ~a);

    int c = 13;
    printf("\nc = %d\n", c);
    printf("c << 2 = %d  (shift left 2, setara c*4)\n", c << 2);
    printf("c >> 2 = %d  (shift right 2, setara c/4)\n", c >> 2);

    printf("\nsizeof(int)    = %zu byte\n", sizeof(int));
    printf("sizeof(float)  = %zu byte\n", sizeof(float));
    printf("sizeof(double) = %zu byte\n", sizeof(double));
    printf("sizeof(char)   = %zu byte\n", sizeof(char));

    int arr[10];
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("\nArray arr[10]: jumlah elemen = %d\n", n);

    int x = -7;
    int abs_x = (x >= 0) ? x : -x;
    printf("\nNilai absolut dari %d = %d\n", x, abs_x);

    int num = 23; /* comma operator: (5, 23) -> 23 */
    printf("int num = (5, 23) -> num = %d\n", num);

    int idx = 2;
    int data[] = {10, 20, 30, 40, 50};
    printf("\ndata[%d] = %d\n", idx, data[idx]);
    printf("*(data+%d) = %d  (setara data[%d])\n", idx, *(data + idx), idx);
}


int main() {

    contoh_modul4();
    contoh_modul5();
    contoh_modul_x();

    return 0;
}

