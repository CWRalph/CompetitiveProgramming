/*
Minimum number of edits to transform a string into another string

distance(a,b) = min(
    distance(a,b −1)+1,
    distance(a−1,b)+1,
    distance(a−1,b −1)+cost(a,b)
).

cost(a,b) = 0 if x[a] = y[b], and otherwise cost(a,b) = 1. The formula
considers the following ways to edit the string x:
• distance(a,b −1): insert a character at the end of x
• distance(a−1,b): remove the last character from x
• distance(a−1,b −1): match or modify the last character of x
*/