package 카카오_블라인드_채용_2021;

class RecommendId {

    public static String solution(String newId) {

        newId = capToSmall(newId);

        newId = deleteSpecials(newId);

        newId = twoDotsToOne(newId);

        newId = trimDot(newId);

        newId = shorten(newId);
        newId = trimDot(newId);

        newId = extend(newId);

        return newId;
    }

    public static String capToSmall(String str) {

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<str.length(); ++i) {
            char c = str.charAt(i);
            if(65 <= c && c <= 90) {
                sb.append((char)(c + 32));
            } else {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    public static String deleteSpecials(String str) {

        StringBuilder sb = new StringBuilder();
        for(int i=0; i<str.length(); ++i) {
            char c = str.charAt(i);
            if(isDigit(c) || isSmall(c) || c == '-' || c == '_' || c == '.') {
                sb.append(c);
            }
        }
        return sb.toString();
    }

    public static String twoDotsToOne(String str) {

        String prev = str;
        while(true) {
            String replaced = prev.replaceAll("\\.\\.", ".");
            if(replaced.equals(prev)) {
                return replaced;
            } else {
                prev = replaced;
            }
        }
    }

    public static String trimDot(String str) {

        if(str.length() == 0) {
            return "a";
        }

        int start = 0, end = str.length();
        if(str.charAt(0) == '.') {
            start = 1;
        }
        if(str.charAt(str.length() - 1) == '.') {
            end = str.length() - 1;
        }

        if(start >= end) {
            return "a";
        } else {
            return str.substring(start, end);
        }
    }

    public static String shorten(String str) {

        if(str.length() >= 16) {
            return str.substring(0, 15);
        }
        return str;
    }

    public static String extend(String str) {

        StringBuilder sb = new StringBuilder(str);
        while(sb.length() < 3) {
            sb.append(sb.charAt(sb.length()-1));
        }
        return sb.toString();
    }

    public static boolean isDigit(char c) {

        try {
            Integer.parseInt(String.valueOf(c));
            return true;
        } catch(NumberFormatException e) {
            return false;
        }
    }

    public static boolean isSmall(char c) {

        if(97 <= c && c <= 122) {
            return true;
        } else {
            return false;
        }
    }
}