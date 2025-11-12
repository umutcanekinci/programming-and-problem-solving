## Software Engineering — Course Materials & Assignments

This repository collects course materials, lab assignments, self-study work, exam solutions, and small projects completed during my university studies in software engineering and related programming courses. It is primarily organized by year and course, and contains sources in C, Java, C++ and text/notes.

Use this README as a map to quickly find material for a specific class or assignment.

---

## Repository layout (top-level)

Note: some folders may contain their own README files with course-specific instructions.

```
.
├── first-year/                        # First year course materials and labs
│   ├── programming-and-problem-solving-1/   # C-language course: labs, lectures, exams
│   └── programming-and-problem-solving-2/   # Follow-up course: Java labs, quizzes
├── second-year/                       # Second year courses (various)
│   ├── data-structers-and-algorithms/ # DSA labs and assignments (C++/C)
│   └── software-engineering-fundamentals/ # SE course materials
├── LICENSE                             # Project license
├── readme.md                           # This file (repository-level)
└── (other course folders)
```

Example notable folders
- `first-year/programming-and-problem-solving-1/` — C programs, labs, lecture notes, midterm/final solutions.
- `first-year/programming-and-problem-solving-2/` — Java labs and quizzes (look under `bin/` and `src/` subfolders).
- `second-year/data-structers-and-algorithms/` — implementations for queues, stacks, etc.

---

## Languages and tools used

- C (GCC / clang) — lots of `.c` and `.h` files in the first-year course folders.
- Java (javac / java) — quizzes and lab exercises under `programming-and-problem-solving-2/`.
- C++ — some data-structures/homework code under `second-year`.
- Plain text / Markdown — notes and READMEs.

This repository was prepared on Windows; examples use PowerShell-friendly commands where shown.

---

## Quick start — open and run a sample

1. Clone the repo (replace with your fork/SSH if needed):

```powershell
git clone https://github.com/umutcanekinci/software-engineering.git
cd software-engineering
```

2. Find a C example (e.g., in `first-year/programming-and-problem-solving-1/labs/`):

```powershell
# compile
gcc .\first-year\programming-and-problem-solving-1\labs\lab1.c -o lab1.exe
# run
.\lab1.exe
```

3. Compile and run a Java example (in PowerShell):

```powershell
cd .\first-year\programming-and-problem-solving-2\quiz-1\src
javac *.java
java UtilityCompany
```

Notes:
- Replace file names with the actual file you want to run. Some folders contain helper headers and multiple source files that must be compiled together.
- On Windows, use a MinGW/MSYS or WSL environment if you prefer Unix-like tooling.

---

## How the content is organized

- Each course usually has a folder per lab/assignment or per exam. Inside you’ll often find `src/` and `bin/` for Java labs, or C files and `README.md` describing the task.
- I kept original file names and created small subfolders for examples from previous years.

If you plan to re-run code, read the local `README.md` files in each folder for course-specific instructions.

---

## Contribution and use

This repository is a personal collection of course work and study material. You're welcome to consult or fork it for learning. If you reuse code in your own assignments, follow your institution's academic integrity rules.

If you want to suggest improvements or corrections, open an issue or a pull request.

---

## License

See `LICENSE` at the repository root for licensing details.

---

## Contact

Owner: GitHub user `umutcanekinci` (repository owner). If you need to reach out, please use GitHub issues or pull requests.

---

If you'd like, I can also:
- Add per-course README files where missing.
- Add a small script to compile a set of C examples at once.
- Generate a summary index file listing all `.c` and `.java` files with paths.

Tell me which of those you'd prefer and I'll prepare it.
