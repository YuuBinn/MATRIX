#include <stdio.h>
#pragma warning(disable:4996)
int matrix[501][2];// ��� 
int dp[501][501]; //���̳��� �˰��� �� 
void mat(int n);// �����Լ�
int min(int x, int y) {
    return x < y ? x : y;
}
//�ΰ��߿� �ּڰ��� ��Ÿ���� �Լ�

int main() {
    int n, i, j;
    printf("����� ���� �Է�:");
    scanf(" %d", &n);// ����� ������ �Է�
    printf("����� ��� �� �Է�\n");
    for (i = 0; i < n; i++) {
        printf("�� �Է�:");
        scanf("%d", &matrix[i][0]);
        printf("�� �Է�:");
        scanf("%d", &matrix[i][1]);
    }
    mat(n);
}

void mat(int n) {
    int a, b;
    int i, j, k;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n - i; j++) {
            a = j;
            b = j + i;
            if (a == b) {
                dp[a][b] = 0;
            }
            else {
                dp[a][b] = 987654321;
                for (k = a; k < b; k++) {
                    dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a][0] * matrix[k][1] * matrix[b][1]));
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {
            printf("%d ", dp[i][j]);



        }
        printf("\n");


    }

    printf("�ּڿ���Ƚ���� :%d", dp[0][n - 1]);

}