#!/usr/bin/env python3
"""Record a solve for a problem, then rebuild README.md and REVIEW.md.

A first solve marks the problem Solved with today's date and solves: 1.
Solving it again adds 1 to solves and sets last_solved to today.

Usage: python3 scripts/solved.py <number> [--review "reason"] [--clear-review]

  python3 scripts/solved.py 49
  python3 scripts/solved.py 49 --review "Missed the empty-string case"
  python3 scripts/solved.py 49 --clear-review
"""
import re
import sys
from datetime import date
from pathlib import Path

import update_readme

ROOT = Path(__file__).resolve().parent.parent


def set_field(fields, key, value, after):
    """Replace `key: ...` in the front matter lines, or insert it after `after`."""
    line = f"{key}: {value}".rstrip()
    keys = [f.split(":", 1)[0].strip() for f in fields]
    if key in keys:
        fields[keys.index(key)] = line
    elif after in keys:
        fields.insert(keys.index(after) + 1, line)
    else:
        fields.append(line)


def parse_args(args):
    if not args or not args[0].isdigit():
        sys.exit(__doc__)
    number, review, clear = int(args[0]), None, False
    rest = args[1:]
    while rest:
        if rest[0] == "--review" and len(rest) > 1:
            review, rest = rest[1], rest[2:]
        elif rest[0] == "--clear-review":
            clear, rest = True, rest[1:]
        else:
            sys.exit(__doc__)
    if review is not None and clear:
        sys.exit("Use --review or --clear-review, not both")
    return number, review, clear


def main():
    number, review, clear = parse_args(sys.argv[1:])

    folders = list((ROOT / "problems").glob(f"{number:04d}-*"))
    if len(folders) != 1:
        sys.exit(f"No problem folder for {number} in problems/")
    writeups = list(folders[0].glob("*.md"))
    if len(writeups) != 1:
        sys.exit(f"Expected one .md write-up in {folders[0].relative_to(ROOT)}")
    path = writeups[0]

    text = path.read_text()
    match = re.match(r"---\n(.*?)\n---\n", text, re.S)
    if not match:
        sys.exit(f"{path.relative_to(ROOT)} has no front matter")
    fields = match.group(1).split("\n")
    meta = {f.split(":", 1)[0].strip(): f.split(":", 1)[1].strip() for f in fields if ":" in f}
    for key in ("status", "date"):
        if key not in meta:
            sys.exit(f"{path.relative_to(ROOT)} front matter has no '{key}:' line")

    today = date.today().isoformat()
    if meta["status"] == "Solved":
        solves = int(meta.get("solves") or 1) + 1
        set_field(fields, "solves", solves, after="date")
        set_field(fields, "last_solved", today, after="solves")
        summary = f"solve #{solves}"
    else:
        solves = 1
        set_field(fields, "status", "Solved", after="topics")
        set_field(fields, "date", today, after="status")
        set_field(fields, "solves", solves, after="date")
        summary = "first solve"

    if review is not None:
        set_field(fields, "review", "true", after="solves")
        set_field(fields, "review_reason", review, after="review")
        summary += ", flagged for review"
    elif clear:
        set_field(fields, "review", "false", after="solves")
        set_field(fields, "review_reason", "", after="review")
        summary += ", review flag cleared"

    path.write_text("---\n" + "\n".join(fields) + "\n---\n" + text[match.end():])
    print(f"{path.relative_to(ROOT)}: {summary}")
    update_readme.main()


if __name__ == "__main__":
    main()
