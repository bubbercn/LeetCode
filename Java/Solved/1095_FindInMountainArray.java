class MountainArray {

    public MountainArray(int[] array) {
        this.array = array;
    }

    public int get(int index) {
        return array[index];
    }

    public int length() {
        return array.length;
    }

    private int[] array;
}

class Solution1095 {
    public int findInMountainArray(int target, MountainArray mountainArr) {
        int peak = findPeak(mountainArr);
        int left = binarySearch(mountainArr, target, 0, peak, true);
        if (left != -1) {
            return left;
        }
        return binarySearch(mountainArr, target, peak + 1, mountainArr.length() - 1, false);
    }

    private int findPeak(MountainArray mountainArr) {
        int left = 1;
        int right = mountainArr.length() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid - 1) < mountainArr.get(mid) && mountainArr.get(mid) > mountainArr.get(mid + 1)) {
                return mid;
            } else if (mountainArr.get(mid - 1) < mountainArr.get(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }

    private int binarySearch(MountainArray mountainArr, int target, int left, int right, boolean asc) {
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (midValue == target) {
                return mid;
            }
            if (midValue < target) {
                if (asc) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (asc) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
}