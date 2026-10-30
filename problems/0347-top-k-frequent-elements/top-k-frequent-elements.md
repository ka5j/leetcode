---
number: 347
title: Top K Frequent Elements
slug: top-k-frequent-elements
difficulty: Medium
topics: Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
status: Solved
date: 2026-10-29
review: true
review_reason: First approach sorts by frequency (O(n log n)); re-solve to meet the better-than-O(n log n) follow-up
---

# 347. Top K Frequent Elements

[LeetCode problem](https://leetcode.com/problems/top-k-frequent-elements/) · [C++ solution](top-k-frequent-elements.cpp)

## Problem

Given an integer array `nums` and an integer `k`, return the `k` most frequent elements. You may return the answer in **any order**.

**Example 1:**

```
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
```

**Example 2:**

```
Input: nums = [1], k = 1
Output: [1]
```

**Example 3:**

```
Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2
Output: [1,2]
```

**Constraints:**

- 1 <= `nums.length` <= 10<sup>5</sup>
- -10<sup>4</sup> <= `nums[i]` <= 10<sup>4</sup>
- `k` is in the range `[1, the number of unique elements in the array]`.
- It is **guaranteed** that the answer is **unique**.

**Follow-up:** Your algorithm's time complexity must be better than O(n log n), where n is the array's size.

## Approach

### 1. Count, then sort by frequency (my solution)

1. Count how many times each number appears with an `unordered_map<int, int>`.
2. Copy the map's (number, count) pairs into a `vector<pair<int, int>>`.
3. Sort the vector by count, highest first, using a custom comparator (`a.second > b.second`).
4. Return the numbers from the first `k` pairs.

- Time: O(n + u log u), where u is the number of unique values. In the worst case every value is unique, which makes it O(n log n).
- Space: O(u)

### To revisit: meeting the follow-up

Not solved yet. Hints for the re-solve:

- Only the top `k` are needed, not a full ranking. Is there a structure that keeps just the best `k` seen so far, more cheaply than sorting everything?
- What's the largest frequency any element can possibly have? If frequencies fall in a small known range, could elements be grouped by frequency without comparing them?

## Complexity

My solution (approach 1):

- Time: O(n log n) in the worst case
- Space: O(u)

## Notes

- **My first version ignored `k`.** The result loop ran `vec.size() - 1` times, which passed all three examples by coincidence (each had exactly `k + 1` unique numbers) but failed inputs like `[1,1], k = 1`. The loop has to stop after the first `k` sorted pairs.
- **The follow-up isn't met yet.** Sorting all unique values is O(n log n) in the worst case, which the follow-up rules out. Flagged to re-solve with a faster approach.
- **Smaller cleanups:** the `nums.size() == 1` special case isn't needed, a static comparator can be passed as plain `compareCounts`, and taking the pairs as `const pair<int, int>&` avoids copies.
- Related: [Valid Anagram](../0242-valid-anagram/valid-anagram.md) and [Group Anagrams](../0049-group-anagrams/group-anagrams.md) also start by counting with a hash map.
