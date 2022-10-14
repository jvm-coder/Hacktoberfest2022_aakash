import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class ShortestPath {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nv = sc.nextInt();
        int ne = sc.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<ArrayList<Integer>>(nv);

        for (int i = 0; i < nv; i++)
            adj.add(new ArrayList<Integer>());

        for (int i = 0; i < ne; i++) {
            int firstVertex = sc.nextInt();
            int secondVertex = sc.nextInt();

            adj.get(firstVertex).add(secondVertex);
            adj.get(secondVertex).add(firstVertex);
        }

        int src = sc.nextInt();
        sc.close();

        int[] dist = shortestPath(adj, nv, src);
        for (int i = 0; i < dist.length; i++) {
            System.out.print(dist[i]+" ");
        }
    }

    private static int[] shortestPath(ArrayList<ArrayList<Integer>> adj, int nv, int startVertex) {

        int[] distance = new int[nv];
        Arrays.fill(distance, Integer.MAX_VALUE);
        distance[startVertex] = 0;

        Queue<Integer> q = new LinkedList<>();
        q.add(startVertex);

        while (!q.isEmpty()) {
            int top = q.poll();

            for (int adjacent : adj.get(top)) {

                if (distance[top] + 1 < distance[adjacent]) {
                    distance[adjacent] = distance[top] + 1;

                    q.add(adjacent);
                }
            }
        }
        return distance;
    }
}
