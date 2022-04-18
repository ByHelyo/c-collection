# c-collection

### Table of Contents

- [Description](#description)
- [Installation](#installation)
- [Getting Started](#getting-started)

## Description

A collection of common data structures.

## Installation

### Dependencies

- CMake (>= 3.22)
- Criterion (testing)

Build the project
```
cmake -S . -B build
cd build
```

## Getting Started

### Linked list

Build the library <strong>liblinkedlist.a</strong>
```
make linkedlist
```

Launch tests
```
make linkedlist-test
./linkedlist-test
```
