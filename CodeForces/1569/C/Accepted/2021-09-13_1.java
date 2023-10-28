import java.math.BigInteger;
import java.util.Scanner;

public class Problem_1569C {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        long result = 0;

        long modV = 998244353L;
        long[] factorial = new long[200005];
        factorial[0] = 1;
        for(int i = 1; i < factorial.length; i++) {
            factorial[i] = (factorial[i-1] * i) % modV;
        }

        int tests = s.nextInt();
        for(int t = 0; t < tests; t++) {
            int jurySize = s.nextInt();
            int[] jury = new int[jurySize];

            int max = 0;
            int maxCount = 0;
            int sMax = 0;
            int sMaxCount = 0;

            for (int i = 0; i < jurySize; i++) {
                int temp = s.nextInt();
                if (temp > max) {
                    sMax = max;
                    max = temp;
                } else if(temp > sMax) {
                    sMax = temp;
                }
                jury[i] = temp;
            }

            for (int i = 0; i < jurySize; i++) {
                if(jury[i] == max) {
                    maxCount++;
                } else if(jury[i] == sMax) {
                    sMaxCount++;
                }
            }

            if (maxCount > 1) {
                result = factorial[jurySize];
            } else if(sMax + 1 < max) {
                result = 0;
            } else {
                result = factorial[jurySize];
                long j = factorial[sMaxCount];
                for(int i = 0; i < jurySize - sMaxCount - 1; i++) {
                    j *= sMaxCount + 2 + i;
                    j %= modV;
                }
                result -= j;
                result += modV;
                result %= modV;
            }
            System.out.println(result);
        }
        s.close();
    }
}
