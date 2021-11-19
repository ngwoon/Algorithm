import java.util.Scanner;
import java.util.Stack;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Stack<String> stk = new Stack<>();
        StringBuilder output = new StringBuilder();

        int n = Integer.parseInt(sc.nextLine());
        for(int i=0; i<n; ++i) {
            String line = sc.nextLine();
            String[] splited = line.split(" ");

            if ("push".equals(splited[0])) {
                stk.push(splited[1]);
            } else if ("pop".equals(splited[0])) {
                if (stk.empty())
                    output.append("-1");
                else
                    output.append(stk.pop());
            } else if ("top".equals(splited[0])) {
                if (stk.empty())
                    output.append("-1");
                else
                    output.append(stk.peek());
            } else if ("size".equals(splited[0])) {
                output.append(stk.size());
            } else if ("empty".equals(splited[0])) {
                output.append(stk.empty() ? "1" : "0");
            }

            if(!splited[0].equals("push"))
                output.append("\n");
        }

        System.out.println(output);
    }
}