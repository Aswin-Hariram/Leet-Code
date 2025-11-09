class Solution {
    public int equalSubstring(String s, String t, int maxCost) {
        int l = 0;
        int res = 0;
        int curCost = 0;

        for (int r = 0; r < t.length(); r++) {
            curCost += Math.abs(s.charAt(r) - t.charAt(r));

            while (curCost > maxCost) {
                curCost -= Math.abs(s.charAt(l) - t.charAt(l));
                l++;
            }

            res = Math.max(res, r - l + 1);
        }

        return res;
    }
}
