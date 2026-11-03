---
number: 238
title: Product of Array Except Self
slug: product-of-array-except-self
difficulty: Medium
topics: Array, Prefix Sum
status: Solved
date: 2026-11-02
review: true
review_reason: New technique (prefix and suffix products); lining up the suffix array and handling the ends; O(1) space follow-up not solved yet
---

# 238. Product of Array Except Self

[LeetCode problem](https://leetcode.com/problems/product-of-array-except-self/) · [C++ solution](product-of-array-except-self.cpp)

## Problem

Given an integer array `nums`, return an array `answer` such that `answer[i]` is equal to the product of all the elements of `nums` except `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**Example 2:**

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

**Constraints:**

- 2 <= `nums.length` <= 10<sup>5</sup>
- -30 <= `nums[i]` <= 30
- The input is generated such that `answer[i]` is **guaranteed** to fit in a **32-bit** integer.

**Follow-up:** Can you solve the problem in O(1) extra space complexity? (The output array does not count as extra space for space complexity analysis.)

## Approach

### 1. Brute force

For each index, multiply every other element. This is correct but misses the O(n) requirement.

- Time: O(n<sup>2</sup>)
- Space: O(1) extra

### 2. Prefix and suffix product arrays (my solution)

Every answer splits into two parts:

```
answer[i] = (product of everything before i) × (product of everything after i)
```

1. Build `prefix`, where `prefix[i]` is the product of `nums[0]` through `nums[i]`.
2. Build `suffix`, where `suffix[i]` is the product of `nums[i]` through the last element.
3. Combine them with `answer[i] = prefix[i - 1] * suffix[i + 1]`, skipping `nums[i]` itself.
4. At the two ends there's nothing on one side, so that part is 1, which leaves the product unchanged.

For `nums = [1,2,3,4]`, `prefix = [1,2,6,24]` and `suffix = [24,24,12,4]`, so `answer[2] = prefix[1] * suffix[3] = 2 * 4 = 8`.

- Time: O(n)
- Space: O(n) extra for the two arrays

### To revisit: the O(1) space follow-up

Not solved yet. Hints for the re-solve:

- The output array doesn't count as extra space. Could it hold some of the work the separate arrays do now?
- When walking across the array, how much of the running product do you actually need to remember at any moment?

## Complexity

My solution (approach 2):

- Time: O(n)
- Space: O(n) extra

## Notes

- **New technique.** I hadn't used prefix arrays before. A prefix array stores a running result, so it's computed once in one pass and reused rather than recomputed for every index. The usual range-sum version removes a part by subtracting. This problem bans division, the equivalent for products, so the answer is built from the two sides instead.
- **Line the arrays up.** I first built `suffix` by appending from the back, so `suffix[k]` and `prefix[k]` described different positions in `nums`. Filling it backward from the last index means both arrays use the same indices as `nums`.
- **Each entry includes its own element.** `prefix[i]` and `suffix[i]` both contain `nums[i]`, so the answer has to use the neighboring entries, `i - 1` and `i + 1`.
- **Handling the ends.** My first check for "nothing after this element" fired one step too early and replaced a valid suffix value with 1, so `[1,2,3,4]` gave `2` instead of `8` at index 2. Example 2 still passed, because a zero hid the mistake, so one passing example doesn't prove the logic.
- **Possible cleanups.** Handling the last index correctly means the `nums.size() == 2` special case is no longer needed. `prefixTrack` and `suffixTrack` are always `i - 1` and `i + 1`, so `i` can replace them.
