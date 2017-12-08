def partition(arr, low, high):
  wall = low-1
  pivot = arr[high]

  for j in range(low, high):
    #if(arr[j] >= pivot): para ordem descendente
    if(arr[j] <= pivot):
      wall+=1
      arr[wall],arr[j] = arr[j],arr[wall]

  arr[wall+1], arr[high] = arr[high], arr[wall+1]

  return (wall+1)

def quickSort(arr, low, high):
  if(low < high):
    pi = partition(arr, low, high)

    quickSort(arr, low, pi-1)
    quickSort(arr, pi+1, high)

array = [10, 5, 3, 8, 1]

quickSort(array, 0, len(array)-1)

print(array)