#!/usr/bin/env python3
"""Create a problem folder with <slug>.md (from the template) and an empty <slug>.cpp.

Usage: python3 scripts/new_problem.py 1 "Two Sum" Easy "Array, Hash Table"
"""
import re
import sys
from datetime import date
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent


def main():
    if len(sys.argv) != 5:
        sys.exit(__doc__)
    number, title, difficulty, topics = sys.argv[1:]
    slug = re.sub(r"[^a-z0-9]+", "-", title.lower()).strip("-")
    folder = ROOT / "problems" / f"{int(number):04d}-{slug}"
    if folder.exists():
        sys.exit(f"{folder} already exists")
    folder.mkdir(parents=True)

    readme = (ROOT / "templates" / "problem_README.md").read_text()
    for old, new in {
        "number: 0": f"number: {int(number)}",
        "title: Problem Title": f"title: {title}",
        "slug: problem-slug": f"slug: {slug}",
        "difficulty: Easy": f"difficulty: {difficulty}",
        "topics: Array, Hash Table": f"topics: {topics}",
        "date: YYYY-MM-DD": f"date: {date.today().isoformat()}",
        "problem-slug/)": f"{slug}/)",
        "problem-slug.cpp": f"{slug}.cpp",
        "{number}": number,
        "{title}": title,
    }.items():
        readme = readme.replace(old, new)
    (folder / f"{slug}.md").write_text(readme)
    (folder / f"{slug}.cpp").touch()
    print(f"Created {folder.relative_to(ROOT)}")


if __name__ == "__main__":
    main()
