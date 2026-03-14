# Integer Queue ADO

A fixed-capacity integer queue implemented as an **Abstract Data Object** (ADO) — a single global instance using a static internal struct.

The underlying representation is a non-circular static array: `front` advances on dequeue but never wraps around, so the effective capacity shrinks as items are removed.

## Files

| File | Purpose |
|------|---------|
| `IntQueue.h` | Interface: `QueueInit`, `QueueIsEmpty`, `QueueEnqueue`, `QueueDequeue` |
| `IntQueue.c` | Implementation |
| `IntQueueTester.c` | Interactive tester — reads n integers and dequeues them in FIFO order |

## Compile & Run

```bash
gcc -Wall -Werror -std=c11 -O0 -g -o int_queue IntQueueTester.c IntQueue.c
./int_queue
```
