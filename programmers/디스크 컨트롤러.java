import java.util.PriorityQueue;

class DiskController {

    static class Job implements Comparable<Job> {
        private int inTime;
        private int startTime;
        private int takeTime;

        Job(int inTime, int takeTime) {
            this.inTime = inTime;
            this.takeTime = takeTime;
            this.startTime = inTime;
        }

        @Override
        public int compareTo(Job o) {
            if(this.startTime < o.startTime)
                return -1;
            else if(this.startTime == o.startTime){
                if(this.takeTime < o.takeTime)
                    return -1;
                else
                    return 1;
            } else
                return 1;
        }
    }

    public static int solution(int[][] jobs) {
        PriorityQueue<Job> pq = new PriorityQueue<>();

        for (int[] job : jobs)
            pq.offer(new Job(job[0], job[1]));

        int curTime = 0;
        int totalTime = 0;
        while(!pq.isEmpty()) {
            Job job = pq.poll();

            totalTime += (job.startTime - job.inTime) + job.takeTime;
            if(curTime < job.startTime)
                curTime = job.startTime + job.takeTime;
            else
                curTime += job.takeTime;

            while(!pq.isEmpty() && pq.peek().startTime < curTime) {
                Job temp = pq.poll();
                temp.startTime = curTime;
                pq.offer(temp);
            }
        }

        return totalTime / jobs.length;
    }

    public static void main(String[] args) {
        int[][] jobs = new int[3][2];

        jobs[0][0] = 0;
        jobs[0][1] = 3;
        jobs[1][0] = 3;
        jobs[1][1] = 9;
        jobs[2][0] = 12;
        jobs[2][1] = 6;

        System.out.println(solution(jobs));
    }
}