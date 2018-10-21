#!/bin/bash
# contribuitor: siuannybsr
# hacktoberfest 2018

selection_sort() {
	array=$1
	array_length=${#array[@]}

	for((i=0; i<array_length; i++)) do
		small=${array[$i]}
		small_index=$i
		for((j=i + 1; j<array_length; j++)) do
			if [ ${array[$j]} -lt $small ]; then
	            small=${array[$j]}
				small_index=$j	    
	    	fi
		done
		swap
	done
}

swap() {
	temp=${array[$i]}
	array[$i]=$small
	array[$small_index]=$temp
}

main() {
	array=("1" "3" "2" "1" "5" "13" "4" "8" "34" "21" "55")
	selection_sort $array
	echo ${array[@]} | tr " " " "
}

main
