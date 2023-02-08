def row_interchange_algorithm(A):
    rows = len(A)
    m = len(A[0])
    for i in range(rows):
        for j in range(i, rows):
            if A[j][i] != 0:
                break
        if A[j][i] == 0:
            continue
        if j != i:
            temp = A[i]
            A[i]=A[j]
            A[j]=temp
    return A
d=row_interchange_algorithm([[0, 0, 2, 0, 4], [0, 8, 0, 0, 1], [8, 0, 9, 0, 3], [8, 0, 0, 5, 1]])
print(d)