 import java.util.LinkedList;
 import java.util.List;

 class PathsFromSourceToTarget {

	 private static List<List<Integer>> ans;
	    private static int[][] graphS;

	    public Solution() {
	        ans = new LinkedList<>();
	    }

	    public List<List<Integer>> allPathsSourceTarget(int[][] graph) {
	        ans.clear();
	        graphS = graph;
	        for (int i = 0; i < graph[0].length; i++) {
	            helper(graphS[0][i], graphS[0][i] << 4, 8);
	        }
	        return ans;
	    }

	    public void helper(int node, long path, int pathLenBits) {
	        if (node == graphS.length - 1) {
	            pathifier(path, pathLenBits);
	            return;
	        }

	        long currPath;
	        for (int i = 0; i < graphS[node].length; i++) {
	            currPath = graphS[node][i];
	            currPath <<= pathLenBits;
	            helper(graphS[node][i], path + currPath, pathLenBits + 4);
	        }
	    }

	    private void pathifier(long path, int pathLen) {
	        LinkedList<Integer> currPath = new LinkedList<>();
	        for (int i = 0; i < pathLen / 4; i++) {
	            currPath.add((int) path & 15);
	            path >>= 4;
	        }
	        ans.add(currPath);
	    }

}
