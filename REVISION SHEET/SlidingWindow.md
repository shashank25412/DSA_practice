# Sliding Window Revision Summary

## Core Philosophy

Sliding Window = maintain a **contiguous range** `[L...R]` while reusing previous work.

Pattern:

```text
Expand → Evaluate → Fix (if invalid) → Continue
```

- **Right Pointer (R)** → EXPAND (gain information)
- **Left Pointer (L)** → REPAIR (remove information)

---

## Why Sliding Window is O(n)

Each element:

- enters the window once
- leaves the window once

Pointers only move forward.

```text
O(2N) = O(N)
```

---

## Fixed Window Pattern

Use when:

```text
window size = k
```

Template:

```cpp
expand

if(size > k)
    shrink

if(size == k)
    update answer
```

### Examples

| Problem | Validity | Core State |
|---|---|---|
| Maximum Average Subarray I | `windowSize == k` | Rolling Sum |
| Maximum Number of Vowels | `windowSize == k` | Vowel Count |
| Find All Anagrams | `windowSize == patternSize` | Frequency Map |
| Permutation in String | `windowSize == patternSize` | Frequency Match |

---

## Dynamic Window Pattern

Use when:

```text
window size is unknown
```

Template:

```cpp
expand

while(invalid)
    shrink

update answer
```

### Key Mental Model

```text
Expand aggressively
Shrink only when forced
```

---

## Dynamic Window Fundamentals

### 1. Max Consecutive Ones III

| Topic | Meaning |
|---|---|
| Pattern | Dynamic Sliding Window |
| Goal | Longest valid subarray |
| Validity Condition | `zeroCount <= k` OR `windowSize - ones <= k` |
| Invalid Condition | `zeroCount > k` |
| Expansion Rule | Include new element |
| Shrink Rule | Remove left element until valid |
| Answer Logic | Maximize window length |
| Core Intuition | Flip at most `k` zeros |

---

### 2. Longest Substring Without Repeating Characters

| Topic | Meaning |
|---|---|
| Pattern | Dynamic Sliding Window |
| Goal | Longest unique substring |
| Validity Condition | No duplicate characters |
| Invalid Condition | `freq[s[r]] > 1` |
| State Maintained | Frequency Map |
| Expansion Rule | Add character frequency |
| Shrink Rule | Remove left until duplicate removed |
| Answer Logic | Maximize window length |
| Invariant | Window remains unique after shrinking |

---

### 3. Fruit Into Baskets

| Topic | Meaning |
|---|---|
| Pattern | Dynamic Sliding Window |
| Goal | Longest valid subarray |
| Validity Condition | `distinctFruits <= 2` |
| Invalid Condition | `distinctFruits > 2` |
| State Maintained | Frequency Map |
| Expansion Rule | Add fruit |
| Shrink Rule | Remove until at most 2 distinct |
| Answer Logic | Maximize length |
| Core Intuition | At most K distinct elements |

---

## High-Value Sliding Window Problems

| Problem | Pattern | Validity Condition | Answer Logic |
|---|---|---|---|
| Maximum Average Subarray I | Fixed | `size == k` | Max Avg |
| Maximum Number of Vowels | Fixed | `size == k` | Max Count |
| Max Consecutive Ones III | Dynamic | `zeros <= k` | Max Length |
| Longest Substring Without Repeating Characters | Dynamic | No duplicates | Max Length |
| Fruit Into Baskets | Dynamic | `distinct <= 2` | Max Length |
| Longest Repeating Character Replacement | Dynamic | `(windowSize - maxFreq) <= k` | Max Length |
| Minimum Size Subarray Sum | Dynamic | `sum >= target` | Min Length |
| Minimum Window Substring | Dynamic | All chars covered | Min Length |
| Find All Anagrams | Fixed + Frequency | Frequency Match | Store Indices |
| Permutation in String | Fixed + Frequency | Frequency Match | Boolean Match |

---

## Sliding Window Categories

### 1. Fixed Window
Known size `k`

### 2. Longest Valid Window
Pattern:

```cpp
while(invalid)
    shrink
```

### 3. Minimum Valid Window
Pattern:

```cpp
while(valid)
{
    minimize answer
    shrink
}
```

### 4. At Most K Constraint

Examples:

```text
zeros <= k
distinct <= k
replacements <= k
```

### 5. Frequency Matching

Maintain:

```text
frequency map
```

Used in:

- Anagrams
- Permutations
- Minimum Window Substring

### 6. Counting Windows

Often uses:

```text
Exactly(K) = AtMost(K) - AtMost(K-1)
```

---

## Interview Recognition Logic

### Q1. Is it contiguous?

Keywords:

```text
subarray
substring
continuous
```

If yes → Sliding Window candidate

### Q2. Fixed or Dynamic?

Known size?

- YES → Fixed Window
- NO → Dynamic Window

### Q3. What makes window invalid?

Examples:

```text
duplicates
too many zeros
too many distinct chars
sum exceeded
missing chars
```

This defines:

```cpp
while(invalid)
    shrink
```

### Q4. Longest or Minimum?

Longest:

```cpp
answer = max(...)
```

Minimum:

```cpp
while(valid)
{
    answer=min(...)
    shrink
}
```

---

## 5–10 Minute Revision Sheet

### Pointer Roles

**Right Pointer**

```text
EXPAND
```

**Left Pointer**

```text
REPAIR
```

---

### Golden Question

> What makes the window invalid?

Answer this and the pattern usually becomes obvious.

---

### Master Templates

#### Fixed Window

```cpp
for(int r = 0; r < n; r++) {
    expand();

    if(windowSize > k)
        shrink();

    if(windowSize == k)
        updateAnswer();
}
```

#### Dynamic Window

```cpp
for(int r = 0; r < n; r++) {
    expand();

    while(invalid())
        shrink();

    updateAnswer();
}
```