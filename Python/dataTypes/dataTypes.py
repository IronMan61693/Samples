#!/usr/bin/env python3


def demonstrateValues(iterable):
    print(type(iterable))
    if type(iterable) == dict:
        for key in iterable:
            print(key, " <- key ", iterable[key], "<- value")
    else:
        for value in iterable:
            print(value)

    print("This ends")


def main():
    intExm = 0  # This is only precise to no decimal points
    floatExm = 0.0  # This is much more precise
    strExm = "This is a series of characters making a string."
    listExm = [intExm, floatExm, strExm]
    list2Exm = [strExm, floatExm, intExm]
    multLstExm = [listExm, list2Exm]
    dicExm = {
        "key1": intExm,
        "key2": floatExm,
        "key3": strExm,
        "key4": listExm,
        "key5": multLstExm,
    }
    # Values can be any data type, keys must be immutable data types, here I used string
    tupExm = (
        intExm,
        floatExm,
        strExm,
    )  # Tuples are immutable but the values do not need be the same
    singExm = tupExm  # A singleton is a tuple of exactly one value, but the value can be complex

    demonstrateValues(listExm)  # Note the order
    demonstrateValues(list2Exm)  # Note the order is reversed, Lists are ordered
    demonstrateValues(multLstExm)
    demonstrateValues(dicExm)
    demonstrateValues(tupExm)
    demonstrateValues(singExm)


if __name__ == "__main__":
    main()
