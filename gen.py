import random

numbers = random.sample(range(0, 500), 500)

with open("numbers.txt", "w") as f:
    f.write(" ".join(str(n) for n in numbers))
