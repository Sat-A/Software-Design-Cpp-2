def binsearch(arr, val):
    lo = 0
    hi = len(arr)
    # mid = (lo + hi)//2
    while lo < hi:
        mid = (lo + hi)//2
        if arr[mid] == val:
            print(mid)
            return
        elif arr[mid] < val:
            lo = mid+1
        else:
            hi = mid
    else:
        print("Element not found")
        return
    
arr = [1,2,3,4,5,6]
for i in range(1, 7):
    print(i, end = " ")
    binsearch(arr, i)