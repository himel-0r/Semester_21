t = int(input())
for jj in range (t):
    n = int(input())
    
    a = list(map(int, input().split()))
    flag = False
    
    for i in range (n):
        if i+1 >= a[i]:
            flag = True
            break
    
    if flag:
        print("YES")
    else:
        print("NO")
    