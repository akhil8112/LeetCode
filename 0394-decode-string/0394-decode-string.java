class Solution {
    public String decodeString(String s) {
        Stack<String> st = new Stack<>();

        for (int i = s.length() - 1; i >= 0; i--) {

            char ch = s.charAt(i);

            if (ch == '[') {

                String curr = "";

                while (!st.isEmpty() && !st.peek().equals("]")) {
                    curr += st.pop();
                }

                st.pop(); // remove ']'

                int num = 0;
                int place = 1;

                i--;

                while (i >= 0 && Character.isDigit(s.charAt(i))) {
                    num = (s.charAt(i) - '0') * place + num;
                    place *= 10;
                    i--;
                }

                i++;

                String temp = "";
                for (int j = 0; j < num; j++) {
                    temp += curr;
                }

                st.push(temp);
            }
            else {
                st.push(String.valueOf(ch));
            }
        }

        String ans = "";

        while (!st.isEmpty()) {
            ans += st.pop();
        }

        return ans;
    }
}