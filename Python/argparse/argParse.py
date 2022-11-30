#!/usr/bin/env python3

import argparse
import json
import os.path


myParser = argparse.ArgumentParser(
    description=(
        "Interact with a JSON; with no" " argument just verifies json file type.\n"
    )
)

myParser.add_argument(
    "-f", "--find", action="store", help="Displays all values of the requested key."
)

helpString = (
    "Prints True or False dependent on if the specific key"
    " is in the JSON.\n argParse.py -k key json.json"
)
myParser.add_argument("-k", "--key", action="store", help=helpString)

myParser.add_argument(
    "-i", "--iterate", action="store_true", help="Iterates over the entire json"
)

myParser.add_argument(
    "-t",
    "--traverse",
    nargs="*",
    help="This lets you traverse the json and get associated values",
)

myParser.add_argument(
    "-c",
    "--count",
    nargs="*",
    help="Traverse to a point in json, and count members at final point",
)

myParser.add_argument("jsonFile", type=str, help="The JSON file to open")

args = myParser.parse_args()


def iterateJson(jsonData):
    for iterable in jsonData:
        print(iterable, jsonData[iterable])


def keyJson(jsonData):
    if args.key in jsonData:
        return True
    else:
        return False


def findJson(jsonData):
    if args.find in jsonData:
        print(args.find, jsonData[args.find])
    else:
        print("The key is not in the json")


def traverseJson(jsonData):
    levels = len(args.traverse)
    currentHolder = jsonData
    counter = 0
    whileCatch = 0
    # print(levels)
    while counter < levels and whileCatch < 1000:
        # print(args.traverse[counter])
        if args.traverse[counter] in currentHolder:
            # print("if move")
            currentHolder = currentHolder[args.traverse[counter]]
            counter = counter + 1
        else:
            print("This appears to be as far as you can traverse")
            break
        whileCatch += 1
    print(currentHolder)


def countJson(jsonData):
    levels = len(args.count)
    currentHolder = jsonData
    counter = 0
    whileCatch = 0
    while counter < levels and whileCatch < 1000:
        if args.count[counter] in currentHolder:
            # print("if move")
            currentHolder = currentHolder[args.count[counter]]
            counter = counter + 1
        else:
            print("This appears to be as far as you can traverse")
            break
        whileCatch += 1
    print(len(currentHolder), " values in: ", args.count[counter - 1])


def main():
    if os.path.isfile(args.jsonFile) and args.jsonFile.endswith(".json"):
        # print('Good the file exists and appears to be a json')
        file = open(args.jsonFile)
        jsonData = json.load(file)
        file.close()
    else:
        print("The json doesn't seem to exist")
        return
    if args.iterate:
        iterateJson(jsonData)

    if args.key:
        print(keyJson(jsonData))

    if args.find:
        findJson(jsonData)

    if args.traverse:
        traverseJson(jsonData)

    if args.count:
        countJson(jsonData)
    # print(args.jsonFile)


if __name__ == "__main__":
    main()
