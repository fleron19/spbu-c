int* mergeSort(int* up, int* down, unsigned int left, unsigned int right)
{
    if (left == right) {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = left + (right - left) / 2;

    int* l_buff = mergeSort(up, down, left, middle);
    int* r_buff = mergeSort(up, down, middle + 1, right);

    int* target = l_buff == up ? down : up;

    unsigned int l_cur = left, r_cur = middle + 1;
    for (unsigned int i = left; i <= right; i++) {
        if (l_cur <= middle && r_cur <= right) {
            if (l_buff[l_cur] < r_buff[r_cur]) {
                target[i] = l_buff[l_cur];
                l_cur++;
            } else {
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        } else if (l_cur <= middle) {
            target[i] = l_buff[l_cur];
            l_cur++;
        } else {
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}
