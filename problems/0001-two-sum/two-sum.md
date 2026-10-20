---
number: 1
title: Two Sum
slug: two-sum
difficulty: Easy
topics: Array, Hash Table
status: Solved
date: 2026-10-20
---

# 1. Two Sum

[LeetCode problem](https://leetcode.com/problems/two-sum/) · [C++ solution](two-sum.cpp)

## Problem

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example 1:**

```
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: nums[0] + nums[1] == 9, so we return [0, 1].
```

**Example 2:**

```
Input: nums = [3,2,4], target = 6
Output: [1,2]
Explanation: nums[1] + nums[2] == 6, so we return [1, 2].
```

**Example 3:**

```
Input: nums = [3,3], target = 6
Output: [0,1]
Explanation: nums[0] + nums[1] == 6, so we return [0, 1].
```

**Constraints:**

- 2 <= `nums.length` <= 10<sup>4</sup>
- -10<sup>9</sup> <= `nums[i]` <= 10<sup>9</sup>
- -10<sup>9</sup> <= `target` <= 10<sup>9</sup>
- Only one valid answer exists.

**Follow-up:** Can you come up with an algorithm that runs in less than O(n<sup>2</sup>) time?

## Approach

### 1. Brute force

Check every combination of two different indices and see whether their values sum to `target`.

- Time: O(n<sup>2</sup>)
- Space: O(1)

### 2. Two-pass hash map (my solution)

1. First loop: store every element of `nums` in a hash map, mapping each value to its index.
2. Second loop: for each element, compute `need = target - nums[i]`.
3. Look up `need` in the hash map. If it exists and its index is not the current index `i`, the pair is found, so return both indices.

The index check matters because the same element cannot be used twice.

- Time: O(n)
- Space: O(n)

### 3. One-pass hash map

Combine both loops into one. For each element, check whether `need` is already in the hash map, then insert the current element. This does the same work as approach 2 with a single loop.

- Time: O(n)
- Space: O(n)

## Complexity

My solution (approach 2):

- Time: O(n)
- Space: O(n)

## Notes

- Hashing trades O(n) extra space for the O(n) time, down from O(n<sup>2</sup>) for brute force, which answers the follow-up.
- The one-pass version is the same idea with one fewer loop.
