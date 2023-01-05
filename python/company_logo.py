from collections import Counter


if __name__ == "__main__":
    s = input()

    characters_list = list(s)
    characters_list.sort()

    c = Counter(characters_list)

    top = c.most_common(3)

    for element in top:
        print(*element)
