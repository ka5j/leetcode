---
number: 128
title: Longest Consecutive Sequence
slug: longest-consecutive-sequence
difficulty: Medium
topics: Array, Hash Table, Union Find
status: Solved
date: 2026-11-05
solves: 1
review: true
review_reason: Needed help to reach O(n): only start walks at the start of a sequence, and avoid repeating walks for duplicates
---

# 128. Longest Consecutive Sequence

[LeetCode problem](https://leetcode.com/problems/longest-consecutive-sequence/) · [C++ solution](longest-consecutive-sequence.cpp)

## Problem

Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.

**Example 1:**

```
Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
```

**Example 2:**

```
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9
```

**Example 3:**

```
Input: nums = [1,0,1,2]
Output: 3
```

**Constraints:**

- 0 <= `nums.length` <= 10<sup>5</sup>
- -10<sup>9</sup> <= `nums[i]` <= 10<sup>9</sup>

## Approach

### 1. Sort, then scan (first idea, too slow)

Sort the array, then walk through it and count how long each run of values that go up by exactly 1 lasts. This works, but the sort alone costs O(n log n), which misses the O(n) requirement. Duplicates also need care: `[1,0,1,2]` sorts to `[0,1,1,2]`, and the repeated `1` must not end the run.

- Time: O(n log n)
- Space: O(1) extra with an in-place sort

### 2. Walk forward from every number (correct, but O(n<sup>2</sup>))

Put every number in a hash structure so "is `x + 1` present?" is an O(1) check. Then, from each number, keep stepping to the next value while it's present, and track the longest walk.

Every walk after the first repeats work. For `[1,2,3,4,5]`, the walks from 1, 2, 3 and 4 cover 4 + 3 + 2 + 1 steps, so one long run of n values costs about n<sup>2</sup>/2 steps.

- Time: O(n<sup>2</sup>) in the worst case
- Space: O(n)

### 3. Hash set, walk only from the start of each sequence (my solution)

1. Put every number in an `unordered_set<int>`.
2. Loop over the **set**, not the input array.
3. A number starts a sequence only if `num - 1` is not in the set. For those numbers alone, walk forward while `num + 1` is present and count the length.
4. Return the longest length found.

For `[100,4,200,1,3,2]`, only 1, 100 and 200 start walks. 2, 3 and 4 are skipped, because the walk from 1 already counts them.

Each sequence is walked once, from its start, so every number is stepped through at most twice: once when the loop checks whether it's a start, and once during its sequence's walk.

- Time: O(n)
- Space: O(n) for the set

### 4. Union-find (alternative)

Treat each number as an item, and for every `x` with `x + 1` also present, merge their groups. Each group ends up as one consecutive sequence, so the answer is the size of the largest group. It's nearly O(n), but it needs a separate union-find structure, so the hash set version is simpler.

## Complexity

My solution (approach 3):

- Time: O(n)
- Space: O(n)

## Notes

- **The start check is what makes it O(n).** Skipping a number whose predecessor is present is safe: that number belongs to a longer sequence that starts earlier, and the walk from that start will count it. Walking from it again could only give a shorter length.
- **Both fixes are needed.** My first version with the start check looped over `nums` and hit the time limit. With many copies of a sequence's first number (for example `1..50,000` plus 50,000 extra 1s), every copy passes the check and repeats the same long walk, which is O(n<sup>2</sup>) again. Looping over the set considers each distinct number once. When I switched to the set, I also lost the start check for a moment, which brought back the O(n<sup>2</sup>) walks from every number.
- **Set, not map.** Only presence matters here, so a set is enough. My earlier version mapped each value to an index and then read the value back, which was always just `target + 1`.
- **Possible cleanups.** Starting `longestSeq` at 0 would handle the empty input without the special case, and the loop condition can check `set.contains(target + 1)` directly instead of using a flag.
- Related: [Contains Duplicate](../0217-contains-duplicate/contains-duplicate.md) uses the same hash set presence check.
