class Solution {
public:
    string maximumTime(string time) {
        //string res;
        for (int i = 0; i < time.size(); ++i) {
            if (i == 2)
                continue;
            if (time[i] == '?') {
                if (i == 4)
                    time[i] = '9';
                else if (i == 3)
                    time[i] = '5';

                if (i == 1 && (time[i - 1] == '1' || time[i - 1] == '0'))
                    time[i] = '9';
                if (i == 1 && (time[i - 1] == '2' || time[i - 1] == '?'))
                    time[i] = '3';
                if (i == 0 && (time[i + 1] == '?' || time[i + 1] < '4'))
                    time[i] = '2';
                if (i == 0 && (time[i + 1] <= '9' && time[i + 1] >= '4'))
                    time[i] = '1';
            }
        }
        return time;
    }
};