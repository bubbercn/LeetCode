class Solution1185 {
    public String dayOfTheWeek(int day, int month, int year) {
        int result = 0;
        for (int i = 1971; i < year; i++) {
            result += isLeapYear(i) ? 366 : 365;
        }
        for (int i = 1; i < month; i++) {
            result += getDaysInMonth(i, year);
        }
        result += day;
        String[] daysOfWeek = { "Thursday", "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday" };
        return daysOfWeek[result % 7];
    }

    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    private int getDaysInMonth(int month, int year) {
        switch (month) {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                return 31;
            case 4: case 6: case 9: case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                throw new IllegalArgumentException("Invalid month: " + month);
        }
    }
}