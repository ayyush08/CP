# 🧮 Bit Manipulation Cheat Sheet

## 1️⃣ Odd / Even Check
- **Check if n is odd:**

    ```
    n & 1
    ```
- `1` if odd
- `0` if even

---

## 2️⃣ Check if i-th Bit is Set
- **Is the i-th bit set?**
  ```
  (n >> i) & 1
  ```

- Returns `1` if i-th bit is set
- Returns `0` otherwise
- *Alternative:*
  ```
  n & (1 << i)
  ```

---

## 3️⃣ Unset (Clear) the i-th Bit
- **Clear i-th bit to 0:**
```
n & ~(1 << i)
```

---

## 4️⃣ Toggle the i-th Bit
- **Flip i-th bit (0→1 or 1→0):**
```
n ^ (1 << i)
```

---

## 5️⃣ Check if n is a Power of Two
- **True if n is power of 2:**
```
n > 0 and (n & (n - 1)) == 0
```

---

## 6️⃣ Unset Rightmost Set Bit
- **Remove the lowest 1-bit in n:**
```
n & (n - 1)
```

## 7️⃣ Keep only the rightmost set bit:
```
n & -n OR n= n & ~(n - 1)
```

## 8️⃣ Number of Set Bits in N (Hamming Weight)
- **Count set bits in n:**
```
count = 0
while n:
    count += n & 1
    n >>= 1
```
Or using STL:
```
__builtin_popcount(n)
```

## 9️⃣ For any integer appearning n times (a^a^a^...^a till n times)
- **Result is a if n is odd, 0 if n is even:**
```
result = a if n & 1 else 0
```

-------------------------------------------------------------------------------------


# DSU (Disjoint Set Union)

```cpp
struct DSU{
  vector<int> parent; //Method 1 (Union by Parent)
  vector<int> size; //Method 2 (Union by Size)
  vector<int> rank; //Method 3 (Union by Rank)
  void init (int n){ //initialize DSU with n elements
    parent.assign(n,0);
    iota(parent.begin(), parent.end(), 0); //assign sequentially from 0 to n-1
    size.assign(n, 1); //initialize size of each set to 1
    rank.assign(n, 0); //initialize rank of each set to 0
  }
  int find(int v){ //find leader of any node
    if(parent[v] != v)
      return find(parent[v]);  //recursive search for the root of the set with complexity O(N)
      //or
      return parent[v] = find(parent[v]); //path compression (reduces complexity to O(N*log(N)))
  }
  void merge(int a,int b){ //merge two sets
    a = find(a);
  b = find(b);
  if(a!=b){
    // parent[b] = a; 1. Method 1: make a the parent of b
    // if(size[a] < size[b])  swap(a, b); //2. Method 2: make parent of bigger size
    //2. Method 2: make parent of bigger size
    // if(size[a]<size[b]) swap(a, b);
    // parent[b] = a; //make a the parent of b
    // size[a] += size[b]; //update size of the new parent
    if(rank[a]<rank[b])  swap(a, b); //3. Method 3: union by rank
    parent[b] = a; //make a the parent of b
    if(rank[a] == rank[b]) rank[a]++; //increase rank if they were
  }
}
}

```