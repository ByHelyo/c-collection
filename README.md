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

### Building

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
```

### Stack

Build the library <strong>libstack.a</strong>

```
make stack
```

> Note this stack version is using linked list implementation

Launch tests
```
make stack-test
```

### Simple Queue

Build the library <strong>libsimple-queue.a</strong>

```
make simple-queue
```

> Note this simple queue version is using linked list implementation

Launch tests
```
make simple-queue-test
```
