// Last updated: 4/22/2026, 12:14:48 AM
#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

typedef struct {
    int size;
    HashNode* nodes;
} HashTable;

// Simple hash function
int hash(int key, int size) {
    int h = key % size;
    return h < 0 ? h + size : h;
}

// Insert into hash table
void insert(HashTable* table, int key, int value) {
    int idx = hash(key, table->size);
    while (table->nodes[idx].value != -1) { // Linear probing
        idx = (idx + 1) % table->size;
    }
    table->nodes[idx].key = key;
    table->nodes[idx].value = value;
}

// Search in hash table
int search(HashTable* table, int key) {
    int idx = hash(key, table->size);
    while (table->nodes[idx].value != -1) {
        if (table->nodes[idx].key == key) {
            return table->nodes[idx].value;
        }
        idx = (idx + 1) % table->size;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int tableSize = numsSize * 2;
    HashTable table;
    table.size = tableSize;
    table.nodes = (HashNode*)malloc(tableSize * sizeof(HashNode));
    
    // Initialize table
    for (int i = 0; i < tableSize; i++) {
        table.nodes[i].value = -1; 
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIdx = search(&table, complement);
        
        if (complementIdx != -1) {
            result[0] = complementIdx;
            result[1] = i;
            free(table.nodes);
            return result;
        }
        insert(&table, nums[i], i);
    }

    free(table.nodes);
    return NULL;
}