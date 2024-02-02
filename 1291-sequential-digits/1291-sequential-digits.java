class Solution {
   private static int getLength(int number) {
        return String.valueOf(number).length();
    }

    private static int getFirstDigit(int number) {
        return Integer.parseInt(String.valueOf(number).substring(0, 1));
    }

    private static int generateNumber(int start, int length) {
        int num = start;
        for (int i = 1; i < length; i++) {
            num = num * 10 + (start + i);
        }
        return num;
    }

    public static List<Integer> sequentialDigits(int low, int high) {
        List<Integer> result = new ArrayList<>();

        int lowLength = getLength(low);
        int highLength = getLength(high);

        for (int length = lowLength; length <= highLength; length++) {
            for (int start = 1; start <= 9 - length + 1; start++) {
                int num = generateNumber(start, length);
                if (num >= low && num <= high) {
                    result.add(num);
                }
            }
        }

        return result;
    }
}