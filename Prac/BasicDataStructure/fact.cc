#include <iostream>
#include <vector>

using namespace std;

class Frame
{
public:
    int val;
    int acc; // 累计值
    Frame *prev_frame;

    Frame(int v, int a, Frame *p) : val(v), acc(a), prev_frame(p) {}
};

int fact_iter(int n)
{
    vector<Frame> stack;
    stack.emplace_back(n, -1, nullptr);
    int res = 1;

    while (!stack.empty())
    {
        Frame &frame = stack.back();
        if (frame.val <= 1)
        {
            frame.acc = 1;
        }

        if (frame.acc != -1)
        {
            res = frame.val * frame.acc;
            if (frame.prev_frame != nullptr)
            {
                frame.prev_frame->acc = res;
                stack.pop_back();
            }
            else
            {
                return res;
            }
        }
        else
        {
            stack.emplace_back(frame.val - 1, -1, &frame);
        }
    }
}