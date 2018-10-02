 
mergeHalfves <- function(arr , beg ,mid ,end) {
  
  leftArr = arr[beg:mid]
  rightArr = arr[(mid+1):end]
  
  mergedArr=c();
  i = 1
  j = 1
  
  while(i<= length(leftArr) && j<= length(rightArr)) {
    if(leftArr[i]<=rightArr[j]) {
      mergedArr = c(mergedArr,leftArr[i])
      i = i+1
      flag = 1
    }
    
    else {
      mergedArr = c(mergedArr,rightArr[j])
      j = j+1
      flag = 2
    }
    
  }
  
  if(flag == 1) {
    mergedArr = c(mergedArr,rightArr[j:length(rightArr)])
  }
  
  else {
    mergedArr = c(mergedArr,leftArr[i:length(leftArr)])
  }
  
  arr[beg:end]=mergedArr
  
  assign("arr",arr,parent.frame()) 
  
}

divide <- function(arr , beg , end ) {
  
  if (beg<end) {
    mid = as.integer((beg+end)/2);
    
    divide(arr ,beg , mid)                         #left sub-array
    divide(arr , mid+1 ,end)                      #right sub-array
    
    mergeHalfves(arr , beg , mid , end)
    
    assign("arr",arr,envir = parent.frame())          
  }
  
}

main <- function() {
  
  prompt <- "Enter numbers to be sorted "
  arr <- as.integer(strsplit(readline(prompt), " ")[[1]])
  divide(arr,1,length(arr))
  print(" Array in sorted order : ")
  print(arr)
}

main()



