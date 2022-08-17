import matplotlib.pyplot as plt


# Using readlines()
file1 = open('data.txt', 'r')
Lines = file1.readlines()

x = []
y = []
count = 0
# Strips the newline character
for line in Lines:
    line.strip()
    t = line.split()
    x.append(float(t[0]))
    y.append(float(t[1]))


plt.xlabel('Tile Size Values')
plt.ylabel('Exec Times Values')

plt.plot(x, y)
plt.show()
