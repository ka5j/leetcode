---
number: 2
title: Add Two Numbers
slug: add-two-numbers
difficulty: Medium
topics: Linked List, Math, Recursion
status: Solved
date: 2026-10-20
---

# 2. Add Two Numbers

[LeetCode problem](https://leetcode.com/problems/add-two-numbers/) · [C++ solution](add-two-numbers.cpp)

## Problem

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

**Example 1:**

```
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
```

**Example 2:**

```
Input: l1 = [0], l2 = [0]
Output: [0]
```

**Example 3:**

```
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
```

**Constraints:**

- The number of nodes in each linked list is in the range [1, 100].
- 0 <= `Node.val` <= 9
- It is guaranteed that the list represents a number that does not have leading zeros.

## Approach

### 1. Convert to integers (rejected)

Convert each linked list into an integer, add the two integers, then convert the sum back into a linked list. This is inefficient. It also breaks on large inputs, because each list can have up to 100 digits, which overflows any built-in integer type.

### 2. Digit-by-digit addition (my solution)

The digits are stored in reverse order, so the lists already start at the least significant digit. This is the order you work in when doing long addition by hand, so the lists can be added node by node:

1. Walk both lists together. If one list is shorter, treat its missing digits as `0`.
2. At each step, sum the two current digits plus the carry from the previous step.
3. If the sum is greater than 9, subtract 10 from it and set the carry to `true`. Otherwise set the carry to `false`.
4. Append the resulting digit to a new linked list.
5. Keep going while either list has nodes left **or** a carry is still pending, so a final carry becomes an extra node.

The carry is tracked with a `bool`, which is enough because the carry from adding two digits and a carry is at most 1 (9 + 9 + 1 = 19).

## Complexity

Where n and m are the lengths of the two lists:

- Time: O(max(n, m))
- Space: O(max(n, m)) for the output list (O(1) extra beyond the output)

## Notes

Things that tripped me up:

- **Returning the wrong pointer.** I advanced my result pointer as I built the list, so I returned the last node instead of the head. The fix is to keep a separate pointer to the head and return that.
- **Leftover carry.** If both lists end while a carry is pending (for example `[5] + [5]`, which should give `[0,1]`), the loop must run once more to add the carry as a new node.
- **Copy-paste typo.** In the branch where both lists still had nodes, I read both values from `l2` instead of one from each list. Reading the examples by hand caught it.

Possible simplification: using a placeholder head node before the real list avoids special-casing the first node, and a single loop condition (`l1 || l2 || carry`) replaces the separate branches for each list ending.
