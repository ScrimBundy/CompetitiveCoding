import java.util.Scanner;

public class Problem_1569A {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int tests = s.nextInt();
        for(int i = 0; i < tests; i++) {
            int len = s.nextInt();
            boolean pair = false;
            int loc = -1;
            String word = s.next();
            if(len > 1) {
                for (int j = 0; j < len - 1; j++) {
                    if (word.charAt(j) != word.charAt(j + 1)) {
                        pair = true;
                        loc = j;
                        break;
                    }
                }
            }
            if(pair) {
                System.out.println((loc + 1) + " " + (loc + 2));
            } else {
                System.out.println("-1 -1");
            }
        }
        s.close();
    }
}
