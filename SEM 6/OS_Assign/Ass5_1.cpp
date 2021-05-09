#include <bits/stdc++.h>
using namespace std;
const int N=100005;

int n;
int frame_size;
int pages[N];

void optimal_page_replacement()
{
    vector<int> frame_st;
    int page_faults = 0;
    cout<<"Frame Status "<<"\t\t\t"<<"Remarks"<<endl;
    for (int i = 0; i < n; i++)
    {
        int k;
        for (k = 0; k < frame_st.size(); k++)
            if (frame_st[k] == pages[i])
                break;
        if (k==frame_st.size())
        {
            if (frame_st.size() < frame_size)
                frame_st.push_back(pages[i]);

            else
            {
                int index=i+1;
                int res = -1, farthest = index;
                for (int l = 0; l < frame_st.size(); l++)
                {
                    int j;
                    for (j = index; j < n; j++)
                    {
                        if (frame_st[l] == pages[j])
                        {
                            if (j > farthest)
                            {
                                farthest = j;
                                res = l;
                            }
                            break;
                        }
                    }
                    if (j == n)
                    {
                        res=l;
                        break;
                    }
                }
                frame_st[res] = pages[i];
            }
            page_faults++;
            for (k = 0; k < frame_st.size(); k++)
            cout<<frame_st[k]<<" ";
            cout<<"\t\t"<<"Reference to page "<<pages[i]<<" caused a page fault\n";
        }
        else
        {
            for (k = 0; k < frame_st.size(); k++)
            cout<<frame_st[k]<<" ";
			cout<<"\t\t"<<"Reference to page "<<pages[i]<<" did not cause a page fault\n";
        }
    }
    cout<<"\nTotal Page Faults: "<<page_faults;
}

int main()
{
    cout<<"Enter Number of Frames: ";
    cin>>frame_size;

    cout<<"Enter Number of Pages: ";
    cin>>n;

    cout<<"Page Reference Stream:\n";
    for(int i=0; i<n; i++)
        cin>>pages[i];
    optimal_page_replacement();
    return 0;
}
