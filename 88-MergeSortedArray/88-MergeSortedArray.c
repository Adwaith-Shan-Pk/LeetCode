// Last updated: 4/22/2026, 12:33:08 AM
1#include <stdbool.h>
2
3bool lemonadeChange(int* bills, int billsSize) {
4    int five = 0, ten = 0;
5
6    for (int i = 0; i < billsSize; i++) {
7        if (bills[i] == 5) {
8            five++;
9        } 
10        else if (bills[i] == 10) {
11            if (five == 0) return false;
12            five--;
13            ten++;
14        } 
15        else { // bills[i] == 20
16            if (ten > 0 && five > 0) {
17                ten--;
18                five--;
19            } 
20            else if (five >= 3) {
21                five -= 3;
22            } 
23            else {
24                return false;
25            }
26        }
27    }
28
29    return true;
30}