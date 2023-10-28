import java.util.*;

public class Problem_1569D {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int tests = s.nextInt();
        for(int t = 0; t < tests; t++) {
            int n = s.nextInt();
            int m = s.nextInt();
            int k = s.nextInt();


            int[] x = new int[n];
            int[] y = new int[m];
            for(int i = 0; i < n; i++) {
                x[i] = s.nextInt();
            }
            for(int i = 0; i < m; i++) {
                y[i] = s.nextInt();
            }
            Arrays.sort(x);
            Arrays.sort(y);

            int[][] people = new int[k][3];
            for(int i = 0; i < k; i++) {
                people[i] = new int[]{i, s.nextInt(), s.nextInt()};
            }
            Comparator<int[]> sortByX = Comparator.comparingInt(o -> o[1]);
            Comparator<int[]> sortByY = Comparator.comparingInt(o -> o[2]);

            Arrays.sort(people, sortByX);
            boolean sortedByX = true;


            long total = 0;
            for(int r = 0; r < 2; r++) {
                int ci = 0;
                int pi = (sortedByX)?1:2;
                int perpIndex = (sortedByX)?2:1;
                int[] streets = (sortedByX)?x:y;
                int low = -1;
                int high = (sortedByX)?x[0]:y[0];
                int highInd = 0;
                int count = 0;
                HashMap<Integer, Integer> sameLine = new HashMap<>();
                while(ci < people.length) {
                    if(people[ci][pi] >= high && count > 0) {
                        total += section(count, sameLine);
                        count = 0;
                    }
                    if(people[ci][pi] >= high) {
                        low = high;
                        if (highInd < streets.length - 1) {
                            high = streets[++highInd];
                        } else if(high == 1000001) {
                            break;
                        } else {
                            high = 1000001;
                        }
                    } else if(people[ci][pi] < high && people[ci][pi] > low) {
                        count++;
                        if(sameLine.containsKey(people[ci][perpIndex])) {
                            sameLine.replace(people[ci][perpIndex], sameLine.get(people[ci][perpIndex]) + 1);
                        } else {
                            sameLine.put(people[ci][perpIndex], 1);
                        }
                        ci++;
                        continue;
                    }
                    if(people[ci][pi] <= low) {
                        ci++;
                    }
                }
                if(count > 0) {
                    total += section(count, sameLine);
                }
                Arrays.sort(people,sortByY);
                sortedByX = false;
            }
            System.out.println(total);
        }
    }

    public static long section(long count, HashMap<Integer, Integer> sameLine) {
        long arithmeticSum = (count * (count - 1)) / 2;
        long total = 0;
        int subtract = 0;
        for(Integer a : sameLine.values()) {
            subtract += ((long)a * (a - 1))/2;
        }
        total += arithmeticSum - subtract;
        sameLine.clear();
        return total;
    }
}
