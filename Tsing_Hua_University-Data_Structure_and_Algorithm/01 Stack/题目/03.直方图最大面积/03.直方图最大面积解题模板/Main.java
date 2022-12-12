import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.Stack;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class Main {

    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        // n：意义如题
        // height：高度数组，height[i]表示第i列的高度（下标从1开始），数组大小为n+2，其中height[0]和height[n+1]都为0
        // 返回值：题目所求答案，即最大面积
        int getAnswer(int n, int[] height) {
            /* 请在这里设计你的算法，并将答案返回 */
        }
        
        void solve(InputReader in, PrintWriter out) {
            int n = in.nextInt();
            
            int[] height = new int[n + 2]; 
            
            for (int i = 1; i <= n; ++i)
                height[i] = in.nextInt();
            
            out.println(getAnswer(n, height));
        }

    }

    static class InputReader {
        BufferedReader reader;
        StringTokenizer tokenizer;

        private InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        private String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        private short nextShort() {
            return Short.parseShort(next());
        }

        private int nextInt() {
            return Integer.parseInt(next());
        }

        private long nextLong() {
            return Long.parseLong(next());
        }

        private float nextFloat() {
            return Float.parseFloat(next());
        }

        private double nextDouble() {
            return Double.parseDouble(next());
        }
    }

}