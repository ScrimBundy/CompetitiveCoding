import java.util.Scanner;

public class Problem_1569B {

    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);

        int tests = s.nextInt();
        for(int t = 0; t < tests; t++) {
            int players = s.nextInt();
            String playerType = s.next();
            int type1 = 0;
            int type2 = 0;
            for(int i = 0; i < players; i++) {
                if(playerType.charAt(i) == '1') type1++;
                else type2++;
            }
            if(type2 > 0 && type2 < 3) {
                System.out.println("No");
            } else {
                System.out.println("Yes");
                for(int i = 0; i < players; i++) {
                    if(playerType.charAt(i) == '1') {
                        for(int j = 0; j < players; j++) {
                            if(i == j) {
                                System.out.print("X");
                            } else if (playerType.charAt(j) == '1') {
                                System.out.print("=");
                            } else {
                                System.out.print("+");
                            }
                        }
                    } else {
                        for(int j = 0; j < players; j++) {
                            if(i == j) {
                                System.out.print("X");
                            } else if(j < i - 1) {
                                if(playerType.charAt(j) == '2') {
                                    if(j == findPrevious(playerType, i, '2')) {
                                        System.out.print("-");
                                    } else {
                                        System.out.print("+");
                                    }
                                } else {
                                    System.out.print("-");
                                }
                            } else if(j < i) {
                                System.out.print("-");
                            } else if(j > i) {
                                if(j == findNext(playerType, i, '2')) {
                                    System.out.print("+");
                                } else {
                                    System.out.print("-");
                                }
                            }
                        }
                    }
                    System.out.println();
                }
            }
        }
    }

    public static int findNext(String str, int currentIndex, char target) {
        if(currentIndex == str.length() - 1) return -1;
        for(int i = currentIndex + 1; i < str.length(); i++) {
            if(str.charAt(i) == target) return i;
        }
        return -1;
    }

    public static int findPrevious(String str, int currentIndex, char target) {
        if(currentIndex == 0) return -1;
        for(int i = currentIndex - 1; i >= 0; i--) {
            if(str.charAt(i) == target) return i;
        }
        return -1;
    }
}
