import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Stack;

class Parenthesis {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringBuilder sb = new StringBuilder();
        int n = Integer.parseInt(br.readLine());

        Stack<Character> stk = new Stack<>();
        for(int i=0; i<n; ++i) {
            stk.clear();
            String pr = br.readLine();
            boolean isVPS = true;
            for(int j=0; j<pr.length(); ++j) {
                char cur = pr.charAt(j);
                if(cur == '(')
                    stk.push(cur);
                else {
                    if(stk.empty() || stk.pop() == ')') {
                        isVPS = false;
                        break;
                    }
                }
            }

            if(!isVPS || !stk.empty())
                sb.append("NO");
            else
                sb.append("YES");
            sb.append("\n");
        }

        bw.write(String.valueOf(sb));
        bw.flush();
    }
}