while True:
    try:
        in1 = input()
        n = int(in1)
        scores = [int(n) for n in input().split()]
        scores.sort()
        print(" ".join(str(i) for i in scores)) 
        i = 0;
        while i < n and scores[i] < 60:
            i += 1
        if i == 0:
            print("best case")
        else:
            print(scores[i-1])
        if i == n:
            print("worst case")
        else:
            print(scores[i])
            
    except EOFError:
        break
