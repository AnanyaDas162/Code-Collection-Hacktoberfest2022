import java.util.Arrays;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;

public class WordLadder {

    private static class Pair {
        String word;
        int length;

        public Pair(String word, int length) {
            this.word = word;
            this.length = length;
        }

        public String getWord() {
            return word;
        }

        public int getLength() {
            return length;
        }

    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String startWord = sc.next();
        String endWord = sc.next();
        sc.close();

        List<String> wordlist = Arrays.asList("hot", "dot", "dog", "lot", "log", "cog");

        int length = ladderLength(startWord, endWord, wordlist);
        System.out.println(length);
    }

    public static int ladderLength(String beginWord, String endWord, List<String> wordList) {

        Queue<Pair> q = new LinkedList<>();
        q.add(new Pair(beginWord, 1));

        Set<String> set = new HashSet<>();
        set.addAll(wordList);
        set.remove(beginWord);

        while (!q.isEmpty()) {
            String word = q.peek().getWord();
            int steps = q.peek().getLength();
            q.poll();

            if (word.equals(endWord)) {
                return steps;
            }

            for (int i = 0; i < word.length(); i++) {
                char[] chars = word.toCharArray();

                for (char c = 'a'; c <= 'z'; c++) {
                    chars[i] = c;

                    String newWord = new String(chars);

                    if (set.contains(newWord)) {
                        set.remove(newWord);

                        q.add(new Pair(newWord, steps + 1));
                    }
                }
            }
        }
        return 0;
    }
}
