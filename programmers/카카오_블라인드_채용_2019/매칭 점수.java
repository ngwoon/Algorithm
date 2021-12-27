package 카카오_블라인드_채용_2019;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/*
    HTML 문서들이 주어졌을 때, 문제에서 제시한 조건에 맞는 매칭점수가 가장 높은 페이지의 인덱스를 구하는 문제.

    <나의 풀이>
    풀지 못해서 구글링을 통해 아이디어를 얻었다.
    이 문제는 정규표현식을 꽤 잘 다룰줄 알아야 풀 수 있는 문제였다.
    외부 링크 수, 링크 점수, 매칭 점수를 구하는 방법 자체는 어렵지 않지만, HTML 문자열에서 원하는 URL만 추출할 수 있는 문자열 파싱 능력을 갖추고 있어야 했다.
 */

class MatchScore {

    static HashMap<String, PageInfo> hm;
    static Pattern urlPattern = Pattern.compile("<meta property=\"og:url\" content=\"(\\S*)\"");
    static Pattern linkPattern = Pattern.compile("<a href=\"https://(\\S*)\"");

    public static int solution(String word, String[] pages) {

        hm = new HashMap<>();
        for (int i=0; i<pages.length; ++i) {
            String url = getUrl(pages[i]);
            hm.put(url, new PageInfo(i, pages[i], url));
        }

        for(String key : hm.keySet()) {
            PageInfo pageInfo = hm.get(key);
            String body = getBody(pageInfo.page);

            pageInfo.linking = getLinks(body);
            pageInfo.basicScore = search(body, word);
        }

        for(PageInfo pageInfo : hm.values()) {
            for (String s : pageInfo.linking) {
                if(hm.containsKey(s)) {
                    hm.get(s).linkScore += pageInfo.basicScore / (double) pageInfo.linking.size();
                }
            }
        }

        double ansScore = 0;
        int ansNum = 20;
        for(PageInfo pageInfo : hm.values()) {
            double matchScore = pageInfo.basicScore + pageInfo.linkScore;

//            System.out.println("index = " + pageInfo.pageNum + " basicScore = " + pageInfo.basicScore + " linkScore = " + pageInfo.linkScore +  " matchScore = " + matchScore);

            if(ansScore <= matchScore) {
                if(ansScore == matchScore) {
                    ansNum = Math.min(ansNum, pageInfo.pageNum);
                } else {
                    ansScore = matchScore;
                    ansNum = pageInfo.pageNum;
                }
            }
        }

        return ansNum;
    }

    public static int search(String body, String word) {

        int found = 0;

        body = body.replaceAll("[0-9]", " ");
        Pattern wordPattern = Pattern.compile("\\b(?i)" + word + "\\b");
        Matcher matcher = wordPattern.matcher(body);

        while(matcher.find()) {
            ++found;
        }

        return found;
    }

    public static List<String> getLinks(String body) {

        List<String> links = new LinkedList<>();
        Matcher matcher = linkPattern.matcher(body);

        while(matcher.find()) {
            links.add(matcher.group().split("\"")[1]);
        }

        return links;
    }

    public static String getUrl(String page) {

        Matcher matcher = urlPattern.matcher(page);

        String ret = "";
        while(matcher.find()) {
            ret = matcher.group().split("=")[2].replaceAll("\"", "");
        }
        return ret;
    }

    public static String getBody(String page) {

        int bsIdx = page.indexOf("<body>");
        bsIdx += 7; // 개행문자 어떻게되는지 확인 필요. 일단 개행문자도 문자 하나로 침

        int beIdx = page.indexOf("</body>");

        return page.substring(bsIdx, beIdx);
    }

    static class PageInfo {

        String page, url;
        double linkScore;
        int pageNum, basicScore, matchScore;
        List<String> linking;

        public PageInfo(int pageNum, String page, String url) {
            this.pageNum = pageNum;
            this.page = page;
            this.url = url;
            this.linkScore = 0;
            this.basicScore = 0;
            this.matchScore = 0;
        }
    }
}