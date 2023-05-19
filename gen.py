import random

numbers = random.sample(range(0, 100), 100)

with open("numbers.txt", "w") as f:
    f.write(" ".join(str(n) for n in numbers))
