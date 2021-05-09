#include <bits/stdc++.h>

using namespace std;
struct building {
        int x;
        int y;
        int h;
};
struct points {
        int x;
        int y;
};
vector < struct building > skyin {
        {
                31,
                41,
                5
        }, {
                4,
                9,
                21
        }, {
                30,
                36,
                9
        }, {
                14,
                18,
                11
        }, {
                2,
                12,
                14
        }, {
                34,
                43,
                19
        }, {
                23,
                25,
                8
        }, {
                14,
                21,
                16
        }, {
                32,
                37,
                12
        }, {
                7,
                16,
                7
        }, {
                24,
                27,
                10
        }
};
vector < struct points > skyout; //output vector
vector < struct points > mergesky(vector < struct points > sky_l, vector < struct points > sky_h);
vector < struct points > skyline(int l, int h, vector < struct building > sky1);

int main() {
        skyout = skyline(0, skyin.size() - 1, skyin);
        skyout.insert(skyout.begin(), {
                0,
                0
        });
        int i;
        cout << "The Skyline(Divide and Conquer)output\n";
        for (i = 0; i < skyout.size(); i++) {
                if (skyout[i].x != -1) {
                        cout << "( " << skyout[i].x << " , " << skyout[i].y << " ) ";
                        cout << endl;
                }
        }
        return 0;
}
//utility functions
vector < struct points > mergesky(vector < struct points > skylow, vector < struct points > skyhigh) {
        int hl = 0, hh = 0;
        int i = 0, j = 0;
        vector < struct points > mergedsky; //storing merged vector
        while (i < skylow.size() && j < skyhigh.size()) {
                if (skylow.empty() || skyhigh.empty()) {
                        break;
                }
                struct points temp;
                if (skylow[i].x < skyhigh[j].x) //to check which coordinate comes first
                {
                        temp.x = skylow[i].x;
                        temp.y = skylow[i].y;
                        if (skylow[i].y < hh) {
                                temp.y = hh;
                        }
                        hl = skylow[i].y;
                        i++;
                } else if (skylow[i].x > skyhigh[j].x) {
                        temp.x = skyhigh[j].x;
                        temp.y = skyhigh[j].y;
                        if (skyhigh[j].y < hl) {
                                temp.y = hl;
                        }
                        hh = skyhigh[j].y;
                        j++;
                } else {
                        temp.x = skyhigh[j].x;
                        temp.y = max(skylow[i].y, skyhigh[j].y);
                        hl = skylow[i].y;
                        hh = skyhigh[j].y;
                        i++;
                        j++;
                }
                mergedsky.push_back(temp);
        }
        if (i >= skylow.size()) {
                while (j < skyhigh.size()) {
                        mergedsky.push_back(skyhigh[j]);
                        j++;
                }
        }
        if (j >= skyhigh.size()) {
                while (i < skylow.size()) {
                        mergedsky.push_back(skylow[i]);
                        i++;
                }
        }
        int inx = 1;
        vector < int > redundant;
        redundant.push_back(0);
        while (inx < mergedsky.size()) {
                if (mergedsky[inx].y == mergedsky[inx - 1].y) {
                        redundant.push_back(1);
                } else {
                        redundant.push_back(0);
                }
                inx++;
        }
        for (i = 0; i < redundant.size(); i++) {
                if (redundant[i] == 1) {
                        mergedsky[i].x = -1;
                }
        }
        return mergedsky;
}
vector < struct points > skyline(int low, int high, vector < struct building > sky1) {
        vector < struct points > skyline1;
        if (low > high) {
                return skyline1;
        } else if (low == high) {
                struct points p = {
                        sky1[low].x,
                        sky1[low].h
                };
                skyline1.push_back(p);
                p.x = sky1[low].y;
                p.y = 0;
                skyline1.push_back(p);
                return skyline1;
        } else //dividing
        {
                int mid = low + ((high - low) / 2);
                vector < struct points > sky_low = skyline(low, mid, sky1);
                vector < struct points > sky_high = skyline(mid + 1, high, sky1);
                //combine
                return mergesky(sky_low, sky_high);
        }
}
