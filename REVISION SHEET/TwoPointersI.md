# Two Pointers → Reader / Writer (Fast-Slow)

### Pattern Recognition

**Recognition Triggers**
- In-place array modification
- Return new length or transformed result in same array
- O(1) extra space
- Remove / filter / rearrange elements
- Compress / encode / transform input in-place
- Keep valid elements together
- Build answer inside the same array

**Core Invariant**
`nums[0...writer-1]` is always correct.

Everything before `writer` is finalized.

**LC 443 Extension:**  
For compression/encoding problems, `writer` represents the next write position in the transformed array, not a filtered subset of original elements.

---

### Pointer Responsibilities

**Reader**
- Discover information
- Evaluate current element (or group in LC 443)
- Decide if it contributes to answer

**Writer**
- Build answer in-place
- Maintain next write position
- Track size of constructed result

---

### Movement Rule

**Reader**
- Always moves forward
- Every element must be examined

**Writer**
- Moves only when answer grows
- Growth can be:
  - `+1` (LC 27, 26, 283, 80)
  - Variable length (LC 443 compression)

---

### Mental Model

```text
Reader discovers.
Writer records.

OR

Reader explores.
Writer builds answer incrementally.
```

---

### Master Question

> What makes an element (or group) valid for output?

Most Reader/Writer problems differ only in:

- Validity condition
- What constitutes a unit of output (element vs group vs encoded form)

---

### Generic Template

```cpp
int writer = 0;

for (int reader = 0; reader < nums.size(); reader++) {
    if (valid(current element or group)) {
        nums[writer] = processed value from nums[reader];
        writer++;
    }
}

return writer;
```

---

### Variation Table

| LC # | Problem | Valid Condition | Reconstruction Hint |
|------|----------|----------------|---------------------|
| 27 | Remove Element | `nums[reader] != val` | Filter elements. Copy valid elements forward. |
| 26 | Remove Duplicates from Sorted Array | `nums[reader] != nums[writer - 1]` | Compare against the last accepted unique value. |
| 283 | Move Zeroes | `nums[reader] != 0` | Pack non-zero elements to the front while preserving order. |
| 80 | Remove Duplicates from Sorted Array II | `nums[reader] != nums[writer - K]` | Sorted array + frequency constraint. LC80 uses `K = 2`. |
| 443 | String Compression | `chars[reader] != chars[groupStart]` | Maintain `groupStart`; when group ends: `count = reader - groupStart`; write `char + count (if >1)`. |

---

### Notes

#### LC 26
- `reader - 1` works because array is sorted.
- `writer - 1` follows invariant of last accepted element.
- Compare against last written valid element in answer.

#### LC 80
**General Rule:**

```cpp
nums[reader] != nums[writer - K]
```

- Allow at most `K` copies
- LC80 is `K = 2`
- If equality holds, accepting current element would exceed allowed frequency.

#### LC 443
- Reader scans characters one by one.
- `groupStart` marks start of current character run.
- Group ends when:

```cpp
chars[reader] != chars[groupStart]
```

- Group size:

```cpp
reader - groupStart
```

- Writer writes:

```text
char + (count if > 1)
```

- Writer advances based on output size (variable digit length).

---

### 30-Second Interview Recall

```text
Mental Model:
R discovers.
W builds.

Invariant:
nums[0...W-1] is always correct.

Movement:
R → always moves
W → moves only when answer grows

Master Question:
"What makes current thing valid?"

LC27 → Filter
LC26 → Unique
LC283 → Non-zero partition
LC80 → K-frequency
LC443 → Group compression
```
