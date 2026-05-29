const l = [10, 21, 34, 42, 55, 68, 74, 83, 90, 106];

function bin_search(list, target) {
    let low = 0;
    let high = list.length - 1

    while (low <= high) {
        const mid = Math.floor((low + high) / 2)
        const current = list[mid]
        if (current == target) {
            return mid
        } 
        if (current < target) {
            low = mid + 1
        } else {
            high = mid - 1
        }
    }
    return null
}

console.log(bin_search(l, 90))