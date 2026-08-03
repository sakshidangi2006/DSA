# 🚀 DSA Practice Repository

Complete Data Structures & Algorithms implementations in C++.

## 📁 Folder Structure

```
DSA/
├── Array/                      # Array operations
├── Binary_Search/              # Search algorithms
├── Bit_Manipulation/           # Bit operations
├── Daily_Challenges/           # Daily problems
├── HashMap/                    # Hash table problems
├── Heap/                       # Priority queue
├── Kadane_Algorithm/           # Max subarray
├── Math/                       # Math problems
├── Merge_Interval/             # Interval problems
├── Prefix_Sum/                 # Prefix sum tricks
├── Recursion/                  # Recursive solutions
├── Reversal_of_Linked_List/    # Linked list reversal
├── Sliding_Window/             # Window technique
├── Slow_Fast_Pointer/          # Two pointer
├── Stack/                      # Stack problems
└── Two_Pointer/                # Two pointer technique
```

## 🚀 Quick Start

### Compile & Run

```bash
cd Array/
g++ -std=c++17 -O2 concatenation_of_array.cpp -o solution
./solution
```

### Example: 4Sum Problem

```bash
cd Two_Pointer/
g++ -std=c++17 -O2 18_four_sum.cpp -o four_sum
./four_sum
```

---

## 📚 Learning Topics

### Basic Data Structures
- **Array**: Concatenation, products, modifications
- **Stack**: Expression evaluation, parentheses matching
- **Heap**: Priority queues, Kth largest/smallest

### Algorithms
- **Two Pointer**: Convergence patterns, multi-pointer
- **Sliding Window**: Substring/subarray optimization
- **Binary Search**: Answer binary search variants
- **Kadane's Algorithm**: Maximum subarray sum
- **Bit Manipulation**: XOR operations, bit masking
- **HashMap**: Frequency tracking, cumulative sums
- **Prefix Sum**: Range queries, subarray problems
- **Merge Interval**: Scheduling, overlap detection

### Advanced
- **Linked List**: Reversal, cycle detection, manipulation
- **Recursion**: Backtracking, tree/graph traversal
- **Math**: Number theory, overflow handling

---

## ⏱️ Complexity Guide

### Time Complexity
- O(1) - Constant
- O(log n) - Binary search
- O(n) - Linear scan
- O(n log n) - Sorting, optimal searches
- O(n²) - Nested loops
- O(n³) - Triple loops
- O(2ⁿ) - Exponential recursion
- O(n!) - Permutations

### Space Complexity
- O(1) - Constant space
- O(log n) - Recursion depth
- O(n) - Linear storage
- O(n²) - 2D arrays
- O(2ⁿ) - Subset generation

---

## 💡 Key Algorithms

### 1. Kadane's Algorithm
Maximum subarray sum in O(n) time
```cpp
int maxSum = nums[0], currentSum = nums[0];
for (int i = 1; i < n; i++) {
    currentSum = max(nums[i], currentSum + nums[i]);
    maxSum = max(maxSum, currentSum);
}
```

### 2. Two Pointer
Solve O(n²) problems in O(n)
```cpp
int left = 0, right = n - 1;
while (left < right) {
    if (condition) left++;
    else right--;
}
```

### 3. Sliding Window
Optimize subarray problems
```cpp
int left = 0;
for (int right = 0; right < n; right++) {
    // Add right element
    while (condition) {
        // Remove left element
        left++;
    }
    // Process window
}
```

### 4. Binary Search
Logarithmic search
```cpp
int left = 0, right = n - 1;
while (left <= right) {
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) left = mid + 1;
    else right = mid - 1;
}
```

### 5. XOR Trick
Find single number appearing once
```cpp
int result = 0;
for (int num : nums) {
    result ^= num;  // Same numbers cancel, unique remains
}
```

---

## 📖 How to Use This Repo

1. **Pick a topic** from the categories
2. **Read the problem** in the file
3. **Understand the approach** (comments in code)
4. **Compile and run** the solution
5. **Modify and experiment** with variations
6. **Practice similar problems** on LeetCode

---

## 🎯 Interview Prep

### Must Know Patterns
- Two Pointer Technique
- Sliding Window
- Binary Search Variants
- Hash Map Optimization
- Stack Applications
- Linked List Manipulation
- Prefix Sum + HashMap
- Bit Manipulation Tricks

### Practice Order
1. Start with Easy problems
2. Move to Medium problems
3. Solve Hard problems
4. Mix problems from different categories
5. Do timed practice (45 min per problem)

---

## 🤝 Contributing

1. Fork the repo
2. Create a branch: `git checkout -b feature/newproblem`
3. Add your solution with comments
4. Include time/space complexity
5. Push: `git push origin feature/newproblem`
6. Create a Pull Request

---

## 📚 Resources

- **LeetCode**: https://leetcode.com
- **GeeksforGeeks**: https://www.geeksforgeeks.org
- **Codeforces**: https://codeforces.com
- **HackerRank**: https://www.hackerrank.com
- **VisuAlgo**: https://visualgo.net (Visualizations)

---

## 👤 Author

**Sakshi Dangi** - [@sakshidangi2006](https://github.com/sakshidangi2006)

📧 Email: sakshidangi2006@gmail.com  
🔗 LinkedIn: [Sakshi Dangi](https://linkedin.com/in/sakshi-dangi-633b2635b/)

---

## 📄 License

MIT License - Free to use for learning and education

---



**Star ⭐ this repo if it helps you!**

Last Updated: 2026
