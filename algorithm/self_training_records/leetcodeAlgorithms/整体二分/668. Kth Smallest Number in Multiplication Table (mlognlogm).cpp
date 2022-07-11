class Solution {
public:
    int solve(int m, int n, int k) {
        int answer = 0;

        for (int i = 1; i <= m; i++) {
            int left = i, right = i * n;
            while (left <= right) {
                int middle = (left + right) >> 1;

                if (middle > k) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            }
            answer += std::min((left - 1) / i, n);
        }

        return answer;
    }
    int findKthNumber(int m, int n, int k) {
        int left = 1, right = m * n;
        while (left <= right) {
            int middle = (left + right) >> 1;

            if (solve(m, n, middle) >= k) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }

        return right + 1;
    }
};