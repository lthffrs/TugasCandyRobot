#include <iostream>


using namespace std;

int main() {
    int arr[5][5] = {
        {2, 0, 1, 1, 0},
        {1, 2, 0, 2, 3},
        {2, 2, 0, 2, 1},
        {3, 1, 0, 2, 0},
        {0, 0, 1, 3, 0}
    };

    // Array untuk menyimpan jumlah maksimal permen yang dapat dikumpulkan
    int dp[5][5] = {0};

    // Inisialisasi titik awal
    dp[0][0] = arr[0][0];

    // Mengisi baris pertama (hanya bisa bergerak ke kanan)
    for (int j = 1; j < 5; j++) {
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    }

    // Mengisi kolom pertama (hanya bisa bergerak ke bawah)
    for (int i = 1; i < 5; i++) {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }

    // Mengisi sisa dari dp array
    for (int i = 1; i < 5; i++) {
        for (int j = 1; j < 5; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }

    // Nilai maksimal permen yang dapat dikumpulkan
    cout << "Jumlah maksimal permen yang dapat dikumpulkan: " << dp[4][4] << endl;

    return 0;
}
