def find_kth_missing_coordinate(n, k, arr):
    missing_count = 0
    prev_coord = 0
    
    for coord in arr:
        missing_gap = coord - prev_coord - 1
        if missing_count + missing_gap >= k:
            return prev_coord + (k - missing_count)
        
        missing_count += missing_gap
        prev_coord = coord
    
    return arr[-1] + (k - missing_count)

# Read the number of test cases
T = int(input())

for _ in range(T):
    n, k = map(int, input().split())
    arr = list(map(int, input().split()))
    
    result = find_kth_missing_coordinate(n, k, arr)
    print(result)