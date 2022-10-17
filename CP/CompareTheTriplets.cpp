import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
public class Solution {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a0 = in.nextInt();
        int a1 = in.nextInt();
        int a2 = in.nextInt();
        int b0 = in.nextInt();
        int b1 = in.nextInt();
        int b2 = in.nextInt();
        
        int a = 0;
        int b = 0;
        
        if (a0 > b0) a++;
        if (a0 < b0) b++;
        
        if (a1 > b1) a++;
        if (a1 < b1) b++;
        
        if (a2 > b2) a++;
        if (a2 < b2) b++;
        
        System.out.println(a + " " + b);
    }
}