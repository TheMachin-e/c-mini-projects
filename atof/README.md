# Custom atof

My implementation of atof() in C.

## Handles

- Leading whitespace
- \+ and - signs
- Integer part
- Fractional part
- Scientific notation
- Positive/negative exponent

## Example

" -123.45e-2" → -1.2345

## TODO

- Improve malformed exponent handling
- Handle overflow/underflow
- Match libc behavior more closely
