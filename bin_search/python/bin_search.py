l = [10, 21, 34, 42, 55, 68, 74, 83, 90, 106] # 10: 0 - 9

def int_bin_search(lst: list[int], target: int) -> int | None:
    low = 0
    high = len(lst) - 1 
    search_result = None

    while low <= high:
        mid = int((low + high) // 2) # get the index (round down the mid value)
        guess = lst[mid] # get the element 
        if guess == target:
            search_result = mid
            break
        if guess < target:
            low = mid + 1
        else:
            high = mid - 1
    
    return search_result

result = int_bin_search(l, 55)
print(result)