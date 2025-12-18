#include <stdio.h>
#define MAX 100
int hashTable[MAX];
void initHashTable(int m) {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}
void insert(int key, int m) {
    int index = key % m;
    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        int i = 1;
        while (hashTable[(index + i) % m] != -1) {
            i++;
        }
        hashTable[(index + i) % m] = key;
    }
}
void display(int m) {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}
int main() {
    int m, n, key;
    printf("Enter size of hash table (m): ");
    scanf("%d", &m);
    initHashTable(m);
    printf("Enter number of employee records: ");
    scanf("%d", &n);
    printf("Enter 4-digit employee keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key, m);
    }
    display(m);
    return 0;
}