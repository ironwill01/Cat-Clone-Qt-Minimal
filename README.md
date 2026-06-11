# Cat Clone (Qt Minimal)

A lightweight console application that mimics the behavior of the Linux `cat` command, built with **Qt6** and modern C++17. This project was created as a fun exercise to sharpen my Qt framework skills while exploring command-line argument parsing and file handling in a cross-platform way.

## Features

- **Basic file output** (just like `cat`)
- **Line numbering** (`-l` / `--line`)
- **Remove specific characters/strings** from output (`-c` / `--remove-char`)
- **Highlight specific words** in output (ANSI color, red) (`-w` / `--word-highlight`)
- Clean command-line interface using `QCommandLineParser`
- Proper file handling with Qt classes (`QFile`, `QTextStream`)

## Usage

```bash
# Basic usage
./App filename.txt

# Show line numbers
./App -l filename.txt
./App --line filename.txt

# Remove all occurrences of a character/string
./App -c " " filename.txt          # remove spaces
./App --remove-char "foo" filename.txt

# Highlight a word (in red)
./App -w "important" filename.txt
./App --word-highlight "TODO" filename.txt

# Combine options
./App -l -w "error" -c "#" logfile.txt
