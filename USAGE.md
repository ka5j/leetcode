# Day-to-day usage

How to add problems and keep this repo up to date.

## Adding a new problem

1. **Scaffold the folder** from the repo root:

   ```bash
   python3 scripts/new_problem.py <number> "<Title>" <Easy|Medium|Hard> "<Topic 1, Topic 2>"
   # example
   python3 scripts/new_problem.py 49 "Group Anagrams" Medium "Array, Hash Table, String"
   ```

   This creates `problems/0049-group-anagrams/` with a write-up and an empty C++ file, both named after the problem: `group-anagrams.md` and `group-anagrams.cpp`.

2. **Paste your accepted C++ code** from LeetCode into the problem's `.cpp` file.

3. **Fill in the problem's `.md` write-up**:
   - Paste the problem statement under **Problem**.
   - Explain the idea in your own words under **Approach**.
   - Fill in **Complexity** (time and space).
   - Add anything useful under **Notes**: mistakes, alternative solutions, related problems.
   - Change `status: In Progress` to `status: Solved` in the front matter. Only solved problems appear in the README table, so unfinished folders can sit in `problems/` safely.

4. **Rebuild the root README table** (this also rebuilds `REVIEW.md`):

   ```bash
   python3 scripts/update_readme.py
   ```

5. **Commit and push**:

   ```bash
   git add .
   git commit -m "Add 0049 Group Anagrams"
   git push
   ```

## Keeping things accurate

- **The table is generated.** Never edit between the `PROBLEMS:START` and `PROBLEMS:END` markers in `README.md` by hand. Edit a problem's front matter (the block between the `---` lines at the top of its `.md` file) and rerun `update_readme.py`.
- **Topic names should be consistent** (always `Hash Table`, not sometimes `Hashmap`), since the topic counts group by exact text. Use LeetCode's own tag names.
- **Revisiting a problem?** Update its `.cpp` file and notes, and commit with a message like `Improve 0049: sort-free O(n*k) solution`.

## Flagging problems to revisit

If you solved a problem but struggled, flag it so it shows up in [`REVIEW.md`](REVIEW.md):

```yaml
review: true
review_reason: Returned the tail pointer and lost the final carry
```

Set these two lines in the front matter of the problem's `.md` file, then run `python3 scripts/update_readme.py`. `REVIEW.md` lists every flagged problem with links to your write-up and to LeetCode.

When you can re-solve it from scratch without help, set `review: false`, clear `review_reason`, rerun the script and commit with a message like `Review 0002: re-solved`.

## Pattern notes

When you notice a technique repeating (sliding window, two pointers, binary search on the answer, DP states), add or extend a file in `notes/`, for example `notes/sliding-window.md`. List the pattern, when to use it, a C++ skeleton, and links to the problems in this repo that use it.

## Commit conventions

- One commit per problem: `Add 0001 Two Sum`.
- Improvements to an existing solution: `Improve 0001: ...`.
- Pattern notes: `Notes: sliding window`.

Small, regular commits keep your GitHub contribution graph honest and make the history easy to read.

## Weekly check (2 minutes)

- Run `python3 scripts/update_readme.py` and confirm the counts look right.
- Skim recent problem write-ups for empty **Approach** or **Complexity** sections.
- Pick one or two problems from `REVIEW.md` and re-solve them from scratch.
- Make sure everything is pushed (`git status` should be clean).
