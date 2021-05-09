#include<bits/stdc++.h>

using namespace std;
struct coord { //structure for storing input
        int x;
        int y;
        int h;
};
//flag if 1 then start of building if 0 then end of building
struct skyline { //structure for (x,h,f) coordinates
        int x;
        int h;
        int f;
};
struct coord c[] = { //input
        {
                31,
                41,
                5
        },
        {
                4,
                9,
                21
        },
        {
                30,
                36,
                9
        },
        {
                14,
                18,
                11
        },
        {
                2,
                12,
                14
        },
        {
                34,
                43,
                19
        },
        {
                23,
                25,
                8
        },
        {
                14,
                21,
                16
        },
        {
                32,
                37,
                12
        },
        {
                7,
                16,
                7
        },
        {
                24,
                27,
                10
        }
};
vector < struct skyline > sky;
vector < struct skyline > skyout;
int size = 0;
void keypoints(vector < struct skyline > & sky) //dividing left and right coordinates and converting the input to desired points 
{
        int i;
        struct skyline skyin;
        for (i = 0; i < 11; i++) {
                skyin.x = c[i].x;
                skyin.h = c[i].h;
                skyin.f = 1; //start of the building
                sky.push_back(skyin);
                skyin.x = c[i].y;
                skyin.h = c[i].h;
                skyin.f = 0; //end of the building
                sky.push_back(skyin);
        }
}
void sort(int n) //sort all the coordinate vectors
{
        int i;
        for (int i = 0; i < sky.size(); i++) {
                bool swaped = false;
                for (int j = 0; j < sky.size() - i - 1; j++) {
                        if (sky[j].x > sky[j + 1].x) {
                                int xtemp, htemp, ftemp;
                                xtemp = sky[j].x;
                                htemp = sky[j].h;
                                ftemp = sky[j].f;
                                sky[j].x = sky[j + 1].x;
                                sky[j].h = sky[j + 1].h;
                                sky[j].f = sky[j + 1].f;
                                sky[j + 1].x = xtemp;
                                sky[j + 1].h = htemp;
                                sky[j + 1].f = ftemp;
                                swaped = true;
                        }
                }
                if (!swaped)
                        break;
        }
}
void create_skyline(vector < struct skyline > & skyout) //skyline function
{
        vector < int > height; //height vector 
        int temp, prev = 0, maxh, i, j, l;
        struct skyline temp1, temp2, temp3;
        for (i = 0; i < sky.size(); i++) {
                temp = sky[i].h;
                if (sky[i].f == 1) //start of building
                {
                        if (height.empty() == true) //no height 
                        {
                                if (i != 0) {
                                        temp1.x = sky[i - 1].x;
                                        temp1.h = 0;
                                        temp1.f = 0;
                                        skyout.push_back(temp1);
                                        size++;
                                } else { //appending (0,0) as start
                                        temp1.x = 0;
                                        temp1.h = 0;
                                        temp1.f = 1;
                                        skyout.push_back(temp1);
                                        size++;
                                }
                                height.push_back(temp);
                        } else //height vector not empty
                        {
                                for (j = 0; j < height.size(); j++) {
                                        if (temp >= height[j])
                                                break;
                                }
                                height.push_back(0);
                                for (l = height.size() - 1; l > j; l--) //shifting right
                                {
                                        height[l] = height[l - 1];
                                }
                                height[j] = temp; //height added to vector
                        }
                        maxh = height[0]; //max height = top of height vector
                } else //f==0 i.e. end of building
                {
                        auto k = find(height.begin(), height.end(), temp); //finding height of building to pop
                        height.erase(k);
                        maxh = height[0];                                   
                }
                if (prev != maxh) {
                        temp3.x = sky[i].x;
                        temp3.h = maxh;
                        temp3.f = 1;
                        if (size != 0) //size of skyout
                        {
                                temp2.x = skyout[size - 1].x;
                                temp2.h = skyout[size - 1].h;
                                temp2.f = skyout[size - 1].f;
                                if (temp2.x == temp3.x) {
                                        if (temp2.h < temp3.h) {
                                                skyout.pop_back(); //remove repeated points
                                                skyout.push_back(temp3);
                                        }
                                } else {
                                        skyout.push_back(temp3);
                                }
                        } else {
                                skyout.push_back(temp1);
                        }
                        size++;
                        prev = maxh; //changing previous max height
                }
        }
        temp3.x = sky[i - 1].x; //appending the last point of the skyline
        temp3.h = 0;
        temp3.f = 1;
        skyout.push_back(temp3);
        cout << "\n\nSkyline(Incremental) is : " << endl;
        for (i = 0; i < skyout.size(); i++) {
                cout << "( " << skyout[i].x << " , " << skyout[i].h << " ) " << endl;
        }
}
int main() {
        int i;
        keypoints(sky);
        sort(sky.size());
        create_skyline(skyout);
}
