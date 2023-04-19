int search(int arr[], int arrSize, int val) {
    int i;

    i = 0;
    while (i < arrSize) {
        if (arr[i] == val)
            return i;
        i++;
    }
    return -1;
}