import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Stack;

class IronStick {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String input = br.readLine();
        Stack<Character> stk = new Stack<>();

        int ans = 0;
        for(int i=0; i<input.length(); ++i) {
            char cur = input.charAt(i);
            char next = 'a';
            if(i < input.length() - 1)
                next = input.charAt(i+1);

            if(cur == '(' && next == ')') {
                ans += stk.size();
                ++i;
            } else if(cur == '(') {
                stk.push(cur);
            } else {
                ans += 1;
                stk.pop();
            }
        }

        System.out.println(ans);
    }
}