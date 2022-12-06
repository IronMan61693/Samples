#!/usr/bin/env python3


def mathFunc(x, y, z):
    # 8 + 4 // 4 - 6 % 4 * 4 == 8 + 1 - 2 * 4 == 8 + 1 - 8 == 1 with correct
    # P E MD AS
    # Technically python just groups as opposed to actually evaluating with correct order
    # That is we would get z // z -> y % z -> x + result z //z -> (y%z) result * z
    # then the subtraction. This still gives the proper value however.
    return x + z // z - y % z * z


def badFunc(x, y, z):
    # The same function as above but forcing left to right with ()
    # 8 + 4 // 4 - 6 % 4 * 4 == 12 // 4 - 6 % 4 * 4 == 3 - 6 % 4 * 4 == -3%4 * 4
    # 1 * 4 == 4
    return ((((x + z) // z) - y) % z) * z


print(mathFunc(8, 6, 4))
print(badFunc(8, 6, 4))
y = 1.0
x = int(y)
print(type(x))
