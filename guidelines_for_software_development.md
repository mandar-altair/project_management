# Software Development Guidelines

This document outlines the standard processes and best practices for software developers in our company. Following these guidelines ensures code quality, maintainability, and smooth collaboration within the team.

---

## 1. **Code Development Process**

### 1.1 **Adopt Test-Driven Development (TDD)**

- Write tests before implementing new features or bug fixes.
- Ensure all tests pass before submitting code for review.

**Example: Writing a test before the function**

```python
import pytest

def test_add():
    assert add(2, 3) == 5
```

**Then implement the function:**

```python
def add(a: int, b: int) -> int:
    return a + b
```

---

## 2. **Version Control with GitHub**

### 2.1 Sample Python Project Structure:**

```
my_python_project/
├── src/
│   └── my_package/
│       ├── __init__.py
│       └── module.py
├── tests/
│   └── test_module.py
├── requirements.txt
├── setup.py
├── README.md
└── .gitignore
```

**Sample C Project Structure:**

```
my_c_project/
├── src/
│   ├── main.c
│   └── utils.c
├── include/
│   └── utils.h
├── tests/
│   └── test_utils.c
├── Makefile
├── README.md
└── .gitignore
```

### 2.2 **Repository Usage**

- All code must be versioned using Git and published to the designated GitHub repository.
- No task is considered complete until the code is merged via a Pull Request (PR) and reviewed/approved.

### 2.3 **Branching Strategy**

- Create a new branch for each task/feature/bugfix.
- Use descriptive branch names, e.g. `feature/user-login`, `bugfix/fix-crash-on-startup`.

### 2.4 **Pull Requests**

- All code must be integrated via PRs—direct pushes to main/master are prohibited.
- PRs should be linked to related issues and include a clear description of changes.

**PR Description Example:**
```
## Summary
Implements user login feature.

## Changes
- Added authentication logic in `auth.py`
- Updated tests for login validation

## Related Issues
Closes #42
```

---

## 3. **Code Documentation**

### 3.1 **Inline Comments and Annotations**

- Use inline comments to explain complex logic or important decisions.
- Use specific keywords for special notes:
  - `BUG:` Known issues or problematic code.
  - `FIX:` Explanation of a fix.
  - `PERFORMANCE:` Notes on performance optimizations.
  - `HACK:` Temporary or non-ideal solutions.

**Example:**
```python
def process_data(data: list[int]) -> list[int]:
    # PERFORMANCE: Using list comprehension for speed
    return [x * 2 for x in data]

def risky_operation() -> None:
    try:
        result = do_something()
    except ValueError as e:
        # BUG: This fails if input is not an integer. Needs validation upstream.
        print(f"Error: {e}")
```

### 3.2 **Docstrings**

- Every function must have a docstring describing its purpose, parameters, return values, and exceptions.

**Example:**
```python
def divide(a: float, b: float) -> float:
    """
    Divide two numbers.

    Args:
        a (float): Dividend
        b (float): Divisor

    Returns:
        float: The result of division.

    Raises:
        ZeroDivisionError: If b is zero.

    Example:
        >>> divide(4, 2)
        2.0
    """
    if b == 0:
        raise ZeroDivisionError("Divisor cannot be zero.")
    return a / b
```

---

## 4. **Code Structure and Reusability**

### 4.1 **Functionality in Functions and Modules**

- All code should be contained within functions or classes.
- Code must be importable by other scripts/modules; avoid writing logic at the top-level.

**Example:**
```python
# my_module.py
def greet(name: str) -> str:
    return f"Hello, {name}!"

# main.py
from my_module import greet

if __name__ == "__main__":
    print(greet("Alice"))
```

### 4.2 **Type Annotations**

- All functions must use type annotations for parameters and return values.

**Example:**
```python
def multiply(a: int, b: int) -> int:
    return a * b
```

---

## 5. **Exception Handling**

- Catch and handle foreseeable exceptions.
- Avoid bare `except:` clauses; always specify exception types.
- Log or clearly communicate errors.

**Example:**
```python
def read_file(filepath: str) -> str:
    """
    Reads the contents of a file.

    Args:
        filepath (str): Path to the file.

    Returns:
        str: File contents.

    Raises:
        FileNotFoundError: If the file does not exist.
    """
    try:
        with open(filepath, 'r') as f:
            return f.read()
    except FileNotFoundError:
        # FIX: Added specific exception handling for missing files
        print(f"File not found: {filepath}")
        raise
```

---

## 6. **Code Examples and Usage**

- Provide usage examples for complex or public-facing functions.
- Prefer including usage in docstrings or as separate example scripts.

**Example:**
```python
def power(base: float, exponent: float) -> float:
    """
    Raises base to the given exponent.

    Args:
        base (float): The base number.
        exponent (float): The exponent.

    Returns:
        float: base ** exponent

    Example:
        >>> power(2, 3)
        8.0
    """
    return base ** exponent
```

---

## 7. **Checklist Before Submission**

- [ ] Tests written and passing (TDD followed)
- [ ] Code reviewed and merged via PR
- [ ] Inline comments with appropriate keywords
- [ ] All code contained in functions/classes
- [ ] Type annotations added
- [ ] Usage examples provided
- [ ] Exceptions handled where appropriate

---

For any questions on these guidelines, please consult your team lead or the engineering manager.

