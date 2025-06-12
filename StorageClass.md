---

### 📌 1. `auto` (Automatic Storage Class)

| Feature            | Description                                                               |
| ------------------ | ------------------------------------------------------------------------- |
| **Default for**    | Local variables inside functions                                          |
| **Scope**          | Block (local)                                                             |
| **Lifetime**       | Till the function/block ends                                              |
| **Initialization** | Garbage value if not initialized                                          |
| **Use**            | Rarely used explicitly, because all local variables are `auto` by default |

✅ **Example**:

```c
void func() {
    auto int x = 10;  // same as int x = 10;
}
```

---

### 📌 2. `register` (Register Storage Class)

| Feature       | Description                                              |
| ------------- | -------------------------------------------------------- |
| **Stored in** | CPU register (if available) for faster access            |
| **Scope**     | Local (block)                                            |
| **Lifetime**  | Till the function/block ends                             |
| **Use**       | For performance-critical variables (e.g., loop counters) |
| **Note**      | Cannot get its address using `&` operator                |

✅ **Example**:

```c
void func() {
    register int i;
    for(i = 0; i < 10; i++) {
        // Fast access loop
    }
}
```

---

### 📌 3. `static` (Static Storage Class)

| Feature   | Description |
| --------- | ----------- |
| **Scope** |             |

* Inside function: local to the function
* Outside function: file-level |
  \| **Lifetime** | Entire program (retains value between calls) |
  \| **Use** | Preserve variable state in function, limit visibility of global variables/functions |
  \| **Linkage** | Internal (when used outside a function) |

✅ **Example 1**: Inside function (preserve value)

```c
void counter() {
    static int count = 0;
    count++;
    printf("%d ", count);
}
```

✅ **Example 2**: Outside function (limit access)

```c
static int hiddenGlobal = 10;  // Visible only in this file
```

---

### 📌 4. `extern` (External Storage Class)

| Feature      | Description                                      |
| ------------ | ------------------------------------------------ |
| **Scope**    | Global (across files)                            |
| **Lifetime** | Entire program                                   |
| **Use**      | Declare global variables defined in another file |
| **Linkage**  | External                                         |

✅ **Example**:

**File1.c:**

```c
int x = 100;
```

**File2.c:**

```c
extern int x;
printf("%d", x);  // Uses x from File1.c
```

---

### 🔁 Summary Table

| Keyword    | Scope                 | Lifetime         | Storage                    | Purpose/Use                              |
| ---------- | --------------------- | ---------------- | -------------------------- | ---------------------------------------- |
| `auto`     | Local block           | Until block ends | RAM                        | Default for local variables              |
| `register` | Local block           | Until block ends | CPU register (if possible) | Fast access                              |
| `static`   | Local or File         | Entire program   | RAM                        | Persist state or limit scope             |
| `extern`   | Global (across files) | Entire program   | RAM                        | Access global variable from another file |

---

