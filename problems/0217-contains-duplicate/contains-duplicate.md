---
number: 217
title: Contains Duplicate
slug: contains-duplicate
difficulty: Easy
topics: Array, Hash Table, Sorting
status: Solved
date: 2026-10-22
---

# 217. Contains Duplicate

[LeetCode problem](https://leetcode.com/problems/contains-duplicate/) · [C++ solution](contains-duplicate.cpp)

## Problem

Given an integer array `nums`, return `true` if any value appears **at least twice** in the array, and return `false` if every element is distinct.

**Example 1:**

```
Input: nums = [1,2,3,1]
Output: true
```

**Example 2:**

```
Input: nums = [1,2,3,4]
Output: false
```

**Example 3:**

```
Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
```

**Constraints:**

- 1 <= `nums.length` <= 10<sup>5</sup>
- -10<sup>9</sup> <= `nums[i]` <= 10<sup>9</sup>

## Approach

### 1. Brute force

Compare every pair of elements and return `true` if any two are equal.

- Time: O(n<sup>2</sup>)
- Space: O(1)

### 2. Sort and compare neighbors

Sort the array with `std::sort`. Any duplicates end up next to each other, so scan once and return `true` if two adjacent elements are equal.

- Time: O(n log n) for the sort, plus O(n) for the scan, which simplifies to O(n log n)
- Space: O(1) extra (O(log n) for the sort's stack), but it reorders the input array

### 3. Hash map (my solution)

Walk through the array, counting how many times each value has been seen in a hash map. As soon as a value's count reaches 2, return `true`. If the loop finishes, every element is distinct, so return `false`.

- Time: O(n), with an early exit as soon as a repeat is found
- Space: O(n)

## Complexity

My solution (approach 3):

- Time: O(n)
- Space: O(n)

## Notes

- **Time vs space trade-off.** Approach 1 uses the least memory but is the slowest. Approach 3 is fastest, at the cost of O(n) memory. Approach 2 sits in between. Since every solution has to look at each element in the worst case, O(n) time is the best possible, and approach 3 reaches it.
- **Hash set instead of a map.** The counts are never used beyond checking for a second occurrence, so an `unordered_set` would work the same way. Its `insert` reports whether the value was already present, which needs one lookup per element instead of two. It is the same complexity with less overhead.
- **Early exit.** The hash approach can stop at the first repeat. Sorting always pays for the full sort first.
- **Input is modified.** Sorting reorders the caller's array, so approach 2 would need a copy to avoid that, which costs O(n) space again.
- Related: [Two Sum](../0001-two-sum/two-sum.md) uses the same idea of trading space for time with a hash map.
