#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    int array[26]; 
    int size;
} Hash;

void insertFromHash(char apla, Hash *hash) {
    if (hash->array[apla - 'a'] == 0) {
        hash->size++;
    }
    hash->array[apla - 'a']++;
}

void deleteFromHash(char apla, Hash *hash) {
    if (hash->array[apla - 'a'] > 0) { 
        hash->array[apla - 'a']--;
        if (hash->array[apla - 'a'] == 0) {
            hash->size--;
        }
    }
}

void initHash(Hash *hash) {
    for (int i = 0; i < 26; i++) { 
        hash->array[i] = 0;
    }
    hash->size = 0;
}

int main() {
    Hash hash;
    initHash(&hash);

    char s[] = "abcba";
    int k = 2;
    int l = 0, r = 0;
    int n = strlen(s);
    printf("size: %d\n", n); 

    int maxiAns = -1;

    while (r < n) {   
        insertFromHash(s[r], &hash);

        while (hash.size > k) {
            deleteFromHash(s[l], &hash);
            l++;
        }

        if (hash.size == k) { 
            if (maxiAns < (r - l) + 1) {
                maxiAns = (r - l) + 1;
            }
        }

        r++;
    }

    printf("Ans: %d\n", maxiAns);

    return 0;
}
