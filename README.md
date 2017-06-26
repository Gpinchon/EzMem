# EzMem
A simple implementation of array and string types fairly similar to JS, mainly used to learn about bitwise operators, could be useful.
# PERFORMANCE UPDATE
Added resize/reserve functions and used them for push/pop/shift/unshift.
Allowing for very fast push when memory has been reserved. (15ms to push 1.000.000 elements with reserve vs 675ms without reserve)
