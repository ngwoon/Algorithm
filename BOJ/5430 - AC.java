import java.io.*;

class AC {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());

        while(t-- > 0) {
            String cmds = br.readLine();
            int numCnt = Integer.parseInt(br.readLine());

            String numLine = br.readLine();
            String numStr = numLine.substring(1, numLine.length() - 1);
            String[] numStrs = numStr.split(",");
            int startIdx = 0, endIdx = numCnt - 1;
            boolean isReversed = false;

            boolean error = false;
            for(int i=0; i<cmds.length(); ++i) {
                char cmd = cmds.charAt(i);
                if(cmd == 'R') {
                    isReversed = !isReversed;
                } else {
                    // 배열이 빈 경우
                    if(startIdx > endIdx) {
                        error = true;
                        break;
                    } else {
                        if(isReversed) {
                            --endIdx;
                        } else {
                            ++startIdx;
                        }
                    }
                }
            }

            if(error) {
                bw.write("error");
            } else {
                bw.write("[");
                if(isReversed) {
                    for(int i=endIdx; i>=startIdx; --i) {
                        bw.write(numStrs[i]);
                        if(i != startIdx) {
                            bw.write(",");
                        }
                    }
                } else {
                    for(int i=startIdx; i<=endIdx; ++i) {
                        bw.write(numStrs[i]);
                        if(i != endIdx) {
                            bw.write(",");
                        }
                    }
                }
                bw.write("]");
            }
            bw.write("\n");
        }

        bw.flush();
    }
}