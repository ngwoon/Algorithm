import java.io.*;
import java.util.LinkedList;
import java.util.ListIterator;

class Editor {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        final String HEAD = "head";
        final String TAIL = "tail";

        String str = br.readLine();
        int m = Integer.parseInt(br.readLine());

        LinkedList<String> editor = new LinkedList<>();

        for(int i=0; i<str.length(); ++i)
            editor.add(str.substring(i, i+1));

        ListIterator<String> it = editor.listIterator(str.length());
        for(int i=0; i<m; ++i) {
            String line = br.readLine();
            if(line.length() == 1) {
                if(line.equals("L")) {
                    if(it.hasPrevious()) {
                        it.previous();
                    }
                } else if(line.equals("D")) {
                    if(it.hasNext()) {
                        it.next();
                    }
                } else {
                    if(it.hasPrevious()) {
                        it.previous();
                        it.remove();
                    }
                }
            } else {
                String[] splited = line.split(" ");
                it.add(splited[1]);
            }
        }

        StringBuilder result = new StringBuilder();
        for (String s : editor) {
            if(s.equals(HEAD) || s.equals(TAIL))
                continue;
            result.append(s);
        }

        bw.write(String.valueOf(result));
        bw.flush();
    }
}