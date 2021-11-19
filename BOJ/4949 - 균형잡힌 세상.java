import java.io.*;
import java.util.Stack;

class BalancedWorld {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        while(true) {
            String line = br.readLine();
            if(line.equals("."))
                break;

            Stack<Character> stk = new Stack<>();
            boolean isBalanced = true;
            for(int i=0; i<line.length(); ++i) {
                char cur = line.charAt(i);
                if(cur == '(' || cur == '[')
                    stk.push(cur);
                else if(cur == ')' || cur == ']') {
                    if(stk.empty())  {
                        isBalanced = false;
                        break;
                    }

                    char top = stk.pop();
                    if(cur == ')') {
                        if(top != '(') {
                            isBalanced = false;
                            break;
                        }
                    } else {
                        if(top != '[') {
                            isBalanced = false;
                            break;
                        }
                    }
                }
            }

            if(!isBalanced || !stk.empty()) {
                bw.write("no");
            } else {
                bw.write("yes");
            }
            bw.write("\n");
        }

        bw.flush();
    }
}