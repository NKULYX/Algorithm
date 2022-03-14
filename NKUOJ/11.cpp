#include <bits/stdc++.h>
using namespace std;

int n;
queue<int> man;
queue<int> man_prefer[35];
int woman_prefer[35][35];
int woman_matched[35];
int man_matched[35];

void GS();

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int woman_id;
            cin >> woman_id;
            man_prefer[i].push(woman_id);
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            int man_id;
            cin >> man_id;
            woman_prefer[i][man_id] = j;
        }
    for (int i = 1; i <= n; i++)
        man.push(i);
    GS();
    for (int i = 1; i <= n; i++)
        cout << man_matched[i] << " ";
    system("pause");
}

void GS()
{
    while (man.size() > 0)
    {
        int man_id = man.front();
        // 在男人的顺序队列中去找合适的搭档
        while (man_prefer[man_id].size() > 0)
        {
            int woman_id = man_prefer[man_id].front();
            // 当前的女士没有搭档
            if (!woman_matched[woman_id])
            {
                woman_matched[woman_id] = man_id; // 结伴搭档
                man_matched[man_id] = woman_id;
                man_prefer[man_id].pop(); // 将女士从男士的选择队列中弹出
                man.pop();                // 将男士从等待队列中弹出
                break;
            }
            // 如果当前搭档有匹配
            else
            {
                // 如果女士愿意保持原状
                if (woman_prefer[woman_id][man_id] > woman_prefer[woman_id][woman_matched[woman_id]])
                {
                    // 将当前的女士从男士的选择队列中弹出
                    man_prefer[man_id].pop();
                    // 男士继续向后选择女士
                }
                // 如果女士更改选择
                else
                {
                    // 将女士之前的搭档加入等待队列
                    man.push(woman_matched[woman_id]);
                    woman_matched[woman_id] = man_id; // 结伴搭档
                    man_matched[man_id] = woman_id;
                    man_prefer[man_id].pop(); // 将女士从男士的选择队列中弹出
                    man.pop();                // 将男士从等待队列中弹出
                    break;
                }
            }
        }
    }
}