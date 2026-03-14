# Running C Code in DSA-in-C

A reference for compiling, running, and checking C programs for memory errors.

---

## Prerequisites

You need a C compiler (`gcc`) and optionally Valgrind for memory checking. See the [Windows Setup](#windows-setup) section below.

---

## Compiling

Use `gcc` from the terminal. The standard flags used throughout this project:

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o <output_name> <source_file.c>
```

| Flag | Meaning |
|------|---------|
| `-Wall` | Enable (almost) all compiler warnings |
| `-Werror` | Treat all warnings as errors (forces clean code) |
| `-std=c11` | Compile to the C11 standard |
| `-O0` | Disable optimisations (better for debugging) |
| `-g` | Include debug info (required for Valgrind / AddressSanitizer) |
| `-o <name>` | Set the output executable name |

### Single-file example

```bash
cd exercises/c-fundamentals
gcc -Wall -Werror -std=c11 -O0 -g -o memerrors memerrors.c
./memerrors
```

### Multi-file example

Some exercises have separate `.h` / `.c` files. List all `.c` files:

```bash
cd exercises/int-queue
gcc -Wall -Werror -std=c11 -O0 -g -o IntQueueTester IntQueue.c IntQueueTester.c
./IntQueueTester
```

---

## Checking for Memory Leaks

### Option 1: Valgrind (Linux / WSL — recommended)

Run the compiled program under Valgrind:

```bash
valgrind -s --leak-check=full --show-leak-kinds=all ./your_program
```

Example of clean output (no leaks):

```
==349759== HEAP SUMMARY:
==349759==     in use at exit: 0 bytes in 0 blocks
==349759==  total heap usage: 9 allocs, 9 frees, 4,160 bytes allocated
==349759==
==349759== All heap blocks were freed -- no leaks are possible
==349759==
==349759== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```

The goal is always:
- `in use at exit: 0 bytes in 0 blocks`
- `ERROR SUMMARY: 0 errors`

Valgrind catches: memory leaks, buffer overflows, dangling pointers, double frees, uninitialised reads, and more.

### Option 2: AddressSanitizer (Windows / no Valgrind)

AddressSanitizer is built into gcc and requires no extra installation:

```bash
gcc -Wall -Werror -std=c11 -O0 -g -fsanitize=address -o your_program your_program.c
./your_program
```

It reports errors at runtime and catches similar issues to Valgrind, including buffer overflows and use-after-free errors.

---

## Editor: VS Code

VS Code works well for this project. Open a folder directly from the **Ubuntu (WSL) terminal**:

```bash
code .
```

Running `code .` from the Ubuntu terminal opens VS Code in WSL mode — you'll see a green `><` badge in the bottom-left corner saying "WSL: Ubuntu". This means the integrated terminal (`Terminal > New Terminal`) will be a WSL bash shell, so `gcc` and `valgrind` work directly inside VS Code without switching windows.

> If you run `code .` from a Windows terminal instead, VS Code opens in Windows mode and the integrated terminal won't have access to WSL tools.

Alternatively, if VS Code is already open, click the `><` badge bottom-left, select **Connect to WSL**, then open the folder via `Ctrl+K Ctrl+O`. When browsing, navigate using the WSL path to your Windows files — type `/mnt/c/` to reach the C drive, e.g. `/mnt/c/users/enqui/source/repos/learning/DSA-in-C`.

Useful extensions:
- **WSL** (by Microsoft) — required for WSL integration; enables the green `><` WSL: Ubuntu badge
- **C/C++** (by Microsoft) — syntax highlighting, IntelliSense, debugging
- **C/C++ Extension Pack** (by Microsoft) — includes the above plus extras

---

## Windows Setup

### Option 1: Cygwin

[Cygwin](https://www.cygwin.com/) provides a Unix-like bash shell and gcc on Windows. During installation, select the `gcc-core` and `make` packages.

Once installed, use the Cygwin terminal to compile and run code as shown above. Note that Valgrind is not available on Cygwin — use AddressSanitizer instead (see above).

### Option 2: WSL2 (recommended for Valgrind)

WSL2 (Windows Subsystem for Linux) gives a full Linux environment on Windows, which supports Valgrind.

1. Open PowerShell as Administrator and run:
   ```powershell
   wsl --install
   ```
   This installs WSL2 with Ubuntu by default. Restart when prompted.

2. Once Ubuntu is set up, open the Ubuntu terminal and install the tools:
   ```bash
   sudo apt update
   sudo apt install gcc valgrind
   ```

3. Navigate to your code (Windows drives are mounted at `/mnt/c/`):
   ```bash
   cd /mnt/c/path/to/DSA-in-C/exercises/c-fundamentals
   gcc -Wall -Werror -std=c11 -O0 -g -o memerrors memerrors.c
   ./memerrors
   valgrind -s --leak-check=full --show-leak-kinds=all ./memerrors
   ```

---

## Common Memory Errors

These are the types of errors Valgrind and AddressSanitizer will catch:

| Error | Description |
|-------|-------------|
| **memory leak** | `malloc`'d memory never `free`'d |
| **buffer overflow** | Writing past the end of an array |
| **dangling pointer** | Using a pointer after the memory it points to has been `free`'d |
| **double free** | Calling `free` on the same pointer twice |
| **invalid free** | Calling `free` on a pointer that wasn't `malloc`'d |
| **uninitialised read** | Reading a variable before assigning it a value |
| **no memory allocated** | Dereferencing a NULL or uninitialised pointer |
| **unchecked malloc** | Not checking if `malloc` returned NULL before using the pointer |
