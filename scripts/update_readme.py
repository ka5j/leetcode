#!/usr/bin/env python3
"""Rebuild the progress summary and problem table in the root README from problem front matter."""
import re
from collections import Counter
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
README = ROOT / "README.md"
START, END = "<!-- PROBLEMS:START -->", "<!-- PROBLEMS:END -->"


def parse(path):
    match = re.match(r"---\n(.*?)\n---", path.read_text(), re.S)
    if not match:
        return None
    meta = dict(
        line.split(":", 1) for line in match.group(1).splitlines() if ":" in line
    )
    return {k.strip(): v.strip() for k, v in meta.items()}


def main():
    problems = []
    for readme in (ROOT / "problems").glob("*/*.md"):
        meta = parse(readme)
        if meta:
            meta["folder"] = readme.parent.name
            problems.append(meta)
    problems.sort(key=lambda m: int(m["number"]))

    difficulty = Counter(m["difficulty"] for m in problems)
    topics = Counter(t.strip() for m in problems for t in m["topics"].split(","))

    rows = [
        f"| {m['number']} | [{m['title']}](problems/{m['folder']}/{m['slug']}.md) "
        f"| {m['difficulty']} | {m['topics']} "
        f"| [C++](problems/{m['folder']}/{m['slug']}.cpp) | {m['date']} |"
        for m in problems
    ]
    topic_line = " · ".join(f"{t} ({n})" for t, n in topics.most_common())

    parts = [
        "| Solved | Easy | Medium | Hard |",
        "|:------:|:----:|:------:|:----:|",
        f"| **{len(problems)}** | {difficulty['Easy']} | {difficulty['Medium']} | {difficulty['Hard']} |",
        "",
    ]
    if topic_line:
        parts += [f"**Topics:** {topic_line}", ""]
    parts += [
        "| # | Problem | Difficulty | Topics | Solution | Solved |",
        "|--:|---------|------------|--------|----------|--------|",
        *rows,
    ]

    block = f"{START}\n" + "\n".join(parts) + f"\n{END}"
    text = re.sub(f"{START}.*?{END}", lambda _: block, README.read_text(), flags=re.S)
    README.write_text(text)
    print(f"Updated README with {len(problems)} problems")


if __name__ == "__main__":
    main()
