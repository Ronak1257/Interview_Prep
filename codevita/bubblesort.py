def bubble_sort_count(arr, reverse=False):
    n = len(arr)
    swap_count = 0
    # Sort the array and count the number of swaps
    for i in range(n):
        for j in range(0, n - i - 1):
            if (arr[j] > arr[j + 1] and not reverse) or (arr[j] < arr[j + 1] and reverse):
                # Swap the elements
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swap_count += 1
    return swap_count

def minimum_swaps_to_beautiful(arr):
    # Make copies of the array for sorting
    ascending_arr = arr[:]
    descending_arr = arr[:]
    
    # Count swaps for ascending order
    ascending_swaps = bubble_sort_count(ascending_arr)
    
    # Count swaps for descending order
    descending_swaps = bubble_sort_count(descending_arr, reverse=True)
    
    # Return the minimum of the two
    return min(ascending_swaps, descending_swaps)

# Input and output handling
if __name__ == "__main__":
    N = int(input())  # Number of elements in the array
    arr = list(map(int, input().split()))  # The array elements
    
    # Get the minimum number of swaps to make the array beautiful
    result = minimum_swaps_to_beautiful(arr)
    
    # Output the result
    print(result)
