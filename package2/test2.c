#include <stdio.h>

typedef struct NUM {
    int number;
    int count;
    int printed;
} NUM;

int main() {
    int n, time;
    scanf("%d %d", &n, &time);

    if (n <= 0) {
        return 0;
    }

    if (time < 1 || time > n) {
        printf("No such element.\n");
        return 0;
    }

    NUM arr[n];
    int k = 0;
    int has_print = 0;

    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        int found = 0;
        for (int j = 0; j < k; j++) {
            if (arr[j].number == num) {
                arr[j].count++;
                if (arr[j].count == time && !arr[j].printed) {
                    printf("%d\n", num);
                    arr[j].printed = 1;
                    has_print++;
                }
                found = 1;
                break;
            }
        }
        if (!found) {
            arr[k].number = num;
            arr[k].count = 1;
            arr[k].printed = 0;

            if (time == 1) {
                printf("%d\n", num);
                arr[k].printed = 1;
                has_print++;
            }
            k++;
        }
    }
    if (has_print == 0) {
        printf("No such element.\n");
    }

    return 0;
}