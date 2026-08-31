# Custom atoi

My implementation of atoi() in C.

## Handles

- Leading whitespace
- + and - signs
- Decimal digits
- Stops at first non-digit
- Empty/malformed input

## Example

"   -123abc" → -123

## TODO

- Handle integer overflow
- Match libc atoi() edge cases exactly
