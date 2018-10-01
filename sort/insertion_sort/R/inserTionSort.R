insertionSort <- function(arr) {
  
  for (j in 2:length(arr)) {
    x = arr[j] 
    i = j - 1 
    while (i > 0 && arr[i] >x) {
      arr[(i + 1)] = arr[i]
      i = i - 1 
    }
    arr[(i + 1)] = x
  }
  assign("arr",arr,envir = parent.frame())          
  
}

main <- function() {
  
  prompt <- "Enter numbers to be sorted "
  arr <- as.integer(strsplit(readline(prompt), " ")[[1]])
  insertionSort(arr)
  print(" Array in sorted order : ")
  print(arr)
}

main()