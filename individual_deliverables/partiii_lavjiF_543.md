# SYSC 4001 — ASSIGNMENT 03
## Part III: Concepts

_Fall 2025_ | _Instructor: Dr. Gabriel Wagner, P. Eng._

**Student(s):**
1. Student 1 --> [_Lavji, F_543_](https://github.com/fareenlavji).
2. Student 2 --> _Ajanthan, A_.

---

# Question 01 (0.6 marks) — Page Replacement Algorithms

**Page Reference String:**

415, 305, 502, 417, 305, 415, 502, 518, 417, 305, 415, 502, 520, 518, 417, 305, 502, 415, 520, 518

## Part i) With 3 Frames Allocated (0.3 marks)

### a) FIFO (First-In-First-Out) Page Replacement Algorithm

**Algorithm Explanation:**

FIFO replaces the page that has been in memory the longest (the oldest page)\[1]. It maintains a queue of pages in the order they were loaded into memory. When a page fault occurs and all frames are full, the page at the front of the queue (oldest) is replaced.

**Step-by-Step Simulation:**

| Step | Page | Frames | Fault? | Explanation |
|------|------|--------|--------|-------------|
| 1 | 415 | \[415] | Yes | Page 415 loaded into empty frame |
| 2 | 305 | \[415, 305] | Yes | Page 305 loaded into empty frame |
| 3 | 502 | \[415, 305, 502] | Yes | Page 502 loaded into empty frame |
| 4 | 417 | \[305, 502, 417] | Yes | Replaced 415 (oldest), loaded 417 |
| 5 | 305 | \[305, 502, 417] | No | Hit: 305 already in memory |
| 6 | 415 | \[502, 417, 415] | Yes | Replaced 305 (oldest), loaded 415 |
| 7 | 502 | \[502, 417, 415] | No | Hit: 502 already in memory |
| 8 | 518 | \[417, 415, 518] | Yes | Replaced 502 (oldest), loaded 518 |
| 9 | 417 | \[417, 415, 518] | No | Hit: 417 already in memory |
| 10 | 305 | \[415, 518, 305] | Yes | Replaced 417 (oldest), loaded 305 |
| 11 | 415 | \[415, 518, 305] | No | Hit: 415 already in memory |
| 12 | 502 | \[518, 305, 502] | Yes | Replaced 415 (oldest), loaded 502 |
| 13 | 520 | \[305, 502, 520] | Yes | Replaced 518 (oldest), loaded 520 |
| 14 | 518 | \[502, 520, 518] | Yes | Replaced 305 (oldest), loaded 518 |
| 15 | 417 | \[520, 518, 417] | Yes | Replaced 502 (oldest), loaded 417 |
| 16 | 305 | \[518, 417, 305] | Yes | Replaced 520 (oldest), loaded 305 |
| 17 | 502 | \[417, 305, 502] | Yes | Replaced 518 (oldest), loaded 502 |
| 18 | 415 | \[305, 502, 415] | Yes | Replaced 417 (oldest), loaded 415 |
| 19 | 520 | \[502, 415, 520] | Yes | Replaced 305 (oldest), loaded 520 |
| 20 | 518 | \[415, 520, 518] | Yes | Replaced 502 (oldest), loaded 518 |

**Results:**

* **Total Page Faults: 16**
* **Total Hits: 4**
* **Hit Ratio: 4/20 = 20.00%**

---

### b) LRU (Least Recently Used) Page Replacement Algorithm

**(Student 1 provides detailed explanation)**

**Algorithm Explanation:**

LRU replaces the page that has not been used for the longest period of time\[1]. The algorithm tracks the time of last access for each page in memory. When a page fault occurs, the page with the oldest "last access time" is replaced. This is based on the principle of temporal locality—if a page hasn't been used recently, it's less likely to be needed soon.

**How LRU Works:**

1. Each page access updates that page's "last used" timestamp
2. When all frames are full and a page fault occurs, scan all pages in memory
3. Replace the page with the oldest timestamp (least recently used)
4. Load the new page and mark current time as its last access

**Step-by-Step Simulation:**

| Step | Page | Frames | Fault? | Explanation |
|------|------|--------|--------|-------------|
| 1 | 415 | \[415] | Yes | Page 415 loaded into empty frame |
| 2 | 305 | \[415, 305] | Yes | Page 305 loaded into empty frame |
| 3 | 502 | \[415, 305, 502] | Yes | Page 502 loaded into empty frame |
| 4 | 417 | \[305, 502, 417] | Yes | Replaced 415 (LRU), loaded 417 |
| 5 | 305 | \[305, 502, 417] | No | Hit: 305 updated as most recent |
| 6 | 415 | \[305, 417, 415] | Yes | Replaced 502 (LRU), loaded 415 |
| 7 | 502 | \[417, 415, 502] | Yes | Replaced 305 (LRU), loaded 502 |
| 8 | 518 | \[415, 502, 518] | Yes | Replaced 417 (LRU), loaded 518 |
| 9 | 417 | \[502, 518, 417] | Yes | Replaced 415 (LRU), loaded 417 |
| 10 | 305 | \[518, 417, 305] | Yes | Replaced 502 (LRU), loaded 305 |
| 11 | 415 | \[417, 305, 415] | Yes | Replaced 518 (LRU), loaded 415 |
| 12 | 502 | \[305, 415, 502] | Yes | Replaced 417 (LRU), loaded 502 |
| 13 | 520 | \[415, 502, 520] | Yes | Replaced 305 (LRU), loaded 520 |
| 14 | 518 | \[502, 520, 518] | Yes | Replaced 415 (LRU), loaded 518 |
| 15 | 417 | \[520, 518, 417] | Yes | Replaced 502 (LRU), loaded 417 |
| 16 | 305 | \[518, 417, 305] | Yes | Replaced 520 (LRU), loaded 305 |
| 17 | 502 | \[417, 305, 502] | Yes | Replaced 518 (LRU), loaded 502 |
| 18 | 415 | \[305, 502, 415] | Yes | Replaced 417 (LRU), loaded 415 |
| 19 | 520 | \[502, 415, 520] | Yes | Replaced 305 (LRU), loaded 520 |
| 20 | 518 | \[415, 520, 518] | Yes | Replaced 502 (LRU), loaded 518 |

**Results:**

* **Total Page Faults: 19**
* **Total Hits: 1**
* **Hit Ratio: 1/20 = 5.00%**

**Analysis:**

LRU performed significantly worse than FIFO with 3 frames (19 faults vs 16 faults). This demonstrates that LRU is not always optimal\[2]. With this particular reference pattern and limited frames, removing the least recently used page happens to be a poor choice for the upcoming references, resulting in more page faults.

---

### c) Optimal Page Replacement Algorithm

**Algorithm Explanation:**

The Optimal algorithm replaces the page that will not be used for the longest period in the future\[1]. This requires knowledge of future page references, making it impractical for real systems but useful as a theoretical benchmark. It produces the minimum possible number of page faults (Belady's optimal algorithm).

**Step-by-Step Simulation:**

| Step | Page | Frames | Fault? | Explanation |
|------|------|--------|--------|-------------|
| 1 | 415 | \[415] | Yes | Page 415 loaded into empty frame |
| 2 | 305 | \[415, 305] | Yes | Page 305 loaded into empty frame |
| 3 | 502 | \[415, 305, 502] | Yes | Page 502 loaded into empty frame |
| 4 | 417 | \[415, 305, 417] | Yes | Replaced 502 (used farthest), loaded 417 |
| 5 | 305 | \[415, 305, 417] | No | Hit: 305 already in memory |
| 6 | 415 | \[415, 305, 417] | No | Hit: 415 already in memory |
| 7 | 502 | \[415, 305, 502] | Yes | Replaced 417 (used farthest), loaded 502 |
| 8 | 518 | \[305, 502, 518] | Yes | Replaced 415 (used farthest), loaded 518 |
| 9 | 417 | \[305, 502, 417] | Yes | Replaced 518 (used farthest), loaded 417 |
| 10 | 305 | \[305, 502, 417] | No | Hit: 305 already in memory |
| 11 | 415 | \[305, 415, 417] | Yes | Replaced 502 (used farthest), loaded 415 |
| 12 | 502 | \[305, 415, 502] | Yes | Replaced 417 (used farthest), loaded 502 |
| 13 | 520 | \[305, 502, 520] | Yes | Replaced 415 (used farthest), loaded 520 |
| 14 | 518 | \[305, 502, 518] | Yes | Replaced 520 (used farthest), loaded 518 |
| 15 | 417 | \[305, 502, 417] | Yes | Replaced 518 (used farthest), loaded 417 |
| 16 | 305 | \[305, 502, 417] | No | Hit: 305 already in memory |
| 17 | 502 | \[305, 502, 417] | No | Hit: 502 already in memory |
| 18 | 415 | \[305, 502, 415] | Yes | Replaced 417 (not used again), loaded 415 |
| 19 | 520 | \[305, 520, 415] | Yes | Replaced 502 (not used again), loaded 520 |
| 20 | 518 | \[520, 415, 518] | Yes | Replaced 305 (not used again), loaded 518 |

**Results:**

* **Total Page Faults: 12**
* **Total Hits: 8**
* **Hit Ratio: 8/20 = 40.00%**

---

## Part ii) With 4 Frames Allocated (0.3 marks)

### a) FIFO with 4 Frames

**Step-by-Step Simulation:**

| Step | Page | Frames | Fault? |
|------|------|--------|--------|
| 1 | 415 | \[415] | Yes |
| 2 | 305 | \[415, 305] | Yes |
| 3 | 502 | \[415, 305, 502] | Yes |
| 4 | 417 | \[415, 305, 502, 417] | Yes |
| 5 | 305 | \[415, 305, 502, 417] | No |
| 6 | 415 | \[415, 305, 502, 417] | No |
| 7 | 502 | \[415, 305, 502, 417] | No |
| 8 | 518 | \[305, 502, 417, 518] | Yes |
| 9 | 417 | \[305, 502, 417, 518] | No |
| 10 | 305 | \[305, 502, 417, 518] | No |
| 11 | 415 | \[502, 417, 518, 415] | Yes |
| 12 | 502 | \[502, 417, 518, 415] | No |
| 13 | 520 | \[417, 518, 415, 520] | Yes |
| 14 | 518 | \[417, 518, 415, 520] | No |
| 15 | 417 | \[417, 518, 415, 520] | No |
| 16 | 305 | \[518, 415, 520, 305] | Yes |
| 17 | 502 | \[415, 520, 305, 502] | Yes |
| 18 | 415 | \[415, 520, 305, 502] | No |
| 19 | 520 | \[415, 520, 305, 502] | No |
| 20 | 518 | \[520, 305, 502, 518] | Yes |

**Results:**

* **Total Page Faults: 10**
* **Total Hits: 10**
* **Hit Ratio: 10/20 = 50.00%**

### b) LRU with 4 Frames

| Step | Page | Frames | Fault? | Explanation                  |
| ---- | ---- | ------ | ------ | ---------------------------- |
| 1    | 415  |        | Yes    | Loaded 415 (empty)           |
| 2    | 305  |        | Yes    | Loaded 305 (empty)           |
| 3    | 502  |        | Yes    | Loaded 502 (empty)           |
| 4    | 417  |        | Yes    | Loaded 417 (empty)           |
| 5    | 305  |        | No     | 305 in memory, update LRU    |
| 6    | 415  |        | No     | 415 in memory, update LRU    |
| 7    | 502  |        | No     | 502 in memory, update LRU    |
| 8    | 518  |        | Yes    | Replaced 415 (LRU), load 518 |
| 9    | 417  |        | Yes    | Replaced 305 (LRU), load 417 |
| 10   | 305  |        | Yes    | Replaced 502 (LRU), load 305 |
| 11   | 415  |        | Yes    | Replaced 518 (LRU), load 415 |
| 12   | 502  |        | Yes    | Replaced 417 (LRU), load 502 |
| 13   | 520  |        | Yes    | Replaced 305 (LRU), load 520 |
| 14   | 518  |        | Yes    | Replaced 415 (LRU), load 518 |
| 15   | 417  |        | Yes    | Replaced 502 (LRU), load 417 |
| 16   | 305  |        | Yes    | Replaced 520 (LRU), load 305 |
| 17   | 502  |        | Yes    | Replaced 518 (LRU), load 502 |
| 18   | 415  |        | Yes    | Replaced 417 (LRU), load 415 |
| 19   | 520  |        | Yes    | Replaced 305 (LRU), load 520 |
| 20   | 518  |        | Yes    | Replaced 502 (LRU), load 518 |

**Results:**

* **Total Page Faults: 17**
* **Total Hits: 3**
* **Hit Ratio: 3/20 = 15.00%**

### c) Optimal with 4 Frames

| Step | Page | Frames | Fault? | Explanation                            |
| ---- | ---- | ------ | ------ | -------------------------------------- |
| 1    | 415  |        | Yes    | Loaded 415 (empty)                     |
| 2    | 305  |        | Yes    | Loaded 305 (empty)                     |
| 3    | 502  |        | Yes    | Loaded 502 (empty)                     |
| 4    | 417  |        | Yes    | Loaded 417 (empty)                     |
| 5    | 305  |        | No     | 305 found (hit)                        |
| 6    | 415  |        | No     | 415 found (hit)                        |
| 7    | 502  |        | No     | 502 found (hit)                        |
| 8    | 518  |        | Yes    | Replace 415 (used farthest), load 518  |
| 9    | 417  |        | No     | 417 found (hit)                        |
| 10   | 305  |        | No     | 305 found (hit)                        |
| 11   | 415  |        | Yes    | Replace 305 (used farthest), load 415  |
| 12   | 502  |        | No     | 502 found (hit)                        |
| 13   | 520  |        | Yes    | Replace 502 (used farthest), load 520  |
| 14   | 518  |        | No     | 518 found (hit)                        |
| 15   | 417  |        | No     | 417 found (hit)                        |
| 16   | 305  |        | Yes    | Replace 415 (not used again), load 305 |
| 17   | 502  |        | Yes    | Replace 417 (not used again), load 502 |
| 18   | 415  |        | Yes    | Replace 502 (not used again), load 415 |
| 19   | 520  |        | No     | 520 found (hit)                        |
| 20   | 518  |        | No     | 518 found (hit)                        |

**Results:**

* **Total Page Faults: 9**
* **Total Hits: 11**
* **Hit Ratio: 11/20 = 55.00%**

---

## Part iii) Analysis and LFU Practice

### iii.a) Comparison of Algorithms with 3 vs 4 Frames

| Algorithm | 3 Frames | 4 Frames | Improvement |
|-----------|----------|----------|-------------|
| FIFO | 16 faults | 10 faults | 6 fewer faults (37.5% reduction) |
| LRU | 19 faults | 17 faults | 2 fewer faults (10.5% reduction) |
| Optimal | 12 faults | 9 faults | 3 fewer faults (25% reduction) |

**Analysis:**

Adding one more frame (from 3 to 4) reduces page faults for all algorithms, but the improvement varies significantly:

* **FIFO:** Shows the most significant improvement (37.5% reduction). With 4 frames, FIFO can hold more pages, and the particular reference pattern benefits greatly from this additional capacity.
* **LRU:** Shows minimal improvement (only 10.5% reduction). This indicates that LRU's replacement decisions are poor for this reference pattern regardless of frame count\[2]. The algorithm's strategy of removing the least recently used page doesn't align well with this workload.
* **Optimal:** Moderate improvement (25% reduction). As expected, Optimal performs best overall and benefits from additional frames but was already efficient with 3 frames.

**Key Observation:** More memory doesn't always proportionally reduce page faults—the benefit depends on both the algorithm and the reference pattern\[1].

---

### iii.b) LFU (Least Frequently Used) Algorithm Practice

**(Student 2 provides detailed explanation)**

**Algorithm Explanation:**

LFU replaces the page that has been accessed the fewest times\[1]. The algorithm maintains a frequency counter for each page in memory. When a page fault occurs and all frames are full, the page with the lowest frequency count is replaced. If multiple pages have the same frequency, LFU uses additional criteria (typically FIFO or LRU) to break the tie.

**How LFU Works:**

1. Maintain a frequency counter for each page
2. Increment counter every time a page is accessed
3. On page fault with full frames, find page(s) with minimum frequency
4. If tie, replace the one that arrived earliest (FIFO tiebreaker)
5. Load new page with frequency initialized to 1

**Step-by-Step Simulation with 3 Frames:**

| Step | Page | Frames | Fault? | Frequency Counts |
|------|------|--------|--------|------------------|
| 1 | 415 | \[415] | Yes | 415:1 |
| 2 | 305 | \[415, 305] | Yes | 415:1, 305:1 |
| 3 | 502 | \[415, 305, 502] | Yes | 415:1, 305:1, 502:1 |
| 4 | 417 | \[417, 305, 502] | Yes | 417:1, 305:1, 502:1 (replaced 415) |
| 5 | 305 | \[417, 305, 502] | No | 417:1, 305:2, 502:1 |
| 6 | 415 | \[415, 305, 502] | Yes | 415:1, 305:2, 502:1 (replaced 417) |
| 7 | 502 | \[415, 305, 502] | No | 415:1, 305:2, 502:2 |
| 8 | 518 | \[518, 305, 502] | Yes | 518:1, 305:2, 502:2 (replaced 415) |
| 9 | 417 | \[417, 305, 502] | Yes | 417:1, 305:2, 502:2 (replaced 518) |
| 10 | 305 | \[417, 305, 502] | No | 417:1, 305:3, 502:2 |
| 11 | 415 | \[415, 305, 502] | Yes | 415:1, 305:3, 502:2 (replaced 417) |
| 12 | 502 | \[415, 305, 502] | No | 415:1, 305:3, 502:3 |
| 13 | 520 | \[520, 305, 502] | Yes | 520:1, 305:3, 502:3 (replaced 415) |
| 14 | 518 | \[518, 305, 502] | Yes | 518:1, 305:3, 502:3 (replaced 520) |
| 15 | 417 | \[417, 305, 502] | Yes | 417:1, 305:3, 502:3 (replaced 518) |
| 16 | 305 | \[417, 305, 502] | No | 417:1, 305:4, 502:3 |
| 17 | 502 | \[417, 305, 502] | No | 417:1, 305:4, 502:4 |
| 18 | 415 | \[415, 305, 502] | Yes | 415:1, 305:4, 502:4 (replaced 417) |
| 19 | 520 | \[520, 305, 502] | Yes | 520:1, 305:4, 502:4 (replaced 415) |
| 20 | 518 | \[518, 305, 502] | Yes | 518:1, 305:4, 502:4 (replaced 520) |

**Results:**

* **Total Page Faults: 18**
* **Total Hits: 2**
* **Hit Ratio: 2/20 = 10.00%**

**LFU Analysis:**

LFU performs poorly with this reference pattern (18 faults), better than LRU (19 faults) but worse than FIFO (16 faults) and significantly worse than Optimal (12 faults).

The problem with LFU for this workload is that pages accessed early (305, 502) build up high frequency counts and become "sticky"—they're rarely replaced even when other pages might be needed more. Pages that appear later or less frequently get replaced quickly, causing thrashing\[2].

**Comparison Summary (3 Frames):**

* Optimal: 12 faults (best - theoretical minimum)
* FIFO: 16 faults
* LFU: 18 faults
* LRU: 19 faults (worst)

This demonstrates that no single replacement algorithm is universally best—performance depends on the specific page reference pattern\[1]\[2].

---

# Question 02 (0.3 marks) — TLB and Memory Access Time

**Given Parameters:**

* Memory access time: **100 nanoseconds**
* TLB lookup time: **20 nanoseconds**
* TLB hit ratio: **95%** (0.95)

## Part a) Effective Memory Access Time WITHOUT TLB

Without a TLB, every memory access requires:

1. One memory access to read the page table entry
2. One memory access to read the actual data

**Calculation:**

```
Effective Access Time = Page Table Access + Data Access
Effective Access Time = 100 ns + 100 ns = 200 ns
```

**Answer: 200 nanoseconds**

---

## Part b) Effective Memory Access Time WITH TLB

With a TLB, we have two scenarios:

**TLB Hit (95% of the time):**

* TLB lookup: 20 ns
* Data access: 100 ns
* Total: 120 ns

**TLB Miss (5% of the time):**

* TLB lookup: 20 ns (unsuccessful)
* Page table access: 100 ns
* Data access: 100 ns
* Total: 220 ns

**Calculation:**

```
Effective Access Time = P\_hit × T\_hit + P\_miss × T\_miss
Effective Access Time = 0.95 × 120 + 0.05 × 220
Effective Access Time = 114 + 11 = 125 ns
```

**Answer: 125 nanoseconds**

---

## Part c) Performance Analysis

**Performance Improvement:**

* Without TLB: 200 ns
* With TLB: 125 ns
* **Speedup: 200/125 = 1.6× (60% faster)**
* **Time Saved per Access:** 200 - 125 = 75 ns (37.5% reduction)

**Analysis:**

The TLB provides significant performance improvement even with the 20 ns lookup overhead\[3]. The 95% hit ratio means that in the vast majority of cases, we avoid the expensive page table lookup. The TLB is critical for modern systems because:

1. **Temporal locality:** Recently accessed pages are likely to be accessed again
2. **Spatial locality:** Nearby addresses often use the same page
3. **Reduces memory traffic:** Fewer page table accesses reduce memory bus contention

Even a small, fast TLB (typically 64-256 entries) can achieve high hit ratios due to program locality, making it one of the most effective caching mechanisms in computer architecture\[3].

**When TLB Can Hurt Performance:**

While the TLB generally improves performance, there are situations where it might perform worse:

* **Very low hit ratio:** If the working set exceeds TLB capacity significantly
* **High overhead:** If TLB lookup time is disproportionately high
* **Random access patterns:** Applications with poor locality suffer more TLB misses
* **Context switching:** Frequent process switches may flush the TLB, reducing effectiveness

---

# Question 03 (0.3 marks) — Paging and Address Translation

**Given System Specifications:**

* Page size: **4 KB = 4096 bytes = 2^12 bytes**
* Logical address space: **128 pages**
* Physical memory: **512 KB**

## Part a) Logical Address Format

**Logical Address Components:**

A logical address consists of:

* **Page number:** Identifies which page
* **Page offset:** Position within the page

**Calculations:**

Number of pages: 128 = 2^7  
Therefore, **page number requires 7 bits**

Page size: 4 KB = 4096 bytes = 2^12 bytes  
Therefore, **offset requires 12 bits**

**Logical Address Format:**

```
+-------------------+-------------------+
| Page Number (7)   | Offset (12)       |
+-------------------+-------------------+
```

**Total logical address size: 7 + 12 = 19 bits**

**Logical address space: 2^19 = 524,288 bytes = 512 KB**

---

## Part b) Page Table Size and Format

**Physical Memory Analysis:**

Physical memory: 512 KB = 524,288 bytes  
Page size: 4 KB = 4096 bytes  
Number of physical frames: 512 KB / 4 KB = **128 frames**

Frames: 128 = 2^7  
Therefore, **frame number requires 7 bits**

**Page Table Entry (PTE) Format:**

Each PTE must contain:

* **Frame number:** 7 bits (to address 128 frames)
* **Valid bit:** 1 bit (indicates if page is in memory)
* **Protection bits:** Typically 2-3 bits (read/write/execute)
* **Modified bit:** 1 bit (dirty bit)
* **Referenced bit:** 1 bit (for replacement algorithms)

**Minimum PTE size:** 7 + 1 + 3 + 1 + 1 = 13 bits  
**Practical PTE size:** Rounded up to 16 bits (2 bytes) for alignment

**Page Table Size:**

Number of entries: 128 pages  
Size per entry: 2 bytes  
**Total page table size: 128 × 2 = 256 bytes**

**Answer:**

* **Width** of the page table: **9 bits per entry** (7 frame + 2 control bits minimum)
* **Length** of the page table: **256 bytes** (128 entries × 2 bytes)

---

## Part c) Effect of Reducing Physical Memory to 256 KB

**New Physical Memory Analysis:**

Physical memory: 256 KB = 262,144 bytes  
Page size: 4 KB = 4096 bytes  
Number of physical frames: 256 KB / 4 KB = **64 frames**

Frames: 64 = 2^6  
Therefore, **frame number requires 6 bits**

**Impact on Logical Address:**

**No change to logical address format!**

The logical address is determined by the logical address space (number of pages and page size), which remains:

* 128 pages = 7 bits for page number
* 4 KB pages = 12 bits for offset
* Total: 19 bits

```
+-------------------+-------------------+
| Page Number (7)   | Offset (12)       |
+-------------------+-------------------+
```

**Impact on Page Table Entry:**

* Frame number: Now 6 bits (instead of 7)
* Other bits: Unchanged
* **New PTE size: 15 bits minimum, still 2 bytes practical**

**Page table size:** Still 128 entries × 2 bytes = **256 bytes**

**Key Insight:**

Reducing physical memory does NOT change the logical address space or format\[1]. It only affects:

1. Number of frames available
2. Bits needed for frame number in PTE
3. More page faults (not enough frames for all pages)

The logical address space represents the programmer's view, which is independent of physical memory size. The operating system manages the mismatch through virtual memory and demand paging\[3].

---

# Question 04 (0.1 marks) — File System lseek Operation

**Question:** Explain what happens during an `lseek(fd, offset, SEEK\_END)` operation in a file system with hierarchical directory structure.

**Answer:**

The `lseek(fd, offset, SEEK\_END)` system call repositions the file offset (read/write pointer) of the open file descriptor `fd` relative to the end of the file\[4].

**Operation Steps:**

1. **Validate file descriptor:** System checks that `fd` is a valid open file descriptor with appropriate permissions
2. **Locate inode:** System retrieves the inode for the file from the file descriptor table
3. **Get file size:** Read the file size from the inode structure
4. **Calculate new position:**

```
   new\_position = file\_size + offset
   ```

   * If `offset = 0`: Position at end of file (common for append)
   * If `offset > 0`: Position beyond end of file (creates "hole")
   * If `offset < 0`: Position before end of file

5. **Update file table entry:** Modify the file offset in the process's file table entry to the new position
6. **Return new position:** Return the new file offset value to the calling process

**Important Characteristics:**

* **No I/O occurs:** `lseek` only modifies the file offset pointer, no data is read or written
* **Beyond EOF is legal:** Can seek beyond the file end, creating a sparse file (hole) on next write
* **Atomic operation:** The offset update is atomic for the process
* **Per-descriptor offset:** Each file descriptor has its own offset, even if multiple descriptors reference the same file

**Common Use Case:**

```c
// Append to file
fd = open("file.txt", O\_RDWR);
lseek(fd, 0, SEEK\_END);  // Position at end
write(fd, data, size);    // Append data
```

**Directory Structure Involvement:**

In hierarchical directory structures, the operation only affects the **file table entry** for this specific open file. The directory entry and inode remain unchanged (unless a subsequent write extends the file, which would update the inode's size field)\[4].

---

# Question 05 (0.2 marks) — Inode-based File System

**Given Specifications:**

* Block size: **8 KB = 8192 bytes**
* Pointer size: **4 bytes**
* Inode contains:

  * 12 direct pointers
  * 1 single indirect pointer
  * 1 double indirect pointer
  * 1 triple indirect pointer

## Part a) Maximum File Size Calculation

**Pointers per block:**

```
Pointers per block = Block size / Pointer size
                   = 8192 / 4 = 2048 pointers
```

**Direct blocks:**

* 12 direct pointers
* Each points to one 8 KB block
* Total: 12 × 8 KB = **96 KB**

**Single indirect:**

* 1 indirect block containing 2048 pointers
* Each pointer references one 8 KB data block
* Total: 2048 × 8 KB = 16,384 KB = **16 MB**

**Double indirect:**

* 1 double indirect block containing 2048 pointers
* Each points to a single indirect block (containing 2048 pointers)
* Each of those pointers references one 8 KB data block
* Total: 2048 × 2048 × 8 KB = 33,554,432 KB = **32 GB**

**Triple indirect:**

* 1 triple indirect block containing 2048 pointers
* Each points to a double indirect block (containing 2048 pointers)
* Each of those points to a single indirect block (containing 2048 pointers)
* Each of those pointers references one 8 KB data block
* Total: 2048 × 2048 × 2048 × 8 KB = 68,719,476,736 KB = **64 TB**

**Maximum File Size:**

```
Max size = 96 KB + 16 MB + 32 GB + 64 TB
Max size ≈ 64 TB
```

(The direct, single indirect, and double indirect contributions are negligible compared to triple indirect)

**Answer: Maximum file size ≈ 64 TB (64 terabytes)**

**Exact calculation:**

* Direct: 98,304 bytes
* Single indirect: 16,777,216 bytes
* Double indirect: 34,359,738,368 bytes
* Triple indirect: 70,368,744,177,664 bytes
* **Total: 70,403,120,791,552 bytes = 64.000 TB**

---

## Part b) Strategy for Larger Files

To support files larger than 64 TB with this inode structure, the file system could implement the following strategies:

### Strategy 1: Extent-Based Storage (Recommended)

Instead of storing individual block pointers, use **extents** (contiguous runs of blocks):

```c
struct extent {
    uint64\_t start\_block;  // Starting block number
    uint32\_t length;       // Number of contiguous blocks
}
```

**Benefits:**

* Each pointer represents multiple contiguous blocks
* Dramatically increases addressable space
* Reduces metadata overhead
* Better for large sequential files
* Example: If average extent is 100 blocks, capacity increases 100×

**Example:** Modern file systems like **ext4** use extent trees that can handle files up to 1 EB (exabyte)\[4].

---

### Strategy 2: Larger Block Size

Increase block size from 8 KB to 64 KB or larger:

**Impact:**

* Pointers per block: 64 KB / 4 bytes = 16,384 pointers
* Triple indirect: 16,384^3 × 64 KB = **256 PB (petabytes)**

**Trade-offs:**

* More internal fragmentation for small files
* Larger I/O operations
* Need careful tuning for workload

---

### Strategy 3: 64-bit Pointers

Increase pointer size from 4 bytes to 8 bytes:

**Impact:**

* Pointers per block: 8192 / 8 = 1024 pointers
* Triple indirect: 1024^3 × 8 KB = **8 PB**
* Can address vastly larger storage devices

**Trade-off:**

* Increased metadata overhead (fewer pointers per block)
* More blocks needed for large files

---

### Strategy 4: Hybrid Approach (Most Practical)

Combine extent-based allocation with larger pointers:

1. Use extents for large sequential portions
2. Use 8-byte pointers for future expansion
3. Add a 4th level of indirection (quadruple indirect)
4. Implement different inode formats for different file types

**Example modern file system:** **XFS** uses extent-based B+ trees that can handle files up to 8 EB (exabytes)\[4].

---

### Strategy 5: Multiple Files (Application-Level)

**How it works:** Split large files into chunks that fit within the maximum file size limit. Each chunk is stored as a separate file in the file system.

**Example:** A **140 TB** file would be split into:

* File 1: 70 TB (one inode)
* File 2: 70 TB (another inode)

The operating system or application would manage these files as if they were a single larger file.

---

### Strategy 6: Distributed/Virtual File Systems

**How it works:** A distributed file system (like **HDFS**, **Ceph**, or **GlusterFS**) allows data to be split across multiple physical storage devices or nodes.

**Example:** A **1 PB** file can be stored using HDFS, which breaks it into smaller blocks (e.g., 128 MB each) and distributes them across many machines. The file appears as one continuous file to applications\[4].

---

### Recommended Strategy:

**Extent-based storage** is the best solution because:

* Maintains reasonable block size (no fragmentation issues)
* Dramatically increases capacity without changing pointer size
* Improves performance (fewer metadata lookups for large files)
* Flexible (can represent both small and large files efficiently)

Modern file systems like **ext4**, **XFS**, and **Btrfs** all use extent-based approaches for this reason\[4].

---

# References

\[1] Silberschatz, A., Galvin, P. B., \& Gagne, G. (2018). *Operating System Concepts* (10th ed.). Wiley. Chapters 9-10 (Virtual Memory, Memory Management).

\[2] Tanenbaum, A. S., \& Bos, H. (2014). *Modern Operating Systems* (4th ed.). Pearson. Chapter 3 (Memory Management).

\[3] Arpaci-Dusseau, R. H., \& Arpaci-Dusseau, A. C. (2018). *Operating Systems: Three Easy Pieces*. Arpaci-Dusseau Books. Chapters 18-20 (Paging, TLBs).

\[4] Love, R. (2010). *Linux Kernel Development* (3rd ed.). Addison-Wesley. Chapter 13 (The Virtual Filesystem).

---

---

# ANNEX: Previous Year Solutions (Fall 2024)

## Comparative Analysis Document

This annex contains the solutions from the previous year's assignment (Fall 2024) for reference and comparison purposes. Formatting was extracted for consistency, note the differences in:

* Page reference strings
* Memory access parameters
* Problem specifications

---

# SYSC 4001 — ASSIGNMENT 03
## Part III: Concepts

_Fall 2024_ | _Instructor: Dr. Gabriel Wagner, P. Eng._

**Student(s):**
1. Student 1 --> [_Lavji, F_543_](https://github.com/fareenlavji).
2. Student 2 --> _E, D_099_.

# Question 01 (Fall 2024)

**Page Reference String (2024):**

201, 302, 203, 404, 302, 201, 205, 206, 302, 201, 302, 203, 207, 206, 203, 302, 201, 302, 203, 206

## Part i) With 3 Frames Allocated

### a) LFU Page Replacement Algorithm (2024)

**Algorithm Explanation:**

LFU replaces the page that has been used the least number of times in the past. If multiple pages have the same frequency, LFU replaces the page that was used least recently among them.

**Step-by-Step Simulation:**

| Step | Page Reference | Page in Memory | Page Fault? | Explanation |
|------|----------------|----------------|-------------|-------------|
| 1 | 201 | \[201] | Yes | Page 201 is not in memory, load it. |
| 2 | 302 | \[201, 302] | Yes | Page 302 is not in memory, load it. |
| 3 | 203 | \[201, 302, 203] | Yes | Page 203 is not in memory, load it. |
| 4 | 404 | \[404, 302, 203] | Yes | Page 404 is not in memory. Replace 201 (LRU). |
| 5 | 302 | \[404, 302, 203] | No | Page 302 is already in memory. |
| 6 | 201 | \[404, 302, 201] | Yes | Page 201 is not in memory. Replace 203 (LFU). |
| 7 | 205 | \[404, 302, 205] | Yes | Page 205 is not in memory. Replace 203 (LFU). |
| 8 | 206 | \[206, 302, 205] | Yes | Page 206 is not in memory. Replace 404 (LFU). |
| 9 | 302 | \[206, 302, 205] | No | Page 302 is already in memory. |
| 10 | 201 | \[206, 302, 201] | Yes | Page 201 is not in memory. Replace 205 (LFU). |
| 11 | 302 | \[206, 302, 201] | No | Page 302 is already in memory. |
| 12 | 203 | \[203, 302, 201] | Yes | Page 203 is not in memory. Replace 206 (LFU). |
| 13 | 207 | \[203, 302, 207] | Yes | Page 207 is not in memory. Replace 201 (LFU). |
| 14 | 206 | \[206, 302, 207] | Yes | Page 206 is not in memory. Replace 203 (LFU). |
| 15 | 203 | \[206, 302, 203] | Yes | Page 203 is not in memory. Replace 207 (LFU). |
| 16 | 302 | \[206, 302, 203] | No | Page 302 is already in memory. |
| 17 | 201 | \[201, 302, 203] | Yes | Page 201 is not in memory. Replace 206 (LFU). |
| 18 | 302 | \[201, 302, 203] | No | Page 302 is already in memory. |
| 19 | 203 | \[201, 302, 203] | No | Page 203 is already in memory. |
| 20 | 206 | \[201, 302, 206] | Yes | Page 206 is not in memory. Replace 201 (LFU). |

**Total Page Faults: 15**

---

### b) FIFO Page Replacement Algorithm (2024)

**Algorithm Explanation:**

In FIFO, we replace the page that was first loaded into memory and hasn't been replaced yet.

**Step-by-Step Simulation:**

| Step | Page Reference | Page in Memory | Page Fault? | Explanation |
|------|----------------|----------------|-------------|-------------|
| 1 | 201 | \[201] | Yes | Page 201 is not in memory, load it. |
| 2 | 302 | \[201, 302] | Yes | Page 302 is not in memory, load it. |
| 3 | 203 | \[201, 302, 203] | Yes | Page 203 is not in memory, load it. |
| 4 | 404 | \[302, 203, 404] | Yes | Page 404 is not in memory. Replace 201 (FIFO). |
| 5 | 302 | \[302, 203, 404] | No | Page 302 is already in memory. |
| 6 | 201 | \[201, 203, 404] | Yes | Page 201 is not in memory. Replace 302 (FIFO). |
| 7 | 205 | \[201, 205, 404] | Yes | Page 205 is not in memory. Replace 203 (FIFO). |
| 8 | 206 | \[201, 205, 206] | Yes | Page 206 is not in memory. Replace 404 (FIFO). |
| 9 | 302 | \[302, 205, 206] | Yes | Page 302 is not in memory. Replace 201 (FIFO). |
| 10 | 201 | \[302, 205, 201] | Yes | Page 201 is not in memory. Replace 206 (FIFO). |
| 11 | 302 | \[302, 205, 201] | No | Page 302 is already in memory. |
| 12 | 203 | \[203, 205, 201] | Yes | Page 203 is not in memory. Replace 302 (FIFO). |
| 13 | 207 | \[203, 205, 207] | Yes | Page 207 is not in memory. Replace 201 (FIFO). |
| 14 | 206 | \[206, 205, 207] | Yes | Page 206 is not in memory. Replace 203 (FIFO). |
| 15 | 203 | \[206, 205, 203] | Yes | Page 203 is not in memory. Replace 207 (FIFO). |
| 16 | 302 | \[206, 302, 203] | Yes | Page 302 is not in memory. Replace 205 (FIFO). |
| 17 | 201 | \[201, 302, 203] | Yes | Page 201 is not in memory. Replace 206 (FIFO). |
| 18 | 302 | \[201, 302, 203] | No | Page 302 is already in memory. |
| 19 | 203 | \[201, 302, 203] | No | Page 203 is already in memory. |
| 20 | 206 | \[201, 302, 206] | Yes | Page 206 is not in memory. Replace 203 (FIFO). |

**Total Page Faults: 15**

---

### c) Optimal Page Replacement Algorithm (2024)

**Algorithm Explanation:**

The page that will not be used for the longest period in the future is replaced. If multiple pages have the same future usage time, the one that is furthest in the future is replaced.

**Step-by-Step Simulation:**

| Step | Page Reference | Page in Memory | Page Fault? | Explanation |
|------|----------------|----------------|-------------|-------------|
| 1 | 201 | \[201] | Yes | Page 201 is not in memory, load it. |
| 2 | 302 | \[201, 302] | Yes | Page 302 is not in memory, load it. |
| 3 | 203 | \[201, 302, 203] | Yes | Page 203 is not in memory, load it. |
| 4 | 404 | \[302, 203, 404] | Yes | Replace 201 (not used again in future). |
| 5 | 302 | \[302, 203, 404] | No | Page 302 is already in memory. |
| 6 | 201 | \[201, 203, 404] | Yes | Replace 203 (used last in future). |
| 7 | 205 | \[201, 205, 404] | Yes | Replace 404 (used furthest in future). |
| 8 | 206 | \[201, 205, 206] | Yes | Replace 404 (used furthest in future). |
| 9 | 302 | \[201, 205, 302] | Yes | Replace 206 (used last in future). |
| 10 | 201 | \[201, 205, 302] | No | Page 201 is already in memory. |
| 11 | 302 | \[201, 205, 302] | No | Page 302 is already in memory. |
| 12 | 203 | \[203, 205, 302] | Yes | Replace 205 (used last in future). |
| 13 | 207 | \[203, 207, 302] | Yes | Replace 302 (used furthest in future). |
| 14 | 206 | \[203, 207, 206] | Yes | Replace 302 (used furthest in future). |
| 15 | 203 | \[203, 207, 206] | No | Page 203 is already in memory. |
| 16 | 302 | \[302, 207, 206] | Yes | Replace 207 (used last in future). |
| 17 | 201 | \[302, 201, 206] | Yes | Replace 206 (used furthest in future). |
| 18 | 302 | \[302, 201, 206] | No | Page 302 is already in memory. |
| 19 | 203 | \[203, 201, 206] | Yes | Replace 302 (used last in future). |
| 20 | 206 | \[203, 201, 206] | No | Page 206 is already in memory. |

**Total Page Faults: 14**

---

## Part ii) With 4 Frames Allocated (2024)

### a) LFU with 4 Frames (2024)

| Step | Page Reference | Page in Memory | Page Fault? | Explanation |
|------|----------------|----------------|-------------|-------------|
| 1 | 201 | \[201] | Yes | Page 201 is not in memory, load it. |
| 2 | 302 | \[201, 302] | Yes | Page 302 is not in memory, load it. |
| 3 | 203 | \[201, 302, 203] | Yes | Page 203 is not in memory, load it. |
| 4 | 404 | \[201, 302, 203, 404] | Yes | Page 404 is not in memory, load it. |
| 5 | 302 | \[201, 302, 203, 404] | No | Page 302 is already in memory. |
| 6 | 201 | \[201, 302, 203, 404] | No | Page 201 is already in memory. |
| 7 | 205 | \[201, 302, 203, 404, 205] | Yes | Page 205 is not in memory, load it. |
| 8 | 206 | \[201, 302, 203, 404, 205, 206] | Yes | Page 206 is not in memory, load it. |
| 9 | 302 | \[201, 302, 203, 404, 205, 206] | No | Page 302 is already in memory. |
| 10 | 201 | \[201, 302, 203, 404, 205, 206] | No | Page 201 is already in memory. |
| 11 | 302 | \[201, 302, 203, 404, 205, 206] | No | Page 302 is already in memory. |
| 12 | 203 | \[201, 302, 203, 404, 205, 206] | No | Page 203 is already in memory. |
| 13 | 207 | \[201, 302, 203, 404, 205, 206] | Yes | Page 207 is not in memory. |

**Total Page Faults: 7**

---

### b) FIFO with 4 Frames (2024)

| Step | Page Reference | Page in Memory | Page Fault? | Explanation |
|------|----------------|----------------|-------------|-------------|
| 1 | 201 | \[201] | Yes | Page 201 is not in memory, load it. |
| 2 | 302 | \[201, 302] | Yes | Page 302 is not in memory, load it. |
| 3 | 203 | \[201, 302, 203] | Yes | Page 203 is not in memory, load it. |
| 4 | 404 | \[201, 302, 203, 404] | Yes | Page 404 is not in memory, load it. |
| 5 | 302 | \[201, 302, 203, 404] | No | Page 302 is already in memory. |
| 6 | 201 | \[201, 302, 203, 404] | No | Page 201 is already in memory. |
| 7 | 205 | \[302, 203, 404, 205] | Yes | Replace 201. |
| 8 | 206 | \[203, 404, 205, 206] | Yes | Replace 302. |
| 9 | 302 | \[404, 205, 206, 302] | Yes | Replace 203. |
| 10 | 201 | \[205, 206, 302, 201] | Yes | Replace 404. |
| 11 | 302 | \[205, 206, 302, 201] | No | Page 302 is already in memory. |
| 12 | 203 | \[206, 302, 201, 203] | Yes | Replace 205. |
| 13 | 207 | \[302, 201, 203, 207] | Yes | Replace 206. |
| 14 | 206 | \[201, 203, 207, 206] | Yes | Replace 302. |
| 15 | 203 | \[201, 203, 207, 206] | No | Page 203 is already in memory. |
| 16 | 302 | \[203, 207, 206, 302] | Yes | Replace 201. |
| 17 | 201 | \[207, 206, 302, 201] | Yes | Replace 203. |
| 18 | 302 | \[207, 206, 302, 201] | No | Page 302 is already in memory. |
| 19 | 203 | \[206, 302, 201, 203] | Yes | Replace 207. |
| 20 | 206 | \[302, 201, 203, 206] | No | Page 206 is already in memory. |

**Total Page Faults: 16**

---

### c) Optimal with 4 Frames (2024)

| Step | Page Reference | Page in Memory | Page Fault? | Explanation |
|------|----------------|----------------|-------------|-------------|
| 1 | 201 | \[201] | Yes | Page 201 is not in memory, load it. |
| 2 | 302 | \[201, 302] | Yes | Page 302 is not in memory, load it. |
| 3 | 203 | \[201, 302, 203] | Yes | Page 203 is not in memory, load it. |
| 4 | 404 | \[201, 302, 203, 404] | Yes | Page 404 is not in memory, load it. |
| 5 | 302 | \[201, 302, 203, 404] | No | Page 302 is already in memory. |
| 6 | 201 | \[201, 302, 203, 404] | No | Page 201 is already in memory. |
| 7 | 205 | \[201, 302, 203, 404, 205] | Yes | Page 205 is not in memory, load it. |
| 8 | 206 | \[302, 203, 404, 205, 206] | Yes | Replace 201 (used furthest in future). |
| 9 | 302 | \[302, 203, 404, 205, 206] | No | Page 302 is already in memory. |
| 10 | 201 | \[201, 203, 404, 205, 206] | Yes | Replace 302 (used furthest in future). |
| 11 | 302 | \[201, 302, 404, 205, 206] | Yes | Replace 203 (used furthest in future). |
| 12 | 203 | \[201, 302, 404, 205, 206] | No | Page 203 is already in memory. |
| 13 | 207 | \[201, 302, 404, 205, 206] | Yes | Replace 206 (used furthest in future). |
| 14 | 206 | \[201, 302, 404, 205, 207] | Yes | Replace 207 (used furthest in future). |
| 15 | 203 | \[201, 302, 404, 205, 206] | No | Page 203 is already in memory. |
| 16 | 302 | \[302, 203, 404, 205, 206] | No | Page 302 is already in memory. |
| 17 | 201 | \[201, 302, 404, 205, 206] | No | Page 201 is already in memory. |
| 18 | 302 | \[201, 302, 404, 205, 206] | No | Page 302 is already in memory. |
| 19 | 203 | \[201, 302, 404, 205, 206] | No | Page 203 is already in memory. |
| 20 | 206 | \[201, 302, 404, 205, 206] | No | Page 206 is already in memory. |

**Total Page Faults: 14**

---

# Question 2 (Fall 2024)

**Given Parameters (2024):**

* Memory reference time: **250 ns**
* TLB lookup time: **30 ns**
* TLB hit ratio: **80%** (0.80)

## Part a) Total Time for Paged Memory Reference (2024)

**Assumptions:**

* Memory access time: 250 ns (for each memory access)
* System uses a single-level page table
* Page table is always in memory

**Total Time:**

Since there are two memory accesses:

1. One for accessing the page table
2. One for accessing the data

```
Total time = Page table lookup time + Data access time
Total time = 250 ns + 250 ns = 500 ns
```

**Answer: 500 nanoseconds**

---

## Part b) Effective Memory Access Time with TLB (2024)

**When there is a TLB hit (80%):**

```
Hit time = TLB lookup time + Data access time
Hit time = 30 ns + 250 ns = 280 ns
```

**When there is a TLB miss (20%):**

```
Miss time = TLB lookup time + Page table lookup time + Data access time
Miss time = 30 ns + 250 ns + 250 ns = 530 ns
```

**Effective Memory Access Time (EMAT):**

```
EMAT = (Hit rate × Hit time) + (Miss rate × Miss time)
EMAT = (0.80 × 280 ns) + (0.20 × 530 ns)
EMAT = 224 ns + 106 ns = 330 ns
```

**Answer: 330 nanoseconds**

---

## Part c) TLB Performance Analysis (2024)

The Translation Lookaside Buffer (TLB) is a specialized cache that stores recent virtual-to-physical address translations. The main reason for adding a TLB is to reduce memory access time for most memory references.

**Benefits:**

1. **Faster Address Translation:**

   * Without TLB: Every memory reference requires a page table lookup
   * With TLB: Translation found immediately on hit, skipping page table access

2. **Reduced Memory Accesses:**

   * 80% hit rate means we skip page table lookup 80% of the time
   * Significantly reduces average memory access time

3. **Improved Efficiency:**

   * TLB implemented in hardware, closer to CPU
   * Takes only a few CPU cycles to check

**When TLB Might Hurt Performance:**

While the TLB generally improves performance, there are situations where it might perform worse:

* **Low hit rate:** If working set exceeds TLB capacity significantly
* **High overhead:** If TLB lookup time is disproportionately high
* **Random access patterns:** Applications with poor locality suffer more TLB misses
* **Context switching:** Frequent process switches may flush TLB, reducing effectiveness

---

# Question 3 (Fall 2024)

**Given Specifications (2024):**

* Page size: **2 KB = 2048 bytes = 2^11 bytes**
* Logical address space: **64 KB**
* Physical memory: **1024 KB (1 MB)**

## Part a) Logical Address Format (2024)

**1. Number of bits for Page Offset:**

Page size: 2 KB = 2^11 bytes  
Therefore, **page offset requires 11 bits**

**2. Number of bits for Page Number:**

Total logical address space: 64 KB = 64 × 1024 = 65,536 bytes  
Number of pages: 64 KB / 2 KB = **32 pages**  
Pages: 32 = 2^5  
Therefore, **page number requires 5 bits**

**3. Format of Logical Address:**

```
Logical Address = Page Number (5 bits) + Page Offset (11 bits)
Total = 5 + 11 = 16 bits
```

**Answer: Logical address is 16 bits (5-bit page number + 11-bit offset)**

---

## Part b) Page Table Size (2024)

**1. Number of entries in page table:**

Number of entries = Number of pages = **32 entries**

**2. Page Table Entry (PTE) Size:**

Physical memory: 1024 KB = 1,048,576 bytes  
Number of frames: 1024 KB / 2 KB = **512 frames**  
Frames: 512 = 2^9  
Therefore, frame number requires **9 bits**

**3. Length and Width of Page Table:**

Width per entry: **9 bits** (for frame number)  
Length: 32 entries × 9 bits = 288 bits = **36 bytes**

**Answer:**

* **Width:** 9 bits per entry
* **Length:** 288 bits or 36 bytes

---

## Part c) Effect of Reducing Physical Memory (2024)

**New Physical Memory: 512 KB**

Number of frames: 512 KB / 2 KB = **256 frames**  
Frames: 256 = 2^8  
Therefore, frame number requires **8 bits**

**Impact on Page Table:**

1. **Page Table Entry Size:** Decreases from 9 bits to 8 bits
2. **Overall page table size:** 32 entries × 8 bits = 256 bits = **32 bytes**

**Impact on Logical Address:**

**No change!** The logical address format remains:

* Page number: 5 bits
* Page offset: 11 bits
* Total: 16 bits

The logical address space represents the programmer's view, independent of physical memory size.

---

# Question 4 (Fall 2024)

## Write Operation in APPEND Mode

In a file system with hierarchical directory structure, a write operation in APPEND mode involves several steps:

**1. File Open Operation (with APPEND mode):**

* File descriptor allocated
* File pointer automatically set to end of file
* Metadata retrieved from inode and directory entry

**2. Check Available Space:**

* Verify sufficient space in current data blocks
* If insufficient, allocate new blocks

**3. File System Block Allocation:**

* **Locate Free Blocks:** Check free space management structures
* **Allocate New Blocks:** Mark blocks as allocated in bitmap/free list
* **Link New Blocks:** Update inode with pointers to new blocks

**4. Write the Data:**

* **Buffering:** Copy data to buffer cache
* **Data Write:** Write buffered data to allocated blocks
* **Update File Size:** Update file size in inode

**5. Update Inode and Directory:**

* **Update Inode:** Modify size and block pointers
* **Directory Structure:** Update last modified timestamp in directory entry

**6. Synchronize and Commit Changes:**

* **Flush Data to Disk:** Write buffer cache to physical storage
* **Metadata Commit:** Write inode and directory entry changes to disk

**Additional Considerations:**

* **Concurrency:** File system ensures atomicity through locking or journaling
* **Write Buffering:** Many systems use caching for improved performance
* **File System Type:** Exact steps vary by file system (FAT, NTFS, ext4, etc.)

---

# Question 5 (Fall 2024)

**Given Specifications (2024):**

* Block size: **8 KB = 8192 bytes**
* Pointer size: **4 bytes**
* Inode: 12 direct + 1 single indirect + 1 double indirect + 1 triple indirect

## Part a) Maximum File Size (2024)

**Pointers per block:**

```
Pointers per block = 8192 / 4 = 2048 pointers
```

**1. Size from direct blocks:**

```
12 × 8192 bytes = 98,304 bytes
```

**2. Size from single indirect:**

```
2048 × 8192 bytes = 16,777,216 bytes = 16 MB
```

**3. Size from double indirect:**

```
2048 × 2048 × 8192 bytes = 34,359,738,368 bytes = 32 GB
```

**4. Size from triple indirect:**

```
2048 × 2048 × 2048 × 8192 bytes = 70,368,744,177,664 bytes = 64 TB
```

**Total Maximum File Size:**

```
98,304 + 16,777,216 + 34,359,738,368 + 70,368,744,177,664
= 70,403,143,013,552 bytes ≈ 70.4 TB
```

**Answer: Maximum file size ≈ 70.4 TB**

---

## Part b) Strategies for Larger Files (2024)

**1. Use Multiple Files (Splitting):**

* Break large file into chunks that fit within 70.4 TB limit
* Example: 140 TB file → two 70 TB files
* OS manages as single logical file

**2. Use New File System with Larger Inodes:**

* Modern file systems (ZFS, Btrfs) support larger files natively
* Example: ZFS can handle 500 TB files directly

**3. Virtual/Distributed File Systems:**

* HDFS, Ceph, GlusterFS split data across multiple nodes
* Example: 1 PB file distributed across HDFS cluster
* Appears as single file to applications

**4. Use File System with Large Block Sizes:**

* Increase from 8 KB to 16 KB blocks
* With 16 KB blocks: 4 pointers per entry
* Larger addressable space

**5. Object Storage Systems:**

* Amazon S3, Azure Blob Storage
* No traditional file system limitations
* Example: 5 TB file uploaded to S3 with no size restrictions

---

# End of Annex

---

## Document Metadata

* **2025 Solutions:** Based on Fall 2025 SYSC 4001 Assignment 3 specification
* **2024 Solutions:** From previous year submission (Student(s): [Lavji, F_543](https://github.com/fareenlavji), E, D_099)
* **Compiled:** November 21, 2025
* **Format:** Markdown with academic citations

---
