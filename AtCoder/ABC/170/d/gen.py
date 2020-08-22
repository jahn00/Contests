with open("t1", "w+") as file1:
    n = 10
    file1.write(str(n) + '\n')
    for i in range(n):
        file1.write(str(i+1) + '\n')
