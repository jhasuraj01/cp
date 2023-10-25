# Competitive Programming Library

## Test
```cpp
g++ ./tests/main.cpp -std=c++17 -o temp && ./temp && rm ./temp
```

## Data Structures

<details>
<summary>Disjoint Set: Union by Rank</summary>

### Initialization:
- Time Complexity: O(N)
- Space Complexity: O(N)

```cpp
 DisjointSet dsu(size);
```

### Operations

#### Find Set Representative
- Avg. Time Complexity: O(1)
- Time Complexity: O(log N)
- Space Complexity: O(1)

```cpp
dsu.find_set(int i);
```

#### Merge Set
- Avg. Time Complexity: O(1)
- Time Complexity: O(log N)
- Space Complexity: O(1)

```cpp
dsu.merge_set(int i, int j)
```

#### Check If Same Set
- Avg. Time Complexity: O(1)
- Time Complexity: O(log N)
- Space Complexity: O(1)

```cpp
dsu.is_same_set(int i, int j)
```

</details>

<details>
<summary>Segment Tree</summary>

### Initialization:
- Time Complexity: O(N)
- Space Complexity: O(N)

```cpp
SegmentTree<int> segment_tree(arr, 0, [&](int a, int b) {
    return a+b;
});
```

### Operations

#### Point Update
- Time Complexity: O(log N)
- Space Complexity: O(1)

```cpp
segment_tree.update(i, value);
```

#### Range Query
- Time Complexity: O(log N)
- Space Complexity: O(log N)

```cpp
segment_tree.get(i, j)
```

</details>


<details>
<summary>Static Hash</summary>

### Examples:
1. `StaticHash hash;`
2. `StaticHash hash(31);`
3. `StaticHash hash(31, 'a');`
4. `StaticHash hash(31, 'a', 1e9+9);`

</details>


<details>
<summary>Rolling Hash</summary>

### Examples:
1. `RollingHash hash;`
2. `RollingHash hash(31);`
3. `RollingHash hash(31, 'a');`
4. `RollingHash hash(31, 'a', 1e9+9);`

</details>


<details>
<summary>Custom Stack</summary>

### Usage
Can be used to build `min`/`max`/`sum`/`xor` Stack using any appropriate associative function

### Initialization:
```cpp
// Max Stack
CustomStack<int> st(0, [&](int a, int b) {
    return std::max(a, b);
});
```

### Operations:
1. `st.custom_value()`
2. `st.empty()`
3. `st.push(value)`
4. `st.pop()`
5. `st.size()`
6. `st.top()`

</details>

<details>
<summary>Custom Queue</summary>

### Usage
Can be used to build `min`/`max`/`sum`/`xor` Queue using any appropriate associative function

### Initialization:
```cpp
// Max Queue
CustomQueue<int> qu(0, [&](int a, int b) {
    return std::max(a, b);
});
```

### Operations:
1. `qu.custom_value()`
2. `qu.empty()`
3. `qu.front()`
4. `qu.push(value)`
5. `qu.pop()`
6. `qu.size()`

</details>