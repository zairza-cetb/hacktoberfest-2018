

# two sorted lists to merge
def merge(a: list, b: list) -> list:
    """

    :param a: left list to be merged
    :param b: right list to be merged
    :return: merged, sorted list
    """
    result = []  # initialise empty list to collect result
    # while both lists are not empty, add values to result in increasing order
    while len(a) > 0 and len(b) > 0:
        if a[0] <= b[0]:
            result.append(a[0])
            del a[0]
        else:
            result.append(b[0])
            del b[0]
    # either left or right may have elements left - consume them.
    while len(a) > 0:
        result.append(a[0])
        del a[0]
    while len(b) > 0:
        result.append(b[0])
        del b[0]
    # return sorted list
    return result


# conducts Merge Sort on provided list in increasing order
def merge_sort(l: list) -> list:
    """
    Sorts numeric or alphabetic list using Merge Sort

    :param l: list of values / strings to sort
    :return: list sorted in increasing order
    """
    if len(l) <= 1:
        return l

    # split the list into two approximately equally-sized lists (len max differ by 1)
    mid = len(l) // 2
    a = merge_sort(l[:mid])
    b = merge_sort(l[mid:])
    # the merge() function merges the left and right sublists
    return merge(a, b)


def main():
    # test numeric merge sort here
    my_list = [35, 12, 78, 100, 2, 39, 55, 9, 88, 77, 1000, 1, 23, 500, 46]
    my_list_sorted = merge_sort(my_list)
    print(my_list_sorted)

    # test alphabetic merge sort here
    my_alist = ['zebra', 'laptop', 'canon', 'explode', 'apple', 'dear', 'thomas', 'herbs', 'kelp', 'frog']
    my_alist_sorted = merge_sort(my_alist)
    print(my_alist_sorted)


if __name__ == "__main__":
    main()
