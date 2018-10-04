 merge <- function(x,y){
    if (is.na(x[1])) return(y)
    else if (is.na(y[1])) return(x)
    else if (x[1]<y[1]) return(c(x[1],merge(x[-1],y)))
    else return(c(y[1],merge(x,y[-1])))
 }

 division <- function(x){
    if (is.na(x[3])) return(cbind(x[1],x[2]))
    else
 return(cbind(c(x[1],division(x[-c(1,2)])[,1]),c(x[2],division(x[-c(1,2)])[,2]))) 

 }

 mergesort <- function(x){
    if (is.na(x[2])) return(x)
    else{
      print(x)
      t=division(x)
      return(merge(mergesort(t[,1]),mergesort(t[,2])))
    }
 }



 mergesort <- function(x) {
   n <- length(x)
   if (n < 2) return(x)

   # split x into two pieces of approximately equal size, x1 and x2

   x1 <- x[1:(n %/% 2)]
   x2 <- x[(n %/% 2 + 1):n]

   # sort each of the pieces
   x1 <- mergesort(x1)
   x2 <- mergesort(x2)

   # merge them back together
   result <- c()
   i <- 0
   while (length(x1) > 0 && length(x2) > 0) {
     # compare the first values
     if (x1[1] < x2[1]) {
       result[i + 1] <- x1[1]
       x1 <- x1[-1]
     } else {
      result[i + 1] <- x2[1]
       x2 <- x2[-1]
     }
     i <- i + 1
   }

   # put the smaller one into the result
   # delete it from whichever vector it came from
   # repeat until one of x1 or x2 is empty
   # copy both vectors (one is empty!) onto the end of the results
   result <- c(result, x1, x2)
   result
 }
