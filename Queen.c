#include <stdio.h>
#include <stdlib.h>

int x[20], n;

void display() {
    int i, j;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(x[i] == j)
                printf("\tQ");
            else
                printf("\t.");
        }
        printf("\n\n");
    }
    printf("\n\n");
}

int place(int k, int i) {
    int j;
    for(j = 1; j <= k - 1; j++) {
        if((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return 0;
    }
    return 1;
}

void nqueen(int k) {
    int i;
    for(i = 1; i <= n; i++) {
        if(place(k, i)) {
            x[k] = i;
            if(k == n)
                display(); // Found a solution
            else
                nqueen(k + 1);
        }
    }
}

int main() {
    printf("Enter the number of queens: ");
    scanf("%d", &n);

    if(n <= 3)
        printf("N-Queens solution does not exist for n = %d\n", n);
    else {
        printf("Solutions for %d-Queens:\n\n", n);
        nqueen(1);
    }

    return 0;
}
