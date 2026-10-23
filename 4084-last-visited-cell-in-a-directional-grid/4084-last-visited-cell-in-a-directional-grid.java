class Solution {
    public int[] lastVisitedCell(char[][] grid) {
        Queue<int[]> q = new LinkedList<>();

        q.offer(new int[]{0, 0});
        int m = grid.length;
        int n = grid[0].length;

        while (!q.isEmpty()) {
            int[] x = q.poll();
            char ch = grid[x[0]][x[1]];

            if (ch == 'R') {
                int r = x[0];
                int c = x[1] + 1;

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 'V') {
                    return new int[]{x[0], x[1]};
                }
                q.offer(new int[]{r, c});

            } else if (ch == 'D') {
                int r = x[0] + 1;
                int c = x[1];

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 'V') {
                    return new int[]{x[0], x[1]};
                }
                q.offer(new int[]{r, c});

            } else if (ch == 'L') {
                int r = x[0];
                int c = x[1] - 1;

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 'V') {
                    return new int[]{x[0], x[1]};
                }
                q.offer(new int[]{r, c});

            } else {
                int r = x[0] - 1;
                int c = x[1];

                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 'V') {
                    return new int[]{x[0], x[1]};
                }
                q.offer(new int[]{r, c});
            }

            grid[x[0]][x[1]] = 'V';
        }

        return new int[]{0, 0};
    }
}