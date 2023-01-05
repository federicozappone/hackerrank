import itertools


K, M = tuple(map(int, input().split()))

lists = []

for i in range(K):
    lists.append(list(map(int, input().split()[1:])))


def f(x):
    return x**2


def S(*numbers):
    return sum(f(x) for x in numbers) % M


print(max(itertools.starmap(S, itertools.product(*lists))))
