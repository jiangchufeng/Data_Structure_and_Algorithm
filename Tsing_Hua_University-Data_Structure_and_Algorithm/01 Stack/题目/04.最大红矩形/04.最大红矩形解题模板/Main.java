import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;
import java.util.StringTokenizer;

import static java.lang.Math.max;

public class MainIO {

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
        
        // n, m：意义如题
        // matrix：一个字符串数组，用来记录所给矩形，matrix[i].charAt(j)表示所给矩形第i行第j列的字符（下标均从0开始）
        // 返回值：题目所求答案，即最大矩形面积
        int getAnswer(int n, int m, String[] matrix) {
            /* 请在这里设计你的算法，并将答案存储到ans中 */
        }
        
        void solve(InputReader in, PrintWriter out) {
            int n, m;
            n = in.nextInt();
            m = in.nextInt();
            
            String[] matrix = new String[n];
            
            for (int i = 0; i < n; ++i)
                matrix[i] = in.next();
            
            out.println(getAnswer(n, m, matrix));
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