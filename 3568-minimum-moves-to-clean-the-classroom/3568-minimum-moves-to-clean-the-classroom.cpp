class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int sr = -1, sc = -1;
        vector<pair<int, int>> litter;

        // Locate S and all L cells.
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    sr = r;
                    sc = c;
                } else if (classroom[r][c] == 'L') {
                    litter.push_back({r, c});
                }
            }
        }

        int k = litter.size();

        // No litter to collect.
        if (k == 0) return 0;

        // Map each litter cell to its bit.
        vector<vector<int>> litterId(m, vector<int>(n, -1));
        for (int i = 0; i < k; ++i) {
            auto [r, c] = litter[i];
            litterId[r][c] = i;
        }

        int fullMask = (1 << k) - 1;

        /*
            State:
            (r, c, mask, e)

            dist[r][c][mask][e] = minimum moves needed to reach
            this exact state.

            Since m,n <= 20, mask <= 1024, energy <= 50,
            the total number of states is manageable.
        */

        int states = m * n * (1 << k) * (energy + 1);

        // Encode a state into a single integer.
        auto encode = [&](int r, int c, int mask, int e) {
            return (((r * n + c) * (1 << k) + mask)
                    * (energy + 1) + e);
        };

        // We can use a flat visited array.
        vector<char> visited(states, false);

        queue<array<int, 4>> q;

        int startMask = 0;
        if (litterId[sr][sc] != -1) {
            startMask |= 1 << litterId[sr][sc];
        }

        int startEnergy = energy;

        int startCode = encode(sr, sc, startMask, startEnergy);
        visited[startCode] = true;

        q.push({sr, sc, startMask, startEnergy});

        int moves = 0;

        int dr[] = {1, -1, 0, 0};
        int dc[] = {0, 0, 1, -1};

        while (!q.empty()) {
            int sz = q.size();

            while (sz--) {
                auto [r, c, mask, e] = q.front();
                q.pop();

                if (mask == fullMask) {
                    return moves;
                }

                for (int d = 0; d < 4; ++d) {
                    int nr = r + dr[d];
                    int nc = c + dc[d];

                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;

                    if (classroom[nr][nc] == 'X')
                        continue;

                    // Every move costs 1 energy.
                    if (e == 0)
                        continue;

                    int ne = e - 1;

                    // Collect litter if this cell contains one.
                    int nmask = mask;

                    if (litterId[nr][nc] != -1) {
                        nmask |= 1 << litterId[nr][nc];
                    }

                    /*
                        If we enter R, energy is immediately restored
                        to maximum capacity.
                    */
                    if (classroom[nr][nc] == 'R') {
                        ne = energy;
                    }

                    int code = encode(nr, nc, nmask, ne);

                    if (!visited[code]) {
                        visited[code] = true;
                        q.push({nr, nc, nmask, ne});
                    }
                }
            }

            ++moves;
        }

        return -1;
    }
};