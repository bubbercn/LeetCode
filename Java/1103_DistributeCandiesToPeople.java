class Solution1103 {
    public int[] distributeCandies(int candies, int num_people) {
        int[] result = new int[num_people];
        int current = 1;
        int people = 0;
        while (candies > 0) {
            if (candies >= current) {
                result[people] += current;
                candies -= current;
            } else {
                result[people] += candies;
                candies = 0;
            }
            people++;
            if (people == num_people) {
                people = 0;
            }
            current++;
        }
        return result;
    }
}